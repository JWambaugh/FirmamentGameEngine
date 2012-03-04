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

Void FEntity_obj::__construct(::com::firmamentengine::firmament::FWorld world,Dynamic config)
{
{
	HX_SOURCE_POS("/Users/jordan/source/Firmament.hx/src/com/firmamentengine/firmament/FEntity.hx",13)
	super::__construct();
	HX_SOURCE_POS("/Users/jordan/source/Firmament.hx/src/com/firmamentengine/firmament/FEntity.hx",14)
	this->world = world;
}
;
	return null();
}

FEntity_obj::~FEntity_obj() { }

Dynamic FEntity_obj::__CreateEmpty() { return  new FEntity_obj; }
hx::ObjectPtr< FEntity_obj > FEntity_obj::__new(::com::firmamentengine::firmament::FWorld world,Dynamic config)
{  hx::ObjectPtr< FEntity_obj > result = new FEntity_obj();
	result->__construct(world,config);
	return result;}

Dynamic FEntity_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FEntity_obj > result = new FEntity_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}


FEntity_obj::FEntity_obj()
{
}

void FEntity_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(FEntity);
	HX_MARK_MEMBER_NAME(world,"world");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic FEntity_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"world") ) { return world; }
	}
	return super::__Field(inName);
}

Dynamic FEntity_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"world") ) { world=inValue.Cast< ::com::firmamentengine::firmament::FWorld >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void FEntity_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("world"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("world"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class FEntity_obj::__mClass;

void FEntity_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.firmamentengine.firmament.FEntity"), hx::TCanCast< FEntity_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void FEntity_obj::__boot()
{
}

} // end namespace com
} // end namespace firmamentengine
} // end namespace firmament
