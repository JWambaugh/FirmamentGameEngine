#include <hxcpp.h>

#ifndef INCLUDED_box2D_common_math_B2Mat22
#include <box2D/common/math/B2Mat22.h>
#endif
#ifndef INCLUDED_box2D_common_math_B2Sweep
#include <box2D/common/math/B2Sweep.h>
#endif
#ifndef INCLUDED_box2D_common_math_B2Transform
#include <box2D/common/math/B2Transform.h>
#endif
#ifndef INCLUDED_box2D_common_math_B2Vec2
#include <box2D/common/math/B2Vec2.h>
#endif
namespace box2D{
namespace common{
namespace math{

Void B2Sweep_obj::__construct()
{
{
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Sweep.hx",33)
	this->localCenter = ::box2D::common::math::B2Vec2_obj::__new(null(),null());
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Sweep.hx",34)
	this->c0 = ::box2D::common::math::B2Vec2_obj::__new(null(),null());
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Sweep.hx",35)
	this->c = ::box2D::common::math::B2Vec2_obj::__new(null(),null());
}
;
	return null();
}

B2Sweep_obj::~B2Sweep_obj() { }

Dynamic B2Sweep_obj::__CreateEmpty() { return  new B2Sweep_obj; }
hx::ObjectPtr< B2Sweep_obj > B2Sweep_obj::__new()
{  hx::ObjectPtr< B2Sweep_obj > result = new B2Sweep_obj();
	result->__construct();
	return result;}

Dynamic B2Sweep_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2Sweep_obj > result = new B2Sweep_obj();
	result->__construct();
	return result;}

Void B2Sweep_obj::set( ::box2D::common::math::B2Sweep other){
{
		HX_SOURCE_PUSH("B2Sweep_obj::set")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Sweep.hx",41)
		this->localCenter->setV(other->localCenter);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Sweep.hx",42)
		this->c0->setV(other->c0);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Sweep.hx",43)
		this->c->setV(other->c);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Sweep.hx",44)
		this->a0 = other->a0;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Sweep.hx",45)
		this->a = other->a;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Sweep.hx",46)
		this->t0 = other->t0;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2Sweep_obj,set,(void))

::box2D::common::math::B2Sweep B2Sweep_obj::copy( ){
	HX_SOURCE_PUSH("B2Sweep_obj::copy")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Sweep.hx",51)
	::box2D::common::math::B2Sweep copy = ::box2D::common::math::B2Sweep_obj::__new();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Sweep.hx",52)
	copy->localCenter->setV(this->localCenter);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Sweep.hx",53)
	copy->c0->setV(this->c0);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Sweep.hx",54)
	copy->c->setV(this->c);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Sweep.hx",55)
	copy->a0 = this->a0;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Sweep.hx",56)
	copy->a = this->a;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Sweep.hx",57)
	copy->t0 = this->t0;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Sweep.hx",58)
	return copy;
}


HX_DEFINE_DYNAMIC_FUNC0(B2Sweep_obj,copy,return )

Void B2Sweep_obj::getTransform( ::box2D::common::math::B2Transform xf,double alpha){
{
		HX_SOURCE_PUSH("B2Sweep_obj::getTransform")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Sweep.hx",67)
		xf->position->x = ((((1.0 - alpha)) * this->c0->x) + (alpha * this->c->x));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Sweep.hx",68)
		xf->position->y = ((((1.0 - alpha)) * this->c0->y) + (alpha * this->c->y));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Sweep.hx",69)
		double angle = ((((1.0 - alpha)) * this->a0) + (alpha * this->a));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Sweep.hx",70)
		xf->R->set(angle);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Sweep.hx",74)
		::box2D::common::math::B2Mat22 tMat = xf->R;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Sweep.hx",75)
		hx::SubEq(xf->position->x,((tMat->col1->x * this->localCenter->x) + (tMat->col2->x * this->localCenter->y)));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Sweep.hx",76)
		hx::SubEq(xf->position->y,((tMat->col1->y * this->localCenter->x) + (tMat->col2->y * this->localCenter->y)));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(B2Sweep_obj,getTransform,(void))

Void B2Sweep_obj::advance( double t){
{
		HX_SOURCE_PUSH("B2Sweep_obj::advance")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Sweep.hx",83)
		if (((bool((this->t0 < t)) && bool(((1.0 - this->t0) > 2.2250738585072014e-308))))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Sweep.hx",86)
			double alpha = (double(((t - this->t0))) / double(((1.0 - this->t0))));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Sweep.hx",88)
			this->c0->x = ((((1.0 - alpha)) * this->c0->x) + (alpha * this->c->x));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Sweep.hx",89)
			this->c0->y = ((((1.0 - alpha)) * this->c0->y) + (alpha * this->c->y));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Sweep.hx",90)
			this->a0 = ((((1.0 - alpha)) * this->a0) + (alpha * this->a));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Sweep.hx",91)
			this->t0 = t;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2Sweep_obj,advance,(void))


B2Sweep_obj::B2Sweep_obj()
{
}

void B2Sweep_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(B2Sweep);
	HX_MARK_MEMBER_NAME(localCenter,"localCenter");
	HX_MARK_MEMBER_NAME(c0,"c0");
	HX_MARK_MEMBER_NAME(c,"c");
	HX_MARK_MEMBER_NAME(a0,"a0");
	HX_MARK_MEMBER_NAME(a,"a");
	HX_MARK_MEMBER_NAME(t0,"t0");
	HX_MARK_END_CLASS();
}

Dynamic B2Sweep_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"c") ) { return c; }
		if (HX_FIELD_EQ(inName,"a") ) { return a; }
		break;
	case 2:
		if (HX_FIELD_EQ(inName,"c0") ) { return c0; }
		if (HX_FIELD_EQ(inName,"a0") ) { return a0; }
		if (HX_FIELD_EQ(inName,"t0") ) { return t0; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"set") ) { return set_dyn(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"copy") ) { return copy_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"advance") ) { return advance_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"localCenter") ) { return localCenter; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"getTransform") ) { return getTransform_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic B2Sweep_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"c") ) { c=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"a") ) { a=inValue.Cast< double >(); return inValue; }
		break;
	case 2:
		if (HX_FIELD_EQ(inName,"c0") ) { c0=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"a0") ) { a0=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"t0") ) { t0=inValue.Cast< double >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"localCenter") ) { localCenter=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void B2Sweep_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("localCenter"));
	outFields->push(HX_CSTRING("c0"));
	outFields->push(HX_CSTRING("c"));
	outFields->push(HX_CSTRING("a0"));
	outFields->push(HX_CSTRING("a"));
	outFields->push(HX_CSTRING("t0"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("set"),
	HX_CSTRING("copy"),
	HX_CSTRING("getTransform"),
	HX_CSTRING("advance"),
	HX_CSTRING("localCenter"),
	HX_CSTRING("c0"),
	HX_CSTRING("c"),
	HX_CSTRING("a0"),
	HX_CSTRING("a"),
	HX_CSTRING("t0"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class B2Sweep_obj::__mClass;

void B2Sweep_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.common.math.B2Sweep"), hx::TCanCast< B2Sweep_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void B2Sweep_obj::__boot()
{
}

} // end namespace box2D
} // end namespace common
} // end namespace math
