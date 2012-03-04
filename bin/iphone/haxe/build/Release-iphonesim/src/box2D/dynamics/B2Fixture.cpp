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
#ifndef INCLUDED_box2D_collision_shapes_B2MassData
#include <box2D/collision/shapes/B2MassData.h>
#endif
#ifndef INCLUDED_box2D_collision_shapes_B2Shape
#include <box2D/collision/shapes/B2Shape.h>
#endif
#ifndef INCLUDED_box2D_common_math_B2Math
#include <box2D/common/math/B2Math.h>
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
#ifndef INCLUDED_box2D_dynamics_B2FilterData
#include <box2D/dynamics/B2FilterData.h>
#endif
#ifndef INCLUDED_box2D_dynamics_B2Fixture
#include <box2D/dynamics/B2Fixture.h>
#endif
#ifndef INCLUDED_box2D_dynamics_B2FixtureDef
#include <box2D/dynamics/B2FixtureDef.h>
#endif
#ifndef INCLUDED_box2D_dynamics_contacts_B2Contact
#include <box2D/dynamics/contacts/B2Contact.h>
#endif
#ifndef INCLUDED_box2D_dynamics_contacts_B2ContactEdge
#include <box2D/dynamics/contacts/B2ContactEdge.h>
#endif
namespace box2D{
namespace dynamics{

Void B2Fixture_obj::__construct()
{
{
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Fixture.hx",264)
	this->m_filter = ::box2D::dynamics::B2FilterData_obj::__new();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Fixture.hx",265)
	this->m_aabb = ::box2D::collision::B2AABB_obj::__new();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Fixture.hx",266)
	this->m_userData = null();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Fixture.hx",267)
	this->m_body = null();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Fixture.hx",268)
	this->m_next = null();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Fixture.hx",270)
	this->m_shape = null();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Fixture.hx",271)
	this->m_density = 0.0;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Fixture.hx",273)
	this->m_friction = 0.0;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Fixture.hx",274)
	this->m_restitution = 0.0;
}
;
	return null();
}

B2Fixture_obj::~B2Fixture_obj() { }

Dynamic B2Fixture_obj::__CreateEmpty() { return  new B2Fixture_obj; }
hx::ObjectPtr< B2Fixture_obj > B2Fixture_obj::__new()
{  hx::ObjectPtr< B2Fixture_obj > result = new B2Fixture_obj();
	result->__construct();
	return result;}

Dynamic B2Fixture_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2Fixture_obj > result = new B2Fixture_obj();
	result->__construct();
	return result;}

int B2Fixture_obj::getType( ){
	HX_SOURCE_PUSH("B2Fixture_obj::getType")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Fixture.hx",49)
	return this->m_shape->getType();
}


HX_DEFINE_DYNAMIC_FUNC0(B2Fixture_obj,getType,return )

::box2D::collision::shapes::B2Shape B2Fixture_obj::getShape( ){
	HX_SOURCE_PUSH("B2Fixture_obj::getShape")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Fixture.hx",58)
	return this->m_shape;
}


HX_DEFINE_DYNAMIC_FUNC0(B2Fixture_obj,getShape,return )

Void B2Fixture_obj::setSensor( bool sensor){
{
		HX_SOURCE_PUSH("B2Fixture_obj::setSensor")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Fixture.hx",67)
		if (((this->m_isSensor == sensor))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Fixture.hx",68)
			return null();
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Fixture.hx",70)
		this->m_isSensor = sensor;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Fixture.hx",72)
		if (((this->m_body == null()))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Fixture.hx",73)
			return null();
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Fixture.hx",75)
		::box2D::dynamics::contacts::B2ContactEdge edge = this->m_body->getContactList();
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Fixture.hx",76)
		while(((edge != null()))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Fixture.hx",78)
			::box2D::dynamics::contacts::B2Contact contact = edge->contact;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Fixture.hx",79)
			::box2D::dynamics::B2Fixture fixtureA = contact->getFixtureA();
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Fixture.hx",80)
			::box2D::dynamics::B2Fixture fixtureB = contact->getFixtureB();
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Fixture.hx",81)
			if (((bool((fixtureA == hx::ObjectPtr<OBJ_>(this))) || bool((fixtureB == hx::ObjectPtr<OBJ_>(this)))))){
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Fixture.hx",82)
				contact->setSensor((bool(fixtureA->isSensor()) || bool(fixtureB->isSensor())));
			}
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Fixture.hx",83)
			edge = edge->next;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2Fixture_obj,setSensor,(void))

bool B2Fixture_obj::isSensor( ){
	HX_SOURCE_PUSH("B2Fixture_obj::isSensor")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Fixture.hx",93)
	return this->m_isSensor;
}


HX_DEFINE_DYNAMIC_FUNC0(B2Fixture_obj,isSensor,return )

Void B2Fixture_obj::setFilterData( ::box2D::dynamics::B2FilterData filter){
{
		HX_SOURCE_PUSH("B2Fixture_obj::setFilterData")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Fixture.hx",103)
		this->m_filter = filter->copy();
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Fixture.hx",105)
		if (((this->m_body != null()))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Fixture.hx",106)
			return null();
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Fixture.hx",108)
		::box2D::dynamics::contacts::B2ContactEdge edge = this->m_body->getContactList();
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Fixture.hx",109)
		while(((edge != null()))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Fixture.hx",111)
			::box2D::dynamics::contacts::B2Contact contact = edge->contact;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Fixture.hx",112)
			::box2D::dynamics::B2Fixture fixtureA = contact->getFixtureA();
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Fixture.hx",113)
			::box2D::dynamics::B2Fixture fixtureB = contact->getFixtureB();
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Fixture.hx",114)
			if (((bool((fixtureA == hx::ObjectPtr<OBJ_>(this))) || bool((fixtureB == hx::ObjectPtr<OBJ_>(this)))))){
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Fixture.hx",115)
				contact->flagForFiltering();
			}
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Fixture.hx",116)
			edge = edge->next;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2Fixture_obj,setFilterData,(void))

::box2D::dynamics::B2FilterData B2Fixture_obj::getFilterData( ){
	HX_SOURCE_PUSH("B2Fixture_obj::getFilterData")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Fixture.hx",124)
	return this->m_filter->copy();
}


HX_DEFINE_DYNAMIC_FUNC0(B2Fixture_obj,getFilterData,return )

::box2D::dynamics::B2Body B2Fixture_obj::getBody( ){
	HX_SOURCE_PUSH("B2Fixture_obj::getBody")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Fixture.hx",133)
	return this->m_body;
}


HX_DEFINE_DYNAMIC_FUNC0(B2Fixture_obj,getBody,return )

::box2D::dynamics::B2Fixture B2Fixture_obj::getNext( ){
	HX_SOURCE_PUSH("B2Fixture_obj::getNext")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Fixture.hx",142)
	return this->m_next;
}


HX_DEFINE_DYNAMIC_FUNC0(B2Fixture_obj,getNext,return )

Dynamic B2Fixture_obj::getUserData( ){
	HX_SOURCE_PUSH("B2Fixture_obj::getUserData")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Fixture.hx",151)
	return this->m_userData;
}


HX_DEFINE_DYNAMIC_FUNC0(B2Fixture_obj,getUserData,return )

Void B2Fixture_obj::SetUserData( Dynamic data){
{
		HX_SOURCE_PUSH("B2Fixture_obj::SetUserData")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Fixture.hx",159)
		this->m_userData = data;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2Fixture_obj,SetUserData,(void))

bool B2Fixture_obj::testPoint( ::box2D::common::math::B2Vec2 p){
	HX_SOURCE_PUSH("B2Fixture_obj::testPoint")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Fixture.hx",169)
	return this->m_shape->testPoint(this->m_body->getTransform(),p);
}


HX_DEFINE_DYNAMIC_FUNC1(B2Fixture_obj,testPoint,return )

bool B2Fixture_obj::rayCast( ::box2D::collision::B2RayCastOutput output,::box2D::collision::B2RayCastInput input){
	HX_SOURCE_PUSH("B2Fixture_obj::rayCast")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Fixture.hx",179)
	return this->m_shape->rayCast(output,input,this->m_body->getTransform());
}


HX_DEFINE_DYNAMIC_FUNC2(B2Fixture_obj,rayCast,return )

::box2D::collision::shapes::B2MassData B2Fixture_obj::getMassData( ::box2D::collision::shapes::B2MassData massData){
	HX_SOURCE_PUSH("B2Fixture_obj::getMassData")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Fixture.hx",191)
	if (((massData == null()))){
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Fixture.hx",192)
		massData = ::box2D::collision::shapes::B2MassData_obj::__new();
	}
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Fixture.hx",195)
	this->m_shape->computeMass(massData,this->m_density);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Fixture.hx",196)
	return massData;
}


HX_DEFINE_DYNAMIC_FUNC1(B2Fixture_obj,getMassData,return )

Void B2Fixture_obj::setDensity( double density){
{
		HX_SOURCE_PUSH("B2Fixture_obj::setDensity")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Fixture.hx",204)
		this->m_density = density;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2Fixture_obj,setDensity,(void))

double B2Fixture_obj::getDensity( ){
	HX_SOURCE_PUSH("B2Fixture_obj::getDensity")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Fixture.hx",213)
	return this->m_density;
}


HX_DEFINE_DYNAMIC_FUNC0(B2Fixture_obj,getDensity,return )

double B2Fixture_obj::getFriction( ){
	HX_SOURCE_PUSH("B2Fixture_obj::getFriction")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Fixture.hx",221)
	return this->m_friction;
}


HX_DEFINE_DYNAMIC_FUNC0(B2Fixture_obj,getFriction,return )

Void B2Fixture_obj::setFriction( double friction){
{
		HX_SOURCE_PUSH("B2Fixture_obj::setFriction")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Fixture.hx",229)
		this->m_friction = friction;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2Fixture_obj,setFriction,(void))

double B2Fixture_obj::getRestitution( ){
	HX_SOURCE_PUSH("B2Fixture_obj::getRestitution")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Fixture.hx",237)
	return this->m_restitution;
}


HX_DEFINE_DYNAMIC_FUNC0(B2Fixture_obj,getRestitution,return )

Void B2Fixture_obj::setRestitution( double restitution){
{
		HX_SOURCE_PUSH("B2Fixture_obj::setRestitution")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Fixture.hx",245)
		this->m_restitution = restitution;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2Fixture_obj,setRestitution,(void))

::box2D::collision::B2AABB B2Fixture_obj::getAABB( ){
	HX_SOURCE_PUSH("B2Fixture_obj::getAABB")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Fixture.hx",255)
	return this->m_aabb;
}


HX_DEFINE_DYNAMIC_FUNC0(B2Fixture_obj,getAABB,return )

Void B2Fixture_obj::create( ::box2D::dynamics::B2Body body,::box2D::common::math::B2Transform xf,::box2D::dynamics::B2FixtureDef def){
{
		HX_SOURCE_PUSH("B2Fixture_obj::create")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Fixture.hx",283)
		this->m_userData = def->userData;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Fixture.hx",284)
		this->m_friction = def->friction;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Fixture.hx",285)
		this->m_restitution = def->restitution;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Fixture.hx",287)
		this->m_body = body;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Fixture.hx",288)
		this->m_next = null();
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Fixture.hx",290)
		this->m_filter = def->filter->copy();
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Fixture.hx",292)
		this->m_isSensor = def->isSensor;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Fixture.hx",294)
		this->m_shape = def->shape->copy();
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Fixture.hx",296)
		this->m_density = def->density;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(B2Fixture_obj,create,(void))

Void B2Fixture_obj::destroy( ){
{
		HX_SOURCE_PUSH("B2Fixture_obj::destroy")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Fixture.hx",304)
		this->m_shape = null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(B2Fixture_obj,destroy,(void))

Void B2Fixture_obj::createProxy( ::box2D::collision::IBroadPhase broadPhase,::box2D::common::math::B2Transform xf){
{
		HX_SOURCE_PUSH("B2Fixture_obj::createProxy")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Fixture.hx",319)
		this->m_shape->computeAABB(this->m_aabb,xf);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Fixture.hx",320)
		this->m_proxy = broadPhase->createProxy(this->m_aabb,hx::ObjectPtr<OBJ_>(this));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(B2Fixture_obj,createProxy,(void))

Void B2Fixture_obj::destroyProxy( ::box2D::collision::IBroadPhase broadPhase){
{
		HX_SOURCE_PUSH("B2Fixture_obj::destroyProxy")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Fixture.hx",327)
		if (((this->m_proxy == null()))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Fixture.hx",328)
			return null();
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Fixture.hx",333)
		broadPhase->destroyProxy(this->m_proxy);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Fixture.hx",334)
		this->m_proxy = null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2Fixture_obj,destroyProxy,(void))

Void B2Fixture_obj::synchronize( ::box2D::collision::IBroadPhase broadPhase,::box2D::common::math::B2Transform transform1,::box2D::common::math::B2Transform transform2){
{
		HX_SOURCE_PUSH("B2Fixture_obj::synchronize")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Fixture.hx",339)
		if (((this->m_proxy == null()))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Fixture.hx",340)
			return null();
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Fixture.hx",343)
		::box2D::collision::B2AABB aabb1 = ::box2D::collision::B2AABB_obj::__new();
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Fixture.hx",344)
		::box2D::collision::B2AABB aabb2 = ::box2D::collision::B2AABB_obj::__new();
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Fixture.hx",345)
		this->m_shape->computeAABB(aabb1,transform1);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Fixture.hx",346)
		this->m_shape->computeAABB(aabb2,transform2);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Fixture.hx",348)
		this->m_aabb->combine(aabb1,aabb2);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Fixture.hx",349)
		::box2D::common::math::B2Vec2 displacement = ::box2D::common::math::B2Math_obj::subtractVV(transform2->position,transform1->position);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Fixture.hx",350)
		broadPhase->moveProxy(this->m_proxy,this->m_aabb,displacement);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(B2Fixture_obj,synchronize,(void))


B2Fixture_obj::B2Fixture_obj()
{
}

void B2Fixture_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(B2Fixture);
	HX_MARK_MEMBER_NAME(m_massData,"m_massData");
	HX_MARK_MEMBER_NAME(m_aabb,"m_aabb");
	HX_MARK_MEMBER_NAME(m_density,"m_density");
	HX_MARK_MEMBER_NAME(m_next,"m_next");
	HX_MARK_MEMBER_NAME(m_body,"m_body");
	HX_MARK_MEMBER_NAME(m_shape,"m_shape");
	HX_MARK_MEMBER_NAME(m_friction,"m_friction");
	HX_MARK_MEMBER_NAME(m_restitution,"m_restitution");
	HX_MARK_MEMBER_NAME(m_proxy,"m_proxy");
	HX_MARK_MEMBER_NAME(m_filter,"m_filter");
	HX_MARK_MEMBER_NAME(m_isSensor,"m_isSensor");
	HX_MARK_MEMBER_NAME(m_userData,"m_userData");
	HX_MARK_END_CLASS();
}

Dynamic B2Fixture_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"create") ) { return create_dyn(); }
		if (HX_FIELD_EQ(inName,"m_aabb") ) { return m_aabb; }
		if (HX_FIELD_EQ(inName,"m_next") ) { return m_next; }
		if (HX_FIELD_EQ(inName,"m_body") ) { return m_body; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"getType") ) { return getType_dyn(); }
		if (HX_FIELD_EQ(inName,"getBody") ) { return getBody_dyn(); }
		if (HX_FIELD_EQ(inName,"getNext") ) { return getNext_dyn(); }
		if (HX_FIELD_EQ(inName,"rayCast") ) { return rayCast_dyn(); }
		if (HX_FIELD_EQ(inName,"getAABB") ) { return getAABB_dyn(); }
		if (HX_FIELD_EQ(inName,"destroy") ) { return destroy_dyn(); }
		if (HX_FIELD_EQ(inName,"m_shape") ) { return m_shape; }
		if (HX_FIELD_EQ(inName,"m_proxy") ) { return m_proxy; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"getShape") ) { return getShape_dyn(); }
		if (HX_FIELD_EQ(inName,"isSensor") ) { return isSensor_dyn(); }
		if (HX_FIELD_EQ(inName,"m_filter") ) { return m_filter; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"setSensor") ) { return setSensor_dyn(); }
		if (HX_FIELD_EQ(inName,"testPoint") ) { return testPoint_dyn(); }
		if (HX_FIELD_EQ(inName,"m_density") ) { return m_density; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"setDensity") ) { return setDensity_dyn(); }
		if (HX_FIELD_EQ(inName,"getDensity") ) { return getDensity_dyn(); }
		if (HX_FIELD_EQ(inName,"m_massData") ) { return m_massData; }
		if (HX_FIELD_EQ(inName,"m_friction") ) { return m_friction; }
		if (HX_FIELD_EQ(inName,"m_isSensor") ) { return m_isSensor; }
		if (HX_FIELD_EQ(inName,"m_userData") ) { return m_userData; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"getUserData") ) { return getUserData_dyn(); }
		if (HX_FIELD_EQ(inName,"SetUserData") ) { return SetUserData_dyn(); }
		if (HX_FIELD_EQ(inName,"getMassData") ) { return getMassData_dyn(); }
		if (HX_FIELD_EQ(inName,"getFriction") ) { return getFriction_dyn(); }
		if (HX_FIELD_EQ(inName,"setFriction") ) { return setFriction_dyn(); }
		if (HX_FIELD_EQ(inName,"createProxy") ) { return createProxy_dyn(); }
		if (HX_FIELD_EQ(inName,"synchronize") ) { return synchronize_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"destroyProxy") ) { return destroyProxy_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"setFilterData") ) { return setFilterData_dyn(); }
		if (HX_FIELD_EQ(inName,"getFilterData") ) { return getFilterData_dyn(); }
		if (HX_FIELD_EQ(inName,"m_restitution") ) { return m_restitution; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"getRestitution") ) { return getRestitution_dyn(); }
		if (HX_FIELD_EQ(inName,"setRestitution") ) { return setRestitution_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic B2Fixture_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"m_aabb") ) { m_aabb=inValue.Cast< ::box2D::collision::B2AABB >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_next") ) { m_next=inValue.Cast< ::box2D::dynamics::B2Fixture >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_body") ) { m_body=inValue.Cast< ::box2D::dynamics::B2Body >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"m_shape") ) { m_shape=inValue.Cast< ::box2D::collision::shapes::B2Shape >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_proxy") ) { m_proxy=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"m_filter") ) { m_filter=inValue.Cast< ::box2D::dynamics::B2FilterData >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"m_density") ) { m_density=inValue.Cast< double >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"m_massData") ) { m_massData=inValue.Cast< ::box2D::collision::shapes::B2MassData >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_friction") ) { m_friction=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_isSensor") ) { m_isSensor=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_userData") ) { m_userData=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"m_restitution") ) { m_restitution=inValue.Cast< double >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void B2Fixture_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("m_massData"));
	outFields->push(HX_CSTRING("m_aabb"));
	outFields->push(HX_CSTRING("m_density"));
	outFields->push(HX_CSTRING("m_next"));
	outFields->push(HX_CSTRING("m_body"));
	outFields->push(HX_CSTRING("m_shape"));
	outFields->push(HX_CSTRING("m_friction"));
	outFields->push(HX_CSTRING("m_restitution"));
	outFields->push(HX_CSTRING("m_proxy"));
	outFields->push(HX_CSTRING("m_filter"));
	outFields->push(HX_CSTRING("m_isSensor"));
	outFields->push(HX_CSTRING("m_userData"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("getType"),
	HX_CSTRING("getShape"),
	HX_CSTRING("setSensor"),
	HX_CSTRING("isSensor"),
	HX_CSTRING("setFilterData"),
	HX_CSTRING("getFilterData"),
	HX_CSTRING("getBody"),
	HX_CSTRING("getNext"),
	HX_CSTRING("getUserData"),
	HX_CSTRING("SetUserData"),
	HX_CSTRING("testPoint"),
	HX_CSTRING("rayCast"),
	HX_CSTRING("getMassData"),
	HX_CSTRING("setDensity"),
	HX_CSTRING("getDensity"),
	HX_CSTRING("getFriction"),
	HX_CSTRING("setFriction"),
	HX_CSTRING("getRestitution"),
	HX_CSTRING("setRestitution"),
	HX_CSTRING("getAABB"),
	HX_CSTRING("create"),
	HX_CSTRING("destroy"),
	HX_CSTRING("createProxy"),
	HX_CSTRING("destroyProxy"),
	HX_CSTRING("synchronize"),
	HX_CSTRING("m_massData"),
	HX_CSTRING("m_aabb"),
	HX_CSTRING("m_density"),
	HX_CSTRING("m_next"),
	HX_CSTRING("m_body"),
	HX_CSTRING("m_shape"),
	HX_CSTRING("m_friction"),
	HX_CSTRING("m_restitution"),
	HX_CSTRING("m_proxy"),
	HX_CSTRING("m_filter"),
	HX_CSTRING("m_isSensor"),
	HX_CSTRING("m_userData"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class B2Fixture_obj::__mClass;

void B2Fixture_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.dynamics.B2Fixture"), hx::TCanCast< B2Fixture_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void B2Fixture_obj::__boot()
{
}

} // end namespace box2D
} // end namespace dynamics
