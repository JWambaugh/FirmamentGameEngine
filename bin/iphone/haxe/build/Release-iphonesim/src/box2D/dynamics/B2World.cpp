#include <hxcpp.h>

#ifndef INCLUDED_box2D_collision_B2AABB
#include <box2D/collision/B2AABB.h>
#endif
#ifndef INCLUDED_box2D_collision_B2RayCastInput
#include <box2D/collision/B2RayCastInput.h>
#endif
#ifndef INCLUDED_box2D_collision_B2RayCastOutput
#include <box2D/collision/B2RayCastOutput.h>
#endif
#ifndef INCLUDED_box2D_collision_IBroadPhase
#include <box2D/collision/IBroadPhase.h>
#endif
#ifndef INCLUDED_box2D_collision_shapes_B2CircleShape
#include <box2D/collision/shapes/B2CircleShape.h>
#endif
#ifndef INCLUDED_box2D_collision_shapes_B2EdgeShape
#include <box2D/collision/shapes/B2EdgeShape.h>
#endif
#ifndef INCLUDED_box2D_collision_shapes_B2PolygonShape
#include <box2D/collision/shapes/B2PolygonShape.h>
#endif
#ifndef INCLUDED_box2D_collision_shapes_B2Shape
#include <box2D/collision/shapes/B2Shape.h>
#endif
#ifndef INCLUDED_box2D_common_B2Color
#include <box2D/common/B2Color.h>
#endif
#ifndef INCLUDED_box2D_common_B2Settings
#include <box2D/common/B2Settings.h>
#endif
#ifndef INCLUDED_box2D_common_math_B2Mat22
#include <box2D/common/math/B2Mat22.h>
#endif
#ifndef INCLUDED_box2D_common_math_B2Math
#include <box2D/common/math/B2Math.h>
#endif
#ifndef INCLUDED_box2D_common_math_B2Sweep
#include <box2D/common/math/B2Sweep.h>
#endif
#ifndef INCLUDED_box2D_common_math_B2Transform
#include <box2D/common/math/B2Transform.h>
#endif
#ifndef INCLUDED_box2D_common_math_B2Vec2
#include <box2D/common/math/B2Vec2.h>
#endif
#ifndef INCLUDED_box2D_dynamics_B2Body
#include <box2D/dynamics/B2Body.h>
#endif
#ifndef INCLUDED_box2D_dynamics_B2BodyDef
#include <box2D/dynamics/B2BodyDef.h>
#endif
#ifndef INCLUDED_box2D_dynamics_B2ContactFilter
#include <box2D/dynamics/B2ContactFilter.h>
#endif
#ifndef INCLUDED_box2D_dynamics_B2ContactListener
#include <box2D/dynamics/B2ContactListener.h>
#endif
#ifndef INCLUDED_box2D_dynamics_B2ContactManager
#include <box2D/dynamics/B2ContactManager.h>
#endif
#ifndef INCLUDED_box2D_dynamics_B2DebugDraw
#include <box2D/dynamics/B2DebugDraw.h>
#endif
#ifndef INCLUDED_box2D_dynamics_B2DestructionListener
#include <box2D/dynamics/B2DestructionListener.h>
#endif
#ifndef INCLUDED_box2D_dynamics_B2Fixture
#include <box2D/dynamics/B2Fixture.h>
#endif
#ifndef INCLUDED_box2D_dynamics_B2Island
#include <box2D/dynamics/B2Island.h>
#endif
#ifndef INCLUDED_box2D_dynamics_B2TimeStep
#include <box2D/dynamics/B2TimeStep.h>
#endif
#ifndef INCLUDED_box2D_dynamics_B2World
#include <box2D/dynamics/B2World.h>
#endif
#ifndef INCLUDED_box2D_dynamics_contacts_B2Contact
#include <box2D/dynamics/contacts/B2Contact.h>
#endif
#ifndef INCLUDED_box2D_dynamics_contacts_B2ContactEdge
#include <box2D/dynamics/contacts/B2ContactEdge.h>
#endif
#ifndef INCLUDED_box2D_dynamics_contacts_B2ContactSolver
#include <box2D/dynamics/contacts/B2ContactSolver.h>
#endif
#ifndef INCLUDED_box2D_dynamics_controllers_B2Controller
#include <box2D/dynamics/controllers/B2Controller.h>
#endif
#ifndef INCLUDED_box2D_dynamics_controllers_B2ControllerEdge
#include <box2D/dynamics/controllers/B2ControllerEdge.h>
#endif
#ifndef INCLUDED_box2D_dynamics_joints_B2Joint
#include <box2D/dynamics/joints/B2Joint.h>
#endif
#ifndef INCLUDED_box2D_dynamics_joints_B2JointDef
#include <box2D/dynamics/joints/B2JointDef.h>
#endif
#ifndef INCLUDED_box2D_dynamics_joints_B2JointEdge
#include <box2D/dynamics/joints/B2JointEdge.h>
#endif
#ifndef INCLUDED_box2D_dynamics_joints_B2PulleyJoint
#include <box2D/dynamics/joints/B2PulleyJoint.h>
#endif
#ifndef INCLUDED_nme_display_DisplayObject
#include <nme/display/DisplayObject.h>
#endif
#ifndef INCLUDED_nme_display_DisplayObjectContainer
#include <nme/display/DisplayObjectContainer.h>
#endif
#ifndef INCLUDED_nme_display_Graphics
#include <nme/display/Graphics.h>
#endif
#ifndef INCLUDED_nme_display_IBitmapDrawable
#include <nme/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_nme_display_InteractiveObject
#include <nme/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_nme_display_Sprite
#include <nme/display/Sprite.h>
#endif
#ifndef INCLUDED_nme_events_EventDispatcher
#include <nme/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_nme_events_IEventDispatcher
#include <nme/events/IEventDispatcher.h>
#endif
namespace box2D{
namespace dynamics{

Void B2World_obj::__construct(::box2D::common::math::B2Vec2 gravity,bool doSleep)
{
{
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",61)
	this->s_stack = Array_obj< ::box2D::dynamics::B2Body >::__new();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",62)
	this->m_contactManager = ::box2D::dynamics::B2ContactManager_obj::__new();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",63)
	this->m_contactSolver = ::box2D::dynamics::contacts::B2ContactSolver_obj::__new();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",64)
	this->m_island = ::box2D::dynamics::B2Island_obj::__new();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",66)
	this->m_destructionListener = null();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",67)
	this->m_debugDraw = null();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",69)
	this->m_bodyList = null();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",70)
	this->m_contactList = null();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",71)
	this->m_jointList = null();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",72)
	this->m_controllerList = null();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",74)
	this->m_bodyCount = (int)0;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",75)
	this->m_contactCount = (int)0;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",76)
	this->m_jointCount = (int)0;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",77)
	this->m_controllerCount = (int)0;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",79)
	::box2D::dynamics::B2World_obj::m_warmStarting = true;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",80)
	::box2D::dynamics::B2World_obj::m_continuousPhysics = true;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",82)
	this->m_allowSleep = doSleep;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",83)
	this->m_gravity = gravity;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",85)
	this->m_inv_dt0 = 0.0;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",87)
	this->m_contactManager->m_world = hx::ObjectPtr<OBJ_>(this);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",89)
	::box2D::dynamics::B2BodyDef bd = ::box2D::dynamics::B2BodyDef_obj::__new();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",90)
	this->m_groundBody = this->createBody(bd);
}
;
	return null();
}

B2World_obj::~B2World_obj() { }

Dynamic B2World_obj::__CreateEmpty() { return  new B2World_obj; }
hx::ObjectPtr< B2World_obj > B2World_obj::__new(::box2D::common::math::B2Vec2 gravity,bool doSleep)
{  hx::ObjectPtr< B2World_obj > result = new B2World_obj();
	result->__construct(gravity,doSleep);
	return result;}

Dynamic B2World_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2World_obj > result = new B2World_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

Void B2World_obj::setDestructionListener( ::box2D::dynamics::B2DestructionListener listener){
{
		HX_SOURCE_PUSH("B2World_obj::setDestructionListener")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",101)
		this->m_destructionListener = listener;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2World_obj,setDestructionListener,(void))

Void B2World_obj::setContactFilter( ::box2D::dynamics::B2ContactFilter filter){
{
		HX_SOURCE_PUSH("B2World_obj::setContactFilter")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",109)
		this->m_contactManager->m_contactFilter = filter;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2World_obj,setContactFilter,(void))

Void B2World_obj::setContactListener( ::box2D::dynamics::B2ContactListener listener){
{
		HX_SOURCE_PUSH("B2World_obj::setContactListener")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",116)
		this->m_contactManager->m_contactListener = listener;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2World_obj,setContactListener,(void))

Void B2World_obj::setDebugDraw( ::box2D::dynamics::B2DebugDraw debugDraw){
{
		HX_SOURCE_PUSH("B2World_obj::setDebugDraw")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",125)
		this->m_debugDraw = debugDraw;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2World_obj,setDebugDraw,(void))

Void B2World_obj::setBroadPhase( ::box2D::collision::IBroadPhase broadPhase){
{
		HX_SOURCE_PUSH("B2World_obj::setBroadPhase")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",136)
		::box2D::collision::IBroadPhase oldBroadPhase = this->m_contactManager->m_broadPhase;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",137)
		this->m_contactManager->m_broadPhase = broadPhase;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",138)
		::box2D::dynamics::B2Body b = this->m_bodyList;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",139)
		while(((b != null()))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",141)
			::box2D::dynamics::B2Fixture f = b->m_fixtureList;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",142)
			while(((f != null()))){
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",144)
				f->m_proxy = broadPhase->createProxy(oldBroadPhase->getFatAABB(f->m_proxy),f);
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",145)
				f = f->m_next;
			}
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",147)
			b = b->m_next;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2World_obj,setBroadPhase,(void))

Void B2World_obj::validate( ){
{
		HX_SOURCE_PUSH("B2World_obj::validate")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",155)
		this->m_contactManager->m_broadPhase->validate();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(B2World_obj,validate,(void))

int B2World_obj::getProxyCount( ){
	HX_SOURCE_PUSH("B2World_obj::getProxyCount")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",163)
	return this->m_contactManager->m_broadPhase->getProxyCount();
}


HX_DEFINE_DYNAMIC_FUNC0(B2World_obj,getProxyCount,return )

::box2D::dynamics::B2Body B2World_obj::createBody( ::box2D::dynamics::B2BodyDef def){
	HX_SOURCE_PUSH("B2World_obj::createBody")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",175)
	if (((this->isLocked() == true))){
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",176)
		return null();
	}
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",181)
	::box2D::dynamics::B2Body b = ::box2D::dynamics::B2Body_obj::__new(def,hx::ObjectPtr<OBJ_>(this));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",184)
	b->m_prev = null();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",185)
	b->m_next = this->m_bodyList;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",186)
	if (((this->m_bodyList != null()))){
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",187)
		this->m_bodyList->m_prev = b;
	}
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",190)
	this->m_bodyList = b;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",191)
	++(this->m_bodyCount);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",193)
	return b;
}


HX_DEFINE_DYNAMIC_FUNC1(B2World_obj,createBody,return )

Void B2World_obj::destroyBody( ::box2D::dynamics::B2Body b){
{
		HX_SOURCE_PUSH("B2World_obj::destroyBody")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",207)
		if (((this->isLocked() == true))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",208)
			return null();
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",213)
		::box2D::dynamics::joints::B2JointEdge jn = b->m_jointList;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",214)
		while(((jn != null()))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",216)
			::box2D::dynamics::joints::B2JointEdge jn0 = jn;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",217)
			jn = jn->next;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",219)
			if (((this->m_destructionListener != null()))){
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",220)
				this->m_destructionListener->sayGoodbyeJoint(jn0->joint);
			}
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",224)
			this->destroyJoint(jn0->joint);
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",228)
		::box2D::dynamics::controllers::B2ControllerEdge coe = b->m_controllerList;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",229)
		while(((coe != null()))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",231)
			::box2D::dynamics::controllers::B2ControllerEdge coe0 = coe;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",232)
			coe = coe->nextController;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",233)
			coe0->controller->removeBody(b);
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",237)
		::box2D::dynamics::contacts::B2ContactEdge ce = b->m_contactList;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",238)
		while(((ce != null()))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",240)
			::box2D::dynamics::contacts::B2ContactEdge ce0 = ce;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",241)
			ce = ce->next;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",242)
			this->m_contactManager->destroy(ce0->contact);
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",244)
		b->m_contactList = null();
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",248)
		::box2D::dynamics::B2Fixture f = b->m_fixtureList;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",249)
		while(((f != null()))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",251)
			::box2D::dynamics::B2Fixture f0 = f;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",252)
			f = f->m_next;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",254)
			if (((this->m_destructionListener != null()))){
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",255)
				this->m_destructionListener->sayGoodbyeFixture(f0);
			}
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",259)
			f0->destroyProxy(this->m_contactManager->m_broadPhase);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",260)
			f0->destroy();
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",265)
		b->m_fixtureList = null();
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",266)
		b->m_fixtureCount = (int)0;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",269)
		if (((b->m_prev != null()))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",270)
			b->m_prev->m_next = b->m_next;
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",274)
		if (((b->m_next != null()))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",275)
			b->m_next->m_prev = b->m_prev;
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",279)
		if (((b == this->m_bodyList))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",280)
			this->m_bodyList = b->m_next;
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",284)
		--(this->m_bodyCount);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2World_obj,destroyBody,(void))

::box2D::dynamics::joints::B2Joint B2World_obj::createJoint( ::box2D::dynamics::joints::B2JointDef def){
	HX_SOURCE_PUSH("B2World_obj::createJoint")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",299)
	::box2D::dynamics::joints::B2Joint j = ::box2D::dynamics::joints::B2Joint_obj::create(def,null());
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",302)
	j->m_prev = null();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",303)
	j->m_next = this->m_jointList;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",304)
	if (((this->m_jointList != null()))){
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",305)
		this->m_jointList->m_prev = j;
	}
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",308)
	this->m_jointList = j;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",309)
	++(this->m_jointCount);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",312)
	j->m_edgeA->joint = j;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",313)
	j->m_edgeA->other = j->m_bodyB;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",314)
	j->m_edgeA->prev = null();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",315)
	j->m_edgeA->next = j->m_bodyA->m_jointList;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",316)
	if (((j->m_bodyA->m_jointList != null()))){
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",316)
		j->m_bodyA->m_jointList->prev = j->m_edgeA;
	}
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",317)
	j->m_bodyA->m_jointList = j->m_edgeA;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",319)
	j->m_edgeB->joint = j;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",320)
	j->m_edgeB->other = j->m_bodyA;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",321)
	j->m_edgeB->prev = null();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",322)
	j->m_edgeB->next = j->m_bodyB->m_jointList;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",323)
	if (((j->m_bodyB->m_jointList != null()))){
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",323)
		j->m_bodyB->m_jointList->prev = j->m_edgeB;
	}
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",324)
	j->m_bodyB->m_jointList = j->m_edgeB;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",326)
	::box2D::dynamics::B2Body bodyA = def->bodyA;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",327)
	::box2D::dynamics::B2Body bodyB = def->bodyB;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",330)
	if (((def->collideConnected == false))){
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",332)
		::box2D::dynamics::contacts::B2ContactEdge edge = bodyB->getContactList();
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",333)
		while(((edge != null()))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",335)
			if (((edge->other == bodyA))){
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",336)
				edge->contact->flagForFiltering();
			}
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",342)
			edge = edge->next;
		}
	}
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",348)
	return j;
}


HX_DEFINE_DYNAMIC_FUNC1(B2World_obj,createJoint,return )

Void B2World_obj::destroyJoint( ::box2D::dynamics::joints::B2Joint j){
{
		HX_SOURCE_PUSH("B2World_obj::destroyJoint")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",360)
		bool collideConnected = j->m_collideConnected;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",363)
		if (((j->m_prev != null()))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",364)
			j->m_prev->m_next = j->m_next;
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",368)
		if (((j->m_next != null()))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",369)
			j->m_next->m_prev = j->m_prev;
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",373)
		if (((j == this->m_jointList))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",374)
			this->m_jointList = j->m_next;
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",379)
		::box2D::dynamics::B2Body bodyA = j->m_bodyA;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",380)
		::box2D::dynamics::B2Body bodyB = j->m_bodyB;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",383)
		bodyA->setAwake(true);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",384)
		bodyB->setAwake(true);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",387)
		if (((j->m_edgeA->prev != null()))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",388)
			j->m_edgeA->prev->next = j->m_edgeA->next;
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",392)
		if (((j->m_edgeA->next != null()))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",393)
			j->m_edgeA->next->prev = j->m_edgeA->prev;
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",397)
		if (((j->m_edgeA == bodyA->m_jointList))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",398)
			bodyA->m_jointList = j->m_edgeA->next;
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",402)
		j->m_edgeA->prev = null();
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",403)
		j->m_edgeA->next = null();
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",406)
		if (((j->m_edgeB->prev != null()))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",407)
			j->m_edgeB->prev->next = j->m_edgeB->next;
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",411)
		if (((j->m_edgeB->next != null()))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",412)
			j->m_edgeB->next->prev = j->m_edgeB->prev;
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",416)
		if (((j->m_edgeB == bodyB->m_jointList))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",417)
			bodyB->m_jointList = j->m_edgeB->next;
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",421)
		j->m_edgeB->prev = null();
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",422)
		j->m_edgeB->next = null();
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",424)
		::box2D::dynamics::joints::B2Joint_obj::destroy(j,null());
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",427)
		--(this->m_jointCount);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",430)
		if (((collideConnected == false))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",432)
			::box2D::dynamics::contacts::B2ContactEdge edge = bodyB->getContactList();
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",433)
			while(((edge != null()))){
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",435)
				if (((edge->other == bodyA))){
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",436)
					edge->contact->flagForFiltering();
				}
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",442)
				edge = edge->next;
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2World_obj,destroyJoint,(void))

::box2D::dynamics::controllers::B2Controller B2World_obj::addController( ::box2D::dynamics::controllers::B2Controller c){
	HX_SOURCE_PUSH("B2World_obj::addController")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",453)
	c->m_next = this->m_controllerList;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",454)
	c->m_prev = null();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",455)
	this->m_controllerList = c;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",457)
	c->m_world = hx::ObjectPtr<OBJ_>(this);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",459)
	(this->m_controllerCount)++;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",461)
	return c;
}


HX_DEFINE_DYNAMIC_FUNC1(B2World_obj,addController,return )

Void B2World_obj::removeController( ::box2D::dynamics::controllers::B2Controller c){
{
		HX_SOURCE_PUSH("B2World_obj::removeController")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",467)
		if (((c->m_prev != null()))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",468)
			c->m_prev->m_next = c->m_next;
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",469)
		if (((c->m_next != null()))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",470)
			c->m_next->m_prev = c->m_prev;
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",471)
		if (((this->m_controllerList == c))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",472)
			this->m_controllerList = c->m_next;
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",474)
		(this->m_controllerCount)--;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2World_obj,removeController,(void))

::box2D::dynamics::controllers::B2Controller B2World_obj::createController( ::box2D::dynamics::controllers::B2Controller controller){
	HX_SOURCE_PUSH("B2World_obj::createController")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",479)
	if (((controller->m_world != hx::ObjectPtr<OBJ_>(this)))){
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",480)
		hx::Throw (HX_CSTRING("Controller can only be a member of one world"));
	}
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",483)
	controller->m_next = this->m_controllerList;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",484)
	controller->m_prev = null();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",485)
	if (((this->m_controllerList != null()))){
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",486)
		this->m_controllerList->m_prev = controller;
	}
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",487)
	this->m_controllerList = controller;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",488)
	++(this->m_controllerCount);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",490)
	controller->m_world = hx::ObjectPtr<OBJ_>(this);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",492)
	return controller;
}


HX_DEFINE_DYNAMIC_FUNC1(B2World_obj,createController,return )

Void B2World_obj::destroyController( ::box2D::dynamics::controllers::B2Controller controller){
{
		HX_SOURCE_PUSH("B2World_obj::destroyController")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",498)
		controller->clear();
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",499)
		if (((controller->m_next != null()))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",500)
			controller->m_next->m_prev = controller->m_prev;
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",501)
		if (((controller->m_prev != null()))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",502)
			controller->m_prev->m_next = controller->m_next;
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",503)
		if (((controller == this->m_controllerList))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",504)
			this->m_controllerList = controller->m_next;
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",505)
		--(this->m_controllerCount);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2World_obj,destroyController,(void))

Void B2World_obj::setWarmStarting( bool flag){
{
		HX_SOURCE_PUSH("B2World_obj::setWarmStarting")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",511)
		::box2D::dynamics::B2World_obj::m_warmStarting = flag;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2World_obj,setWarmStarting,(void))

Void B2World_obj::setContinuousPhysics( bool flag){
{
		HX_SOURCE_PUSH("B2World_obj::setContinuousPhysics")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",516)
		::box2D::dynamics::B2World_obj::m_continuousPhysics = flag;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2World_obj,setContinuousPhysics,(void))

int B2World_obj::getBodyCount( ){
	HX_SOURCE_PUSH("B2World_obj::getBodyCount")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",522)
	return this->m_bodyCount;
}


HX_DEFINE_DYNAMIC_FUNC0(B2World_obj,getBodyCount,return )

int B2World_obj::getJointCount( ){
	HX_SOURCE_PUSH("B2World_obj::getJointCount")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",530)
	return this->m_jointCount;
}


HX_DEFINE_DYNAMIC_FUNC0(B2World_obj,getJointCount,return )

int B2World_obj::getContactCount( ){
	HX_SOURCE_PUSH("B2World_obj::getContactCount")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",538)
	return this->m_contactCount;
}


HX_DEFINE_DYNAMIC_FUNC0(B2World_obj,getContactCount,return )

Void B2World_obj::setGravity( ::box2D::common::math::B2Vec2 gravity){
{
		HX_SOURCE_PUSH("B2World_obj::setGravity")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",546)
		this->m_gravity = gravity;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2World_obj,setGravity,(void))

::box2D::common::math::B2Vec2 B2World_obj::getGravity( ){
	HX_SOURCE_PUSH("B2World_obj::getGravity")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",553)
	return this->m_gravity;
}


HX_DEFINE_DYNAMIC_FUNC0(B2World_obj,getGravity,return )

::box2D::dynamics::B2Body B2World_obj::getGroundBody( ){
	HX_SOURCE_PUSH("B2World_obj::getGroundBody")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",561)
	return this->m_groundBody;
}


HX_DEFINE_DYNAMIC_FUNC0(B2World_obj,getGroundBody,return )

Void B2World_obj::step( double dt,int velocityIterations,int positionIterations){
{
		HX_SOURCE_PUSH("B2World_obj::step")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",574)
		if (((((int(this->m_flags) & int(::box2D::dynamics::B2World_obj::e_newFixture))) != (int)0))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",576)
			this->m_contactManager->findNewContacts();
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",577)
			hx::AndEq(this->m_flags,~(int)(::box2D::dynamics::B2World_obj::e_newFixture));
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",580)
		hx::OrEq(this->m_flags,::box2D::dynamics::B2World_obj::e_locked);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",582)
		::box2D::dynamics::B2TimeStep step = ::box2D::dynamics::B2World_obj::s_timestep2;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",583)
		step->dt = dt;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",584)
		step->velocityIterations = velocityIterations;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",585)
		step->positionIterations = positionIterations;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",586)
		if (((dt > 0.0))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",587)
			step->inv_dt = (double(1.0) / double(dt));
		}
		else{
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",591)
			step->inv_dt = 0.0;
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",595)
		step->dtRatio = (this->m_inv_dt0 * dt);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",597)
		step->warmStarting = ::box2D::dynamics::B2World_obj::m_warmStarting;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",600)
		this->m_contactManager->collide();
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",603)
		if (((step->dt > 0.0))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",604)
			this->solve(step);
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",609)
		if (((bool(::box2D::dynamics::B2World_obj::m_continuousPhysics) && bool((step->dt > 0.0))))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",610)
			this->solveTOI(step);
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",614)
		if (((step->dt > 0.0))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",615)
			this->m_inv_dt0 = step->inv_dt;
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",618)
		hx::AndEq(this->m_flags,~(int)(::box2D::dynamics::B2World_obj::e_locked));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(B2World_obj,step,(void))

Void B2World_obj::clearForces( ){
{
		HX_SOURCE_PUSH("B2World_obj::clearForces")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",627)
		::box2D::dynamics::B2Body body = this->m_bodyList;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",628)
		while(((body != null()))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",630)
			body->m_force->setZero();
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",631)
			body->m_torque = 0.0;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",632)
			body = body->m_next;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(B2World_obj,clearForces,(void))

Void B2World_obj::drawDebugData( ){
{
		HX_SOURCE_PUSH("B2World_obj::drawDebugData")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",642)
		if (((this->m_debugDraw == null()))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",643)
			return null();
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",647)
		this->m_debugDraw->m_sprite->nmeGetGraphics()->clear();
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",649)
		int flags = this->m_debugDraw->getFlags();
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",651)
		int i;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",652)
		::box2D::dynamics::B2Body b;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",653)
		::box2D::dynamics::B2Fixture f;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",654)
		::box2D::collision::shapes::B2Shape s;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",655)
		::box2D::dynamics::joints::B2Joint j;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",656)
		::box2D::collision::IBroadPhase bp;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",657)
		::box2D::common::math::B2Vec2 invQ = ::box2D::common::math::B2Vec2_obj::__new(null(),null());
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",658)
		::box2D::common::math::B2Vec2 x1 = ::box2D::common::math::B2Vec2_obj::__new(null(),null());
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",659)
		::box2D::common::math::B2Vec2 x2 = ::box2D::common::math::B2Vec2_obj::__new(null(),null());
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",660)
		::box2D::common::math::B2Transform xf;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",661)
		::box2D::collision::B2AABB b1 = ::box2D::collision::B2AABB_obj::__new();
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",662)
		::box2D::collision::B2AABB b2 = ::box2D::collision::B2AABB_obj::__new();
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",663)
		Array< ::box2D::common::math::B2Vec2 > vs = Array_obj< ::box2D::common::math::B2Vec2 >::__new().Add(::box2D::common::math::B2Vec2_obj::__new(null(),null())).Add(::box2D::common::math::B2Vec2_obj::__new(null(),null())).Add(::box2D::common::math::B2Vec2_obj::__new(null(),null())).Add(::box2D::common::math::B2Vec2_obj::__new(null(),null()));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",666)
		::box2D::common::B2Color color = ::box2D::common::B2Color_obj::__new((int)0,(int)0,(int)0);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",668)
		if (((((int(flags) & int(::box2D::dynamics::B2DebugDraw_obj::e_shapeBit))) != (int)0))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",670)
			b = this->m_bodyList;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",671)
			while(((b != null()))){
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",673)
				xf = b->m_xf;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",674)
				f = b->getFixtureList();
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",675)
				while(((f != null()))){
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",677)
					s = f->getShape();
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",678)
					if (((b->isActive() == false))){
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",680)
						color->set(0.5,0.5,0.3);
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",681)
						this->drawShape(s,xf,color);
					}
					else{
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",683)
						if (((b->getType() == ::box2D::dynamics::B2Body_obj::b2_staticBody))){
							HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",685)
							color->set(0.5,0.9,0.5);
							HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",686)
							this->drawShape(s,xf,color);
						}
						else{
							HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",688)
							if (((b->getType() == ::box2D::dynamics::B2Body_obj::b2_kinematicBody))){
								HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",690)
								color->set(0.5,0.5,0.9);
								HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",691)
								this->drawShape(s,xf,color);
							}
							else{
								HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",693)
								if (((b->isAwake() == false))){
									HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",695)
									color->set(0.6,0.6,0.6);
									HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",696)
									this->drawShape(s,xf,color);
								}
								else{
									HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",700)
									color->set(0.9,0.7,0.7);
									HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",701)
									this->drawShape(s,xf,color);
								}
							}
						}
					}
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",703)
					f = f->m_next;
				}
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",705)
				b = b->m_next;
			}
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",709)
		if (((((int(flags) & int(::box2D::dynamics::B2DebugDraw_obj::e_jointBit))) != (int)0))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",711)
			j = this->m_jointList;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",712)
			while(((j != null()))){
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",714)
				this->drawJoint(j);
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",715)
				j = j->m_next;
			}
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",719)
		if (((((int(flags) & int(::box2D::dynamics::B2DebugDraw_obj::e_controllerBit))) != (int)0))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",721)
			::box2D::dynamics::controllers::B2Controller c = this->m_controllerList;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",722)
			while(((c != null()))){
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",724)
				c->draw(this->m_debugDraw);
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",725)
				c = c->m_next;
			}
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",729)
		if (((((int(flags) & int(::box2D::dynamics::B2DebugDraw_obj::e_pairBit))) != (int)0))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",731)
			color->set(0.3,0.9,0.9);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",732)
			::box2D::dynamics::contacts::B2Contact contact = this->m_contactManager->m_contactList;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",733)
			while(((contact != null()))){
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",735)
				::box2D::dynamics::B2Fixture fixtureA = contact->getFixtureA();
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",736)
				::box2D::dynamics::B2Fixture fixtureB = contact->getFixtureB();
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",738)
				::box2D::common::math::B2Vec2 cA = fixtureA->getAABB()->getCenter();
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",739)
				::box2D::common::math::B2Vec2 cB = fixtureB->getAABB()->getCenter();
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",741)
				this->m_debugDraw->drawSegment(cA,cB,color);
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",742)
				contact = contact->getNext();
			}
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",746)
		if (((((int(flags) & int(::box2D::dynamics::B2DebugDraw_obj::e_aabbBit))) != (int)0))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",748)
			bp = this->m_contactManager->m_broadPhase;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",750)
			vs = Array_obj< ::box2D::common::math::B2Vec2 >::__new().Add(::box2D::common::math::B2Vec2_obj::__new(null(),null())).Add(::box2D::common::math::B2Vec2_obj::__new(null(),null())).Add(::box2D::common::math::B2Vec2_obj::__new(null(),null())).Add(::box2D::common::math::B2Vec2_obj::__new(null(),null()));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",752)
			b = this->m_bodyList;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",753)
			while(((b != null()))){
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",755)
				if (((b->isActive() == false))){
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",757)
					b = b->getNext();
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",758)
					continue;
				}
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",760)
				f = b->getFixtureList();
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",761)
				while(((f != null()))){
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",763)
					::box2D::collision::B2AABB aabb = bp->getFatAABB(f->m_proxy);
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",764)
					vs->__get((int)0)->set(aabb->lowerBound->x,aabb->lowerBound->y);
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",765)
					vs->__get((int)1)->set(aabb->upperBound->x,aabb->lowerBound->y);
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",766)
					vs->__get((int)2)->set(aabb->upperBound->x,aabb->upperBound->y);
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",767)
					vs->__get((int)3)->set(aabb->lowerBound->x,aabb->upperBound->y);
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",769)
					this->m_debugDraw->drawPolygon(vs,(int)4,color);
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",770)
					f = f->getNext();
				}
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",772)
				b = b->getNext();
			}
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",776)
		if (((((int(flags) & int(::box2D::dynamics::B2DebugDraw_obj::e_centerOfMassBit))) != (int)0))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",778)
			b = this->m_bodyList;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",779)
			while(((b != null()))){
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",781)
				xf = ::box2D::dynamics::B2World_obj::s_xf;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",782)
				xf->R = b->m_xf->R;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",783)
				xf->position = b->getWorldCenter();
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",784)
				this->m_debugDraw->drawTransform(xf);
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",785)
				b = b->m_next;
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(B2World_obj,drawDebugData,(void))

Void B2World_obj::queryAABB( Dynamic callbackMethod,::box2D::collision::B2AABB aabb){
{
		HX_SOURCE_PUSH("B2World_obj::queryAABB")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",798)
		Dynamic callbackMethod1 = Dynamic( Array_obj<Dynamic>::__new().Add(callbackMethod));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",800)
		Array< ::box2D::collision::IBroadPhase > broadPhase = Array_obj< ::box2D::collision::IBroadPhase >::__new().Add(this->m_contactManager->m_broadPhase);

		HX_BEGIN_LOCAL_FUNC_S2(hx::LocalFunc,_Function_1_1,Dynamic,callbackMethod1,Array< ::box2D::collision::IBroadPhase >,broadPhase)
		bool run(Dynamic proxy){
{
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",802)
				return callbackMethod1->__GetItem((int)0)(broadPhase->__get((int)0)->getUserData(proxy));
			}
			return null();
		}
		HX_END_LOCAL_FUNC1(return)

		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",801)
		Dynamic worldQueryWrapper =  Dynamic(new _Function_1_1(callbackMethod1,broadPhase));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",805)
		broadPhase->__get((int)0)->query(worldQueryWrapper,aabb);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(B2World_obj,queryAABB,(void))

Void B2World_obj::queryShape( Dynamic callbackMethod,::box2D::collision::shapes::B2Shape shape,::box2D::common::math::B2Transform transform){
{
		HX_SOURCE_PUSH("B2World_obj::queryShape")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",815)
		Array< ::box2D::common::math::B2Transform > transform1 = Array_obj< ::box2D::common::math::B2Transform >::__new().Add(transform);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",815)
		Array< ::box2D::collision::shapes::B2Shape > shape1 = Array_obj< ::box2D::collision::shapes::B2Shape >::__new().Add(shape);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",815)
		Dynamic callbackMethod1 = Dynamic( Array_obj<Dynamic>::__new().Add(callbackMethod));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",817)
		if (((transform1->__get((int)0) == null()))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",819)
			transform1[(int)0] = ::box2D::common::math::B2Transform_obj::__new(null(),null());
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",820)
			transform1->__get((int)0)->setIdentity();
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",822)
		Array< ::box2D::collision::IBroadPhase > broadPhase = Array_obj< ::box2D::collision::IBroadPhase >::__new().Add(this->m_contactManager->m_broadPhase);

		HX_BEGIN_LOCAL_FUNC_S4(hx::LocalFunc,_Function_1_1,Array< ::box2D::collision::IBroadPhase >,broadPhase,Array< ::box2D::collision::shapes::B2Shape >,shape1,Array< ::box2D::common::math::B2Transform >,transform1,Dynamic,callbackMethod1)
		bool run(Dynamic proxy){
{
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",825)
				::box2D::dynamics::B2Fixture fixture = hx::TCast< box2D::dynamics::B2Fixture >::cast(broadPhase->__get((int)0)->getUserData(proxy));
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",826)
				if ((::box2D::collision::shapes::B2Shape_obj::testOverlap(shape1->__get((int)0),transform1->__get((int)0),fixture->getShape(),fixture->getBody()->getTransform()))){
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",827)
					return callbackMethod1->__GetItem((int)0)(fixture);
				}
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",828)
				return true;
			}
			return null();
		}
		HX_END_LOCAL_FUNC1(return)

		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",823)
		Dynamic worldQueryWrapper =  Dynamic(new _Function_1_1(broadPhase,shape1,transform1,callbackMethod1));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",830)
		::box2D::collision::B2AABB aabb = ::box2D::collision::B2AABB_obj::__new();
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",831)
		shape1->__get((int)0)->computeAABB(aabb,transform1->__get((int)0));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",832)
		broadPhase->__get((int)0)->query(worldQueryWrapper,aabb);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(B2World_obj,queryShape,(void))

Void B2World_obj::queryPoint( Dynamic callbackMethod,::box2D::common::math::B2Vec2 p){
{
		HX_SOURCE_PUSH("B2World_obj::queryPoint")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",842)
		Array< ::box2D::common::math::B2Vec2 > p1 = Array_obj< ::box2D::common::math::B2Vec2 >::__new().Add(p);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",842)
		Dynamic callbackMethod1 = Dynamic( Array_obj<Dynamic>::__new().Add(callbackMethod));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",844)
		Array< ::box2D::collision::IBroadPhase > broadPhase = Array_obj< ::box2D::collision::IBroadPhase >::__new().Add(this->m_contactManager->m_broadPhase);

		HX_BEGIN_LOCAL_FUNC_S3(hx::LocalFunc,_Function_1_1,Array< ::box2D::collision::IBroadPhase >,broadPhase,Array< ::box2D::common::math::B2Vec2 >,p1,Dynamic,callbackMethod1)
		bool run(Dynamic proxy){
{
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",847)
				::box2D::dynamics::B2Fixture fixture = hx::TCast< box2D::dynamics::B2Fixture >::cast(broadPhase->__get((int)0)->getUserData(proxy));
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",848)
				if ((fixture->testPoint(p1->__get((int)0)))){
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",849)
					return callbackMethod1->__GetItem((int)0)(fixture);
				}
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",850)
				return true;
			}
			return null();
		}
		HX_END_LOCAL_FUNC1(return)

		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",845)
		Dynamic worldQueryWrapper =  Dynamic(new _Function_1_1(broadPhase,p1,callbackMethod1));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",853)
		::box2D::collision::B2AABB aabb = ::box2D::collision::B2AABB_obj::__new();
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",854)
		aabb->lowerBound->set((p1->__get((int)0)->x - ::box2D::common::B2Settings_obj::b2_linearSlop),(p1->__get((int)0)->y - ::box2D::common::B2Settings_obj::b2_linearSlop));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",855)
		aabb->upperBound->set((p1->__get((int)0)->x + ::box2D::common::B2Settings_obj::b2_linearSlop),(p1->__get((int)0)->y + ::box2D::common::B2Settings_obj::b2_linearSlop));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",856)
		broadPhase->__get((int)0)->query(worldQueryWrapper,aabb);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(B2World_obj,queryPoint,(void))

Void B2World_obj::rayCast( Dynamic callbackMethod,::box2D::common::math::B2Vec2 point1,::box2D::common::math::B2Vec2 point2){
{
		HX_SOURCE_PUSH("B2World_obj::rayCast")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",877)
		Array< ::box2D::common::math::B2Vec2 > point21 = Array_obj< ::box2D::common::math::B2Vec2 >::__new().Add(point2);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",877)
		Array< ::box2D::common::math::B2Vec2 > point11 = Array_obj< ::box2D::common::math::B2Vec2 >::__new().Add(point1);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",877)
		Dynamic callbackMethod1 = Dynamic( Array_obj<Dynamic>::__new().Add(callbackMethod));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",879)
		Array< ::box2D::collision::IBroadPhase > broadPhase = Array_obj< ::box2D::collision::IBroadPhase >::__new().Add(this->m_contactManager->m_broadPhase);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",880)
		Array< ::box2D::collision::B2RayCastOutput > output = Array_obj< ::box2D::collision::B2RayCastOutput >::__new().Add(::box2D::collision::B2RayCastOutput_obj::__new());

		HX_BEGIN_LOCAL_FUNC_S5(hx::LocalFunc,_Function_1_1,Array< ::box2D::collision::IBroadPhase >,broadPhase,Array< ::box2D::collision::B2RayCastOutput >,output,Array< ::box2D::common::math::B2Vec2 >,point11,Array< ::box2D::common::math::B2Vec2 >,point21,Dynamic,callbackMethod1)
		double run(::box2D::collision::B2RayCastInput input,Dynamic proxy){
{
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",883)
				Dynamic userData = broadPhase->__get((int)0)->getUserData(proxy);
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",884)
				::box2D::dynamics::B2Fixture fixture = hx::TCast< box2D::dynamics::B2Fixture >::cast(userData);
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",885)
				bool hit = fixture->rayCast(output->__get((int)0),input);
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",886)
				if ((hit)){
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",888)
					double fraction = output->__get((int)0)->fraction;
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",889)
					::box2D::common::math::B2Vec2 point = ::box2D::common::math::B2Vec2_obj::__new(((((1.0 - fraction)) * point11->__get((int)0)->x) + (fraction * point21->__get((int)0)->x)),((((1.0 - fraction)) * point11->__get((int)0)->y) + (fraction * point21->__get((int)0)->y)));
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",892)
					return callbackMethod1->__GetItem((int)0)(fixture,point,output->__get((int)0)->normal,fraction);
				}
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",894)
				return input->maxFraction;
			}
			return null();
		}
		HX_END_LOCAL_FUNC2(return)

		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",881)
		Dynamic rayCastWrapper =  Dynamic(new _Function_1_1(broadPhase,output,point11,point21,callbackMethod1));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",896)
		::box2D::collision::B2RayCastInput input = ::box2D::collision::B2RayCastInput_obj::__new(point11->__get((int)0),point21->__get((int)0),null());
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",897)
		broadPhase->__get((int)0)->rayCast(rayCastWrapper,input);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(B2World_obj,rayCast,(void))

::box2D::dynamics::B2Fixture B2World_obj::rayCastOne( ::box2D::common::math::B2Vec2 point1,::box2D::common::math::B2Vec2 point2){
	HX_SOURCE_PUSH("B2World_obj::rayCastOne")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",902)
	Array< ::box2D::dynamics::B2Fixture > result = Array_obj< ::box2D::dynamics::B2Fixture >::__new();

	HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_1_1,Array< ::box2D::dynamics::B2Fixture >,result)
	double run(::box2D::dynamics::B2Fixture fixture,::box2D::common::math::B2Vec2 point,::box2D::common::math::B2Vec2 normal,double fraction){
{
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",905)
			result[(int)0] = fixture;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",906)
			return fraction;
		}
		return null();
	}
	HX_END_LOCAL_FUNC4(return)

	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",903)
	Dynamic rayCastOneWrapper =  Dynamic(new _Function_1_1(result));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",908)
	this->rayCast(rayCastOneWrapper,point1,point2);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",909)
	return result->__get((int)0);
}


HX_DEFINE_DYNAMIC_FUNC2(B2World_obj,rayCastOne,return )

Array< ::box2D::dynamics::B2Fixture > B2World_obj::rayCastAll( ::box2D::common::math::B2Vec2 point1,::box2D::common::math::B2Vec2 point2){
	HX_SOURCE_PUSH("B2World_obj::rayCastAll")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",914)
	Array< Array< ::box2D::dynamics::B2Fixture > > result = Array_obj< Array< ::box2D::dynamics::B2Fixture > >::__new().Add(Array_obj< ::box2D::dynamics::B2Fixture >::__new());

	HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_1_1,Array< Array< ::box2D::dynamics::B2Fixture > >,result)
	double run(::box2D::dynamics::B2Fixture fixture,::box2D::common::math::B2Vec2 point,::box2D::common::math::B2Vec2 normal,double fraction){
{
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",917)
			result->__get((int)0)[result->__get((int)0)->length] = fixture;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",918)
			return (int)1;
		}
		return null();
	}
	HX_END_LOCAL_FUNC4(return)

	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",915)
	Dynamic rayCastAllWrapper =  Dynamic(new _Function_1_1(result));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",920)
	this->rayCast(rayCastAllWrapper,point1,point2);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",921)
	return result->__get((int)0);
}


HX_DEFINE_DYNAMIC_FUNC2(B2World_obj,rayCastAll,return )

::box2D::dynamics::B2Body B2World_obj::getBodyList( ){
	HX_SOURCE_PUSH("B2World_obj::getBodyList")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",929)
	return this->m_bodyList;
}


HX_DEFINE_DYNAMIC_FUNC0(B2World_obj,getBodyList,return )

::box2D::dynamics::joints::B2Joint B2World_obj::getJointList( ){
	HX_SOURCE_PUSH("B2World_obj::getJointList")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",938)
	return this->m_jointList;
}


HX_DEFINE_DYNAMIC_FUNC0(B2World_obj,getJointList,return )

::box2D::dynamics::contacts::B2Contact B2World_obj::getContactList( ){
	HX_SOURCE_PUSH("B2World_obj::getContactList")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",949)
	return this->m_contactList;
}


HX_DEFINE_DYNAMIC_FUNC0(B2World_obj,getContactList,return )

bool B2World_obj::isLocked( ){
	HX_SOURCE_PUSH("B2World_obj::isLocked")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",957)
	return (((int(this->m_flags) & int(::box2D::dynamics::B2World_obj::e_locked))) > (int)0);
}


HX_DEFINE_DYNAMIC_FUNC0(B2World_obj,isLocked,return )

Void B2World_obj::solve( ::box2D::dynamics::B2TimeStep step){
{
		HX_SOURCE_PUSH("B2World_obj::solve")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",967)
		::box2D::dynamics::B2Body b;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",970)
		::box2D::dynamics::controllers::B2Controller controller = this->m_controllerList;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",971)
		while(((controller != null()))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",973)
			controller->step(step);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",974)
			controller = controller->m_next;
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",978)
		::box2D::dynamics::B2Island island = this->m_island;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",979)
		island->initialize(this->m_bodyCount,this->m_contactCount,this->m_jointCount,null(),this->m_contactManager->m_contactListener,this->m_contactSolver);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",982)
		b = this->m_bodyList;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",983)
		while(((b != null()))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",985)
			hx::AndEq(b->m_flags,~(int)(::box2D::dynamics::B2Body_obj::e_islandFlag));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",986)
			b = b->m_next;
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",988)
		::box2D::dynamics::contacts::B2Contact c = this->m_contactList;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",989)
		while(((c != null()))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",991)
			hx::AndEq(c->m_flags,~(int)(::box2D::dynamics::contacts::B2Contact_obj::e_islandFlag));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",992)
			c = c->m_next;
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",994)
		::box2D::dynamics::joints::B2Joint j = this->m_jointList;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",995)
		while(((j != null()))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",997)
			j->m_islandFlag = false;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",998)
			j = j->m_next;
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1002)
		int stackSize = this->m_bodyCount;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1004)
		Array< ::box2D::dynamics::B2Body > stack = this->s_stack;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1005)
		::box2D::dynamics::B2Body seed = this->m_bodyList;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1006)
		while(((seed != null()))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1008)
			if (((((int(seed->m_flags) & int(::box2D::dynamics::B2Body_obj::e_islandFlag))) != (int)0))){
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1010)
				seed = seed->m_next;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1011)
				continue;
			}
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1014)
			if (((bool((seed->isAwake() == false)) || bool((seed->isActive() == false))))){
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1016)
				seed = seed->m_next;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1017)
				continue;
			}
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1021)
			if (((seed->getType() == ::box2D::dynamics::B2Body_obj::b2_staticBody))){
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1023)
				seed = seed->m_next;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1024)
				continue;
			}
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1028)
			island->clear();
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1029)
			int stackCount = (int)0;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1030)
			stack[(stackCount)++] = seed;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1031)
			hx::OrEq(seed->m_flags,::box2D::dynamics::B2Body_obj::e_islandFlag);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1034)
			while(((stackCount > (int)0))){
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1037)
				b = stack->__get(--(stackCount));
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1039)
				island->addBody(b);
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1042)
				if (((b->isAwake() == false))){
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1043)
					b->setAwake(true);
				}
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1049)
				if (((b->getType() == ::box2D::dynamics::B2Body_obj::b2_staticBody))){
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1050)
					continue;
				}
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1054)
				::box2D::dynamics::B2Body other;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1056)
				::box2D::dynamics::contacts::B2ContactEdge ce = b->m_contactList;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1057)
				while(((ce != null()))){
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1060)
					if (((((int(ce->contact->m_flags) & int(::box2D::dynamics::contacts::B2Contact_obj::e_islandFlag))) != (int)0))){
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1062)
						ce = ce->next;
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1063)
						continue;
					}
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1067)
					if (((bool((bool((ce->contact->isSensor() == true)) || bool((ce->contact->isEnabled() == false)))) || bool((ce->contact->isTouching() == false))))){
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1071)
						ce = ce->next;
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1072)
						continue;
					}
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1075)
					island->addContact(ce->contact);
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1076)
					hx::OrEq(ce->contact->m_flags,::box2D::dynamics::contacts::B2Contact_obj::e_islandFlag);
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1079)
					other = ce->other;
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1082)
					if (((((int(other->m_flags) & int(::box2D::dynamics::B2Body_obj::e_islandFlag))) != (int)0))){
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1084)
						ce = ce->next;
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1085)
						continue;
					}
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1089)
					stack[(stackCount)++] = other;
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1090)
					hx::OrEq(other->m_flags,::box2D::dynamics::B2Body_obj::e_islandFlag);
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1091)
					ce = ce->next;
				}
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1095)
				::box2D::dynamics::joints::B2JointEdge jn = b->m_jointList;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1096)
				while(((jn != null()))){
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1098)
					if (((jn->joint->m_islandFlag == true))){
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1100)
						jn = jn->next;
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1101)
						continue;
					}
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1104)
					other = jn->other;
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1107)
					if (((other->isActive() == false))){
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1109)
						jn = jn->next;
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1110)
						continue;
					}
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1113)
					island->addJoint(jn->joint);
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1114)
					jn->joint->m_islandFlag = true;
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1116)
					if (((((int(other->m_flags) & int(::box2D::dynamics::B2Body_obj::e_islandFlag))) != (int)0))){
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1118)
						jn = jn->next;
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1119)
						continue;
					}
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1123)
					stack[(stackCount)++] = other;
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1124)
					hx::OrEq(other->m_flags,::box2D::dynamics::B2Body_obj::e_islandFlag);
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1125)
					jn = jn->next;
				}
			}
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1128)
			island->solve(step,this->m_gravity,this->m_allowSleep);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1131)
			{
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1131)
				int _g1 = (int)0;
				int _g = island->m_bodyCount;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1131)
				while(((_g1 < _g))){
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1131)
					int i = (_g1)++;
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1134)
					b = island->m_bodies->__get(i);
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1135)
					if (((b->getType() == ::box2D::dynamics::B2Body_obj::b2_staticBody))){
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1136)
						hx::AndEq(b->m_flags,~(int)(::box2D::dynamics::B2Body_obj::e_islandFlag));
					}
				}
			}
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1140)
			seed = seed->m_next;
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1144)
		{
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1144)
			int _g1 = (int)0;
			int _g = stack->length;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1144)
			while(((_g1 < _g))){
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1144)
				int i = (_g1)++;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1146)
				if (((stack->__get(i) == null()))){
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1146)
					break;
				}
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1147)
				stack[i] = null();
			}
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1151)
		b = this->m_bodyList;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1152)
		while(((b != null()))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1154)
			if (((bool((b->isAwake() == false)) || bool((b->isActive() == false))))){
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1156)
				b = b->m_next;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1157)
				continue;
			}
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1160)
			if (((b->getType() == ::box2D::dynamics::B2Body_obj::b2_staticBody))){
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1162)
				b = b->m_next;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1163)
				continue;
			}
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1167)
			b->synchronizeFixtures();
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1168)
			b = b->m_next;
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1172)
		this->m_contactManager->findNewContacts();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2World_obj,solve,(void))

