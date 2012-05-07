package firmament.core;

import box2D.dynamics.B2ContactListener;
import firmament.core.FWorld;
import firmament.core.FEntity;
import box2D.dynamics.B2World;
import box2D.collision.B2AABB;
import nme.events.Event;

import box2D.dynamics.contacts.B2Contact;
import box2D.collision.B2Manifold;
/**
 * ...
 * @author Jordan Wambaugh
 */

class FPhysicsWorldContactListener extends B2ContactListener {
	var world:FPhysicsWorld;
	
	public function new(world) {
		this.world = world;
		super();
	}
	
	override public function preSolve(contact:B2Contact, oldManifold:B2Manifold):Void {
		//world.contacts.push(Reflect.copy(contact));
	}
}
 

 
class FPhysicsWorld extends FWorld
{

	
	var b2world:B2World;
	
	private var deleteQueue:Array<FPhysicsEntity>;
	public function new(gravity:FVector) 
	{
		super();
		this.b2world = new B2World(gravity, true);
		this.deleteQueue = new Array<FPhysicsEntity>();
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
	
	override public function getEntitiesAtPoint(p:FVector):Array<FEntity> {
		return this.getEntitiesInBox(p.x,p.y,p.x,p.y);
	}
	
	public function getB2World():B2World {
		return this.b2world;
	}
	
	public function createEntity(config:Dynamic):FPhysicsEntity {
		var ent:FPhysicsEntity = new FPhysicsEntity(this,config);
		//this.addEntity(ent);
		return ent;
		
	}
	
	override public function step():Void {
		
		this.b2world.step(this.getTimeSinceLastStep(), 10, 10);
		this.endOfStep();
		var contact = this.b2world.getContactList();
		while (contact!=null) {
			var entA:FPhysicsEntity = cast(contact.getFixtureA().getBody().getUserData());
			var entB:FPhysicsEntity = cast(contact.getFixtureB().getBody().getUserData());
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
	
	
	
	
	private function deleteEntity(ent:FPhysicsEntity) {
		this.b2world.destroyBody(ent.body);
	}
	
	public function removeEntity(ent:FPhysicsEntity) {
		this.deleteQueue.push(ent);
		
	}
	
	
}