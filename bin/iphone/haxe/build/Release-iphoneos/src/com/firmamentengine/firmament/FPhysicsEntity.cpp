#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_box2D_collision_shapes_B2CircleShape
#include <box2D/collision/shapes/B2CircleShape.h>
#endif
#ifndef INCLUDED_box2D_collision_shapes_B2Shape
#include <box2D/collision/shapes/B2Shape.h>
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
#ifndef INCLUDED_box2D_dynamics_B2Fixture
#include <box2D/dynamics/B2Fixture.h>
#endif
#ifndef INCLUDED_box2D_dynamics_B2FixtureDef
#include <box2D/dynamics/B2FixtureDef.h>
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
#ifndef INCLUDED_com_firmamentengine_firmament_FRenderer
#include <com/firmamentengine/firmament/FRenderer.h>
#endif
#ifndef INCLUDED_com_firmamentengine_firmament_FVector
#include <com/firmamentengine/firmament/FVector.h>
#endif
#ifndef INCLUDED_com_firmamentengine_firmament_FWireframeRenderer
#include <com/firmamentengine/firmament/FWireframeRenderer.h>
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

Void FPhysicsEntity_obj::__construct(::com::firmamentengine::firmament::FPhysicsWorld world,Dynamic config)
{
{
	HX_SOURCE_POS("/Users/jordan/source/Firmament.hx/src/com/firmamentengine/firmament/FPhysicsEntity.hx",22)
	super::__construct(world,config);
	HX_SOURCE_POS("/Users/jordan/source/Firmament.hx/src/com/firmamentengine/firmament/FPhysicsEntity.hx",23)
	this->renderer = ::com::firmamentengine::firmament::FWireframeRenderer_obj::__new();
	HX_SOURCE_POS("/Users/jordan/source/Firmament.hx/src/com/firmamentengine/firmament/FPhysicsEntity.hx",24)
	::box2D::dynamics::B2BodyDef def = ::box2D::dynamics::B2BodyDef_obj::__new();
	HX_SOURCE_POS("/Users/jordan/source/Firmament.hx/src/com/firmamentengine/firmament/FPhysicsEntity.hx",25)
	::box2D::dynamics::B2FixtureDef fixtureDef = ::box2D::dynamics::B2FixtureDef_obj::__new();
	HX_SOURCE_POS("/Users/jordan/source/Firmament.hx/src/com/firmamentengine/firmament/FPhysicsEntity.hx",27)
	if ((::Std_obj::is(config->__Field(HX_CSTRING("position")),hx::ClassOf< ::com::firmamentengine::firmament::FVector >()))){
		HX_SOURCE_POS("/Users/jordan/source/Firmament.hx/src/com/firmamentengine/firmament/FPhysicsEntity.hx",27)
		def->position = config->__Field(HX_CSTRING("position"));
	}
	else{
		HX_SOURCE_POS("/Users/jordan/source/Firmament.hx/src/com/firmamentengine/firmament/FPhysicsEntity.hx",29)
		def->position = ::com::firmamentengine::firmament::FVector_obj::__new((int)0,(int)0);
	}
	HX_SOURCE_POS("/Users/jordan/source/Firmament.hx/src/com/firmamentengine/firmament/FPhysicsEntity.hx",32)
	def->userData = hx::ObjectPtr<OBJ_>(this);
	HX_SOURCE_POS("/Users/jordan/source/Firmament.hx/src/com/firmamentengine/firmament/FPhysicsEntity.hx",33)
	def->type = ::box2D::dynamics::B2Body_obj::b2_dynamicBody;
	HX_SOURCE_POS("/Users/jordan/source/Firmament.hx/src/com/firmamentengine/firmament/FPhysicsEntity.hx",35)
	::com::firmamentengine::firmament::FPhysicsWorld physWorld = world;
	HX_SOURCE_POS("/Users/jordan/source/Firmament.hx/src/com/firmamentengine/firmament/FPhysicsEntity.hx",37)
	this->body = physWorld->getB2World()->createBody(def);
	HX_SOURCE_POS("/Users/jordan/source/Firmament.hx/src/com/firmamentengine/firmament/FPhysicsEntity.hx",38)
	this->body->createFixture2(::box2D::collision::shapes::B2CircleShape_obj::__new((int)1),null());
}
;
	return null();
}

FPhysicsEntity_obj::~FPhysicsEntity_obj() { }

Dynamic FPhysicsEntity_obj::__CreateEmpty() { return  new FPhysicsEntity_obj; }
hx::ObjectPtr< FPhysicsEntity_obj > FPhysicsEntity_obj::__new(::com::firmamentengine::firmament::FPhysicsWorld world,Dynamic config)
{  hx::ObjectPtr< FPhysicsEntity_obj > result = new FPhysicsEntity_obj();
	result->__construct(world,config);
	return result;}

Dynamic FPhysicsEntity_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FPhysicsEntity_obj > result = new FPhysicsEntity_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

::com::firmamentengine::firmament::FVector FPhysicsEntity_obj::getPosition( ){
	HX_SOURCE_PUSH("FPhysicsEntity_obj::getPosition")
	HX_SOURCE_POS("/Users/jordan/source/Firmament.hx/src/com/firmamentengine/firmament/FPhysicsEntity.hx",46)
	this->position->x = this->body->getPosition()->x;
	HX_SOURCE_POS("/Users/jordan/source/Firmament.hx/src/com/firmamentengine/firmament/FPhysicsEntity.hx",47)
	this->position->y = this->body->getPosition()->y;
	HX_SOURCE_POS("/Users/jordan/source/Firmament.hx/src/com/firmamentengine/firmament/FPhysicsEntity.hx",48)
	return this->position;
}


HX_DEFINE_DYNAMIC_FUNC0(FPhysicsEntity_obj,getPosition,return )


FPhysicsEntity_obj::FPhysicsEntity_obj()
{
}

void FPhysicsEntity_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(FPhysicsEntity);
	HX_MARK_MEMBER_NAME(body,"body");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic FPhysicsEntity_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"body") ) { return body; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"getPosition") ) { return getPosition_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic FPhysicsEntity_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"body") ) { body=inValue.Cast< ::box2D::dynamics::B2Body >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void FPhysicsEntity_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("body"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("body"),
	HX_CSTRING("getPosition"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class FPhysicsEntity_obj::__mClass;

void FPhysicsEntity_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.firmamentengine.firmament.FPhysicsEntity"), hx::TCanCast< FPhysicsEntity_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void FPhysicsEntity_obj::__boot()
{
}

} // end namespace com
} // end namespace firmamentengine
} // end namespace firmament