Void B2World_obj::solveTOI( ::box2D::dynamics::B2TimeStep step){
{
		HX_SOURCE_PUSH("B2World_obj::solveTOI")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1183)
		::box2D::dynamics::B2Body b;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1184)
		::box2D::dynamics::B2Fixture fA;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1185)
		::box2D::dynamics::B2Fixture fB;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1186)
		::box2D::dynamics::B2Body bA;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1187)
		::box2D::dynamics::B2Body bB;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1188)
		::box2D::dynamics::contacts::B2ContactEdge cEdge;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1189)
		::box2D::dynamics::joints::B2Joint j;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1192)
		::box2D::dynamics::B2Island island = this->m_island;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1193)
		island->initialize(this->m_bodyCount,::box2D::common::B2Settings_obj::b2_maxTOIContactsPerIsland,::box2D::common::B2Settings_obj::b2_maxTOIJointsPerIsland,null(),this->m_contactManager->m_contactListener,this->m_contactSolver);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1204)
		Array< ::box2D::dynamics::B2Body > queue = ::box2D::dynamics::B2World_obj::s_queue;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1206)
		b = this->m_bodyList;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1207)
		while(((b != null()))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1209)
			hx::AndEq(b->m_flags,~(int)(::box2D::dynamics::B2Body_obj::e_islandFlag));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1210)
			b->m_sweep->t0 = 0.0;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1211)
			b = b->m_next;
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1214)
		::box2D::dynamics::contacts::B2Contact c = this->m_contactList;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1215)
		while(((c != null()))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1218)
			hx::AndEq(c->m_flags,~(int)(((int(::box2D::dynamics::contacts::B2Contact_obj::e_toiFlag) | int(::box2D::dynamics::contacts::B2Contact_obj::e_islandFlag)))));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1219)
			c = c->m_next;
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1222)
		j = this->m_jointList;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1223)
		while(((j != null()))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1225)
			j->m_islandFlag = false;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1226)
			j = j->m_next;
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1232)
		while((true)){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1235)
			::box2D::dynamics::contacts::B2Contact minContact = null();
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1236)
			double minTOI = 1.0;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1238)
			c = this->m_contactList;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1239)
			while(((c != null()))){
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1242)
				if (((bool((bool((c->isSensor() == true)) || bool((c->isEnabled() == false)))) || bool((c->isContinuous() == false))))){
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1246)
					c = c->m_next;
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1247)
					continue;
				}
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1252)
				double toi = 1.0;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1253)
				if (((((int(c->m_flags) & int(::box2D::dynamics::contacts::B2Contact_obj::e_toiFlag))) != (int)0))){
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1254)
					toi = c->m_toi;
				}
				else{
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1261)
					fA = c->m_fixtureA;
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1262)
					fB = c->m_fixtureB;
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1263)
					bA = fA->m_body;
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1264)
					bB = fB->m_body;
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1266)
					if (((bool(((bool((bA->getType() != ::box2D::dynamics::B2Body_obj::b2_dynamicBody)) || bool((bA->isAwake() == false))))) && bool(((bool((bB->getType() != ::box2D::dynamics::B2Body_obj::b2_dynamicBody)) || bool((bB->isAwake() == false)))))))){
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1269)
						c = c->m_next;
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1270)
						continue;
					}
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1274)
					double t0 = bA->m_sweep->t0;
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1276)
					if (((bA->m_sweep->t0 < bB->m_sweep->t0))){
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1278)
						t0 = bB->m_sweep->t0;
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1279)
						bA->m_sweep->advance(t0);
					}
					else{
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1281)
						if (((bB->m_sweep->t0 < bA->m_sweep->t0))){
							HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1283)
							t0 = bA->m_sweep->t0;
							HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1284)
							bB->m_sweep->advance(t0);
						}
					}
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1290)
					toi = c->computeTOI(bA->m_sweep,bB->m_sweep);
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1291)
					::box2D::common::B2Settings_obj::b2Assert((bool((0.0 <= toi)) && bool((toi <= 1.0))));
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1294)
					if (((bool((toi > 0.0)) && bool((toi < 1.0))))){
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1298)
						toi = ((((1.0 - toi)) * t0) + toi);
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1299)
						if (((toi > (int)1))){
							HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1299)
							toi = (int)1;
						}
					}
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1303)
					c->m_toi = toi;
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1304)
					hx::OrEq(c->m_flags,::box2D::dynamics::contacts::B2Contact_obj::e_toiFlag);
				}
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1307)
				if (((bool((2.2250738585072014e-308 < toi)) && bool((toi < minTOI))))){
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1310)
					minContact = c;
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1311)
					minTOI = toi;
				}
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1314)
				c = c->m_next;
			}
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1317)
			if (((bool((minContact == null())) || bool(((1.0 - (100.0 * 2.2250738585072014e-308)) < minTOI))))){
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1318)
				break;
			}
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1324)
			fA = minContact->m_fixtureA;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1325)
			fB = minContact->m_fixtureB;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1326)
			bA = fA->m_body;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1327)
			bB = fB->m_body;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1328)
			::box2D::dynamics::B2World_obj::s_backupA->set(bA->m_sweep);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1329)
			::box2D::dynamics::B2World_obj::s_backupB->set(bB->m_sweep);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1330)
			bA->advance(minTOI);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1331)
			bB->advance(minTOI);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1334)
			minContact->update(this->m_contactManager->m_contactListener);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1335)
			hx::AndEq(minContact->m_flags,~(int)(::box2D::dynamics::contacts::B2Contact_obj::e_toiFlag));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1338)
			if (((bool((minContact->isSensor() == true)) || bool((minContact->isEnabled() == false))))){
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1342)
				bA->m_sweep->set(::box2D::dynamics::B2World_obj::s_backupA);
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1343)
				bB->m_sweep->set(::box2D::dynamics::B2World_obj::s_backupB);
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1344)
				bA->synchronizeTransform();
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1345)
				bB->synchronizeTransform();
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1346)
				continue;
			}
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1350)
			if (((minContact->isTouching() == false))){
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1351)
				continue;
			}
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1357)
			::box2D::dynamics::B2Body seed = bA;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1358)
			if (((seed->getType() != ::box2D::dynamics::B2Body_obj::b2_dynamicBody))){
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1359)
				seed = bB;
			}
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1364)
			island->clear();
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1365)
			int queueStart = (int)0;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1366)
			int queueSize = (int)0;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1367)
			queue[(queueStart + (queueSize)++)] = seed;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1368)
			hx::OrEq(seed->m_flags,::box2D::dynamics::B2Body_obj::e_islandFlag);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1371)
			while(((queueSize > (int)0))){
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1374)
				b = queue->__get((queueStart)++);
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1375)
				--(queueSize);
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1377)
				island->addBody(b);
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1380)
				if (((b->isAwake() == false))){
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1381)
					b->setAwake(true);
				}
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1387)
				if (((b->getType() != ::box2D::dynamics::B2Body_obj::b2_dynamicBody))){
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1388)
					continue;
				}
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1393)
				cEdge = b->m_contactList;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1394)
				::box2D::dynamics::B2Body other;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1395)
				while(((cEdge != null()))){
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1398)
					if (((island->m_contactCount == island->m_contactCapacity))){
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1400)
						cEdge = cEdge->next;
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1401)
						break;
					}
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1405)
					if (((((int(cEdge->contact->m_flags) & int(::box2D::dynamics::contacts::B2Contact_obj::e_islandFlag))) != (int)0))){
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1407)
						cEdge = cEdge->next;
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1408)
						continue;
					}
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1412)
					if (((bool((bool((cEdge->contact->isSensor() == true)) || bool((cEdge->contact->isEnabled() == false)))) || bool((cEdge->contact->isTouching() == false))))){
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1416)
						cEdge = cEdge->next;
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1417)
						continue;
					}
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1420)
					island->addContact(cEdge->contact);
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1421)
					hx::OrEq(cEdge->contact->m_flags,::box2D::dynamics::contacts::B2Contact_obj::e_islandFlag);
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1424)
					other = cEdge->other;
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1427)
					if (((((int(other->m_flags) & int(::box2D::dynamics::B2Body_obj::e_islandFlag))) != (int)0))){
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1429)
						cEdge = cEdge->next;
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1430)
						continue;
					}
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1434)
					if (((other->getType() != ::box2D::dynamics::B2Body_obj::b2_staticBody))){
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1436)
						other->advance(minTOI);
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1437)
						other->setAwake(true);
					}
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1441)
					queue[(queueStart + queueSize)] = other;
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1442)
					++(queueSize);
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1443)
					hx::OrEq(other->m_flags,::box2D::dynamics::B2Body_obj::e_islandFlag);
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1444)
					cEdge = cEdge->next;
				}
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1447)
				::box2D::dynamics::joints::B2JointEdge jEdge = b->m_jointList;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1448)
				while(((jEdge != null()))){
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1450)
					if (((island->m_jointCount == island->m_jointCapacity))){
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1451)
						jEdge = jEdge->next;
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1452)
						continue;
					}
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1455)
					if (((jEdge->joint->m_islandFlag == true))){
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1456)
						jEdge = jEdge->next;
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1457)
						continue;
					}
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1460)
					other = jEdge->other;
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1461)
					if (((other->isActive() == false))){
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1463)
						jEdge = jEdge->next;
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1464)
						continue;
					}
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1467)
					island->addJoint(jEdge->joint);
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1468)
					jEdge->joint->m_islandFlag = true;
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1470)
					if (((((int(other->m_flags) & int(::box2D::dynamics::B2Body_obj::e_islandFlag))) != (int)0))){
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1471)
						jEdge = jEdge->next;
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1472)
						continue;
					}
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1476)
					if (((other->getType() != ::box2D::dynamics::B2Body_obj::b2_staticBody))){
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1478)
						other->advance(minTOI);
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1479)
						other->setAwake(true);
					}
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1483)
					queue[(queueStart + queueSize)] = other;
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1484)
					++(queueSize);
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1485)
					hx::OrEq(other->m_flags,::box2D::dynamics::B2Body_obj::e_islandFlag);
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1486)
					jEdge = jEdge->next;
				}
			}
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1490)
			::box2D::dynamics::B2TimeStep subStep = ::box2D::dynamics::B2World_obj::s_timestep;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1491)
			subStep->warmStarting = false;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1492)
			subStep->dt = (((1.0 - minTOI)) * step->dt);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1493)
			subStep->inv_dt = (double(1.0) / double(subStep->dt));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1494)
			subStep->dtRatio = 0.0;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1495)
			subStep->velocityIterations = step->velocityIterations;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1496)
			subStep->positionIterations = step->positionIterations;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1498)
			island->solveTOI(subStep);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1500)
			int i;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1502)
			{
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1502)
				int _g1 = (int)0;
				int _g = island->m_bodyCount;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1502)
				while(((_g1 < _g))){
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1502)
					int i1 = (_g1)++;
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1505)
					b = island->m_bodies->__get(i1);
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1506)
					hx::AndEq(b->m_flags,~(int)(::box2D::dynamics::B2Body_obj::e_islandFlag));
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1508)
					if (((b->isAwake() == false))){
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1509)
						continue;
					}
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1513)
					if (((b->getType() != ::box2D::dynamics::B2Body_obj::b2_dynamicBody))){
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1514)
						continue;
					}
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1519)
					b->synchronizeFixtures();
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1523)
					cEdge = b->m_contactList;
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1524)
					while(((cEdge != null()))){
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1526)
						hx::AndEq(cEdge->contact->m_flags,~(int)(::box2D::dynamics::contacts::B2Contact_obj::e_toiFlag));
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1527)
						cEdge = cEdge->next;
					}
				}
			}
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1531)
			{
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1531)
				int _g1 = (int)0;
				int _g = island->m_contactCount;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1531)
				while(((_g1 < _g))){
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1531)
					int i1 = (_g1)++;
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1534)
					c = island->m_contacts->__get(i1);
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1535)
					hx::AndEq(c->m_flags,~(int)(((int(::box2D::dynamics::contacts::B2Contact_obj::e_toiFlag) | int(::box2D::dynamics::contacts::B2Contact_obj::e_islandFlag)))));
				}
			}
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1538)
			{
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1538)
				int _g1 = (int)0;
				int _g = island->m_jointCount;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1538)
				while(((_g1 < _g))){
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1538)
					int i1 = (_g1)++;
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1541)
					j = island->m_joints->__get(i1);
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1542)
					j->m_islandFlag = false;
				}
			}
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1547)
			this->m_contactManager->findNewContacts();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2World_obj,solveTOI,(void))

