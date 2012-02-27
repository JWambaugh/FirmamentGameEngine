#include <hxcpp.h>

#ifndef INCLUDED_box2D_common_math_B2Vec2
#include <box2D/common/math/B2Vec2.h>
#endif
#ifndef INCLUDED_com_firmamentengine_firmament_FVector
#include <com/firmamentengine/firmament/FVector.h>
#endif
namespace com{
namespace firmamentengine{
namespace firmament{

Void FVector_obj::__construct(double x,double y)
{
{
	HX_SOURCE_POS("/Users/jordan/source/Firmament.hx/src/com/firmamentengine/firmament/FVector.hx",14)
	super::__construct(x,y);
}
;
	return null();
}

FVector_obj::~FVector_obj() { }

Dynamic FVector_obj::__CreateEmpty() { return  new FVector_obj; }
hx::ObjectPtr< FVector_obj > FVector_obj::__new(double x,double y)
{  hx::ObjectPtr< FVector_obj > result = new FVector_obj();
	result->__construct(x,y);
	return result;}

Dynamic FVector_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FVector_obj > result = new FVector_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}


FVector_obj::FVector_obj()
{
}

void FVector_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(FVector);
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic FVector_obj::__Field(const ::String &inName)
{
	return super::__Field(inName);
}

Dynamic FVector_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	return super::__SetField(inName,inValue);
}

void FVector_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class FVector_obj::__mClass;

void FVector_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.firmamentengine.firmament.FVector"), hx::TCanCast< FVector_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void FVector_obj::__boot()
{
}

} // end namespace com
} // end namespace firmamentengine
} // end namespace firmament
