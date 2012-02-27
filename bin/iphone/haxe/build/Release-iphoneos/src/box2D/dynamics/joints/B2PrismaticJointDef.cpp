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
#ifndef INCLUDED_box2D_dynamics_joints_B2PrismaticJointDef
#include <box2D/dynamics/joints/B2PrismaticJointDef.h>
#endif
namespace box2D{
namespace dynamics{
namespace joints{

Void B2PrismaticJointDef_obj::__construct()
{
{
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJointDef.hx",39)
	super::__construct();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJointDef.hx",40)
	this->localAnchorA = ::box2D::common::math::B2Vec2_obj::__new(null(),null());
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJointDef.hx",41)
	this->localAnchorB = ::box2D::common::math::B2Vec2_obj::__new(null(),null());
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJointDef.hx",42)
	this->localAxisA = ::box2D::common::math::B2Vec2_obj::__new(null(),null());
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJointDef.hx",44)
	this->type = ::box2D::dynamics::joints::B2Joint_obj::e_prismaticJoint;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJointDef.hx",47)
	this->localAxisA->set(1.0,0.0);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJointDef.hx",48)
	this->referenceAngle = 0.0;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJointDef.hx",49)
	this->enableLimit = false;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJointDef.hx",50)
	this->lowerTranslation = 0.0;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJointDef.hx",51)
	this->upperTranslation = 0.0;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJointDef.hx",52)
	this->enableMotor = false;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJointDef.hx",53)
	this->maxMotorForce = 0.0;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJointDef.hx",54)
	this->motorSpeed = 0.0;
}
;
	return null();
}

B2PrismaticJointDef_obj::~B2PrismaticJointDef_obj() { }

Dynamic B2PrismaticJointDef_obj::__CreateEmpty() { return  new B2PrismaticJointDef_obj; }
hx::ObjectPtr< B2PrismaticJointDef_obj > B2PrismaticJointDef_obj::__new()
{  hx::ObjectPtr< B2PrismaticJointDef_obj > result = new B2PrismaticJointDef_obj();
	result->__construct();
	return result;}

Dynamic B2PrismaticJointDef_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2PrismaticJointDef_obj > result = new B2PrismaticJointDef_obj();
	result->__construct();
	return result;}

Void B2PrismaticJointDef_obj::initialize( ::box2D::dynamics::B2Body bA,::box2D::dynamics::B2Body bB,::box2D::common::math::B2Vec2 anchor,::box2D::common::math::B2Vec2 axis){
{
		HX_SOURCE_PUSH("B2PrismaticJointDef_obj::initialize")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJointDef.hx",59)
		this->bodyA = bA;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJointDef.hx",60)
		this->bodyB = bB;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJointDef.hx",61)
		this->localAnchorA = this->bodyA->getLocalPoint(anchor);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJointDef.hx",62)
		this->localAnchorB = this->bodyB->getLocalPoint(anchor);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJointDef.hx",63)
		this->localAxisA = this->bodyA->getLocalVector(axis);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJointDef.hx",64)
		this->referenceAngle = (this->bodyB->getAngle() - this->bodyA->getAngle());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(B2PrismaticJointDef_obj,initialize,(void))


B2PrismaticJointDef_obj::B2PrismaticJointDef_obj()
{
}

void B2PrismaticJointDef_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(B2PrismaticJointDef);
	HX_MARK_MEMBER_NAME(localAnchorA,"localAnchorA");
	HX_MARK_MEMBER_NAME(localAnchorB,"localAnchorB");
	HX_MARK_MEMBER_NAME(localAxisA,"localAxisA");
	HX_MARK_MEMBER_NAME(referenceAngle,"referenceAngle");
	HX_MARK_MEMBER_NAME(enableLimit,"enableLimit");
	HX_MARK_MEMBER_NAME(lowerTranslation,"lowerTranslation");
	HX_MARK_MEMBER_NAME(upperTranslation,"upperTranslation");
	HX_MARK_MEMBER_NAME(enableMotor,"enableMotor");
	HX_MARK_MEMBER_NAME(maxMotorForce,"maxMotorForce");
	HX_MARK_MEMBER_NAME(motorSpeed,"motorSpeed");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic B2PrismaticJointDef_obj::__Field(const ::String &inName)
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
		if (HX_FIELD_EQ(inName,"referenceAngle") ) { return referenceAngle; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"lowerTranslation") ) { return lowerTranslation; }
		if (HX_FIELD_EQ(inName,"upperTranslation") ) { return upperTranslation; }
	}
	return super::__Field(inName);
}

Dynamic B2PrismaticJointDef_obj::__SetField(const ::String &inName,const Dynamic &inValue)
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
	case 14:
		if (HX_FIELD_EQ(inName,"referenceAngle") ) { referenceAngle=inValue.Cast< double >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"lowerTranslation") ) { lowerTranslation=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"upperTranslation") ) { upperTranslation=inValue.Cast< double >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void B2PrismaticJointDef_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("localAnchorA"));
	outFields->push(HX_CSTRING("localAnchorB"));
	outFields->push(HX_CSTRING("localAxisA"));
	outFields->push(HX_CSTRING("referenceAngle"));
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
	HX_CSTRING("initialize"),
	HX_CSTRING("localAnchorA"),
	HX_CSTRING("localAnchorB"),
	HX_CSTRING("localAxisA"),
	HX_CSTRING("referenceAngle"),
	HX_CSTRING("enableLimit"),
	HX_CSTRING("lowerTranslation"),
	HX_CSTRING("upperTranslation"),
	HX_CSTRING("enableMotor"),
	HX_CSTRING("maxMotorForce"),
	HX_CSTRING("motorSpeed"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class B2PrismaticJointDef_obj::__mClass;

void B2PrismaticJointDef_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.dynamics.joints.B2PrismaticJointDef"), hx::TCanCast< B2PrismaticJointDef_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void B2PrismaticJointDef_obj::__boot()
{
}

} // end namespace box2D
} // end namespace dynamics
} // end namespace joints