Void B2World_obj::drawJoint( ::box2D::dynamics::joints::B2Joint joint){
{
		HX_SOURCE_PUSH("B2World_obj::drawJoint")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1557)
		::box2D::dynamics::B2Body b1 = joint->getBodyA();
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1558)
		::box2D::dynamics::B2Body b2 = joint->getBodyB();
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1559)
		::box2D::common::math::B2Transform xf1 = b1->m_xf;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1560)
		::box2D::common::math::B2Transform xf2 = b2->m_xf;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1561)
		::box2D::common::math::B2Vec2 x1 = xf1->position;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1562)
		::box2D::common::math::B2Vec2 x2 = xf2->position;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1563)
		::box2D::common::math::B2Vec2 p1 = joint->getAnchorA();
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1564)
		::box2D::common::math::B2Vec2 p2 = joint->getAnchorB();
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1567)
		::box2D::common::B2Color color = ::box2D::dynamics::B2World_obj::s_jointColor;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1569)
		int _switch_1 = (joint->m_type);
		if (  ( _switch_1==::box2D::dynamics::joints::B2Joint_obj::e_distanceJoint)){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1571)
			this->m_debugDraw->drawSegment(p1,p2,color);
		}
		else if (  ( _switch_1==::box2D::dynamics::joints::B2Joint_obj::e_pulleyJoint)){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1576)
			::box2D::dynamics::joints::B2PulleyJoint pulley = hx::TCast< box2D::dynamics::joints::B2PulleyJoint >::cast(joint);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1577)
			::box2D::common::math::B2Vec2 s1 = pulley->getGroundAnchorA();
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1578)
			::box2D::common::math::B2Vec2 s2 = pulley->getGroundAnchorB();
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1579)
			this->m_debugDraw->drawSegment(s1,p1,color);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1580)
			this->m_debugDraw->drawSegment(s2,p2,color);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1581)
			this->m_debugDraw->drawSegment(s1,s2,color);
		}
		else if (  ( _switch_1==::box2D::dynamics::joints::B2Joint_obj::e_mouseJoint)){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1584)
			this->m_debugDraw->drawSegment(p1,p2,color);
		}
		else  {
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1588)
			if (((b1 != this->m_groundBody))){
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1589)
				this->m_debugDraw->drawSegment(x1,p1,color);
			}
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1590)
			this->m_debugDraw->drawSegment(p1,p2,color);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1591)
			if (((b2 != this->m_groundBody))){
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1592)
				this->m_debugDraw->drawSegment(x2,p2,color);
			}
		}
