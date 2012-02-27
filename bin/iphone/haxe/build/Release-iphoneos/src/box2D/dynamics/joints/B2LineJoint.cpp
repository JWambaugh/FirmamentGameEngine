#include <hxcpp.h>

#ifndef INCLUDED_box2D_common_B2Settings
#include <box2D/common/B2Settings.h>
#endif
#ifndef INCLUDED_box2D_common_math_B2Mat22
#include <box2D/common/math/B2Mat22.h>
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
#ifndef INCLUDED_box2D_dynamics_joints_B2LineJoint
#include <box2D/dynamics/joints/B2LineJoint.h>
#endif
#ifndef INCLUDED_box2D_dynamics_joints_B2LineJointDef
#include <box2D/dynamics/joints/B2LineJointDef.h>
#endif
namespace box2D{
namespace dynamics{
namespace joints{

Void B2LineJoint_obj::__construct(::box2D::dynamics::joints::B2LineJointDef def)
{
{
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",298)
	super::__construct(def);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",300)
	this->m_localAnchor1 = ::box2D::common::math::B2Vec2_obj::__new(null(),null());
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",301)
	this->m_localAnchor2 = ::box2D::common::math::B2Vec2_obj::__new(null(),null());
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",302)
	this->m_localXAxis1 = ::box2D::common::math::B2Vec2_obj::__new(null(),null());
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",303)
	this->m_localYAxis1 = ::box2D::common::math::B2Vec2_obj::__new(null(),null());
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",305)
	this->m_axis = ::box2D::common::math::B2Vec2_obj::__new(null(),null());
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",306)
	this->m_perp = ::box2D::common::math::B2Vec2_obj::__new(null(),null());
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",308)
	this->m_K = ::box2D::common::math::B2Mat22_obj::__new();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",309)
	this->m_impulse = ::box2D::common::math::B2Vec2_obj::__new(null(),null());
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",312)
	::box2D::common::math::B2Mat22 tMat;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",313)
	double tX;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",314)
	double tY;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",316)
	this->m_localAnchor1->setV(def->localAnchorA);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",317)
	this->m_localAnchor2->setV(def->localAnchorB);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",318)
	this->m_localXAxis1->setV(def->localAxisA);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",321)
	this->m_localYAxis1->x = -(this->m_localXAxis1->y);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",322)
	this->m_localYAxis1->y = this->m_localXAxis1->x;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",324)
	this->m_impulse->setZero();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",325)
	this->m_motorMass = 0.0;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",326)
	this->m_motorImpulse = 0.0;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",328)
	this->m_lowerTranslation = def->lowerTranslation;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",329)
	this->m_upperTranslation = def->upperTranslation;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",330)
	this->m_maxMotorForce = def->maxMotorForce;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",331)
	this->m_motorSpeed = def->motorSpeed;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",332)
	this->m_enableLimit = def->enableLimit;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",333)
	this->m_enableMotor = def->enableMotor;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",334)
	this->m_limitState = ::box2D::dynamics::joints::B2Joint_obj::e_inactiveLimit;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",336)
	this->m_axis->setZero();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",337)
	this->m_perp->setZero();
}
;
	return null();
}

B2LineJoint_obj::~B2LineJoint_obj() { }

Dynamic B2LineJoint_obj::__CreateEmpty() { return  new B2LineJoint_obj; }
hx::ObjectPtr< B2LineJoint_obj > B2LineJoint_obj::__new(::box2D::dynamics::joints::B2LineJointDef def)
{  hx::ObjectPtr< B2LineJoint_obj > result = new B2LineJoint_obj();
	result->__construct(def);
	return result;}

Dynamic B2LineJoint_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2LineJoint_obj > result = new B2LineJoint_obj();
	result->__construct(inArgs[0]);
	return result;}

::box2D::common::math::B2Vec2 B2LineJoint_obj::getAnchorA( ){
	HX_SOURCE_PUSH("B2LineJoint_obj::getAnchorA")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",101)
	return this->m_bodyA->getWorldPoint(this->m_localAnchor1);
}


HX_DEFINE_DYNAMIC_FUNC0(B2LineJoint_obj,getAnchorA,return )

::box2D::common::math::B2Vec2 B2LineJoint_obj::getAnchorB( ){
	HX_SOURCE_PUSH("B2LineJoint_obj::getAnchorB")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",105)
	return this->m_bodyB->getWorldPoint(this->m_localAnchor2);
}


HX_DEFINE_DYNAMIC_FUNC0(B2LineJoint_obj,getAnchorB,return )

::box2D::common::math::B2Vec2 B2LineJoint_obj::getReactionForce( double inv_dt){
	HX_SOURCE_PUSH("B2LineJoint_obj::getReactionForce")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",110)
	return ::box2D::common::math::B2Vec2_obj::__new((inv_dt * (((this->m_impulse->x * this->m_perp->x) + (((this->m_motorImpulse + this->m_impulse->y)) * this->m_axis->x)))),(inv_dt * (((this->m_impulse->x * this->m_perp->y) + (((this->m_motorImpulse + this->m_impulse->y)) * this->m_axis->y)))));
}


HX_DEFINE_DYNAMIC_FUNC1(B2LineJoint_obj,getReactionForce,return )

double B2LineJoint_obj::getReactionTorque( double inv_dt){
	HX_SOURCE_PUSH("B2LineJoint_obj::getReactionTorque")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",118)
	return (inv_dt * this->m_impulse->y);
}


HX_DEFINE_DYNAMIC_FUNC1(B2LineJoint_obj,getReactionTorque,return )

double B2LineJoint_obj::getJointTranslation( ){
	HX_SOURCE_PUSH("B2LineJoint_obj::getJointTranslation")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",126)
	::box2D::dynamics::B2Body bA = this->m_bodyA;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",127)
	::box2D::dynamics::B2Body bB = this->m_bodyB;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",129)
	::box2D::common::math::B2Mat22 tMat;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",131)
	::box2D::common::math::B2Vec2 p1 = bA->getWorldPoint(this->m_localAnchor1);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",132)
	::box2D::common::math::B2Vec2 p2 = bB->getWorldPoint(this->m_localAnchor2);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",134)
	double dX = (p2->x - p1->x);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",135)
	double dY = (p2->y - p1->y);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",137)
	::box2D::common::math::B2Vec2 axis = bA->getWorldVector(this->m_localXAxis1);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",140)
	double translation = ((axis->x * dX) + (axis->y * dY));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",141)
	return translation;
}


HX_DEFINE_DYNAMIC_FUNC0(B2LineJoint_obj,getJointTranslation,return )

double B2LineJoint_obj::getJointSpeed( ){
	HX_SOURCE_PUSH("B2LineJoint_obj::getJointSpeed")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",148)
	::box2D::dynamics::B2Body bA = this->m_bodyA;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",149)
	::box2D::dynamics::B2Body bB = this->m_bodyB;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",151)
	::box2D::common::math::B2Mat22 tMat;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",154)
	tMat = bA->m_xf->R;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",155)
	double r1X = (this->m_localAnchor1->x - bA->m_sweep->localCenter->x);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",156)
	double r1Y = (this->m_localAnchor1->y - bA->m_sweep->localCenter->y);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",157)
	double tX = ((tMat->col1->x * r1X) + (tMat->col2->x * r1Y));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",158)
	r1Y = ((tMat->col1->y * r1X) + (tMat->col2->y * r1Y));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",159)
	r1X = tX;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",161)
	tMat = bB->m_xf->R;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",162)
	double r2X = (this->m_localAnchor2->x - bB->m_sweep->localCenter->x);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",163)
	double r2Y = (this->m_localAnchor2->y - bB->m_sweep->localCenter->y);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",164)
	tX = ((tMat->col1->x * r2X) + (tMat->col2->x * r2Y));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",165)
	r2Y = ((tMat->col1->y * r2X) + (tMat->col2->y * r2Y));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",166)
	r2X = tX;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",169)
	double p1X = (bA->m_sweep->c->x + r1X);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",170)
	double p1Y = (bA->m_sweep->c->y + r1Y);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",172)
	double p2X = (bB->m_sweep->c->x + r2X);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",173)
	double p2Y = (bB->m_sweep->c->y + r2Y);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",175)
	double dX = (p2X - p1X);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",176)
	double dY = (p2Y - p1Y);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",178)
	::box2D::common::math::B2Vec2 axis = bA->getWorldVector(this->m_localXAxis1);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",180)
	::box2D::common::math::B2Vec2 v1 = bA->m_linearVelocity;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",181)
	::box2D::common::math::B2Vec2 v2 = bB->m_linearVelocity;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",182)
	double w1 = bA->m_angularVelocity;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",183)
	double w2 = bB->m_angularVelocity;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",188)
	double speed = (((dX * ((-(w1) * axis->y))) + (dY * ((w1 * axis->x)))) + (((axis->x * ((((v2->x + (-(w2) * r2Y)) - v1->x) - (-(w1) * r1Y)))) + (axis->y * ((((v2->y + (w2 * r2X)) - v1->y) - (w1 * r1X)))))));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",190)
	return speed;
}


HX_DEFINE_DYNAMIC_FUNC0(B2LineJoint_obj,getJointSpeed,return )

bool B2LineJoint_obj::isLimitEnabled( ){
	HX_SOURCE_PUSH("B2LineJoint_obj::isLimitEnabled")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",197)
	return this->m_enableLimit;
}


HX_DEFINE_DYNAMIC_FUNC0(B2LineJoint_obj,isLimitEnabled,return )

Void B2LineJoint_obj::enableLimit( bool flag){
{
		HX_SOURCE_PUSH("B2LineJoint_obj::enableLimit")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",205)
		this->m_bodyA->setAwake(true);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",206)
		this->m_bodyB->setAwake(true);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",207)
		this->m_enableLimit = flag;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2LineJoint_obj,enableLimit,(void))

double B2LineJoint_obj::getLowerLimit( ){
	HX_SOURCE_PUSH("B2LineJoint_obj::getLowerLimit")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",213)
	return this->m_lowerTranslation;
}


HX_DEFINE_DYNAMIC_FUNC0(B2LineJoint_obj,getLowerLimit,return )

double B2LineJoint_obj::getUpperLimit( ){
	HX_SOURCE_PUSH("B2LineJoint_obj::getUpperLimit")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",220)
	return this->m_upperTranslation;
}


HX_DEFINE_DYNAMIC_FUNC0(B2LineJoint_obj,getUpperLimit,return )

Void B2LineJoint_obj::setLimits( double lower,double upper){
{
		HX_SOURCE_PUSH("B2LineJoint_obj::setLimits")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",229)
		this->m_bodyA->setAwake(true);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",230)
		this->m_bodyB->setAwake(true);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",231)
		this->m_lowerTranslation = lower;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",232)
		this->m_upperTranslation = upper;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(B2LineJoint_obj,setLimits,(void))

bool B2LineJoint_obj::isMotorEnabled( ){
	HX_SOURCE_PUSH("B2LineJoint_obj::isMotorEnabled")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",238)
	return this->m_enableMotor;
}


HX_DEFINE_DYNAMIC_FUNC0(B2LineJoint_obj,isMotorEnabled,return )

Void B2LineJoint_obj::enableMotor( bool flag){
{
		HX_SOURCE_PUSH("B2LineJoint_obj::enableMotor")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",246)
		this->m_bodyA->setAwake(true);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",247)
		this->m_bodyB->setAwake(true);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",248)
		this->m_enableMotor = flag;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2LineJoint_obj,enableMotor,(void))

Void B2LineJoint_obj::setMotorSpeed( double speed){
{
		HX_SOURCE_PUSH("B2LineJoint_obj::setMotorSpeed")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",255)
		this->m_bodyA->setAwake(true);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",256)
		this->m_bodyB->setAwake(true);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",257)
		this->m_motorSpeed = speed;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2LineJoint_obj,setMotorSpeed,(void))

double B2LineJoint_obj::getMotorSpeed( ){
	HX_SOURCE_PUSH("B2LineJoint_obj::getMotorSpeed")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",263)
	return this->m_motorSpeed;
}


HX_DEFINE_DYNAMIC_FUNC0(B2LineJoint_obj,getMotorSpeed,return )

Void B2LineJoint_obj::setMaxMotorForce( double force){
{
		HX_SOURCE_PUSH("B2LineJoint_obj::setMaxMotorForce")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",272)
		this->m_bodyA->setAwake(true);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",273)
		this->m_bodyB->setAwake(true);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",274)
		this->m_maxMotorForce = force;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2LineJoint_obj,setMaxMotorForce,(void))

double B2LineJoint_obj::getMaxMotorForce( ){
	HX_SOURCE_PUSH("B2LineJoint_obj::getMaxMotorForce")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",281)
	return this->m_maxMotorForce;
}


HX_DEFINE_DYNAMIC_FUNC0(B2LineJoint_obj,getMaxMotorForce,return )

double B2LineJoint_obj::getMotorForce( ){
	HX_SOURCE_PUSH("B2LineJoint_obj::getMotorForce")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",289)
	return this->m_motorImpulse;
}


HX_DEFINE_DYNAMIC_FUNC0(B2LineJoint_obj,getMotorForce,return )

Void B2LineJoint_obj::initVelocityConstraints( ::box2D::dynamics::B2TimeStep step){
{
		HX_SOURCE_PUSH("B2LineJoint_obj::initVelocityConstraints")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",341)
		::box2D::dynamics::B2Body bA = this->m_bodyA;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",342)
		::box2D::dynamics::B2Body bB = this->m_bodyB;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",344)
		::box2D::common::math::B2Mat22 tMat;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",345)
		double tX;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",347)
		this->m_localCenterA->setV(bA->getLocalCenter());
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",348)
		this->m_localCenterB->setV(bB->getLocalCenter());
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",350)
		::box2D::common::math::B2Transform xf1 = bA->getTransform();
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",351)
		::box2D::common::math::B2Transform xf2 = bB->getTransform();
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",355)
		tMat = bA->m_xf->R;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",356)
		double r1X = (this->m_localAnchor1->x - this->m_localCenterA->x);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",357)
		double r1Y = (this->m_localAnchor1->y - this->m_localCenterA->y);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",358)
		tX = ((tMat->col1->x * r1X) + (tMat->col2->x * r1Y));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",359)
		r1Y = ((tMat->col1->y * r1X) + (tMat->col2->y * r1Y));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",360)
		r1X = tX;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",362)
		tMat = bB->m_xf->R;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",363)
		double r2X = (this->m_localAnchor2->x - this->m_localCenterB->x);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",364)
		double r2Y = (this->m_localAnchor2->y - this->m_localCenterB->y);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",365)
		tX = ((tMat->col1->x * r2X) + (tMat->col2->x * r2Y));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",366)
		r2Y = ((tMat->col1->y * r2X) + (tMat->col2->y * r2Y));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",367)
		r2X = tX;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",370)
		double dX = (((bB->m_sweep->c->x + r2X) - bA->m_sweep->c->x) - r1X);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",371)
		double dY = (((bB->m_sweep->c->y + r2Y) - bA->m_sweep->c->y) - r1Y);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",373)
		this->m_invMassA = bA->m_invMass;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",374)
		this->m_invMassB = bB->m_invMass;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",375)
		this->m_invIA = bA->m_invI;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",376)
		this->m_invIB = bB->m_invI;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",379)
		{
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",380)
			this->m_axis->setV(::box2D::common::math::B2Math_obj::mulMV(xf1->R,this->m_localXAxis1));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",382)
			this->m_a1 = ((((dX + r1X)) * this->m_axis->y) - (((dY + r1Y)) * this->m_axis->x));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",384)
			this->m_a2 = ((r2X * this->m_axis->y) - (r2Y * this->m_axis->x));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",386)
			this->m_motorMass = (((this->m_invMassA + this->m_invMassB) + ((this->m_invIA * this->m_a1) * this->m_a1)) + ((this->m_invIB * this->m_a2) * this->m_a2));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",387)
			this->m_motorMass = (  (((this->m_motorMass > 2.2250738585072014e-308))) ? double((double(1.0) / double(this->m_motorMass))) : double(0.0) );
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",391)
		{
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",392)
			this->m_perp->setV(::box2D::common::math::B2Math_obj::mulMV(xf1->R,this->m_localYAxis1));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",394)
			this->m_s1 = ((((dX + r1X)) * this->m_perp->y) - (((dY + r1Y)) * this->m_perp->x));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",396)
			this->m_s2 = ((r2X * this->m_perp->y) - (r2Y * this->m_perp->x));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",398)
			double m1 = this->m_invMassA;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",399)
			double m2 = this->m_invMassB;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",400)
			double i1 = this->m_invIA;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",401)
			double i2 = this->m_invIB;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",403)
			this->m_K->col1->x = (((m1 + m2) + ((i1 * this->m_s1) * this->m_s1)) + ((i2 * this->m_s2) * this->m_s2));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",404)
			this->m_K->col1->y = (((i1 * this->m_s1) * this->m_a1) + ((i2 * this->m_s2) * this->m_a2));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",405)
			this->m_K->col2->x = this->m_K->col1->y;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",406)
			this->m_K->col2->y = (((m1 + m2) + ((i1 * this->m_a1) * this->m_a1)) + ((i2 * this->m_a2) * this->m_a2));
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",410)
		if ((this->m_enableLimit)){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",413)
			double jointTransition = ((this->m_axis->x * dX) + (this->m_axis->y * dY));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",414)
			if (((::box2D::common::math::B2Math_obj::abs((this->m_upperTranslation - this->m_lowerTranslation)) < (2.0 * ::box2D::common::B2Settings_obj::b2_linearSlop)))){
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",415)
				this->m_limitState = ::box2D::dynamics::joints::B2Joint_obj::e_equalLimits;
			}
			else{
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",418)
				if (((jointTransition <= this->m_lowerTranslation))){
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",419)
					if (((this->m_limitState != ::box2D::dynamics::joints::B2Joint_obj::e_atLowerLimit))){
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",422)
						this->m_limitState = ::box2D::dynamics::joints::B2Joint_obj::e_atLowerLimit;
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",423)
						this->m_impulse->y = 0.0;
					}
				}
				else{
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",426)
					if (((jointTransition >= this->m_upperTranslation))){
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",427)
						if (((this->m_limitState != ::box2D::dynamics::joints::B2Joint_obj::e_atUpperLimit))){
							HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",430)
							this->m_limitState = ::box2D::dynamics::joints::B2Joint_obj::e_atUpperLimit;
							HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",431)
							this->m_impulse->y = 0.0;
						}
					}
					else{
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",436)
						this->m_limitState = ::box2D::dynamics::joints::B2Joint_obj::e_inactiveLimit;
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",437)
						this->m_impulse->y = 0.0;
					}
				}
			}
		}
		else{
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",441)
			this->m_limitState = ::box2D::dynamics::joints::B2Joint_obj::e_inactiveLimit;
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",445)
		if (((this->m_enableMotor == false))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",446)
			this->m_motorImpulse = 0.0;
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",450)
		if ((step->warmStarting)){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",453)
			hx::MultEq(this->m_impulse->x,step->dtRatio);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",454)
			hx::MultEq(this->m_impulse->y,step->dtRatio);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",455)
			hx::MultEq(this->m_motorImpulse,step->dtRatio);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",458)
			double PX = ((this->m_impulse->x * this->m_perp->x) + (((this->m_motorImpulse + this->m_impulse->y)) * this->m_axis->x));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",459)
			double PY = ((this->m_impulse->x * this->m_perp->y) + (((this->m_motorImpulse + this->m_impulse->y)) * this->m_axis->y));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",460)
			double L1 = ((this->m_impulse->x * this->m_s1) + (((this->m_motorImpulse + this->m_impulse->y)) * this->m_a1));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",461)
			double L2 = ((this->m_impulse->x * this->m_s2) + (((this->m_motorImpulse + this->m_impulse->y)) * this->m_a2));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",464)
			hx::SubEq(bA->m_linearVelocity->x,(this->m_invMassA * PX));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",465)
			hx::SubEq(bA->m_linearVelocity->y,(this->m_invMassA * PY));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",467)
			hx::SubEq(bA->m_angularVelocity,(this->m_invIA * L1));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",470)
			hx::AddEq(bB->m_linearVelocity->x,(this->m_invMassB * PX));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",471)
			hx::AddEq(bB->m_linearVelocity->y,(this->m_invMassB * PY));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",473)
			hx::AddEq(bB->m_angularVelocity,(this->m_invIB * L2));
		}
		else{
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",477)
			this->m_impulse->setZero();
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",478)
			this->m_motorImpulse = 0.0;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2LineJoint_obj,initVelocityConstraints,(void))

Void B2LineJoint_obj::solveVelocityConstraints( ::box2D::dynamics::B2TimeStep step){
{
		HX_SOURCE_PUSH("B2LineJoint_obj::solveVelocityConstraints")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",483)
		::box2D::dynamics::B2Body bA = this->m_bodyA;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",484)
		::box2D::dynamics::B2Body bB = this->m_bodyB;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",486)
		::box2D::common::math::B2Vec2 v1 = bA->m_linearVelocity;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",487)
		double w1 = bA->m_angularVelocity;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",488)
		::box2D::common::math::B2Vec2 v2 = bB->m_linearVelocity;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",489)
		double w2 = bB->m_angularVelocity;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",491)
		double PX;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",492)
		double PY;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",493)
		double L1;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",494)
		double L2;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",497)
		if (((bool(this->m_enableMotor) && bool((this->m_limitState != ::box2D::dynamics::joints::B2Joint_obj::e_equalLimits))))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",500)
			double Cdot = ((((this->m_axis->x * ((v2->x - v1->x))) + (this->m_axis->y * ((v2->y - v1->y)))) + (this->m_a2 * w2)) - (this->m_a1 * w1));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",501)
			double impulse = (this->m_motorMass * ((this->m_motorSpeed - Cdot)));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",502)
			double oldImpulse = this->m_motorImpulse;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",503)
			double maxImpulse = (step->dt * this->m_maxMotorForce);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",504)
			this->m_motorImpulse = ::box2D::common::math::B2Math_obj::clamp((this->m_motorImpulse + impulse),-(maxImpulse),maxImpulse);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",505)
			impulse = (this->m_motorImpulse - oldImpulse);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",507)
			PX = (impulse * this->m_axis->x);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",508)
			PY = (impulse * this->m_axis->y);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",509)
			L1 = (impulse * this->m_a1);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",510)
			L2 = (impulse * this->m_a2);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",512)
			hx::SubEq(v1->x,(this->m_invMassA * PX));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",513)
			hx::SubEq(v1->y,(this->m_invMassA * PY));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",514)
			hx::SubEq(w1,(this->m_invIA * L1));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",516)
			hx::AddEq(v2->x,(this->m_invMassB * PX));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",517)
			hx::AddEq(v2->y,(this->m_invMassB * PY));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",518)
			hx::AddEq(w2,(this->m_invIB * L2));
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",522)
		double Cdot1 = ((((this->m_perp->x * ((v2->x - v1->x))) + (this->m_perp->y * ((v2->y - v1->y)))) + (this->m_s2 * w2)) - (this->m_s1 * w1));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",524)
		if (((bool(this->m_enableLimit) && bool((this->m_limitState != ::box2D::dynamics::joints::B2Joint_obj::e_inactiveLimit))))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",528)
			double Cdot2 = ((((this->m_axis->x * ((v2->x - v1->x))) + (this->m_axis->y * ((v2->y - v1->y)))) + (this->m_a2 * w2)) - (this->m_a1 * w1));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",530)
			::box2D::common::math::B2Vec2 f1 = this->m_impulse->copy();
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",531)
			::box2D::common::math::B2Vec2 df = this->m_K->solve(::box2D::common::math::B2Vec2_obj::__new(null(),null()),-(Cdot1),-(Cdot2));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",533)
			this->m_impulse->add(df);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",535)
			if (((this->m_limitState == ::box2D::dynamics::joints::B2Joint_obj::e_atLowerLimit))){
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",536)
				this->m_impulse->y = ::box2D::common::math::B2Math_obj::max(this->m_impulse->y,0.0);
			}
			else{
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",539)
				if (((this->m_limitState == ::box2D::dynamics::joints::B2Joint_obj::e_atUpperLimit))){
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",540)
					this->m_impulse->y = ::box2D::common::math::B2Math_obj::min(this->m_impulse->y,0.0);
				}
			}
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",545)
			double b = (-(Cdot1) - (((this->m_impulse->y - f1->y)) * this->m_K->col2->x));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",546)
			double f2r;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",547)
			if (((this->m_K->col1->x != 0.0))){
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",548)
				f2r = ((double(b) / double(this->m_K->col1->x)) + f1->x);
			}
			else{
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",550)
				f2r = f1->x;
			}
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",553)
			this->m_impulse->x = f2r;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",555)
			df->x = (this->m_impulse->x - f1->x);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",556)
			df->y = (this->m_impulse->y - f1->y);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",558)
			PX = ((df->x * this->m_perp->x) + (df->y * this->m_axis->x));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",559)
			PY = ((df->x * this->m_perp->y) + (df->y * this->m_axis->y));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",560)
			L1 = ((df->x * this->m_s1) + (df->y * this->m_a1));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",561)
			L2 = ((df->x * this->m_s2) + (df->y * this->m_a2));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",563)
			hx::SubEq(v1->x,(this->m_invMassA * PX));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",564)
			hx::SubEq(v1->y,(this->m_invMassA * PY));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",565)
			hx::SubEq(w1,(this->m_invIA * L1));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",567)
			hx::AddEq(v2->x,(this->m_invMassB * PX));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",568)
			hx::AddEq(v2->y,(this->m_invMassB * PY));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",569)
			hx::AddEq(w2,(this->m_invIB * L2));
		}
		else{
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",574)
			double df2;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",575)
			if (((this->m_K->col1->x != 0.0))){
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",576)
				df2 = (double(-(Cdot1)) / double(this->m_K->col1->x));
			}
			else{
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",578)
				df2 = 0.0;
			}
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",581)
			hx::AddEq(this->m_impulse->x,df2);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",583)
			PX = (df2 * this->m_perp->x);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",584)
			PY = (df2 * this->m_perp->y);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",585)
			L1 = (df2 * this->m_s1);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",586)
			L2 = (df2 * this->m_s2);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",588)
			hx::SubEq(v1->x,(this->m_invMassA * PX));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",589)
			hx::SubEq(v1->y,(this->m_invMassA * PY));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",590)
			hx::SubEq(w1,(this->m_invIA * L1));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",592)
			hx::AddEq(v2->x,(this->m_invMassB * PX));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",593)
			hx::AddEq(v2->y,(this->m_invMassB * PY));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",594)
			hx::AddEq(w2,(this->m_invIB * L2));
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",597)
		bA->m_linearVelocity->setV(v1);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",598)
		bA->m_angularVelocity = w1;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",599)
		bB->m_linearVelocity->setV(v2);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",600)
		bB->m_angularVelocity = w2;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2LineJoint_obj,solveVelocityConstraints,(void))

bool B2LineJoint_obj::solvePositionConstraints( double baumgarte){
	HX_SOURCE_PUSH("B2LineJoint_obj::solvePositionConstraints")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",608)
	double limitC;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",609)
	double oldLimitImpulse;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",611)
	::box2D::dynamics::B2Body bA = this->m_bodyA;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",612)
	::box2D::dynamics::B2Body bB = this->m_bodyB;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",614)
	::box2D::common::math::B2Vec2 c1 = bA->m_sweep->c;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",615)
	double a1 = bA->m_sweep->a;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",617)
	::box2D::common::math::B2Vec2 c2 = bB->m_sweep->c;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",618)
	double a2 = bB->m_sweep->a;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",620)
	::box2D::common::math::B2Mat22 tMat;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",621)
	double tX;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",623)
	double m1;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",624)
	double m2;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",625)
	double i1;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",626)
	double i2;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",629)
	double linearError = 0.0;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",630)
	double angularError = 0.0;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",631)
	bool active = false;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",632)
	double C2 = 0.0;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",634)
	::box2D::common::math::B2Mat22 R1 = ::box2D::common::math::B2Mat22_obj::fromAngle(a1);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",635)
	::box2D::common::math::B2Mat22 R2 = ::box2D::common::math::B2Mat22_obj::fromAngle(a2);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",638)
	tMat = R1;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",639)
	double r1X = (this->m_localAnchor1->x - this->m_localCenterA->x);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",640)
	double r1Y = (this->m_localAnchor1->y - this->m_localCenterA->y);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",641)
	tX = ((tMat->col1->x * r1X) + (tMat->col2->x * r1Y));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",642)
	r1Y = ((tMat->col1->y * r1X) + (tMat->col2->y * r1Y));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",643)
	r1X = tX;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",645)
	tMat = R2;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",646)
	double r2X = (this->m_localAnchor2->x - this->m_localCenterB->x);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",647)
	double r2Y = (this->m_localAnchor2->y - this->m_localCenterB->y);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",648)
	tX = ((tMat->col1->x * r2X) + (tMat->col2->x * r2Y));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",649)
	r2Y = ((tMat->col1->y * r2X) + (tMat->col2->y * r2Y));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",650)
	r2X = tX;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",652)
	double dX = (((c2->x + r2X) - c1->x) - r1X);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",653)
	double dY = (((c2->y + r2Y) - c1->y) - r1Y);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",655)
	if ((this->m_enableLimit)){
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",657)
		this->m_axis = ::box2D::common::math::B2Math_obj::mulMV(R1,this->m_localXAxis1);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",660)
		this->m_a1 = ((((dX + r1X)) * this->m_axis->y) - (((dY + r1Y)) * this->m_axis->x));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",662)
		this->m_a2 = ((r2X * this->m_axis->y) - (r2Y * this->m_axis->x));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",664)
		double translation = ((this->m_axis->x * dX) + (this->m_axis->y * dY));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",665)
		if (((::box2D::common::math::B2Math_obj::abs((this->m_upperTranslation - this->m_lowerTranslation)) < (2.0 * ::box2D::common::B2Settings_obj::b2_linearSlop)))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",668)
			C2 = ::box2D::common::math::B2Math_obj::clamp(translation,-(::box2D::common::B2Settings_obj::b2_maxLinearCorrection),::box2D::common::B2Settings_obj::b2_maxLinearCorrection);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",669)
			linearError = ::box2D::common::math::B2Math_obj::abs(translation);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",670)
			active = true;
		}
		else{
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",672)
			if (((translation <= this->m_lowerTranslation))){
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",675)
				C2 = ::box2D::common::math::B2Math_obj::clamp(((translation - this->m_lowerTranslation) + ::box2D::common::B2Settings_obj::b2_linearSlop),-(::box2D::common::B2Settings_obj::b2_maxLinearCorrection),0.0);
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",676)
				linearError = (this->m_lowerTranslation - translation);
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",677)
				active = true;
			}
			else{
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",679)
				if (((translation >= this->m_upperTranslation))){
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",682)
					C2 = ::box2D::common::math::B2Math_obj::clamp(((translation - this->m_upperTranslation) + ::box2D::common::B2Settings_obj::b2_linearSlop),0.0,::box2D::common::B2Settings_obj::b2_maxLinearCorrection);
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",683)
					linearError = (translation - this->m_upperTranslation);
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",684)
					active = true;
				}
			}
		}
	}
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",688)
	this->m_perp = ::box2D::common::math::B2Math_obj::mulMV(R1,this->m_localYAxis1);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",691)
	this->m_s1 = ((((dX + r1X)) * this->m_perp->y) - (((dY + r1Y)) * this->m_perp->x));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",693)
	this->m_s2 = ((r2X * this->m_perp->y) - (r2Y * this->m_perp->x));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",695)
	::box2D::common::math::B2Vec2 impulse = ::box2D::common::math::B2Vec2_obj::__new(null(),null());
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",696)
	double C1 = ((this->m_perp->x * dX) + (this->m_perp->y * dY));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",698)
	linearError = ::box2D::common::math::B2Math_obj::max(linearError,::box2D::common::math::B2Math_obj::abs(C1));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",699)
	angularError = 0.0;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",701)
	if ((active)){
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",703)
		m1 = this->m_invMassA;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",704)
		m2 = this->m_invMassB;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",705)
		i1 = this->m_invIA;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",706)
		i2 = this->m_invIB;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",708)
		this->m_K->col1->x = (((m1 + m2) + ((i1 * this->m_s1) * this->m_s1)) + ((i2 * this->m_s2) * this->m_s2));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",709)
		this->m_K->col1->y = (((i1 * this->m_s1) * this->m_a1) + ((i2 * this->m_s2) * this->m_a2));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",710)
		this->m_K->col2->x = this->m_K->col1->y;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",711)
		this->m_K->col2->y = (((m1 + m2) + ((i1 * this->m_a1) * this->m_a1)) + ((i2 * this->m_a2) * this->m_a2));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",713)
		this->m_K->solve(impulse,-(C1),-(C2));
	}
	else{
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",717)
		m1 = this->m_invMassA;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",718)
		m2 = this->m_invMassB;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",719)
		i1 = this->m_invIA;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",720)
		i2 = this->m_invIB;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",722)
		double k11 = (((m1 + m2) + ((i1 * this->m_s1) * this->m_s1)) + ((i2 * this->m_s2) * this->m_s2));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",724)
		double impulse1;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",725)
		if (((k11 != 0.0))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",726)
			impulse1 = (double(-(C1)) / double(k11));
		}
		else{
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",728)
			impulse1 = 0.0;
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",731)
		impulse->x = impulse1;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",732)
		impulse->y = 0.0;
	}
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",735)
	double PX = ((impulse->x * this->m_perp->x) + (impulse->y * this->m_axis->x));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",736)
	double PY = ((impulse->x * this->m_perp->y) + (impulse->y * this->m_axis->y));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",737)
	double L1 = ((impulse->x * this->m_s1) + (impulse->y * this->m_a1));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",738)
	double L2 = ((impulse->x * this->m_s2) + (impulse->y * this->m_a2));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",740)
	hx::SubEq(c1->x,(this->m_invMassA * PX));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",741)
	hx::SubEq(c1->y,(this->m_invMassA * PY));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",742)
	hx::SubEq(a1,(this->m_invIA * L1));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",744)
	hx::AddEq(c2->x,(this->m_invMassB * PX));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",745)
	hx::AddEq(c2->y,(this->m_invMassB * PY));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",746)
	hx::AddEq(a2,(this->m_invIB * L2));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",750)
	bA->m_sweep->a = a1;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",752)
	bB->m_sweep->a = a2;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",753)
	bA->synchronizeTransform();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",754)
	bB->synchronizeTransform();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2LineJoint.hx",756)
	return (bool((linearError <= ::box2D::common::B2Settings_obj::b2_linearSlop)) && bool((angularError <= ::box2D::common::B2Settings_obj::b2_angularSlop)));
}


HX_DEFINE_DYNAMIC_FUNC1(B2LineJoint_obj,solvePositionConstraints,return )


B2LineJoint_obj::B2LineJoint_obj()
{
}

void B2LineJoint_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(B2LineJoint);
	HX_MARK_MEMBER_NAME(m_localAnchor1,"m_localAnchor1");
	HX_MARK_MEMBER_NAME(m_localAnchor2,"m_localAnchor2");
	HX_MARK_MEMBER_NAME(m_localXAxis1,"m_localXAxis1");
	HX_MARK_MEMBER_NAME(m_localYAxis1,"m_localYAxis1");
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

Dynamic B2LineJoint_obj::__Field(const ::String &inName)
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
		if (HX_FIELD_EQ(inName,"getMaxMotorForce") ) { return getMaxMotorForce_dyn(); }
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

Dynamic B2LineJoint_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"m_K") ) { m_K=inValue.Cast< ::box2D::common::math::B2Mat22 >(); return inValue; }
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
		if (HX_FIELD_EQ(inName,"m_impulse") ) { m_impulse=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
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

void B2LineJoint_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("m_localAnchor1"));
	outFields->push(HX_CSTRING("m_localAnchor2"));
	outFields->push(HX_CSTRING("m_localXAxis1"));
	outFields->push(HX_CSTRING("m_localYAxis1"));
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
	HX_CSTRING("getMaxMotorForce"),
	HX_CSTRING("getMotorForce"),
	HX_CSTRING("initVelocityConstraints"),
	HX_CSTRING("solveVelocityConstraints"),
	HX_CSTRING("solvePositionConstraints"),
	HX_CSTRING("m_localAnchor1"),
	HX_CSTRING("m_localAnchor2"),
	HX_CSTRING("m_localXAxis1"),
	HX_CSTRING("m_localYAxis1"),
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

Class B2LineJoint_obj::__mClass;

void B2LineJoint_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.dynamics.joints.B2LineJoint"), hx::TCanCast< B2LineJoint_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void B2LineJoint_obj::__boot()
{
}

} // end namespace box2D
} // end namespace dynamics
} // end namespace joints
