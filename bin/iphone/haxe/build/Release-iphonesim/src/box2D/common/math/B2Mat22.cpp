#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_box2D_common_math_B2Mat22
#include <box2D/common/math/B2Mat22.h>
#endif
#ifndef INCLUDED_box2D_common_math_B2Vec2
#include <box2D/common/math/B2Vec2.h>
#endif
namespace box2D{
namespace common{
namespace math{

Void B2Mat22_obj::__construct()
{
{
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Mat22.hx",29)
	this->col1 = ::box2D::common::math::B2Vec2_obj::__new((int)0,1.0);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Mat22.hx",30)
	this->col2 = ::box2D::common::math::B2Vec2_obj::__new((int)0,1.0);
}
;
	return null();
}

B2Mat22_obj::~B2Mat22_obj() { }

Dynamic B2Mat22_obj::__CreateEmpty() { return  new B2Mat22_obj; }
hx::ObjectPtr< B2Mat22_obj > B2Mat22_obj::__new()
{  hx::ObjectPtr< B2Mat22_obj > result = new B2Mat22_obj();
	result->__construct();
	return result;}

Dynamic B2Mat22_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2Mat22_obj > result = new B2Mat22_obj();
	result->__construct();
	return result;}

Void B2Mat22_obj::set( double angle){
{
		HX_SOURCE_PUSH("B2Mat22_obj::set")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Mat22.hx",49)
		double c = ::Math_obj::cos(angle);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Mat22.hx",50)
		double s = ::Math_obj::sin(angle);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Mat22.hx",51)
		this->col1->x = c;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Mat22.hx",51)
		this->col2->x = -(s);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Mat22.hx",52)
		this->col1->y = s;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Mat22.hx",52)
		this->col2->y = c;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2Mat22_obj,set,(void))

Void B2Mat22_obj::setVV( ::box2D::common::math::B2Vec2 c1,::box2D::common::math::B2Vec2 c2){
{
		HX_SOURCE_PUSH("B2Mat22_obj::setVV")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Mat22.hx",57)
		this->col1->setV(c1);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Mat22.hx",58)
		this->col2->setV(c2);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(B2Mat22_obj,setVV,(void))

::box2D::common::math::B2Mat22 B2Mat22_obj::copy( ){
	HX_SOURCE_PUSH("B2Mat22_obj::copy")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Mat22.hx",62)
	::box2D::common::math::B2Mat22 mat = ::box2D::common::math::B2Mat22_obj::__new();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Mat22.hx",63)
	mat->setM(hx::ObjectPtr<OBJ_>(this));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Mat22.hx",64)
	return mat;
}


HX_DEFINE_DYNAMIC_FUNC0(B2Mat22_obj,copy,return )

Void B2Mat22_obj::setM( ::box2D::common::math::B2Mat22 m){
{
		HX_SOURCE_PUSH("B2Mat22_obj::setM")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Mat22.hx",69)
		this->col1->setV(m->col1);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Mat22.hx",70)
		this->col2->setV(m->col2);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2Mat22_obj,setM,(void))

Void B2Mat22_obj::addM( ::box2D::common::math::B2Mat22 m){
{
		HX_SOURCE_PUSH("B2Mat22_obj::addM")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Mat22.hx",75)
		hx::AddEq(this->col1->x,m->col1->x);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Mat22.hx",76)
		hx::AddEq(this->col1->y,m->col1->y);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Mat22.hx",77)
		hx::AddEq(this->col2->x,m->col2->x);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Mat22.hx",78)
		hx::AddEq(this->col2->y,m->col2->y);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2Mat22_obj,addM,(void))

Void B2Mat22_obj::setIdentity( ){
{
		HX_SOURCE_PUSH("B2Mat22_obj::setIdentity")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Mat22.hx",83)
		this->col1->x = 1.0;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Mat22.hx",83)
		this->col2->x = 0.0;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Mat22.hx",84)
		this->col1->y = 0.0;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Mat22.hx",84)
		this->col2->y = 1.0;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(B2Mat22_obj,setIdentity,(void))

Void B2Mat22_obj::setZero( ){
{
		HX_SOURCE_PUSH("B2Mat22_obj::setZero")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Mat22.hx",89)
		this->col1->x = 0.0;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Mat22.hx",89)
		this->col2->x = 0.0;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Mat22.hx",90)
		this->col1->y = 0.0;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Mat22.hx",90)
		this->col2->y = 0.0;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(B2Mat22_obj,setZero,(void))

double B2Mat22_obj::getAngle( ){
	HX_SOURCE_PUSH("B2Mat22_obj::getAngle")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Mat22.hx",94)
	return ::Math_obj::atan2(this->col1->y,this->col1->x);
}


HX_DEFINE_DYNAMIC_FUNC0(B2Mat22_obj,getAngle,return )

::box2D::common::math::B2Mat22 B2Mat22_obj::getInverse( ::box2D::common::math::B2Mat22 out){
	HX_SOURCE_PUSH("B2Mat22_obj::getInverse")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Mat22.hx",103)
	double a = this->col1->x;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Mat22.hx",104)
	double b = this->col2->x;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Mat22.hx",105)
	double c = this->col1->y;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Mat22.hx",106)
	double d = this->col2->y;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Mat22.hx",108)
	double det = ((a * d) - (b * c));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Mat22.hx",109)
	if (((det != 0.0))){
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Mat22.hx",110)
		det = (double(1.0) / double(det));
	}
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Mat22.hx",113)
	out->col1->x = (det * d);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Mat22.hx",113)
	out->col2->x = (-(det) * b);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Mat22.hx",114)
	out->col1->y = (-(det) * c);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Mat22.hx",114)
	out->col2->y = (det * a);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Mat22.hx",115)
	return out;
}


HX_DEFINE_DYNAMIC_FUNC1(B2Mat22_obj,getInverse,return )

::box2D::common::math::B2Vec2 B2Mat22_obj::solve( ::box2D::common::math::B2Vec2 out,double bX,double bY){
	HX_SOURCE_PUSH("B2Mat22_obj::solve")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Mat22.hx",122)
	double a11 = this->col1->x;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Mat22.hx",123)
	double a12 = this->col2->x;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Mat22.hx",124)
	double a21 = this->col1->y;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Mat22.hx",125)
	double a22 = this->col2->y;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Mat22.hx",127)
	double det = ((a11 * a22) - (a12 * a21));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Mat22.hx",128)
	if (((det != 0.0))){
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Mat22.hx",129)
		det = (double(1.0) / double(det));
	}
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Mat22.hx",132)
	out->x = (det * (((a22 * bX) - (a12 * bY))));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Mat22.hx",133)
	out->y = (det * (((a11 * bY) - (a21 * bX))));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Mat22.hx",135)
	return out;
}


HX_DEFINE_DYNAMIC_FUNC3(B2Mat22_obj,solve,return )

Void B2Mat22_obj::abs( ){
{
		HX_SOURCE_PUSH("B2Mat22_obj::abs")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Mat22.hx",140)
		this->col1->abs();
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Mat22.hx",141)
		this->col2->abs();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(B2Mat22_obj,abs,(void))

::box2D::common::math::B2Mat22 B2Mat22_obj::fromAngle( double angle){
	HX_SOURCE_PUSH("B2Mat22_obj::fromAngle")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Mat22.hx",35)
	::box2D::common::math::B2Mat22 mat = ::box2D::common::math::B2Mat22_obj::__new();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Mat22.hx",36)
	mat->set(angle);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Mat22.hx",37)
	return mat;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(B2Mat22_obj,fromAngle,return )

::box2D::common::math::B2Mat22 B2Mat22_obj::fromVV( ::box2D::common::math::B2Vec2 c1,::box2D::common::math::B2Vec2 c2){
	HX_SOURCE_PUSH("B2Mat22_obj::fromVV")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Mat22.hx",42)
	::box2D::common::math::B2Mat22 mat = ::box2D::common::math::B2Mat22_obj::__new();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Mat22.hx",43)
	mat->setVV(c1,c2);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Mat22.hx",44)
	return mat;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(B2Mat22_obj,fromVV,return )


B2Mat22_obj::B2Mat22_obj()
{
}

void B2Mat22_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(B2Mat22);
	HX_MARK_MEMBER_NAME(col1,"col1");
	HX_MARK_MEMBER_NAME(col2,"col2");
	HX_MARK_END_CLASS();
}

Dynamic B2Mat22_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"set") ) { return set_dyn(); }
		if (HX_FIELD_EQ(inName,"abs") ) { return abs_dyn(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"copy") ) { return copy_dyn(); }
		if (HX_FIELD_EQ(inName,"setM") ) { return setM_dyn(); }
		if (HX_FIELD_EQ(inName,"addM") ) { return addM_dyn(); }
		if (HX_FIELD_EQ(inName,"col1") ) { return col1; }
		if (HX_FIELD_EQ(inName,"col2") ) { return col2; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"setVV") ) { return setVV_dyn(); }
		if (HX_FIELD_EQ(inName,"solve") ) { return solve_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"fromVV") ) { return fromVV_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"setZero") ) { return setZero_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"getAngle") ) { return getAngle_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"fromAngle") ) { return fromAngle_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"getInverse") ) { return getInverse_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"setIdentity") ) { return setIdentity_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic B2Mat22_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"col1") ) { col1=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"col2") ) { col2=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void B2Mat22_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("col1"));
	outFields->push(HX_CSTRING("col2"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("fromAngle"),
	HX_CSTRING("fromVV"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("set"),
	HX_CSTRING("setVV"),
	HX_CSTRING("copy"),
	HX_CSTRING("setM"),
	HX_CSTRING("addM"),
	HX_CSTRING("setIdentity"),
	HX_CSTRING("setZero"),
	HX_CSTRING("getAngle"),
	HX_CSTRING("getInverse"),
	HX_CSTRING("solve"),
	HX_CSTRING("abs"),
	HX_CSTRING("col1"),
	HX_CSTRING("col2"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class B2Mat22_obj::__mClass;

void B2Mat22_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.common.math.B2Mat22"), hx::TCanCast< B2Mat22_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void B2Mat22_obj::__boot()
{
}

} // end namespace box2D
} // end namespace common
} // end namespace math
