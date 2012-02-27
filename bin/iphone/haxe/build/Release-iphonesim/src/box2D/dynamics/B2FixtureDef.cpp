#include <hxcpp.h>

#ifndef INCLUDED_box2D_collision_shapes_B2Shape
#include <box2D/collision/shapes/B2Shape.h>
#endif
#ifndef INCLUDED_box2D_dynamics_B2FilterData
#include <box2D/dynamics/B2FilterData.h>
#endif
#ifndef INCLUDED_box2D_dynamics_B2FixtureDef
#include <box2D/dynamics/B2FixtureDef.h>
#endif
namespace box2D{
namespace dynamics{

Void B2FixtureDef_obj::__construct()
{
{
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2FixtureDef.hx",36)
	this->filter = ::box2D::dynamics::B2FilterData_obj::__new();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2FixtureDef.hx",37)
	this->shape = null();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2FixtureDef.hx",38)
	this->userData = null();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2FixtureDef.hx",39)
	this->friction = 0.2;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2FixtureDef.hx",40)
	this->restitution = 0.0;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2FixtureDef.hx",41)
	this->density = 0.0;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2FixtureDef.hx",42)
	this->filter->categoryBits = (int)1;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2FixtureDef.hx",43)
	this->filter->maskBits = (int)65535;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2FixtureDef.hx",44)
	this->filter->groupIndex = (int)0;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2FixtureDef.hx",45)
	this->isSensor = false;
}
;
	return null();
}

B2FixtureDef_obj::~B2FixtureDef_obj() { }

Dynamic B2FixtureDef_obj::__CreateEmpty() { return  new B2FixtureDef_obj; }
hx::ObjectPtr< B2FixtureDef_obj > B2FixtureDef_obj::__new()
{  hx::ObjectPtr< B2FixtureDef_obj > result = new B2FixtureDef_obj();
	result->__construct();
	return result;}

Dynamic B2FixtureDef_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2FixtureDef_obj > result = new B2FixtureDef_obj();
	result->__construct();
	return result;}


B2FixtureDef_obj::B2FixtureDef_obj()
{
}

void B2FixtureDef_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(B2FixtureDef);
	HX_MARK_MEMBER_NAME(shape,"shape");
	HX_MARK_MEMBER_NAME(userData,"userData");
	HX_MARK_MEMBER_NAME(friction,"friction");
	HX_MARK_MEMBER_NAME(restitution,"restitution");
	HX_MARK_MEMBER_NAME(density,"density");
	HX_MARK_MEMBER_NAME(isSensor,"isSensor");
	HX_MARK_MEMBER_NAME(filter,"filter");
	HX_MARK_END_CLASS();
}

Dynamic B2FixtureDef_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"shape") ) { return shape; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"filter") ) { return filter; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"density") ) { return density; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"userData") ) { return userData; }
		if (HX_FIELD_EQ(inName,"friction") ) { return friction; }
		if (HX_FIELD_EQ(inName,"isSensor") ) { return isSensor; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"restitution") ) { return restitution; }
	}
	return super::__Field(inName);
}

Dynamic B2FixtureDef_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"shape") ) { shape=inValue.Cast< ::box2D::collision::shapes::B2Shape >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"filter") ) { filter=inValue.Cast< ::box2D::dynamics::B2FilterData >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"density") ) { density=inValue.Cast< double >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"userData") ) { userData=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"friction") ) { friction=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"isSensor") ) { isSensor=inValue.Cast< bool >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"restitution") ) { restitution=inValue.Cast< double >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void B2FixtureDef_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("shape"));
	outFields->push(HX_CSTRING("userData"));
	outFields->push(HX_CSTRING("friction"));
	outFields->push(HX_CSTRING("restitution"));
	outFields->push(HX_CSTRING("density"));
	outFields->push(HX_CSTRING("isSensor"));
	outFields->push(HX_CSTRING("filter"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("shape"),
	HX_CSTRING("userData"),
	HX_CSTRING("friction"),
	HX_CSTRING("restitution"),
	HX_CSTRING("density"),
	HX_CSTRING("isSensor"),
	HX_CSTRING("filter"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class B2FixtureDef_obj::__mClass;

void B2FixtureDef_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.dynamics.B2FixtureDef"), hx::TCanCast< B2FixtureDef_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void B2FixtureDef_obj::__boot()
{
}

} // end namespace box2D
} // end namespace dynamics
