package firmament.core;
import box2D.collision.B2WorldManifold;
import box2D.common.math.B2Math;
import box2D.common.math.B2Vec2;
import nme.events.Event;
import box2D.dynamics.contacts.B2Contact;
import box2D.collision.B2Manifold;
/**
 * ...
 * @author Jordan Wambaugh
 */

class FPhysicsCollisionEvent extends Event
{
	var _contact:B2Contact;
	public function new(contact:B2Contact) 
	{
		this._contact = contact;
		super(FGame.COLLISION_EVENT);
	}
	
	public function getCollisionSpeed() {
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
	
}