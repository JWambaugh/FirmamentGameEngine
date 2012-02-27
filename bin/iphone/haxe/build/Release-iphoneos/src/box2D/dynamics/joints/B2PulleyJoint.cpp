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
#ifndef INCLUDED_box2D_dynamics_B2World
#include <box2D/dynamics/B2World.h>
#endif
#ifndef INCLUDED_box2D_dynamics_joints_B2Joint
#include <box2D/dynamics/joints/B2Joint.h>
#endif
#ifndef INCLUDED_box2D_dynamics_joints_B2JointDef
#include <box2D/dynamics/joints/B2JointDef.h>
#endif
#ifndef INCLUDED_box2D_dynamics_joints_B2PulleyJoint
#include <box2D/dynamics/joints/B2PulleyJoint.h>
#endif
#ifndef INCLUDED_box2D_dynamics_joints_B2PulleyJointDef
#include <box2D/dynamics/joints/B2PulleyJointDef.h>
#endif
namespace box2D{
namespace dynamics{
namespace joints{

Void B2PulleyJoint_obj::__construct(::box2D::dynamics::joints::B2PulleyJointDef def)
{
{
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",132)
	super::__construct(def);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",135)
	this->m_groundAnchor1 = ::box2D::common::math::B2Vec2_obj::__new(null(),null());
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",136)
	this->m_groundAnchor2 = ::box2D::common::math::B2Vec2_obj::__new(null(),null());
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",137)
	this->m_localAnchor1 = ::box2D::common::math::B2Vec2_obj::__new(null(),null());
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",138)
	this->m_localAnchor2 = ::box2D::common::math::B2Vec2_obj::__new(null(),null());
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",140)
	this->m_u1 = ::box2D::common::math::B2Vec2_obj::__new(null(),null());
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",141)
	this->m_u2 = ::box2D::common::math::B2Vec2_obj::__new(null(),null());
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",144)
	::box2D::common::math::B2Mat22 tMat;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",145)
	double tX;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",146)
	double tY;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",148)
	this->m_ground = this->m_bodyA->m_world->m_groundBody;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",150)
	this->m_groundAnchor1->x = (def->groundAnchorA->x - this->m_ground->m_xf->position->x);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",151)
	this->m_groundAnchor1->y = (def->groundAnchorA->y - this->m_ground->m_xf->position->y);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",153)
	this->m_groundAnchor2->x = (def->groundAnchorB->x - this->m_ground->m_xf->position->x);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",154)
	this->m_groundAnchor2->y = (def->groundAnchorB->y - this->m_ground->m_xf->position->y);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",156)
	this->m_localAnchor1->setV(def->localAnchorA);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",158)
	this->m_localAnchor2->setV(def->localAnchorB);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",161)
	this->m_ratio = def->ratio;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",163)
	this->m_constant = (def->lengthA + (this->m_ratio * def->lengthB));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",165)
	this->m_maxLength1 = ::box2D::common::math::B2Math_obj::min(def->maxLengthA,(this->m_constant - (this->m_ratio * ::box2D::dynamics::joints::B2PulleyJoint_obj::b2_minPulleyLength)));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",166)
	this->m_maxLength2 = ::box2D::common::math::B2Math_obj::min(def->maxLengthB,(double(((this->m_constant - ::box2D::dynamics::joints::B2PulleyJoint_obj::b2_minPulleyLength))) / double(this->m_ratio)));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",168)
	this->m_impulse = 0.0;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",169)
	this->m_limitImpulse1 = 0.0;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",170)
	this->m_limitImpulse2 = 0.0;
}
;
	return null();
}

B2PulleyJoint_obj::~B2PulleyJoint_obj() { }

Dynamic B2PulleyJoint_obj::__CreateEmpty() { return  new B2PulleyJoint_obj; }
hx::ObjectPtr< B2PulleyJoint_obj > B2PulleyJoint_obj::__new(::box2D::dynamics::joints::B2PulleyJointDef def)
{  hx::ObjectPtr< B2PulleyJoint_obj > result = new B2PulleyJoint_obj();
	result->__construct(def);
	return result;}

Dynamic B2PulleyJoint_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2PulleyJoint_obj > result = new B2PulleyJoint_obj();
	result->__construct(inArgs[0]);
	return result;}

::box2D::common::math::B2Vec2 B2PulleyJoint_obj::getAnchorA( ){
	HX_SOURCE_PUSH("B2PulleyJoint_obj::getAnchorA")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",42)
	return this->m_bodyA->getWorldPoint(this->m_localAnchor1);
}


HX_DEFINE_DYNAMIC_FUNC0(B2PulleyJoint_obj,getAnchorA,return )

::box2D::common::math::B2Vec2 B2PulleyJoint_obj::getAnchorB( ){
	HX_SOURCE_PUSH("B2PulleyJoint_obj::getAnchorB")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",46)
	return this->m_bodyB->getWorldPoint(this->m_localAnchor2);
}


HX_DEFINE_DYNAMIC_FUNC0(B2PulleyJoint_obj,getAnchorB,return )

::box2D::common::math::B2Vec2 B2PulleyJoint_obj::getReactionForce( double inv_dt){
	HX_SOURCE_PUSH("B2PulleyJoint_obj::getReactionForce")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",52)
	return ::box2D::common::math::B2Vec2_obj::__new(((inv_dt * this->m_impulse) * this->m_u2->x),((inv_dt * this->m_impulse) * this->m_u2->y));
}


HX_DEFINE_DYNAMIC_FUNC1(B2PulleyJoint_obj,getReactionForce,return )

double B2PulleyJoint_obj::getReactionTorque( double inv_dt){
	HX_SOURCE_PUSH("B2PulleyJoint_obj::getReactionTorque")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",60)
	return 0.0;
}


HX_DEFINE_DYNAMIC_FUNC1(B2PulleyJoint_obj,getReactionTorque,return )

::box2D::common::math::B2Vec2 B2PulleyJoint_obj::getGroundAnchorA( ){
	HX_SOURCE_PUSH("B2PulleyJoint_obj::getGroundAnchorA")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",71)
	::box2D::common::math::B2Vec2 a = this->m_ground->m_xf->position->copy();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",72)
	a->add(this->m_groundAnchor1);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",73)
	return a;
}


HX_DEFINE_DYNAMIC_FUNC0(B2PulleyJoint_obj,getGroundAnchorA,return )

::box2D::common::math::B2Vec2 B2PulleyJoint_obj::getGroundAnchorB( ){
	HX_SOURCE_PUSH("B2PulleyJoint_obj::getGroundAnchorB")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",82)
	::box2D::common::math::B2Vec2 a = this->m_ground->m_xf->position->copy();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",83)
	a->add(this->m_groundAnchor2);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",84)
	return a;
}


HX_DEFINE_DYNAMIC_FUNC0(B2PulleyJoint_obj,getGroundAnchorB,return )

double B2PulleyJoint_obj::getLength1( ){
	HX_SOURCE_PUSH("B2PulleyJoint_obj::getLength1")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",92)
	::box2D::common::math::B2Vec2 p = this->m_bodyA->getWorldPoint(this->m_localAnchor1);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",94)
	double sX = (this->m_ground->m_xf->position->x + this->m_groundAnchor1->x);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",95)
	double sY = (this->m_ground->m_xf->position->y + this->m_groundAnchor1->y);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",97)
	double dX = (p->x - sX);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",98)
	double dY = (p->y - sY);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",100)
	return ::Math_obj::sqrt(((dX * dX) + (dY * dY)));
}


HX_DEFINE_DYNAMIC_FUNC0(B2PulleyJoint_obj,getLength1,return )

double B2PulleyJoint_obj::getLength2( ){
	HX_SOURCE_PUSH("B2PulleyJoint_obj::getLength2")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",108)
	::box2D::common::math::B2Vec2 p = this->m_bodyB->getWorldPoint(this->m_localAnchor2);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",110)
	double sX = (this->m_ground->m_xf->position->x + this->m_groundAnchor2->x);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",111)
	double sY = (this->m_ground->m_xf->position->y + this->m_groundAnchor2->y);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",113)
	double dX = (p->x - sX);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",114)
	double dY = (p->y - sY);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",116)
	return ::Math_obj::sqrt(((dX * dX) + (dY * dY)));
}


HX_DEFINE_DYNAMIC_FUNC0(B2PulleyJoint_obj,getLength2,return )

double B2PulleyJoint_obj::getRatio( ){
	HX_SOURCE_PUSH("B2PulleyJoint_obj::getRatio")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",122)
	return this->m_ratio;
}


HX_DEFINE_DYNAMIC_FUNC0(B2PulleyJoint_obj,getRatio,return )

Void B2PulleyJoint_obj::initVelocityConstraints( ::box2D::dynamics::B2TimeStep step){
{
		HX_SOURCE_PUSH("B2PulleyJoint_obj::initVelocityConstraints")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",175)
		::box2D::dynamics::B2Body bA = this->m_bodyA;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",176)
		::box2D::dynamics::B2Body bB = this->m_bodyB;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",178)
		::box2D::common::math::B2Mat22 tMat;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",181)
		tMat = bA->m_xf->R;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",182)
		double r1X = (this->m_localAnchor1->x - bA->m_sweep->localCenter->x);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",183)
		double r1Y = (this->m_localAnchor1->y - bA->m_sweep->localCenter->y);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",184)
		double tX = ((tMat->col1->x * r1X) + (tMat->col2->x * r1Y));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",185)
		r1Y = ((tMat->col1->y * r1X) + (tMat->col2->y * r1Y));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",186)
		r1X = tX;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",188)
		tMat = bB->m_xf->R;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",189)
		double r2X = (this->m_localAnchor2->x - bB->m_sweep->localCenter->x);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",190)
		double r2Y = (this->m_localAnchor2->y - bB->m_sweep->localCenter->y);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",191)
		tX = ((tMat->col1->x * r2X) + (tMat->col2->x * r2Y));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",192)
		r2Y = ((tMat->col1->y * r2X) + (tMat->col2->y * r2Y));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",193)
		r2X = tX;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",196)
		double p1X = (bA->m_sweep->c->x + r1X);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",197)
		double p1Y = (bA->m_sweep->c->y + r1Y);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",199)
		double p2X = (bB->m_sweep->c->x + r2X);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",200)
		double p2Y = (bB->m_sweep->c->y + r2Y);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",203)
		double s1X = (this->m_ground->m_xf->position->x + this->m_groundAnchor1->x);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",204)
		double s1Y = (this->m_ground->m_xf->position->y + this->m_groundAnchor1->y);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",206)
		double s2X = (this->m_ground->m_xf->position->x + this->m_groundAnchor2->x);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",207)
		double s2Y = (this->m_ground->m_xf->position->y + this->m_groundAnchor2->y);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",211)
		this->m_u1->set((p1X - s1X),(p1Y - s1Y));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",213)
		this->m_u2->set((p2X - s2X),(p2Y - s2Y));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",215)
		double length1 = this->m_u1->length();
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",216)
		double length2 = this->m_u2->length();
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",218)
		if (((length1 > ::box2D::common::B2Settings_obj::b2_linearSlop))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",219)
			this->m_u1->multiply((double(1.0) / double(length1)));
		}
		else{
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",224)
			this->m_u1->setZero();
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",228)
		if (((length2 > ::box2D::common::B2Settings_obj::b2_linearSlop))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",229)
			this->m_u2->multiply((double(1.0) / double(length2)));
		}
		else{
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",234)
			this->m_u2->setZero();
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",238)
		double C = ((this->m_constant - length1) - (this->m_ratio * length2));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",239)
		if (((C > 0.0))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",241)
			this->m_state = ::box2D::dynamics::joints::B2Joint_obj::e_inactiveLimit;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",242)
			this->m_impulse = 0.0;
		}
		else{
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",245)
			this->m_state = ::box2D::dynamics::joints::B2Joint_obj::e_atUpperLimit;
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",249)
		if (((length1 < this->m_maxLength1))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",251)
			this->m_limitState1 = ::box2D::dynamics::joints::B2Joint_obj::e_inactiveLimit;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",252)
			this->m_limitImpulse1 = 0.0;
		}
		else{
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",255)
			this->m_limitState1 = ::box2D::dynamics::joints::B2Joint_obj::e_atUpperLimit;
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",259)
		if (((length2 < this->m_maxLength2))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",261)
			this->m_limitState2 = ::box2D::dynamics::joints::B2Joint_obj::e_inactiveLimit;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",262)
			this->m_limitImpulse2 = 0.0;
		}
		else{
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",265)
			this->m_limitState2 = ::box2D::dynamics::joints::B2Joint_obj::e_atUpperLimit;
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",271)
		double cr1u1 = ((r1X * this->m_u1->y) - (r1Y * this->m_u1->x));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",273)
		double cr2u2 = ((r2X * this->m_u2->y) - (r2Y * this->m_u2->x));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",275)
		this->m_limitMass1 = (bA->m_invMass + ((bA->m_invI * cr1u1) * cr1u1));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",276)
		this->m_limitMass2 = (bB->m_invMass + ((bB->m_invI * cr2u2) * cr2u2));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",277)
		this->m_pulleyMass = (this->m_limitMass1 + ((this->m_ratio * this->m_ratio) * this->m_limitMass2));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",281)
		this->m_limitMass1 = (double(1.0) / double(this->m_limitMass1));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",282)
		this->m_limitMass2 = (double(1.0) / double(this->m_limitMass2));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",283)
		this->m_pulleyMass = (double(1.0) / double(this->m_pulleyMass));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",285)
		if ((step->warmStarting)){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",288)
			hx::MultEq(this->m_impulse,step->dtRatio);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",289)
			hx::MultEq(this->m_limitImpulse1,step->dtRatio);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",290)
			hx::MultEq(this->m_limitImpulse2,step->dtRatio);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",294)
			double P1X = (((-(this->m_impulse) - this->m_limitImpulse1)) * this->m_u1->x);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",295)
			double P1Y = (((-(this->m_impulse) - this->m_limitImpulse1)) * this->m_u1->y);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",297)
			double P2X = ((((-(this->m_ratio) * this->m_impulse) - this->m_limitImpulse2)) * this->m_u2->x);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",298)
			double P2Y = ((((-(this->m_ratio) * this->m_impulse) - this->m_limitImpulse2)) * this->m_u2->y);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",300)
			hx::AddEq(bA->m_linearVelocity->x,(bA->m_invMass * P1X));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",301)
			hx::AddEq(bA->m_linearVelocity->y,(bA->m_invMass * P1Y));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",303)
			hx::AddEq(bA->m_angularVelocity,(bA->m_invI * (((r1X * P1Y) - (r1Y * P1X)))));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",305)
			hx::AddEq(bB->m_linearVelocity->x,(bB->m_invMass * P2X));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",306)
			hx::AddEq(bB->m_linearVelocity->y,(bB->m_invMass * P2Y));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",308)
			hx::AddEq(bB->m_angularVelocity,(bB->m_invI * (((r2X * P2Y) - (r2Y * P2X)))));
		}
		else{
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",312)
			this->m_impulse = 0.0;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",313)
			this->m_limitImpulse1 = 0.0;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",314)
			this->m_limitImpulse2 = 0.0;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2PulleyJoint_obj,initVelocityConstraints,(void))

Void B2PulleyJoint_obj::solveVelocityConstraints( ::box2D::dynamics::B2TimeStep step){
{
		HX_SOURCE_PUSH("B2PulleyJoint_obj::solveVelocityConstraints")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",322)
		::box2D::dynamics::B2Body bA = this->m_bodyA;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",323)
		::box2D::dynamics::B2Body bB = this->m_bodyB;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",325)
		::box2D::common::math::B2Mat22 tMat;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",328)
		tMat = bA->m_xf->R;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",329)
		double r1X = (this->m_localAnchor1->x - bA->m_sweep->localCenter->x);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",330)
		double r1Y = (this->m_localAnchor1->y - bA->m_sweep->localCenter->y);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",331)
		double tX = ((tMat->col1->x * r1X) + (tMat->col2->x * r1Y));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",332)
		r1Y = ((tMat->col1->y * r1X) + (tMat->col2->y * r1Y));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",333)
		r1X = tX;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",335)
		tMat = bB->m_xf->R;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",336)
		double r2X = (this->m_localAnchor2->x - bB->m_sweep->localCenter->x);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",337)
		double r2Y = (this->m_localAnchor2->y - bB->m_sweep->localCenter->y);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",338)
		tX = ((tMat->col1->x * r2X) + (tMat->col2->x * r2Y));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",339)
		r2Y = ((tMat->col1->y * r2X) + (tMat->col2->y * r2Y));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",340)
		r2X = tX;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",343)
		double v1X;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",344)
		double v1Y;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",345)
		double v2X;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",346)
		double v2Y;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",347)
		double P1X;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",348)
		double P1Y;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",349)
		double P2X;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",350)
		double P2Y;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",351)
		double Cdot;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",352)
		double impulse;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",353)
		double oldImpulse;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",355)
		if (((this->m_state == ::box2D::dynamics::joints::B2Joint_obj::e_atUpperLimit))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",358)
			v1X = (bA->m_linearVelocity->x + (-(bA->m_angularVelocity) * r1Y));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",359)
			v1Y = (bA->m_linearVelocity->y + (bA->m_angularVelocity * r1X));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",361)
			v2X = (bB->m_linearVelocity->x + (-(bB->m_angularVelocity) * r2Y));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",362)
			v2Y = (bB->m_linearVelocity->y + (bB->m_angularVelocity * r2X));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",365)
			Cdot = (-((((this->m_u1->x * v1X) + (this->m_u1->y * v1Y)))) - (this->m_ratio * (((this->m_u2->x * v2X) + (this->m_u2->y * v2Y)))));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",366)
			impulse = (this->m_pulleyMass * -(Cdot));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",367)
			oldImpulse = this->m_impulse;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",368)
			this->m_impulse = ::box2D::common::math::B2Math_obj::max(0.0,(this->m_impulse + impulse));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",369)
			impulse = (this->m_impulse - oldImpulse);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",372)
			P1X = (-(impulse) * this->m_u1->x);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",373)
			P1Y = (-(impulse) * this->m_u1->y);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",375)
			P2X = ((-(this->m_ratio) * impulse) * this->m_u2->x);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",376)
			P2Y = ((-(this->m_ratio) * impulse) * this->m_u2->y);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",378)
			hx::AddEq(bA->m_linearVelocity->x,(bA->m_invMass * P1X));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",379)
			hx::AddEq(bA->m_linearVelocity->y,(bA->m_invMass * P1Y));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",381)
			hx::AddEq(bA->m_angularVelocity,(bA->m_invI * (((r1X * P1Y) - (r1Y * P1X)))));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",383)
			hx::AddEq(bB->m_linearVelocity->x,(bB->m_invMass * P2X));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",384)
			hx::AddEq(bB->m_linearVelocity->y,(bB->m_invMass * P2Y));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",386)
			hx::AddEq(bB->m_angularVelocity,(bB->m_invI * (((r2X * P2Y) - (r2Y * P2X)))));
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",389)
		if (((this->m_limitState1 == ::box2D::dynamics::joints::B2Joint_obj::e_atUpperLimit))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",392)
			v1X = (bA->m_linearVelocity->x + (-(bA->m_angularVelocity) * r1Y));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",393)
			v1Y = (bA->m_linearVelocity->y + (bA->m_angularVelocity * r1X));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",396)
			Cdot = -((((this->m_u1->x * v1X) + (this->m_u1->y * v1Y))));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",397)
			impulse = (-(this->m_limitMass1) * Cdot);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",398)
			oldImpulse = this->m_limitImpulse1;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",399)
			this->m_limitImpulse1 = ::box2D::common::math::B2Math_obj::max(0.0,(this->m_limitImpulse1 + impulse));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",400)
			impulse = (this->m_limitImpulse1 - oldImpulse);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",403)
			P1X = (-(impulse) * this->m_u1->x);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",404)
			P1Y = (-(impulse) * this->m_u1->y);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",406)
			hx::AddEq(bA->m_linearVelocity->x,(bA->m_invMass * P1X));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",407)
			hx::AddEq(bA->m_linearVelocity->y,(bA->m_invMass * P1Y));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",409)
			hx::AddEq(bA->m_angularVelocity,(bA->m_invI * (((r1X * P1Y) - (r1Y * P1X)))));
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",412)
		if (((this->m_limitState2 == ::box2D::dynamics::joints::B2Joint_obj::e_atUpperLimit))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",415)
			v2X = (bB->m_linearVelocity->x + (-(bB->m_angularVelocity) * r2Y));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",416)
			v2Y = (bB->m_linearVelocity->y + (bB->m_angularVelocity * r2X));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",419)
			Cdot = -((((this->m_u2->x * v2X) + (this->m_u2->y * v2Y))));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",420)
			impulse = (-(this->m_limitMass2) * Cdot);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",421)
			oldImpulse = this->m_limitImpulse2;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",422)
			this->m_limitImpulse2 = ::box2D::common::math::B2Math_obj::max(0.0,(this->m_limitImpulse2 + impulse));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",423)
			impulse = (this->m_limitImpulse2 - oldImpulse);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",426)
			P2X = (-(impulse) * this->m_u2->x);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",427)
			P2Y = (-(impulse) * this->m_u2->y);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",429)
			hx::AddEq(bB->m_linearVelocity->x,(bB->m_invMass * P2X));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",430)
			hx::AddEq(bB->m_linearVelocity->y,(bB->m_invMass * P2Y));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",432)
			hx::AddEq(bB->m_angularVelocity,(bB->m_invI * (((r2X * P2Y) - (r2Y * P2X)))));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2PulleyJoint_obj,solveVelocityConstraints,(void))

bool B2PulleyJoint_obj::solvePositionConstraints( double baumgarte){
	HX_SOURCE_PUSH("B2PulleyJoint_obj::solvePositionConstraints")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",440)
	::box2D::dynamics::B2Body bA = this->m_bodyA;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",441)
	::box2D::dynamics::B2Body bB = this->m_bodyB;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",443)
	::box2D::common::math::B2Mat22 tMat;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",446)
	double s1X = (this->m_ground->m_xf->position->x + this->m_groundAnchor1->x);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",447)
	double s1Y = (this->m_ground->m_xf->position->y + this->m_groundAnchor1->y);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",449)
	double s2X = (this->m_ground->m_xf->position->x + this->m_groundAnchor2->x);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",450)
	double s2Y = (this->m_ground->m_xf->position->y + this->m_groundAnchor2->y);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",453)
	double r1X;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",454)
	double r1Y;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",455)
	double r2X;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",456)
	double r2Y;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",457)
	double p1X;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",458)
	double p1Y;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",459)
	double p2X;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",460)
	double p2Y;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",461)
	double length1;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",462)
	double length2;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",463)
	double C;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",464)
	double impulse;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",465)
	double oldImpulse;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",466)
	double oldLimitPositionImpulse;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",468)
	double tX;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",470)
	double linearError = 0.0;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",472)
	if (((this->m_state == ::box2D::dynamics::joints::B2Joint_obj::e_atUpperLimit))){
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",475)
		tMat = bA->m_xf->R;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",476)
		r1X = (this->m_localAnchor1->x - bA->m_sweep->localCenter->x);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",477)
		r1Y = (this->m_localAnchor1->y - bA->m_sweep->localCenter->y);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",478)
		tX = ((tMat->col1->x * r1X) + (tMat->col2->x * r1Y));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",479)
		r1Y = ((tMat->col1->y * r1X) + (tMat->col2->y * r1Y));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",480)
		r1X = tX;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",482)
		tMat = bB->m_xf->R;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",483)
		r2X = (this->m_localAnchor2->x - bB->m_sweep->localCenter->x);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",484)
		r2Y = (this->m_localAnchor2->y - bB->m_sweep->localCenter->y);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",485)
		tX = ((tMat->col1->x * r2X) + (tMat->col2->x * r2Y));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",486)
		r2Y = ((tMat->col1->y * r2X) + (tMat->col2->y * r2Y));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",487)
		r2X = tX;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",490)
		p1X = (bA->m_sweep->c->x + r1X);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",491)
		p1Y = (bA->m_sweep->c->y + r1Y);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",493)
		p2X = (bB->m_sweep->c->x + r2X);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",494)
		p2Y = (bB->m_sweep->c->y + r2Y);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",498)
		this->m_u1->set((p1X - s1X),(p1Y - s1Y));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",500)
		this->m_u2->set((p2X - s2X),(p2Y - s2Y));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",502)
		length1 = this->m_u1->length();
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",503)
		length2 = this->m_u2->length();
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",505)
		if (((length1 > ::box2D::common::B2Settings_obj::b2_linearSlop))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",506)
			this->m_u1->multiply((double(1.0) / double(length1)));
		}
		else{
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",511)
			this->m_u1->setZero();
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",515)
		if (((length2 > ::box2D::common::B2Settings_obj::b2_linearSlop))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",516)
			this->m_u2->multiply((double(1.0) / double(length2)));
		}
		else{
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",521)
			this->m_u2->setZero();
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",525)
		C = ((this->m_constant - length1) - (this->m_ratio * length2));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",526)
		linearError = ::box2D::common::math::B2Math_obj::max(linearError,-(C));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",527)
		C = ::box2D::common::math::B2Math_obj::clamp((C + ::box2D::common::B2Settings_obj::b2_linearSlop),-(::box2D::common::B2Settings_obj::b2_maxLinearCorrection),0.0);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",528)
		impulse = (-(this->m_pulleyMass) * C);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",530)
		p1X = (-(impulse) * this->m_u1->x);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",531)
		p1Y = (-(impulse) * this->m_u1->y);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",532)
		p2X = ((-(this->m_ratio) * impulse) * this->m_u2->x);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",533)
		p2Y = ((-(this->m_ratio) * impulse) * this->m_u2->y);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",535)
		hx::AddEq(bA->m_sweep->c->x,(bA->m_invMass * p1X));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",536)
		hx::AddEq(bA->m_sweep->c->y,(bA->m_invMass * p1Y));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",537)
		hx::AddEq(bA->m_sweep->a,(bA->m_invI * (((r1X * p1Y) - (r1Y * p1X)))));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",538)
		hx::AddEq(bB->m_sweep->c->x,(bB->m_invMass * p2X));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",539)
		hx::AddEq(bB->m_sweep->c->y,(bB->m_invMass * p2Y));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",540)
		hx::AddEq(bB->m_sweep->a,(bB->m_invI * (((r2X * p2Y) - (r2Y * p2X)))));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",542)
		bA->synchronizeTransform();
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",543)
		bB->synchronizeTransform();
	}
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",546)
	if (((this->m_limitState1 == ::box2D::dynamics::joints::B2Joint_obj::e_atUpperLimit))){
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",549)
		tMat = bA->m_xf->R;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",550)
		r1X = (this->m_localAnchor1->x - bA->m_sweep->localCenter->x);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",551)
		r1Y = (this->m_localAnchor1->y - bA->m_sweep->localCenter->y);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",552)
		tX = ((tMat->col1->x * r1X) + (tMat->col2->x * r1Y));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",553)
		r1Y = ((tMat->col1->y * r1X) + (tMat->col2->y * r1Y));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",554)
		r1X = tX;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",556)
		p1X = (bA->m_sweep->c->x + r1X);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",557)
		p1Y = (bA->m_sweep->c->y + r1Y);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",560)
		this->m_u1->set((p1X - s1X),(p1Y - s1Y));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",562)
		length1 = this->m_u1->length();
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",564)
		if (((length1 > ::box2D::common::B2Settings_obj::b2_linearSlop))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",567)
			hx::MultEq(this->m_u1->x,(double(1.0) / double(length1)));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",568)
			hx::MultEq(this->m_u1->y,(double(1.0) / double(length1)));
		}
		else{
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",571)
			this->m_u1->setZero();
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",575)
		C = (this->m_maxLength1 - length1);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",576)
		linearError = ::box2D::common::math::B2Math_obj::max(linearError,-(C));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",577)
		C = ::box2D::common::math::B2Math_obj::clamp((C + ::box2D::common::B2Settings_obj::b2_linearSlop),-(::box2D::common::B2Settings_obj::b2_maxLinearCorrection),0.0);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",578)
		impulse = (-(this->m_limitMass1) * C);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",581)
		p1X = (-(impulse) * this->m_u1->x);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",582)
		p1Y = (-(impulse) * this->m_u1->y);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",584)
		hx::AddEq(bA->m_sweep->c->x,(bA->m_invMass * p1X));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",585)
		hx::AddEq(bA->m_sweep->c->y,(bA->m_invMass * p1Y));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",587)
		hx::AddEq(bA->m_sweep->a,(bA->m_invI * (((r1X * p1Y) - (r1Y * p1X)))));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",589)
		bA->synchronizeTransform();
	}
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",592)
	if (((this->m_limitState2 == ::box2D::dynamics::joints::B2Joint_obj::e_atUpperLimit))){
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",595)
		tMat = bB->m_xf->R;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",596)
		r2X = (this->m_localAnchor2->x - bB->m_sweep->localCenter->x);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",597)
		r2Y = (this->m_localAnchor2->y - bB->m_sweep->localCenter->y);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",598)
		tX = ((tMat->col1->x * r2X) + (tMat->col2->x * r2Y));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",599)
		r2Y = ((tMat->col1->y * r2X) + (tMat->col2->y * r2Y));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",600)
		r2X = tX;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",602)
		p2X = (bB->m_sweep->c->x + r2X);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",603)
		p2Y = (bB->m_sweep->c->y + r2Y);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",606)
		this->m_u2->set((p2X - s2X),(p2Y - s2Y));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",608)
		length2 = this->m_u2->length();
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",610)
		if (((length2 > ::box2D::common::B2Settings_obj::b2_linearSlop))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",613)
			hx::MultEq(this->m_u2->x,(double(1.0) / double(length2)));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",614)
			hx::MultEq(this->m_u2->y,(double(1.0) / double(length2)));
		}
		else{
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",617)
			this->m_u2->setZero();
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",621)
		C = (this->m_maxLength2 - length2);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",622)
		linearError = ::box2D::common::math::B2Math_obj::max(linearError,-(C));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",623)
		C = ::box2D::common::math::B2Math_obj::clamp((C + ::box2D::common::B2Settings_obj::b2_linearSlop),-(::box2D::common::B2Settings_obj::b2_maxLinearCorrection),0.0);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",624)
		impulse = (-(this->m_limitMass2) * C);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",627)
		p2X = (-(impulse) * this->m_u2->x);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",628)
		p2Y = (-(impulse) * this->m_u2->y);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",631)
		hx::AddEq(bB->m_sweep->c->x,(bB->m_invMass * p2X));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",632)
		hx::AddEq(bB->m_sweep->c->y,(bB->m_invMass * p2Y));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",634)
		hx::AddEq(bB->m_sweep->a,(bB->m_invI * (((r2X * p2Y) - (r2Y * p2X)))));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",636)
		bB->synchronizeTransform();
	}
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/joints/B2PulleyJoint.hx",639)
	return (linearError < ::box2D::common::B2Settings_obj::b2_linearSlop);
}


HX_DEFINE_DYNAMIC_FUNC1(B2PulleyJoint_obj,solvePositionConstraints,return )

double B2PulleyJoint_obj::b2_minPulleyLength;


B2PulleyJoint_obj::B2PulleyJoint_obj()
{
}

void B2PulleyJoint_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(B2PulleyJoint);
	HX_MARK_MEMBER_NAME(m_ground,"m_ground");
	HX_MARK_MEMBER_NAME(m_groundAnchor1,"m_groundAnchor1");
	HX_MARK_MEMBER_NAME(m_groundAnchor2,"m_groundAnchor2");
	HX_MARK_MEMBER_NAME(m_localAnchor1,"m_localAnchor1");
	HX_MARK_MEMBER_NAME(m_localAnchor2,"m_localAnchor2");
	HX_MARK_MEMBER_NAME(m_u1,"m_u1");
	HX_MARK_MEMBER_NAME(m_u2,"m_u2");
	HX_MARK_MEMBER_NAME(m_constant,"m_constant");
	HX_MARK_MEMBER_NAME(m_ratio,"m_ratio");
	HX_MARK_MEMBER_NAME(m_maxLength1,"m_maxLength1");
	HX_MARK_MEMBER_NAME(m_maxLength2,"m_maxLength2");
	HX_MARK_MEMBER_NAME(m_pulleyMass,"m_pulleyMass");
	HX_MARK_MEMBER_NAME(m_limitMass1,"m_limitMass1");
	HX_MARK_MEMBER_NAME(m_limitMass2,"m_limitMass2");
	HX_MARK_MEMBER_NAME(m_impulse,"m_impulse");
	HX_MARK_MEMBER_NAME(m_limitImpulse1,"m_limitImpulse1");
	HX_MARK_MEMBER_NAME(m_limitImpulse2,"m_limitImpulse2");
	HX_MARK_MEMBER_NAME(m_state,"m_state");
	HX_MARK_MEMBER_NAME(m_limitState1,"m_limitState1");
	HX_MARK_MEMBER_NAME(m_limitState2,"m_limitState2");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic B2PulleyJoint_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"m_u1") ) { return m_u1; }
		if (HX_FIELD_EQ(inName,"m_u2") ) { return m_u2; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"m_ratio") ) { return m_ratio; }
		if (HX_FIELD_EQ(inName,"m_state") ) { return m_state; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"getRatio") ) { return getRatio_dyn(); }
		if (HX_FIELD_EQ(inName,"m_ground") ) { return m_ground; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"m_impulse") ) { return m_impulse; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"getAnchorA") ) { return getAnchorA_dyn(); }
		if (HX_FIELD_EQ(inName,"getAnchorB") ) { return getAnchorB_dyn(); }
		if (HX_FIELD_EQ(inName,"getLength1") ) { return getLength1_dyn(); }
		if (HX_FIELD_EQ(inName,"getLength2") ) { return getLength2_dyn(); }
		if (HX_FIELD_EQ(inName,"m_constant") ) { return m_constant; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"m_maxLength1") ) { return m_maxLength1; }
		if (HX_FIELD_EQ(inName,"m_maxLength2") ) { return m_maxLength2; }
		if (HX_FIELD_EQ(inName,"m_pulleyMass") ) { return m_pulleyMass; }
		if (HX_FIELD_EQ(inName,"m_limitMass1") ) { return m_limitMass1; }
		if (HX_FIELD_EQ(inName,"m_limitMass2") ) { return m_limitMass2; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"m_limitState1") ) { return m_limitState1; }
		if (HX_FIELD_EQ(inName,"m_limitState2") ) { return m_limitState2; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"m_localAnchor1") ) { return m_localAnchor1; }
		if (HX_FIELD_EQ(inName,"m_localAnchor2") ) { return m_localAnchor2; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"m_groundAnchor1") ) { return m_groundAnchor1; }
		if (HX_FIELD_EQ(inName,"m_groundAnchor2") ) { return m_groundAnchor2; }
		if (HX_FIELD_EQ(inName,"m_limitImpulse1") ) { return m_limitImpulse1; }
		if (HX_FIELD_EQ(inName,"m_limitImpulse2") ) { return m_limitImpulse2; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"getReactionForce") ) { return getReactionForce_dyn(); }
		if (HX_FIELD_EQ(inName,"getGroundAnchorA") ) { return getGroundAnchorA_dyn(); }
		if (HX_FIELD_EQ(inName,"getGroundAnchorB") ) { return getGroundAnchorB_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"getReactionTorque") ) { return getReactionTorque_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"b2_minPulleyLength") ) { return b2_minPulleyLength; }
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

Dynamic B2PulleyJoint_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"m_u1") ) { m_u1=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_u2") ) { m_u2=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"m_ratio") ) { m_ratio=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_state") ) { m_state=inValue.Cast< int >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"m_ground") ) { m_ground=inValue.Cast< ::box2D::dynamics::B2Body >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"m_impulse") ) { m_impulse=inValue.Cast< double >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"m_constant") ) { m_constant=inValue.Cast< double >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"m_maxLength1") ) { m_maxLength1=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_maxLength2") ) { m_maxLength2=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_pulleyMass") ) { m_pulleyMass=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_limitMass1") ) { m_limitMass1=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_limitMass2") ) { m_limitMass2=inValue.Cast< double >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"m_limitState1") ) { m_limitState1=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_limitState2") ) { m_limitState2=inValue.Cast< int >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"m_localAnchor1") ) { m_localAnchor1=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_localAnchor2") ) { m_localAnchor2=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"m_groundAnchor1") ) { m_groundAnchor1=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_groundAnchor2") ) { m_groundAnchor2=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_limitImpulse1") ) { m_limitImpulse1=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_limitImpulse2") ) { m_limitImpulse2=inValue.Cast< double >(); return inValue; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"b2_minPulleyLength") ) { b2_minPulleyLength=inValue.Cast< double >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void B2PulleyJoint_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("m_ground"));
	outFields->push(HX_CSTRING("m_groundAnchor1"));
	outFields->push(HX_CSTRING("m_groundAnchor2"));
	outFields->push(HX_CSTRING("m_localAnchor1"));
	outFields->push(HX_CSTRING("m_localAnchor2"));
	outFields->push(HX_CSTRING("m_u1"));
	outFields->push(HX_CSTRING("m_u2"));
	outFields->push(HX_CSTRING("m_constant"));
	outFields->push(HX_CSTRING("m_ratio"));
	outFields->push(HX_CSTRING("m_maxLength1"));
	outFields->push(HX_CSTRING("m_maxLength2"));
	outFields->push(HX_CSTRING("m_pulleyMass"));
	outFields->push(HX_CSTRING("m_limitMass1"));
	outFields->push(HX_CSTRING("m_limitMass2"));
	outFields->push(HX_CSTRING("m_impulse"));
	outFields->push(HX_CSTRING("m_limitImpulse1"));
	outFields->push(HX_CSTRING("m_limitImpulse2"));
	outFields->push(HX_CSTRING("m_state"));
	outFields->push(HX_CSTRING("m_limitState1"));
	outFields->push(HX_CSTRING("m_limitState2"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("b2_minPulleyLength"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("getAnchorA"),
	HX_CSTRING("getAnchorB"),
	HX_CSTRING("getReactionForce"),
	HX_CSTRING("getReactionTorque"),
	HX_CSTRING("getGroundAnchorA"),
	HX_CSTRING("getGroundAnchorB"),
	HX_CSTRING("getLength1"),
	HX_CSTRING("getLength2"),
	HX_CSTRING("getRatio"),
	HX_CSTRING("initVelocityConstraints"),
	HX_CSTRING("solveVelocityConstraints"),
	HX_CSTRING("solvePositionConstraints"),
	HX_CSTRING("m_ground"),
	HX_CSTRING("m_groundAnchor1"),
	HX_CSTRING("m_groundAnchor2"),
	HX_CSTRING("m_localAnchor1"),
	HX_CSTRING("m_localAnchor2"),
	HX_CSTRING("m_u1"),
	HX_CSTRING("m_u2"),
	HX_CSTRING("m_constant"),
	HX_CSTRING("m_ratio"),
	HX_CSTRING("m_maxLength1"),
	HX_CSTRING("m_maxLength2"),
	HX_CSTRING("m_pulleyMass"),
	HX_CSTRING("m_limitMass1"),
	HX_CSTRING("m_limitMass2"),
	HX_CSTRING("m_impulse"),
	HX_CSTRING("m_limitImpulse1"),
	HX_CSTRING("m_limitImpulse2"),
	HX_CSTRING("m_state"),
	HX_CSTRING("m_limitState1"),
	HX_CSTRING("m_limitState2"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(B2PulleyJoint_obj::b2_minPulleyLength,"b2_minPulleyLength");
};

Class B2PulleyJoint_obj::__mClass;

void B2PulleyJoint_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.dynamics.joints.B2PulleyJoint"), hx::TCanCast< B2PulleyJoint_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void B2PulleyJoint_obj::__boot()
{
	hx::Static(b2_minPulleyLength) = 2.0;
}

} // end namespace box2D
} // end namespace dynamics
} // end namespace joints