;
;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2World_obj,drawJoint,(void))

Void B2World_obj::drawShape( ::box2D::collision::shapes::B2Shape shape,::box2D::common::math::B2Transform xf,::box2D::common::B2Color color){
{
		HX_SOURCE_PUSH("B2World_obj::drawShape")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1596)
		int _switch_2 = (shape->m_type);
		if (  ( _switch_2==::box2D::collision::shapes::B2Shape_obj::e_circleShape)){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1602)
			::box2D::collision::shapes::B2CircleShape circle = hx::TCast< box2D::collision::shapes::B2CircleShape >::cast(shape);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1604)
			::box2D::common::math::B2Vec2 center = ::box2D::common::math::B2Math_obj::mulX(xf,circle->m_p);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1605)
			double radius = circle->m_radius;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1606)
			::box2D::common::math::B2Vec2 axis = xf->R->col1;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1608)
			this->m_debugDraw->drawSolidCircle(center,radius,axis,color);
		}
		else if (  ( _switch_2==::box2D::collision::shapes::B2Shape_obj::e_polygonShape)){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1613)
			int i;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1614)
			::box2D::collision::shapes::B2PolygonShape poly = hx::TCast< box2D::collision::shapes::B2PolygonShape >::cast(shape);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1615)
			int vertexCount = poly->getVertexCount();
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1616)
			Array< ::box2D::common::math::B2Vec2 > localVertices = poly->getVertices();
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1618)
			Array< ::box2D::common::math::B2Vec2 > vertices = Array_obj< ::box2D::common::math::B2Vec2 >::__new();
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1620)
			{
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1620)
				int _g = (int)0;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1620)
				while(((_g < vertexCount))){
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1620)
					int i1 = (_g)++;
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1622)
					vertices[i1] = ::box2D::common::math::B2Math_obj::mulX(xf,localVertices->__get(i1));
				}
			}
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1625)
			this->m_debugDraw->drawSolidPolygon(vertices,vertexCount,color);
		}
		else if (  ( _switch_2==::box2D::collision::shapes::B2Shape_obj::e_edgeShape)){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1630)
			::box2D::collision::shapes::B2EdgeShape edge = hx::TCast< box2D::collision::shapes::B2EdgeShape >::cast(shape);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2World.hx",1632)
			this->m_debugDraw->drawSegment(::box2D::common::math::B2Math_obj::mulX(xf,edge->getVertex1()),::box2D::common::math::B2Math_obj::mulX(xf,edge->getVertex2()),color);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(B2World_obj,drawShape,(void))

