#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_box2D_common_B2Color
#include <box2D/common/B2Color.h>
#endif
#ifndef INCLUDED_box2D_common_math_B2Math
#include <box2D/common/math/B2Math.h>
#endif
namespace box2D{
namespace common{

Void B2Color_obj::__construct(double rr,double gg,double bb)
{
{
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/B2Color.hx",33)
	this->_r = ::Std_obj::_int(((int)255 * ::box2D::common::math::B2Math_obj::clamp(rr,0.0,1.0)));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/B2Color.hx",34)
	this->_g = ::Std_obj::_int(((int)255 * ::box2D::common::math::B2Math_obj::clamp(gg,0.0,1.0)));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/B2Color.hx",35)
	this->_b = ::Std_obj::_int(((int)255 * ::box2D::common::math::B2Math_obj::clamp(bb,0.0,1.0)));
}
;
	return null();
}

B2Color_obj::~B2Color_obj() { }

Dynamic B2Color_obj::__CreateEmpty() { return  new B2Color_obj; }
hx::ObjectPtr< B2Color_obj > B2Color_obj::__new(double rr,double gg,double bb)
{  hx::ObjectPtr< B2Color_obj > result = new B2Color_obj();
	result->__construct(rr,gg,bb);
	return result;}

Dynamic B2Color_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2Color_obj > result = new B2Color_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

Void B2Color_obj::set( double rr,double gg,double bb){
{
		HX_SOURCE_PUSH("B2Color_obj::set")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/B2Color.hx",39)
		this->_r = ::Std_obj::_int(((int)255 * ::box2D::common::math::B2Math_obj::clamp(rr,0.0,1.0)));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/B2Color.hx",40)
		this->_g = ::Std_obj::_int(((int)255 * ::box2D::common::math::B2Math_obj::clamp(gg,0.0,1.0)));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/B2Color.hx",41)
		this->_b = ::Std_obj::_int(((int)255 * ::box2D::common::math::B2Math_obj::clamp(bb,0.0,1.0)));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(B2Color_obj,set,(void))

double B2Color_obj::setR( double rr){
	HX_SOURCE_PUSH("B2Color_obj::setR")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/B2Color.hx",50)
	return this->_r = ::Std_obj::_int(((int)255 * ::box2D::common::math::B2Math_obj::clamp(rr,0.0,1.0)));
}


HX_DEFINE_DYNAMIC_FUNC1(B2Color_obj,setR,return )

double B2Color_obj::setG( double gg){
	HX_SOURCE_PUSH("B2Color_obj::setG")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/B2Color.hx",54)
	return this->_g = ::Std_obj::_int(((int)255 * ::box2D::common::math::B2Math_obj::clamp(gg,0.0,1.0)));
}


HX_DEFINE_DYNAMIC_FUNC1(B2Color_obj,setG,return )

double B2Color_obj::setB( double bb){
	HX_SOURCE_PUSH("B2Color_obj::setB")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/B2Color.hx",58)
	return this->_b = ::Std_obj::_int(((int)255 * ::box2D::common::math::B2Math_obj::clamp(bb,0.0,1.0)));
}


HX_DEFINE_DYNAMIC_FUNC1(B2Color_obj,setB,return )

int B2Color_obj::getColor( ){
	HX_SOURCE_PUSH("B2Color_obj::getColor")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/B2Color.hx",63)
	return (int((int((int(this->_r) << int((int)16))) | int((int(this->_g) << int((int)8))))) | int(this->_b));
}


HX_DEFINE_DYNAMIC_FUNC0(B2Color_obj,getColor,return )


B2Color_obj::B2Color_obj()
{
}

void B2Color_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(B2Color);
	HX_MARK_MEMBER_NAME(r,"r");
	HX_MARK_MEMBER_NAME(g,"g");
	HX_MARK_MEMBER_NAME(b,"b");
	HX_MARK_MEMBER_NAME(color,"color");
	HX_MARK_MEMBER_NAME(_r,"_r");
	HX_MARK_MEMBER_NAME(_g,"_g");
	HX_MARK_MEMBER_NAME(_b,"_b");
	HX_MARK_END_CLASS();
}

Dynamic B2Color_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"r") ) { return r; }
		if (HX_FIELD_EQ(inName,"g") ) { return g; }
		if (HX_FIELD_EQ(inName,"b") ) { return b; }
		break;
	case 2:
		if (HX_FIELD_EQ(inName,"_r") ) { return _r; }
		if (HX_FIELD_EQ(inName,"_g") ) { return _g; }
		if (HX_FIELD_EQ(inName,"_b") ) { return _b; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"set") ) { return set_dyn(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"setR") ) { return setR_dyn(); }
		if (HX_FIELD_EQ(inName,"setG") ) { return setG_dyn(); }
		if (HX_FIELD_EQ(inName,"setB") ) { return setB_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"color") ) { return getColor(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"getColor") ) { return getColor_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic B2Color_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"r") ) { return setR(inValue); }
		if (HX_FIELD_EQ(inName,"g") ) { return setG(inValue); }
		if (HX_FIELD_EQ(inName,"b") ) { return setB(inValue); }
		break;
	case 2:
		if (HX_FIELD_EQ(inName,"_r") ) { _r=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_g") ) { _g=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_b") ) { _b=inValue.Cast< int >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"color") ) { color=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void B2Color_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("r"));
	outFields->push(HX_CSTRING("g"));
	outFields->push(HX_CSTRING("b"));
	outFields->push(HX_CSTRING("color"));
	outFields->push(HX_CSTRING("_r"));
	outFields->push(HX_CSTRING("_g"));
	outFields->push(HX_CSTRING("_b"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("set"),
	HX_CSTRING("r"),
	HX_CSTRING("g"),
	HX_CSTRING("b"),
	HX_CSTRING("color"),
	HX_CSTRING("setR"),
	HX_CSTRING("setG"),
	HX_CSTRING("setB"),
	HX_CSTRING("getColor"),
	HX_CSTRING("_r"),
	HX_CSTRING("_g"),
	HX_CSTRING("_b"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class B2Color_obj::__mClass;

void B2Color_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.common.B2Color"), hx::TCanCast< B2Color_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void B2Color_obj::__boot()
{
}

} // end namespace box2D
} // end namespace common
