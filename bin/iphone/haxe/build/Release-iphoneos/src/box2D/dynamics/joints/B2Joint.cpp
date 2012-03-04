#include <hxcpp.h>

#ifndef INCLUDED_box2D_common_B2Settings
#include <box2D/common/B2Settings.h>
#endif
#ifndef INCLUDED_box2D_common_math_B2Vec2
#include <box2D/common/math/B2Vec2.h>
#endif
#ifndef INCLUDED_box2D_dynamics_B2Body
#include <box2D/dynamics/B2Body.h>
#endif
#ifndef INCLUDED_box2D_dynamics_B2TimeStep
#include <box2D/dynamics/B2TimeStep.h>
#endif
#ifndef INCLUDED_box2D_dynamics_joints_B2DistanceJoint
#include <box2D/dynamics/joints/B2DistanceJoint.h>
#endif
#ifndef INCLUDED_box2D_dynamics_joints_B2DistanceJointDef
#include <box2D/dynamics/joints/B2DistanceJointDef.h>
#endif
#ifndef INCLUDED_box2D_dynamics_joints_B2FrictionJoint
#include <box2D/dynamics/joints/B2FrictionJoint.h>
#endif
#ifndef INCLUDED_box2D_dynamics_joints_B2FrictionJointDef
#include <box2D/dynamics/joints/B2FrictionJointDef.h>
#endif
#ifndef INCLUDED_box2D_dynamics_joints_B2GearJoint
#include <box2D/dynamics/joints/B2GearJoint.h>
#endif
#ifndef INCLUDED_box2D_dynamics_joints_B2GearJointDef
#include <box2D/dynamics/joints/B2GearJointDef.h>
#endif
#ifndef INCLUDED_box2D_dynamics_joints_B2Joint
#include <box2D/dynamics/joints/B2Joint.h>
#endif
#ifndef INCLUDED_box2D_dynamics_joints_B2JointDef
#include <box2D/dynamics/joints/B2JointDef.h>
#endif
#ifndef INCLUDED_box2D_dynamics_joints_B2JointEdge
#include <box2D/dynamics/joints/B2JointEdge.h>
#endif
#ifndef INCLUDED_box2D_dynamics_joints_B2LineJoint
#include <box2D/dynamics/joints/B2LineJoint.h>
#endif
#ifndef INCLUDED_box2D_dynamics_joints_B2LineJointDef
#include <box2D/dynamics/joints/B2LineJointDef.h>
#endif
#ifndef INCLUDED_box2D_dynamics_joints_B2MouseJoint
#include <box2D/dynamics/joints/B2MouseJoint.h>
#endif
#ifndef INCLUDED_box2D_dynamics_joints_B2MouseJointDef
#include <box2D/dynamics/joints/B2MouseJointDef.h>
#endif
#ifndef INCLUDED_box2D_dynamics_joints_B2PrismaticJoint
#include <box2D/dynamics/joints/B2PrismaticJoint.h>
#endif
#ifndef INCLUDED_box2D_dynamics_joints_B2PrismaticJointDef
#include <box2D/dynamics/joints/B2PrismaticJointDef.h>
#endif
#ifndef INCLUDED_box2D_dynamics_joints_B2PulleyJoint
#include <box2D/dynamics/joints/B2PulleyJoint.h>
#endif
#ifndef INCLUDED_box2D_dynamics_joints_B2PulleyJointDef
#include <box2D/dynamics/joints/B2PulleyJointDef.h>
#endif
#ifndef INCLUDED_box2D_dynamics_joints_B2RevoluteJoint
#include <box2D/dynamics/joints/B2RevoluteJoint.h>
#endif
#ifndef INCLUDED_box2D_dynamics_joints_B2RevoluteJointDef
#include <box2D/dynamics/joints/B2RevoluteJointDef.h>
#endif
#ifndef INCLUDED_box2D_dynamics_joints_B2WeldJoint
#include <box2D/dynamics/joints/B2WeldJoint.h>
#endif
#ifndef INCLUDED_box2D_dynamics_joints_B2WeldJointDef
#include <box2D/dynamics/joints/B2WeldJointDef.h>
#endif
namespace box2D{
namespace dynamics{
namespace joints{

Void B2Joint_obj::__construct(::box2D::dynamics::joints::B2JointDef def)
{
{
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2Joint.hx",222)
	this->m_edgeA = ::box2D::dynamics::joints::B2JointEdge_obj::__new();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2Joint.hx",223)
	this->m_edgeB = ::box2D::dynamics::joints::B2JointEdge_obj::__new();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2Joint.hx",224)
	this->m_localCenterA = ::box2D::common::math::B2Vec2_obj::__new(null(),null());
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2Joint.hx",225)
	this->m_localCenterB = ::box2D::common::math::B2Vec2_obj::__new(null(),null());
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2Joint.hx",227)
	::box2D::common::B2Settings_obj::b2Assert((def->bodyA != def->bodyB));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2Joint.hx",228)
	this->m_type = def->type;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2Joint.hx",229)
	this->m_prev = null();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2Joint.hx",230)
	this->m_next = null();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2Joint.hx",231)
	this->m_bodyA = def->bodyA;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2Joint.hx",232)
	this->m_bodyB = def->bodyB;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2Joint.hx",233)
	this->m_collideConnected = def->collideConnected;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2Joint.hx",234)
	this->m_islandFlag = false;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2Joint.hx",235)
	this->m_userData = def->userData;
}
;
	return null();
}

B2Joint_obj::~B2Joint_obj() { }

Dynamic B2Joint_obj::__CreateEmpty() { return  new B2Joint_obj; }
hx::ObjectPtr< B2Joint_obj > B2Joint_obj::__new(::box2D::dynamics::joints::B2JointDef def)
{  hx::ObjectPtr< B2Joint_obj > result = new B2Joint_obj();
	result->__construct(def);
	return result;}

Dynamic B2Joint_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2Joint_obj > result = new B2Joint_obj();
	result->__construct(inArgs[0]);
	return result;}

int B2Joint_obj::getType( ){
	HX_SOURCE_PUSH("B2Joint_obj::getType")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2Joint.hx",38)
	return this->m_type;
}


HX_DEFINE_DYNAMIC_FUNC0(B2Joint_obj,getType,return )

::box2D::common::math::B2Vec2 B2Joint_obj::getAnchorA( ){
	HX_SOURCE_PUSH("B2Joint_obj::getAnchorA")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2Joint.hx",45)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(B2Joint_obj,getAnchorA,return )

::box2D::common::math::B2Vec2 B2Joint_obj::getAnchorB( ){
	HX_SOURCE_PUSH("B2Joint_obj::getAnchorB")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2Joint.hx",49)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(B2Joint_obj,getAnchorB,return )

::box2D::common::math::B2Vec2 B2Joint_obj::getReactionForce( double inv_dt){
	HX_SOURCE_PUSH("B2Joint_obj::getReactionForce")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2Joint.hx",54)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2Joint_obj,getReactionForce,return )

double B2Joint_obj::getReactionTorque( double inv_dt){
	HX_SOURCE_PUSH("B2Joint_obj::getReactionTorque")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2Joint.hx",58)
	return 0.0;
}


HX_DEFINE_DYNAMIC_FUNC1(B2Joint_obj,getReactionTorque,return )

::box2D::dynamics::B2Body B2Joint_obj::getBodyA( ){
	HX_SOURCE_PUSH("B2Joint_obj::getBodyA")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2Joint.hx",64)
	return this->m_bodyA;
}


HX_DEFINE_DYNAMIC_FUNC0(B2Joint_obj,getBodyA,return )

::box2D::dynamics::B2Body B2Joint_obj::getBodyB( ){
	HX_SOURCE_PUSH("B2Joint_obj::getBodyB")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2Joint.hx",72)
	return this->m_bodyB;
}


HX_DEFINE_DYNAMIC_FUNC0(B2Joint_obj,getBodyB,return )

::box2D::dynamics::joints::B2Joint B2Joint_obj::getNext( ){
	HX_SOURCE_PUSH("B2Joint_obj::getNext")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2Joint.hx",79)
	return this->m_next;
}


HX_DEFINE_DYNAMIC_FUNC0(B2Joint_obj,getNext,return )

Dynamic B2Joint_obj::getUserData( ){
	HX_SOURCE_PUSH("B2Joint_obj::getUserData")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2Joint.hx",86)
	return this->m_userData;
}


HX_DEFINE_DYNAMIC_FUNC0(B2Joint_obj,getUserData,return )

Void B2Joint_obj::setUserData( Dynamic data){
{
		HX_SOURCE_PUSH("B2Joint_obj::setUserData")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2Joint.hx",93)
		this->m_userData = data;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2Joint_obj,setUserData,(void))

bool B2Joint_obj::isActive( ){
	HX_SOURCE_PUSH("B2Joint_obj::isActive")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2Joint.hx",101)
	return (bool(this->m_bodyA->isActive()) && bool(this->m_bodyB->isActive()));
}


HX_DEFINE_DYNAMIC_FUNC0(B2Joint_obj,isActive,return )

Void B2Joint_obj::initVelocityConstraints( ::box2D::dynamics::B2TimeStep step){
{
		HX_SOURCE_PUSH("B2Joint_obj::initVelocityConstraints")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2Joint_obj,initVelocityConstraints,(void))

Void B2Joint_obj::solveVelocityConstraints( ::box2D::dynamics::B2TimeStep step){
{
		HX_SOURCE_PUSH("B2Joint_obj::solveVelocityConstraints")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2Joint_obj,solveVelocityConstraints,(void))

Void B2Joint_obj::finalizeVelocityConstraints( ){
{
		HX_SOURCE_PUSH("B2Joint_obj::finalizeVelocityConstraints")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(B2Joint_obj,finalizeVelocityConstraints,(void))

bool B2Joint_obj::solvePositionConstraints( double baumgarte){
	HX_SOURCE_PUSH("B2Joint_obj::solvePositionConstraints")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2Joint.hx",244)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC1(B2Joint_obj,solvePositionConstraints,return )

::box2D::dynamics::joints::B2Joint B2Joint_obj::create( ::box2D::dynamics::joints::B2JointDef def,Dynamic allocator){
	HX_SOURCE_PUSH("B2Joint_obj::create")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2Joint.hx",108)
	::box2D::dynamics::joints::B2Joint joint = null();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2Joint.hx",110)
	int _switch_1 = (def->type);
	if (  ( _switch_1==::box2D::dynamics::joints::B2Joint_obj::e_distanceJoint)){
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2Joint.hx",112)
		joint = ::box2D::dynamics::joints::B2DistanceJoint_obj::__new(hx::TCast< box2D::dynamics::joints::B2DistanceJointDef >::cast(def));
	}
	else if (  ( _switch_1==::box2D::dynamics::joints::B2Joint_obj::e_mouseJoint)){
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2Joint.hx",118)
		joint = ::box2D::dynamics::joints::B2MouseJoint_obj::__new(hx::TCast< box2D::dynamics::joints::B2MouseJointDef >::cast(def));
	}
	else if (  ( _switch_1==::box2D::dynamics::joints::B2Joint_obj::e_prismaticJoint)){
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2Joint.hx",124)
		joint = ::box2D::dynamics::joints::B2PrismaticJoint_obj::__new(hx::TCast< box2D::dynamics::joints::B2PrismaticJointDef >::cast(def));
	}
	else if (  ( _switch_1==::box2D::dynamics::joints::B2Joint_obj::e_revoluteJoint)){
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2Joint.hx",130)
		joint = ::box2D::dynamics::joints::B2RevoluteJoint_obj::__new(hx::TCast< box2D::dynamics::joints::B2RevoluteJointDef >::cast(def));
	}
	else if (  ( _switch_1==::box2D::dynamics::joints::B2Joint_obj::e_pulleyJoint)){
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2Joint.hx",136)
		joint = ::box2D::dynamics::joints::B2PulleyJoint_obj::__new(hx::TCast< box2D::dynamics::joints::B2PulleyJointDef >::cast(def));
	}
	else if (  ( _switch_1==::box2D::dynamics::joints::B2Joint_obj::e_gearJoint)){
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2Joint.hx",142)
		joint = ::box2D::dynamics::joints::B2GearJoint_obj::__new(hx::TCast< box2D::dynamics::joints::B2GearJointDef >::cast(def));
	}
	else if (  ( _switch_1==::box2D::dynamics::joints::B2Joint_obj::e_lineJoint)){
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2Joint.hx",148)
		joint = ::box2D::dynamics::joints::B2LineJoint_obj::__new(hx::TCast< box2D::dynamics::joints::B2LineJointDef >::cast(def));
	}
	else if (  ( _switch_1==::box2D::dynamics::joints::B2Joint_obj::e_weldJoint)){
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2Joint.hx",154)
		joint = ::box2D::dynamics::joints::B2WeldJoint_obj::__new(hx::TCast< box2D::dynamics::joints::B2WeldJointDef >::cast(def));
	}
	else if (  ( _switch_1==::box2D::dynamics::joints::B2Joint_obj::e_frictionJoint)){
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2Joint.hx",160)
		joint = ::box2D::dynamics::joints::B2FrictionJoint_obj::__new(hx::TCast< box2D::dynamics::joints::B2FrictionJointDef >::cast(def));
	}
	else  {
	}
;
;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2Joint.hx",170)
	return joint;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(B2Joint_obj,create,return )

Void B2Joint_obj::destroy( ::box2D::dynamics::joints::B2Joint joint,Dynamic allocator){
{
		HX_SOURCE_PUSH("B2Joint_obj::destroy")
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(B2Joint_obj,destroy,(void))

int B2Joint_obj::e_unknownJoint;

int B2Joint_obj::e_revoluteJoint;

int B2Joint_obj::e_prismaticJoint;

int B2Joint_obj::e_distanceJoint;

int B2Joint_obj::e_pulleyJoint;

int B2Joint_obj::e_mouseJoint;

int B2Joint_obj::e_gearJoint;

int B2Joint_obj::e_lineJoint;

int B2Joint_obj::e_weldJoint;

int B2Joint_obj::e_frictionJoint;

int B2Joint_obj::e_inactiveLimit;

int B2Joint_obj::e_atLowerLimit;

int B2Joint_obj::e_atUpperLimit;

int B2Joint_obj::e_equalLimits;


B2Joint_obj::B2Joint_obj()
{
}

void B2Joint_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(B2Joint);
	HX_MARK_MEMBER_NAME(m_type,"m_type");
	HX_MARK_MEMBER_NAME(m_prev,"m_prev");
	HX_MARK_MEMBER_NAME(m_next,"m_next");
	HX_MARK_MEMBER_NAME(m_edgeA,"m_edgeA");
	HX_MARK_MEMBER_NAME(m_edgeB,"m_edgeB");
	HX_MARK_MEMBER_NAME(m_bodyA,"m_bodyA");
	HX_MARK_MEMBER_NAME(m_bodyB,"m_bodyB");
	HX_MARK_MEMBER_NAME(m_islandFlag,"m_islandFlag");
	HX_MARK_MEMBER_NAME(m_collideConnected,"m_collideConnected");
	HX_MARK_MEMBER_NAME(m_userData,"m_userData");
	HX_MARK_MEMBER_NAME(m_localCenterA,"m_localCenterA");
	HX_MARK_MEMBER_NAME(m_localCenterB,"m_localCenterB");
	HX_MARK_MEMBER_NAME(m_invMassA,"m_invMassA");
	HX_MARK_MEMBER_NAME(m_invMassB,"m_invMassB");
	HX_MARK_MEMBER_NAME(m_invIA,"m_invIA");
	HX_MARK_MEMBER_NAME(m_invIB,"m_invIB");
	HX_MARK_END_CLASS();
}

Dynamic B2Joint_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"create") ) { return create_dyn(); }
		if (HX_FIELD_EQ(inName,"m_type") ) { return m_type; }
		if (HX_FIELD_EQ(inName,"m_prev") ) { return m_prev; }
		if (HX_FIELD_EQ(inName,"m_next") ) { return m_next; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"destroy") ) { return destroy_dyn(); }
		if (HX_FIELD_EQ(inName,"getType") ) { return getType_dyn(); }
		if (HX_FIELD_EQ(inName,"getNext") ) { return getNext_dyn(); }
		if (HX_FIELD_EQ(inName,"m_edgeA") ) { return m_edgeA; }
		if (HX_FIELD_EQ(inName,"m_edgeB") ) { return m_edgeB; }
		if (HX_FIELD_EQ(inName,"m_bodyA") ) { return m_bodyA; }
		if (HX_FIELD_EQ(inName,"m_bodyB") ) { return m_bodyB; }
		if (HX_FIELD_EQ(inName,"m_invIA") ) { return m_invIA; }
		if (HX_FIELD_EQ(inName,"m_invIB") ) { return m_invIB; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"getBodyA") ) { return getBodyA_dyn(); }
		if (HX_FIELD_EQ(inName,"getBodyB") ) { return getBodyB_dyn(); }
		if (HX_FIELD_EQ(inName,"isActive") ) { return isActive_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"getAnchorA") ) { return getAnchorA_dyn(); }
		if (HX_FIELD_EQ(inName,"getAnchorB") ) { return getAnchorB_dyn(); }
		if (HX_FIELD_EQ(inName,"m_userData") ) { return m_userData; }
		if (HX_FIELD_EQ(inName,"m_invMassA") ) { return m_invMassA; }
		if (HX_FIELD_EQ(inName,"m_invMassB") ) { return m_invMassB; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"e_gearJoint") ) { return e_gearJoint; }
		if (HX_FIELD_EQ(inName,"e_lineJoint") ) { return e_lineJoint; }
		if (HX_FIELD_EQ(inName,"e_weldJoint") ) { return e_weldJoint; }
		if (HX_FIELD_EQ(inName,"getUserData") ) { return getUserData_dyn(); }
		if (HX_FIELD_EQ(inName,"setUserData") ) { return setUserData_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"e_mouseJoint") ) { return e_mouseJoint; }
		if (HX_FIELD_EQ(inName,"m_islandFlag") ) { return m_islandFlag; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"e_pulleyJoint") ) { return e_pulleyJoint; }
		if (HX_FIELD_EQ(inName,"e_equalLimits") ) { return e_equalLimits; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"e_unknownJoint") ) { return e_unknownJoint; }
		if (HX_FIELD_EQ(inName,"e_atLowerLimit") ) { return e_atLowerLimit; }
		if (HX_FIELD_EQ(inName,"e_atUpperLimit") ) { return e_atUpperLimit; }
		if (HX_FIELD_EQ(inName,"m_localCenterA") ) { return m_localCenterA; }
		if (HX_FIELD_EQ(inName,"m_localCenterB") ) { return m_localCenterB; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"e_revoluteJoint") ) { return e_revoluteJoint; }
		if (HX_FIELD_EQ(inName,"e_distanceJoint") ) { return e_distanceJoint; }
		if (HX_FIELD_EQ(inName,"e_frictionJoint") ) { return e_frictionJoint; }
		if (HX_FIELD_EQ(inName,"e_inactiveLimit") ) { return e_inactiveLimit; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"e_prismaticJoint") ) { return e_prismaticJoint; }
		if (HX_FIELD_EQ(inName,"getReactionForce") ) { return getReactionForce_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"getReactionTorque") ) { return getReactionTorque_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"m_collideConnected") ) { return m_collideConnected; }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"initVelocityConstraints") ) { return initVelocityConstraints_dyn(); }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"solveVelocityConstraints") ) { return solveVelocityConstraints_dyn(); }
		if (HX_FIELD_EQ(inName,"solvePositionConstraints") ) { return solvePositionConstraints_dyn(); }
		break;
	case 27:
		if (HX_FIELD_EQ(inName,"finalizeVelocityConstraints") ) { return finalizeVelocityConstraints_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic B2Joint_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"m_type") ) { m_type=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_prev") ) { m_prev=inValue.Cast< ::box2D::dynamics::joints::B2Joint >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_next") ) { m_next=inValue.Cast< ::box2D::dynamics::joints::B2Joint >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"m_edgeA") ) { m_edgeA=inValue.Cast< ::box2D::dynamics::joints::B2JointEdge >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_edgeB") ) { m_edgeB=inValue.Cast< ::box2D::dynamics::joints::B2JointEdge >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_bodyA") ) { m_bodyA=inValue.Cast< ::box2D::dynamics::B2Body >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_bodyB") ) { m_bodyB=inValue.Cast< ::box2D::dynamics::B2Body >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_invIA") ) { m_invIA=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_invIB") ) { m_invIB=inValue.Cast< double >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"m_userData") ) { m_userData=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_invMassA") ) { m_invMassA=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_invMassB") ) { m_invMassB=inValue.Cast< double >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"e_gearJoint") ) { e_gearJoint=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"e_lineJoint") ) { e_lineJoint=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"e_weldJoint") ) { e_weldJoint=inValue.Cast< int >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"e_mouseJoint") ) { e_mouseJoint=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_islandFlag") ) { m_islandFlag=inValue.Cast< bool >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"e_pulleyJoint") ) { e_pulleyJoint=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"e_equalLimits") ) { e_equalLimits=inValue.Cast< int >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"e_unknownJoint") ) { e_unknownJoint=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"e_atLowerLimit") ) { e_atLowerLimit=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"e_atUpperLimit") ) { e_atUpperLimit=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_localCenterA") ) { m_localCenterA=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_localCenterB") ) { m_localCenterB=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"e_revoluteJoint") ) { e_revoluteJoint=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"e_distanceJoint") ) { e_distanceJoint=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"e_frictionJoint") ) { e_frictionJoint=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"e_inactiveLimit") ) { e_inactiveLimit=inValue.Cast< int >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"e_prismaticJoint") ) { e_prismaticJoint=inValue.Cast< int >(); return inValue; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"m_collideConnected") ) { m_collideConnected=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void B2Joint_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("m_type"));
	outFields->push(HX_CSTRING("m_prev"));
	outFields->push(HX_CSTRING("m_next"));
	outFields->push(HX_CSTRING("m_edgeA"));
	outFields->push(HX_CSTRING("m_edgeB"));
	outFields->push(HX_CSTRING("m_bodyA"));
	outFields->push(HX_CSTRING("m_bodyB"));
	outFields->push(HX_CSTRING("m_islandFlag"));
	outFields->push(HX_CSTRING("m_collideConnected"));
	outFields->push(HX_CSTRING("m_userData"));
	outFields->push(HX_CSTRING("m_localCenterA"));
	outFields->push(HX_CSTRING("m_localCenterB"));
	outFields->push(HX_CSTRING("m_invMassA"));
	outFields->push(HX_CSTRING("m_invMassB"));
	outFields->push(HX_CSTRING("m_invIA"));
	outFields->push(HX_CSTRING("m_invIB"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("create"),
	HX_CSTRING("destroy"),
	HX_CSTRING("e_unknownJoint"),
	HX_CSTRING("e_revoluteJoint"),
	HX_CSTRING("e_prismaticJoint"),
	HX_CSTRING("e_distanceJoint"),
	HX_CSTRING("e_pulleyJoint"),
	HX_CSTRING("e_mouseJoint"),
	HX_CSTRING("e_gearJoint"),
	HX_CSTRING("e_lineJoint"),
	HX_CSTRING("e_weldJoint"),
	HX_CSTRING("e_frictionJoint"),
	HX_CSTRING("e_inactiveLimit"),
	HX_CSTRING("e_atLowerLimit"),
	HX_CSTRING("e_atUpperLimit"),
	HX_CSTRING("e_equalLimits"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("getType"),
	HX_CSTRING("getAnchorA"),
	HX_CSTRING("getAnchorB"),
	HX_CSTRING("getReactionForce"),
	HX_CSTRING("getReactionTorque"),
	HX_CSTRING("getBodyA"),
	HX_CSTRING("getBodyB"),
	HX_CSTRING("getNext"),
	HX_CSTRING("getUserData"),
	HX_CSTRING("setUserData"),
	HX_CSTRING("isActive"),
	HX_CSTRING("initVelocityConstraints"),
	HX_CSTRING("solveVelocityConstraints"),
	HX_CSTRING("finalizeVelocityConstraints"),
	HX_CSTRING("solvePositionConstraints"),
	HX_CSTRING("m_type"),
	HX_CSTRING("m_prev"),
	HX_CSTRING("m_next"),
	HX_CSTRING("m_edgeA"),
	HX_CSTRING("m_edgeB"),
	HX_CSTRING("m_bodyA"),
	HX_CSTRING("m_bodyB"),
	HX_CSTRING("m_islandFlag"),
	HX_CSTRING("m_collideConnected"),
	HX_CSTRING("m_userData"),
	HX_CSTRING("m_localCenterA"),
	HX_CSTRING("m_localCenterB"),
	HX_CSTRING("m_invMassA"),
	HX_CSTRING("m_invMassB"),
	HX_CSTRING("m_invIA"),
	HX_CSTRING("m_invIB"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(B2Joint_obj::e_unknownJoint,"e_unknownJoint");
	HX_MARK_MEMBER_NAME(B2Joint_obj::e_revoluteJoint,"e_revoluteJoint");
	HX_MARK_MEMBER_NAME(B2Joint_obj::e_prismaticJoint,"e_prismaticJoint");
	HX_MARK_MEMBER_NAME(B2Joint_obj::e_distanceJoint,"e_distanceJoint");
	HX_MARK_MEMBER_NAME(B2Joint_obj::e_pulleyJoint,"e_pulleyJoint");
	HX_MARK_MEMBER_NAME(B2Joint_obj::e_mouseJoint,"e_mouseJoint");
	HX_MARK_MEMBER_NAME(B2Joint_obj::e_gearJoint,"e_gearJoint");
	HX_MARK_MEMBER_NAME(B2Joint_obj::e_lineJoint,"e_lineJoint");
	HX_MARK_MEMBER_NAME(B2Joint_obj::e_weldJoint,"e_weldJoint");
	HX_MARK_MEMBER_NAME(B2Joint_obj::e_frictionJoint,"e_frictionJoint");
	HX_MARK_MEMBER_NAME(B2Joint_obj::e_inactiveLimit,"e_inactiveLimit");
	HX_MARK_MEMBER_NAME(B2Joint_obj::e_atLowerLimit,"e_atLowerLimit");
	HX_MARK_MEMBER_NAME(B2Joint_obj::e_atUpperLimit,"e_atUpperLimit");
	HX_MARK_MEMBER_NAME(B2Joint_obj::e_equalLimits,"e_equalLimits");
};

Class B2Joint_obj::__mClass;

void B2Joint_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.dynamics.joints.B2Joint"), hx::TCanCast< B2Joint_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void B2Joint_obj::__boot()
{
	hx::Static(e_unknownJoint) = (int)0;
	hx::Static(e_revoluteJoint) = (int)1;
	hx::Static(e_prismaticJoint) = (int)2;
	hx::Static(e_distanceJoint) = (int)3;
	hx::Static(e_pulleyJoint) = (int)4;
	hx::Static(e_mouseJoint) = (int)5;
	hx::Static(e_gearJoint) = (int)6;
	hx::Static(e_lineJoint) = (int)7;
	hx::Static(e_weldJoint) = (int)8;
	hx::Static(e_frictionJoint) = (int)9;
	hx::Static(e_inactiveLimit) = (int)0;
	hx::Static(e_atLowerLimit) = (int)1;
	hx::Static(e_atUpperLimit) = (int)2;
	hx::Static(e_equalLimits) = (int)3;
}

} // end namespace box2D
} // end namespace dynamics
} // end namespace joints
