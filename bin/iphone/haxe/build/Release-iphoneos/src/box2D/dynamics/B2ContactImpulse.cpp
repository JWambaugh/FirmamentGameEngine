#include <hxcpp.h>

#ifndef INCLUDED_box2D_dynamics_B2ContactImpulse
#include <box2D/dynamics/B2ContactImpulse.h>
#endif
namespace box2D{
namespace dynamics{

Void B2ContactImpulse_obj::__construct()
{
{
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2ContactImpulse.hx",33)
	this->normalImpulses = Array_obj< double >::__new();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2ContactImpulse.hx",34)
	this->tangentImpulses = Array_obj< double >::__new();
}
;
	return null();
}

B2ContactImpulse_obj::~B2ContactImpulse_obj() { }

Dynamic B2ContactImpulse_obj::__CreateEmpty() { return  new B2ContactImpulse_obj; }
hx::ObjectPtr< B2ContactImpulse_obj > B2ContactImpulse_obj::__new()
{  hx::ObjectPtr< B2ContactImpulse_obj > result = new B2ContactImpulse_obj();
	result->__construct();
	return result;}

Dynamic B2ContactImpulse_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2ContactImpulse_obj > result = new B2ContactImpulse_obj();
	result->__construct();
	return result;}


B2ContactImpulse_obj::B2ContactImpulse_obj()
{
}

void B2ContactImpulse_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(B2ContactImpulse);
	HX_MARK_MEMBER_NAME(normalImpulses,"normalImpulses");
	HX_MARK_MEMBER_NAME(tangentImpulses,"tangentImpulses");
	HX_MARK_END_CLASS();
}

Dynamic B2ContactImpulse_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 14:
		if (HX_FIELD_EQ(inName,"normalImpulses") ) { return normalImpulses; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"tangentImpulses") ) { return tangentImpulses; }
	}
	return super::__Field(inName);
}

Dynamic B2ContactImpulse_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 14:
		if (HX_FIELD_EQ(inName,"normalImpulses") ) { normalImpulses=inValue.Cast< Array< double > >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"tangentImpulses") ) { tangentImpulses=inValue.Cast< Array< double > >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void B2ContactImpulse_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("normalImpulses"));
	outFields->push(HX_CSTRING("tangentImpulses"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("normalImpulses"),
	HX_CSTRING("tangentImpulses"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class B2ContactImpulse_obj::__mClass;

void B2ContactImpulse_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.dynamics.B2ContactImpulse"), hx::TCanCast< B2ContactImpulse_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void B2ContactImpulse_obj::__boot()
{
}

} // end namespace box2D
} // end namespace dynamics
