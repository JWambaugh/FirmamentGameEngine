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
#ifndef INCLUDED_box2D_dynamics_joints_B2WeldJointDef
#include <box2D/dynamics/joints/B2WeldJointDef.h>
#endif
namespace box2D{
namespace dynamics{
namespace joints{

Void B2WeldJointDef_obj::__construct()
{
{
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJointDef.hx",36)
	super::__construct();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJointDef.hx",37)
	this->localAnchorA = ::box2D::common::math::B2Vec2_obj::__new(null(),null());
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJointDef.hx",38)
	this->localAnchorB = ::box2D::common::math::B2Vec2_obj::__new(null(),null());
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJointDef.hx",40)
	this->type = ::box2D::dynamics::joints::B2Joint_obj::e_weldJoint;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJointDef.hx",41)
	this->referenceAngle = 0.0;
}
;
	return null();
}

B2WeldJointDef_obj::~B2WeldJointDef_obj() { }

Dynamic B2WeldJointDef_obj::__CreateEmpty() { return  new B2WeldJointDef_obj; }
hx::ObjectPtr< B2WeldJointDef_obj > B2WeldJointDef_obj::__new()
{  hx::ObjectPtr< B2WeldJointDef_obj > result = new B2WeldJointDef_obj();
	result->__construct();
	return result;}

Dynamic B2WeldJointDef_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2WeldJointDef_obj > result = new B2WeldJointDef_obj();
	result->__construct();
	return result;}

Void B2WeldJointDef_obj::initialize( ::box2D::dynamics::B2Body bA,::box2D::dynamics::B2Body bB,::box2D::common::math::B2Vec2 anchor){
{
		HX_SOURCE_PUSH("B2WeldJointDef_obj::initialize")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJointDef.hx",51)
		this->bodyA = bA;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJointDef.hx",52)
		this->bodyB = bB;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJointDef.hx",53)
		this->localAnchorA->setV(this->bodyA->getLocalPoint(anchor));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJointDef.hx",54)
		this->localAnchorB->setV(this->bodyB->getLocalPoint(anchor));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJointDef.hx",55)
		this->referenceAngle = (this->bodyB->getAngle() - this->bodyA->getAngle());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(B2WeldJointDef_obj,initialize,(void))


B2WeldJointDef_obj::B2WeldJointDef_obj()
{
}

void B2WeldJointDef_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(B2WeldJointDef);
	HX_MARK_MEMBER_NAME(localAnchorA,"localAnchorA");
	HX_MARK_MEMBER_NAME(localAnchorB,"localAnchorB");
	HX_MARK_MEMBER_NAME(referenceAngle,"referenceAngle");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic B2WeldJointDef_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 10:
		if (HX_FIELD_EQ(inName,"initialize") ) { return initialize_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"localAnchorA") ) { return localAnchorA; }
		if (HX_FIELD_EQ(inName,"localAnchorB") ) { return localAnchorB; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"referenceAngle") ) { return referenceAngle; }
	}
	return super::__Field(inName);
}

Dynamic B2WeldJointDef_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 12:
		if (HX_FIELD_EQ(inName,"localAnchorA") ) { localAnchorA=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"localAnchorB") ) { localAnchorB=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"referenceAngle") ) { referenceAngle=inValue.Cast< double >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void B2WeldJointDef_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("localAnchorA"));
	outFields->push(HX_CSTRING("localAnchorB"));
	outFields->push(HX_CSTRING("referenceAngle"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("initialize"),
	HX_CSTRING("localAnchorA"),
	HX_CSTRING("localAnchorB"),
	HX_CSTRING("referenceAngle"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class B2WeldJointDef_obj::__mClass;

void B2WeldJointDef_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.dynamics.joints.B2WeldJointDef"), hx::TCanCast< B2WeldJointDef_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void B2WeldJointDef_obj::__boot()
{
}

} // end namespace box2D
} // end namespace dynamics
} // end namespace joints
