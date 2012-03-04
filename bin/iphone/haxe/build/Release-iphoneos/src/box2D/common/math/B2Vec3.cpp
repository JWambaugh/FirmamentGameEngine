#include <hxcpp.h>

#ifndef INCLUDED_box2D_common_math_B2Vec3
#include <box2D/common/math/B2Vec3.h>
#endif
namespace box2D{
namespace common{
namespace math{

Void B2Vec3_obj::__construct(Dynamic __o_x,Dynamic __o_y,Dynamic __o_z)
{
double x = __o_x.Default(0);
double y = __o_y.Default(0);
double z = __o_z.Default(0);
{
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Vec3.hx",33)
	this->x = x;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Vec3.hx",34)
	this->y = y;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Vec3.hx",35)
	this->z = z;
}
;
	return null();
}

B2Vec3_obj::~B2Vec3_obj() { }

Dynamic B2Vec3_obj::__CreateEmpty() { return  new B2Vec3_obj; }
hx::ObjectPtr< B2Vec3_obj > B2Vec3_obj::__new(Dynamic __o_x,Dynamic __o_y,Dynamic __o_z)
{  hx::ObjectPtr< B2Vec3_obj > result = new B2Vec3_obj();
	result->__construct(__o_x,__o_y,__o_z);
	return result;}

Dynamic B2Vec3_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2Vec3_obj > result = new B2Vec3_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

Void B2Vec3_obj::setZero( ){
{
		HX_SOURCE_PUSH("B2Vec3_obj::setZero")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Vec3.hx",42)
		this->x = this->y = this->z = 0.0;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(B2Vec3_obj,setZero,(void))

Void B2Vec3_obj::set( double x,double y,double z){
{
		HX_SOURCE_PUSH("B2Vec3_obj::set")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Vec3.hx",51)
		this->x = x;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Vec3.hx",52)
		this->y = y;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Vec3.hx",53)
		this->z = z;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(B2Vec3_obj,set,(void))

Void B2Vec3_obj::setV( ::box2D::common::math::B2Vec3 v){
{
		HX_SOURCE_PUSH("B2Vec3_obj::setV")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Vec3.hx",58)
		this->x = v->x;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Vec3.hx",59)
		this->y = v->y;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Vec3.hx",60)
		this->z = v->z;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2Vec3_obj,setV,(void))

::box2D::common::math::B2Vec3 B2Vec3_obj::getNegative( ){
	HX_SOURCE_PUSH("B2Vec3_obj::getNegative")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Vec3.hx",66)
	return ::box2D::common::math::B2Vec3_obj::__new(-(this->x),-(this->y),-(this->z));
}


HX_DEFINE_DYNAMIC_FUNC0(B2Vec3_obj,getNegative,return )

Void B2Vec3_obj::negativeSelf( ){
{
		HX_SOURCE_PUSH("B2Vec3_obj::negativeSelf")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Vec3.hx",68)
		this->x = -(this->x);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Vec3.hx",68)
		this->y = -(this->y);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Vec3.hx",68)
		this->z = -(this->z);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(B2Vec3_obj,negativeSelf,(void))

::box2D::common::math::B2Vec3 B2Vec3_obj::copy( ){
	HX_SOURCE_PUSH("B2Vec3_obj::copy")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Vec3.hx",70)
	return ::box2D::common::math::B2Vec3_obj::__new(this->x,this->y,this->z);
}


HX_DEFINE_DYNAMIC_FUNC0(B2Vec3_obj,copy,return )

Void B2Vec3_obj::add( ::box2D::common::math::B2Vec3 v){
{
		HX_SOURCE_PUSH("B2Vec3_obj::add")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Vec3.hx",76)
		hx::AddEq(this->x,v->x);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Vec3.hx",76)
		hx::AddEq(this->y,v->y);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Vec3.hx",76)
		hx::AddEq(this->z,v->z);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2Vec3_obj,add,(void))

Void B2Vec3_obj::subtract( ::box2D::common::math::B2Vec3 v){
{
		HX_SOURCE_PUSH("B2Vec3_obj::subtract")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Vec3.hx",81)
		hx::SubEq(this->x,v->x);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Vec3.hx",81)
		hx::SubEq(this->y,v->y);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Vec3.hx",81)
		hx::SubEq(this->z,v->z);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2Vec3_obj,subtract,(void))

Void B2Vec3_obj::multiply( double a){
{
		HX_SOURCE_PUSH("B2Vec3_obj::multiply")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Vec3.hx",86)
		hx::MultEq(this->x,a);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Vec3.hx",86)
		hx::MultEq(this->y,a);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Vec3.hx",86)
		hx::MultEq(this->z,a);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2Vec3_obj,multiply,(void))


B2Vec3_obj::B2Vec3_obj()
{
}

void B2Vec3_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(B2Vec3);
	HX_MARK_MEMBER_NAME(x,"x");
	HX_MARK_MEMBER_NAME(y,"y");
	HX_MARK_MEMBER_NAME(z,"z");
	HX_MARK_END_CLASS();
}

Dynamic B2Vec3_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"x") ) { return x; }
		if (HX_FIELD_EQ(inName,"y") ) { return y; }
		if (HX_FIELD_EQ(inName,"z") ) { return z; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"set") ) { return set_dyn(); }
		if (HX_FIELD_EQ(inName,"add") ) { return add_dyn(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"setV") ) { return setV_dyn(); }
		if (HX_FIELD_EQ(inName,"copy") ) { return copy_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"setZero") ) { return setZero_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"subtract") ) { return subtract_dyn(); }
		if (HX_FIELD_EQ(inName,"multiply") ) { return multiply_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"getNegative") ) { return getNegative_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"negativeSelf") ) { return negativeSelf_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic B2Vec3_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"x") ) { x=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"y") ) { y=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"z") ) { z=inValue.Cast< double >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void B2Vec3_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("x"));
	outFields->push(HX_CSTRING("y"));
	outFields->push(HX_CSTRING("z"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
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
	HX_CSTRING("x"),
	HX_CSTRING("y"),
	HX_CSTRING("z"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class B2Vec3_obj::__mClass;

void B2Vec3_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.common.math.B2Vec3"), hx::TCanCast< B2Vec3_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void B2Vec3_obj::__boot()
{
}

} // end namespace box2D
} // end namespace common
} // end namespace math
