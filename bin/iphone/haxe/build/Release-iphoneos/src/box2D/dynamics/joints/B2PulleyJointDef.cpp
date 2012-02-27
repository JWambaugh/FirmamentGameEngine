#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
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
#ifndef INCLUDED_box2D_dynamics_joints_B2PulleyJoint
#include <box2D/dynamics/joints/B2PulleyJoint.h>
#endif
#ifndef INCLUDED_box2D_dynamics_joints_B2PulleyJointDef
#include <box2D/dynamics/joints/B2PulleyJointDef.h>
#endif
namespace box2D{
namespace dynamics{
namespace joints{

Void B2PulleyJointDef_obj::__construct()
{
{
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJointDef.hx",38)
	super::__construct();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJointDef.hx",39)
	this->groundAnchorA = ::box2D::common::math::B2Vec2_obj::__new(null(),null());
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJointDef.hx",40)
	this->groundAnchorB = ::box2D::common::math::B2Vec2_obj::__new(null(),null());
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJointDef.hx",41)
	this->localAnchorA = ::box2D::common::math::B2Vec2_obj::__new(null(),null());
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJointDef.hx",42)
	this->localAnchorB = ::box2D::common::math::B2Vec2_obj::__new(null(),null());
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJointDef.hx",44)
	this->type = ::box2D::dynamics::joints::B2Joint_obj::e_pulleyJoint;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJointDef.hx",45)
	this->groundAnchorA->set(-1.0,1.0);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJointDef.hx",46)
	this->groundAnchorB->set(1.0,1.0);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJointDef.hx",47)
	this->localAnchorA->set(-1.0,0.0);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJointDef.hx",48)
	this->localAnchorB->set(1.0,0.0);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJointDef.hx",49)
	this->lengthA = 0.0;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJointDef.hx",50)
	this->maxLengthA = 0.0;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJointDef.hx",51)
	this->lengthB = 0.0;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJointDef.hx",52)
	this->maxLengthB = 0.0;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJointDef.hx",53)
	this->ratio = 1.0;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJointDef.hx",54)
	this->collideConnected = true;
}
;
	return null();
}

B2PulleyJointDef_obj::~B2PulleyJointDef_obj() { }

Dynamic B2PulleyJointDef_obj::__CreateEmpty() { return  new B2PulleyJointDef_obj; }
hx::ObjectPtr< B2PulleyJointDef_obj > B2PulleyJointDef_obj::__new()
{  hx::ObjectPtr< B2PulleyJointDef_obj > result = new B2PulleyJointDef_obj();
	result->__construct();
	return result;}

Dynamic B2PulleyJointDef_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2PulleyJointDef_obj > result = new B2PulleyJointDef_obj();
	result->__construct();
	return result;}

Void B2PulleyJointDef_obj::initialize( ::box2D::dynamics::B2Body bA,::box2D::dynamics::B2Body bB,::box2D::common::math::B2Vec2 gaA,::box2D::common::math::B2Vec2 gaB,::box2D::common::math::B2Vec2 anchorA,::box2D::common::math::B2Vec2 anchorB,double r){
{
		HX_SOURCE_PUSH("B2PulleyJointDef_obj::initialize")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJointDef.hx",62)
		this->bodyA = bA;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJointDef.hx",63)
		this->bodyB = bB;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJointDef.hx",64)
		this->groundAnchorA->setV(gaA);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJointDef.hx",65)
		this->groundAnchorB->setV(gaB);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJointDef.hx",66)
		this->localAnchorA = this->bodyA->getLocalPoint(anchorA);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJointDef.hx",67)
		this->localAnchorB = this->bodyB->getLocalPoint(anchorB);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJointDef.hx",69)
		double d1X = (anchorA->x - gaA->x);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJointDef.hx",70)
		double d1Y = (anchorA->y - gaA->y);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJointDef.hx",72)
		this->lengthA = ::Math_obj::sqrt(((d1X * d1X) + (d1Y * d1Y)));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJointDef.hx",75)
		double d2X = (anchorB->x - gaB->x);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJointDef.hx",76)
		double d2Y = (anchorB->y - gaB->y);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJointDef.hx",78)
		this->lengthB = ::Math_obj::sqrt(((d2X * d2X) + (d2Y * d2Y)));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJointDef.hx",80)
		this->ratio = r;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJointDef.hx",82)
		double C = (this->lengthA + (this->ratio * this->lengthB));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJointDef.hx",83)
		this->maxLengthA = (C - (this->ratio * ::box2D::dynamics::joints::B2PulleyJoint_obj::b2_minPulleyLength));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJointDef.hx",84)
		this->maxLengthB = (double(((C - ::box2D::dynamics::joints::B2PulleyJoint_obj::b2_minPulleyLength))) / double(this->ratio));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC7(B2PulleyJointDef_obj,initialize,(void))


B2PulleyJointDef_obj::B2PulleyJointDef_obj()
{
}

void B2PulleyJointDef_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(B2PulleyJointDef);
	HX_MARK_MEMBER_NAME(groundAnchorA,"groundAnchorA");
	HX_MARK_MEMBER_NAME(groundAnchorB,"groundAnchorB");
	HX_MARK_MEMBER_NAME(localAnchorA,"localAnchorA");
	HX_MARK_MEMBER_NAME(localAnchorB,"localAnchorB");
	HX_MARK_MEMBER_NAME(lengthA,"lengthA");
	HX_MARK_MEMBER_NAME(maxLengthA,"maxLengthA");
	HX_MARK_MEMBER_NAME(lengthB,"lengthB");
	HX_MARK_MEMBER_NAME(maxLengthB,"maxLengthB");
	HX_MARK_MEMBER_NAME(ratio,"ratio");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic B2PulleyJointDef_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"ratio") ) { return ratio; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"lengthA") ) { return lengthA; }
		if (HX_FIELD_EQ(inName,"lengthB") ) { return lengthB; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"initialize") ) { return initialize_dyn(); }
		if (HX_FIELD_EQ(inName,"maxLengthA") ) { return maxLengthA; }
		if (HX_FIELD_EQ(inName,"maxLengthB") ) { return maxLengthB; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"localAnchorA") ) { return localAnchorA; }
		if (HX_FIELD_EQ(inName,"localAnchorB") ) { return localAnchorB; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"groundAnchorA") ) { return groundAnchorA; }
		if (HX_FIELD_EQ(inName,"groundAnchorB") ) { return groundAnchorB; }
	}
	return super::__Field(inName);
}

