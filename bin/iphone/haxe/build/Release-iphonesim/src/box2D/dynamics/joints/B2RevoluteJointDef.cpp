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
#ifndef INCLUDED_box2D_dynamics_joints_B2RevoluteJointDef
#include <box2D/dynamics/joints/B2RevoluteJointDef.h>
#endif
namespace box2D{
namespace dynamics{
namespace joints{

Void B2RevoluteJointDef_obj::__construct()
{
{
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJointDef.hx",45)
	super::__construct();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJointDef.hx",46)
	this->localAnchorA = ::box2D::common::math::B2Vec2_obj::__new(null(),null());
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJointDef.hx",47)
	this->localAnchorB = ::box2D::common::math::B2Vec2_obj::__new(null(),null());
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJointDef.hx",49)
	this->type = ::box2D::dynamics::joints::B2Joint_obj::e_revoluteJoint;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJointDef.hx",50)
	this->localAnchorA->set(0.0,0.0);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJointDef.hx",51)
	this->localAnchorB->set(0.0,0.0);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJointDef.hx",52)
	this->referenceAngle = 0.0;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJointDef.hx",53)
	this->lowerAngle = 0.0;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJointDef.hx",54)
	this->upperAngle = 0.0;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJointDef.hx",55)
	this->maxMotorTorque = 0.0;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJointDef.hx",56)
	this->motorSpeed = 0.0;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJointDef.hx",57)
	this->enableLimit = false;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJointDef.hx",58)
	this->enableMotor = false;
}
;
	return null();
}

B2RevoluteJointDef_obj::~B2RevoluteJointDef_obj() { }

Dynamic B2RevoluteJointDef_obj::__CreateEmpty() { return  new B2RevoluteJointDef_obj; }
hx::ObjectPtr< B2RevoluteJointDef_obj > B2RevoluteJointDef_obj::__new()
{  hx::ObjectPtr< B2RevoluteJointDef_obj > result = new B2RevoluteJointDef_obj();
	result->__construct();
	return result;}

Dynamic B2RevoluteJointDef_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2RevoluteJointDef_obj > result = new B2RevoluteJointDef_obj();
	result->__construct();
	return result;}

Void B2RevoluteJointDef_obj::initialize( ::box2D::dynamics::B2Body bA,::box2D::dynamics::B2Body bB,::box2D::common::math::B2Vec2 anchor){
{
		HX_SOURCE_PUSH("B2RevoluteJointDef_obj::initialize")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJointDef.hx",66)
		this->bodyA = bA;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJointDef.hx",67)
		this->bodyB = bB;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJointDef.hx",68)
		this->localAnchorA = this->bodyA->getLocalPoint(anchor);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJointDef.hx",69)
		this->localAnchorB = this->bodyB->getLocalPoint(anchor);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJointDef.hx",70)
		this->referenceAngle = (this->bodyB->getAngle() - this->bodyA->getAngle());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(B2RevoluteJointDef_obj,initialize,(void))


B2RevoluteJointDef_obj::B2RevoluteJointDef_obj()
{
}

void B2RevoluteJointDef_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(B2RevoluteJointDef);
	HX_MARK_MEMBER_NAME(localAnchorA,"localAnchorA");
	HX_MARK_MEMBER_NAME(localAnchorB,"localAnchorB");
	HX_MARK_MEMBER_NAME(referenceAngle,"referenceAngle");
	HX_MARK_MEMBER_NAME(enableLimit,"enableLimit");
	HX_MARK_MEMBER_NAME(lowerAngle,"lowerAngle");
	HX_MARK_MEMBER_NAME(upperAngle,"upperAngle");
	HX_MARK_MEMBER_NAME(enableMotor,"enableMotor");
	HX_MARK_MEMBER_NAME(motorSpeed,"motorSpeed");
	HX_MARK_MEMBER_NAME(maxMotorTorque,"maxMotorTorque");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic B2RevoluteJointDef_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 10:
		if (HX_FIELD_EQ(inName,"initialize") ) { return initialize_dyn(); }
		if (HX_FIELD_EQ(inName,"lowerAngle") ) { return lowerAngle; }
		if (HX_FIELD_EQ(inName,"upperAngle") ) { return upperAngle; }
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
	case 14:
		if (HX_FIELD_EQ(inName,"referenceAngle") ) { return referenceAngle; }
		if (HX_FIELD_EQ(inName,"maxMotorTorque") ) { return maxMotorTorque; }
	}
	return super::__Field(inName);
}

Dynamic B2RevoluteJointDef_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 10:
		if (HX_FIELD_EQ(inName,"lowerAngle") ) { lowerAngle=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"upperAngle") ) { upperAngle=inValue.Cast< double >(); return inValue; }
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
	case 14:
		if (HX_FIELD_EQ(inName,"referenceAngle") ) { referenceAngle=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"maxMotorTorque") ) { maxMotorTorque=inValue.Cast< double >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void B2RevoluteJointDef_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("localAnchorA"));
	outFields->push(HX_CSTRING("localAnchorB"));
	outFields->push(HX_CSTRING("referenceAngle"));
	outFields->push(HX_CSTRING("enableLimit"));
	outFields->push(HX_CSTRING("lowerAngle"));
	outFields->push(HX_CSTRING("upperAngle"));
	outFields->push(HX_CSTRING("enableMotor"));
	outFields->push(HX_CSTRING("motorSpeed"));
	outFields->push(HX_CSTRING("maxMotorTorque"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("initialize"),
	HX_CSTRING("localAnchorA"),
	HX_CSTRING("localAnchorB"),
	HX_CSTRING("referenceAngle"),
	HX_CSTRING("enableLimit"),
	HX_CSTRING("lowerAngle"),
	HX_CSTRING("upperAngle"),
	HX_CSTRING("enableMotor"),
	HX_CSTRING("motorSpeed"),
	HX_CSTRING("maxMotorTorque"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class B2RevoluteJointDef_obj::__mClass;

void B2RevoluteJointDef_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.dynamics.joints.B2RevoluteJointDef"), hx::TCanCast< B2RevoluteJointDef_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void B2RevoluteJointDef_obj::__boot()
{
}

} // end namespace box2D
} // end namespace dynamics
} // end namespace joints
