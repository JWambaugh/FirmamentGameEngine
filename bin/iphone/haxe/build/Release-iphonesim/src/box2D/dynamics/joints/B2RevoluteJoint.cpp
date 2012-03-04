#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_box2D_common_B2Settings
#include <box2D/common/B2Settings.h>
#endif
#ifndef INCLUDED_box2D_common_math_B2Mat22
#include <box2D/common/math/B2Mat22.h>
#endif
#ifndef INCLUDED_box2D_common_math_B2Mat33
#include <box2D/common/math/B2Mat33.h>
#endif
#ifndef INCLUDED_box2D_common_math_B2Math
#include <box2D/common/math/B2Math.h>
#endif
#ifndef INCLUDED_box2D_common_math_B2Sweep
#include <box2D/common/math/B2Sweep.h>
#endif
#ifndef INCLUDED_box2D_common_math_B2Transform
#include <box2D/common/math/B2Transform.h>
#endif
#ifndef INCLUDED_box2D_common_math_B2Vec2
#include <box2D/common/math/B2Vec2.h>
#endif
#ifndef INCLUDED_box2D_common_math_B2Vec3
#include <box2D/common/math/B2Vec3.h>
#endif
#ifndef INCLUDED_box2D_dynamics_B2Body
#include <box2D/dynamics/B2Body.h>
#endif
#ifndef INCLUDED_box2D_dynamics_B2TimeStep
#include <box2D/dynamics/B2TimeStep.h>
#endif
#ifndef INCLUDED_box2D_dynamics_joints_B2Joint
#include <box2D/dynamics/joints/B2Joint.h>
#endif
#ifndef INCLUDED_box2D_dynamics_joints_B2JointDef
#include <box2D/dynamics/joints/B2JointDef.h>
#endif
#ifndef INCLUDED_box2D_dynamics_joints_B2RevoluteJoint
#include <box2D/dynamics/joints/B2RevoluteJoint.h>
#endif
#ifndef INCLUDED_box2D_dynamics_joints_B2RevoluteJointDef
#include <box2D/dynamics/joints/B2RevoluteJointDef.h>
#endif
namespace box2D{
namespace dynamics{
namespace joints{

Void B2RevoluteJoint_obj::__construct(::box2D::dynamics::joints::B2RevoluteJointDef def)
{
{
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",178)
	super::__construct(def);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",180)
	this->K = ::box2D::common::math::B2Mat22_obj::__new();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",181)
	this->K1 = ::box2D::common::math::B2Mat22_obj::__new();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",182)
	this->K2 = ::box2D::common::math::B2Mat22_obj::__new();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",183)
	this->K3 = ::box2D::common::math::B2Mat22_obj::__new();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",185)
	this->impulse3 = ::box2D::common::math::B2Vec3_obj::__new(null(),null(),null());
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",186)
	this->impulse2 = ::box2D::common::math::B2Vec2_obj::__new(null(),null());
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",187)
	this->reduced = ::box2D::common::math::B2Vec2_obj::__new(null(),null());
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",189)
	this->m_localAnchor1 = ::box2D::common::math::B2Vec2_obj::__new(null(),null());
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",190)
	this->m_localAnchor2 = ::box2D::common::math::B2Vec2_obj::__new(null(),null());
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",191)
	this->m_impulse = ::box2D::common::math::B2Vec3_obj::__new(null(),null(),null());
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",192)
	this->m_mass = ::box2D::common::math::B2Mat33_obj::__new(null(),null(),null());
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",196)
	this->m_localAnchor1->setV(def->localAnchorA);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",198)
	this->m_localAnchor2->setV(def->localAnchorB);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",200)
	this->m_referenceAngle = def->referenceAngle;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",202)
	this->m_impulse->setZero();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",203)
	this->m_motorImpulse = 0.0;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",205)
	this->m_lowerAngle = def->lowerAngle;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",206)
	this->m_upperAngle = def->upperAngle;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",207)
	this->m_maxMotorTorque = def->maxMotorTorque;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",208)
	this->m_motorSpeed = def->motorSpeed;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",209)
	this->m_enableLimit = def->enableLimit;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",210)
	this->m_enableMotor = def->enableMotor;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",211)
	this->m_limitState = ::box2D::dynamics::joints::B2Joint_obj::e_inactiveLimit;
}
;
	return null();
}

B2RevoluteJoint_obj::~B2RevoluteJoint_obj() { }

Dynamic B2RevoluteJoint_obj::__CreateEmpty() { return  new B2RevoluteJoint_obj; }
hx::ObjectPtr< B2RevoluteJoint_obj > B2RevoluteJoint_obj::__new(::box2D::dynamics::joints::B2RevoluteJointDef def)
{  hx::ObjectPtr< B2RevoluteJoint_obj > result = new B2RevoluteJoint_obj();
	result->__construct(def);
	return result;}

Dynamic B2RevoluteJoint_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2RevoluteJoint_obj > result = new B2RevoluteJoint_obj();
	result->__construct(inArgs[0]);
	return result;}

::box2D::common::math::B2Vec2 B2RevoluteJoint_obj::getAnchorA( ){
	HX_SOURCE_PUSH("B2RevoluteJoint_obj::getAnchorA")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",56)
	return this->m_bodyA->getWorldPoint(this->m_localAnchor1);
}


HX_DEFINE_DYNAMIC_FUNC0(B2RevoluteJoint_obj,getAnchorA,return )

::box2D::common::math::B2Vec2 B2RevoluteJoint_obj::getAnchorB( ){
	HX_SOURCE_PUSH("B2RevoluteJoint_obj::getAnchorB")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",60)
	return this->m_bodyB->getWorldPoint(this->m_localAnchor2);
}


HX_DEFINE_DYNAMIC_FUNC0(B2RevoluteJoint_obj,getAnchorB,return )

::box2D::common::math::B2Vec2 B2RevoluteJoint_obj::getReactionForce( double inv_dt){
	HX_SOURCE_PUSH("B2RevoluteJoint_obj::getReactionForce")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",65)
	return ::box2D::common::math::B2Vec2_obj::__new((inv_dt * this->m_impulse->x),(inv_dt * this->m_impulse->y));
}


HX_DEFINE_DYNAMIC_FUNC1(B2RevoluteJoint_obj,getReactionForce,return )

double B2RevoluteJoint_obj::getReactionTorque( double inv_dt){
	HX_SOURCE_PUSH("B2RevoluteJoint_obj::getReactionTorque")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",69)
	return (inv_dt * this->m_impulse->z);
}


HX_DEFINE_DYNAMIC_FUNC1(B2RevoluteJoint_obj,getReactionTorque,return )

double B2RevoluteJoint_obj::getJointAngle( ){
	HX_SOURCE_PUSH("B2RevoluteJoint_obj::getJointAngle")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",76)
	return ((this->m_bodyB->m_sweep->a - this->m_bodyA->m_sweep->a) - this->m_referenceAngle);
}


HX_DEFINE_DYNAMIC_FUNC0(B2RevoluteJoint_obj,getJointAngle,return )

double B2RevoluteJoint_obj::getJointSpeed( ){
	HX_SOURCE_PUSH("B2RevoluteJoint_obj::getJointSpeed")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",85)
	return (this->m_bodyB->m_angularVelocity - this->m_bodyA->m_angularVelocity);
}


HX_DEFINE_DYNAMIC_FUNC0(B2RevoluteJoint_obj,getJointSpeed,return )

bool B2RevoluteJoint_obj::isLimitEnabled( ){
	HX_SOURCE_PUSH("B2RevoluteJoint_obj::isLimitEnabled")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",94)
	return this->m_enableLimit;
}


HX_DEFINE_DYNAMIC_FUNC0(B2RevoluteJoint_obj,isLimitEnabled,return )

Void B2RevoluteJoint_obj::enableLimit( bool flag){
{
		HX_SOURCE_PUSH("B2RevoluteJoint_obj::enableLimit")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",101)
		this->m_enableLimit = flag;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2RevoluteJoint_obj,enableLimit,(void))

double B2RevoluteJoint_obj::getLowerLimit( ){
	HX_SOURCE_PUSH("B2RevoluteJoint_obj::getLowerLimit")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",108)
	return this->m_lowerAngle;
}


HX_DEFINE_DYNAMIC_FUNC0(B2RevoluteJoint_obj,getLowerLimit,return )

double B2RevoluteJoint_obj::getUpperLimit( ){
	HX_SOURCE_PUSH("B2RevoluteJoint_obj::getUpperLimit")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",115)
	return this->m_upperAngle;
}


HX_DEFINE_DYNAMIC_FUNC0(B2RevoluteJoint_obj,getUpperLimit,return )

Void B2RevoluteJoint_obj::setLimits( double lower,double upper){
{
		HX_SOURCE_PUSH("B2RevoluteJoint_obj::setLimits")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",124)
		this->m_lowerAngle = lower;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",125)
		this->m_upperAngle = upper;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(B2RevoluteJoint_obj,setLimits,(void))

bool B2RevoluteJoint_obj::isMotorEnabled( ){
	HX_SOURCE_PUSH("B2RevoluteJoint_obj::isMotorEnabled")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",132)
	this->m_bodyA->setAwake(true);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",133)
	this->m_bodyB->setAwake(true);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",134)
	return this->m_enableMotor;
}


HX_DEFINE_DYNAMIC_FUNC0(B2RevoluteJoint_obj,isMotorEnabled,return )

Void B2RevoluteJoint_obj::enableMotor( bool flag){
{
		HX_SOURCE_PUSH("B2RevoluteJoint_obj::enableMotor")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",140)
		this->m_enableMotor = flag;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2RevoluteJoint_obj,enableMotor,(void))

Void B2RevoluteJoint_obj::setMotorSpeed( double speed){
{
		HX_SOURCE_PUSH("B2RevoluteJoint_obj::setMotorSpeed")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",148)
		this->m_bodyA->setAwake(true);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",149)
		this->m_bodyB->setAwake(true);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",150)
		this->m_motorSpeed = speed;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2RevoluteJoint_obj,setMotorSpeed,(void))

double B2RevoluteJoint_obj::getMotorSpeed( ){
	HX_SOURCE_PUSH("B2RevoluteJoint_obj::getMotorSpeed")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",156)
	return this->m_motorSpeed;
}


HX_DEFINE_DYNAMIC_FUNC0(B2RevoluteJoint_obj,getMotorSpeed,return )

Void B2RevoluteJoint_obj::setMaxMotorTorque( double torque){
{
		HX_SOURCE_PUSH("B2RevoluteJoint_obj::setMaxMotorTorque")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",163)
		this->m_maxMotorTorque = torque;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2RevoluteJoint_obj,setMaxMotorTorque,(void))

double B2RevoluteJoint_obj::getMotorTorque( ){
	HX_SOURCE_PUSH("B2RevoluteJoint_obj::getMotorTorque")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",170)
	return this->m_maxMotorTorque;
}


HX_DEFINE_DYNAMIC_FUNC0(B2RevoluteJoint_obj,getMotorTorque,return )

Void B2RevoluteJoint_obj::initVelocityConstraints( ::box2D::dynamics::B2TimeStep step){
{
		HX_SOURCE_PUSH("B2RevoluteJoint_obj::initVelocityConstraints")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",220)
		::box2D::dynamics::B2Body bA = this->m_bodyA;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",221)
		::box2D::dynamics::B2Body bB = this->m_bodyB;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",223)
		::box2D::common::math::B2Mat22 tMat;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",224)
		double tX;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",226)
		if (((bool(this->m_enableMotor) || bool(this->m_enableLimit)))){
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",237)
		tMat = bA->m_xf->R;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",238)
		double r1X = (this->m_localAnchor1->x - bA->m_sweep->localCenter->x);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",239)
		double r1Y = (this->m_localAnchor1->y - bA->m_sweep->localCenter->y);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",240)
		tX = ((tMat->col1->x * r1X) + (tMat->col2->x * r1Y));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",241)
		r1Y = ((tMat->col1->y * r1X) + (tMat->col2->y * r1Y));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",242)
		r1X = tX;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",244)
		tMat = bB->m_xf->R;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",245)
		double r2X = (this->m_localAnchor2->x - bB->m_sweep->localCenter->x);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",246)
		double r2Y = (this->m_localAnchor2->y - bB->m_sweep->localCenter->y);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",247)
		tX = ((tMat->col1->x * r2X) + (tMat->col2->x * r2Y));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",248)
		r2Y = ((tMat->col1->y * r2X) + (tMat->col2->y * r2Y));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",249)
		r2X = tX;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",260)
		double m1 = bA->m_invMass;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",261)
		double m2 = bB->m_invMass;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",262)
		double i1 = bA->m_invI;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",263)
		double i2 = bB->m_invI;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",265)
		this->m_mass->col1->x = (((m1 + m2) + ((r1Y * r1Y) * i1)) + ((r2Y * r2Y) * i2));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",266)
		this->m_mass->col2->x = (((-(r1Y) * r1X) * i1) - ((r2Y * r2X) * i2));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",267)
		this->m_mass->col3->x = ((-(r1Y) * i1) - (r2Y * i2));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",268)
		this->m_mass->col1->y = this->m_mass->col2->x;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",269)
		this->m_mass->col2->y = (((m1 + m2) + ((r1X * r1X) * i1)) + ((r2X * r2X) * i2));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",270)
		this->m_mass->col3->y = ((r1X * i1) + (r2X * i2));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",271)
		this->m_mass->col1->z = this->m_mass->col3->x;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",272)
		this->m_mass->col2->z = this->m_mass->col3->y;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",273)
		this->m_mass->col3->z = (i1 + i2);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",276)
		this->m_motorMass = (double(1.0) / double(((i1 + i2))));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",278)
		if (((this->m_enableMotor == false))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",279)
			this->m_motorImpulse = 0.0;
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",283)
		if ((this->m_enableLimit)){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",286)
			double jointAngle = ((bB->m_sweep->a - bA->m_sweep->a) - this->m_referenceAngle);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",287)
			if (((::box2D::common::math::B2Math_obj::abs((this->m_upperAngle - this->m_lowerAngle)) < (2.0 * ::box2D::common::B2Settings_obj::b2_angularSlop)))){
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",288)
				this->m_limitState = ::box2D::dynamics::joints::B2Joint_obj::e_equalLimits;
			}
			else{
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",291)
				if (((jointAngle <= this->m_lowerAngle))){
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",293)
					if (((this->m_limitState != ::box2D::dynamics::joints::B2Joint_obj::e_atLowerLimit))){
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",294)
						this->m_impulse->z = 0.0;
					}
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",297)
					this->m_limitState = ::box2D::dynamics::joints::B2Joint_obj::e_atLowerLimit;
				}
				else{
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",299)
					if (((jointAngle >= this->m_upperAngle))){
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",301)
						if (((this->m_limitState != ::box2D::dynamics::joints::B2Joint_obj::e_atUpperLimit))){
							HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",302)
							this->m_impulse->z = 0.0;
						}
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",305)
						this->m_limitState = ::box2D::dynamics::joints::B2Joint_obj::e_atUpperLimit;
					}
					else{
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",309)
						this->m_limitState = ::box2D::dynamics::joints::B2Joint_obj::e_inactiveLimit;
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",310)
						this->m_impulse->z = 0.0;
					}
				}
			}
		}
		else{
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",314)
			this->m_limitState = ::box2D::dynamics::joints::B2Joint_obj::e_inactiveLimit;
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",319)
		if ((step->warmStarting)){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",322)
			hx::MultEq(this->m_impulse->x,step->dtRatio);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",323)
			hx::MultEq(this->m_impulse->y,step->dtRatio);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",324)
			hx::MultEq(this->m_motorImpulse,step->dtRatio);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",326)
			double PX = this->m_impulse->x;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",327)
			double PY = this->m_impulse->y;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",330)
			hx::SubEq(bA->m_linearVelocity->x,(m1 * PX));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",331)
			hx::SubEq(bA->m_linearVelocity->y,(m1 * PY));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",333)
			hx::SubEq(bA->m_angularVelocity,(i1 * (((((r1X * PY) - (r1Y * PX)) + this->m_motorImpulse) + this->m_impulse->z))));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",336)
			hx::AddEq(bB->m_linearVelocity->x,(m2 * PX));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",337)
			hx::AddEq(bB->m_linearVelocity->y,(m2 * PY));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",339)
			hx::AddEq(bB->m_angularVelocity,(i2 * (((((r2X * PY) - (r2Y * PX)) + this->m_motorImpulse) + this->m_impulse->z))));
		}
		else{
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",343)
			this->m_impulse->setZero();
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",344)
			this->m_motorImpulse = 0.0;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2RevoluteJoint_obj,initVelocityConstraints,(void))

Void B2RevoluteJoint_obj::solveVelocityConstraints( ::box2D::dynamics::B2TimeStep step){
{
		HX_SOURCE_PUSH("B2RevoluteJoint_obj::solveVelocityConstraints")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",352)
		::box2D::dynamics::B2Body bA = this->m_bodyA;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",353)
		::box2D::dynamics::B2Body bB = this->m_bodyB;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",355)
		::box2D::common::math::B2Mat22 tMat;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",356)
		double tX;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",358)
		double newImpulse;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",359)
		double r1X;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",360)
		double r1Y;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",361)
		double r2X;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",362)
		double r2Y;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",364)
		::box2D::common::math::B2Vec2 v1 = bA->m_linearVelocity;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",365)
		double w1 = bA->m_angularVelocity;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",366)
		::box2D::common::math::B2Vec2 v2 = bB->m_linearVelocity;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",367)
		double w2 = bB->m_angularVelocity;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",369)
		double m1 = bA->m_invMass;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",370)
		double m2 = bB->m_invMass;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",371)
		double i1 = bA->m_invI;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",372)
		double i2 = bB->m_invI;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",375)
		if (((bool(this->m_enableMotor) && bool((this->m_limitState != ::box2D::dynamics::joints::B2Joint_obj::e_equalLimits))))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",377)
			double Cdot = ((w2 - w1) - this->m_motorSpeed);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",378)
			double impulse = (this->m_motorMass * -(Cdot));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",379)
			double oldImpulse = this->m_motorImpulse;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",380)
			double maxImpulse = (step->dt * this->m_maxMotorTorque);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",382)
			this->m_motorImpulse = ::box2D::common::math::B2Math_obj::clamp((this->m_motorImpulse + impulse),-(maxImpulse),maxImpulse);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",383)
			impulse = (this->m_motorImpulse - oldImpulse);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",385)
			hx::SubEq(w1,(i1 * impulse));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",386)
			hx::AddEq(w2,(i2 * impulse));
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",390)
		if (((bool(this->m_enableLimit) && bool((this->m_limitState != ::box2D::dynamics::joints::B2Joint_obj::e_inactiveLimit))))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",393)
			tMat = bA->m_xf->R;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",394)
			r1X = (this->m_localAnchor1->x - bA->m_sweep->localCenter->x);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",395)
			r1Y = (this->m_localAnchor1->y - bA->m_sweep->localCenter->y);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",396)
			tX = ((tMat->col1->x * r1X) + (tMat->col2->x * r1Y));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",397)
			r1Y = ((tMat->col1->y * r1X) + (tMat->col2->y * r1Y));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",398)
			r1X = tX;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",400)
			tMat = bB->m_xf->R;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",401)
			r2X = (this->m_localAnchor2->x - bB->m_sweep->localCenter->x);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",402)
			r2Y = (this->m_localAnchor2->y - bB->m_sweep->localCenter->y);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",403)
			tX = ((tMat->col1->x * r2X) + (tMat->col2->x * r2Y));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",404)
			r2Y = ((tMat->col1->y * r2X) + (tMat->col2->y * r2Y));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",405)
			r2X = tX;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",409)
			double Cdot1X = (((v2->x + (-(w2) * r2Y)) - v1->x) - (-(w1) * r1Y));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",410)
			double Cdot1Y = (((v2->y + (w2 * r2X)) - v1->y) - (w1 * r1X));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",411)
			double Cdot2 = (w2 - w1);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",413)
			this->m_mass->solve33(this->impulse3,-(Cdot1X),-(Cdot1Y),-(Cdot2));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",415)
			if (((this->m_limitState == ::box2D::dynamics::joints::B2Joint_obj::e_equalLimits))){
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",416)
				this->m_impulse->add(this->impulse3);
			}
			else{
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",419)
				if (((this->m_limitState == ::box2D::dynamics::joints::B2Joint_obj::e_atLowerLimit))){
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",421)
					newImpulse = (this->m_impulse->z + this->impulse3->z);
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",422)
					if (((newImpulse < 0.0))){
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",424)
						this->m_mass->solve22(this->reduced,-(Cdot1X),-(Cdot1Y));
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",425)
						this->impulse3->x = this->reduced->x;
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",426)
						this->impulse3->y = this->reduced->y;
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",427)
						this->impulse3->z = -(this->m_impulse->z);
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",428)
						hx::AddEq(this->m_impulse->x,this->reduced->x);
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",429)
						hx::AddEq(this->m_impulse->y,this->reduced->y);
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",430)
						this->m_impulse->z = 0.0;
					}
				}
				else{
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",433)
					if (((this->m_limitState == ::box2D::dynamics::joints::B2Joint_obj::e_atUpperLimit))){
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",435)
						newImpulse = (this->m_impulse->z + this->impulse3->z);
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",436)
						if (((newImpulse > 0.0))){
							HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",438)
							this->m_mass->solve22(this->reduced,-(Cdot1X),-(Cdot1Y));
							HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",439)
							this->impulse3->x = this->reduced->x;
							HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",440)
							this->impulse3->y = this->reduced->y;
							HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",441)
							this->impulse3->z = -(this->m_impulse->z);
							HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",442)
							hx::AddEq(this->m_impulse->x,this->reduced->x);
							HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",443)
							hx::AddEq(this->m_impulse->y,this->reduced->y);
							HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",444)
							this->m_impulse->z = 0.0;
						}
					}
				}
			}
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",448)
			hx::SubEq(v1->x,(m1 * this->impulse3->x));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",449)
			hx::SubEq(v1->y,(m1 * this->impulse3->y));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",450)
			hx::SubEq(w1,(i1 * ((((r1X * this->impulse3->y) - (r1Y * this->impulse3->x)) + this->impulse3->z))));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",452)
			hx::AddEq(v2->x,(m2 * this->impulse3->x));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",453)
			hx::AddEq(v2->y,(m2 * this->impulse3->y));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",454)
			hx::AddEq(w2,(i2 * ((((r2X * this->impulse3->y) - (r2Y * this->impulse3->x)) + this->impulse3->z))));
		}
		else{
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",459)
			tMat = bA->m_xf->R;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",460)
			r1X = (this->m_localAnchor1->x - bA->m_sweep->localCenter->x);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",461)
			r1Y = (this->m_localAnchor1->y - bA->m_sweep->localCenter->y);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",462)
			tX = ((tMat->col1->x * r1X) + (tMat->col2->x * r1Y));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",463)
			r1Y = ((tMat->col1->y * r1X) + (tMat->col2->y * r1Y));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",464)
			r1X = tX;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",466)
			tMat = bB->m_xf->R;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",467)
			r2X = (this->m_localAnchor2->x - bB->m_sweep->localCenter->x);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",468)
			r2Y = (this->m_localAnchor2->y - bB->m_sweep->localCenter->y);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",469)
			tX = ((tMat->col1->x * r2X) + (tMat->col2->x * r2Y));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",470)
			r2Y = ((tMat->col1->y * r2X) + (tMat->col2->y * r2Y));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",471)
			r2X = tX;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",474)
			double CdotX = (((v2->x + (-(w2) * r2Y)) - v1->x) - (-(w1) * r1Y));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",475)
			double CdotY = (((v2->y + (w2 * r2X)) - v1->y) - (w1 * r1X));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",477)
			this->m_mass->solve22(this->impulse2,-(CdotX),-(CdotY));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",479)
			hx::AddEq(this->m_impulse->x,this->impulse2->x);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",480)
			hx::AddEq(this->m_impulse->y,this->impulse2->y);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",482)
			hx::SubEq(v1->x,(m1 * this->impulse2->x));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",483)
			hx::SubEq(v1->y,(m1 * this->impulse2->y));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",485)
			hx::SubEq(w1,(i1 * (((r1X * this->impulse2->y) - (r1Y * this->impulse2->x)))));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",487)
			hx::AddEq(v2->x,(m2 * this->impulse2->x));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",488)
			hx::AddEq(v2->y,(m2 * this->impulse2->y));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",490)
			hx::AddEq(w2,(i2 * (((r2X * this->impulse2->y) - (r2Y * this->impulse2->x)))));
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",493)
		bA->m_linearVelocity->setV(v1);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",494)
		bA->m_angularVelocity = w1;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",495)
		bB->m_linearVelocity->setV(v2);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",496)
		bB->m_angularVelocity = w2;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2RevoluteJoint_obj,solveVelocityConstraints,(void))

bool B2RevoluteJoint_obj::solvePositionConstraints( double baumgarte){
	HX_SOURCE_PUSH("B2RevoluteJoint_obj::solvePositionConstraints")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",504)
	double oldLimitImpulse;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",505)
	double C;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",507)
	::box2D::common::math::B2Mat22 tMat;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",509)
	::box2D::dynamics::B2Body bA = this->m_bodyA;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",510)
	::box2D::dynamics::B2Body bB = this->m_bodyB;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",512)
	double angularError = 0.0;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",513)
	double positionError = 0.0;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",515)
	double tX;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",517)
	double impulseX;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",518)
	double impulseY;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",521)
	if (((bool(this->m_enableLimit) && bool((this->m_limitState != ::box2D::dynamics::joints::B2Joint_obj::e_inactiveLimit))))){
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",523)
		double angle = ((bB->m_sweep->a - bA->m_sweep->a) - this->m_referenceAngle);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",524)
		double limitImpulse = 0.0;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",526)
		if (((this->m_limitState == ::box2D::dynamics::joints::B2Joint_obj::e_equalLimits))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",529)
			C = ::box2D::common::math::B2Math_obj::clamp((angle - this->m_lowerAngle),-(::box2D::common::B2Settings_obj::b2_maxAngularCorrection),::box2D::common::B2Settings_obj::b2_maxAngularCorrection);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",530)
			limitImpulse = (-(this->m_motorMass) * C);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",531)
			angularError = ::box2D::common::math::B2Math_obj::abs(C);
		}
		else{
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",533)
			if (((this->m_limitState == ::box2D::dynamics::joints::B2Joint_obj::e_atLowerLimit))){
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",535)
				C = (angle - this->m_lowerAngle);
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",536)
				angularError = -(C);
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",539)
				C = ::box2D::common::math::B2Math_obj::clamp((C + ::box2D::common::B2Settings_obj::b2_angularSlop),-(::box2D::common::B2Settings_obj::b2_maxAngularCorrection),0.0);
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",540)
				limitImpulse = (-(this->m_motorMass) * C);
			}
			else{
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",542)
				if (((this->m_limitState == ::box2D::dynamics::joints::B2Joint_obj::e_atUpperLimit))){
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",544)
					C = (angle - this->m_upperAngle);
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",545)
					angularError = C;
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",548)
					C = ::box2D::common::math::B2Math_obj::clamp((C - ::box2D::common::B2Settings_obj::b2_angularSlop),0.0,::box2D::common::B2Settings_obj::b2_maxAngularCorrection);
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",549)
					limitImpulse = (-(this->m_motorMass) * C);
				}
			}
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",552)
		hx::SubEq(bA->m_sweep->a,(bA->m_invI * limitImpulse));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",553)
		hx::AddEq(bB->m_sweep->a,(bB->m_invI * limitImpulse));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",555)
		bA->synchronizeTransform();
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",556)
		bB->synchronizeTransform();
	}
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",560)
	{
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",562)
		tMat = bA->m_xf->R;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",563)
		double r1X = (this->m_localAnchor1->x - bA->m_sweep->localCenter->x);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",564)
		double r1Y = (this->m_localAnchor1->y - bA->m_sweep->localCenter->y);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",565)
		tX = ((tMat->col1->x * r1X) + (tMat->col2->x * r1Y));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",566)
		r1Y = ((tMat->col1->y * r1X) + (tMat->col2->y * r1Y));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",567)
		r1X = tX;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",569)
		tMat = bB->m_xf->R;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",570)
		double r2X = (this->m_localAnchor2->x - bB->m_sweep->localCenter->x);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",571)
		double r2Y = (this->m_localAnchor2->y - bB->m_sweep->localCenter->y);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",572)
		tX = ((tMat->col1->x * r2X) + (tMat->col2->x * r2Y));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",573)
		r2Y = ((tMat->col1->y * r2X) + (tMat->col2->y * r2Y));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",574)
		r2X = tX;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",577)
		double CX = (((bB->m_sweep->c->x + r2X) - bA->m_sweep->c->x) - r1X);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",578)
		double CY = (((bB->m_sweep->c->y + r2Y) - bA->m_sweep->c->y) - r1Y);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",579)
		double CLengthSquared = ((CX * CX) + (CY * CY));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",580)
		double CLength = ::Math_obj::sqrt(CLengthSquared);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",581)
		positionError = CLength;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",583)
		double invMass1 = bA->m_invMass;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",584)
		double invMass2 = bB->m_invMass;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",585)
		double invI1 = bA->m_invI;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",586)
		double invI2 = bB->m_invI;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",589)
		double k_allowedStretch = (10.0 * ::box2D::common::B2Settings_obj::b2_linearSlop);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",590)
		if (((CLengthSquared > (k_allowedStretch * k_allowedStretch)))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",594)
			double uX = (double(CX) / double(CLength));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",595)
			double uY = (double(CY) / double(CLength));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",596)
			double k = (invMass1 + invMass2);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",598)
			double m = (double(1.0) / double(k));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",599)
			impulseX = (m * -(CX));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",600)
			impulseY = (m * -(CY));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",601)
			double k_beta = 0.5;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",602)
			hx::SubEq(bA->m_sweep->c->x,((k_beta * invMass1) * impulseX));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",603)
			hx::SubEq(bA->m_sweep->c->y,((k_beta * invMass1) * impulseY));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",604)
			hx::AddEq(bB->m_sweep->c->x,((k_beta * invMass2) * impulseX));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",605)
			hx::AddEq(bB->m_sweep->c->y,((k_beta * invMass2) * impulseY));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",608)
			CX = (((bB->m_sweep->c->x + r2X) - bA->m_sweep->c->x) - r1X);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",609)
			CY = (((bB->m_sweep->c->y + r2Y) - bA->m_sweep->c->y) - r1Y);
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",613)
		this->K1->col1->x = (invMass1 + invMass2);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",613)
		this->K1->col2->x = 0.0;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",614)
		this->K1->col1->y = 0.0;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",614)
		this->K1->col2->y = (invMass1 + invMass2);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",617)
		this->K2->col1->x = ((invI1 * r1Y) * r1Y);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",617)
		this->K2->col2->x = ((-(invI1) * r1X) * r1Y);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",618)
		this->K2->col1->y = ((-(invI1) * r1X) * r1Y);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",618)
		this->K2->col2->y = ((invI1 * r1X) * r1X);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",621)
		this->K3->col1->x = ((invI2 * r2Y) * r2Y);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",621)
		this->K3->col2->x = ((-(invI2) * r2X) * r2Y);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",622)
		this->K3->col1->y = ((-(invI2) * r2X) * r2Y);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",622)
		this->K3->col2->y = ((invI2 * r2X) * r2X);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",625)
		this->K->setM(this->K1);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",626)
		this->K->addM(this->K2);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",627)
		this->K->addM(this->K3);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",629)
		this->K->solve(::box2D::dynamics::joints::B2RevoluteJoint_obj::tImpulse,-(CX),-(CY));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",630)
		impulseX = ::box2D::dynamics::joints::B2RevoluteJoint_obj::tImpulse->x;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",631)
		impulseY = ::box2D::dynamics::joints::B2RevoluteJoint_obj::tImpulse->y;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",634)
		hx::SubEq(bA->m_sweep->c->x,(bA->m_invMass * impulseX));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",635)
		hx::SubEq(bA->m_sweep->c->y,(bA->m_invMass * impulseY));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",637)
		hx::SubEq(bA->m_sweep->a,(bA->m_invI * (((r1X * impulseY) - (r1Y * impulseX)))));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",640)
		hx::AddEq(bB->m_sweep->c->x,(bB->m_invMass * impulseX));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",641)
		hx::AddEq(bB->m_sweep->c->y,(bB->m_invMass * impulseY));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",643)
		hx::AddEq(bB->m_sweep->a,(bB->m_invI * (((r2X * impulseY) - (r2Y * impulseX)))));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",645)
		bA->synchronizeTransform();
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",646)
		bB->synchronizeTransform();
	}
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2RevoluteJoint.hx",649)
	return (bool((positionError <= ::box2D::common::B2Settings_obj::b2_linearSlop)) && bool((angularError <= ::box2D::common::B2Settings_obj::b2_angularSlop)));
}


HX_DEFINE_DYNAMIC_FUNC1(B2RevoluteJoint_obj,solvePositionConstraints,return )

::box2D::common::math::B2Vec2 B2RevoluteJoint_obj::tImpulse;


B2RevoluteJoint_obj::B2RevoluteJoint_obj()
{
}

void B2RevoluteJoint_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(B2RevoluteJoint);
	HX_MARK_MEMBER_NAME(K,"K");
	HX_MARK_MEMBER_NAME(K1,"K1");
	HX_MARK_MEMBER_NAME(K2,"K2");
	HX_MARK_MEMBER_NAME(K3,"K3");
	HX_MARK_MEMBER_NAME(impulse3,"impulse3");
	HX_MARK_MEMBER_NAME(impulse2,"impulse2");
	HX_MARK_MEMBER_NAME(reduced,"reduced");
	HX_MARK_MEMBER_NAME(m_localAnchor1,"m_localAnchor1");
	HX_MARK_MEMBER_NAME(m_localAnchor2,"m_localAnchor2");
	HX_MARK_MEMBER_NAME(m_impulse,"m_impulse");
	HX_MARK_MEMBER_NAME(m_motorImpulse,"m_motorImpulse");
	HX_MARK_MEMBER_NAME(m_mass,"m_mass");
	HX_MARK_MEMBER_NAME(m_motorMass,"m_motorMass");
	HX_MARK_MEMBER_NAME(m_enableMotor,"m_enableMotor");
	HX_MARK_MEMBER_NAME(m_maxMotorTorque,"m_maxMotorTorque");
	HX_MARK_MEMBER_NAME(m_motorSpeed,"m_motorSpeed");
	HX_MARK_MEMBER_NAME(m_enableLimit,"m_enableLimit");
	HX_MARK_MEMBER_NAME(m_referenceAngle,"m_referenceAngle");
	HX_MARK_MEMBER_NAME(m_lowerAngle,"m_lowerAngle");
	HX_MARK_MEMBER_NAME(m_upperAngle,"m_upperAngle");
	HX_MARK_MEMBER_NAME(m_limitState,"m_limitState");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic B2RevoluteJoint_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"K") ) { return K; }
		break;
	case 2:
		if (HX_FIELD_EQ(inName,"K1") ) { return K1; }
		if (HX_FIELD_EQ(inName,"K2") ) { return K2; }
		if (HX_FIELD_EQ(inName,"K3") ) { return K3; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"m_mass") ) { return m_mass; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"reduced") ) { return reduced; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"tImpulse") ) { return tImpulse; }
		if (HX_FIELD_EQ(inName,"impulse3") ) { return impulse3; }
		if (HX_FIELD_EQ(inName,"impulse2") ) { return impulse2; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"setLimits") ) { return setLimits_dyn(); }
		if (HX_FIELD_EQ(inName,"m_impulse") ) { return m_impulse; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"getAnchorA") ) { return getAnchorA_dyn(); }
		if (HX_FIELD_EQ(inName,"getAnchorB") ) { return getAnchorB_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"enableLimit") ) { return enableLimit_dyn(); }
		if (HX_FIELD_EQ(inName,"enableMotor") ) { return enableMotor_dyn(); }
		if (HX_FIELD_EQ(inName,"m_motorMass") ) { return m_motorMass; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"m_motorSpeed") ) { return m_motorSpeed; }
		if (HX_FIELD_EQ(inName,"m_lowerAngle") ) { return m_lowerAngle; }
		if (HX_FIELD_EQ(inName,"m_upperAngle") ) { return m_upperAngle; }
		if (HX_FIELD_EQ(inName,"m_limitState") ) { return m_limitState; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"getJointAngle") ) { return getJointAngle_dyn(); }
		if (HX_FIELD_EQ(inName,"getJointSpeed") ) { return getJointSpeed_dyn(); }
		if (HX_FIELD_EQ(inName,"getLowerLimit") ) { return getLowerLimit_dyn(); }
		if (HX_FIELD_EQ(inName,"getUpperLimit") ) { return getUpperLimit_dyn(); }
		if (HX_FIELD_EQ(inName,"setMotorSpeed") ) { return setMotorSpeed_dyn(); }
		if (HX_FIELD_EQ(inName,"getMotorSpeed") ) { return getMotorSpeed_dyn(); }
		if (HX_FIELD_EQ(inName,"m_enableMotor") ) { return m_enableMotor; }
		if (HX_FIELD_EQ(inName,"m_enableLimit") ) { return m_enableLimit; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"isLimitEnabled") ) { return isLimitEnabled_dyn(); }
		if (HX_FIELD_EQ(inName,"isMotorEnabled") ) { return isMotorEnabled_dyn(); }
		if (HX_FIELD_EQ(inName,"getMotorTorque") ) { return getMotorTorque_dyn(); }
		if (HX_FIELD_EQ(inName,"m_localAnchor1") ) { return m_localAnchor1; }
		if (HX_FIELD_EQ(inName,"m_localAnchor2") ) { return m_localAnchor2; }
		if (HX_FIELD_EQ(inName,"m_motorImpulse") ) { return m_motorImpulse; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"getReactionForce") ) { return getReactionForce_dyn(); }
		if (HX_FIELD_EQ(inName,"m_maxMotorTorque") ) { return m_maxMotorTorque; }
		if (HX_FIELD_EQ(inName,"m_referenceAngle") ) { return m_referenceAngle; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"getReactionTorque") ) { return getReactionTorque_dyn(); }
		if (HX_FIELD_EQ(inName,"setMaxMotorTorque") ) { return setMaxMotorTorque_dyn(); }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"initVelocityConstraints") ) { return initVelocityConstraints_dyn(); }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"solveVelocityConstraints") ) { return solveVelocityConstraints_dyn(); }
		if (HX_FIELD_EQ(inName,"solvePositionConstraints") ) { return solvePositionConstraints_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic B2RevoluteJoint_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"K") ) { K=inValue.Cast< ::box2D::common::math::B2Mat22 >(); return inValue; }
		break;
	case 2:
		if (HX_FIELD_EQ(inName,"K1") ) { K1=inValue.Cast< ::box2D::common::math::B2Mat22 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"K2") ) { K2=inValue.Cast< ::box2D::common::math::B2Mat22 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"K3") ) { K3=inValue.Cast< ::box2D::common::math::B2Mat22 >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"m_mass") ) { m_mass=inValue.Cast< ::box2D::common::math::B2Mat33 >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"reduced") ) { reduced=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"tImpulse") ) { tImpulse=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"impulse3") ) { impulse3=inValue.Cast< ::box2D::common::math::B2Vec3 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"impulse2") ) { impulse2=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"m_impulse") ) { m_impulse=inValue.Cast< ::box2D::common::math::B2Vec3 >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"m_motorMass") ) { m_motorMass=inValue.Cast< double >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"m_motorSpeed") ) { m_motorSpeed=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_lowerAngle") ) { m_lowerAngle=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_upperAngle") ) { m_upperAngle=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_limitState") ) { m_limitState=inValue.Cast< int >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"m_enableMotor") ) { m_enableMotor=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_enableLimit") ) { m_enableLimit=inValue.Cast< bool >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"m_localAnchor1") ) { m_localAnchor1=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_localAnchor2") ) { m_localAnchor2=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_motorImpulse") ) { m_motorImpulse=inValue.Cast< double >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"m_maxMotorTorque") ) { m_maxMotorTorque=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_referenceAngle") ) { m_referenceAngle=inValue.Cast< double >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void B2RevoluteJoint_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("K"));
	outFields->push(HX_CSTRING("K1"));
	outFields->push(HX_CSTRING("K2"));
	outFields->push(HX_CSTRING("K3"));
	outFields->push(HX_CSTRING("impulse3"));
	outFields->push(HX_CSTRING("impulse2"));
	outFields->push(HX_CSTRING("reduced"));
	outFields->push(HX_CSTRING("m_localAnchor1"));
	outFields->push(HX_CSTRING("m_localAnchor2"));
	outFields->push(HX_CSTRING("m_impulse"));
	outFields->push(HX_CSTRING("m_motorImpulse"));
	outFields->push(HX_CSTRING("m_mass"));
	outFields->push(HX_CSTRING("m_motorMass"));
	outFields->push(HX_CSTRING("m_enableMotor"));
	outFields->push(HX_CSTRING("m_maxMotorTorque"));
	outFields->push(HX_CSTRING("m_motorSpeed"));
	outFields->push(HX_CSTRING("m_enableLimit"));
	outFields->push(HX_CSTRING("m_referenceAngle"));
	outFields->push(HX_CSTRING("m_lowerAngle"));
	outFields->push(HX_CSTRING("m_upperAngle"));
	outFields->push(HX_CSTRING("m_limitState"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("tImpulse"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("getAnchorA"),
	HX_CSTRING("getAnchorB"),
	HX_CSTRING("getReactionForce"),
	HX_CSTRING("getReactionTorque"),
	HX_CSTRING("getJointAngle"),
	HX_CSTRING("getJointSpeed"),
	HX_CSTRING("isLimitEnabled"),
	HX_CSTRING("enableLimit"),
	HX_CSTRING("getLowerLimit"),
	HX_CSTRING("getUpperLimit"),
	HX_CSTRING("setLimits"),
	HX_CSTRING("isMotorEnabled"),
	HX_CSTRING("enableMotor"),
	HX_CSTRING("setMotorSpeed"),
	HX_CSTRING("getMotorSpeed"),
	HX_CSTRING("setMaxMotorTorque"),
	HX_CSTRING("getMotorTorque"),
	HX_CSTRING("K"),
	HX_CSTRING("K1"),
	HX_CSTRING("K2"),
	HX_CSTRING("K3"),
	HX_CSTRING("initVelocityConstraints"),
	HX_CSTRING("impulse3"),
	HX_CSTRING("impulse2"),
	HX_CSTRING("reduced"),
	HX_CSTRING("solveVelocityConstraints"),
	HX_CSTRING("solvePositionConstraints"),
	HX_CSTRING("m_localAnchor1"),
	HX_CSTRING("m_localAnchor2"),
	HX_CSTRING("m_impulse"),
	HX_CSTRING("m_motorImpulse"),
	HX_CSTRING("m_mass"),
	HX_CSTRING("m_motorMass"),
	HX_CSTRING("m_enableMotor"),
	HX_CSTRING("m_maxMotorTorque"),
	HX_CSTRING("m_motorSpeed"),
	HX_CSTRING("m_enableLimit"),
	HX_CSTRING("m_referenceAngle"),
	HX_CSTRING("m_lowerAngle"),
	HX_CSTRING("m_upperAngle"),
	HX_CSTRING("m_limitState"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(B2RevoluteJoint_obj::tImpulse,"tImpulse");
};

Class B2RevoluteJoint_obj::__mClass;

void B2RevoluteJoint_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.dynamics.joints.B2RevoluteJoint"), hx::TCanCast< B2RevoluteJoint_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void B2RevoluteJoint_obj::__boot()
{
	hx::Static(tImpulse) = ::box2D::common::math::B2Vec2_obj::__new(null(),null());
}

} // end namespace box2D
} // end namespace dynamics
} // end namespace joints