Dynamic B2PulleyJointDef_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"ratio") ) { ratio=inValue.Cast< double >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"lengthA") ) { lengthA=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lengthB") ) { lengthB=inValue.Cast< double >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"maxLengthA") ) { maxLengthA=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"maxLengthB") ) { maxLengthB=inValue.Cast< double >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"localAnchorA") ) { localAnchorA=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"localAnchorB") ) { localAnchorB=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"groundAnchorA") ) { groundAnchorA=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"groundAnchorB") ) { groundAnchorB=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void B2PulleyJointDef_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("groundAnchorA"));
	outFields->push(HX_CSTRING("groundAnchorB"));
	outFields->push(HX_CSTRING("localAnchorA"));
	outFields->push(HX_CSTRING("localAnchorB"));
	outFields->push(HX_CSTRING("lengthA"));
	outFields->push(HX_CSTRING("maxLengthA"));
	outFields->push(HX_CSTRING("lengthB"));
	outFields->push(HX_CSTRING("maxLengthB"));
	outFields->push(HX_CSTRING("ratio"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("initialize"),
	HX_CSTRING("groundAnchorA"),
	HX_CSTRING("groundAnchorB"),
	HX_CSTRING("localAnchorA"),
	HX_CSTRING("localAnchorB"),
	HX_CSTRING("lengthA"),
	HX_CSTRING("maxLengthA"),
	HX_CSTRING("lengthB"),
	HX_CSTRING("maxLengthB"),
	HX_CSTRING("ratio"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class B2PulleyJointDef_obj::__mClass;

void B2PulleyJointDef_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.dynamics.joints.B2PulleyJointDef"), hx::TCanCast< B2PulleyJointDef_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void B2PulleyJointDef_obj::__boot()
{
}

} // end namespace box2D
} // end namespace dynamics
} // end namespace joints
