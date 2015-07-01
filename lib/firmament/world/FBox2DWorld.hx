package firmament.world;


import box2D.collision.B2AABB;
import box2D.collision.B2Manifold;
import box2D.common.math.B2Vec2;
import box2D.dynamics.B2Body;
import box2D.dynamics.B2BodyDef;
import box2D.dynamics.B2ContactListener;
import box2D.dynamics.B2Fixture;
import box2D.dynamics.B2World;
import box2D.dynamics.contacts.B2Contact;
import firmament.component.physics.FBox2DComponent;
import firmament.core.FConfig;
import firmament.core.FEntity;
import firmament.core.FEvent;
import firmament.core.FVector;
import firmament.event.FBox2DCollisionEvent;
import firmament.event.FPhysicsCollisionEvent;
import firmament.ui.FDialog;
import firmament.world.FWorld;

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
		var colEvent = new FBox2DCollisionEvent(world,FCollisionEventType.beginContact,contact);
		bodyA.getEntity().trigger(colEvent);
		bodyB.getEntity().trigger(colEvent);
		//firmament.util.FLog.debug("beginContact "+bodyA.getEntity().getTypeId() + " > "+bodyB.getEntity().getTypeId());
		// collisionAllowed doesn't work here so we need a different Event Type
		// contact.setEnabled( colEvent.collisionAllowed() );
	}

	override public function endContact(contact:B2Contact):Void {
		var bodyA:FBox2DComponent = contact.getFixtureA().getBody().getUserData();
		var bodyB:FBox2DComponent = contact.getFixtureB().getBody().getUserData();
		var colEvent = new FBox2DCollisionEvent(world,FCollisionEventType.endContact,contact);
		bodyA.getEntity().trigger(colEvent);
		bodyB.getEntity().trigger(colEvent);
		// collisionAllowed doesn't work here so we need a different Event Type
		// contact.setEnabled( colEvent.collisionAllowed() );
	}

	override public function preSolve(contact:B2Contact, oldManifold:B2Manifold):Void {
		//preSolve is called when just bounding boxes collide, which we aren't interested in.
		//only care if they are actually touching.
		if(!contact.isTouching()){
			return;
		}

		var bodyA:FBox2DComponent = contact.getFixtureA().getBody().getUserData();
		var bodyB:FBox2DComponent = contact.getFixtureB().getBody().getUserData();
		var colEvent = new FBox2DCollisionEvent(world,FCollisionEventType.preSolve,contact);
		bodyA.getEntity().trigger(colEvent);
		bodyB.getEntity().trigger(colEvent);
		contact.setEnabled( colEvent.collisionAllowed() );
	}
}

// To enable ridership on static objects
// the setLin/setAng need to be overloaded
// to allow updating of the values
class B2BodyS extends B2Body
{

	/**
	* Set the linear velocity of the center of mass.
	* @param v the new linear velocity of the center of mass.
	*/
	override public function setLinearVelocity(v:B2Vec2) : Void {
		m_linearVelocity.setV(v);
	}

	/**
	* Set the angular velocity.
	* @param omega the new angular velocity in radians/second.
	*/
	override public function setAngularVelocity(omega:Float) : Void {
		m_angularVelocity = omega;
	}
}

class B2WorldS extends B2World
{
	override public function createBody(def:B2BodyDef) : B2BodyS{

		//b2Settings.b2Assert(m_lock == false);
		if (isLocked() == true)
		{
			return null;
		}

		//void* mem = m_blockAllocator.Allocate(sizeof(b2Body));
		var b:B2BodyS = new B2BodyS(def, this);

		// Add to world doubly linked list.
		b.m_prev = null;
		b.m_next = m_bodyList;
		if (m_bodyList != null)
		{
			m_bodyList.m_prev = b;
		}
		m_bodyList = b;
		++m_bodyCount;

		return b;
	}
}

class FBox2DWorld extends FWorld
{


