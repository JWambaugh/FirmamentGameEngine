#include <hxcpp.h>

#ifndef INCLUDED_box2D_collision_B2AABB
#include <box2D/collision/B2AABB.h>
#endif
#ifndef INCLUDED_box2D_common_math_B2Vec2
#include <box2D/common/math/B2Vec2.h>
#endif
#ifndef INCLUDED_box2D_dynamics_B2Body
#include <box2D/dynamics/B2Body.h>
#endif
#ifndef INCLUDED_box2D_dynamics_B2Fixture
#include <box2D/dynamics/B2Fixture.h>
#endif
#ifndef INCLUDED_box2D_dynamics_B2World
#include <box2D/dynamics/B2World.h>
#endif
#ifndef INCLUDED_com_firmamentengine_firmament_FEntity
#include <com/firmamentengine/firmament/FEntity.h>
#endif
#ifndef INCLUDED_com_firmamentengine_firmament_FPhysicsEntity
#include <com/firmamentengine/firmament/FPhysicsEntity.h>
#endif
#ifndef INCLUDED_com_firmamentengine_firmament_FPhysicsWorld
#include <com/firmamentengine/firmament/FPhysicsWorld.h>
#endif
#ifndef INCLUDED_com_firmamentengine_firmament_FRenderable
#include <com/firmamentengine/firmament/FRenderable.h>
#endif
#ifndef INCLUDED_com_firmamentengine_firmament_FVector
#include <com/firmamentengine/firmament/FVector.h>
#endif
#ifndef INCLUDED_com_firmamentengine_firmament_FWorld
#include <com/firmamentengine/firmament/FWorld.h>
#endif
#ifndef INCLUDED_com_firmamentengine_firmament_FWorldPositional
#include <com/firmamentengine/firmament/FWorldPositional.h>
#endif
#ifndef INCLUDED_nme_events_EventDispatcher
#include <nme/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_nme_events_IEventDispatcher
#include <nme/events/IEventDispatcher.h>
#endif
namespace com{
namespace firmamentengine{
namespace firmament{

Void FPhysicsWorld_obj::__construct(::com::firmamentengine::firmament::FVector gravity)
{
{
	HX_SOURCE_POS("/Users/jordan/source/Firmament.hx/src/com/firmamentengine/firmament/FPhysicsWorld.hx",19)
	super::__construct();
	HX_SOURCE_POS("/Users/jordan/source/Firmament.hx/src/com/firmamentengine/firmament/FPhysicsWorld.hx",20)
	this->b2world = ::box2D::dynamics::B2World_obj::__new(gravity,true);
}
;
	return null();
}

FPhysicsWorld_obj::~FPhysicsWorld_obj() { }

Dynamic FPhysicsWorld_obj::__CreateEmpty() { return  new FPhysicsWorld_obj; }
hx::ObjectPtr< FPhysicsWorld_obj > FPhysicsWorld_obj::__new(::com::firmamentengine::firmament::FVector gravity)
{  hx::ObjectPtr< FPhysicsWorld_obj > result = new FPhysicsWorld_obj();
	result->__construct(gravity);
	return result;}

Dynamic FPhysicsWorld_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FPhysicsWorld_obj > result = new FPhysicsWorld_obj();
	result->__construct(inArgs[0]);
	return result;}

Array< ::com::firmamentengine::firmament::FEntity > FPhysicsWorld_obj::getEntitiesInBox( int topLeftX,int topLeftY,int bottomRightX,int bottomRightY){
	HX_SOURCE_PUSH("FPhysicsWorld_obj::getEntitiesInBox")
	HX_SOURCE_POS("/Users/jordan/source/Firmament.hx/src/com/firmamentengine/firmament/FPhysicsWorld.hx",23)
	Array< Array< ::com::firmamentengine::firmament::FEntity > > selectEntities = Array_obj< Array< ::com::firmamentengine::firmament::FEntity > >::__new().Add(Array_obj< ::com::firmamentengine::firmament::FEntity >::__new());
	HX_SOURCE_POS("/Users/jordan/source/Firmament.hx/src/com/firmamentengine/firmament/FPhysicsWorld.hx",24)
	::box2D::collision::B2AABB query = ::box2D::collision::B2AABB_obj::__new();
	HX_SOURCE_POS("/Users/jordan/source/Firmament.hx/src/com/firmamentengine/firmament/FPhysicsWorld.hx",26)
	query->upperBound->set(bottomRightX,bottomRightY);
	HX_SOURCE_POS("/Users/jordan/source/Firmament.hx/src/com/firmamentengine/firmament/FPhysicsWorld.hx",27)
	query->lowerBound->set(topLeftX,topLeftY);

	HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_1_1,Array< Array< ::com::firmamentengine::firmament::FEntity > >,selectEntities)
	bool run(::box2D::dynamics::B2Fixture fixture){
{
			HX_SOURCE_POS("/Users/jordan/source/Firmament.hx/src/com/firmamentengine/firmament/FPhysicsWorld.hx",32)
			selectEntities->__get((int)0)->push(fixture->getBody()->getUserData());
			HX_SOURCE_POS("/Users/jordan/source/Firmament.hx/src/com/firmamentengine/firmament/FPhysicsWorld.hx",33)
			return true;
		}
		return null();
	}
	HX_END_LOCAL_FUNC1(return)

