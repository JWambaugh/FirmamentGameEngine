#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_box2D_common_math_B2Mat22
#include <box2D/common/math/B2Mat22.h>
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
#ifndef INCLUDED_box2D_dynamics_joints_B2MouseJoint
#include <box2D/dynamics/joints/B2MouseJoint.h>
#endif
#ifndef INCLUDED_box2D_dynamics_joints_B2MouseJointDef
#include <box2D/dynamics/joints/B2MouseJointDef.h>
#endif
namespace box2D{
namespace dynamics{
namespace joints{

Void B2MouseJoint_obj::__construct(::box2D::dynamics::joints::B2MouseJointDef def)
{
{
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2MouseJoint.hx",122)
	super::__construct(def);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2MouseJoint.hx",124)
	this->K = ::box2D::common::math::B2Mat22_obj::__new();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2MouseJoint.hx",125)
	this->K1 = ::box2D::common::math::B2Mat22_obj::__new();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2MouseJoint.hx",126)
	this->K2 = ::box2D::common::math::B2Mat22_obj::__new();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2MouseJoint.hx",128)
	this->m_localAnchor = ::box2D::common::math::B2Vec2_obj::__new(null(),null());
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2MouseJoint.hx",129)
	this->m_target = ::box2D::common::math::B2Vec2_obj::__new(null(),null());
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2MouseJoint.hx",130)
	this->m_impulse = ::box2D::common::math::B2Vec2_obj::__new(null(),null());
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2MouseJoint.hx",132)
	this->m_mass = ::box2D::common::math::B2Mat22_obj::__new();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2MouseJoint.hx",133)
	this->m_C = ::box2D::common::math::B2Vec2_obj::__new(null(),null());
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2MouseJoint.hx",140)
	this->m_target->setV(def->target);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2MouseJoint.hx",142)
	double tX = (this->m_target->x - this->m_bodyB->m_xf->position->x);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2MouseJoint.hx",143)
	double tY = (this->m_target->y - this->m_bodyB->m_xf->position->y);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2MouseJoint.hx",144)
	::box2D::common::math::B2Mat22 tMat = this->m_bodyB->m_xf->R;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2MouseJoint.hx",145)
	this->m_localAnchor->x = ((tX * tMat->col1->x) + (tY * tMat->col1->y));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2MouseJoint.hx",146)
	this->m_localAnchor->y = ((tX * tMat->col2->x) + (tY * tMat->col2->y));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2MouseJoint.hx",148)
	this->m_maxForce = def->maxForce;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2MouseJoint.hx",149)
	this->m_impulse->setZero();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2MouseJoint.hx",151)
	this->m_frequencyHz = def->frequencyHz;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2MouseJoint.hx",152)
	this->m_dampingRatio = def->dampingRatio;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2MouseJoint.hx",154)
	this->m_beta = 0.0;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2MouseJoint.hx",155)
	this->m_gamma = 0.0;
}
;
	return null();
}

B2MouseJoint_obj::~B2MouseJoint_obj() { }

Dynamic B2MouseJoint_obj::__CreateEmpty() { return  new B2MouseJoint_obj; }
hx::ObjectPtr< B2MouseJoint_obj > B2MouseJoint_obj::__new(::box2D::dynamics::joints::B2MouseJointDef def)
{  hx::ObjectPtr< B2MouseJoint_obj > result = new B2MouseJoint_obj();
	result->__construct(def);
	return result;}

Dynamic B2MouseJoint_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2MouseJoint_obj > result = new B2MouseJoint_obj();
	result->__construct(inArgs[0]);
	return result;}

::box2D::common::math::B2Vec2 B2MouseJoint_obj::getAnchorA( ){
	HX_SOURCE_PUSH("B2MouseJoint_obj::getAnchorA")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2MouseJoint.hx",49)
	return this->m_target;
}


HX_DEFINE_DYNAMIC_FUNC0(B2MouseJoint_obj,getAnchorA,return )

::box2D::common::math::B2Vec2 B2MouseJoint_obj::getAnchorB( ){
	HX_SOURCE_PUSH("B2MouseJoint_obj::getAnchorB")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2MouseJoint.hx",53)
	return this->m_bodyB->getWorldPoint(this->m_localAnchor);
}


HX_DEFINE_DYNAMIC_FUNC0(B2MouseJoint_obj,getAnchorB,return )

::box2D::common::math::B2Vec2 B2MouseJoint_obj::getReactionForce( double inv_dt){
	HX_SOURCE_PUSH("B2MouseJoint_obj::getReactionForce")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2MouseJoint.hx",58)
	return ::box2D::common::math::B2Vec2_obj::__new((inv_dt * this->m_impulse->x),(inv_dt * this->m_impulse->y));
}


HX_DEFINE_DYNAMIC_FUNC1(B2MouseJoint_obj,getReactionForce,return )

double B2MouseJoint_obj::getReactionTorque( double inv_dt){
	HX_SOURCE_PUSH("B2MouseJoint_obj::getReactionTorque")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2MouseJoint.hx",63)
	return 0.0;
}


HX_DEFINE_DYNAMIC_FUNC1(B2MouseJoint_obj,getReactionTorque,return )

::box2D::common::math::B2Vec2 B2MouseJoint_obj::getTarget( ){
	HX_SOURCE_PUSH("B2MouseJoint_obj::getTarget")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2MouseJoint.hx",68)
	return this->m_target;
}


HX_DEFINE_DYNAMIC_FUNC0(B2MouseJoint_obj,getTarget,return )

Void B2MouseJoint_obj::setTarget( ::box2D::common::math::B2Vec2 target){
{
		HX_SOURCE_PUSH("B2MouseJoint_obj::setTarget")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2MouseJoint.hx",76)
		if (((this->m_bodyB->isAwake() == false))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2MouseJoint.hx",76)
			this->m_bodyB->setAwake(true);
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2MouseJoint.hx",79)
		this->m_target = target;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2MouseJoint_obj,setTarget,(void))

double B2MouseJoint_obj::getMaxForce( ){
	HX_SOURCE_PUSH("B2MouseJoint_obj::getMaxForce")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2MouseJoint.hx",84)
	return this->m_maxForce;
}


HX_DEFINE_DYNAMIC_FUNC0(B2MouseJoint_obj,getMaxForce,return )

Void B2MouseJoint_obj::setMaxForce( double maxForce){
{
		HX_SOURCE_PUSH("B2MouseJoint_obj::setMaxForce")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2MouseJoint.hx",90)
		this->m_maxForce = maxForce;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2MouseJoint_obj,setMaxForce,(void))

double B2MouseJoint_obj::getFrequency( ){
	HX_SOURCE_PUSH("B2MouseJoint_obj::getFrequency")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2MouseJoint.hx",96)
	return this->m_frequencyHz;
}


HX_DEFINE_DYNAMIC_FUNC0(B2MouseJoint_obj,getFrequency,return )

Void B2MouseJoint_obj::setFrequency( double hz){
{
		HX_SOURCE_PUSH("B2MouseJoint_obj::setFrequency")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2MouseJoint.hx",102)
		this->m_frequencyHz = hz;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2MouseJoint_obj,setFrequency,(void))

double B2MouseJoint_obj::getDampingRatio( ){
	HX_SOURCE_PUSH("B2MouseJoint_obj::getDampingRatio")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2MouseJoint.hx",108)
	return this->m_dampingRatio;
}


HX_DEFINE_DYNAMIC_FUNC0(B2MouseJoint_obj,getDampingRatio,return )

Void B2MouseJoint_obj::setDampingRatio( double ratio){
{
		HX_SOURCE_PUSH("B2MouseJoint_obj::setDampingRatio")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2MouseJoint.hx",114)
		this->m_dampingRatio = ratio;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2MouseJoint_obj,setDampingRatio,(void))

Void B2MouseJoint_obj::initVelocityConstraints( ::box2D::dynamics::B2TimeStep step){
{
		HX_SOURCE_PUSH("B2MouseJoint_obj::initVelocityConstraints")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2MouseJoint.hx",163)
		::box2D::dynamics::B2Body b = this->m_bodyB;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2MouseJoint.hx",165)
		double mass = b->getMass();
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2MouseJoint.hx",168)
		double omega = ((2.0 * ::Math_obj::PI) * this->m_frequencyHz);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2MouseJoint.hx",171)
		double d = (((2.0 * mass) * this->m_dampingRatio) * omega);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2MouseJoint.hx",174)
		double k = ((mass * omega) * omega);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2MouseJoint.hx",180)
		this->m_gamma = (step->dt * ((d + (step->dt * k))));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2MouseJoint.hx",181)
		this->m_gamma = (  (((this->m_gamma != (int)0))) ? double((double((int)1) / double(this->m_gamma))) : double(0.0) );
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2MouseJoint.hx",182)
		this->m_beta = ((step->dt * k) * this->m_gamma);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2MouseJoint.hx",184)
		::box2D::common::math::B2Mat22 tMat;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2MouseJoint.hx",188)
		tMat = b->m_xf->R;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2MouseJoint.hx",189)
		double rX = (this->m_localAnchor->x - b->m_sweep->localCenter->x);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2MouseJoint.hx",190)
		double rY = (this->m_localAnchor->y - b->m_sweep->localCenter->y);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2MouseJoint.hx",191)
		double tX = ((tMat->col1->x * rX) + (tMat->col2->x * rY));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2MouseJoint.hx",192)
		rY = ((tMat->col1->y * rX) + (tMat->col2->y * rY));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2MouseJoint.hx",193)
		rX = tX;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2MouseJoint.hx",198)
		double invMass = b->m_invMass;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2MouseJoint.hx",199)
		double invI = b->m_invI;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2MouseJoint.hx",202)
		this->K1->col1->x = invMass;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2MouseJoint.hx",202)
		this->K1->col2->x = 0.0;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2MouseJoint.hx",203)
		this->K1->col1->y = 0.0;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2MouseJoint.hx",203)
		this->K1->col2->y = invMass;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2MouseJoint.hx",206)
		this->K2->col1->x = ((invI * rY) * rY);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2MouseJoint.hx",206)
		this->K2->col2->x = ((-(invI) * rX) * rY);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2MouseJoint.hx",207)
		this->K2->col1->y = ((-(invI) * rX) * rY);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2MouseJoint.hx",207)
		this->K2->col2->y = ((invI * rX) * rX);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2MouseJoint.hx",210)
		this->K->setM(this->K1);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2MouseJoint.hx",211)
		this->K->addM(this->K2);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2MouseJoint.hx",212)
		hx::AddEq(this->K->col1->x,this->m_gamma);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2MouseJoint.hx",213)
		hx::AddEq(this->K->col2->y,this->m_gamma);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2MouseJoint.hx",216)
		this->K->getInverse(this->m_mass);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2MouseJoint.hx",219)
		this->m_C->x = ((b->m_sweep->c->x + rX) - this->m_target->x);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2MouseJoint.hx",220)
		this->m_C->y = ((b->m_sweep->c->y + rY) - this->m_target->y);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2MouseJoint.hx",223)
		hx::MultEq(b->m_angularVelocity,0.98);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2MouseJoint.hx",226)
		hx::MultEq(this->m_impulse->x,step->dtRatio);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2MouseJoint.hx",227)
		hx::MultEq(this->m_impulse->y,step->dtRatio);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2MouseJoint.hx",229)
		hx::AddEq(b->m_linearVelocity->x,(invMass * this->m_impulse->x));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2MouseJoint.hx",230)
		hx::AddEq(b->m_linearVelocity->y,(invMass * this->m_impulse->y));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2MouseJoint.hx",232)
		hx::AddEq(b->m_angularVelocity,(invI * (((rX * this->m_impulse->y) - (rY * this->m_impulse->x)))));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2MouseJoint_obj,initVelocityConstraints,(void))

Void B2MouseJoint_obj::solveVelocityConstraints( ::box2D::dynamics::B2TimeStep step){
{
		HX_SOURCE_PUSH("B2MouseJoint_obj::solveVelocityConstraints")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2MouseJoint.hx",236)
		::box2D::dynamics::B2Body b = this->m_bodyB;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2MouseJoint.hx",238)
		::box2D::common::math::B2Mat22 tMat;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2MouseJoint.hx",239)
		double tX;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2MouseJoint.hx",240)
		double tY;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2MouseJoint.hx",244)
		tMat = b->m_xf->R;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2MouseJoint.hx",245)
		double rX = (this->m_localAnchor->x - b->m_sweep->localCenter->x);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2MouseJoint.hx",246)
		double rY = (this->m_localAnchor->y - b->m_sweep->localCenter->y);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2MouseJoint.hx",247)
		tX = ((tMat->col1->x * rX) + (tMat->col2->x * rY));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2MouseJoint.hx",248)
		rY = ((tMat->col1->y * rX) + (tMat->col2->y * rY));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2MouseJoint.hx",249)
		rX = tX;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2MouseJoint.hx",253)
		double CdotX = (b->m_linearVelocity->x + (-(b->m_angularVelocity) * rY));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2MouseJoint.hx",254)
		double CdotY = (b->m_linearVelocity->y + (b->m_angularVelocity * rX));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2MouseJoint.hx",256)
		tMat = this->m_mass;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2MouseJoint.hx",257)
		tX = ((CdotX + (this->m_beta * this->m_C->x)) + (this->m_gamma * this->m_impulse->x));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2MouseJoint.hx",258)
		tY = ((CdotY + (this->m_beta * this->m_C->y)) + (this->m_gamma * this->m_impulse->y));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2MouseJoint.hx",259)
		double impulseX = -((((tMat->col1->x * tX) + (tMat->col2->x * tY))));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2MouseJoint.hx",260)
		double impulseY = -((((tMat->col1->y * tX) + (tMat->col2->y * tY))));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2MouseJoint.hx",262)
		double oldImpulseX = this->m_impulse->x;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2MouseJoint.hx",263)
		double oldImpulseY = this->m_impulse->y;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2MouseJoint.hx",265)
		hx::AddEq(this->m_impulse->x,impulseX);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2MouseJoint.hx",266)
		hx::AddEq(this->m_impulse->y,impulseY);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2MouseJoint.hx",267)
		double maxImpulse = (step->dt * this->m_maxForce);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2MouseJoint.hx",268)
		if (((this->m_impulse->lengthSquared() > (maxImpulse * maxImpulse)))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2MouseJoint.hx",269)
			this->m_impulse->multiply((double(maxImpulse) / double(this->m_impulse->length())));
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2MouseJoint.hx",274)
		impulseX = (this->m_impulse->x - oldImpulseX);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2MouseJoint.hx",275)
		impulseY = (this->m_impulse->y - oldImpulseY);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2MouseJoint.hx",278)
		hx::AddEq(b->m_linearVelocity->x,(b->m_invMass * impulseX));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2MouseJoint.hx",279)
		hx::AddEq(b->m_linearVelocity->y,(b->m_invMass * impulseY));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2MouseJoint.hx",281)
		hx::AddEq(b->m_angularVelocity,(b->m_invI * (((rX * impulseY) - (rY * impulseX)))));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2MouseJoint_obj,solveVelocityConstraints,(void))

bool B2MouseJoint_obj::solvePositionConstraints( double baumgarte){
	HX_SOURCE_PUSH("B2MouseJoint_obj::solvePositionConstraints")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2MouseJoint.hx",284)
	return true;
}


HX_DEFINE_DYNAMIC_FUNC1(B2MouseJoint_obj,solvePositionConstraints,return )


B2MouseJoint_obj::B2MouseJoint_obj()
{
}

void B2MouseJoint_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(B2MouseJoint);
	HX_MARK_MEMBER_NAME(K,"K");
	HX_MARK_MEMBER_NAME(K1,"K1");
	HX_MARK_MEMBER_NAME(K2,"K2");
	HX_MARK_MEMBER_NAME(m_localAnchor,"m_localAnchor");
	HX_MARK_MEMBER_NAME(m_target,"m_target");
	HX_MARK_MEMBER_NAME(m_impulse,"m_impulse");
	HX_MARK_MEMBER_NAME(m_mass,"m_mass");
	HX_MARK_MEMBER_NAME(m_C,"m_C");
	HX_MARK_MEMBER_NAME(m_maxForce,"m_maxForce");
	HX_MARK_MEMBER_NAME(m_frequencyHz,"m_frequencyHz");
	HX_MARK_MEMBER_NAME(m_dampingRatio,"m_dampingRatio");
	HX_MARK_MEMBER_NAME(m_beta,"m_beta");
	HX_MARK_MEMBER_NAME(m_gamma,"m_gamma");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic B2MouseJoint_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"K") ) { return K; }
		break;
	case 2:
		if (HX_FIELD_EQ(inName,"K1") ) { return K1; }
		if (HX_FIELD_EQ(inName,"K2") ) { return K2; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"m_C") ) { return m_C; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"m_mass") ) { return m_mass; }
		if (HX_FIELD_EQ(inName,"m_beta") ) { return m_beta; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"m_gamma") ) { return m_gamma; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"m_target") ) { return m_target; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"getTarget") ) { return getTarget_dyn(); }
		if (HX_FIELD_EQ(inName,"setTarget") ) { return setTarget_dyn(); }
		if (HX_FIELD_EQ(inName,"m_impulse") ) { return m_impulse; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"getAnchorA") ) { return getAnchorA_dyn(); }
		if (HX_FIELD_EQ(inName,"getAnchorB") ) { return getAnchorB_dyn(); }
		if (HX_FIELD_EQ(inName,"m_maxForce") ) { return m_maxForce; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"getMaxForce") ) { return getMaxForce_dyn(); }
		if (HX_FIELD_EQ(inName,"setMaxForce") ) { return setMaxForce_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"getFrequency") ) { return getFrequency_dyn(); }
		if (HX_FIELD_EQ(inName,"setFrequency") ) { return setFrequency_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"m_localAnchor") ) { return m_localAnchor; }
		if (HX_FIELD_EQ(inName,"m_frequencyHz") ) { return m_frequencyHz; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"m_dampingRatio") ) { return m_dampingRatio; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"getDampingRatio") ) { return getDampingRatio_dyn(); }
		if (HX_FIELD_EQ(inName,"setDampingRatio") ) { return setDampingRatio_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"getReactionForce") ) { return getReactionForce_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"getReactionTorque") ) { return getReactionTorque_dyn(); }
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

