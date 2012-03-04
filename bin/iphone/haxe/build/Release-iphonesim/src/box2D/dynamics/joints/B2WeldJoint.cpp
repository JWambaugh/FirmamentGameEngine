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
#ifndef INCLUDED_box2D_dynamics_joints_B2WeldJoint
#include <box2D/dynamics/joints/B2WeldJoint.h>
#endif
#ifndef INCLUDED_box2D_dynamics_joints_B2WeldJointDef
#include <box2D/dynamics/joints/B2WeldJointDef.h>
#endif
namespace box2D{
namespace dynamics{
namespace joints{

Void B2WeldJoint_obj::__construct(::box2D::dynamics::joints::B2WeldJointDef def)
{
{
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",74)
	super::__construct(def);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",76)
	this->m_localAnchorA = ::box2D::common::math::B2Vec2_obj::__new(null(),null());
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",77)
	this->m_localAnchorB = ::box2D::common::math::B2Vec2_obj::__new(null(),null());
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",78)
	this->m_impulse = ::box2D::common::math::B2Vec3_obj::__new(null(),null(),null());
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",79)
	this->m_mass = ::box2D::common::math::B2Mat33_obj::__new(null(),null(),null());
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",82)
	this->m_localAnchorA->setV(def->localAnchorA);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",83)
	this->m_localAnchorB->setV(def->localAnchorB);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",84)
	this->m_referenceAngle = def->referenceAngle;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",86)
	this->m_impulse->setZero();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",87)
	this->m_mass = ::box2D::common::math::B2Mat33_obj::__new(null(),null(),null());
}
;
	return null();
}

B2WeldJoint_obj::~B2WeldJoint_obj() { }

Dynamic B2WeldJoint_obj::__CreateEmpty() { return  new B2WeldJoint_obj; }
hx::ObjectPtr< B2WeldJoint_obj > B2WeldJoint_obj::__new(::box2D::dynamics::joints::B2WeldJointDef def)
{  hx::ObjectPtr< B2WeldJoint_obj > result = new B2WeldJoint_obj();
	result->__construct(def);
	return result;}

Dynamic B2WeldJoint_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2WeldJoint_obj > result = new B2WeldJoint_obj();
	result->__construct(inArgs[0]);
	return result;}

::box2D::common::math::B2Vec2 B2WeldJoint_obj::getAnchorA( ){
	HX_SOURCE_PUSH("B2WeldJoint_obj::getAnchorA")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",50)
	return this->m_bodyA->getWorldPoint(this->m_localAnchorA);
}


HX_DEFINE_DYNAMIC_FUNC0(B2WeldJoint_obj,getAnchorA,return )

::box2D::common::math::B2Vec2 B2WeldJoint_obj::getAnchorB( ){
	HX_SOURCE_PUSH("B2WeldJoint_obj::getAnchorB")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",54)
	return this->m_bodyB->getWorldPoint(this->m_localAnchorB);
}


HX_DEFINE_DYNAMIC_FUNC0(B2WeldJoint_obj,getAnchorB,return )

::box2D::common::math::B2Vec2 B2WeldJoint_obj::getReactionForce( double inv_dt){
	HX_SOURCE_PUSH("B2WeldJoint_obj::getReactionForce")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",60)
	return ::box2D::common::math::B2Vec2_obj::__new((inv_dt * this->m_impulse->x),(inv_dt * this->m_impulse->y));
}


HX_DEFINE_DYNAMIC_FUNC1(B2WeldJoint_obj,getReactionForce,return )

double B2WeldJoint_obj::getReactionTorque( double inv_dt){
	HX_SOURCE_PUSH("B2WeldJoint_obj::getReactionTorque")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",66)
	return (inv_dt * this->m_impulse->z);
}


HX_DEFINE_DYNAMIC_FUNC1(B2WeldJoint_obj,getReactionTorque,return )

Void B2WeldJoint_obj::initVelocityConstraints( ::box2D::dynamics::B2TimeStep step){
{
		HX_SOURCE_PUSH("B2WeldJoint_obj::initVelocityConstraints")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",91)
		::box2D::common::math::B2Mat22 tMat;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",92)
		double tX;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",94)
		::box2D::dynamics::B2Body bA = this->m_bodyA;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",95)
		::box2D::dynamics::B2Body bB = this->m_bodyB;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",99)
		tMat = bA->m_xf->R;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",100)
		double rAX = (this->m_localAnchorA->x - bA->m_sweep->localCenter->x);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",101)
		double rAY = (this->m_localAnchorA->y - bA->m_sweep->localCenter->y);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",102)
		tX = ((tMat->col1->x * rAX) + (tMat->col2->x * rAY));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",103)
		rAY = ((tMat->col1->y * rAX) + (tMat->col2->y * rAY));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",104)
		rAX = tX;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",106)
		tMat = bB->m_xf->R;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",107)
		double rBX = (this->m_localAnchorB->x - bB->m_sweep->localCenter->x);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",108)
		double rBY = (this->m_localAnchorB->y - bB->m_sweep->localCenter->y);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",109)
		tX = ((tMat->col1->x * rBX) + (tMat->col2->x * rBY));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",110)
		rBY = ((tMat->col1->y * rBX) + (tMat->col2->y * rBY));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",111)
		rBX = tX;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",122)
		double mA = bA->m_invMass;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",123)
		double mB = bB->m_invMass;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",124)
		double iA = bA->m_invI;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",125)
		double iB = bB->m_invI;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",127)
		this->m_mass->col1->x = (((mA + mB) + ((rAY * rAY) * iA)) + ((rBY * rBY) * iB));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",128)
		this->m_mass->col2->x = (((-(rAY) * rAX) * iA) - ((rBY * rBX) * iB));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",129)
		this->m_mass->col3->x = ((-(rAY) * iA) - (rBY * iB));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",130)
		this->m_mass->col1->y = this->m_mass->col2->x;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",131)
		this->m_mass->col2->y = (((mA + mB) + ((rAX * rAX) * iA)) + ((rBX * rBX) * iB));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",132)
		this->m_mass->col3->y = ((rAX * iA) + (rBX * iB));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",133)
		this->m_mass->col1->z = this->m_mass->col3->x;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",134)
		this->m_mass->col2->z = this->m_mass->col3->y;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",135)
		this->m_mass->col3->z = (iA + iB);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",137)
		if ((step->warmStarting)){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",140)
			hx::MultEq(this->m_impulse->x,step->dtRatio);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",141)
			hx::MultEq(this->m_impulse->y,step->dtRatio);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",142)
			hx::MultEq(this->m_impulse->z,step->dtRatio);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",144)
			hx::SubEq(bA->m_linearVelocity->x,(mA * this->m_impulse->x));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",145)
			hx::SubEq(bA->m_linearVelocity->y,(mA * this->m_impulse->y));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",146)
			hx::SubEq(bA->m_angularVelocity,(iA * ((((rAX * this->m_impulse->y) - (rAY * this->m_impulse->x)) + this->m_impulse->z))));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",148)
			hx::AddEq(bB->m_linearVelocity->x,(mB * this->m_impulse->x));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",149)
			hx::AddEq(bB->m_linearVelocity->y,(mB * this->m_impulse->y));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",150)
			hx::AddEq(bB->m_angularVelocity,(iB * ((((rBX * this->m_impulse->y) - (rBY * this->m_impulse->x)) + this->m_impulse->z))));
		}
		else{
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",153)
			this->m_impulse->setZero();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2WeldJoint_obj,initVelocityConstraints,(void))

Void B2WeldJoint_obj::solveVelocityConstraints( ::box2D::dynamics::B2TimeStep step){
{
		HX_SOURCE_PUSH("B2WeldJoint_obj::solveVelocityConstraints")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",163)
		::box2D::common::math::B2Mat22 tMat;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",164)
		double tX;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",166)
		::box2D::dynamics::B2Body bA = this->m_bodyA;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",167)
		::box2D::dynamics::B2Body bB = this->m_bodyB;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",169)
		::box2D::common::math::B2Vec2 vA = bA->m_linearVelocity;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",170)
		double wA = bA->m_angularVelocity;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",171)
		::box2D::common::math::B2Vec2 vB = bB->m_linearVelocity;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",172)
		double wB = bB->m_angularVelocity;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",174)
		double mA = bA->m_invMass;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",175)
		double mB = bB->m_invMass;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",176)
		double iA = bA->m_invI;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",177)
		double iB = bB->m_invI;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",180)
		tMat = bA->m_xf->R;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",181)
		double rAX = (this->m_localAnchorA->x - bA->m_sweep->localCenter->x);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",182)
		double rAY = (this->m_localAnchorA->y - bA->m_sweep->localCenter->y);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",183)
		tX = ((tMat->col1->x * rAX) + (tMat->col2->x * rAY));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",184)
		rAY = ((tMat->col1->y * rAX) + (tMat->col2->y * rAY));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",185)
		rAX = tX;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",187)
		tMat = bB->m_xf->R;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",188)
		double rBX = (this->m_localAnchorB->x - bB->m_sweep->localCenter->x);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",189)
		double rBY = (this->m_localAnchorB->y - bB->m_sweep->localCenter->y);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",190)
		tX = ((tMat->col1->x * rBX) + (tMat->col2->x * rBY));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",191)
		rBY = ((tMat->col1->y * rBX) + (tMat->col2->y * rBY));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",192)
		rBX = tX;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",196)
		double Cdot1X = (((vB->x - (wB * rBY)) - vA->x) + (wA * rAY));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",197)
		double Cdot1Y = (((vB->y + (wB * rBX)) - vA->y) - (wA * rAX));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",198)
		double Cdot2 = (wB - wA);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",199)
		::box2D::common::math::B2Vec3 impulse = ::box2D::common::math::B2Vec3_obj::__new(null(),null(),null());
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",200)
		this->m_mass->solve33(impulse,-(Cdot1X),-(Cdot1Y),-(Cdot2));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",202)
		this->m_impulse->add(impulse);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",204)
		hx::SubEq(vA->x,(mA * impulse->x));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",205)
		hx::SubEq(vA->y,(mA * impulse->y));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",206)
		hx::SubEq(wA,(iA * ((((rAX * impulse->y) - (rAY * impulse->x)) + impulse->z))));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",208)
		hx::AddEq(vB->x,(mB * impulse->x));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",209)
		hx::AddEq(vB->y,(mB * impulse->y));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",210)
		hx::AddEq(wB,(iB * ((((rBX * impulse->y) - (rBY * impulse->x)) + impulse->z))));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",214)
		bA->m_angularVelocity = wA;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",216)
		bB->m_angularVelocity = wB;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2WeldJoint_obj,solveVelocityConstraints,(void))

bool B2WeldJoint_obj::solvePositionConstraints( double baumgarte){
	HX_SOURCE_PUSH("B2WeldJoint_obj::solvePositionConstraints")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",223)
	::box2D::common::math::B2Mat22 tMat;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",224)
	double tX;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",226)
	::box2D::dynamics::B2Body bA = this->m_bodyA;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",227)
	::box2D::dynamics::B2Body bB = this->m_bodyB;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",231)
	tMat = bA->m_xf->R;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",232)
	double rAX = (this->m_localAnchorA->x - bA->m_sweep->localCenter->x);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",233)
	double rAY = (this->m_localAnchorA->y - bA->m_sweep->localCenter->y);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",234)
	tX = ((tMat->col1->x * rAX) + (tMat->col2->x * rAY));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",235)
	rAY = ((tMat->col1->y * rAX) + (tMat->col2->y * rAY));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",236)
	rAX = tX;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",238)
	tMat = bB->m_xf->R;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",239)
	double rBX = (this->m_localAnchorB->x - bB->m_sweep->localCenter->x);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",240)
	double rBY = (this->m_localAnchorB->y - bB->m_sweep->localCenter->y);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",241)
	tX = ((tMat->col1->x * rBX) + (tMat->col2->x * rBY));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",242)
	rBY = ((tMat->col1->y * rBX) + (tMat->col2->y * rBY));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",243)
	rBX = tX;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",254)
	double mA = bA->m_invMass;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",255)
	double mB = bB->m_invMass;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",256)
	double iA = bA->m_invI;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",257)
	double iB = bB->m_invI;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",260)
	double C1X = (((bB->m_sweep->c->x + rBX) - bA->m_sweep->c->x) - rAX);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",261)
	double C1Y = (((bB->m_sweep->c->y + rBY) - bA->m_sweep->c->y) - rAY);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",262)
	double C2 = ((bB->m_sweep->a - bA->m_sweep->a) - this->m_referenceAngle);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",265)
	double k_allowedStretch = (10.0 * ::box2D::common::B2Settings_obj::b2_linearSlop);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",266)
	double positionError = ::Math_obj::sqrt(((C1X * C1X) + (C1Y * C1Y)));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",267)
	double angularError = ::box2D::common::math::B2Math_obj::abs(C2);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",268)
	if (((positionError > k_allowedStretch))){
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",270)
		hx::MultEq(iA,1.0);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",271)
		hx::MultEq(iB,1.0);
	}
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",274)
	this->m_mass->col1->x = (((mA + mB) + ((rAY * rAY) * iA)) + ((rBY * rBY) * iB));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",275)
	this->m_mass->col2->x = (((-(rAY) * rAX) * iA) - ((rBY * rBX) * iB));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",276)
	this->m_mass->col3->x = ((-(rAY) * iA) - (rBY * iB));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",277)
	this->m_mass->col1->y = this->m_mass->col2->x;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",278)
	this->m_mass->col2->y = (((mA + mB) + ((rAX * rAX) * iA)) + ((rBX * rBX) * iB));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",279)
	this->m_mass->col3->y = ((rAX * iA) + (rBX * iB));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",280)
	this->m_mass->col1->z = this->m_mass->col3->x;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",281)
	this->m_mass->col2->z = this->m_mass->col3->y;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",282)
	this->m_mass->col3->z = (iA + iB);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",284)
	::box2D::common::math::B2Vec3 impulse = ::box2D::common::math::B2Vec3_obj::__new(null(),null(),null());
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",285)
	this->m_mass->solve33(impulse,-(C1X),-(C1Y),-(C2));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",288)
	hx::SubEq(bA->m_sweep->c->x,(mA * impulse->x));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",289)
	hx::SubEq(bA->m_sweep->c->y,(mA * impulse->y));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",290)
	hx::SubEq(bA->m_sweep->a,(iA * ((((rAX * impulse->y) - (rAY * impulse->x)) + impulse->z))));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",292)
	hx::AddEq(bB->m_sweep->c->x,(mB * impulse->x));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",293)
	hx::AddEq(bB->m_sweep->c->y,(mB * impulse->y));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",294)
	hx::AddEq(bB->m_sweep->a,(iB * ((((rBX * impulse->y) - (rBY * impulse->x)) + impulse->z))));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",296)
	bA->synchronizeTransform();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",297)
	bB->synchronizeTransform();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2WeldJoint.hx",299)
	return (bool((positionError <= ::box2D::common::B2Settings_obj::b2_linearSlop)) && bool((angularError <= ::box2D::common::B2Settings_obj::b2_angularSlop)));
}


HX_DEFINE_DYNAMIC_FUNC1(B2WeldJoint_obj,solvePositionConstraints,return )


B2WeldJoint_obj::B2WeldJoint_obj()
{
}

void B2WeldJoint_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(B2WeldJoint);
	HX_MARK_MEMBER_NAME(m_localAnchorA,"m_localAnchorA");
	HX_MARK_MEMBER_NAME(m_localAnchorB,"m_localAnchorB");
	HX_MARK_MEMBER_NAME(m_referenceAngle,"m_referenceAngle");
	HX_MARK_MEMBER_NAME(m_impulse,"m_impulse");
	HX_MARK_MEMBER_NAME(m_mass,"m_mass");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic B2WeldJoint_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"m_mass") ) { return m_mass; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"m_impulse") ) { return m_impulse; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"getAnchorA") ) { return getAnchorA_dyn(); }
		if (HX_FIELD_EQ(inName,"getAnchorB") ) { return getAnchorB_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"m_localAnchorA") ) { return m_localAnchorA; }
		if (HX_FIELD_EQ(inName,"m_localAnchorB") ) { return m_localAnchorB; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"getReactionForce") ) { return getReactionForce_dyn(); }
		if (HX_FIELD_EQ(inName,"m_referenceAngle") ) { return m_referenceAngle; }
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

