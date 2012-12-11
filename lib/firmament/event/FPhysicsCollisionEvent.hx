package firmament.event;


import box2D.collision.B2Manifold;
import box2D.collision.B2WorldManifold;
import box2D.common.math.B2Math;
import box2D.common.math.B2Vec2;
import box2D.dynamics.contacts.B2Contact;
import firmament.core.FEntity;
import firmament.core.FGame;
import firmament.core.FVector;
import firmament.core.FWorld;
import nme.events.Event;
/**
 * ...
 * @author Jordan Wambaugh
 */

enum FCollisionEventType{
	preSolve;
	postSolve;
	beginContact;
	endContact;
}

class FPhysicsCollisionEvent extends Event
{
	var _world:FWorld;
	var _collisionType:FCollisionEventType;



	public function new(world:FWorld,type:FCollisionEventType) 
	{
		this._world = world;
		_collisionType = type;
		var typeStr = switch(type){
			case preSolve:FGame.COLLISION_PRE_SOLVE_EVENT;
			case postSolve:FGame.COLLISION_POST_SOLVE_EVENT;
			case endContact:FGame.COLLISION_END_CONTACT_EVENT;
			case beginContact:FGame.COLLISION_BEGIN_CONTACT_EVENT;
			
		}
		super(typeStr);
	}
	
	public function getCollisionSpeed():Float {
		throw "not implemented";
		return 0;
	}
	
	public function getEntityA():FEntity {
		throw "not implemented";
		return null;
	}
	
	public function getEntityB():FEntity {
		throw "not implemented";
		return null;
	}

	public function getOtherEntity(ent:FEntity):FEntity{
		var entA = this.getEntityA();
		if(entA != ent)return entA;
		return this.getEntityB();
	}

	public function getCollisionType(){
		return _collisionType;
	}

	public function allowCollision(c:Bool){

	}

	public function getLocalPointOfContact(entity:FEntity):FVector{
		return new FVector(0,0);
	}
	
}