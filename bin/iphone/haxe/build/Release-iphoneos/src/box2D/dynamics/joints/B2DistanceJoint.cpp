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
#ifndef INCLUDED_box2D_dynamics_joints_B2DistanceJoint
#include <box2D/dynamics/joints/B2DistanceJoint.h>
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

Void B2DistanceJoint_obj::__construct(::box2D::dynamics::joints::B2DistanceJointDef def)
{
{
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",117)
	super::__construct(def);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",119)
	this->m_localAnchor1 = ::box2D::common::math::B2Vec2_obj::__new(null(),null());
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",120)
	this->m_localAnchor2 = ::box2D::common::math::B2Vec2_obj::__new(null(),null());
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",121)
	this->m_u = ::box2D::common::math::B2Vec2_obj::__new(null(),null());
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",124)
	::box2D::common::math::B2Mat22 tMat;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",125)
	double tX;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",126)
	double tY;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",127)
	this->m_localAnchor1->setV(def->localAnchorA);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",128)
	this->m_localAnchor2->setV(def->localAnchorB);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",130)
	this->m_length = def->length;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",131)
	this->m_frequencyHz = def->frequencyHz;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",132)
	this->m_dampingRatio = def->dampingRatio;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",133)
	this->m_impulse = 0.0;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",134)
	this->m_gamma = 0.0;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",135)
	this->m_bias = 0.0;
}
;
	return null();
}

B2DistanceJoint_obj::~B2DistanceJoint_obj() { }

Dynamic B2DistanceJoint_obj::__CreateEmpty() { return  new B2DistanceJoint_obj; }
hx::ObjectPtr< B2DistanceJoint_obj > B2DistanceJoint_obj::__new(::box2D::dynamics::joints::B2DistanceJointDef def)
{  hx::ObjectPtr< B2DistanceJoint_obj > result = new B2DistanceJoint_obj();
	result->__construct(def);
	return result;}

Dynamic B2DistanceJoint_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2DistanceJoint_obj > result = new B2DistanceJoint_obj();
	result->__construct(inArgs[0]);
	return result;}

::box2D::common::math::B2Vec2 B2DistanceJoint_obj::getAnchorA( ){
	HX_SOURCE_PUSH("B2DistanceJoint_obj::getAnchorA")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",54)
	return this->m_bodyA->getWorldPoint(this->m_localAnchor1);
}


HX_DEFINE_DYNAMIC_FUNC0(B2DistanceJoint_obj,getAnchorA,return )

::box2D::common::math::B2Vec2 B2DistanceJoint_obj::getAnchorB( ){
	HX_SOURCE_PUSH("B2DistanceJoint_obj::getAnchorB")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",58)
	return this->m_bodyB->getWorldPoint(this->m_localAnchor2);
}


HX_DEFINE_DYNAMIC_FUNC0(B2DistanceJoint_obj,getAnchorB,return )

::box2D::common::math::B2Vec2 B2DistanceJoint_obj::getReactionForce( double inv_dt){
	HX_SOURCE_PUSH("B2DistanceJoint_obj::getReactionForce")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",64)
	return ::box2D::common::math::B2Vec2_obj::__new(((inv_dt * this->m_impulse) * this->m_u->x),((inv_dt * this->m_impulse) * this->m_u->y));
}


HX_DEFINE_DYNAMIC_FUNC1(B2DistanceJoint_obj,getReactionForce,return )

double B2DistanceJoint_obj::getReactionTorque( double inv_dt){
	HX_SOURCE_PUSH("B2DistanceJoint_obj::getReactionTorque")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",72)
	return 0.0;
}


HX_DEFINE_DYNAMIC_FUNC1(B2DistanceJoint_obj,getReactionTorque,return )

double B2DistanceJoint_obj::getLength( ){
	HX_SOURCE_PUSH("B2DistanceJoint_obj::getLength")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",79)
	return this->m_length;
}


HX_DEFINE_DYNAMIC_FUNC0(B2DistanceJoint_obj,getLength,return )

