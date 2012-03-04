#include <hxcpp.h>

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
#ifndef INCLUDED_box2D_dynamics_joints_B2FrictionJoint
#include <box2D/dynamics/joints/B2FrictionJoint.h>
#endif
#ifndef INCLUDED_box2D_dynamics_joints_B2FrictionJointDef
#include <box2D/dynamics/joints/B2FrictionJointDef.h>
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

Void B2FrictionJoint_obj::__construct(::box2D::dynamics::joints::B2FrictionJointDef def)
{
{
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2FrictionJoint.hx",94)
	super::__construct(def);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2FrictionJoint.hx",96)
	this->m_localAnchorA = ::box2D::common::math::B2Vec2_obj::__new(null(),null());
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2FrictionJoint.hx",97)
	this->m_localAnchorB = ::box2D::common::math::B2Vec2_obj::__new(null(),null());
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2FrictionJoint.hx",98)
	this->m_linearMass = ::box2D::common::math::B2Mat22_obj::__new();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2FrictionJoint.hx",99)
	this->m_linearImpulse = ::box2D::common::math::B2Vec2_obj::__new(null(),null());
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2FrictionJoint.hx",101)
	this->m_localAnchorA->setV(def->localAnchorA);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2FrictionJoint.hx",102)
	this->m_localAnchorB->setV(def->localAnchorB);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2FrictionJoint.hx",104)
	this->m_linearMass->setZero();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2FrictionJoint.hx",105)
	this->m_angularMass = 0.0;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2FrictionJoint.hx",107)
	this->m_linearImpulse->setZero();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2FrictionJoint.hx",108)
	this->m_angularImpulse = 0.0;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2FrictionJoint.hx",110)
	this->m_maxForce = def->maxForce;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2FrictionJoint.hx",111)
	this->m_maxTorque = def->maxTorque;
}
;
	return null();
}

B2FrictionJoint_obj::~B2FrictionJoint_obj() { }

Dynamic B2FrictionJoint_obj::__CreateEmpty() { return  new B2FrictionJoint_obj; }
hx::ObjectPtr< B2FrictionJoint_obj > B2FrictionJoint_obj::__new(::box2D::dynamics::joints::B2FrictionJointDef def)
{  hx::ObjectPtr< B2FrictionJoint_obj > result = new B2FrictionJoint_obj();
	result->__construct(def);
	return result;}

Dynamic B2FrictionJoint_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2FrictionJoint_obj > result = new B2FrictionJoint_obj();
	result->__construct(inArgs[0]);
	return result;}

::box2D::common::math::B2Vec2 B2FrictionJoint_obj::getAnchorA( ){
	HX_SOURCE_PUSH("B2FrictionJoint_obj::getAnchorA")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2FrictionJoint.hx",49)
	return this->m_bodyA->getWorldPoint(this->m_localAnchorA);
}


HX_DEFINE_DYNAMIC_FUNC0(B2FrictionJoint_obj,getAnchorA,return )

::box2D::common::math::B2Vec2 B2FrictionJoint_obj::getAnchorB( ){
	HX_SOURCE_PUSH("B2FrictionJoint_obj::getAnchorB")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2FrictionJoint.hx",53)
	return this->m_bodyB->getWorldPoint(this->m_localAnchorB);
}


HX_DEFINE_DYNAMIC_FUNC0(B2FrictionJoint_obj,getAnchorB,return )

::box2D::common::math::B2Vec2 B2FrictionJoint_obj::getReactionForce( double inv_dt){
	HX_SOURCE_PUSH("B2FrictionJoint_obj::getReactionForce")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2FrictionJoint.hx",59)
	return ::box2D::common::math::B2Vec2_obj::__new((inv_dt * this->m_linearImpulse->x),(inv_dt * this->m_linearImpulse->y));
}


HX_DEFINE_DYNAMIC_FUNC1(B2FrictionJoint_obj,getReactionForce,return )

double B2FrictionJoint_obj::getReactionTorque( double inv_dt){
	HX_SOURCE_PUSH("B2FrictionJoint_obj::getReactionTorque")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2FrictionJoint.hx",65)
	return (inv_dt * this->m_angularImpulse);
}


HX_DEFINE_DYNAMIC_FUNC1(B2FrictionJoint_obj,getReactionTorque,return )

