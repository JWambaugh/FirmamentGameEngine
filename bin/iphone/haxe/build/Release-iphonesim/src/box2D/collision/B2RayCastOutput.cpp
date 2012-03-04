#include <hxcpp.h>

#ifndef INCLUDED_box2D_collision_B2RayCastOutput
#include <box2D/collision/B2RayCastOutput.h>
#endif
#ifndef INCLUDED_box2D_common_math_B2Vec2
#include <box2D/common/math/B2Vec2.h>
#endif
namespace box2D{
namespace collision{

Void B2RayCastOutput_obj::__construct()
{
{
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2RayCastOutput.hx",29)
	this->normal = ::box2D::common::math::B2Vec2_obj::__new(null(),null());
}
;
	return null();
}

B2RayCastOutput_obj::~B2RayCastOutput_obj() { }

Dynamic B2RayCastOutput_obj::__CreateEmpty() { return  new B2RayCastOutput_obj; }
hx::ObjectPtr< B2RayCastOutput_obj > B2RayCastOutput_obj::__new()
{  hx::ObjectPtr< B2RayCastOutput_obj > result = new B2RayCastOutput_obj();
	result->__construct();
	return result;}

Dynamic B2RayCastOutput_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2RayCastOutput_obj > result = new B2RayCastOutput_obj();
	result->__construct();
	return result;}


B2RayCastOutput_obj::B2RayCastOutput_obj()
{
}

void B2RayCastOutput_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(B2RayCastOutput);
	HX_MARK_MEMBER_NAME(normal,"normal");
	HX_MARK_MEMBER_NAME(fraction,"fraction");
	HX_MARK_END_CLASS();
}

Dynamic B2RayCastOutput_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"normal") ) { return normal; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"fraction") ) { return fraction; }
	}
	return super::__Field(inName);
}

Dynamic B2RayCastOutput_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"normal") ) { normal=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"fraction") ) { fraction=inValue.Cast< double >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void B2RayCastOutput_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("normal"));
	outFields->push(HX_CSTRING("fraction"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("normal"),
	HX_CSTRING("fraction"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class B2RayCastOutput_obj::__mClass;

void B2RayCastOutput_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.collision.B2RayCastOutput"), hx::TCanCast< B2RayCastOutput_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void B2RayCastOutput_obj::__boot()
{
}

} // end namespace box2D
} // end namespace collision
