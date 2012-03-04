#include <hxcpp.h>

#ifndef INCLUDED_box2D_common_B2Settings
#include <box2D/common/B2Settings.h>
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
#ifndef INCLUDED_box2D_dynamics_joints_B2GearJoint
#include <box2D/dynamics/joints/B2GearJoint.h>
#endif
#ifndef INCLUDED_box2D_dynamics_joints_B2GearJointDef
#include <box2D/dynamics/joints/B2GearJointDef.h>
#endif
#ifndef INCLUDED_box2D_dynamics_joints_B2Jacobian
#include <box2D/dynamics/joints/B2Jacobian.h>
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
#ifndef INCLUDED_box2D_dynamics_joints_B2RevoluteJoint
#include <box2D/dynamics/joints/B2RevoluteJoint.h>
#endif
namespace box2D{
namespace dynamics{
namespace joints{

Void B2GearJoint_obj::__construct(::box2D::dynamics::joints::B2GearJointDef def)
{
{
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",99)
	super::__construct(def);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",101)
	this->m_groundAnchor1 = ::box2D::common::math::B2Vec2_obj::__new(null(),null());
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",102)
	this->m_groundAnchor2 = ::box2D::common::math::B2Vec2_obj::__new(null(),null());
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",104)
	this->m_localAnchor1 = ::box2D::common::math::B2Vec2_obj::__new(null(),null());
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",105)
	this->m_localAnchor2 = ::box2D::common::math::B2Vec2_obj::__new(null(),null());
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",107)
	this->m_J = ::box2D::dynamics::joints::B2Jacobian_obj::__new();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",110)
	int type1 = def->joint1->m_type;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",111)
	int type2 = def->joint2->m_type;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",118)
	this->m_revolute1 = null();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",119)
	this->m_prismatic1 = null();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",120)
	this->m_revolute2 = null();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",121)
	this->m_prismatic2 = null();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",123)
	double coordinate1;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",124)
	double coordinate2;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",126)
	this->m_ground1 = def->joint1->getBodyA();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",127)
	this->m_bodyA = def->joint1->getBodyB();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",128)
	if (((type1 == ::box2D::dynamics::joints::B2Joint_obj::e_revoluteJoint))){
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",130)
		this->m_revolute1 = hx::TCast< box2D::dynamics::joints::B2RevoluteJoint >::cast(def->joint1);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",131)
		this->m_groundAnchor1->setV(this->m_revolute1->m_localAnchor1);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",132)
		this->m_localAnchor1->setV(this->m_revolute1->m_localAnchor2);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",133)
		coordinate1 = this->m_revolute1->getJointAngle();
	}
	else{
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",137)
		this->m_prismatic1 = hx::TCast< box2D::dynamics::joints::B2PrismaticJoint >::cast(def->joint1);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",138)
		this->m_groundAnchor1->setV(this->m_prismatic1->m_localAnchor1);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",139)
		this->m_localAnchor1->setV(this->m_prismatic1->m_localAnchor2);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",140)
		coordinate1 = this->m_prismatic1->getJointTranslation();
	}
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",143)
	this->m_ground2 = def->joint2->getBodyA();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",144)
	this->m_bodyB = def->joint2->getBodyB();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",145)
	if (((type2 == ::box2D::dynamics::joints::B2Joint_obj::e_revoluteJoint))){
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",147)
		this->m_revolute2 = hx::TCast< box2D::dynamics::joints::B2RevoluteJoint >::cast(def->joint2);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",148)
		this->m_groundAnchor2->setV(this->m_revolute2->m_localAnchor1);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",149)
		this->m_localAnchor2->setV(this->m_revolute2->m_localAnchor2);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",150)
		coordinate2 = this->m_revolute2->getJointAngle();
	}
	else{
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",154)
		this->m_prismatic2 = hx::TCast< box2D::dynamics::joints::B2PrismaticJoint >::cast(def->joint2);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",155)
		this->m_groundAnchor2->setV(this->m_prismatic2->m_localAnchor1);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",156)
		this->m_localAnchor2->setV(this->m_prismatic2->m_localAnchor2);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",157)
		coordinate2 = this->m_prismatic2->getJointTranslation();
	}
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",160)
	this->m_ratio = def->ratio;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",162)
	this->m_constant = (coordinate1 + (this->m_ratio * coordinate2));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",164)
	this->m_impulse = 0.0;
}
;
	return null();
}

B2GearJoint_obj::~B2GearJoint_obj() { }

Dynamic B2GearJoint_obj::__CreateEmpty() { return  new B2GearJoint_obj; }
hx::ObjectPtr< B2GearJoint_obj > B2GearJoint_obj::__new(::box2D::dynamics::joints::B2GearJointDef def)
{  hx::ObjectPtr< B2GearJoint_obj > result = new B2GearJoint_obj();
	result->__construct(def);
	return result;}

Dynamic B2GearJoint_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2GearJoint_obj > result = new B2GearJoint_obj();
	result->__construct(inArgs[0]);
	return result;}

::box2D::common::math::B2Vec2 B2GearJoint_obj::getAnchorA( ){
	HX_SOURCE_PUSH("B2GearJoint_obj::getAnchorA")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",45)
	return this->m_bodyA->getWorldPoint(this->m_localAnchor1);
}


HX_DEFINE_DYNAMIC_FUNC0(B2GearJoint_obj,getAnchorA,return )

::box2D::common::math::B2Vec2 B2GearJoint_obj::getAnchorB( ){
	HX_SOURCE_PUSH("B2GearJoint_obj::getAnchorB")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",50)
	return this->m_bodyB->getWorldPoint(this->m_localAnchor2);
}


HX_DEFINE_DYNAMIC_FUNC0(B2GearJoint_obj,getAnchorB,return )

::box2D::common::math::B2Vec2 B2GearJoint_obj::getReactionForce( double inv_dt){
	HX_SOURCE_PUSH("B2GearJoint_obj::getReactionForce")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",55)
	return ::box2D::common::math::B2Vec2_obj::__new(((inv_dt * this->m_impulse) * this->m_J->linearB->x),((inv_dt * this->m_impulse) * this->m_J->linearB->y));
}


HX_DEFINE_DYNAMIC_FUNC1(B2GearJoint_obj,getReactionForce,return )

double B2GearJoint_obj::getReactionTorque( double inv_dt){
	HX_SOURCE_PUSH("B2GearJoint_obj::getReactionTorque")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",65)
	::box2D::common::math::B2Mat22 tMat = this->m_bodyB->m_xf->R;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",66)
	double rX = (this->m_localAnchor1->x - this->m_bodyB->m_sweep->localCenter->x);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",67)
	double rY = (this->m_localAnchor1->y - this->m_bodyB->m_sweep->localCenter->y);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",68)
	double tX = ((tMat->col1->x * rX) + (tMat->col2->x * rY));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",69)
	rY = ((tMat->col1->y * rX) + (tMat->col2->y * rY));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",70)
	rX = tX;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",72)
	double PX = (this->m_impulse * this->m_J->linearB->x);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",73)
	double PY = (this->m_impulse * this->m_J->linearB->y);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",76)
	return (inv_dt * ((((this->m_impulse * this->m_J->angularB) - (rX * PY)) + (rY * PX))));
}


HX_DEFINE_DYNAMIC_FUNC1(B2GearJoint_obj,getReactionTorque,return )

double B2GearJoint_obj::getRatio( ){
	HX_SOURCE_PUSH("B2GearJoint_obj::getRatio")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",82)
	return this->m_ratio;
}


HX_DEFINE_DYNAMIC_FUNC0(B2GearJoint_obj,getRatio,return )

Void B2GearJoint_obj::setRatio( double ratio){
{
		HX_SOURCE_PUSH("B2GearJoint_obj::setRatio")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",89)
		this->m_ratio = ratio;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2GearJoint_obj,setRatio,(void))

Void B2GearJoint_obj::initVelocityConstraints( ::box2D::dynamics::B2TimeStep step){
{
		HX_SOURCE_PUSH("B2GearJoint_obj::initVelocityConstraints")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",169)
		::box2D::dynamics::B2Body g1 = this->m_ground1;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",170)
		::box2D::dynamics::B2Body g2 = this->m_ground2;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",171)
		::box2D::dynamics::B2Body bA = this->m_bodyA;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",172)
		::box2D::dynamics::B2Body bB = this->m_bodyB;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",175)
		double ugX;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",176)
		double ugY;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",177)
		double rX;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",178)
		double rY;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",179)
		::box2D::common::math::B2Mat22 tMat;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",180)
		::box2D::common::math::B2Vec2 tVec;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",181)
		double crug;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",182)
		double tX;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",184)
		double K = 0.0;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",185)
		this->m_J->setZero();
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",187)
		if (((this->m_revolute1 != null()))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",189)
			this->m_J->angularA = -1.0;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",190)
			hx::AddEq(K,bA->m_invI);
		}
		else{
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",195)
			tMat = g1->m_xf->R;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",196)
			tVec = this->m_prismatic1->m_localXAxis1;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",197)
			ugX = ((tMat->col1->x * tVec->x) + (tMat->col2->x * tVec->y));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",198)
			ugY = ((tMat->col1->y * tVec->x) + (tMat->col2->y * tVec->y));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",200)
			tMat = bA->m_xf->R;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",201)
			rX = (this->m_localAnchor1->x - bA->m_sweep->localCenter->x);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",202)
			rY = (this->m_localAnchor1->y - bA->m_sweep->localCenter->y);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",203)
			tX = ((tMat->col1->x * rX) + (tMat->col2->x * rY));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",204)
			rY = ((tMat->col1->y * rX) + (tMat->col2->y * rY));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",205)
			rX = tX;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",208)
			crug = ((rX * ugY) - (rY * ugX));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",210)
			this->m_J->linearA->set(-(ugX),-(ugY));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",211)
			this->m_J->angularA = -(crug);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",212)
			hx::AddEq(K,(bA->m_invMass + ((bA->m_invI * crug) * crug)));
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",215)
		if (((this->m_revolute2 != null()))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",217)
			this->m_J->angularB = -(this->m_ratio);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",218)
			hx::AddEq(K,((this->m_ratio * this->m_ratio) * bB->m_invI));
		}
		else{
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",223)
			tMat = g2->m_xf->R;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",224)
			tVec = this->m_prismatic2->m_localXAxis1;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",225)
			ugX = ((tMat->col1->x * tVec->x) + (tMat->col2->x * tVec->y));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",226)
			ugY = ((tMat->col1->y * tVec->x) + (tMat->col2->y * tVec->y));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",228)
			tMat = bB->m_xf->R;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",229)
			rX = (this->m_localAnchor2->x - bB->m_sweep->localCenter->x);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",230)
			rY = (this->m_localAnchor2->y - bB->m_sweep->localCenter->y);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",231)
			tX = ((tMat->col1->x * rX) + (tMat->col2->x * rY));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",232)
			rY = ((tMat->col1->y * rX) + (tMat->col2->y * rY));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",233)
			rX = tX;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",236)
			crug = ((rX * ugY) - (rY * ugX));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",238)
			this->m_J->linearB->set((-(this->m_ratio) * ugX),(-(this->m_ratio) * ugY));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",239)
			this->m_J->angularB = (-(this->m_ratio) * crug);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",240)
			hx::AddEq(K,((this->m_ratio * this->m_ratio) * ((bB->m_invMass + ((bB->m_invI * crug) * crug)))));
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",244)
		this->m_mass = (  (((K > 0.0))) ? double((double(1.0) / double(K))) : double(0.0) );
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",246)
		if ((step->warmStarting)){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",250)
			hx::AddEq(bA->m_linearVelocity->x,((bA->m_invMass * this->m_impulse) * this->m_J->linearA->x));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",251)
			hx::AddEq(bA->m_linearVelocity->y,((bA->m_invMass * this->m_impulse) * this->m_J->linearA->y));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",252)
			hx::AddEq(bA->m_angularVelocity,((bA->m_invI * this->m_impulse) * this->m_J->angularA));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",254)
			hx::AddEq(bB->m_linearVelocity->x,((bB->m_invMass * this->m_impulse) * this->m_J->linearB->x));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",255)
			hx::AddEq(bB->m_linearVelocity->y,((bB->m_invMass * this->m_impulse) * this->m_J->linearB->y));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",256)
			hx::AddEq(bB->m_angularVelocity,((bB->m_invI * this->m_impulse) * this->m_J->angularB));
		}
		else{
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",259)
			this->m_impulse = 0.0;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2GearJoint_obj,initVelocityConstraints,(void))

Void B2GearJoint_obj::solveVelocityConstraints( ::box2D::dynamics::B2TimeStep step){
{
		HX_SOURCE_PUSH("B2GearJoint_obj::solveVelocityConstraints")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",268)
		::box2D::dynamics::B2Body bA = this->m_bodyA;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",269)
		::box2D::dynamics::B2Body bB = this->m_bodyB;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",271)
		double Cdot = this->m_J->compute(bA->m_linearVelocity,bA->m_angularVelocity,bB->m_linearVelocity,bB->m_angularVelocity);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",274)
		double impulse = (-(this->m_mass) * Cdot);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",275)
		hx::AddEq(this->m_impulse,impulse);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",277)
		hx::AddEq(bA->m_linearVelocity->x,((bA->m_invMass * impulse) * this->m_J->linearA->x));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",278)
		hx::AddEq(bA->m_linearVelocity->y,((bA->m_invMass * impulse) * this->m_J->linearA->y));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",279)
		hx::AddEq(bA->m_angularVelocity,((bA->m_invI * impulse) * this->m_J->angularA));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",280)
		hx::AddEq(bB->m_linearVelocity->x,((bB->m_invMass * impulse) * this->m_J->linearB->x));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",281)
		hx::AddEq(bB->m_linearVelocity->y,((bB->m_invMass * impulse) * this->m_J->linearB->y));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",282)
		hx::AddEq(bB->m_angularVelocity,((bB->m_invI * impulse) * this->m_J->angularB));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2GearJoint_obj,solveVelocityConstraints,(void))

bool B2GearJoint_obj::solvePositionConstraints( double baumgarte){
	HX_SOURCE_PUSH("B2GearJoint_obj::solvePositionConstraints")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",289)
	double linearError = 0.0;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",291)
	::box2D::dynamics::B2Body bA = this->m_bodyA;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",292)
	::box2D::dynamics::B2Body bB = this->m_bodyB;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",294)
	double coordinate1;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",295)
	double coordinate2;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",296)
	if (((this->m_revolute1 != null()))){
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",297)
		coordinate1 = this->m_revolute1->getJointAngle();
	}
	else{
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",301)
		coordinate1 = this->m_prismatic1->getJointTranslation();
	}
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",305)
	if (((this->m_revolute2 != null()))){
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",306)
		coordinate2 = this->m_revolute2->getJointAngle();
	}
	else{
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",310)
		coordinate2 = this->m_prismatic2->getJointTranslation();
	}
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",314)
	double C = (this->m_constant - ((coordinate1 + (this->m_ratio * coordinate2))));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",316)
	double impulse = (-(this->m_mass) * C);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",318)
	hx::AddEq(bA->m_sweep->c->x,((bA->m_invMass * impulse) * this->m_J->linearA->x));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",319)
	hx::AddEq(bA->m_sweep->c->y,((bA->m_invMass * impulse) * this->m_J->linearA->y));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",320)
	hx::AddEq(bA->m_sweep->a,((bA->m_invI * impulse) * this->m_J->angularA));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",321)
	hx::AddEq(bB->m_sweep->c->x,((bB->m_invMass * impulse) * this->m_J->linearB->x));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",322)
	hx::AddEq(bB->m_sweep->c->y,((bB->m_invMass * impulse) * this->m_J->linearB->y));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",323)
	hx::AddEq(bB->m_sweep->a,((bB->m_invI * impulse) * this->m_J->angularB));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",325)
	bA->synchronizeTransform();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",326)
	bB->synchronizeTransform();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2GearJoint.hx",329)
	return (linearError < ::box2D::common::B2Settings_obj::b2_linearSlop);
}


HX_DEFINE_DYNAMIC_FUNC1(B2GearJoint_obj,solvePositionConstraints,return )


B2GearJoint_obj::B2GearJoint_obj()
{
}

void B2GearJoint_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(B2GearJoint);
	HX_MARK_MEMBER_NAME(m_ground1,"m_ground1");
	HX_MARK_MEMBER_NAME(m_ground2,"m_ground2");
	HX_MARK_MEMBER_NAME(m_revolute1,"m_revolute1");
	HX_MARK_MEMBER_NAME(m_prismatic1,"m_prismatic1");
	HX_MARK_MEMBER_NAME(m_revolute2,"m_revolute2");
	HX_MARK_MEMBER_NAME(m_prismatic2,"m_prismatic2");
	HX_MARK_MEMBER_NAME(m_groundAnchor1,"m_groundAnchor1");
	HX_MARK_MEMBER_NAME(m_groundAnchor2,"m_groundAnchor2");
	HX_MARK_MEMBER_NAME(m_localAnchor1,"m_localAnchor1");
	HX_MARK_MEMBER_NAME(m_localAnchor2,"m_localAnchor2");
	HX_MARK_MEMBER_NAME(m_J,"m_J");
	HX_MARK_MEMBER_NAME(m_constant,"m_constant");
	HX_MARK_MEMBER_NAME(m_ratio,"m_ratio");
	HX_MARK_MEMBER_NAME(m_mass,"m_mass");
	HX_MARK_MEMBER_NAME(m_impulse,"m_impulse");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic B2GearJoint_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"m_J") ) { return m_J; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"m_mass") ) { return m_mass; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"m_ratio") ) { return m_ratio; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"getRatio") ) { return getRatio_dyn(); }
		if (HX_FIELD_EQ(inName,"setRatio") ) { return setRatio_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"m_ground1") ) { return m_ground1; }
		if (HX_FIELD_EQ(inName,"m_ground2") ) { return m_ground2; }
		if (HX_FIELD_EQ(inName,"m_impulse") ) { return m_impulse; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"getAnchorA") ) { return getAnchorA_dyn(); }
		if (HX_FIELD_EQ(inName,"getAnchorB") ) { return getAnchorB_dyn(); }
		if (HX_FIELD_EQ(inName,"m_constant") ) { return m_constant; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"m_revolute1") ) { return m_revolute1; }
		if (HX_FIELD_EQ(inName,"m_revolute2") ) { return m_revolute2; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"m_prismatic1") ) { return m_prismatic1; }
		if (HX_FIELD_EQ(inName,"m_prismatic2") ) { return m_prismatic2; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"m_localAnchor1") ) { return m_localAnchor1; }
		if (HX_FIELD_EQ(inName,"m_localAnchor2") ) { return m_localAnchor2; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"m_groundAnchor1") ) { return m_groundAnchor1; }
		if (HX_FIELD_EQ(inName,"m_groundAnchor2") ) { return m_groundAnchor2; }
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

