#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_box2D_common_math_B2Mat22
#include <box2D/common/math/B2Mat22.h>
#endif
#ifndef INCLUDED_box2D_common_math_B2Math
#include <box2D/common/math/B2Math.h>
#endif
#ifndef INCLUDED_box2D_common_math_B2Vec2
#include <box2D/common/math/B2Vec2.h>
#endif
namespace box2D{
namespace common{
namespace math{

Void B2Vec2_obj::__construct(Dynamic __o_x_,Dynamic __o_y_)
{
double x_ = __o_x_.Default(0);
double y_ = __o_y_.Default(0);
{
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Vec2.hx",28)
	this->x = x_;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Vec2.hx",28)
	this->y = y_;
}
;
	return null();
}

B2Vec2_obj::~B2Vec2_obj() { }

Dynamic B2Vec2_obj::__CreateEmpty() { return  new B2Vec2_obj; }
hx::ObjectPtr< B2Vec2_obj > B2Vec2_obj::__new(Dynamic __o_x_,Dynamic __o_y_)
{  hx::ObjectPtr< B2Vec2_obj > result = new B2Vec2_obj();
	result->__construct(__o_x_,__o_y_);
	return result;}

Dynamic B2Vec2_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2Vec2_obj > result = new B2Vec2_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

Void B2Vec2_obj::setZero( ){
{
		HX_SOURCE_PUSH("B2Vec2_obj::setZero")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Vec2.hx",30)
		this->x = 0.0;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Vec2.hx",30)
		this->y = 0.0;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(B2Vec2_obj,setZero,(void))

Void B2Vec2_obj::set( Dynamic __o_x_,Dynamic __o_y_){
double x_ = __o_x_.Default(0);
double y_ = __o_y_.Default(0);
	HX_SOURCE_PUSH("B2Vec2_obj::set");
{
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Vec2.hx",31)
		this->x = x_;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Vec2.hx",31)
		this->y = y_;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(B2Vec2_obj,set,(void))

Void B2Vec2_obj::setV( ::box2D::common::math::B2Vec2 v){
{
		HX_SOURCE_PUSH("B2Vec2_obj::setV")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Vec2.hx",32)
		this->x = v->x;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Vec2.hx",32)
		this->y = v->y;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2Vec2_obj,setV,(void))

::box2D::common::math::B2Vec2 B2Vec2_obj::getNegative( ){
	HX_SOURCE_PUSH("B2Vec2_obj::getNegative")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Vec2.hx",34)
	return ::box2D::common::math::B2Vec2_obj::__new(-(this->x),-(this->y));
}


HX_DEFINE_DYNAMIC_FUNC0(B2Vec2_obj,getNegative,return )

Void B2Vec2_obj::negativeSelf( ){
{
		HX_SOURCE_PUSH("B2Vec2_obj::negativeSelf")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Vec2.hx",35)
		this->x = -(this->x);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Vec2.hx",35)
		this->y = -(this->y);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(B2Vec2_obj,negativeSelf,(void))

::box2D::common::math::B2Vec2 B2Vec2_obj::copy( ){
	HX_SOURCE_PUSH("B2Vec2_obj::copy")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Vec2.hx",42)
	return ::box2D::common::math::B2Vec2_obj::__new(this->x,this->y);
}


HX_DEFINE_DYNAMIC_FUNC0(B2Vec2_obj,copy,return )

Void B2Vec2_obj::add( ::box2D::common::math::B2Vec2 v){
{
		HX_SOURCE_PUSH("B2Vec2_obj::add")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Vec2.hx",48)
		hx::AddEq(this->x,v->x);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Vec2.hx",48)
		hx::AddEq(this->y,v->y);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2Vec2_obj,add,(void))

Void B2Vec2_obj::subtract( ::box2D::common::math::B2Vec2 v){
{
		HX_SOURCE_PUSH("B2Vec2_obj::subtract")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Vec2.hx",53)
		hx::SubEq(this->x,v->x);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Vec2.hx",53)
		hx::SubEq(this->y,v->y);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2Vec2_obj,subtract,(void))

Void B2Vec2_obj::multiply( double a){
{
		HX_SOURCE_PUSH("B2Vec2_obj::multiply")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Vec2.hx",58)
		hx::MultEq(this->x,a);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Vec2.hx",58)
		hx::MultEq(this->y,a);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2Vec2_obj,multiply,(void))

Void B2Vec2_obj::mulM( ::box2D::common::math::B2Mat22 A){
{
		HX_SOURCE_PUSH("B2Vec2_obj::mulM")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Vec2.hx",63)
		double tX = this->x;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Vec2.hx",64)
		this->x = ((A->col1->x * tX) + (A->col2->x * this->y));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Vec2.hx",65)
		this->y = ((A->col1->y * tX) + (A->col2->y * this->y));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2Vec2_obj,mulM,(void))

Void B2Vec2_obj::mulTM( ::box2D::common::math::B2Mat22 A){
{
		HX_SOURCE_PUSH("B2Vec2_obj::mulTM")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Vec2.hx",70)
		double tX = ::box2D::common::math::B2Math_obj::dot(hx::ObjectPtr<OBJ_>(this),A->col1);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Vec2.hx",71)
		this->y = ::box2D::common::math::B2Math_obj::dot(hx::ObjectPtr<OBJ_>(this),A->col2);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Vec2.hx",72)
		this->x = tX;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2Vec2_obj,mulTM,(void))

Void B2Vec2_obj::crossVF( double s){
{
		HX_SOURCE_PUSH("B2Vec2_obj::crossVF")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Vec2.hx",77)
		double tX = this->x;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Vec2.hx",78)
		this->x = (s * this->y);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Vec2.hx",79)
		this->y = (-(s) * tX);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2Vec2_obj,crossVF,(void))

Void B2Vec2_obj::crossFV( double s){
{
		HX_SOURCE_PUSH("B2Vec2_obj::crossFV")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Vec2.hx",84)
		double tX = this->x;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Vec2.hx",85)
		this->x = (-(s) * this->y);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Vec2.hx",86)
		this->y = (s * tX);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2Vec2_obj,crossFV,(void))

Void B2Vec2_obj::minV( ::box2D::common::math::B2Vec2 b){
{
		HX_SOURCE_PUSH("B2Vec2_obj::minV")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Vec2.hx",91)
		this->x = (  (((this->x < b->x))) ? double(this->x) : double(b->x) );
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Vec2.hx",92)
		this->y = (  (((this->y < b->y))) ? double(this->y) : double(b->y) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2Vec2_obj,minV,(void))

Void B2Vec2_obj::maxV( ::box2D::common::math::B2Vec2 b){
{
		HX_SOURCE_PUSH("B2Vec2_obj::maxV")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Vec2.hx",97)
		this->x = (  (((this->x > b->x))) ? double(this->x) : double(b->x) );
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Vec2.hx",98)
		this->y = (  (((this->y > b->y))) ? double(this->y) : double(b->y) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2Vec2_obj,maxV,(void))

Void B2Vec2_obj::abs( ){
{
		HX_SOURCE_PUSH("B2Vec2_obj::abs")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Vec2.hx",103)
		if (((this->x < (int)0))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Vec2.hx",103)
			this->x = -(this->x);
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Vec2.hx",104)
		if (((this->y < (int)0))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Vec2.hx",104)
			this->y = -(this->y);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(B2Vec2_obj,abs,(void))

double B2Vec2_obj::length( ){
	HX_SOURCE_PUSH("B2Vec2_obj::length")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Vec2.hx",108)
	return ::Math_obj::sqrt(((this->x * this->x) + (this->y * this->y)));
}


HX_DEFINE_DYNAMIC_FUNC0(B2Vec2_obj,length,return )

double B2Vec2_obj::lengthSquared( ){
	HX_SOURCE_PUSH("B2Vec2_obj::lengthSquared")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Vec2.hx",113)
	return ((this->x * this->x) + (this->y * this->y));
}


HX_DEFINE_DYNAMIC_FUNC0(B2Vec2_obj,lengthSquared,return )

double B2Vec2_obj::normalize( ){
	HX_SOURCE_PUSH("B2Vec2_obj::normalize")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Vec2.hx",119)
	double length = ::Math_obj::sqrt(((this->x * this->x) + (this->y * this->y)));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Vec2.hx",120)
	if (((length < 2.2250738585072014e-308))){
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Vec2.hx",121)
		return 0.0;
	}
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Vec2.hx",124)
	double invLength = (double(1.0) / double(length));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Vec2.hx",125)
	hx::MultEq(this->x,invLength);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Vec2.hx",126)
	hx::MultEq(this->y,invLength);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Vec2.hx",128)
	return length;
}


HX_DEFINE_DYNAMIC_FUNC0(B2Vec2_obj,normalize,return )

bool B2Vec2_obj::isValid( ){
	HX_SOURCE_PUSH("B2Vec2_obj::isValid")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Vec2.hx",132)
	return (bool(::box2D::common::math::B2Math_obj::isValid(this->x)) && bool(::box2D::common::math::B2Math_obj::isValid(this->y)));
}


HX_DEFINE_DYNAMIC_FUNC0(B2Vec2_obj,isValid,return )

::box2D::common::math::B2Vec2 B2Vec2_obj::make( double x_,double y_){
	HX_SOURCE_PUSH("B2Vec2_obj::make")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Vec2.hx",38)
	return ::box2D::common::math::B2Vec2_obj::__new(x_,y_);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(B2Vec2_obj,make,return )


B2Vec2_obj::B2Vec2_obj()
{
}

void B2Vec2_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(B2Vec2);
	HX_MARK_MEMBER_NAME(x,"x");
	HX_MARK_MEMBER_NAME(y,"y");
	HX_MARK_END_CLASS();
}

Dynamic B2Vec2_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"x") ) { return x; }
		if (HX_FIELD_EQ(inName,"y") ) { return y; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"set") ) { return set_dyn(); }
		if (HX_FIELD_EQ(inName,"add") ) { return add_dyn(); }
		if (HX_FIELD_EQ(inName,"abs") ) { return abs_dyn(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"make") ) { return make_dyn(); }
		if (HX_FIELD_EQ(inName,"setV") ) { return setV_dyn(); }
		if (HX_FIELD_EQ(inName,"copy") ) { return copy_dyn(); }
		if (HX_FIELD_EQ(inName,"mulM") ) { return mulM_dyn(); }
		if (HX_FIELD_EQ(inName,"minV") ) { return minV_dyn(); }
		if (HX_FIELD_EQ(inName,"maxV") ) { return maxV_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"mulTM") ) { return mulTM_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"length") ) { return length_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"setZero") ) { return setZero_dyn(); }
		if (HX_FIELD_EQ(inName,"crossVF") ) { return crossVF_dyn(); }
		if (HX_FIELD_EQ(inName,"crossFV") ) { return crossFV_dyn(); }
		if (HX_FIELD_EQ(inName,"isValid") ) { return isValid_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"subtract") ) { return subtract_dyn(); }
		if (HX_FIELD_EQ(inName,"multiply") ) { return multiply_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"normalize") ) { return normalize_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"getNegative") ) { return getNegative_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"negativeSelf") ) { return negativeSelf_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"lengthSquared") ) { return lengthSquared_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic B2Vec2_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"x") ) { x=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"y") ) { y=inValue.Cast< double >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void B2Vec2_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("x"));
	outFields->push(HX_CSTRING("y"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("make"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("setZero"),
	HX_CSTRING("set"),
	HX_CSTRING("setV"),
	HX_CSTRING("getNegative"),
	HX_CSTRING("negativeSelf"),
	HX_CSTRING("copy"),
	HX_CSTRING("add"),
	HX_CSTRING("subtract"),
	HX_CSTRING("multiply"),
	HX_CSTRING("mulM"),
	HX_CSTRING("mulTM"),
	HX_CSTRING("crossVF"),
	HX_CSTRING("crossFV"),
	HX_CSTRING("minV"),
	HX_CSTRING("maxV"),
	HX_CSTRING("abs"),
	HX_CSTRING("length"),
	HX_CSTRING("lengthSquared"),
	HX_CSTRING("normalize"),
	HX_CSTRING("isValid"),
	HX_CSTRING("x"),
	HX_CSTRING("y"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class B2Vec2_obj::__mClass;

void B2Vec2_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.common.math.B2Vec2"), hx::TCanCast< B2Vec2_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void B2Vec2_obj::__boot()
{
}

} // end namespace box2D
} // end namespace common
} // end namespace math
