package firmament.events;

import box2D.collision.B2Manifold;
import box2D.collision.B2WorldManifold;
import box2D.common.math.B2Math;
import box2D.common.math.B2Vec2;
import box2D.dynamics.contacts.B2Contact;
import firmament.component.physics.FBox2DComponent;
import firmament.core.FEntity;
import firmament.core.FGame;
import firmament.core.FWorld;
import firmament.events.FPhysicsCollisionEvent;
import nme.events.Event;
/**
 * ...
 * @author Jordan Wambaugh
 */

class FBox2DCollisionEvent extends FPhysicsCollisionEvent
{
	var _contact:B2Contact;
	public function new(world:FWorld,type:FCollisionEventType,contact:B2Contact) 
	{
		this._contact = contact;
		super(world,type);
	}
	
	override public function getCollisionSpeed():Float {
		var manifold:B2WorldManifold = new B2WorldManifold();
		_contact.getWorldManifold(manifold);
		var bodyA = _contact.getFixtureA().getBody();
		var bodyB = _contact.getFixtureB().getBody();
		var point = manifold.m_points[0];
		var va:B2Vec2 = bodyA.getLinearVelocityFromWorldPoint(point);
		var vb = bodyB.getLinearVelocityFromWorldPoint(point);
		va.subtract(vb);
		var velocity = B2Math.dot(va, manifold.m_normal);
		return velocity;
	}


	
	override public function getEntityA():FEntity {
		return cast(_contact.getFixtureA().getBody().getUserData(),FBox2DComponent).getEntity();
	}
	
	override public function getEntityB():FEntity {
		return cast(_contact.getFixtureB().getBody().getUserData(),FBox2DComponent).getEntity();
	}

	override public function allowCollision(c:Bool){
		_contact.setEnabled(c);
	}

	


}