::box2D::dynamics::B2TimeStep B2World_obj::s_timestep2;

::box2D::common::math::B2Transform B2World_obj::s_xf;

::box2D::common::math::B2Sweep B2World_obj::s_backupA;

::box2D::common::math::B2Sweep B2World_obj::s_backupB;

::box2D::dynamics::B2TimeStep B2World_obj::s_timestep;

Array< ::box2D::dynamics::B2Body > B2World_obj::s_queue;

::box2D::common::B2Color B2World_obj::s_jointColor;

bool B2World_obj::m_warmStarting;

bool B2World_obj::m_continuousPhysics;

int B2World_obj::e_newFixture;

int B2World_obj::e_locked;


B2World_obj::B2World_obj()
{
}

void B2World_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(B2World);
	HX_MARK_MEMBER_NAME(s_stack,"s_stack");
	HX_MARK_MEMBER_NAME(m_flags,"m_flags");
	HX_MARK_MEMBER_NAME(m_contactManager,"m_contactManager");
	HX_MARK_MEMBER_NAME(m_contactSolver,"m_contactSolver");
	HX_MARK_MEMBER_NAME(m_island,"m_island");
	HX_MARK_MEMBER_NAME(m_bodyList,"m_bodyList");
	HX_MARK_MEMBER_NAME(m_jointList,"m_jointList");
	HX_MARK_MEMBER_NAME(m_contactList,"m_contactList");
	HX_MARK_MEMBER_NAME(m_bodyCount,"m_bodyCount");
	HX_MARK_MEMBER_NAME(m_contactCount,"m_contactCount");
	HX_MARK_MEMBER_NAME(m_jointCount,"m_jointCount");
	HX_MARK_MEMBER_NAME(m_controllerList,"m_controllerList");
	HX_MARK_MEMBER_NAME(m_controllerCount,"m_controllerCount");
	HX_MARK_MEMBER_NAME(m_gravity,"m_gravity");
	HX_MARK_MEMBER_NAME(m_allowSleep,"m_allowSleep");
	HX_MARK_MEMBER_NAME(m_groundBody,"m_groundBody");
	HX_MARK_MEMBER_NAME(m_destructionListener,"m_destructionListener");
	HX_MARK_MEMBER_NAME(m_debugDraw,"m_debugDraw");
	HX_MARK_MEMBER_NAME(m_inv_dt0,"m_inv_dt0");
	HX_MARK_END_CLASS();
}

