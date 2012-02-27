#include <hxcpp.h>

#ifndef INCLUDED_com_firmamentengine_firmament_FEntity
#include <com/firmamentengine/firmament/FEntity.h>
#endif
#ifndef INCLUDED_com_firmamentengine_firmament_FRenderable
#include <com/firmamentengine/firmament/FRenderable.h>
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

Void FWorld_obj::__construct()
{
{
	HX_SOURCE_POS("/Users/jordan/source/Firmament.hx/src/com/firmamentengine/firmament/FWorld.hx",15)
	this->entities = Array_obj< ::com::firmamentengine::firmament::FEntity >::__new();
}
;
	return null();
}

FWorld_obj::~FWorld_obj() { }

Dynamic FWorld_obj::__CreateEmpty() { return  new FWorld_obj; }
hx::ObjectPtr< FWorld_obj > FWorld_obj::__new()
{  hx::ObjectPtr< FWorld_obj > result = new FWorld_obj();
	result->__construct();
	return result;}

Dynamic FWorld_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FWorld_obj > result = new FWorld_obj();
	result->__construct();
	return result;}

Void FWorld_obj::addEntity( ::com::firmamentengine::firmament::FEntity ent){
{
		HX_SOURCE_PUSH("FWorld_obj::addEntity")
		HX_SOURCE_POS("/Users/jordan/source/Firmament.hx/src/com/firmamentengine/firmament/FWorld.hx",18)
		this->entities->push(ent);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FWorld_obj,addEntity,(void))

Array< ::com::firmamentengine::firmament::FEntity > FWorld_obj::getAllEntities( ){
	HX_SOURCE_PUSH("FWorld_obj::getAllEntities")
	HX_SOURCE_POS("/Users/jordan/source/Firmament.hx/src/com/firmamentengine/firmament/FWorld.hx",24)
	return this->entities;
}


HX_DEFINE_DYNAMIC_FUNC0(FWorld_obj,getAllEntities,return )

Void FWorld_obj::step( ){
{
		HX_SOURCE_PUSH("FWorld_obj::step")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FWorld_obj,step,(void))


FWorld_obj::FWorld_obj()
{
}

void FWorld_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(FWorld);
	HX_MARK_MEMBER_NAME(entities,"entities");
	HX_MARK_END_CLASS();
}

Dynamic FWorld_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"step") ) { return step_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"entities") ) { return entities; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"addEntity") ) { return addEntity_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"getAllEntities") ) { return getAllEntities_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic FWorld_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"entities") ) { entities=inValue.Cast< Array< ::com::firmamentengine::firmament::FEntity > >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void FWorld_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("entities"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("entities"),
	HX_CSTRING("addEntity"),
	HX_CSTRING("getAllEntities"),
	HX_CSTRING("step"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class FWorld_obj::__mClass;

void FWorld_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.firmamentengine.firmament.FWorld"), hx::TCanCast< FWorld_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void FWorld_obj::__boot()
{
}

} // end namespace com
} // end namespace firmamentengine
} // end namespace firmament