Dynamic B2WeldJoint_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"m_mass") ) { m_mass=inValue.Cast< ::box2D::common::math::B2Mat33 >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"m_impulse") ) { m_impulse=inValue.Cast< ::box2D::common::math::B2Vec3 >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"m_localAnchorA") ) { m_localAnchorA=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_localAnchorB") ) { m_localAnchorB=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"m_referenceAngle") ) { m_referenceAngle=inValue.Cast< double >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void B2WeldJoint_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("m_localAnchorA"));
	outFields->push(HX_CSTRING("m_localAnchorB"));
	outFields->push(HX_CSTRING("m_referenceAngle"));
	outFields->push(HX_CSTRING("m_impulse"));
	outFields->push(HX_CSTRING("m_mass"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("getAnchorA"),
	HX_CSTRING("getAnchorB"),
	HX_CSTRING("getReactionForce"),
	HX_CSTRING("getReactionTorque"),
	HX_CSTRING("initVelocityConstraints"),
	HX_CSTRING("solveVelocityConstraints"),
	HX_CSTRING("solvePositionConstraints"),
	HX_CSTRING("m_localAnchorA"),
	HX_CSTRING("m_localAnchorB"),
	HX_CSTRING("m_referenceAngle"),
	HX_CSTRING("m_impulse"),
	HX_CSTRING("m_mass"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class B2WeldJoint_obj::__mClass;

void B2WeldJoint_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.dynamics.joints.B2WeldJoint"), hx::TCanCast< B2WeldJoint_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void B2WeldJoint_obj::__boot()
{
}

} // end namespace box2D
} // end namespace dynamics
} // end namespace joints