Dynamic B2World_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"s_xf") ) { return s_xf; }
		if (HX_FIELD_EQ(inName,"step") ) { return step_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"solve") ) { return solve_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"s_queue") ) { return s_queue; }
		if (HX_FIELD_EQ(inName,"rayCast") ) { return rayCast_dyn(); }
		if (HX_FIELD_EQ(inName,"s_stack") ) { return s_stack; }
		if (HX_FIELD_EQ(inName,"m_flags") ) { return m_flags; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"e_locked") ) { return e_locked; }
		if (HX_FIELD_EQ(inName,"validate") ) { return validate_dyn(); }
		if (HX_FIELD_EQ(inName,"isLocked") ) { return isLocked_dyn(); }
		if (HX_FIELD_EQ(inName,"solveTOI") ) { return solveTOI_dyn(); }
		if (HX_FIELD_EQ(inName,"m_island") ) { return m_island; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"s_backupA") ) { return s_backupA; }
		if (HX_FIELD_EQ(inName,"s_backupB") ) { return s_backupB; }
		if (HX_FIELD_EQ(inName,"queryAABB") ) { return queryAABB_dyn(); }
		if (HX_FIELD_EQ(inName,"drawJoint") ) { return drawJoint_dyn(); }
		if (HX_FIELD_EQ(inName,"drawShape") ) { return drawShape_dyn(); }
		if (HX_FIELD_EQ(inName,"m_gravity") ) { return m_gravity; }
		if (HX_FIELD_EQ(inName,"m_inv_dt0") ) { return m_inv_dt0; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"s_timestep") ) { return s_timestep; }
		if (HX_FIELD_EQ(inName,"createBody") ) { return createBody_dyn(); }
		if (HX_FIELD_EQ(inName,"setGravity") ) { return setGravity_dyn(); }
		if (HX_FIELD_EQ(inName,"getGravity") ) { return getGravity_dyn(); }
		if (HX_FIELD_EQ(inName,"queryShape") ) { return queryShape_dyn(); }
		if (HX_FIELD_EQ(inName,"queryPoint") ) { return queryPoint_dyn(); }
		if (HX_FIELD_EQ(inName,"rayCastOne") ) { return rayCastOne_dyn(); }
		if (HX_FIELD_EQ(inName,"rayCastAll") ) { return rayCastAll_dyn(); }
		if (HX_FIELD_EQ(inName,"m_bodyList") ) { return m_bodyList; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"s_timestep2") ) { return s_timestep2; }
		if (HX_FIELD_EQ(inName,"destroyBody") ) { return destroyBody_dyn(); }
		if (HX_FIELD_EQ(inName,"createJoint") ) { return createJoint_dyn(); }
		if (HX_FIELD_EQ(inName,"clearForces") ) { return clearForces_dyn(); }
		if (HX_FIELD_EQ(inName,"getBodyList") ) { return getBodyList_dyn(); }
		if (HX_FIELD_EQ(inName,"m_jointList") ) { return m_jointList; }
		if (HX_FIELD_EQ(inName,"m_bodyCount") ) { return m_bodyCount; }
		if (HX_FIELD_EQ(inName,"m_debugDraw") ) { return m_debugDraw; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"s_jointColor") ) { return s_jointColor; }
		if (HX_FIELD_EQ(inName,"e_newFixture") ) { return e_newFixture; }
		if (HX_FIELD_EQ(inName,"setDebugDraw") ) { return setDebugDraw_dyn(); }
		if (HX_FIELD_EQ(inName,"destroyJoint") ) { return destroyJoint_dyn(); }
		if (HX_FIELD_EQ(inName,"getBodyCount") ) { return getBodyCount_dyn(); }
		if (HX_FIELD_EQ(inName,"getJointList") ) { return getJointList_dyn(); }
		if (HX_FIELD_EQ(inName,"m_jointCount") ) { return m_jointCount; }
		if (HX_FIELD_EQ(inName,"m_allowSleep") ) { return m_allowSleep; }
		if (HX_FIELD_EQ(inName,"m_groundBody") ) { return m_groundBody; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"setBroadPhase") ) { return setBroadPhase_dyn(); }
		if (HX_FIELD_EQ(inName,"getProxyCount") ) { return getProxyCount_dyn(); }
		if (HX_FIELD_EQ(inName,"addController") ) { return addController_dyn(); }
		if (HX_FIELD_EQ(inName,"getJointCount") ) { return getJointCount_dyn(); }
		if (HX_FIELD_EQ(inName,"getGroundBody") ) { return getGroundBody_dyn(); }
		if (HX_FIELD_EQ(inName,"drawDebugData") ) { return drawDebugData_dyn(); }
		if (HX_FIELD_EQ(inName,"m_contactList") ) { return m_contactList; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"m_warmStarting") ) { return m_warmStarting; }
		if (HX_FIELD_EQ(inName,"getContactList") ) { return getContactList_dyn(); }
		if (HX_FIELD_EQ(inName,"m_contactCount") ) { return m_contactCount; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"setWarmStarting") ) { return setWarmStarting_dyn(); }
		if (HX_FIELD_EQ(inName,"getContactCount") ) { return getContactCount_dyn(); }
		if (HX_FIELD_EQ(inName,"m_contactSolver") ) { return m_contactSolver; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"setContactFilter") ) { return setContactFilter_dyn(); }
		if (HX_FIELD_EQ(inName,"removeController") ) { return removeController_dyn(); }
		if (HX_FIELD_EQ(inName,"createController") ) { return createController_dyn(); }
		if (HX_FIELD_EQ(inName,"m_contactManager") ) { return m_contactManager; }
		if (HX_FIELD_EQ(inName,"m_controllerList") ) { return m_controllerList; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"destroyController") ) { return destroyController_dyn(); }
		if (HX_FIELD_EQ(inName,"m_controllerCount") ) { return m_controllerCount; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"setContactListener") ) { return setContactListener_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"m_continuousPhysics") ) { return m_continuousPhysics; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"setContinuousPhysics") ) { return setContinuousPhysics_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"m_destructionListener") ) { return m_destructionListener; }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"setDestructionListener") ) { return setDestructionListener_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic B2World_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"s_xf") ) { s_xf=inValue.Cast< ::box2D::common::math::B2Transform >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"s_queue") ) { s_queue=inValue.Cast< Array< ::box2D::dynamics::B2Body > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"s_stack") ) { s_stack=inValue.Cast< Array< ::box2D::dynamics::B2Body > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_flags") ) { m_flags=inValue.Cast< int >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"e_locked") ) { e_locked=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_island") ) { m_island=inValue.Cast< ::box2D::dynamics::B2Island >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"s_backupA") ) { s_backupA=inValue.Cast< ::box2D::common::math::B2Sweep >(); return inValue; }
		if (HX_FIELD_EQ(inName,"s_backupB") ) { s_backupB=inValue.Cast< ::box2D::common::math::B2Sweep >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_gravity") ) { m_gravity=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_inv_dt0") ) { m_inv_dt0=inValue.Cast< double >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"s_timestep") ) { s_timestep=inValue.Cast< ::box2D::dynamics::B2TimeStep >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_bodyList") ) { m_bodyList=inValue.Cast< ::box2D::dynamics::B2Body >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"s_timestep2") ) { s_timestep2=inValue.Cast< ::box2D::dynamics::B2TimeStep >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_jointList") ) { m_jointList=inValue.Cast< ::box2D::dynamics::joints::B2Joint >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_bodyCount") ) { m_bodyCount=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_debugDraw") ) { m_debugDraw=inValue.Cast< ::box2D::dynamics::B2DebugDraw >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"s_jointColor") ) { s_jointColor=inValue.Cast< ::box2D::common::B2Color >(); return inValue; }
		if (HX_FIELD_EQ(inName,"e_newFixture") ) { e_newFixture=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_jointCount") ) { m_jointCount=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_allowSleep") ) { m_allowSleep=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_groundBody") ) { m_groundBody=inValue.Cast< ::box2D::dynamics::B2Body >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"m_contactList") ) { m_contactList=inValue.Cast< ::box2D::dynamics::contacts::B2Contact >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"m_warmStarting") ) { m_warmStarting=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_contactCount") ) { m_contactCount=inValue.Cast< int >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"m_contactSolver") ) { m_contactSolver=inValue.Cast< ::box2D::dynamics::contacts::B2ContactSolver >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"m_contactManager") ) { m_contactManager=inValue.Cast< ::box2D::dynamics::B2ContactManager >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_controllerList") ) { m_controllerList=inValue.Cast< ::box2D::dynamics::controllers::B2Controller >(); return inValue; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"m_controllerCount") ) { m_controllerCount=inValue.Cast< int >(); return inValue; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"m_continuousPhysics") ) { m_continuousPhysics=inValue.Cast< bool >(); return inValue; }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"m_destructionListener") ) { m_destructionListener=inValue.Cast< ::box2D::dynamics::B2DestructionListener >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void B2World_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("s_stack"));
	outFields->push(HX_CSTRING("m_flags"));
	outFields->push(HX_CSTRING("m_contactManager"));
	outFields->push(HX_CSTRING("m_contactSolver"));
	outFields->push(HX_CSTRING("m_island"));
	outFields->push(HX_CSTRING("m_bodyList"));
	outFields->push(HX_CSTRING("m_jointList"));
	outFields->push(HX_CSTRING("m_contactList"));
	outFields->push(HX_CSTRING("m_bodyCount"));
	outFields->push(HX_CSTRING("m_contactCount"));
	outFields->push(HX_CSTRING("m_jointCount"));
	outFields->push(HX_CSTRING("m_controllerList"));
	outFields->push(HX_CSTRING("m_controllerCount"));
	outFields->push(HX_CSTRING("m_gravity"));
	outFields->push(HX_CSTRING("m_allowSleep"));
	outFields->push(HX_CSTRING("m_groundBody"));
	outFields->push(HX_CSTRING("m_destructionListener"));
	outFields->push(HX_CSTRING("m_debugDraw"));
	outFields->push(HX_CSTRING("m_inv_dt0"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("s_timestep2"),
	HX_CSTRING("s_xf"),
	HX_CSTRING("s_backupA"),
	HX_CSTRING("s_backupB"),
	HX_CSTRING("s_timestep"),
	HX_CSTRING("s_queue"),
	HX_CSTRING("s_jointColor"),
	HX_CSTRING("m_warmStarting"),
	HX_CSTRING("m_continuousPhysics"),
	HX_CSTRING("e_newFixture"),
	HX_CSTRING("e_locked"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("setDestructionListener"),
	HX_CSTRING("setContactFilter"),
	HX_CSTRING("setContactListener"),
	HX_CSTRING("setDebugDraw"),
	HX_CSTRING("setBroadPhase"),
	HX_CSTRING("validate"),
	HX_CSTRING("getProxyCount"),
	HX_CSTRING("createBody"),
	HX_CSTRING("destroyBody"),
	HX_CSTRING("createJoint"),
	HX_CSTRING("destroyJoint"),
	HX_CSTRING("addController"),
	HX_CSTRING("removeController"),
	HX_CSTRING("createController"),
	HX_CSTRING("destroyController"),
	HX_CSTRING("setWarmStarting"),
	HX_CSTRING("setContinuousPhysics"),
	HX_CSTRING("getBodyCount"),
	HX_CSTRING("getJointCount"),
	HX_CSTRING("getContactCount"),
	HX_CSTRING("setGravity"),
	HX_CSTRING("getGravity"),
	HX_CSTRING("getGroundBody"),
	HX_CSTRING("step"),
	HX_CSTRING("clearForces"),
	HX_CSTRING("drawDebugData"),
	HX_CSTRING("queryAABB"),
	HX_CSTRING("queryShape"),
	HX_CSTRING("queryPoint"),
	HX_CSTRING("rayCast"),
	HX_CSTRING("rayCastOne"),
	HX_CSTRING("rayCastAll"),
	HX_CSTRING("getBodyList"),
	HX_CSTRING("getJointList"),
	HX_CSTRING("getContactList"),
	HX_CSTRING("isLocked"),
	HX_CSTRING("s_stack"),
	HX_CSTRING("solve"),
	HX_CSTRING("solveTOI"),
	HX_CSTRING("drawJoint"),
	HX_CSTRING("drawShape"),
	HX_CSTRING("m_flags"),
	HX_CSTRING("m_contactManager"),
	HX_CSTRING("m_contactSolver"),
	HX_CSTRING("m_island"),
	HX_CSTRING("m_bodyList"),
	HX_CSTRING("m_jointList"),
	HX_CSTRING("m_contactList"),
	HX_CSTRING("m_bodyCount"),
	HX_CSTRING("m_contactCount"),
	HX_CSTRING("m_jointCount"),
	HX_CSTRING("m_controllerList"),
	HX_CSTRING("m_controllerCount"),
	HX_CSTRING("m_gravity"),
	HX_CSTRING("m_allowSleep"),
	HX_CSTRING("m_groundBody"),
	HX_CSTRING("m_destructionListener"),
	HX_CSTRING("m_debugDraw"),
	HX_CSTRING("m_inv_dt0"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(B2World_obj::s_timestep2,"s_timestep2");
	HX_MARK_MEMBER_NAME(B2World_obj::s_xf,"s_xf");
	HX_MARK_MEMBER_NAME(B2World_obj::s_backupA,"s_backupA");
	HX_MARK_MEMBER_NAME(B2World_obj::s_backupB,"s_backupB");
	HX_MARK_MEMBER_NAME(B2World_obj::s_timestep,"s_timestep");
	HX_MARK_MEMBER_NAME(B2World_obj::s_queue,"s_queue");
	HX_MARK_MEMBER_NAME(B2World_obj::s_jointColor,"s_jointColor");
	HX_MARK_MEMBER_NAME(B2World_obj::m_warmStarting,"m_warmStarting");
	HX_MARK_MEMBER_NAME(B2World_obj::m_continuousPhysics,"m_continuousPhysics");
	HX_MARK_MEMBER_NAME(B2World_obj::e_newFixture,"e_newFixture");
	HX_MARK_MEMBER_NAME(B2World_obj::e_locked,"e_locked");
};

Class B2World_obj::__mClass;

void B2World_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.dynamics.B2World"), hx::TCanCast< B2World_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void B2World_obj::__boot()
{
	hx::Static(s_timestep2) = ::box2D::dynamics::B2TimeStep_obj::__new();
	hx::Static(s_xf) = ::box2D::common::math::B2Transform_obj::__new(null(),null());
	hx::Static(s_backupA) = ::box2D::common::math::B2Sweep_obj::__new();
	hx::Static(s_backupB) = ::box2D::common::math::B2Sweep_obj::__new();
	hx::Static(s_timestep) = ::box2D::dynamics::B2TimeStep_obj::__new();
	hx::Static(s_queue) = Array_obj< ::box2D::dynamics::B2Body >::__new();
	hx::Static(s_jointColor) = ::box2D::common::B2Color_obj::__new(0.5,0.8,0.8);
	hx::Static(m_warmStarting);
	hx::Static(m_continuousPhysics);
	hx::Static(e_newFixture) = (int)1;
	hx::Static(e_locked) = (int)2;
}

} // end namespace box2D
} // end namespace dynamics
