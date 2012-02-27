#include <hxcpp.h>

#ifndef INCLUDED_box2D_collision_B2DistanceOutput
#include <box2D/collision/B2DistanceOutput.h>
#endif
#ifndef INCLUDED_box2D_common_math_B2Vec2
#include <box2D/common/math/B2Vec2.h>
#endif
namespace box2D{
namespace collision{

Void B2DistanceOutput_obj::__construct()
{
{
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DistanceOutput.hx",30)
	this->pointA = ::box2D::common::math::B2Vec2_obj::__new(null(),null());
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DistanceOutput.hx",31)
	this->pointB = ::box2D::common::math::B2Vec2_obj::__new(null(),null());
}
;
	return null();
}

B2DistanceOutput_obj::~B2DistanceOutput_obj() { }

Dynamic B2DistanceOutput_obj::__CreateEmpty() { return  new B2DistanceOutput_obj; }
hx::ObjectPtr< B2DistanceOutput_obj > B2DistanceOutput_obj::__new()
{  hx::ObjectPtr< B2DistanceOutput_obj > result = new B2DistanceOutput_obj();
	result->__construct();
	return result;}

Dynamic B2DistanceOutput_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2DistanceOutput_obj > result = new B2DistanceOutput_obj();
	result->__construct();
	return result;}


B2DistanceOutput_obj::B2DistanceOutput_obj()
{
}

void B2DistanceOutput_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(B2DistanceOutput);
	HX_MARK_MEMBER_NAME(pointA,"pointA");
	HX_MARK_MEMBER_NAME(pointB,"pointB");
	HX_MARK_MEMBER_NAME(distance,"distance");
	HX_MARK_MEMBER_NAME(iterations,"iterations");
	HX_MARK_END_CLASS();
}

Dynamic B2DistanceOutput_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"pointA") ) { return pointA; }
		if (HX_FIELD_EQ(inName,"pointB") ) { return pointB; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"distance") ) { return distance; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"iterations") ) { return iterations; }
	}
	return super::__Field(inName);
}

Dynamic B2DistanceOutput_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"pointA") ) { pointA=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"pointB") ) { pointB=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"distance") ) { distance=inValue.Cast< double >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"iterations") ) { iterations=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void B2DistanceOutput_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("pointA"));
	outFields->push(HX_CSTRING("pointB"));
	outFields->push(HX_CSTRING("distance"));
	outFields->push(HX_CSTRING("iterations"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("pointA"),
	HX_CSTRING("pointB"),
	HX_CSTRING("distance"),
	HX_CSTRING("iterations"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class B2DistanceOutput_obj::__mClass;

void B2DistanceOutput_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.collision.B2DistanceOutput"), hx::TCanCast< B2DistanceOutput_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void B2DistanceOutput_obj::__boot()
{
}

} // end namespace box2D
} // end namespace collision
