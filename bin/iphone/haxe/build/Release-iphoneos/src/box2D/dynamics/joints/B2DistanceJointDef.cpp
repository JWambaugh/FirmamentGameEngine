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
#ifndef INCLUDED_box2D_dynamics_joints_B2DistanceJointDef
#include <box2D/dynamics/joints/B2DistanceJointDef.h>
#endif
#ifndef INCLUDED_box2D_dynamics_joints_B2Joint
#include <box2D/dynamics/joints/B2Joint.h>
#endif
#ifndef INCLUDED_box2D_dynamics_joints_B2JointDef
#include <box2D/dynamics/joints/B2JointDef.h>
#endif
namespace box2D{
namespace dynamics{
namespace joints{

Void B2DistanceJointDef_obj::__construct()
{
{
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJointDef.hx",39)
	super::__construct();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJointDef.hx",40)
	this->localAnchorA = ::box2D::common::math::B2Vec2_obj::__new(null(),null());
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJointDef.hx",41)
	this->localAnchorB = ::box2D::common::math::B2Vec2_obj::__new(null(),null());
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJointDef.hx",43)
	this->type = ::box2D::dynamics::joints::B2Joint_obj::e_distanceJoint;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJointDef.hx",46)
	this->length = 1.0;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJointDef.hx",47)
	this->frequencyHz = 0.0;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJointDef.hx",48)
	this->dampingRatio = 0.0;
}
;
	return null();
}

B2DistanceJointDef_obj::~B2DistanceJointDef_obj() { }

Dynamic B2DistanceJointDef_obj::__CreateEmpty() { return  new B2DistanceJointDef_obj; }
hx::ObjectPtr< B2DistanceJointDef_obj > B2DistanceJointDef_obj::__new()
{  hx::ObjectPtr< B2DistanceJointDef_obj > result = new B2DistanceJointDef_obj();
	result->__construct();
	return result;}

Dynamic B2DistanceJointDef_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2DistanceJointDef_obj > result = new B2DistanceJointDef_obj();
	result->__construct();
	return result;}

Void B2DistanceJointDef_obj::initialize( ::box2D::dynamics::B2Body bA,::box2D::dynamics::B2Body bB,::box2D::common::math::B2Vec2 anchorA,::box2D::common::math::B2Vec2 anchorB){
{
		HX_SOURCE_PUSH("B2DistanceJointDef_obj::initialize")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJointDef.hx",58)
		this->bodyA = bA;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJointDef.hx",59)
		this->bodyB = bB;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJointDef.hx",60)
		this->localAnchorA->setV(this->bodyA->getLocalPoint(anchorA));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJointDef.hx",61)
		this->localAnchorB->setV(this->bodyB->getLocalPoint(anchorB));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJointDef.hx",62)
		double dX = (anchorB->x - anchorA->x);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJointDef.hx",63)
		double dY = (anchorB->y - anchorA->y);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJointDef.hx",64)
		this->length = ::Math_obj::sqrt(((dX * dX) + (dY * dY)));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJointDef.hx",65)
		this->frequencyHz = 0.0;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJointDef.hx",66)
		this->dampingRatio = 0.0;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(B2DistanceJointDef_obj,initialize,(void))


B2DistanceJointDef_obj::B2DistanceJointDef_obj()
{
}

void B2DistanceJointDef_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(B2DistanceJointDef);
	HX_MARK_MEMBER_NAME(localAnchorA,"localAnchorA");
	HX_MARK_MEMBER_NAME(localAnchorB,"localAnchorB");
	HX_MARK_MEMBER_NAME(length,"length");
	HX_MARK_MEMBER_NAME(frequencyHz,"frequencyHz");
	HX_MARK_MEMBER_NAME(dampingRatio,"dampingRatio");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic B2DistanceJointDef_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"length") ) { return length; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"initialize") ) { return initialize_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"frequencyHz") ) { return frequencyHz; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"localAnchorA") ) { return localAnchorA; }
		if (HX_FIELD_EQ(inName,"localAnchorB") ) { return localAnchorB; }
		if (HX_FIELD_EQ(inName,"dampingRatio") ) { return dampingRatio; }
	}
	return super::__Field(inName);
}

Dynamic B2DistanceJointDef_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"length") ) { length=inValue.Cast< double >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"frequencyHz") ) { frequencyHz=inValue.Cast< double >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"localAnchorA") ) { localAnchorA=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"localAnchorB") ) { localAnchorB=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"dampingRatio") ) { dampingRatio=inValue.Cast< double >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void B2DistanceJointDef_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("localAnchorA"));
	outFields->push(HX_CSTRING("localAnchorB"));
	outFields->push(HX_CSTRING("length"));
	outFields->push(HX_CSTRING("frequencyHz"));
	outFields->push(HX_CSTRING("dampingRatio"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("initialize"),
	HX_CSTRING("localAnchorA"),
	HX_CSTRING("localAnchorB"),
	HX_CSTRING("length"),
	HX_CSTRING("frequencyHz"),
	HX_CSTRING("dampingRatio"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class B2DistanceJointDef_obj::__mClass;

void B2DistanceJointDef_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.dynamics.joints.B2DistanceJointDef"), hx::TCanCast< B2DistanceJointDef_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void B2DistanceJointDef_obj::__boot()
{
}

} // end namespace box2D
} // end namespace dynamics
} // end namespace joints