	var _b2world:B2WorldS;
	var _inStep:Bool;

	private var deleteQueue:Array<FEntity>;
	public function new()
	{
		super();
		_inStep=false;
		this._b2world = new B2WorldS(new B2Vec2(0,0), true);
		this.deleteQueue = new Array<FEntity>();
		this._b2world.setContactListener(new FPhysicsWorldContactListener(this));
	}

	override public function init(config:Dynamic){
		super.init(config);
		var c:FConfig = config;
		var vec = c.getVector('gravity',{x:0,y:0});
		this._b2world.setGravity(new B2Vec2(vec.x,vec.y));
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

	public function getEntitiesRay(a:FVector, b:FVector,mask:Int=0xFFFF) {
		var ents:Array<FEntity>=new Array<FEntity>();
		this.rayCast(a, b, function(fixture:B2Fixture , a, b, fraction) {
			//FDialog.alert('here');
			if(fixture.m_filter.categoryBits & mask>0)
			ents.push(cast(fixture.getBody().getUserData(),FBox2DComponent).getEntity());
			return fraction;
		} );
		return ents;
	}

	public function getEntitiesRaySorted(a:FVector, b:FVector,mask:Int=0xFFFF) {
		var ents:Array<FEntity>=new Array<FEntity>();
		this.rayCast(a, b, function(fixture:B2Fixture , a, b, fraction) {
			//FDialog.alert('here');
			if(fixture.m_filter.categoryBits & mask >0)
			ents.push(cast(fixture.getBody().getUserData(),FBox2DComponent).getEntity());
			return fraction;
		} );
		ents.sort(function(x,y):Int{
			var xd = x.getProp('position').distanceTo(a);
			var yd = y.getProp('position').distanceTo(a);
			if(xd==yd) return 0;
			if(xd<yd) return -1;
			return 1;
		});
		return ents;
	}

	public function rayCast(a:FVector, b:FVector, callbackMethod:B2Fixture -> B2Vec2 -> B2Vec2 -> Float -> Dynamic) {

		this._b2world.rayCast(callbackMethod, new B2Vec2(a.x,a.y), new B2Vec2(a.x,a.y));
	}

	override public function getEntitiesAtPoint(fvec:FVector):Array<FEntity> {
		var p = new B2Vec2(fvec.x,fvec.y);
		var ents:Array<FEntity> = this.getEntitiesInBox(p.x, p.y, p.x, p.y);
		var filtered:Array<FEntity> = new Array<FEntity>();
		var seen:Map<String,Int> = new Map();

		//loop through each fixture in each entity, and see if its an actual match.
		for (ent in ents) {
			var component = cast(ent.getPhysicsComponent(), FBox2DComponent);
			var fixture = component.body.getFixtureList();
			while (fixture!=null) {
				if ( fixture.testPoint(p) ) {
					//check if its already in the array
					var id = ent.getInstanceId();
					if( ! seen.exists( id ) ) {
						seen.set( id, 1 );
						filtered.push(ent);
					}
				}
				fixture = fixture.getNext();
			}
		}
		return filtered;
	}

	public function getB2World():B2WorldS {
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
			//firmament.util.FLog.debug('collision');
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
			try {
				// This can happen if the world object is deleted before the
				//  pool objects are deleted
				this._b2world.destroyBody(cast(ent.getPhysicsComponent(),FBox2DComponent).body); 
			} catch(e:Dynamic) {
				trace("Error destroying body for entity", haxe.CallStack.toString(haxe.CallStack.callStack()) );
				throw e;
			}
		}

	}


	override public function getType():String{
		return "box2d";
	}

	override public function setGravity(gravity:FVector){
		this._b2world.setGravity(new B2Vec2(gravity.x,gravity.y));
	}

	override public function insideStep():Bool{
		return _inStep;
	}

	override public function destruct(){
		super.destruct();
		this._b2world = null; 
	}

}
