package firmament.core;

import box2D.dynamics.B2ContactListener;
import firmament.component.physics.FBox2DComponent;
import firmament.core.FWorld;
import firmament.core.FEntity;
import box2D.dynamics.B2World;
import box2D.collision.B2AABB;
import firmament.ui.FDialog;
import nme.events.Event;

import box2D.dynamics.contacts.B2Contact;
import box2D.collision.B2Manifold;
import box2D.dynamics.B2Fixture;
import box2D.common.math.B2Vec2;
/**
 * ...
 * @author Jordan Wambaugh
 */

class FPhysicsWorldContactListener extends B2ContactListener {
	var world:FBox2DWorld;
	
	public function new(world) {
		this.world = world;
		super();
	}
	
	override public function preSolve(contact:B2Contact, oldManifold:B2Manifold):Void {
		//world.contacts.push(Reflect.copy(contact));
	}
}
 

 
class FBox2DWorld extends FWorld
{

	
	var b2world:B2World;
	
	private var deleteQueue:Array<FEntity>;
	public function new(gravity:FVector) 
	{
		super();
		this.b2world = new B2World(gravity, true);
		this.deleteQueue = new Array<FEntity>();
		//this.b2world.setContactListener(new FPhysicsWorldContactListener(this));
	}
	
	override public function getEntitiesInBox(topLeftX:Float,topLeftY:Float,bottomRightX:Float,bottomRightY:Float):Array<FEntity>{
		var selectEntities:Array<FEntity> = new Array<FEntity>();
		var query = new B2AABB();
		
		query.upperBound.set(bottomRightX,bottomRightY);
		query.lowerBound.set(topLeftX,topLeftY);
		
		this.b2world.queryAABB(function(fixture){
			
			selectEntities.push(fixture.getBody().getUserData());
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
		this.b2world.rayCast(callbackMethod, a, b);
	}
	
	override public function getEntitiesAtPoint(p:FVector):Array<FEntity> {
		
		var ents:Array<FEntity> = this.getEntitiesInBox(p.x, p.y, p.x, p.y);
		var filtered:Array<FEntity> = new Array<FEntity>();
		
		//loop through each fixture in each entity, and see if its an actual match.
		for (ent in ents) {
			var component = cast(ent.getPhysicsComponent, FBox2DComponent);
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
		return this.b2world;
	}
	
	public function createEntity(config:Dynamic):FEntity {
		var ent:FEntity = new FEntity(config);
		//this.addEntity(ent);
		return ent;
		
	}
	
	override public function step():Void {
		
		this.b2world.step(this.getTimeSinceLastStep(), 10, 10);
		this.endOfStep();
		var contact = this.b2world.getContactList();
		while (contact!=null) {
			var entA:FEntity = cast(contact.getFixtureA().getBody().getUserData());
			var entB:FEntity = cast(contact.getFixtureB().getBody().getUserData());
			entA.dispatchEvent(new FPhysicsCollisionEvent(contact));
			entB.dispatchEvent(new FPhysicsCollisionEvent(contact));
			contact = contact.getNext();
			//trace('collision');
		}
		var ent;
		//Delete any entities waiting for deletion.
		while((ent=this.deleteQueue.shift())!=null) {
			this.deleteEntity(ent);
		}
		
		
		
	}
	
	
	
	/*
	 * NOT SAFE for fphysics entities. call removeEntity instead
	 */
	override public function deleteEntity(ent:FEntity) {
		
		super.deleteEntity(ent);
	}
	
	public function removeEntity(ent:FEntity) {
		this.deleteQueue.push(ent);
		
	}
	
	override public function getType():String{
		return "box2d";
	}
	
}