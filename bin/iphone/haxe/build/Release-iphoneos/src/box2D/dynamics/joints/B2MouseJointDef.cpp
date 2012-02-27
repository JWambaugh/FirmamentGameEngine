#include <hxcpp.h>

#ifndef INCLUDED_box2D_common_math_B2Vec2
#include <box2D/common/math/B2Vec2.h>
#endif
#ifndef INCLUDED_box2D_dynamics_joints_B2Joint
#include <box2D/dynamics/joints/B2Joint.h>
#endif
#ifndef INCLUDED_box2D_dynamics_joints_B2JointDef
#include <box2D/dynamics/joints/B2JointDef.h>
#endif
#ifndef INCLUDED_box2D_dynamics_joints_B2MouseJointDef
#include <box2D/dynamics/joints/B2MouseJointDef.h>
#endif
namespace box2D{
namespace dynamics{
namespace joints{

Void B2MouseJointDef_obj::__construct()
{
{
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2MouseJointDef.hx",34)
	super::__construct();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2MouseJointDef.hx",35)
	this->target = ::box2D::common::math::B2Vec2_obj::__new(null(),null());
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2MouseJointDef.hx",37)
	this->type = ::box2D::dynamics::joints::B2Joint_obj::e_mouseJoint;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2MouseJointDef.hx",38)
	this->maxForce = 0.0;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2MouseJointDef.hx",39)
	this->frequencyHz = 5.0;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2MouseJointDef.hx",40)
	this->dampingRatio = 0.7;
}
;
	return null();
}

B2MouseJointDef_obj::~B2MouseJointDef_obj() { }

Dynamic B2MouseJointDef_obj::__CreateEmpty() { return  new B2MouseJointDef_obj; }
hx::ObjectPtr< B2MouseJointDef_obj > B2MouseJointDef_obj::__new()
{  hx::ObjectPtr< B2MouseJointDef_obj > result = new B2MouseJointDef_obj();
	result->__construct();
	return result;}

Dynamic B2MouseJointDef_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2MouseJointDef_obj > result = new B2MouseJointDef_obj();
	result->__construct();
	return result;}


B2MouseJointDef_obj::B2MouseJointDef_obj()
{
}

void B2MouseJointDef_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(B2MouseJointDef);
	HX_MARK_MEMBER_NAME(target,"target");
	HX_MARK_MEMBER_NAME(maxForce,"maxForce");
	HX_MARK_MEMBER_NAME(frequencyHz,"frequencyHz");
	HX_MARK_MEMBER_NAME(dampingRatio,"dampingRatio");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic B2MouseJointDef_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"target") ) { return target; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"maxForce") ) { return maxForce; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"frequencyHz") ) { return frequencyHz; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"dampingRatio") ) { return dampingRatio; }
	}
	return super::__Field(inName);
}

Dynamic B2MouseJointDef_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"target") ) { target=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"maxForce") ) { maxForce=inValue.Cast< double >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"frequencyHz") ) { frequencyHz=inValue.Cast< double >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"dampingRatio") ) { dampingRatio=inValue.Cast< double >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void B2MouseJointDef_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("target"));
	outFields->push(HX_CSTRING("maxForce"));
	outFields->push(HX_CSTRING("frequencyHz"));
	outFields->push(HX_CSTRING("dampingRatio"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("target"),
	HX_CSTRING("maxForce"),
	HX_CSTRING("frequencyHz"),
	HX_CSTRING("dampingRatio"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class B2MouseJointDef_obj::__mClass;

void B2MouseJointDef_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.dynamics.joints.B2MouseJointDef"), hx::TCanCast< B2MouseJointDef_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void B2MouseJointDef_obj::__boot()
{
}

} // end namespace box2D
} // end namespace dynamics
} // end namespace joints
