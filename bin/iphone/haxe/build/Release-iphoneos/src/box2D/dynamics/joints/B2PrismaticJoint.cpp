#include <hxcpp.h>

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
#ifndef INCLUDED_box2D_dynamics_joints_B2PrismaticJoint
#include <box2D/dynamics/joints/B2PrismaticJoint.h>
#endif
#ifndef INCLUDED_box2D_dynamics_joints_B2PrismaticJointDef
#include <box2D/dynamics/joints/B2PrismaticJointDef.h>
#endif
namespace box2D{
namespace dynamics{
namespace joints{

Void B2PrismaticJoint_obj::__construct(::box2D::dynamics::joints::B2PrismaticJointDef def)
{
{
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",297)
	super::__construct(def);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",299)
	this->m_localAnchor1 = ::box2D::common::math::B2Vec2_obj::__new(null(),null());
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",300)
	this->m_localAnchor2 = ::box2D::common::math::B2Vec2_obj::__new(null(),null());
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",301)
	this->m_localXAxis1 = ::box2D::common::math::B2Vec2_obj::__new(null(),null());
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",302)
	this->m_localYAxis1 = ::box2D::common::math::B2Vec2_obj::__new(null(),null());
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",303)
	this->m_axis = ::box2D::common::math::B2Vec2_obj::__new(null(),null());
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",304)
	this->m_perp = ::box2D::common::math::B2Vec2_obj::__new(null(),null());
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",305)
	this->m_K = ::box2D::common::math::B2Mat33_obj::__new(null(),null(),null());
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",306)
	this->m_impulse = ::box2D::common::math::B2Vec3_obj::__new(null(),null(),null());
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",309)
	::box2D::common::math::B2Mat22 tMat;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",310)
	double tX;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",311)
	double tY;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",313)
	this->m_localAnchor1->setV(def->localAnchorA);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",314)
	this->m_localAnchor2->setV(def->localAnchorB);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",315)
	this->m_localXAxis1->setV(def->localAxisA);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",318)
	this->m_localYAxis1->x = -(this->m_localXAxis1->y);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",319)
	this->m_localYAxis1->y = this->m_localXAxis1->x;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",321)
	this->m_refAngle = def->referenceAngle;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",323)
	this->m_impulse->setZero();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",324)
	this->m_motorMass = 0.0;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",325)
	this->m_motorImpulse = 0.0;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",327)
	this->m_lowerTranslation = def->lowerTranslation;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",328)
	this->m_upperTranslation = def->upperTranslation;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",329)
	this->m_maxMotorForce = def->maxMotorForce;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",330)
	this->m_motorSpeed = def->motorSpeed;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",331)
	this->m_enableLimit = def->enableLimit;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",332)
	this->m_enableMotor = def->enableMotor;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",333)
	this->m_limitState = ::box2D::dynamics::joints::B2Joint_obj::e_inactiveLimit;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",335)
	this->m_axis->setZero();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",336)
	this->m_perp->setZero();
}
;
	return null();
}

B2PrismaticJoint_obj::~B2PrismaticJoint_obj() { }

Dynamic B2PrismaticJoint_obj::__CreateEmpty() { return  new B2PrismaticJoint_obj; }
hx::ObjectPtr< B2PrismaticJoint_obj > B2PrismaticJoint_obj::__new(::box2D::dynamics::joints::B2PrismaticJointDef def)
{  hx::ObjectPtr< B2PrismaticJoint_obj > result = new B2PrismaticJoint_obj();
	result->__construct(def);
	return result;}

Dynamic B2PrismaticJoint_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2PrismaticJoint_obj > result = new B2PrismaticJoint_obj();
	result->__construct(inArgs[0]);
	return result;}

::box2D::common::math::B2Vec2 B2PrismaticJoint_obj::getAnchorA( ){
	HX_SOURCE_PUSH("B2PrismaticJoint_obj::getAnchorA")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",109)
	return this->m_bodyA->getWorldPoint(this->m_localAnchor1);
}


HX_DEFINE_DYNAMIC_FUNC0(B2PrismaticJoint_obj,getAnchorA,return )

::box2D::common::math::B2Vec2 B2PrismaticJoint_obj::getAnchorB( ){
	HX_SOURCE_PUSH("B2PrismaticJoint_obj::getAnchorB")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",113)
	return this->m_bodyB->getWorldPoint(this->m_localAnchor2);
}


HX_DEFINE_DYNAMIC_FUNC0(B2PrismaticJoint_obj,getAnchorB,return )

::box2D::common::math::B2Vec2 B2PrismaticJoint_obj::getReactionForce( double inv_dt){
	HX_SOURCE_PUSH("B2PrismaticJoint_obj::getReactionForce")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",118)
	return ::box2D::common::math::B2Vec2_obj::__new((inv_dt * (((this->m_impulse->x * this->m_perp->x) + (((this->m_motorImpulse + this->m_impulse->z)) * this->m_axis->x)))),(inv_dt * (((this->m_impulse->x * this->m_perp->y) + (((this->m_motorImpulse + this->m_impulse->z)) * this->m_axis->y)))));
}


HX_DEFINE_DYNAMIC_FUNC1(B2PrismaticJoint_obj,getReactionForce,return )

double B2PrismaticJoint_obj::getReactionTorque( double inv_dt){
	HX_SOURCE_PUSH("B2PrismaticJoint_obj::getReactionTorque")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",126)
	return (inv_dt * this->m_impulse->y);
}


HX_DEFINE_DYNAMIC_FUNC1(B2PrismaticJoint_obj,getReactionTorque,return )

double B2PrismaticJoint_obj::getJointTranslation( ){
	HX_SOURCE_PUSH("B2PrismaticJoint_obj::getJointTranslation")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",134)
	::box2D::dynamics::B2Body bA = this->m_bodyA;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",135)
	::box2D::dynamics::B2Body bB = this->m_bodyB;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",137)
	::box2D::common::math::B2Mat22 tMat;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",139)
	::box2D::common::math::B2Vec2 p1 = bA->getWorldPoint(this->m_localAnchor1);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",140)
	::box2D::common::math::B2Vec2 p2 = bB->getWorldPoint(this->m_localAnchor2);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",142)
	double dX = (p2->x - p1->x);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",143)
	double dY = (p2->y - p1->y);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",145)
	::box2D::common::math::B2Vec2 axis = bA->getWorldVector(this->m_localXAxis1);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",148)
	double translation = ((axis->x * dX) + (axis->y * dY));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",149)
	return translation;
}


HX_DEFINE_DYNAMIC_FUNC0(B2PrismaticJoint_obj,getJointTranslation,return )

double B2PrismaticJoint_obj::getJointSpeed( ){
	HX_SOURCE_PUSH("B2PrismaticJoint_obj::getJointSpeed")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",156)
	::box2D::dynamics::B2Body bA = this->m_bodyA;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",157)
	::box2D::dynamics::B2Body bB = this->m_bodyB;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",159)
	::box2D::common::math::B2Mat22 tMat;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",162)
	tMat = bA->m_xf->R;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",163)
	double r1X = (this->m_localAnchor1->x - bA->m_sweep->localCenter->x);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",164)
	double r1Y = (this->m_localAnchor1->y - bA->m_sweep->localCenter->y);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",165)
	double tX = ((tMat->col1->x * r1X) + (tMat->col2->x * r1Y));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",166)
	r1Y = ((tMat->col1->y * r1X) + (tMat->col2->y * r1Y));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",167)
	r1X = tX;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",169)
	tMat = bB->m_xf->R;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",170)
	double r2X = (this->m_localAnchor2->x - bB->m_sweep->localCenter->x);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",171)
	double r2Y = (this->m_localAnchor2->y - bB->m_sweep->localCenter->y);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",172)
	tX = ((tMat->col1->x * r2X) + (tMat->col2->x * r2Y));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",173)
	r2Y = ((tMat->col1->y * r2X) + (tMat->col2->y * r2Y));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",174)
	r2X = tX;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",177)
	double p1X = (bA->m_sweep->c->x + r1X);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",178)
	double p1Y = (bA->m_sweep->c->y + r1Y);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",180)
	double p2X = (bB->m_sweep->c->x + r2X);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",181)
	double p2Y = (bB->m_sweep->c->y + r2Y);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",183)
	double dX = (p2X - p1X);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",184)
	double dY = (p2Y - p1Y);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",186)
	::box2D::common::math::B2Vec2 axis = bA->getWorldVector(this->m_localXAxis1);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",188)
	::box2D::common::math::B2Vec2 v1 = bA->m_linearVelocity;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",189)
	::box2D::common::math::B2Vec2 v2 = bB->m_linearVelocity;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",190)
	double w1 = bA->m_angularVelocity;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",191)
	double w2 = bB->m_angularVelocity;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",196)
	double speed = (((dX * ((-(w1) * axis->y))) + (dY * ((w1 * axis->x)))) + (((axis->x * ((((v2->x + (-(w2) * r2Y)) - v1->x) - (-(w1) * r1Y)))) + (axis->y * ((((v2->y + (w2 * r2X)) - v1->y) - (w1 * r1X)))))));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",198)
	return speed;
}


HX_DEFINE_DYNAMIC_FUNC0(B2PrismaticJoint_obj,getJointSpeed,return )

bool B2PrismaticJoint_obj::isLimitEnabled( ){
	HX_SOURCE_PUSH("B2PrismaticJoint_obj::isLimitEnabled")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",205)
	return this->m_enableLimit;
}


HX_DEFINE_DYNAMIC_FUNC0(B2PrismaticJoint_obj,isLimitEnabled,return )

Void B2PrismaticJoint_obj::enableLimit( bool flag){
{
		HX_SOURCE_PUSH("B2PrismaticJoint_obj::enableLimit")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",213)
		this->m_bodyA->setAwake(true);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",214)
		this->m_bodyB->setAwake(true);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",215)
		this->m_enableLimit = flag;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2PrismaticJoint_obj,enableLimit,(void))

double B2PrismaticJoint_obj::getLowerLimit( ){
	HX_SOURCE_PUSH("B2PrismaticJoint_obj::getLowerLimit")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",221)
	return this->m_lowerTranslation;
}


HX_DEFINE_DYNAMIC_FUNC0(B2PrismaticJoint_obj,getLowerLimit,return )

double B2PrismaticJoint_obj::getUpperLimit( ){
	HX_SOURCE_PUSH("B2PrismaticJoint_obj::getUpperLimit")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",228)
	return this->m_upperTranslation;
}


HX_DEFINE_DYNAMIC_FUNC0(B2PrismaticJoint_obj,getUpperLimit,return )

Void B2PrismaticJoint_obj::setLimits( double lower,double upper){
{
		HX_SOURCE_PUSH("B2PrismaticJoint_obj::setLimits")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",237)
		this->m_bodyA->setAwake(true);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",238)
		this->m_bodyB->setAwake(true);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",239)
		this->m_lowerTranslation = lower;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",240)
		this->m_upperTranslation = upper;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(B2PrismaticJoint_obj,setLimits,(void))

bool B2PrismaticJoint_obj::isMotorEnabled( ){
	HX_SOURCE_PUSH("B2PrismaticJoint_obj::isMotorEnabled")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",246)
	return this->m_enableMotor;
}


HX_DEFINE_DYNAMIC_FUNC0(B2PrismaticJoint_obj,isMotorEnabled,return )

Void B2PrismaticJoint_obj::enableMotor( bool flag){
{
		HX_SOURCE_PUSH("B2PrismaticJoint_obj::enableMotor")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",254)
		this->m_bodyA->setAwake(true);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",255)
		this->m_bodyB->setAwake(true);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",256)
		this->m_enableMotor = flag;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2PrismaticJoint_obj,enableMotor,(void))

Void B2PrismaticJoint_obj::setMotorSpeed( double speed){
{
		HX_SOURCE_PUSH("B2PrismaticJoint_obj::setMotorSpeed")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",263)
		this->m_bodyA->setAwake(true);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",264)
		this->m_bodyB->setAwake(true);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",265)
		this->m_motorSpeed = speed;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2PrismaticJoint_obj,setMotorSpeed,(void))

double B2PrismaticJoint_obj::getMotorSpeed( ){
	HX_SOURCE_PUSH("B2PrismaticJoint_obj::getMotorSpeed")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",271)
	return this->m_motorSpeed;
}


HX_DEFINE_DYNAMIC_FUNC0(B2PrismaticJoint_obj,getMotorSpeed,return )

Void B2PrismaticJoint_obj::setMaxMotorForce( double force){
{
		HX_SOURCE_PUSH("B2PrismaticJoint_obj::setMaxMotorForce")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",280)
		this->m_bodyA->setAwake(true);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",281)
		this->m_bodyB->setAwake(true);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",282)
		this->m_maxMotorForce = force;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2PrismaticJoint_obj,setMaxMotorForce,(void))

double B2PrismaticJoint_obj::getMotorForce( ){
	HX_SOURCE_PUSH("B2PrismaticJoint_obj::getMotorForce")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",288)
	return this->m_motorImpulse;
}


HX_DEFINE_DYNAMIC_FUNC0(B2PrismaticJoint_obj,getMotorForce,return )

Void B2PrismaticJoint_obj::initVelocityConstraints( ::box2D::dynamics::B2TimeStep step){
{
		HX_SOURCE_PUSH("B2PrismaticJoint_obj::initVelocityConstraints")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",340)
		::box2D::dynamics::B2Body bA = this->m_bodyA;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",341)
		::box2D::dynamics::B2Body bB = this->m_bodyB;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",343)
		::box2D::common::math::B2Mat22 tMat;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",344)
		double tX;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",346)
		this->m_localCenterA->setV(bA->getLocalCenter());
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",347)
		this->m_localCenterB->setV(bB->getLocalCenter());
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",349)
		::box2D::common::math::B2Transform xf1 = bA->getTransform();
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",350)
		::box2D::common::math::B2Transform xf2 = bB->getTransform();
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",354)
		tMat = bA->m_xf->R;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",355)
		double r1X = (this->m_localAnchor1->x - this->m_localCenterA->x);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",356)
		double r1Y = (this->m_localAnchor1->y - this->m_localCenterA->y);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",357)
		tX = ((tMat->col1->x * r1X) + (tMat->col2->x * r1Y));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",358)
		r1Y = ((tMat->col1->y * r1X) + (tMat->col2->y * r1Y));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",359)
		r1X = tX;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",361)
		tMat = bB->m_xf->R;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",362)
		double r2X = (this->m_localAnchor2->x - this->m_localCenterB->x);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",363)
		double r2Y = (this->m_localAnchor2->y - this->m_localCenterB->y);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",364)
		tX = ((tMat->col1->x * r2X) + (tMat->col2->x * r2Y));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",365)
		r2Y = ((tMat->col1->y * r2X) + (tMat->col2->y * r2Y));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",366)
		r2X = tX;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",369)
		double dX = (((bB->m_sweep->c->x + r2X) - bA->m_sweep->c->x) - r1X);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",370)
		double dY = (((bB->m_sweep->c->y + r2Y) - bA->m_sweep->c->y) - r1Y);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",372)
		this->m_invMassA = bA->m_invMass;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",373)
		this->m_invMassB = bB->m_invMass;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",374)
		this->m_invIA = bA->m_invI;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",375)
		this->m_invIB = bB->m_invI;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",378)
		{
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",379)
			this->m_axis->setV(::box2D::common::math::B2Math_obj::mulMV(xf1->R,this->m_localXAxis1));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",381)
			this->m_a1 = ((((dX + r1X)) * this->m_axis->y) - (((dY + r1Y)) * this->m_axis->x));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",383)
			this->m_a2 = ((r2X * this->m_axis->y) - (r2Y * this->m_axis->x));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",385)
			this->m_motorMass = (((this->m_invMassA + this->m_invMassB) + ((this->m_invIA * this->m_a1) * this->m_a1)) + ((this->m_invIB * this->m_a2) * this->m_a2));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",386)
			if (((this->m_motorMass > 2.2250738585072014e-308))){
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",387)
				this->m_motorMass = (double(1.0) / double(this->m_motorMass));
			}
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",391)
		{
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",392)
			this->m_perp->setV(::box2D::common::math::B2Math_obj::mulMV(xf1->R,this->m_localYAxis1));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",394)
			this->m_s1 = ((((dX + r1X)) * this->m_perp->y) - (((dY + r1Y)) * this->m_perp->x));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",396)
			this->m_s2 = ((r2X * this->m_perp->y) - (r2Y * this->m_perp->x));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",398)
			double m1 = this->m_invMassA;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",399)
			double m2 = this->m_invMassB;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",400)
			double i1 = this->m_invIA;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",401)
			double i2 = this->m_invIB;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",403)
			this->m_K->col1->x = (((m1 + m2) + ((i1 * this->m_s1) * this->m_s1)) + ((i2 * this->m_s2) * this->m_s2));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",404)
			this->m_K->col1->y = ((i1 * this->m_s1) + (i2 * this->m_s2));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",405)
			this->m_K->col1->z = (((i1 * this->m_s1) * this->m_a1) + ((i2 * this->m_s2) * this->m_a2));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",406)
			this->m_K->col2->x = this->m_K->col1->y;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",407)
			this->m_K->col2->y = (i1 + i2);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",408)
			this->m_K->col2->z = ((i1 * this->m_a1) + (i2 * this->m_a2));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",409)
			this->m_K->col3->x = this->m_K->col1->z;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",410)
			this->m_K->col3->y = this->m_K->col2->z;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",411)
			this->m_K->col3->z = (((m1 + m2) + ((i1 * this->m_a1) * this->m_a1)) + ((i2 * this->m_a2) * this->m_a2));
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",415)
		if ((this->m_enableLimit)){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",418)
			double jointTransition = ((this->m_axis->x * dX) + (this->m_axis->y * dY));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",419)
			if (((::box2D::common::math::B2Math_obj::abs((this->m_upperTranslation - this->m_lowerTranslation)) < (2.0 * ::box2D::common::B2Settings_obj::b2_linearSlop)))){
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",420)
				this->m_limitState = ::box2D::dynamics::joints::B2Joint_obj::e_equalLimits;
			}
			else{
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",423)
				if (((jointTransition <= this->m_lowerTranslation))){
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",424)
					if (((this->m_limitState != ::box2D::dynamics::joints::B2Joint_obj::e_atLowerLimit))){
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",427)
						this->m_limitState = ::box2D::dynamics::joints::B2Joint_obj::e_atLowerLimit;
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",428)
						this->m_impulse->z = 0.0;
					}
				}
				else{
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",431)
					if (((jointTransition >= this->m_upperTranslation))){
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",432)
						if (((this->m_limitState != ::box2D::dynamics::joints::B2Joint_obj::e_atUpperLimit))){
							HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",435)
							this->m_limitState = ::box2D::dynamics::joints::B2Joint_obj::e_atUpperLimit;
							HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",436)
							this->m_impulse->z = 0.0;
						}
					}
					else{
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",441)
						this->m_limitState = ::box2D::dynamics::joints::B2Joint_obj::e_inactiveLimit;
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",442)
						this->m_impulse->z = 0.0;
					}
				}
			}
		}
		else{
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",446)
			this->m_limitState = ::box2D::dynamics::joints::B2Joint_obj::e_inactiveLimit;
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",450)
		if (((this->m_enableMotor == false))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",451)
			this->m_motorImpulse = 0.0;
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",455)
		if ((step->warmStarting)){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",458)
			hx::MultEq(this->m_impulse->x,step->dtRatio);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",459)
			hx::MultEq(this->m_impulse->y,step->dtRatio);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",460)
			hx::MultEq(this->m_motorImpulse,step->dtRatio);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",463)
			double PX = ((this->m_impulse->x * this->m_perp->x) + (((this->m_motorImpulse + this->m_impulse->z)) * this->m_axis->x));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",464)
			double PY = ((this->m_impulse->x * this->m_perp->y) + (((this->m_motorImpulse + this->m_impulse->z)) * this->m_axis->y));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",465)
			double L1 = (((this->m_impulse->x * this->m_s1) + this->m_impulse->y) + (((this->m_motorImpulse + this->m_impulse->z)) * this->m_a1));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",466)
			double L2 = (((this->m_impulse->x * this->m_s2) + this->m_impulse->y) + (((this->m_motorImpulse + this->m_impulse->z)) * this->m_a2));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",469)
			hx::SubEq(bA->m_linearVelocity->x,(this->m_invMassA * PX));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",470)
			hx::SubEq(bA->m_linearVelocity->y,(this->m_invMassA * PY));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",472)
			hx::SubEq(bA->m_angularVelocity,(this->m_invIA * L1));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",475)
			hx::AddEq(bB->m_linearVelocity->x,(this->m_invMassB * PX));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",476)
			hx::AddEq(bB->m_linearVelocity->y,(this->m_invMassB * PY));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",478)
			hx::AddEq(bB->m_angularVelocity,(this->m_invIB * L2));
		}
		else{
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",482)
			this->m_impulse->setZero();
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",483)
			this->m_motorImpulse = 0.0;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2PrismaticJoint_obj,initVelocityConstraints,(void))

Void B2PrismaticJoint_obj::solveVelocityConstraints( ::box2D::dynamics::B2TimeStep step){
{
		HX_SOURCE_PUSH("B2PrismaticJoint_obj::solveVelocityConstraints")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",488)
		::box2D::dynamics::B2Body bA = this->m_bodyA;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",489)
		::box2D::dynamics::B2Body bB = this->m_bodyB;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",491)
		::box2D::common::math::B2Vec2 v1 = bA->m_linearVelocity;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",492)
		double w1 = bA->m_angularVelocity;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",493)
		::box2D::common::math::B2Vec2 v2 = bB->m_linearVelocity;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",494)
		double w2 = bB->m_angularVelocity;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",496)
		double PX;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",497)
		double PY;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",498)
		double L1;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",499)
		double L2;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",502)
		if (((bool(this->m_enableMotor) && bool((this->m_limitState != ::box2D::dynamics::joints::B2Joint_obj::e_equalLimits))))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",505)
			double Cdot = ((((this->m_axis->x * ((v2->x - v1->x))) + (this->m_axis->y * ((v2->y - v1->y)))) + (this->m_a2 * w2)) - (this->m_a1 * w1));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",506)
			double impulse = (this->m_motorMass * ((this->m_motorSpeed - Cdot)));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",507)
			double oldImpulse = this->m_motorImpulse;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",508)
			double maxImpulse = (step->dt * this->m_maxMotorForce);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",509)
			this->m_motorImpulse = ::box2D::common::math::B2Math_obj::clamp((this->m_motorImpulse + impulse),-(maxImpulse),maxImpulse);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",510)
			impulse = (this->m_motorImpulse - oldImpulse);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",512)
			PX = (impulse * this->m_axis->x);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",513)
			PY = (impulse * this->m_axis->y);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",514)
			L1 = (impulse * this->m_a1);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",515)
			L2 = (impulse * this->m_a2);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",517)
			hx::SubEq(v1->x,(this->m_invMassA * PX));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",518)
			hx::SubEq(v1->y,(this->m_invMassA * PY));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",519)
			hx::SubEq(w1,(this->m_invIA * L1));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",521)
			hx::AddEq(v2->x,(this->m_invMassB * PX));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",522)
			hx::AddEq(v2->y,(this->m_invMassB * PY));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",523)
			hx::AddEq(w2,(this->m_invIB * L2));
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",527)
		double Cdot1X = ((((this->m_perp->x * ((v2->x - v1->x))) + (this->m_perp->y * ((v2->y - v1->y)))) + (this->m_s2 * w2)) - (this->m_s1 * w1));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",528)
		double Cdot1Y = (w2 - w1);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",530)
		if (((bool(this->m_enableLimit) && bool((this->m_limitState != ::box2D::dynamics::joints::B2Joint_obj::e_inactiveLimit))))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",534)
			double Cdot2 = ((((this->m_axis->x * ((v2->x - v1->x))) + (this->m_axis->y * ((v2->y - v1->y)))) + (this->m_a2 * w2)) - (this->m_a1 * w1));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",536)
			::box2D::common::math::B2Vec3 f1 = this->m_impulse->copy();
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",537)
			::box2D::common::math::B2Vec3 df = this->m_K->solve33(::box2D::common::math::B2Vec3_obj::__new(null(),null(),null()),-(Cdot1X),-(Cdot1Y),-(Cdot2));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",539)
			this->m_impulse->add(df);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",541)
			if (((this->m_limitState == ::box2D::dynamics::joints::B2Joint_obj::e_atLowerLimit))){
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",542)
				this->m_impulse->z = ::box2D::common::math::B2Math_obj::max(this->m_impulse->z,0.0);
			}
			else{
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",545)
				if (((this->m_limitState == ::box2D::dynamics::joints::B2Joint_obj::e_atUpperLimit))){
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",546)
					this->m_impulse->z = ::box2D::common::math::B2Math_obj::min(this->m_impulse->z,0.0);
				}
			}
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",552)
			double bX = (-(Cdot1X) - (((this->m_impulse->z - f1->z)) * this->m_K->col3->x));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",553)
			double bY = (-(Cdot1Y) - (((this->m_impulse->z - f1->z)) * this->m_K->col3->y));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",554)
			::box2D::common::math::B2Vec2 f2r = this->m_K->solve22(::box2D::common::math::B2Vec2_obj::__new(null(),null()),bX,bY);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",555)
			hx::AddEq(f2r->x,f1->x);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",556)
			hx::AddEq(f2r->y,f1->y);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",557)
			this->m_impulse->x = f2r->x;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",558)
			this->m_impulse->y = f2r->y;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",560)
			df->x = (this->m_impulse->x - f1->x);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",561)
			df->y = (this->m_impulse->y - f1->y);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",562)
			df->z = (this->m_impulse->z - f1->z);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",564)
			PX = ((df->x * this->m_perp->x) + (df->z * this->m_axis->x));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",565)
			PY = ((df->x * this->m_perp->y) + (df->z * this->m_axis->y));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",566)
			L1 = (((df->x * this->m_s1) + df->y) + (df->z * this->m_a1));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",567)
			L2 = (((df->x * this->m_s2) + df->y) + (df->z * this->m_a2));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",569)
			hx::SubEq(v1->x,(this->m_invMassA * PX));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",570)
			hx::SubEq(v1->y,(this->m_invMassA * PY));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",571)
			hx::SubEq(w1,(this->m_invIA * L1));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",573)
			hx::AddEq(v2->x,(this->m_invMassB * PX));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",574)
			hx::AddEq(v2->y,(this->m_invMassB * PY));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",575)
			hx::AddEq(w2,(this->m_invIB * L2));
		}
		else{
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",580)
			::box2D::common::math::B2Vec2 df2 = this->m_K->solve22(::box2D::common::math::B2Vec2_obj::__new(null(),null()),-(Cdot1X),-(Cdot1Y));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",581)
			hx::AddEq(this->m_impulse->x,df2->x);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",582)
			hx::AddEq(this->m_impulse->y,df2->y);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",584)
			PX = (df2->x * this->m_perp->x);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",585)
			PY = (df2->x * this->m_perp->y);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",586)
			L1 = ((df2->x * this->m_s1) + df2->y);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",587)
			L2 = ((df2->x * this->m_s2) + df2->y);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",589)
			hx::SubEq(v1->x,(this->m_invMassA * PX));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",590)
			hx::SubEq(v1->y,(this->m_invMassA * PY));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",591)
			hx::SubEq(w1,(this->m_invIA * L1));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",593)
			hx::AddEq(v2->x,(this->m_invMassB * PX));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",594)
			hx::AddEq(v2->y,(this->m_invMassB * PY));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",595)
			hx::AddEq(w2,(this->m_invIB * L2));
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",598)
		bA->m_linearVelocity->setV(v1);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",599)
		bA->m_angularVelocity = w1;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",600)
		bB->m_linearVelocity->setV(v2);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",601)
		bB->m_angularVelocity = w2;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2PrismaticJoint_obj,solveVelocityConstraints,(void))

bool B2PrismaticJoint_obj::solvePositionConstraints( double baumgarte){
	HX_SOURCE_PUSH("B2PrismaticJoint_obj::solvePositionConstraints")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",609)
	double limitC;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",610)
	double oldLimitImpulse;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",612)
	::box2D::dynamics::B2Body bA = this->m_bodyA;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",613)
	::box2D::dynamics::B2Body bB = this->m_bodyB;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",615)
	::box2D::common::math::B2Vec2 c1 = bA->m_sweep->c;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",616)
	double a1 = bA->m_sweep->a;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",618)
	::box2D::common::math::B2Vec2 c2 = bB->m_sweep->c;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",619)
	double a2 = bB->m_sweep->a;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",621)
	::box2D::common::math::B2Mat22 tMat;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",622)
	double tX;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",624)
	double m1;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",625)
	double m2;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",626)
	double i1;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",627)
	double i2;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",630)
	double linearError = 0.0;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",631)
	double angularError = 0.0;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",632)
	bool active = false;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",633)
	double C2 = 0.0;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",635)
	::box2D::common::math::B2Mat22 R1 = ::box2D::common::math::B2Mat22_obj::fromAngle(a1);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",636)
	::box2D::common::math::B2Mat22 R2 = ::box2D::common::math::B2Mat22_obj::fromAngle(a2);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",639)
	tMat = R1;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",640)
	double r1X = (this->m_localAnchor1->x - this->m_localCenterA->x);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",641)
	double r1Y = (this->m_localAnchor1->y - this->m_localCenterA->y);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",642)
	tX = ((tMat->col1->x * r1X) + (tMat->col2->x * r1Y));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",643)
	r1Y = ((tMat->col1->y * r1X) + (tMat->col2->y * r1Y));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",644)
	r1X = tX;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",646)
	tMat = R2;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",647)
	double r2X = (this->m_localAnchor2->x - this->m_localCenterB->x);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",648)
	double r2Y = (this->m_localAnchor2->y - this->m_localCenterB->y);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",649)
	tX = ((tMat->col1->x * r2X) + (tMat->col2->x * r2Y));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",650)
	r2Y = ((tMat->col1->y * r2X) + (tMat->col2->y * r2Y));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",651)
	r2X = tX;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",653)
	double dX = (((c2->x + r2X) - c1->x) - r1X);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",654)
	double dY = (((c2->y + r2Y) - c1->y) - r1Y);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",656)
	if ((this->m_enableLimit)){
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",658)
		this->m_axis = ::box2D::common::math::B2Math_obj::mulMV(R1,this->m_localXAxis1);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",661)
		this->m_a1 = ((((dX + r1X)) * this->m_axis->y) - (((dY + r1Y)) * this->m_axis->x));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",663)
		this->m_a2 = ((r2X * this->m_axis->y) - (r2Y * this->m_axis->x));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",665)
		double translation = ((this->m_axis->x * dX) + (this->m_axis->y * dY));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",666)
		if (((::box2D::common::math::B2Math_obj::abs((this->m_upperTranslation - this->m_lowerTranslation)) < (2.0 * ::box2D::common::B2Settings_obj::b2_linearSlop)))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",669)
			C2 = ::box2D::common::math::B2Math_obj::clamp(translation,-(::box2D::common::B2Settings_obj::b2_maxLinearCorrection),::box2D::common::B2Settings_obj::b2_maxLinearCorrection);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",670)
			linearError = ::box2D::common::math::B2Math_obj::abs(translation);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",671)
			active = true;
		}
		else{
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",673)
			if (((translation <= this->m_lowerTranslation))){
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",676)
				C2 = ::box2D::common::math::B2Math_obj::clamp(((translation - this->m_lowerTranslation) + ::box2D::common::B2Settings_obj::b2_linearSlop),-(::box2D::common::B2Settings_obj::b2_maxLinearCorrection),0.0);
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",677)
				linearError = (this->m_lowerTranslation - translation);
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",678)
				active = true;
			}
			else{
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",680)
				if (((translation >= this->m_upperTranslation))){
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",683)
					C2 = ::box2D::common::math::B2Math_obj::clamp(((translation - this->m_upperTranslation) + ::box2D::common::B2Settings_obj::b2_linearSlop),0.0,::box2D::common::B2Settings_obj::b2_maxLinearCorrection);
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",684)
					linearError = (translation - this->m_upperTranslation);
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",685)
					active = true;
				}
			}
		}
	}
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",689)
	this->m_perp = ::box2D::common::math::B2Math_obj::mulMV(R1,this->m_localYAxis1);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",692)
	this->m_s1 = ((((dX + r1X)) * this->m_perp->y) - (((dY + r1Y)) * this->m_perp->x));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",694)
	this->m_s2 = ((r2X * this->m_perp->y) - (r2Y * this->m_perp->x));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",696)
	::box2D::common::math::B2Vec3 impulse = ::box2D::common::math::B2Vec3_obj::__new(null(),null(),null());
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",697)
	double C1X = ((this->m_perp->x * dX) + (this->m_perp->y * dY));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",698)
	double C1Y = ((a2 - a1) - this->m_refAngle);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",700)
	linearError = ::box2D::common::math::B2Math_obj::max(linearError,::box2D::common::math::B2Math_obj::abs(C1X));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",701)
	angularError = ::box2D::common::math::B2Math_obj::abs(C1Y);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",703)
	if ((active)){
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",705)
		m1 = this->m_invMassA;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",706)
		m2 = this->m_invMassB;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",707)
		i1 = this->m_invIA;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",708)
		i2 = this->m_invIB;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",710)
		this->m_K->col1->x = (((m1 + m2) + ((i1 * this->m_s1) * this->m_s1)) + ((i2 * this->m_s2) * this->m_s2));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",711)
		this->m_K->col1->y = ((i1 * this->m_s1) + (i2 * this->m_s2));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",712)
		this->m_K->col1->z = (((i1 * this->m_s1) * this->m_a1) + ((i2 * this->m_s2) * this->m_a2));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",713)
		this->m_K->col2->x = this->m_K->col1->y;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",714)
		this->m_K->col2->y = (i1 + i2);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",715)
		this->m_K->col2->z = ((i1 * this->m_a1) + (i2 * this->m_a2));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",716)
		this->m_K->col3->x = this->m_K->col1->z;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",717)
		this->m_K->col3->y = this->m_K->col2->z;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",718)
		this->m_K->col3->z = (((m1 + m2) + ((i1 * this->m_a1) * this->m_a1)) + ((i2 * this->m_a2) * this->m_a2));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",720)
		this->m_K->solve33(impulse,-(C1X),-(C1Y),-(C2));
	}
	else{
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",724)
		m1 = this->m_invMassA;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",725)
		m2 = this->m_invMassB;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",726)
		i1 = this->m_invIA;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",727)
		i2 = this->m_invIB;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",729)
		double k11 = (((m1 + m2) + ((i1 * this->m_s1) * this->m_s1)) + ((i2 * this->m_s2) * this->m_s2));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",730)
		double k12 = ((i1 * this->m_s1) + (i2 * this->m_s2));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",731)
		double k22 = (i1 + i2);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",733)
		this->m_K->col1->set(k11,k12,0.0);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",734)
		this->m_K->col2->set(k12,k22,0.0);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",736)
		::box2D::common::math::B2Vec2 impulse1 = this->m_K->solve22(::box2D::common::math::B2Vec2_obj::__new(null(),null()),-(C1X),-(C1Y));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",737)
		impulse->x = impulse1->x;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",738)
		impulse->y = impulse1->y;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",739)
		impulse->z = 0.0;
	}
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",742)
	double PX = ((impulse->x * this->m_perp->x) + (impulse->z * this->m_axis->x));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",743)
	double PY = ((impulse->x * this->m_perp->y) + (impulse->z * this->m_axis->y));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",744)
	double L1 = (((impulse->x * this->m_s1) + impulse->y) + (impulse->z * this->m_a1));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",745)
	double L2 = (((impulse->x * this->m_s2) + impulse->y) + (impulse->z * this->m_a2));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",747)
	hx::SubEq(c1->x,(this->m_invMassA * PX));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",748)
	hx::SubEq(c1->y,(this->m_invMassA * PY));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",749)
	hx::SubEq(a1,(this->m_invIA * L1));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",751)
	hx::AddEq(c2->x,(this->m_invMassB * PX));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",752)
	hx::AddEq(c2->y,(this->m_invMassB * PY));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",753)
	hx::AddEq(a2,(this->m_invIB * L2));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",757)
	bA->m_sweep->a = a1;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",759)
	bB->m_sweep->a = a2;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",760)
	bA->synchronizeTransform();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",761)
	bB->synchronizeTransform();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PrismaticJoint.hx",763)
	return (bool((linearError <= ::box2D::common::B2Settings_obj::b2_linearSlop)) && bool((angularError <= ::box2D::common::B2Settings_obj::b2_angularSlop)));
}


HX_DEFINE_DYNAMIC_FUNC1(B2PrismaticJoint_obj,solvePositionConstraints,return )


B2PrismaticJoint_obj::B2PrismaticJoint_obj()
{
}

void B2PrismaticJoint_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(B2PrismaticJoint);
	HX_MARK_MEMBER_NAME(m_localAnchor1,"m_localAnchor1");
	HX_MARK_MEMBER_NAME(m_localAnchor2,"m_localAnchor2");
	HX_MARK_MEMBER_NAME(m_localXAxis1,"m_localXAxis1");
	HX_MARK_MEMBER_NAME(m_localYAxis1,"m_localYAxis1");
	HX_MARK_MEMBER_NAME(m_refAngle,"m_refAngle");
	HX_MARK_MEMBER_NAME(m_axis,"m_axis");
	HX_MARK_MEMBER_NAME(m_perp,"m_perp");
	HX_MARK_MEMBER_NAME(m_s1,"m_s1");
	HX_MARK_MEMBER_NAME(m_s2,"m_s2");
	HX_MARK_MEMBER_NAME(m_a1,"m_a1");
	HX_MARK_MEMBER_NAME(m_a2,"m_a2");
	HX_MARK_MEMBER_NAME(m_K,"m_K");
	HX_MARK_MEMBER_NAME(m_impulse,"m_impulse");
	HX_MARK_MEMBER_NAME(m_motorMass,"m_motorMass");
	HX_MARK_MEMBER_NAME(m_motorImpulse,"m_motorImpulse");
	HX_MARK_MEMBER_NAME(m_lowerTranslation,"m_lowerTranslation");
	HX_MARK_MEMBER_NAME(m_upperTranslation,"m_upperTranslation");
	HX_MARK_MEMBER_NAME(m_maxMotorForce,"m_maxMotorForce");
	HX_MARK_MEMBER_NAME(m_motorSpeed,"m_motorSpeed");
	HX_MARK_MEMBER_NAME(m_enableLimit,"m_enableLimit");
	HX_MARK_MEMBER_NAME(m_enableMotor,"m_enableMotor");
	HX_MARK_MEMBER_NAME(m_limitState,"m_limitState");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic B2PrismaticJoint_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"m_K") ) { return m_K; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"m_s1") ) { return m_s1; }
		if (HX_FIELD_EQ(inName,"m_s2") ) { return m_s2; }
		if (HX_FIELD_EQ(inName,"m_a1") ) { return m_a1; }
		if (HX_FIELD_EQ(inName,"m_a2") ) { return m_a2; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"m_axis") ) { return m_axis; }
		if (HX_FIELD_EQ(inName,"m_perp") ) { return m_perp; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"setLimits") ) { return setLimits_dyn(); }
		if (HX_FIELD_EQ(inName,"m_impulse") ) { return m_impulse; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"getAnchorA") ) { return getAnchorA_dyn(); }
		if (HX_FIELD_EQ(inName,"getAnchorB") ) { return getAnchorB_dyn(); }
		if (HX_FIELD_EQ(inName,"m_refAngle") ) { return m_refAngle; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"enableLimit") ) { return enableLimit_dyn(); }
		if (HX_FIELD_EQ(inName,"enableMotor") ) { return enableMotor_dyn(); }
		if (HX_FIELD_EQ(inName,"m_motorMass") ) { return m_motorMass; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"m_motorSpeed") ) { return m_motorSpeed; }
		if (HX_FIELD_EQ(inName,"m_limitState") ) { return m_limitState; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"getJointSpeed") ) { return getJointSpeed_dyn(); }
		if (HX_FIELD_EQ(inName,"getLowerLimit") ) { return getLowerLimit_dyn(); }
		if (HX_FIELD_EQ(inName,"getUpperLimit") ) { return getUpperLimit_dyn(); }
		if (HX_FIELD_EQ(inName,"setMotorSpeed") ) { return setMotorSpeed_dyn(); }
		if (HX_FIELD_EQ(inName,"getMotorSpeed") ) { return getMotorSpeed_dyn(); }
		if (HX_FIELD_EQ(inName,"getMotorForce") ) { return getMotorForce_dyn(); }
		if (HX_FIELD_EQ(inName,"m_localXAxis1") ) { return m_localXAxis1; }
		if (HX_FIELD_EQ(inName,"m_localYAxis1") ) { return m_localYAxis1; }
		if (HX_FIELD_EQ(inName,"m_enableLimit") ) { return m_enableLimit; }
		if (HX_FIELD_EQ(inName,"m_enableMotor") ) { return m_enableMotor; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"isLimitEnabled") ) { return isLimitEnabled_dyn(); }
		if (HX_FIELD_EQ(inName,"isMotorEnabled") ) { return isMotorEnabled_dyn(); }
		if (HX_FIELD_EQ(inName,"m_localAnchor1") ) { return m_localAnchor1; }
		if (HX_FIELD_EQ(inName,"m_localAnchor2") ) { return m_localAnchor2; }
		if (HX_FIELD_EQ(inName,"m_motorImpulse") ) { return m_motorImpulse; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"m_maxMotorForce") ) { return m_maxMotorForce; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"getReactionForce") ) { return getReactionForce_dyn(); }
		if (HX_FIELD_EQ(inName,"setMaxMotorForce") ) { return setMaxMotorForce_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"getReactionTorque") ) { return getReactionTorque_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"m_lowerTranslation") ) { return m_lowerTranslation; }
		if (HX_FIELD_EQ(inName,"m_upperTranslation") ) { return m_upperTranslation; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"getJointTranslation") ) { return getJointTranslation_dyn(); }
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

Dynamic B2PrismaticJoint_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"m_K") ) { m_K=inValue.Cast< ::box2D::common::math::B2Mat33 >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"m_s1") ) { m_s1=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_s2") ) { m_s2=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_a1") ) { m_a1=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_a2") ) { m_a2=inValue.Cast< double >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"m_axis") ) { m_axis=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_perp") ) { m_perp=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"m_impulse") ) { m_impulse=inValue.Cast< ::box2D::common::math::B2Vec3 >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"m_refAngle") ) { m_refAngle=inValue.Cast< double >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"m_motorMass") ) { m_motorMass=inValue.Cast< double >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"m_motorSpeed") ) { m_motorSpeed=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_limitState") ) { m_limitState=inValue.Cast< int >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"m_localXAxis1") ) { m_localXAxis1=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_localYAxis1") ) { m_localYAxis1=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_enableLimit") ) { m_enableLimit=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_enableMotor") ) { m_enableMotor=inValue.Cast< bool >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"m_localAnchor1") ) { m_localAnchor1=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_localAnchor2") ) { m_localAnchor2=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_motorImpulse") ) { m_motorImpulse=inValue.Cast< double >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"m_maxMotorForce") ) { m_maxMotorForce=inValue.Cast< double >(); return inValue; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"m_lowerTranslation") ) { m_lowerTranslation=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_upperTranslation") ) { m_upperTranslation=inValue.Cast< double >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void B2PrismaticJoint_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("m_localAnchor1"));
	outFields->push(HX_CSTRING("m_localAnchor2"));
	outFields->push(HX_CSTRING("m_localXAxis1"));
	outFields->push(HX_CSTRING("m_localYAxis1"));
	outFields->push(HX_CSTRING("m_refAngle"));
	outFields->push(HX_CSTRING("m_axis"));
	outFields->push(HX_CSTRING("m_perp"));
	outFields->push(HX_CSTRING("m_s1"));
	outFields->push(HX_CSTRING("m_s2"));
	outFields->push(HX_CSTRING("m_a1"));
	outFields->push(HX_CSTRING("m_a2"));
	outFields->push(HX_CSTRING("m_K"));
	outFields->push(HX_CSTRING("m_impulse"));
	outFields->push(HX_CSTRING("m_motorMass"));
	outFields->push(HX_CSTRING("m_motorImpulse"));
	outFields->push(HX_CSTRING("m_lowerTranslation"));
	outFields->push(HX_CSTRING("m_upperTranslation"));
	outFields->push(HX_CSTRING("m_maxMotorForce"));
	outFields->push(HX_CSTRING("m_motorSpeed"));
	outFields->push(HX_CSTRING("m_enableLimit"));
	outFields->push(HX_CSTRING("m_enableMotor"));
	outFields->push(HX_CSTRING("m_limitState"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("getAnchorA"),
	HX_CSTRING("getAnchorB"),
	HX_CSTRING("getReactionForce"),
	HX_CSTRING("getReactionTorque"),
	HX_CSTRING("getJointTranslation"),
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
	HX_CSTRING("setMaxMotorForce"),
	HX_CSTRING("getMotorForce"),
	HX_CSTRING("initVelocityConstraints"),
	HX_CSTRING("solveVelocityConstraints"),
	HX_CSTRING("solvePositionConstraints"),
	HX_CSTRING("m_localAnchor1"),
	HX_CSTRING("m_localAnchor2"),
	HX_CSTRING("m_localXAxis1"),
	HX_CSTRING("m_localYAxis1"),
	HX_CSTRING("m_refAngle"),
	HX_CSTRING("m_axis"),
	HX_CSTRING("m_perp"),
	HX_CSTRING("m_s1"),
	HX_CSTRING("m_s2"),
	HX_CSTRING("m_a1"),
	HX_CSTRING("m_a2"),
	HX_CSTRING("m_K"),
	HX_CSTRING("m_impulse"),
	HX_CSTRING("m_motorMass"),
	HX_CSTRING("m_motorImpulse"),
	HX_CSTRING("m_lowerTranslation"),
	HX_CSTRING("m_upperTranslation"),
	HX_CSTRING("m_maxMotorForce"),
	HX_CSTRING("m_motorSpeed"),
	HX_CSTRING("m_enableLimit"),
	HX_CSTRING("m_enableMotor"),
	HX_CSTRING("m_limitState"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class B2PrismaticJoint_obj::__mClass;

void B2PrismaticJoint_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.dynamics.joints.B2PrismaticJoint"), hx::TCanCast< B2PrismaticJoint_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void B2PrismaticJoint_obj::__boot()
{
}

} // end namespace box2D
} // end namespace dynamics
} // end namespace joints