Void B2FrictionJoint_obj::setMaxForce( double force){
{
		HX_SOURCE_PUSH("B2FrictionJoint_obj::setMaxForce")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2FrictionJoint.hx",71)
		this->m_maxForce = force;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2FrictionJoint_obj,setMaxForce,(void))

double B2FrictionJoint_obj::getMaxForce( ){
	HX_SOURCE_PUSH("B2FrictionJoint_obj::getMaxForce")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2FrictionJoint.hx",76)
	return this->m_maxForce;
}


HX_DEFINE_DYNAMIC_FUNC0(B2FrictionJoint_obj,getMaxForce,return )

Void B2FrictionJoint_obj::setMaxTorque( double torque){
{
		HX_SOURCE_PUSH("B2FrictionJoint_obj::setMaxTorque")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2FrictionJoint.hx",81)
		this->m_maxTorque = torque;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2FrictionJoint_obj,setMaxTorque,(void))

double B2FrictionJoint_obj::getMaxTorque( ){
	HX_SOURCE_PUSH("B2FrictionJoint_obj::getMaxTorque")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2FrictionJoint.hx",86)
	return this->m_maxTorque;
}


HX_DEFINE_DYNAMIC_FUNC0(B2FrictionJoint_obj,getMaxTorque,return )

Void B2FrictionJoint_obj::initVelocityConstraints( ::box2D::dynamics::B2TimeStep step){
{
		HX_SOURCE_PUSH("B2FrictionJoint_obj::initVelocityConstraints")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2FrictionJoint.hx",115)
		::box2D::common::math::B2Mat22 tMat;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2FrictionJoint.hx",116)
		double tX;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2FrictionJoint.hx",118)
		::box2D::dynamics::B2Body bA = this->m_bodyA;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2FrictionJoint.hx",119)
		::box2D::dynamics::B2Body bB = this->m_bodyB;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2FrictionJoint.hx",123)
		tMat = bA->m_xf->R;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2FrictionJoint.hx",124)
		double rAX = (this->m_localAnchorA->x - bA->m_sweep->localCenter->x);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2FrictionJoint.hx",125)
		double rAY = (this->m_localAnchorA->y - bA->m_sweep->localCenter->y);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2FrictionJoint.hx",126)
		tX = ((tMat->col1->x * rAX) + (tMat->col2->x * rAY));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2FrictionJoint.hx",127)
		rAY = ((tMat->col1->y * rAX) + (tMat->col2->y * rAY));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2FrictionJoint.hx",128)
		rAX = tX;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2FrictionJoint.hx",130)
		tMat = bB->m_xf->R;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2FrictionJoint.hx",131)
		double rBX = (this->m_localAnchorB->x - bB->m_sweep->localCenter->x);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2FrictionJoint.hx",132)
		double rBY = (this->m_localAnchorB->y - bB->m_sweep->localCenter->y);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2FrictionJoint.hx",133)
		tX = ((tMat->col1->x * rBX) + (tMat->col2->x * rBY));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2FrictionJoint.hx",134)
		rBY = ((tMat->col1->y * rBX) + (tMat->col2->y * rBY));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2FrictionJoint.hx",135)
		rBX = tX;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2FrictionJoint.hx",146)
		double mA = bA->m_invMass;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2FrictionJoint.hx",147)
		double mB = bB->m_invMass;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2FrictionJoint.hx",148)
		double iA = bA->m_invI;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2FrictionJoint.hx",149)
		double iB = bB->m_invI;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2FrictionJoint.hx",151)
		::box2D::common::math::B2Mat22 K = ::box2D::common::math::B2Mat22_obj::__new();
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2FrictionJoint.hx",152)
		K->col1->x = (mA + mB);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2FrictionJoint.hx",152)
		K->col2->x = 0.0;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2FrictionJoint.hx",153)
		K->col1->y = 0.0;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2FrictionJoint.hx",153)
		K->col2->y = (mA + mB);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2FrictionJoint.hx",155)
		hx::AddEq(K->col1->x,((iA * rAY) * rAY));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2FrictionJoint.hx",155)
		hx::AddEq(K->col2->x,((-(iA) * rAX) * rAY));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2FrictionJoint.hx",156)
		hx::AddEq(K->col1->y,((-(iA) * rAX) * rAY));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2FrictionJoint.hx",156)
		hx::AddEq(K->col2->y,((iA * rAX) * rAX));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2FrictionJoint.hx",158)
		hx::AddEq(K->col1->x,((iB * rBY) * rBY));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2FrictionJoint.hx",158)
		hx::AddEq(K->col2->x,((-(iB) * rBX) * rBY));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2FrictionJoint.hx",159)
		hx::AddEq(K->col1->y,((-(iB) * rBX) * rBY));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2FrictionJoint.hx",159)
		hx::AddEq(K->col2->y,((iB * rBX) * rBX));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2FrictionJoint.hx",161)
		K->getInverse(this->m_linearMass);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2FrictionJoint.hx",163)
		this->m_angularMass = (iA + iB);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2FrictionJoint.hx",164)
		if (((this->m_angularMass > 0.0))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2FrictionJoint.hx",165)
			this->m_angularMass = (double(1.0) / double(this->m_angularMass));
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2FrictionJoint.hx",169)
		if ((step->warmStarting)){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2FrictionJoint.hx",172)
			hx::MultEq(this->m_linearImpulse->x,step->dtRatio);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2FrictionJoint.hx",173)
			hx::MultEq(this->m_linearImpulse->y,step->dtRatio);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2FrictionJoint.hx",174)
			hx::MultEq(this->m_angularImpulse,step->dtRatio);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2FrictionJoint.hx",176)
			::box2D::common::math::B2Vec2 P = this->m_linearImpulse;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2FrictionJoint.hx",178)
			hx::SubEq(bA->m_linearVelocity->x,(mA * P->x));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2FrictionJoint.hx",179)
			hx::SubEq(bA->m_linearVelocity->y,(mA * P->y));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2FrictionJoint.hx",180)
			hx::SubEq(bA->m_angularVelocity,(iA * ((((rAX * P->y) - (rAY * P->x)) + this->m_angularImpulse))));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2FrictionJoint.hx",182)
			hx::AddEq(bB->m_linearVelocity->x,(mB * P->x));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2FrictionJoint.hx",183)
			hx::AddEq(bB->m_linearVelocity->y,(mB * P->y));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2FrictionJoint.hx",184)
			hx::AddEq(bB->m_angularVelocity,(iB * ((((rBX * P->y) - (rBY * P->x)) + this->m_angularImpulse))));
		}
		else{
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2FrictionJoint.hx",188)
			this->m_linearImpulse->setZero();
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2FrictionJoint.hx",189)
			this->m_angularImpulse = 0.0;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2FrictionJoint_obj,initVelocityConstraints,(void))

Void B2FrictionJoint_obj::solveVelocityConstraints( ::box2D::dynamics::B2TimeStep step){
{
		HX_SOURCE_PUSH("B2FrictionJoint_obj::solveVelocityConstraints")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2FrictionJoint.hx",198)
		::box2D::common::math::B2Mat22 tMat;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2FrictionJoint.hx",199)
		double tX;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2FrictionJoint.hx",201)
		::box2D::dynamics::B2Body bA = this->m_bodyA;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2FrictionJoint.hx",202)
		::box2D::dynamics::B2Body bB = this->m_bodyB;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2FrictionJoint.hx",204)
		::box2D::common::math::B2Vec2 vA = bA->m_linearVelocity;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2FrictionJoint.hx",205)
		double wA = bA->m_angularVelocity;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2FrictionJoint.hx",206)
		::box2D::common::math::B2Vec2 vB = bB->m_linearVelocity;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2FrictionJoint.hx",207)
		double wB = bB->m_angularVelocity;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2FrictionJoint.hx",209)
		double mA = bA->m_invMass;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2FrictionJoint.hx",210)
		double mB = bB->m_invMass;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2FrictionJoint.hx",211)
		double iA = bA->m_invI;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2FrictionJoint.hx",212)
		double iB = bB->m_invI;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2FrictionJoint.hx",215)
		tMat = bA->m_xf->R;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2FrictionJoint.hx",216)
		double rAX = (this->m_localAnchorA->x - bA->m_sweep->localCenter->x);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2FrictionJoint.hx",217)
		double rAY = (this->m_localAnchorA->y - bA->m_sweep->localCenter->y);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2FrictionJoint.hx",218)
		tX = ((tMat->col1->x * rAX) + (tMat->col2->x * rAY));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2FrictionJoint.hx",219)
		rAY = ((tMat->col1->y * rAX) + (tMat->col2->y * rAY));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2FrictionJoint.hx",220)
		rAX = tX;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2FrictionJoint.hx",222)
		tMat = bB->m_xf->R;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2FrictionJoint.hx",223)
		double rBX = (this->m_localAnchorB->x - bB->m_sweep->localCenter->x);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2FrictionJoint.hx",224)
		double rBY = (this->m_localAnchorB->y - bB->m_sweep->localCenter->y);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2FrictionJoint.hx",225)
		tX = ((tMat->col1->x * rBX) + (tMat->col2->x * rBY));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2FrictionJoint.hx",226)
		rBY = ((tMat->col1->y * rBX) + (tMat->col2->y * rBY));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2FrictionJoint.hx",227)
		rBX = tX;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2FrictionJoint.hx",229)
		double maxImpulse;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2FrictionJoint.hx",232)
		{
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2FrictionJoint.hx",233)
			double Cdot = (wB - wA);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2FrictionJoint.hx",234)
			double impulse = (-(this->m_angularMass) * Cdot);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2FrictionJoint.hx",236)
			double oldImpulse = this->m_angularImpulse;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2FrictionJoint.hx",237)
			maxImpulse = (step->dt * this->m_maxTorque);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2FrictionJoint.hx",238)
			this->m_angularImpulse = ::box2D::common::math::B2Math_obj::clamp((this->m_angularImpulse + impulse),-(maxImpulse),maxImpulse);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2FrictionJoint.hx",239)
			impulse = (this->m_angularImpulse - oldImpulse);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2FrictionJoint.hx",241)
			hx::SubEq(wA,(iA * impulse));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2FrictionJoint.hx",242)
			hx::AddEq(wB,(iB * impulse));
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2FrictionJoint.hx",246)
		{
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2FrictionJoint.hx",248)
			double CdotX = (((vB->x - (wB * rBY)) - vA->x) + (wA * rAY));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2FrictionJoint.hx",249)
			double CdotY = (((vB->y + (wB * rBX)) - vA->y) - (wA * rAX));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2FrictionJoint.hx",251)
			::box2D::common::math::B2Vec2 impulseV = ::box2D::common::math::B2Math_obj::mulMV(this->m_linearMass,::box2D::common::math::B2Vec2_obj::__new(-(CdotX),-(CdotY)));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2FrictionJoint.hx",252)
			::box2D::common::math::B2Vec2 oldImpulseV = this->m_linearImpulse->copy();
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2FrictionJoint.hx",254)
			this->m_linearImpulse->add(impulseV);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2FrictionJoint.hx",256)
			maxImpulse = (step->dt * this->m_maxForce);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2FrictionJoint.hx",258)
			if (((this->m_linearImpulse->lengthSquared() > (maxImpulse * maxImpulse)))){
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2FrictionJoint.hx",260)
				this->m_linearImpulse->normalize();
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2FrictionJoint.hx",261)
				this->m_linearImpulse->multiply(maxImpulse);
			}
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2FrictionJoint.hx",264)
			impulseV = ::box2D::common::math::B2Math_obj::subtractVV(this->m_linearImpulse,oldImpulseV);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2FrictionJoint.hx",266)
			hx::SubEq(vA->x,(mA * impulseV->x));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2FrictionJoint.hx",267)
			hx::SubEq(vA->y,(mA * impulseV->y));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2FrictionJoint.hx",268)
			hx::SubEq(wA,(iA * (((rAX * impulseV->y) - (rAY * impulseV->x)))));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2FrictionJoint.hx",270)
			hx::AddEq(vB->x,(mB * impulseV->x));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2FrictionJoint.hx",271)
			hx::AddEq(vB->y,(mB * impulseV->y));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2FrictionJoint.hx",272)
			hx::AddEq(wB,(iB * (((rBX * impulseV->y) - (rBY * impulseV->x)))));
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2FrictionJoint.hx",277)
		bA->m_angularVelocity = wA;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2FrictionJoint.hx",279)
		bB->m_angularVelocity = wB;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2FrictionJoint_obj,solveVelocityConstraints,(void))

bool B2FrictionJoint_obj::solvePositionConstraints( double baumgarte){
	HX_SOURCE_PUSH("B2FrictionJoint_obj::solvePositionConstraints")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2FrictionJoint.hx",284)
	return true;
}


HX_DEFINE_DYNAMIC_FUNC1(B2FrictionJoint_obj,solvePositionConstraints,return )


B2FrictionJoint_obj::B2FrictionJoint_obj()
{
}

void B2FrictionJoint_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(B2FrictionJoint);
	HX_MARK_MEMBER_NAME(m_localAnchorA,"m_localAnchorA");
	HX_MARK_MEMBER_NAME(m_localAnchorB,"m_localAnchorB");
	HX_MARK_MEMBER_NAME(m_linearMass,"m_linearMass");
	HX_MARK_MEMBER_NAME(m_angularMass,"m_angularMass");
	HX_MARK_MEMBER_NAME(m_linearImpulse,"m_linearImpulse");
	HX_MARK_MEMBER_NAME(m_angularImpulse,"m_angularImpulse");
	HX_MARK_MEMBER_NAME(m_maxForce,"m_maxForce");
	HX_MARK_MEMBER_NAME(m_maxTorque,"m_maxTorque");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic B2FrictionJoint_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 10:
		if (HX_FIELD_EQ(inName,"getAnchorA") ) { return getAnchorA_dyn(); }
		if (HX_FIELD_EQ(inName,"getAnchorB") ) { return getAnchorB_dyn(); }
		if (HX_FIELD_EQ(inName,"m_maxForce") ) { return m_maxForce; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"setMaxForce") ) { return setMaxForce_dyn(); }
		if (HX_FIELD_EQ(inName,"getMaxForce") ) { return getMaxForce_dyn(); }
		if (HX_FIELD_EQ(inName,"m_maxTorque") ) { return m_maxTorque; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"setMaxTorque") ) { return setMaxTorque_dyn(); }
		if (HX_FIELD_EQ(inName,"getMaxTorque") ) { return getMaxTorque_dyn(); }
		if (HX_FIELD_EQ(inName,"m_linearMass") ) { return m_linearMass; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"m_angularMass") ) { return m_angularMass; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"m_localAnchorA") ) { return m_localAnchorA; }
		if (HX_FIELD_EQ(inName,"m_localAnchorB") ) { return m_localAnchorB; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"m_linearImpulse") ) { return m_linearImpulse; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"getReactionForce") ) { return getReactionForce_dyn(); }
		if (HX_FIELD_EQ(inName,"m_angularImpulse") ) { return m_angularImpulse; }
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

Dynamic B2FrictionJoint_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 10:
		if (HX_FIELD_EQ(inName,"m_maxForce") ) { m_maxForce=inValue.Cast< double >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"m_maxTorque") ) { m_maxTorque=inValue.Cast< double >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"m_linearMass") ) { m_linearMass=inValue.Cast< ::box2D::common::math::B2Mat22 >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"m_angularMass") ) { m_angularMass=inValue.Cast< double >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"m_localAnchorA") ) { m_localAnchorA=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_localAnchorB") ) { m_localAnchorB=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"m_linearImpulse") ) { m_linearImpulse=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"m_angularImpulse") ) { m_angularImpulse=inValue.Cast< double >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void B2FrictionJoint_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("m_localAnchorA"));
	outFields->push(HX_CSTRING("m_localAnchorB"));
	outFields->push(HX_CSTRING("m_linearMass"));
	outFields->push(HX_CSTRING("m_angularMass"));
	outFields->push(HX_CSTRING("m_linearImpulse"));
	outFields->push(HX_CSTRING("m_angularImpulse"));
	outFields->push(HX_CSTRING("m_maxForce"));
	outFields->push(HX_CSTRING("m_maxTorque"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("getAnchorA"),
	HX_CSTRING("getAnchorB"),
	HX_CSTRING("getReactionForce"),
	HX_CSTRING("getReactionTorque"),
	HX_CSTRING("setMaxForce"),
	HX_CSTRING("getMaxForce"),
	HX_CSTRING("setMaxTorque"),
	HX_CSTRING("getMaxTorque"),
	HX_CSTRING("initVelocityConstraints"),
	HX_CSTRING("solveVelocityConstraints"),
	HX_CSTRING("solvePositionConstraints"),
	HX_CSTRING("m_localAnchorA"),
	HX_CSTRING("m_localAnchorB"),
	HX_CSTRING("m_linearMass"),
	HX_CSTRING("m_angularMass"),
	HX_CSTRING("m_linearImpulse"),
	HX_CSTRING("m_angularImpulse"),
	HX_CSTRING("m_maxForce"),
	HX_CSTRING("m_maxTorque"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class B2FrictionJoint_obj::__mClass;

void B2FrictionJoint_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.dynamics.joints.B2FrictionJoint"), hx::TCanCast< B2FrictionJoint_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void B2FrictionJoint_obj::__boot()
{
}

} // end namespace box2D
} // end namespace dynamics
} // end namespace joints