Void B2DistanceJoint_obj::setLength( double length){
{
		HX_SOURCE_PUSH("B2DistanceJoint_obj::setLength")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",85)
		this->m_length = length;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2DistanceJoint_obj,setLength,(void))

double B2DistanceJoint_obj::getFrequency( ){
	HX_SOURCE_PUSH("B2DistanceJoint_obj::getFrequency")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",91)
	return this->m_frequencyHz;
}


HX_DEFINE_DYNAMIC_FUNC0(B2DistanceJoint_obj,getFrequency,return )

Void B2DistanceJoint_obj::setFrequency( double hz){
{
		HX_SOURCE_PUSH("B2DistanceJoint_obj::setFrequency")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",97)
		this->m_frequencyHz = hz;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2DistanceJoint_obj,setFrequency,(void))

double B2DistanceJoint_obj::getDampingRatio( ){
	HX_SOURCE_PUSH("B2DistanceJoint_obj::getDampingRatio")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",103)
	return this->m_dampingRatio;
}


HX_DEFINE_DYNAMIC_FUNC0(B2DistanceJoint_obj,getDampingRatio,return )

Void B2DistanceJoint_obj::setDampingRatio( double ratio){
{
		HX_SOURCE_PUSH("B2DistanceJoint_obj::setDampingRatio")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",109)
		this->m_dampingRatio = ratio;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2DistanceJoint_obj,setDampingRatio,(void))

Void B2DistanceJoint_obj::initVelocityConstraints( ::box2D::dynamics::B2TimeStep step){
{
		HX_SOURCE_PUSH("B2DistanceJoint_obj::initVelocityConstraints")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",140)
		::box2D::common::math::B2Mat22 tMat;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",141)
		double tX;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",143)
		::box2D::dynamics::B2Body bA = this->m_bodyA;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",144)
		::box2D::dynamics::B2Body bB = this->m_bodyB;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",148)
		tMat = bA->m_xf->R;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",149)
		double r1X = (this->m_localAnchor1->x - bA->m_sweep->localCenter->x);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",150)
		double r1Y = (this->m_localAnchor1->y - bA->m_sweep->localCenter->y);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",151)
		tX = ((tMat->col1->x * r1X) + (tMat->col2->x * r1Y));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",152)
		r1Y = ((tMat->col1->y * r1X) + (tMat->col2->y * r1Y));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",153)
		r1X = tX;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",155)
		tMat = bB->m_xf->R;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",156)
		double r2X = (this->m_localAnchor2->x - bB->m_sweep->localCenter->x);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",157)
		double r2Y = (this->m_localAnchor2->y - bB->m_sweep->localCenter->y);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",158)
		tX = ((tMat->col1->x * r2X) + (tMat->col2->x * r2Y));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",159)
		r2Y = ((tMat->col1->y * r2X) + (tMat->col2->y * r2Y));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",160)
		r2X = tX;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",163)
		this->m_u->x = (((bB->m_sweep->c->x + r2X) - bA->m_sweep->c->x) - r1X);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",164)
		this->m_u->y = (((bB->m_sweep->c->y + r2Y) - bA->m_sweep->c->y) - r1Y);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",168)
		double length = ::Math_obj::sqrt(((this->m_u->x * this->m_u->x) + (this->m_u->y * this->m_u->y)));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",169)
		if (((length > ::box2D::common::B2Settings_obj::b2_linearSlop))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",170)
			this->m_u->multiply((double(1.0) / double(length)));
		}
		else{
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",175)
			this->m_u->setZero();
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",180)
		double cr1u = ((r1X * this->m_u->y) - (r1Y * this->m_u->x));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",182)
		double cr2u = ((r2X * this->m_u->y) - (r2Y * this->m_u->x));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",184)
		double invMass = (((bA->m_invMass + ((bA->m_invI * cr1u) * cr1u)) + bB->m_invMass) + ((bB->m_invI * cr2u) * cr2u));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",185)
		this->m_mass = (  (((invMass != 0.0))) ? double((double(1.0) / double(invMass))) : double(0.0) );
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",187)
		if (((this->m_frequencyHz > 0.0))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",189)
			double C = (length - this->m_length);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",192)
			double omega = ((2.0 * ::Math_obj::PI) * this->m_frequencyHz);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",195)
			double d = (((2.0 * this->m_mass) * this->m_dampingRatio) * omega);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",198)
			double k = ((this->m_mass * omega) * omega);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",201)
			this->m_gamma = (step->dt * ((d + (step->dt * k))));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",202)
			this->m_gamma = (  (((this->m_gamma != 0.0))) ? double((double((int)1) / double(this->m_gamma))) : double(0.0) );
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",203)
			this->m_bias = (((C * step->dt) * k) * this->m_gamma);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",205)
			this->m_mass = (invMass + this->m_gamma);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",206)
			this->m_mass = (  (((this->m_mass != 0.0))) ? double((double(1.0) / double(this->m_mass))) : double(0.0) );
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",209)
		if ((step->warmStarting)){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",212)
			hx::MultEq(this->m_impulse,step->dtRatio);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",215)
			double PX = (this->m_impulse * this->m_u->x);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",216)
			double PY = (this->m_impulse * this->m_u->y);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",218)
			hx::SubEq(bA->m_linearVelocity->x,(bA->m_invMass * PX));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",219)
			hx::SubEq(bA->m_linearVelocity->y,(bA->m_invMass * PY));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",221)
			hx::SubEq(bA->m_angularVelocity,(bA->m_invI * (((r1X * PY) - (r1Y * PX)))));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",223)
			hx::AddEq(bB->m_linearVelocity->x,(bB->m_invMass * PX));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",224)
			hx::AddEq(bB->m_linearVelocity->y,(bB->m_invMass * PY));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",226)
			hx::AddEq(bB->m_angularVelocity,(bB->m_invI * (((r2X * PY) - (r2Y * PX)))));
		}
		else{
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",229)
			this->m_impulse = 0.0;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2DistanceJoint_obj,initVelocityConstraints,(void))

Void B2DistanceJoint_obj::solveVelocityConstraints( ::box2D::dynamics::B2TimeStep step){
{
		HX_SOURCE_PUSH("B2DistanceJoint_obj::solveVelocityConstraints")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",238)
		::box2D::common::math::B2Mat22 tMat;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",240)
		::box2D::dynamics::B2Body bA = this->m_bodyA;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",241)
		::box2D::dynamics::B2Body bB = this->m_bodyB;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",244)
		tMat = bA->m_xf->R;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",245)
		double r1X = (this->m_localAnchor1->x - bA->m_sweep->localCenter->x);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",246)
		double r1Y = (this->m_localAnchor1->y - bA->m_sweep->localCenter->y);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",247)
		double tX = ((tMat->col1->x * r1X) + (tMat->col2->x * r1Y));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",248)
		r1Y = ((tMat->col1->y * r1X) + (tMat->col2->y * r1Y));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",249)
		r1X = tX;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",251)
		tMat = bB->m_xf->R;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",252)
		double r2X = (this->m_localAnchor2->x - bB->m_sweep->localCenter->x);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",253)
		double r2Y = (this->m_localAnchor2->y - bB->m_sweep->localCenter->y);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",254)
		tX = ((tMat->col1->x * r2X) + (tMat->col2->x * r2Y));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",255)
		r2Y = ((tMat->col1->y * r2X) + (tMat->col2->y * r2Y));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",256)
		r2X = tX;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",260)
		double v1X = (bA->m_linearVelocity->x + (-(bA->m_angularVelocity) * r1Y));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",261)
		double v1Y = (bA->m_linearVelocity->y + (bA->m_angularVelocity * r1X));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",263)
		double v2X = (bB->m_linearVelocity->x + (-(bB->m_angularVelocity) * r2Y));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",264)
		double v2Y = (bB->m_linearVelocity->y + (bB->m_angularVelocity * r2X));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",266)
		double Cdot = ((this->m_u->x * ((v2X - v1X))) + (this->m_u->y * ((v2Y - v1Y))));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",268)
		double impulse = (-(this->m_mass) * (((Cdot + this->m_bias) + (this->m_gamma * this->m_impulse))));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",269)
		hx::AddEq(this->m_impulse,impulse);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",272)
		double PX = (impulse * this->m_u->x);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",273)
		double PY = (impulse * this->m_u->y);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",275)
		hx::SubEq(bA->m_linearVelocity->x,(bA->m_invMass * PX));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",276)
		hx::SubEq(bA->m_linearVelocity->y,(bA->m_invMass * PY));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",278)
		hx::SubEq(bA->m_angularVelocity,(bA->m_invI * (((r1X * PY) - (r1Y * PX)))));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",280)
		hx::AddEq(bB->m_linearVelocity->x,(bB->m_invMass * PX));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",281)
		hx::AddEq(bB->m_linearVelocity->y,(bB->m_invMass * PY));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",283)
		hx::AddEq(bB->m_angularVelocity,(bB->m_invI * (((r2X * PY) - (r2Y * PX)))));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2DistanceJoint_obj,solveVelocityConstraints,(void))

bool B2DistanceJoint_obj::solvePositionConstraints( double baumgarte){
	HX_SOURCE_PUSH("B2DistanceJoint_obj::solvePositionConstraints")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",290)
	::box2D::common::math::B2Mat22 tMat;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",292)
	if (((this->m_frequencyHz > 0.0))){
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",293)
		return true;
	}
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",298)
	::box2D::dynamics::B2Body bA = this->m_bodyA;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",299)
	::box2D::dynamics::B2Body bB = this->m_bodyB;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",302)
	tMat = bA->m_xf->R;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",303)
	double r1X = (this->m_localAnchor1->x - bA->m_sweep->localCenter->x);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",304)
	double r1Y = (this->m_localAnchor1->y - bA->m_sweep->localCenter->y);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",305)
	double tX = ((tMat->col1->x * r1X) + (tMat->col2->x * r1Y));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",306)
	r1Y = ((tMat->col1->y * r1X) + (tMat->col2->y * r1Y));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",307)
	r1X = tX;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",309)
	tMat = bB->m_xf->R;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",310)
	double r2X = (this->m_localAnchor2->x - bB->m_sweep->localCenter->x);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",311)
	double r2Y = (this->m_localAnchor2->y - bB->m_sweep->localCenter->y);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",312)
	tX = ((tMat->col1->x * r2X) + (tMat->col2->x * r2Y));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",313)
	r2Y = ((tMat->col1->y * r2X) + (tMat->col2->y * r2Y));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",314)
	r2X = tX;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",317)
	double dX = (((bB->m_sweep->c->x + r2X) - bA->m_sweep->c->x) - r1X);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",318)
	double dY = (((bB->m_sweep->c->y + r2Y) - bA->m_sweep->c->y) - r1Y);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",321)
	double length = ::Math_obj::sqrt(((dX * dX) + (dY * dY)));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",322)
	hx::DivEq(dX,length);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",323)
	hx::DivEq(dY,length);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",325)
	double C = (length - this->m_length);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",326)
	C = ::box2D::common::math::B2Math_obj::clamp(C,-(::box2D::common::B2Settings_obj::b2_maxLinearCorrection),::box2D::common::B2Settings_obj::b2_maxLinearCorrection);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",328)
	double impulse = (-(this->m_mass) * C);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",330)
	this->m_u->set(dX,dY);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",332)
	double PX = (impulse * this->m_u->x);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",333)
	double PY = (impulse * this->m_u->y);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",336)
	hx::SubEq(bA->m_sweep->c->x,(bA->m_invMass * PX));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",337)
	hx::SubEq(bA->m_sweep->c->y,(bA->m_invMass * PY));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",339)
	hx::SubEq(bA->m_sweep->a,(bA->m_invI * (((r1X * PY) - (r1Y * PX)))));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",341)
	hx::AddEq(bB->m_sweep->c->x,(bB->m_invMass * PX));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",342)
	hx::AddEq(bB->m_sweep->c->y,(bB->m_invMass * PY));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",344)
	hx::AddEq(bB->m_sweep->a,(bB->m_invI * (((r2X * PY) - (r2Y * PX)))));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",346)
	bA->synchronizeTransform();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",347)
	bB->synchronizeTransform();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2DistanceJoint.hx",349)
	return (::box2D::common::math::B2Math_obj::abs(C) < ::box2D::common::B2Settings_obj::b2_linearSlop);
}


HX_DEFINE_DYNAMIC_FUNC1(B2DistanceJoint_obj,solvePositionConstraints,return )


B2DistanceJoint_obj::B2DistanceJoint_obj()
{
}

void B2DistanceJoint_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(B2DistanceJoint);
	HX_MARK_MEMBER_NAME(m_localAnchor1,"m_localAnchor1");
	HX_MARK_MEMBER_NAME(m_localAnchor2,"m_localAnchor2");
	HX_MARK_MEMBER_NAME(m_u,"m_u");
	HX_MARK_MEMBER_NAME(m_frequencyHz,"m_frequencyHz");
	HX_MARK_MEMBER_NAME(m_dampingRatio,"m_dampingRatio");
	HX_MARK_MEMBER_NAME(m_gamma,"m_gamma");
	HX_MARK_MEMBER_NAME(m_bias,"m_bias");
	HX_MARK_MEMBER_NAME(m_impulse,"m_impulse");
	HX_MARK_MEMBER_NAME(m_mass,"m_mass");
	HX_MARK_MEMBER_NAME(m_length,"m_length");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic B2DistanceJoint_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"m_u") ) { return m_u; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"m_bias") ) { return m_bias; }
		if (HX_FIELD_EQ(inName,"m_mass") ) { return m_mass; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"m_gamma") ) { return m_gamma; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"m_length") ) { return m_length; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"getLength") ) { return getLength_dyn(); }
		if (HX_FIELD_EQ(inName,"setLength") ) { return setLength_dyn(); }
		if (HX_FIELD_EQ(inName,"m_impulse") ) { return m_impulse; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"getAnchorA") ) { return getAnchorA_dyn(); }
		if (HX_FIELD_EQ(inName,"getAnchorB") ) { return getAnchorB_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"getFrequency") ) { return getFrequency_dyn(); }
		if (HX_FIELD_EQ(inName,"setFrequency") ) { return setFrequency_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"m_frequencyHz") ) { return m_frequencyHz; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"m_localAnchor1") ) { return m_localAnchor1; }
		if (HX_FIELD_EQ(inName,"m_localAnchor2") ) { return m_localAnchor2; }
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