Dynamic B2GearJoint_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"m_J") ) { m_J=inValue.Cast< ::box2D::dynamics::joints::B2Jacobian >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"m_mass") ) { m_mass=inValue.Cast< double >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"m_ratio") ) { m_ratio=inValue.Cast< double >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"m_ground1") ) { m_ground1=inValue.Cast< ::box2D::dynamics::B2Body >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_ground2") ) { m_ground2=inValue.Cast< ::box2D::dynamics::B2Body >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_impulse") ) { m_impulse=inValue.Cast< double >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"m_constant") ) { m_constant=inValue.Cast< double >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"m_revolute1") ) { m_revolute1=inValue.Cast< ::box2D::dynamics::joints::B2RevoluteJoint >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_revolute2") ) { m_revolute2=inValue.Cast< ::box2D::dynamics::joints::B2RevoluteJoint >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"m_prismatic1") ) { m_prismatic1=inValue.Cast< ::box2D::dynamics::joints::B2PrismaticJoint >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_prismatic2") ) { m_prismatic2=inValue.Cast< ::box2D::dynamics::joints::B2PrismaticJoint >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"m_localAnchor1") ) { m_localAnchor1=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_localAnchor2") ) { m_localAnchor2=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"m_groundAnchor1") ) { m_groundAnchor1=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_groundAnchor2") ) { m_groundAnchor2=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void B2GearJoint_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("m_ground1"));
	outFields->push(HX_CSTRING("m_ground2"));
	outFields->push(HX_CSTRING("m_revolute1"));
	outFields->push(HX_CSTRING("m_prismatic1"));
	outFields->push(HX_CSTRING("m_revolute2"));
	outFields->push(HX_CSTRING("m_prismatic2"));
	outFields->push(HX_CSTRING("m_groundAnchor1"));
	outFields->push(HX_CSTRING("m_groundAnchor2"));
	outFields->push(HX_CSTRING("m_localAnchor1"));
	outFields->push(HX_CSTRING("m_localAnchor2"));
	outFields->push(HX_CSTRING("m_J"));
	outFields->push(HX_CSTRING("m_constant"));
	outFields->push(HX_CSTRING("m_ratio"));
	outFields->push(HX_CSTRING("m_mass"));
	outFields->push(HX_CSTRING("m_impulse"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("getAnchorA"),
	HX_CSTRING("getAnchorB"),
	HX_CSTRING("getReactionForce"),
	HX_CSTRING("getReactionTorque"),
	HX_CSTRING("getRatio"),
	HX_CSTRING("setRatio"),
	HX_CSTRING("initVelocityConstraints"),
	HX_CSTRING("solveVelocityConstraints"),
	HX_CSTRING("solvePositionConstraints"),
	HX_CSTRING("m_ground1"),
	HX_CSTRING("m_ground2"),
	HX_CSTRING("m_revolute1"),
	HX_CSTRING("m_prismatic1"),
	HX_CSTRING("m_revolute2"),
	HX_CSTRING("m_prismatic2"),
	HX_CSTRING("m_groundAnchor1"),
	HX_CSTRING("m_groundAnchor2"),
	HX_CSTRING("m_localAnchor1"),
	HX_CSTRING("m_localAnchor2"),
	HX_CSTRING("m_J"),
	HX_CSTRING("m_constant"),
	HX_CSTRING("m_ratio"),
	HX_CSTRING("m_mass"),
	HX_CSTRING("m_impulse"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class B2GearJoint_obj::__mClass;

void B2GearJoint_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.dynamics.joints.B2GearJoint"), hx::TCanCast< B2GearJoint_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void B2GearJoint_obj::__boot()
{
}

} // end namespace box2D
} // end namespace dynamics
} // end namespace joints
