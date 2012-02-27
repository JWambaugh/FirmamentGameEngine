#include <hxcpp.h>

#ifndef INCLUDED_box2D_collision_B2RayCastInput
#include <box2D/collision/B2RayCastInput.h>
#endif
#ifndef INCLUDED_box2D_common_math_B2Vec2
#include <box2D/common/math/B2Vec2.h>
#endif
namespace box2D{
namespace collision{

Void B2RayCastInput_obj::__construct(::box2D::common::math::B2Vec2 p1,::box2D::common::math::B2Vec2 p2,Dynamic __o_maxFraction)
{
double maxFraction = __o_maxFraction.Default(1);
{
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2RayCastInput.hx",31)
	this->p1 = ::box2D::common::math::B2Vec2_obj::__new(null(),null());
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2RayCastInput.hx",32)
	this->p2 = ::box2D::common::math::B2Vec2_obj::__new(null(),null());
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2RayCastInput.hx",34)
	if (((p1 != null()))){
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2RayCastInput.hx",35)
		this->p1->setV(p1);
	}
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2RayCastInput.hx",36)
	if (((p2 != null()))){
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2RayCastInput.hx",37)
		this->p2->setV(p2);
	}
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2RayCastInput.hx",38)
	this->maxFraction = maxFraction;
}
;
	return null();
}

B2RayCastInput_obj::~B2RayCastInput_obj() { }

Dynamic B2RayCastInput_obj::__CreateEmpty() { return  new B2RayCastInput_obj; }
hx::ObjectPtr< B2RayCastInput_obj > B2RayCastInput_obj::__new(::box2D::common::math::B2Vec2 p1,::box2D::common::math::B2Vec2 p2,Dynamic __o_maxFraction)
{  hx::ObjectPtr< B2RayCastInput_obj > result = new B2RayCastInput_obj();
	result->__construct(p1,p2,__o_maxFraction);
	return result;}

Dynamic B2RayCastInput_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2RayCastInput_obj > result = new B2RayCastInput_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}


B2RayCastInput_obj::B2RayCastInput_obj()
{
}

void B2RayCastInput_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(B2RayCastInput);
	HX_MARK_MEMBER_NAME(p1,"p1");
	HX_MARK_MEMBER_NAME(p2,"p2");
	HX_MARK_MEMBER_NAME(maxFraction,"maxFraction");
	HX_MARK_END_CLASS();
}

Dynamic B2RayCastInput_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"p1") ) { return p1; }
		if (HX_FIELD_EQ(inName,"p2") ) { return p2; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"maxFraction") ) { return maxFraction; }
	}
	return super::__Field(inName);
}

Dynamic B2RayCastInput_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"p1") ) { p1=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"p2") ) { p2=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"maxFraction") ) { maxFraction=inValue.Cast< double >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void B2RayCastInput_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("p1"));
	outFields->push(HX_CSTRING("p2"));
	outFields->push(HX_CSTRING("maxFraction"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("p1"),
	HX_CSTRING("p2"),
	HX_CSTRING("maxFraction"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class B2RayCastInput_obj::__mClass;

void B2RayCastInput_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.collision.B2RayCastInput"), hx::TCanCast< B2RayCastInput_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void B2RayCastInput_obj::__boot()
{
}

} // end namespace box2D
} // end namespace collision
