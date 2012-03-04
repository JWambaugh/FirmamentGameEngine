#include <hxcpp.h>

#ifndef INCLUDED_box2D_common_math_B2Vec2
#include <box2D/common/math/B2Vec2.h>
#endif
#ifndef INCLUDED_box2D_dynamics_joints_B2Jacobian
#include <box2D/dynamics/joints/B2Jacobian.h>
#endif
namespace box2D{
namespace dynamics{
namespace joints{

Void B2Jacobian_obj::__construct()
{
{
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2Jacobian.hx",33)
	this->linearA = ::box2D::common::math::B2Vec2_obj::__new(null(),null());
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2Jacobian.hx",34)
	this->linearB = ::box2D::common::math::B2Vec2_obj::__new(null(),null());
}
;
	return null();
}

B2Jacobian_obj::~B2Jacobian_obj() { }

Dynamic B2Jacobian_obj::__CreateEmpty() { return  new B2Jacobian_obj; }
hx::ObjectPtr< B2Jacobian_obj > B2Jacobian_obj::__new()
{  hx::ObjectPtr< B2Jacobian_obj > result = new B2Jacobian_obj();
	result->__construct();
	return result;}

Dynamic B2Jacobian_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2Jacobian_obj > result = new B2Jacobian_obj();
	result->__construct();
	return result;}

Void B2Jacobian_obj::setZero( ){
{
		HX_SOURCE_PUSH("B2Jacobian_obj::setZero")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2Jacobian.hx",44)
		this->linearA->setZero();
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2Jacobian.hx",44)
		this->angularA = 0.0;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2Jacobian.hx",45)
		this->linearB->setZero();
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2Jacobian.hx",45)
		this->angularB = 0.0;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(B2Jacobian_obj,setZero,(void))

Void B2Jacobian_obj::set( ::box2D::common::math::B2Vec2 x1,double a1,::box2D::common::math::B2Vec2 x2,double a2){
{
		HX_SOURCE_PUSH("B2Jacobian_obj::set")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2Jacobian.hx",48)
		this->linearA->setV(x1);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2Jacobian.hx",48)
		this->angularA = a1;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2Jacobian.hx",49)
		this->linearB->setV(x2);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2Jacobian.hx",49)
		this->angularB = a2;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(B2Jacobian_obj,set,(void))

double B2Jacobian_obj::compute( ::box2D::common::math::B2Vec2 x1,double a1,::box2D::common::math::B2Vec2 x2,double a2){
	HX_SOURCE_PUSH("B2Jacobian_obj::compute")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2Jacobian.hx",51)
	return (((((this->linearA->x * x1->x) + (this->linearA->y * x1->y)) + (this->angularA * a1)) + (((this->linearB->x * x2->x) + (this->linearB->y * x2->y)))) + (this->angularB * a2));
}


HX_DEFINE_DYNAMIC_FUNC4(B2Jacobian_obj,compute,return )


B2Jacobian_obj::B2Jacobian_obj()
{
}

void B2Jacobian_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(B2Jacobian);
	HX_MARK_MEMBER_NAME(linearA,"linearA");
	HX_MARK_MEMBER_NAME(angularA,"angularA");
	HX_MARK_MEMBER_NAME(linearB,"linearB");
	HX_MARK_MEMBER_NAME(angularB,"angularB");
	HX_MARK_END_CLASS();
}

Dynamic B2Jacobian_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"set") ) { return set_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"linearA") ) { return linearA; }
		if (HX_FIELD_EQ(inName,"linearB") ) { return linearB; }
		if (HX_FIELD_EQ(inName,"setZero") ) { return setZero_dyn(); }
		if (HX_FIELD_EQ(inName,"compute") ) { return compute_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"angularA") ) { return angularA; }
		if (HX_FIELD_EQ(inName,"angularB") ) { return angularB; }
	}
	return super::__Field(inName);
}

Dynamic B2Jacobian_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"linearA") ) { linearA=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"linearB") ) { linearB=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"angularA") ) { angularA=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"angularB") ) { angularB=inValue.Cast< double >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void B2Jacobian_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("linearA"));
	outFields->push(HX_CSTRING("angularA"));
	outFields->push(HX_CSTRING("linearB"));
	outFields->push(HX_CSTRING("angularB"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("linearA"),
	HX_CSTRING("angularA"),
	HX_CSTRING("linearB"),
	HX_CSTRING("angularB"),
	HX_CSTRING("setZero"),
	HX_CSTRING("set"),
	HX_CSTRING("compute"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class B2Jacobian_obj::__mClass;

void B2Jacobian_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.dynamics.joints.B2Jacobian"), hx::TCanCast< B2Jacobian_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void B2Jacobian_obj::__boot()
{
}

} // end namespace box2D
} // end namespace dynamics
} // end namespace joints