	HX_SOURCE_POS("/Users/jordan/source/Firmament.hx/src/com/firmamentengine/firmament/FPhysicsWorld.hx",30)
	this->b2world->queryAABB( Dynamic(new _Function_1_1(selectEntities)),query);
	HX_SOURCE_POS("/Users/jordan/source/Firmament.hx/src/com/firmamentengine/firmament/FPhysicsWorld.hx",36)
	return selectEntities->__get((int)0);
}


HX_DEFINE_DYNAMIC_FUNC4(FPhysicsWorld_obj,getEntitiesInBox,return )

::box2D::dynamics::B2World FPhysicsWorld_obj::getB2World( ){
	HX_SOURCE_PUSH("FPhysicsWorld_obj::getB2World")
	HX_SOURCE_POS("/Users/jordan/source/Firmament.hx/src/com/firmamentengine/firmament/FPhysicsWorld.hx",39)
	return this->b2world;
}


HX_DEFINE_DYNAMIC_FUNC0(FPhysicsWorld_obj,getB2World,return )

::com::firmamentengine::firmament::FPhysicsEntity FPhysicsWorld_obj::createEntity( Dynamic config){
	HX_SOURCE_PUSH("FPhysicsWorld_obj::createEntity")
	HX_SOURCE_POS("/Users/jordan/source/Firmament.hx/src/com/firmamentengine/firmament/FPhysicsWorld.hx",44)
	::com::firmamentengine::firmament::FPhysicsEntity ent = ::com::firmamentengine::firmament::FPhysicsEntity_obj::__new(hx::ObjectPtr<OBJ_>(this),config);
	HX_SOURCE_POS("/Users/jordan/source/Firmament.hx/src/com/firmamentengine/firmament/FPhysicsWorld.hx",45)
	this->addEntity(ent);
	HX_SOURCE_POS("/Users/jordan/source/Firmament.hx/src/com/firmamentengine/firmament/FPhysicsWorld.hx",46)
	return ent;
}


HX_DEFINE_DYNAMIC_FUNC1(FPhysicsWorld_obj,createEntity,return )

Void FPhysicsWorld_obj::step( ){
{
		HX_SOURCE_PUSH("FPhysicsWorld_obj::step")
		HX_SOURCE_POS("/Users/jordan/source/Firmament.hx/src/com/firmamentengine/firmament/FPhysicsWorld.hx",50)
		this->b2world->step((double((int)1) / double((int)30)),(int)10,(int)10);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FPhysicsWorld_obj,step,(void))


FPhysicsWorld_obj::FPhysicsWorld_obj()
{
}

void FPhysicsWorld_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(FPhysicsWorld);
	HX_MARK_MEMBER_NAME(b2world,"b2world");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic FPhysicsWorld_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"step") ) { return step_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"b2world") ) { return b2world; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"getB2World") ) { return getB2World_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"createEntity") ) { return createEntity_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"getEntitiesInBox") ) { return getEntitiesInBox_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic FPhysicsWorld_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"b2world") ) { b2world=inValue.Cast< ::box2D::dynamics::B2World >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void FPhysicsWorld_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("b2world"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("b2world"),
	HX_CSTRING("getEntitiesInBox"),
	HX_CSTRING("getB2World"),
	HX_CSTRING("createEntity"),
	HX_CSTRING("step"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class FPhysicsWorld_obj::__mClass;

void FPhysicsWorld_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.firmamentengine.firmament.FPhysicsWorld"), hx::TCanCast< FPhysicsWorld_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void FPhysicsWorld_obj::__boot()
{
}

} // end namespace com
} // end namespace firmamentengine
} // end namespace firmament
