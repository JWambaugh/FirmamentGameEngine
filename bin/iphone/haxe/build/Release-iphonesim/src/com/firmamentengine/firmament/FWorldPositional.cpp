#include <hxcpp.h>

#ifndef INCLUDED_box2D_common_math_B2Vec2
#include <box2D/common/math/B2Vec2.h>
#endif
#ifndef INCLUDED_com_firmamentengine_firmament_FVector
#include <com/firmamentengine/firmament/FVector.h>
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

Void FWorldPositional_obj::__construct()
{
{
	HX_SOURCE_POS("/Users/jordan/source/Firmament.hx/src/com/firmamentengine/firmament/FWorldPositional.hx",18)
	super::__construct(null());
	HX_SOURCE_POS("/Users/jordan/source/Firmament.hx/src/com/firmamentengine/firmament/FWorldPositional.hx",19)
	this->position = ::com::firmamentengine::firmament::FVector_obj::__new((int)0,(int)0);
}
;
	return null();
}

FWorldPositional_obj::~FWorldPositional_obj() { }

Dynamic FWorldPositional_obj::__CreateEmpty() { return  new FWorldPositional_obj; }
hx::ObjectPtr< FWorldPositional_obj > FWorldPositional_obj::__new()
{  hx::ObjectPtr< FWorldPositional_obj > result = new FWorldPositional_obj();
	result->__construct();
	return result;}

Dynamic FWorldPositional_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FWorldPositional_obj > result = new FWorldPositional_obj();
	result->__construct();
	return result;}

Void FWorldPositional_obj::setPosition( ::com::firmamentengine::firmament::FVector pos){
{
		HX_SOURCE_PUSH("FWorldPositional_obj::setPosition")
		HX_SOURCE_POS("/Users/jordan/source/Firmament.hx/src/com/firmamentengine/firmament/FWorldPositional.hx",22)
		this->position = pos;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FWorldPositional_obj,setPosition,(void))

::com::firmamentengine::firmament::FVector FWorldPositional_obj::getPosition( ){
	HX_SOURCE_PUSH("FWorldPositional_obj::getPosition")
	HX_SOURCE_POS("/Users/jordan/source/Firmament.hx/src/com/firmamentengine/firmament/FWorldPositional.hx",26)
	return this->position;
}


HX_DEFINE_DYNAMIC_FUNC0(FWorldPositional_obj,getPosition,return )

double FWorldPositional_obj::getPositionX( ){
	HX_SOURCE_PUSH("FWorldPositional_obj::getPositionX")
	HX_SOURCE_POS("/Users/jordan/source/Firmament.hx/src/com/firmamentengine/firmament/FWorldPositional.hx",30)
	return this->position->x;
}


HX_DEFINE_DYNAMIC_FUNC0(FWorldPositional_obj,getPositionX,return )

double FWorldPositional_obj::getPositionY( ){
	HX_SOURCE_PUSH("FWorldPositional_obj::getPositionY")
	HX_SOURCE_POS("/Users/jordan/source/Firmament.hx/src/com/firmamentengine/firmament/FWorldPositional.hx",34)
	return this->position->y;
}


HX_DEFINE_DYNAMIC_FUNC0(FWorldPositional_obj,getPositionY,return )


FWorldPositional_obj::FWorldPositional_obj()
{
}

void FWorldPositional_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(FWorldPositional);
	HX_MARK_MEMBER_NAME(position,"position");
	HX_MARK_MEMBER_NAME(positionBase,"positionBase");
	HX_MARK_MEMBER_NAME(angle,"angle");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic FWorldPositional_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"angle") ) { return angle; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"position") ) { return position; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"setPosition") ) { return setPosition_dyn(); }
		if (HX_FIELD_EQ(inName,"getPosition") ) { return getPosition_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"positionBase") ) { return positionBase; }
		if (HX_FIELD_EQ(inName,"getPositionX") ) { return getPositionX_dyn(); }
		if (HX_FIELD_EQ(inName,"getPositionY") ) { return getPositionY_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic FWorldPositional_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"angle") ) { angle=inValue.Cast< double >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"position") ) { position=inValue.Cast< ::com::firmamentengine::firmament::FVector >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"positionBase") ) { positionBase=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void FWorldPositional_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("position"));
	outFields->push(HX_CSTRING("positionBase"));
	outFields->push(HX_CSTRING("angle"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("position"),
	HX_CSTRING("positionBase"),
	HX_CSTRING("angle"),
	HX_CSTRING("setPosition"),
	HX_CSTRING("getPosition"),
	HX_CSTRING("getPositionX"),
	HX_CSTRING("getPositionY"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class FWorldPositional_obj::__mClass;

void FWorldPositional_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.firmamentengine.firmament.FWorldPositional"), hx::TCanCast< FWorldPositional_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void FWorldPositional_obj::__boot()
{
}

} // end namespace com
} // end namespace firmamentengine
} // end namespace firmament
