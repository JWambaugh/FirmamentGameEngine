#include <hxcpp.h>

#ifndef INCLUDED_box2D_common_math_B2Vec2
#include <box2D/common/math/B2Vec2.h>
#endif
#ifndef INCLUDED_box2D_dynamics_B2Body
#include <box2D/dynamics/B2Body.h>
#endif
#ifndef INCLUDED_box2D_dynamics_joints_B2Joint
#include <box2D/dynamics/joints/B2Joint.h>
#endif
#ifndef INCLUDED_box2D_dynamics_joints_B2JointDef
#include <box2D/dynamics/joints/B2JointDef.h>
#endif
#ifndef INCLUDED_box2D_dynamics_joints_B2LineJointDef
#include <box2D/dynamics/joints/B2LineJointDef.h>
#endif
namespace box2D{
namespace dynamics{
namespace joints{

Void B2LineJointDef_obj::__construct()
{
{
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJointDef.hx",35)
	super::__construct();
}
;
	return null();
}

B2LineJointDef_obj::~B2LineJointDef_obj() { }

Dynamic B2LineJointDef_obj::__CreateEmpty() { return  new B2LineJointDef_obj; }
hx::ObjectPtr< B2LineJointDef_obj > B2LineJointDef_obj::__new()
{  hx::ObjectPtr< B2LineJointDef_obj > result = new B2LineJointDef_obj();
	result->__construct();
	return result;}

Dynamic B2LineJointDef_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2LineJointDef_obj > result = new B2LineJointDef_obj();
	result->__construct();
	return result;}

Void B2LineJointDef_obj::b2LineJointDef( ){
{
		HX_SOURCE_PUSH("B2LineJointDef_obj::b2LineJointDef")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJointDef.hx",40)
		this->localAnchorA = ::box2D::common::math::B2Vec2_obj::__new(null(),null());
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJointDef.hx",41)
		this->localAnchorB = ::box2D::common::math::B2Vec2_obj::__new(null(),null());
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJointDef.hx",42)
		this->localAxisA = ::box2D::common::math::B2Vec2_obj::__new(null(),null());
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJointDef.hx",44)
		this->type = ::box2D::dynamics::joints::B2Joint_obj::e_lineJoint;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJointDef.hx",47)
		this->localAxisA->set(1.0,0.0);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJointDef.hx",48)
		this->enableLimit = false;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJointDef.hx",49)
		this->lowerTranslation = 0.0;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJointDef.hx",50)
		this->upperTranslation = 0.0;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJointDef.hx",51)
		this->enableMotor = false;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJointDef.hx",52)
		this->maxMotorForce = 0.0;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJointDef.hx",53)
		this->motorSpeed = 0.0;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(B2LineJointDef_obj,b2LineJointDef,(void))

Void B2LineJointDef_obj::initialize( ::box2D::dynamics::B2Body bA,::box2D::dynamics::B2Body bB,::box2D::common::math::B2Vec2 anchor,::box2D::common::math::B2Vec2 axis){
{
		HX_SOURCE_PUSH("B2LineJointDef_obj::initialize")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJointDef.hx",58)
		this->bodyA = bA;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJointDef.hx",59)
		this->bodyB = bB;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJointDef.hx",60)
		this->localAnchorA = this->bodyA->getLocalPoint(anchor);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJointDef.hx",61)
		this->localAnchorB = this->bodyB->getLocalPoint(anchor);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJointDef.hx",62)
		this->localAxisA = this->bodyA->getLocalVector(axis);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(B2LineJointDef_obj,initialize,(void))


B2LineJointDef_obj::B2LineJointDef_obj()
{
}

void B2LineJointDef_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(B2LineJointDef);
	HX_MARK_MEMBER_NAME(localAnchorA,"localAnchorA");
	HX_MARK_MEMBER_NAME(localAnchorB,"localAnchorB");
	HX_MARK_MEMBER_NAME(localAxisA,"localAxisA");
	HX_MARK_MEMBER_NAME(enableLimit,"enableLimit");
	HX_MARK_MEMBER_NAME(lowerTranslation,"lowerTranslation");
	HX_MARK_MEMBER_NAME(upperTranslation,"upperTranslation");
	HX_MARK_MEMBER_NAME(enableMotor,"enableMotor");
	HX_MARK_MEMBER_NAME(maxMotorForce,"maxMotorForce");
	HX_MARK_MEMBER_NAME(motorSpeed,"motorSpeed");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic B2LineJointDef_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 10:
		if (HX_FIELD_EQ(inName,"initialize") ) { return initialize_dyn(); }
		if (HX_FIELD_EQ(inName,"localAxisA") ) { return localAxisA; }
		if (HX_FIELD_EQ(inName,"motorSpeed") ) { return motorSpeed; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"enableLimit") ) { return enableLimit; }
		if (HX_FIELD_EQ(inName,"enableMotor") ) { return enableMotor; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"localAnchorA") ) { return localAnchorA; }
		if (HX_FIELD_EQ(inName,"localAnchorB") ) { return localAnchorB; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"maxMotorForce") ) { return maxMotorForce; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"b2LineJointDef") ) { return b2LineJointDef_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"lowerTranslation") ) { return lowerTranslation; }
		if (HX_FIELD_EQ(inName,"upperTranslation") ) { return upperTranslation; }
	}
	return super::__Field(inName);
}

Dynamic B2LineJointDef_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 10:
		if (HX_FIELD_EQ(inName,"localAxisA") ) { localAxisA=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"motorSpeed") ) { motorSpeed=inValue.Cast< double >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"enableLimit") ) { enableLimit=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"enableMotor") ) { enableMotor=inValue.Cast< bool >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"localAnchorA") ) { localAnchorA=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"localAnchorB") ) { localAnchorB=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"maxMotorForce") ) { maxMotorForce=inValue.Cast< double >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"lowerTranslation") ) { lowerTranslation=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"upperTranslation") ) { upperTranslation=inValue.Cast< double >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void B2LineJointDef_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("localAnchorA"));
	outFields->push(HX_CSTRING("localAnchorB"));
	outFields->push(HX_CSTRING("localAxisA"));
	outFields->push(HX_CSTRING("enableLimit"));
	outFields->push(HX_CSTRING("lowerTranslation"));
	outFields->push(HX_CSTRING("upperTranslation"));
	outFields->push(HX_CSTRING("enableMotor"));
	outFields->push(HX_CSTRING("maxMotorForce"));
	outFields->push(HX_CSTRING("motorSpeed"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("b2LineJointDef"),
	HX_CSTRING("initialize"),
	HX_CSTRING("localAnchorA"),
	HX_CSTRING("localAnchorB"),
	HX_CSTRING("localAxisA"),
	HX_CSTRING("enableLimit"),
	HX_CSTRING("lowerTranslation"),
	HX_CSTRING("upperTranslation"),
	HX_CSTRING("enableMotor"),
	HX_CSTRING("maxMotorForce"),
	HX_CSTRING("motorSpeed"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class B2LineJointDef_obj::__mClass;

void B2LineJointDef_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.dynamics.joints.B2LineJointDef"), hx::TCanCast< B2LineJointDef_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void B2LineJointDef_obj::__boot()
{
}

} // end namespace box2D
} // end namespace dynamics
} // end namespace joints