Dynamic B2MouseJoint_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"K") ) { K=inValue.Cast< ::box2D::common::math::B2Mat22 >(); return inValue; }
		break;
	case 2:
		if (HX_FIELD_EQ(inName,"K1") ) { K1=inValue.Cast< ::box2D::common::math::B2Mat22 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"K2") ) { K2=inValue.Cast< ::box2D::common::math::B2Mat22 >(); return inValue; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"m_C") ) { m_C=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"m_mass") ) { m_mass=inValue.Cast< ::box2D::common::math::B2Mat22 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_beta") ) { m_beta=inValue.Cast< double >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"m_gamma") ) { m_gamma=inValue.Cast< double >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"m_target") ) { m_target=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"m_impulse") ) { m_impulse=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"m_maxForce") ) { m_maxForce=inValue.Cast< double >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"m_localAnchor") ) { m_localAnchor=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_frequencyHz") ) { m_frequencyHz=inValue.Cast< double >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"m_dampingRatio") ) { m_dampingRatio=inValue.Cast< double >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void B2MouseJoint_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("K"));
	outFields->push(HX_CSTRING("K1"));
	outFields->push(HX_CSTRING("K2"));
	outFields->push(HX_CSTRING("m_localAnchor"));
	outFields->push(HX_CSTRING("m_target"));
	outFields->push(HX_CSTRING("m_impulse"));
	outFields->push(HX_CSTRING("m_mass"));
	outFields->push(HX_CSTRING("m_C"));
	outFields->push(HX_CSTRING("m_maxForce"));
	outFields->push(HX_CSTRING("m_frequencyHz"));
	outFields->push(HX_CSTRING("m_dampingRatio"));
	outFields->push(HX_CSTRING("m_beta"));
	outFields->push(HX_CSTRING("m_gamma"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("getAnchorA"),
	HX_CSTRING("getAnchorB"),
	HX_CSTRING("getReactionForce"),
	HX_CSTRING("getReactionTorque"),
	HX_CSTRING("getTarget"),
	HX_CSTRING("setTarget"),
	HX_CSTRING("getMaxForce"),
	HX_CSTRING("setMaxForce"),
	HX_CSTRING("getFrequency"),
	HX_CSTRING("setFrequency"),
	HX_CSTRING("getDampingRatio"),
	HX_CSTRING("setDampingRatio"),
	HX_CSTRING("K"),
	HX_CSTRING("K1"),
	HX_CSTRING("K2"),
	HX_CSTRING("initVelocityConstraints"),
	HX_CSTRING("solveVelocityConstraints"),
	HX_CSTRING("solvePositionConstraints"),
	HX_CSTRING("m_localAnchor"),
	HX_CSTRING("m_target"),
	HX_CSTRING("m_impulse"),
	HX_CSTRING("m_mass"),
	HX_CSTRING("m_C"),
	HX_CSTRING("m_maxForce"),
	HX_CSTRING("m_frequencyHz"),
	HX_CSTRING("m_dampingRatio"),
	HX_CSTRING("m_beta"),
	HX_CSTRING("m_gamma"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class B2MouseJoint_obj::__mClass;

void B2MouseJoint_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.dynamics.joints.B2MouseJoint"), hx::TCanCast< B2MouseJoint_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void B2MouseJoint_obj::__boot()
{
}

} // end namespace box2D
} // end namespace dynamics
} // end namespace joints
