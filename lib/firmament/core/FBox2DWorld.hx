package firmament.core;


import box2D.collision.B2AABB;
import box2D.collision.B2Manifold;
import box2D.common.math.B2Vec2;
import box2D.dynamics.B2ContactListener;
import box2D.dynamics.B2Fixture;
import box2D.dynamics.B2World;
import box2D.dynamics.contacts.B2Contact;
import firmament.component.physics.FBox2DComponent;
import firmament.core.FEntity;
import firmament.core.FWorld;
import firmament.events.FBox2DCollisionEvent;
import firmament.events.FPhysicsCollisionEvent;
import firmament.ui.FDialog;
import nme.events.Event;
/**
 * ...
 * @author Jordan Wambaughz
 */

class FPhysicsWorldContactListener extends B2ContactListener {
	var world:FBox2DWorld;
	
	public function new(world) {
		this.world = world;
		super();
	}
	override public function beginContact(contact:B2Contact):Void {

		var bodyA:FBox2DComponent = contact.getFixtureA().getBody().getUserData();
		var bodyB:FBox2DComponent = contact.getFixtureB().getBody().getUserData();
		bodyA.getEntity().dispatchEvent(new FBox2DCollisionEvent(world,FCollisionEventType.beginContact,contact));
		bodyB.getEntity().dispatchEvent(new FBox2DCollisionEvent(world,FCollisionEventType.beginContact,contact));
		//trace("beginContact "+bodyA.getEntity().getTypeId() + " > "+bodyB.getEntity().getTypeId());
	}

	override public function endContact(contact:B2Contact):Void {
		var bodyA:FBox2DComponent = contact.getFixtureA().getBody().getUserData();
		var bodyB:FBox2DComponent = contact.getFixtureB().getBody().getUserData();
		bodyA.getEntity().dispatchEvent(new FBox2DCollisionEvent(world,FCollisionEventType.endContact,contact));
		bodyB.getEntity().dispatchEvent(new FBox2DCollisionEvent(world,FCollisionEventType.endContact,contact));
	}

	override public function preSolve(contact:B2Contact, oldManifold:B2Manifold):Void {
		//preSolve is called when just bounding boxes collide, which we aren't interested in.
		//only care if they are actually touching.
		if(!contact.isTouching()){
			return;
		}
		
		var bodyA:FBox2DComponent = contact.getFixtureA().getBody().getUserData();
		var bodyB:FBox2DComponent = contact.getFixtureB().getBody().getUserData();
		bodyA.getEntity().dispatchEvent(new FBox2DCollisionEvent(world,FCollisionEventType.preSolve,contact));
		bodyB.getEntity().dispatchEvent(new FBox2DCollisionEvent(world,FCollisionEventType.preSolve,contact));
	}
}
 

 
class FBox2DWorld extends FWorld
{

	
	var _b2world:B2World;
	var _inStep:Bool;
	
	private var deleteQueue:Array<FEntity>;
	public function new() 
	{
		super();
		_inStep=false;
		this._b2world = new B2World(new B2Vec2(0,0), true);
		this.deleteQueue = new Array<FEntity>();
		this._b2world.setContactListener(new FPhysicsWorldContactListener(this));
	}
	
	override public function getEntitiesInBox(topLeftX:Float,topLeftY:Float,bottomRightX:Float,bottomRightY:Float):Array<FEntity>{
		var selectEntities:Array<FEntity> = new Array<FEntity>();
		var query = new B2AABB();
		
		query.upperBound.set(bottomRightX,bottomRightY);
		query.lowerBound.set(topLeftX,topLeftY);
		
		this._b2world.queryAABB(function(fixture){
			selectEntities.push(cast(fixture.getBody().getUserData(),FBox2DComponent).getEntity());
			return true;
		},query);
	  
		return selectEntities;
	}
	
	public function getEntitiesRay(a:FVector, b:FVector) {
		var ents:Array<FEntity>=new Array<FEntity>();
		this.rayCast(a, b, function(fixture:B2Fixture , a, b, fraction) {
			FDialog.alert('here');
			ents.push(fixture.m_body.getUserData());
			return fraction;
		} );
		return ents;
	}
	
	public function rayCast(a:FVector, b:FVector, callbackMethod:B2Fixture -> B2Vec2 -> B2Vec2 -> Float -> Dynamic) {
		this._b2world.rayCast(callbackMethod, a, b);
	}
	
	override public function getEntitiesAtPoint(p:FVector):Array<FEntity> {
		
		var ents:Array<FEntity> = this.getEntitiesInBox(p.x, p.y, p.x, p.y);
		var filtered:Array<FEntity> = new Array<FEntity>();
		
		//loop through each fixture in each entity, and see if its an actual match.
		for (ent in ents) {
			var component = cast(ent.getPhysicsComponent(), FBox2DComponent);
			var fixture = component.body.getFixtureList();
			while (fixture!=null) {
				if (fixture.testPoint(p)) {
					//match!
					//check if its already in the array
					var contains = false;
					for (fItem in filtered) {
						contains = true;
					}
					if (!contains) {
						filtered.push(ent);
					}
				}
				fixture = fixture.getNext();
			}
		}
		return filtered;
	}
	
	public function getB2World():B2World {
		return this._b2world;
	}
	
	
	
	override public function step():Void {
		_inStep = true;
		this._b2world.step(this.getTimeSinceLastStep(), 10, 10);
		this._b2world.clearForces();
		_inStep = false;
		this.endOfStep();
		/*
		var contact = this._b2world.getContactList();
		while (contact!=null) {
			var entA:FEntity = cast(contact.getFixtureA().getBody().getUserData().getEntity());
			var entB:FEntity = cast(contact.getFixtureB().getBody().getUserData().getEntity());
			entA.dispatchEvent(new FBox2DCollisionEvent(this,contact));
			entB.dispatchEvent(new FBox2DCollisionEvent(this,contact));
			contact = contact.getNext();
			//trace('collision');
		}*/
		var ent;
		//Delete any entities waiting for deletion.
		while((ent=this.deleteQueue.shift())!=null) {
			this.deleteEntity(ent);
		}
		
		
		
	}
	
	
	
	
	override public function deleteEntity(ent:FEntity) {
		//can't delete while world is simulating so queue it up if we are.
		if(_inStep){
			this.deleteQueue.push(ent);
		} 
		else {
			super.deleteEntity(ent);
			this._b2world.destroyBody(cast(ent.getPhysicsComponent(),FBox2DComponent).body);
		}
		
	}
	
	
	override public function getType():String{
		return "box2d";
	}

	override public function setGravity(gravity){
		this._b2world.setGravity(gravity);
	}

	override public function insideStep():Bool{
		return _inStep;
	}
	
}