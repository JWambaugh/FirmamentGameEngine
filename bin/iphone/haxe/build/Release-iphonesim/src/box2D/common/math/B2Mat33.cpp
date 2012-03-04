#include <hxcpp.h>

#ifndef INCLUDED_box2D_common_math_B2Mat33
#include <box2D/common/math/B2Mat33.h>
#endif
#ifndef INCLUDED_box2D_common_math_B2Vec2
#include <box2D/common/math/B2Vec2.h>
#endif
#ifndef INCLUDED_box2D_common_math_B2Vec3
#include <box2D/common/math/B2Vec3.h>
#endif
namespace box2D{
namespace common{
namespace math{

Void B2Mat33_obj::__construct(::box2D::common::math::B2Vec3 c1,::box2D::common::math::B2Vec3 c2,::box2D::common::math::B2Vec3 c3)
{
{
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Mat33.hx",30)
	this->col1 = ::box2D::common::math::B2Vec3_obj::__new(null(),null(),null());
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Mat33.hx",31)
	this->col2 = ::box2D::common::math::B2Vec3_obj::__new(null(),null(),null());
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Mat33.hx",32)
	this->col3 = ::box2D::common::math::B2Vec3_obj::__new(null(),null(),null());
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Mat33.hx",34)
	if (((bool((bool((c1 == null())) && bool((c2 == null())))) && bool((c3 == null()))))){
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Mat33.hx",36)
		this->col1->setZero();
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Mat33.hx",37)
		this->col2->setZero();
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Mat33.hx",38)
		this->col3->setZero();
	}
	else{
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Mat33.hx",42)
		this->col1->setV(c1);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Mat33.hx",43)
		this->col2->setV(c2);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Mat33.hx",44)
		this->col3->setV(c3);
	}
}
;
	return null();
}

B2Mat33_obj::~B2Mat33_obj() { }

Dynamic B2Mat33_obj::__CreateEmpty() { return  new B2Mat33_obj; }
hx::ObjectPtr< B2Mat33_obj > B2Mat33_obj::__new(::box2D::common::math::B2Vec3 c1,::box2D::common::math::B2Vec3 c2,::box2D::common::math::B2Vec3 c3)
{  hx::ObjectPtr< B2Mat33_obj > result = new B2Mat33_obj();
	result->__construct(c1,c2,c3);
	return result;}

Dynamic B2Mat33_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2Mat33_obj > result = new B2Mat33_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

Void B2Mat33_obj::setVVV( ::box2D::common::math::B2Vec3 c1,::box2D::common::math::B2Vec3 c2,::box2D::common::math::B2Vec3 c3){
{
		HX_SOURCE_PUSH("B2Mat33_obj::setVVV")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Mat33.hx",50)
		this->col1->setV(c1);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Mat33.hx",51)
		this->col2->setV(c2);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Mat33.hx",52)
		this->col3->setV(c3);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(B2Mat33_obj,setVVV,(void))

::box2D::common::math::B2Mat33 B2Mat33_obj::copy( ){
	HX_SOURCE_PUSH("B2Mat33_obj::copy")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Mat33.hx",55)
	return ::box2D::common::math::B2Mat33_obj::__new(this->col1,this->col2,this->col3);
}


HX_DEFINE_DYNAMIC_FUNC0(B2Mat33_obj,copy,return )

Void B2Mat33_obj::setM( ::box2D::common::math::B2Mat33 m){
{
		HX_SOURCE_PUSH("B2Mat33_obj::setM")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Mat33.hx",61)
		this->col1->setV(m->col1);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Mat33.hx",62)
		this->col2->setV(m->col2);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Mat33.hx",63)
		this->col3->setV(m->col3);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2Mat33_obj,setM,(void))

Void B2Mat33_obj::addM( ::box2D::common::math::B2Mat33 m){
{
		HX_SOURCE_PUSH("B2Mat33_obj::addM")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Mat33.hx",68)
		hx::AddEq(this->col1->x,m->col1->x);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Mat33.hx",69)
		hx::AddEq(this->col1->y,m->col1->y);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Mat33.hx",70)
		hx::AddEq(this->col1->z,m->col1->z);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Mat33.hx",71)
		hx::AddEq(this->col2->x,m->col2->x);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Mat33.hx",72)
		hx::AddEq(this->col2->y,m->col2->y);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Mat33.hx",73)
		hx::AddEq(this->col2->z,m->col2->z);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Mat33.hx",74)
		hx::AddEq(this->col3->x,m->col3->x);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Mat33.hx",75)
		hx::AddEq(this->col3->y,m->col3->y);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Mat33.hx",76)
		hx::AddEq(this->col3->z,m->col3->z);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2Mat33_obj,addM,(void))

Void B2Mat33_obj::setIdentity( ){
{
		HX_SOURCE_PUSH("B2Mat33_obj::setIdentity")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Mat33.hx",81)
		this->col1->x = 1.0;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Mat33.hx",81)
		this->col2->x = 0.0;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Mat33.hx",81)
		this->col3->x = 0.0;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Mat33.hx",82)
		this->col1->y = 0.0;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Mat33.hx",82)
		this->col2->y = 1.0;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Mat33.hx",82)
		this->col3->y = 0.0;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Mat33.hx",83)
		this->col1->z = 0.0;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Mat33.hx",83)
		this->col2->z = 0.0;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Mat33.hx",83)
		this->col3->z = 1.0;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(B2Mat33_obj,setIdentity,(void))

Void B2Mat33_obj::setZero( ){
{
		HX_SOURCE_PUSH("B2Mat33_obj::setZero")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Mat33.hx",88)
		this->col1->x = 0.0;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Mat33.hx",88)
		this->col2->x = 0.0;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Mat33.hx",88)
		this->col3->x = 0.0;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Mat33.hx",89)
		this->col1->y = 0.0;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Mat33.hx",89)
		this->col2->y = 0.0;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Mat33.hx",89)
		this->col3->y = 0.0;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Mat33.hx",90)
		this->col1->z = 0.0;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Mat33.hx",90)
		this->col2->z = 0.0;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Mat33.hx",90)
		this->col3->z = 0.0;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(B2Mat33_obj,setZero,(void))

::box2D::common::math::B2Vec2 B2Mat33_obj::solve22( ::box2D::common::math::B2Vec2 out,double bX,double bY){
	HX_SOURCE_PUSH("B2Mat33_obj::solve22")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Mat33.hx",97)
	double a11 = this->col1->x;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Mat33.hx",98)
	double a12 = this->col2->x;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Mat33.hx",99)
	double a21 = this->col1->y;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Mat33.hx",100)
	double a22 = this->col2->y;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Mat33.hx",102)
	double det = ((a11 * a22) - (a12 * a21));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Mat33.hx",103)
	if (((det != 0.0))){
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Mat33.hx",104)
		det = (double(1.0) / double(det));
	}
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Mat33.hx",107)
	out->x = (det * (((a22 * bX) - (a12 * bY))));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Mat33.hx",108)
	out->y = (det * (((a11 * bY) - (a21 * bX))));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Mat33.hx",110)
	return out;
}


HX_DEFINE_DYNAMIC_FUNC3(B2Mat33_obj,solve22,return )

::box2D::common::math::B2Vec3 B2Mat33_obj::solve33( ::box2D::common::math::B2Vec3 out,double bX,double bY,double bZ){
	HX_SOURCE_PUSH("B2Mat33_obj::solve33")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Mat33.hx",116)
	double a11 = this->col1->x;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Mat33.hx",117)
	double a21 = this->col1->y;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Mat33.hx",118)
	double a31 = this->col1->z;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Mat33.hx",119)
	double a12 = this->col2->x;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Mat33.hx",120)
	double a22 = this->col2->y;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Mat33.hx",121)
	double a32 = this->col2->z;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Mat33.hx",122)
	double a13 = this->col3->x;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Mat33.hx",123)
	double a23 = this->col3->y;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Mat33.hx",124)
	double a33 = this->col3->z;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Mat33.hx",126)
	double det = (((a11 * (((a22 * a33) - (a32 * a23)))) + (a21 * (((a32 * a13) - (a12 * a33))))) + (a31 * (((a12 * a23) - (a22 * a13)))));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Mat33.hx",129)
	if (((det != 0.0))){
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Mat33.hx",130)
		det = (double(1.0) / double(det));
	}
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Mat33.hx",134)
	out->x = (det * ((((bX * (((a22 * a33) - (a32 * a23)))) + (bY * (((a32 * a13) - (a12 * a33))))) + (bZ * (((a12 * a23) - (a22 * a13)))))));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Mat33.hx",138)
	out->y = (det * ((((a11 * (((bY * a33) - (bZ * a23)))) + (a21 * (((bZ * a13) - (bX * a33))))) + (a31 * (((bX * a23) - (bY * a13)))))));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Mat33.hx",142)
	out->z = (det * ((((a11 * (((a22 * bZ) - (a32 * bY)))) + (a21 * (((a32 * bX) - (a12 * bZ))))) + (a31 * (((a12 * bY) - (a22 * bX)))))));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Mat33.hx",145)
	return out;
}


HX_DEFINE_DYNAMIC_FUNC4(B2Mat33_obj,solve33,return )


B2Mat33_obj::B2Mat33_obj()
{
}

void B2Mat33_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(B2Mat33);
	HX_MARK_MEMBER_NAME(col1,"col1");
	HX_MARK_MEMBER_NAME(col2,"col2");
	HX_MARK_MEMBER_NAME(col3,"col3");
	HX_MARK_END_CLASS();
}

Dynamic B2Mat33_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"copy") ) { return copy_dyn(); }
		if (HX_FIELD_EQ(inName,"setM") ) { return setM_dyn(); }
		if (HX_FIELD_EQ(inName,"addM") ) { return addM_dyn(); }
		if (HX_FIELD_EQ(inName,"col1") ) { return col1; }
		if (HX_FIELD_EQ(inName,"col2") ) { return col2; }
		if (HX_FIELD_EQ(inName,"col3") ) { return col3; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"setVVV") ) { return setVVV_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"setZero") ) { return setZero_dyn(); }
		if (HX_FIELD_EQ(inName,"solve22") ) { return solve22_dyn(); }
		if (HX_FIELD_EQ(inName,"solve33") ) { return solve33_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"setIdentity") ) { return setIdentity_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic B2Mat33_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"col1") ) { col1=inValue.Cast< ::box2D::common::math::B2Vec3 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"col2") ) { col2=inValue.Cast< ::box2D::common::math::B2Vec3 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"col3") ) { col3=inValue.Cast< ::box2D::common::math::B2Vec3 >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void B2Mat33_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("col1"));
	outFields->push(HX_CSTRING("col2"));
	outFields->push(HX_CSTRING("col3"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("setVVV"),
	HX_CSTRING("copy"),
	HX_CSTRING("setM"),
	HX_CSTRING("addM"),
	HX_CSTRING("setIdentity"),
	HX_CSTRING("setZero"),
	HX_CSTRING("solve22"),
	HX_CSTRING("solve33"),
	HX_CSTRING("col1"),
	HX_CSTRING("col2"),
	HX_CSTRING("col3"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class B2Mat33_obj::__mClass;

void B2Mat33_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.common.math.B2Mat33"), hx::TCanCast< B2Mat33_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void B2Mat33_obj::__boot()
{
}

} // end namespace box2D
} // end namespace common
} // end namespace math