Dynamic B2DistanceJoint_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"m_u") ) { m_u=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"m_bias") ) { m_bias=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_mass") ) { m_mass=inValue.Cast< double >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"m_gamma") ) { m_gamma=inValue.Cast< double >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"m_length") ) { m_length=inValue.Cast< double >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"m_impulse") ) { m_impulse=inValue.Cast< double >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"m_frequencyHz") ) { m_frequencyHz=inValue.Cast< double >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"m_localAnchor1") ) { m_localAnchor1=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_localAnchor2") ) { m_localAnchor2=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_dampingRatio") ) { m_dampingRatio=inValue.Cast< double >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void B2DistanceJoint_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("m_localAnchor1"));
	outFields->push(HX_CSTRING("m_localAnchor2"));
	outFields->push(HX_CSTRING("m_u"));
	outFields->push(HX_CSTRING("m_frequencyHz"));
	outFields->push(HX_CSTRING("m_dampingRatio"));
	outFields->push(HX_CSTRING("m_gamma"));
	outFields->push(HX_CSTRING("m_bias"));
	outFields->push(HX_CSTRING("m_impulse"));
	outFields->push(HX_CSTRING("m_mass"));
	outFields->push(HX_CSTRING("m_length"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("getAnchorA"),
	HX_CSTRING("getAnchorB"),
	HX_CSTRING("getReactionForce"),
	HX_CSTRING("getReactionTorque"),
	HX_CSTRING("getLength"),
	HX_CSTRING("setLength"),
	HX_CSTRING("getFrequency"),
	HX_CSTRING("setFrequency"),
	HX_CSTRING("getDampingRatio"),
	HX_CSTRING("setDampingRatio"),
	HX_CSTRING("initVelocityConstraints"),
	HX_CSTRING("solveVelocityConstraints"),
	HX_CSTRING("solvePositionConstraints"),
	HX_CSTRING("m_localAnchor1"),
	HX_CSTRING("m_localAnchor2"),
	HX_CSTRING("m_u"),
	HX_CSTRING("m_frequencyHz"),
	HX_CSTRING("m_dampingRatio"),
	HX_CSTRING("m_gamma"),
	HX_CSTRING("m_bias"),
	HX_CSTRING("m_impulse"),
	HX_CSTRING("m_mass"),
	HX_CSTRING("m_length"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class B2DistanceJoint_obj::__mClass;

void B2DistanceJoint_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.dynamics.joints.B2DistanceJoint"), hx::TCanCast< B2DistanceJoint_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void B2DistanceJoint_obj::__boot()
{
}

} // end namespace box2D
} // end namespace dynamics
} // end namespace joints
