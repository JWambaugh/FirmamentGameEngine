#include <hxcpp.h>

#ifndef INCLUDED_box2D_collision_B2AABB
#include <box2D/collision/B2AABB.h>
#endif
#ifndef INCLUDED_box2D_collision_B2ContactID
#include <box2D/collision/B2ContactID.h>
#endif
#ifndef INCLUDED_box2D_collision_B2DistanceProxy
#include <box2D/collision/B2DistanceProxy.h>
#endif
#ifndef INCLUDED_box2D_collision_B2Manifold
#include <box2D/collision/B2Manifold.h>
#endif
#ifndef INCLUDED_box2D_collision_B2ManifoldPoint
#include <box2D/collision/B2ManifoldPoint.h>
#endif
#ifndef INCLUDED_box2D_collision_B2TOIInput
#include <box2D/collision/B2TOIInput.h>
#endif
#ifndef INCLUDED_box2D_collision_B2TimeOfImpact
#include <box2D/collision/B2TimeOfImpact.h>
#endif
#ifndef INCLUDED_box2D_collision_B2WorldManifold
#include <box2D/collision/B2WorldManifold.h>
#endif
#ifndef INCLUDED_box2D_collision_shapes_B2Shape
#include <box2D/collision/shapes/B2Shape.h>
#endif
#ifndef INCLUDED_box2D_common_B2Settings
#include <box2D/common/B2Settings.h>
#endif
#ifndef INCLUDED_box2D_common_math_B2Sweep
#include <box2D/common/math/B2Sweep.h>
#endif
#ifndef INCLUDED_box2D_common_math_B2Transform
#include <box2D/common/math/B2Transform.h>
#endif
#ifndef INCLUDED_box2D_dynamics_B2Body
#include <box2D/dynamics/B2Body.h>
#endif
#ifndef INCLUDED_box2D_dynamics_B2ContactListener
#include <box2D/dynamics/B2ContactListener.h>
#endif
#ifndef INCLUDED_box2D_dynamics_B2Fixture
#include <box2D/dynamics/B2Fixture.h>
#endif
#ifndef INCLUDED_box2D_dynamics_contacts_B2Contact
#include <box2D/dynamics/contacts/B2Contact.h>
#endif
#ifndef INCLUDED_box2D_dynamics_contacts_B2ContactEdge
#include <box2D/dynamics/contacts/B2ContactEdge.h>
#endif
namespace box2D{
namespace dynamics{
namespace contacts{

Void B2Contact_obj::__construct()
{
{
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2Contact.hx",186)
	this->m_nodeA = ::box2D::dynamics::contacts::B2ContactEdge_obj::__new();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2Contact.hx",187)
	this->m_nodeB = ::box2D::dynamics::contacts::B2ContactEdge_obj::__new();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2Contact.hx",188)
	this->m_manifold = ::box2D::collision::B2Manifold_obj::__new();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2Contact.hx",189)
	this->m_oldManifold = ::box2D::collision::B2Manifold_obj::__new();
}
;
	return null();
}

B2Contact_obj::~B2Contact_obj() { }

Dynamic B2Contact_obj::__CreateEmpty() { return  new B2Contact_obj; }
hx::ObjectPtr< B2Contact_obj > B2Contact_obj::__new()
{  hx::ObjectPtr< B2Contact_obj > result = new B2Contact_obj();
	result->__construct();
	return result;}

Dynamic B2Contact_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2Contact_obj > result = new B2Contact_obj();
	result->__construct();
	return result;}

::box2D::collision::B2Manifold B2Contact_obj::getManifold( ){
	HX_SOURCE_PUSH("B2Contact_obj::getManifold")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2Contact.hx",54)
	return this->m_manifold;
}


HX_DEFINE_DYNAMIC_FUNC0(B2Contact_obj,getManifold,return )

Void B2Contact_obj::getWorldManifold( ::box2D::collision::B2WorldManifold worldManifold){
{
		HX_SOURCE_PUSH("B2Contact_obj::getWorldManifold")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2Contact.hx",63)
		::box2D::dynamics::B2Body bodyA = this->m_fixtureA->getBody();
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2Contact.hx",64)
		::box2D::dynamics::B2Body bodyB = this->m_fixtureB->getBody();
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2Contact.hx",65)
		::box2D::collision::shapes::B2Shape shapeA = this->m_fixtureA->getShape();
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2Contact.hx",66)
		::box2D::collision::shapes::B2Shape shapeB = this->m_fixtureB->getShape();
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2Contact.hx",68)
		worldManifold->initialize(this->m_manifold,bodyA->getTransform(),shapeA->m_radius,bodyB->getTransform(),shapeB->m_radius);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2Contact_obj,getWorldManifold,(void))

bool B2Contact_obj::isTouching( ){
	HX_SOURCE_PUSH("B2Contact_obj::isTouching")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2Contact.hx",75)
	return (((int(this->m_flags) & int(::box2D::dynamics::contacts::B2Contact_obj::e_touchingFlag))) == ::box2D::dynamics::contacts::B2Contact_obj::e_touchingFlag);
}


HX_DEFINE_DYNAMIC_FUNC0(B2Contact_obj,isTouching,return )

bool B2Contact_obj::isContinuous( ){
	HX_SOURCE_PUSH("B2Contact_obj::isContinuous")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2Contact.hx",83)
	return (((int(this->m_flags) & int(::box2D::dynamics::contacts::B2Contact_obj::e_continuousFlag))) == ::box2D::dynamics::contacts::B2Contact_obj::e_continuousFlag);
}


HX_DEFINE_DYNAMIC_FUNC0(B2Contact_obj,isContinuous,return )

Void B2Contact_obj::setSensor( bool sensor){
{
		HX_SOURCE_PUSH("B2Contact_obj::setSensor")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2Contact.hx",90)
		if ((sensor)){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2Contact.hx",92)
			hx::OrEq(this->m_flags,::box2D::dynamics::contacts::B2Contact_obj::e_sensorFlag);
		}
		else{
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2Contact.hx",96)
			hx::AndEq(this->m_flags,~(int)(::box2D::dynamics::contacts::B2Contact_obj::e_sensorFlag));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2Contact_obj,setSensor,(void))

bool B2Contact_obj::isSensor( ){
	HX_SOURCE_PUSH("B2Contact_obj::isSensor")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2Contact.hx",104)
	return (((int(this->m_flags) & int(::box2D::dynamics::contacts::B2Contact_obj::e_sensorFlag))) == ::box2D::dynamics::contacts::B2Contact_obj::e_sensorFlag);
}


HX_DEFINE_DYNAMIC_FUNC0(B2Contact_obj,isSensor,return )

Void B2Contact_obj::setEnabled( bool flag){
{
		HX_SOURCE_PUSH("B2Contact_obj::setEnabled")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2Contact.hx",113)
		if ((flag)){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2Contact.hx",115)
			hx::OrEq(this->m_flags,::box2D::dynamics::contacts::B2Contact_obj::e_enabledFlag);
		}
		else{
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2Contact.hx",119)
			hx::AndEq(this->m_flags,~(int)(::box2D::dynamics::contacts::B2Contact_obj::e_enabledFlag));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2Contact_obj,setEnabled,(void))

bool B2Contact_obj::isEnabled( ){
	HX_SOURCE_PUSH("B2Contact_obj::isEnabled")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2Contact.hx",128)
	return (((int(this->m_flags) & int(::box2D::dynamics::contacts::B2Contact_obj::e_enabledFlag))) == ::box2D::dynamics::contacts::B2Contact_obj::e_enabledFlag);
}


HX_DEFINE_DYNAMIC_FUNC0(B2Contact_obj,isEnabled,return )

::box2D::dynamics::contacts::B2Contact B2Contact_obj::getNext( ){
	HX_SOURCE_PUSH("B2Contact_obj::getNext")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2Contact.hx",135)
	return this->m_next;
}


HX_DEFINE_DYNAMIC_FUNC0(B2Contact_obj,getNext,return )

::box2D::dynamics::B2Fixture B2Contact_obj::getFixtureA( ){
	HX_SOURCE_PUSH("B2Contact_obj::getFixtureA")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2Contact.hx",143)
	return this->m_fixtureA;
}


HX_DEFINE_DYNAMIC_FUNC0(B2Contact_obj,getFixtureA,return )

::box2D::dynamics::B2Fixture B2Contact_obj::getFixtureB( ){
	HX_SOURCE_PUSH("B2Contact_obj::getFixtureB")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2Contact.hx",151)
	return this->m_fixtureB;
}


HX_DEFINE_DYNAMIC_FUNC0(B2Contact_obj,getFixtureB,return )

Void B2Contact_obj::flagForFiltering( ){
{
		HX_SOURCE_PUSH("B2Contact_obj::flagForFiltering")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2Contact.hx",159)
		hx::OrEq(this->m_flags,::box2D::dynamics::contacts::B2Contact_obj::e_filterFlag);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(B2Contact_obj,flagForFiltering,(void))

Void B2Contact_obj::reset( ::box2D::dynamics::B2Fixture fixtureA,::box2D::dynamics::B2Fixture fixtureB){
{
		HX_SOURCE_PUSH("B2Contact_obj::reset")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2Contact.hx",197)
		this->m_flags = ::box2D::dynamics::contacts::B2Contact_obj::e_enabledFlag;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2Contact.hx",199)
		if (((bool((fixtureA == null())) || bool((fixtureB == null()))))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2Contact.hx",200)
			this->m_fixtureA = null();
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2Contact.hx",201)
			this->m_fixtureB = null();
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2Contact.hx",202)
			return null();
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2Contact.hx",205)
		if (((bool(fixtureA->isSensor()) || bool(fixtureB->isSensor())))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2Contact.hx",206)
			hx::OrEq(this->m_flags,::box2D::dynamics::contacts::B2Contact_obj::e_sensorFlag);
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2Contact.hx",210)
		::box2D::dynamics::B2Body bodyA = fixtureA->getBody();
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2Contact.hx",211)
		::box2D::dynamics::B2Body bodyB = fixtureB->getBody();
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2Contact.hx",213)
		if (((bool((bool((bool((bodyA->getType() != ::box2D::dynamics::B2Body_obj::b2_dynamicBody)) || bool(bodyA->isBullet()))) || bool((bodyB->getType() != ::box2D::dynamics::B2Body_obj::b2_dynamicBody)))) || bool(bodyB->isBullet())))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2Contact.hx",214)
			hx::OrEq(this->m_flags,::box2D::dynamics::contacts::B2Contact_obj::e_continuousFlag);
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2Contact.hx",218)
		this->m_fixtureA = fixtureA;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2Contact.hx",219)
		this->m_fixtureB = fixtureB;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2Contact.hx",221)
		this->m_manifold->m_pointCount = (int)0;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2Contact.hx",223)
		this->m_prev = null();
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2Contact.hx",224)
		this->m_next = null();
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2Contact.hx",226)
		this->m_nodeA->contact = null();
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2Contact.hx",227)
		this->m_nodeA->prev = null();
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2Contact.hx",228)
		this->m_nodeA->next = null();
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2Contact.hx",229)
		this->m_nodeA->other = null();
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2Contact.hx",231)
		this->m_nodeB->contact = null();
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2Contact.hx",232)
		this->m_nodeB->prev = null();
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2Contact.hx",233)
		this->m_nodeB->next = null();
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2Contact.hx",234)
		this->m_nodeB->other = null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(B2Contact_obj,reset,(void))

Void B2Contact_obj::update( ::box2D::dynamics::B2ContactListener listener){
{
		HX_SOURCE_PUSH("B2Contact_obj::update")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2Contact.hx",240)
		::box2D::collision::B2Manifold tManifold = this->m_oldManifold;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2Contact.hx",241)
		this->m_oldManifold = this->m_manifold;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2Contact.hx",242)
		this->m_manifold = tManifold;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2Contact.hx",245)
		hx::OrEq(this->m_flags,::box2D::dynamics::contacts::B2Contact_obj::e_enabledFlag);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2Contact.hx",247)
		bool touching = false;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2Contact.hx",248)
		bool wasTouching = (((int(this->m_flags) & int(::box2D::dynamics::contacts::B2Contact_obj::e_touchingFlag))) == ::box2D::dynamics::contacts::B2Contact_obj::e_touchingFlag);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2Contact.hx",250)
		::box2D::dynamics::B2Body bodyA = this->m_fixtureA->m_body;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2Contact.hx",251)
		::box2D::dynamics::B2Body bodyB = this->m_fixtureB->m_body;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2Contact.hx",253)
		bool aabbOverlap = this->m_fixtureA->m_aabb->testOverlap(this->m_fixtureB->m_aabb);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2Contact.hx",256)
		if (((((int(this->m_flags) & int(::box2D::dynamics::contacts::B2Contact_obj::e_sensorFlag))) != (int)0))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2Contact.hx",258)
			if ((aabbOverlap)){
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2Contact.hx",260)
				::box2D::collision::shapes::B2Shape shapeA = this->m_fixtureA->getShape();
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2Contact.hx",261)
				::box2D::collision::shapes::B2Shape shapeB = this->m_fixtureB->getShape();
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2Contact.hx",262)
				::box2D::common::math::B2Transform xfA = bodyA->getTransform();
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2Contact.hx",263)
				::box2D::common::math::B2Transform xfB = bodyB->getTransform();
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2Contact.hx",264)
				touching = ::box2D::collision::shapes::B2Shape_obj::testOverlap(shapeA,xfA,shapeB,xfB);
			}
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2Contact.hx",268)
			this->m_manifold->m_pointCount = (int)0;
		}
		else{
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2Contact.hx",273)
			if (((bool((bool((bool((bodyA->getType() != ::box2D::dynamics::B2Body_obj::b2_dynamicBody)) || bool(bodyA->isBullet()))) || bool((bodyB->getType() != ::box2D::dynamics::B2Body_obj::b2_dynamicBody)))) || bool(bodyB->isBullet())))){
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2Contact.hx",274)
				hx::OrEq(this->m_flags,::box2D::dynamics::contacts::B2Contact_obj::e_continuousFlag);
			}
			else{
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2Contact.hx",278)
				hx::AndEq(this->m_flags,~(int)(::box2D::dynamics::contacts::B2Contact_obj::e_continuousFlag));
			}
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2Contact.hx",282)
			if ((aabbOverlap)){
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2Contact.hx",284)
				this->evaluate();
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2Contact.hx",286)
				touching = (this->m_manifold->m_pointCount > (int)0);
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2Contact.hx",290)
				{
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2Contact.hx",290)
					int _g1 = (int)0;
					int _g = this->m_manifold->m_pointCount;
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2Contact.hx",290)
					while(((_g1 < _g))){
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2Contact.hx",290)
						int i = (_g1)++;
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2Contact.hx",292)
						::box2D::collision::B2ManifoldPoint mp2 = this->m_manifold->m_points->__get(i);
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2Contact.hx",293)
						mp2->m_normalImpulse = 0.0;
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2Contact.hx",294)
						mp2->m_tangentImpulse = 0.0;
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2Contact.hx",295)
						::box2D::collision::B2ContactID id2 = mp2->m_id;
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2Contact.hx",297)
						{
							HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2Contact.hx",297)
							int _g3 = (int)0;
							int _g2 = this->m_oldManifold->m_pointCount;
							HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2Contact.hx",297)
							while(((_g3 < _g2))){
								HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2Contact.hx",297)
								int j = (_g3)++;
								HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2Contact.hx",299)
								::box2D::collision::B2ManifoldPoint mp1 = this->m_oldManifold->m_points->__get(j);
								HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2Contact.hx",301)
								if (((mp1->m_id->getKey() == id2->getKey()))){
									HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2Contact.hx",303)
									mp2->m_normalImpulse = mp1->m_normalImpulse;
									HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2Contact.hx",304)
									mp2->m_tangentImpulse = mp1->m_tangentImpulse;
									HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2Contact.hx",305)
									break;
								}
							}
						}
					}
				}
			}
			else{
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2Contact.hx",312)
				this->m_manifold->m_pointCount = (int)0;
			}
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2Contact.hx",315)
			if (((touching != wasTouching))){
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2Contact.hx",317)
				bodyA->setAwake(true);
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2Contact.hx",318)
				bodyB->setAwake(true);
			}
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2Contact.hx",322)
		if ((touching)){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2Contact.hx",323)
			hx::OrEq(this->m_flags,::box2D::dynamics::contacts::B2Contact_obj::e_touchingFlag);
		}
		else{
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2Contact.hx",327)
			hx::AndEq(this->m_flags,~(int)(::box2D::dynamics::contacts::B2Contact_obj::e_touchingFlag));
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2Contact.hx",331)
		if (((bool((wasTouching == false)) && bool((touching == true))))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2Contact.hx",332)
			listener->beginContact(hx::ObjectPtr<OBJ_>(this));
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2Contact.hx",336)
		if (((bool((wasTouching == true)) && bool((touching == false))))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2Contact.hx",337)
			listener->endContact(hx::ObjectPtr<OBJ_>(this));
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2Contact.hx",341)
		if (((((int(this->m_flags) & int(::box2D::dynamics::contacts::B2Contact_obj::e_sensorFlag))) == (int)0))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2Contact.hx",342)
			listener->preSolve(hx::ObjectPtr<OBJ_>(this),this->m_oldManifold);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2Contact_obj,update,(void))

Void B2Contact_obj::evaluate( ){
{
		HX_SOURCE_PUSH("B2Contact_obj::evaluate")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(B2Contact_obj,evaluate,(void))

double B2Contact_obj::computeTOI( ::box2D::common::math::B2Sweep sweepA,::box2D::common::math::B2Sweep sweepB){
	HX_SOURCE_PUSH("B2Contact_obj::computeTOI")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2Contact.hx",354)
	::box2D::dynamics::contacts::B2Contact_obj::s_input->proxyA->set(this->m_fixtureA->getShape());
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2Contact.hx",355)
	::box2D::dynamics::contacts::B2Contact_obj::s_input->proxyB->set(this->m_fixtureB->getShape());
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2Contact.hx",356)
	::box2D::dynamics::contacts::B2Contact_obj::s_input->sweepA = sweepA;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2Contact.hx",357)
	::box2D::dynamics::contacts::B2Contact_obj::s_input->sweepB = sweepB;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2Contact.hx",358)
	::box2D::dynamics::contacts::B2Contact_obj::s_input->tolerance = ::box2D::common::B2Settings_obj::b2_linearSlop;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2Contact.hx",359)
	return ::box2D::collision::B2TimeOfImpact_obj::timeOfImpact(::box2D::dynamics::contacts::B2Contact_obj::s_input);
}


HX_DEFINE_DYNAMIC_FUNC2(B2Contact_obj,computeTOI,return )

int B2Contact_obj::e_sensorFlag;

int B2Contact_obj::e_continuousFlag;

int B2Contact_obj::e_islandFlag;

int B2Contact_obj::e_toiFlag;

int B2Contact_obj::e_touchingFlag;

int B2Contact_obj::e_enabledFlag;

int B2Contact_obj::e_filterFlag;

::box2D::collision::B2TOIInput B2Contact_obj::s_input;


B2Contact_obj::B2Contact_obj()
{
}

void B2Contact_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(B2Contact);
	HX_MARK_MEMBER_NAME(m_flags,"m_flags");
	HX_MARK_MEMBER_NAME(m_prev,"m_prev");
	HX_MARK_MEMBER_NAME(m_next,"m_next");
	HX_MARK_MEMBER_NAME(m_nodeA,"m_nodeA");
	HX_MARK_MEMBER_NAME(m_nodeB,"m_nodeB");
	HX_MARK_MEMBER_NAME(m_fixtureA,"m_fixtureA");
	HX_MARK_MEMBER_NAME(m_fixtureB,"m_fixtureB");
	HX_MARK_MEMBER_NAME(m_manifold,"m_manifold");
	HX_MARK_MEMBER_NAME(m_oldManifold,"m_oldManifold");
	HX_MARK_MEMBER_NAME(m_toi,"m_toi");
	HX_MARK_END_CLASS();
}

Dynamic B2Contact_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"reset") ) { return reset_dyn(); }
		if (HX_FIELD_EQ(inName,"m_toi") ) { return m_toi; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		if (HX_FIELD_EQ(inName,"m_prev") ) { return m_prev; }
		if (HX_FIELD_EQ(inName,"m_next") ) { return m_next; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"s_input") ) { return s_input; }
		if (HX_FIELD_EQ(inName,"getNext") ) { return getNext_dyn(); }
		if (HX_FIELD_EQ(inName,"m_flags") ) { return m_flags; }
		if (HX_FIELD_EQ(inName,"m_nodeA") ) { return m_nodeA; }
		if (HX_FIELD_EQ(inName,"m_nodeB") ) { return m_nodeB; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"isSensor") ) { return isSensor_dyn(); }
		if (HX_FIELD_EQ(inName,"evaluate") ) { return evaluate_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"e_toiFlag") ) { return e_toiFlag; }
		if (HX_FIELD_EQ(inName,"setSensor") ) { return setSensor_dyn(); }
		if (HX_FIELD_EQ(inName,"isEnabled") ) { return isEnabled_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"isTouching") ) { return isTouching_dyn(); }
		if (HX_FIELD_EQ(inName,"setEnabled") ) { return setEnabled_dyn(); }
		if (HX_FIELD_EQ(inName,"computeTOI") ) { return computeTOI_dyn(); }
		if (HX_FIELD_EQ(inName,"m_fixtureA") ) { return m_fixtureA; }
		if (HX_FIELD_EQ(inName,"m_fixtureB") ) { return m_fixtureB; }
		if (HX_FIELD_EQ(inName,"m_manifold") ) { return m_manifold; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"getManifold") ) { return getManifold_dyn(); }
		if (HX_FIELD_EQ(inName,"getFixtureA") ) { return getFixtureA_dyn(); }
		if (HX_FIELD_EQ(inName,"getFixtureB") ) { return getFixtureB_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"e_sensorFlag") ) { return e_sensorFlag; }
		if (HX_FIELD_EQ(inName,"e_islandFlag") ) { return e_islandFlag; }
		if (HX_FIELD_EQ(inName,"e_filterFlag") ) { return e_filterFlag; }
		if (HX_FIELD_EQ(inName,"isContinuous") ) { return isContinuous_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"e_enabledFlag") ) { return e_enabledFlag; }
		if (HX_FIELD_EQ(inName,"m_oldManifold") ) { return m_oldManifold; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"e_touchingFlag") ) { return e_touchingFlag; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"e_continuousFlag") ) { return e_continuousFlag; }
		if (HX_FIELD_EQ(inName,"getWorldManifold") ) { return getWorldManifold_dyn(); }
		if (HX_FIELD_EQ(inName,"flagForFiltering") ) { return flagForFiltering_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic B2Contact_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"m_toi") ) { m_toi=inValue.Cast< double >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"m_prev") ) { m_prev=inValue.Cast< ::box2D::dynamics::contacts::B2Contact >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_next") ) { m_next=inValue.Cast< ::box2D::dynamics::contacts::B2Contact >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"s_input") ) { s_input=inValue.Cast< ::box2D::collision::B2TOIInput >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_flags") ) { m_flags=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_nodeA") ) { m_nodeA=inValue.Cast< ::box2D::dynamics::contacts::B2ContactEdge >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_nodeB") ) { m_nodeB=inValue.Cast< ::box2D::dynamics::contacts::B2ContactEdge >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"e_toiFlag") ) { e_toiFlag=inValue.Cast< int >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"m_fixtureA") ) { m_fixtureA=inValue.Cast< ::box2D::dynamics::B2Fixture >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_fixtureB") ) { m_fixtureB=inValue.Cast< ::box2D::dynamics::B2Fixture >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_manifold") ) { m_manifold=inValue.Cast< ::box2D::collision::B2Manifold >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"e_sensorFlag") ) { e_sensorFlag=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"e_islandFlag") ) { e_islandFlag=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"e_filterFlag") ) { e_filterFlag=inValue.Cast< int >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"e_enabledFlag") ) { e_enabledFlag=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_oldManifold") ) { m_oldManifold=inValue.Cast< ::box2D::collision::B2Manifold >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"e_touchingFlag") ) { e_touchingFlag=inValue.Cast< int >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"e_continuousFlag") ) { e_continuousFlag=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void B2Contact_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("m_flags"));
	outFields->push(HX_CSTRING("m_prev"));
	outFields->push(HX_CSTRING("m_next"));
	outFields->push(HX_CSTRING("m_nodeA"));
	outFields->push(HX_CSTRING("m_nodeB"));
	outFields->push(HX_CSTRING("m_fixtureA"));
	outFields->push(HX_CSTRING("m_fixtureB"));
	outFields->push(HX_CSTRING("m_manifold"));
	outFields->push(HX_CSTRING("m_oldManifold"));
	outFields->push(HX_CSTRING("m_toi"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("e_sensorFlag"),
	HX_CSTRING("e_continuousFlag"),
	HX_CSTRING("e_islandFlag"),
	HX_CSTRING("e_toiFlag"),
	HX_CSTRING("e_touchingFlag"),
	HX_CSTRING("e_enabledFlag"),
	HX_CSTRING("e_filterFlag"),
	HX_CSTRING("s_input"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("getManifold"),
	HX_CSTRING("getWorldManifold"),
	HX_CSTRING("isTouching"),
	HX_CSTRING("isContinuous"),
	HX_CSTRING("setSensor"),
	HX_CSTRING("isSensor"),
	HX_CSTRING("setEnabled"),
	HX_CSTRING("isEnabled"),
	HX_CSTRING("getNext"),
	HX_CSTRING("getFixtureA"),
	HX_CSTRING("getFixtureB"),
	HX_CSTRING("flagForFiltering"),
	HX_CSTRING("reset"),
	HX_CSTRING("update"),
	HX_CSTRING("evaluate"),
	HX_CSTRING("computeTOI"),
	HX_CSTRING("m_flags"),
	HX_CSTRING("m_prev"),
	HX_CSTRING("m_next"),
	HX_CSTRING("m_nodeA"),
	HX_CSTRING("m_nodeB"),
	HX_CSTRING("m_fixtureA"),
	HX_CSTRING("m_fixtureB"),
	HX_CSTRING("m_manifold"),
	HX_CSTRING("m_oldManifold"),
	HX_CSTRING("m_toi"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(B2Contact_obj::e_sensorFlag,"e_sensorFlag");
	HX_MARK_MEMBER_NAME(B2Contact_obj::e_continuousFlag,"e_continuousFlag");
	HX_MARK_MEMBER_NAME(B2Contact_obj::e_islandFlag,"e_islandFlag");
	HX_MARK_MEMBER_NAME(B2Contact_obj::e_toiFlag,"e_toiFlag");
	HX_MARK_MEMBER_NAME(B2Contact_obj::e_touchingFlag,"e_touchingFlag");
	HX_MARK_MEMBER_NAME(B2Contact_obj::e_enabledFlag,"e_enabledFlag");
	HX_MARK_MEMBER_NAME(B2Contact_obj::e_filterFlag,"e_filterFlag");
	HX_MARK_MEMBER_NAME(B2Contact_obj::s_input,"s_input");
};

Class B2Contact_obj::__mClass;

void B2Contact_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.dynamics.contacts.B2Contact"), hx::TCanCast< B2Contact_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void B2Contact_obj::__boot()
{
	hx::Static(e_sensorFlag) = (int)1;
	hx::Static(e_continuousFlag) = (int)2;
	hx::Static(e_islandFlag) = (int)4;
	hx::Static(e_toiFlag) = (int)8;
	hx::Static(e_touchingFlag) = (int)16;
	hx::Static(e_enabledFlag) = (int)32;
	hx::Static(e_filterFlag) = (int)64;
	hx::Static(s_input) = ::box2D::collision::B2TOIInput_obj::__new();
}

} // end namespace box2D
} // end namespace dynamics
} // end namespace contacts
