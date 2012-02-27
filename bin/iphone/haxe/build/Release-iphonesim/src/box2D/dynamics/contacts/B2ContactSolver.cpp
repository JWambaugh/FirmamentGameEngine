#include <hxcpp.h>

#ifndef INCLUDED_box2D_collision_B2Manifold
#include <box2D/collision/B2Manifold.h>
#endif
#ifndef INCLUDED_box2D_collision_B2ManifoldPoint
#include <box2D/collision/B2ManifoldPoint.h>
#endif
#ifndef INCLUDED_box2D_collision_B2WorldManifold
#include <box2D/collision/B2WorldManifold.h>
#endif
#ifndef INCLUDED_box2D_collision_shapes_B2Shape
#include <box2D/collision/shapes/B2Shape.h>
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
#ifndef INCLUDED_box2D_dynamics_B2Fixture
#include <box2D/dynamics/B2Fixture.h>
#endif
#ifndef INCLUDED_box2D_dynamics_B2TimeStep
#include <box2D/dynamics/B2TimeStep.h>
#endif
#ifndef INCLUDED_box2D_dynamics_contacts_B2Contact
#include <box2D/dynamics/contacts/B2Contact.h>
#endif
#ifndef INCLUDED_box2D_dynamics_contacts_B2ContactConstraint
#include <box2D/dynamics/contacts/B2ContactConstraint.h>
#endif
#ifndef INCLUDED_box2D_dynamics_contacts_B2ContactConstraintPoint
#include <box2D/dynamics/contacts/B2ContactConstraintPoint.h>
#endif
#ifndef INCLUDED_box2D_dynamics_contacts_B2ContactSolver
#include <box2D/dynamics/contacts/B2ContactSolver.h>
#endif
#ifndef INCLUDED_box2D_dynamics_contacts_B2PositionSolverManifold
#include <box2D/dynamics/contacts/B2PositionSolverManifold.h>
#endif
namespace box2D{
namespace dynamics{
namespace contacts{

Void B2ContactSolver_obj::__construct()
{
{
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",44)
	this->m_step = ::box2D::dynamics::B2TimeStep_obj::__new();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",45)
	this->m_constraints = Array_obj< ::box2D::dynamics::contacts::B2ContactConstraint >::__new();
}
;
	return null();
}

B2ContactSolver_obj::~B2ContactSolver_obj() { }

Dynamic B2ContactSolver_obj::__CreateEmpty() { return  new B2ContactSolver_obj; }
hx::ObjectPtr< B2ContactSolver_obj > B2ContactSolver_obj::__new()
{  hx::ObjectPtr< B2ContactSolver_obj > result = new B2ContactSolver_obj();
	result->__construct();
	return result;}

Dynamic B2ContactSolver_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2ContactSolver_obj > result = new B2ContactSolver_obj();
	result->__construct();
	return result;}

Void B2ContactSolver_obj::initialize( ::box2D::dynamics::B2TimeStep step,Array< ::box2D::dynamics::contacts::B2Contact > contacts,int contactCount,Dynamic allocator){
{
		HX_SOURCE_PUSH("B2ContactSolver_obj::initialize")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",51)
		::box2D::dynamics::contacts::B2Contact contact;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",53)
		this->m_step->set(step);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",55)
		this->m_allocator = allocator;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",57)
		int i;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",58)
		::box2D::common::math::B2Vec2 tVec;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",59)
		::box2D::common::math::B2Mat22 tMat;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",61)
		this->m_constraintCount = contactCount;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",64)
		while(((this->m_constraints->length < this->m_constraintCount))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",65)
			this->m_constraints[this->m_constraints->length] = ::box2D::dynamics::contacts::B2ContactConstraint_obj::__new();
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",69)
		{
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",69)
			int _g = (int)0;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",69)
			while(((_g < contactCount))){
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",69)
				int i1 = (_g)++;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",71)
				contact = contacts->__get(i1);
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",72)
				::box2D::dynamics::B2Fixture fixtureA = contact->m_fixtureA;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",73)
				::box2D::dynamics::B2Fixture fixtureB = contact->m_fixtureB;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",74)
				::box2D::collision::shapes::B2Shape shapeA = fixtureA->m_shape;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",75)
				::box2D::collision::shapes::B2Shape shapeB = fixtureB->m_shape;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",76)
				double radiusA = shapeA->m_radius;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",77)
				double radiusB = shapeB->m_radius;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",78)
				::box2D::dynamics::B2Body bodyA = fixtureA->m_body;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",79)
				::box2D::dynamics::B2Body bodyB = fixtureB->m_body;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",80)
				::box2D::collision::B2Manifold manifold = contact->getManifold();
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",82)
				double friction = ::box2D::common::B2Settings_obj::b2MixFriction(fixtureA->getFriction(),fixtureB->getFriction());
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",83)
				double restitution = ::box2D::common::B2Settings_obj::b2MixRestitution(fixtureA->getRestitution(),fixtureB->getRestitution());
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",86)
				double vAX = bodyA->m_linearVelocity->x;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",87)
				double vAY = bodyA->m_linearVelocity->y;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",89)
				double vBX = bodyB->m_linearVelocity->x;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",90)
				double vBY = bodyB->m_linearVelocity->y;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",91)
				double wA = bodyA->m_angularVelocity;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",92)
				double wB = bodyB->m_angularVelocity;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",94)
				::box2D::common::B2Settings_obj::b2Assert((manifold->m_pointCount > (int)0));
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",96)
				::box2D::dynamics::contacts::B2ContactSolver_obj::s_worldManifold->initialize(manifold,bodyA->m_xf,radiusA,bodyB->m_xf,radiusB);
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",98)
				double normalX = ::box2D::dynamics::contacts::B2ContactSolver_obj::s_worldManifold->m_normal->x;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",99)
				double normalY = ::box2D::dynamics::contacts::B2ContactSolver_obj::s_worldManifold->m_normal->y;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",101)
				::box2D::dynamics::contacts::B2ContactConstraint cc = this->m_constraints->__get(i1);
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",102)
				cc->bodyA = bodyA;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",103)
				cc->bodyB = bodyB;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",104)
				cc->manifold = manifold;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",106)
				cc->normal->x = normalX;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",107)
				cc->normal->y = normalY;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",108)
				cc->pointCount = manifold->m_pointCount;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",109)
				cc->friction = friction;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",110)
				cc->restitution = restitution;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",112)
				cc->localPlaneNormal->x = manifold->m_localPlaneNormal->x;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",113)
				cc->localPlaneNormal->y = manifold->m_localPlaneNormal->y;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",114)
				cc->localPoint->x = manifold->m_localPoint->x;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",115)
				cc->localPoint->y = manifold->m_localPoint->y;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",116)
				cc->radius = (radiusA + radiusB);
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",117)
				cc->type = manifold->m_type;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",119)
				{
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",119)
					int _g2 = (int)0;
					int _g1 = cc->pointCount;
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",119)
					while(((_g2 < _g1))){
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",119)
						int k = (_g2)++;
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",121)
						::box2D::collision::B2ManifoldPoint cp = manifold->m_points->__get(k);
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",122)
						::box2D::dynamics::contacts::B2ContactConstraintPoint ccp = cc->points->__get(k);
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",124)
						ccp->normalImpulse = cp->m_normalImpulse;
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",125)
						ccp->tangentImpulse = cp->m_tangentImpulse;
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",127)
						ccp->localPoint->setV(cp->m_localPoint);
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",129)
						double rAX = ccp->rA->x = (::box2D::dynamics::contacts::B2ContactSolver_obj::s_worldManifold->m_points->__get(k)->x - bodyA->m_sweep->c->x);
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",130)
						double rAY = ccp->rA->y = (::box2D::dynamics::contacts::B2ContactSolver_obj::s_worldManifold->m_points->__get(k)->y - bodyA->m_sweep->c->y);
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",131)
						double rBX = ccp->rB->x = (::box2D::dynamics::contacts::B2ContactSolver_obj::s_worldManifold->m_points->__get(k)->x - bodyB->m_sweep->c->x);
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",132)
						double rBY = ccp->rB->y = (::box2D::dynamics::contacts::B2ContactSolver_obj::s_worldManifold->m_points->__get(k)->y - bodyB->m_sweep->c->y);
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",134)
						double rnA = ((rAX * normalY) - (rAY * normalX));
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",135)
						double rnB = ((rBX * normalY) - (rBY * normalX));
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",137)
						hx::MultEq(rnA,rnA);
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",138)
						hx::MultEq(rnB,rnB);
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",140)
						double kNormal = (((bodyA->m_invMass + bodyB->m_invMass) + (bodyA->m_invI * rnA)) + (bodyB->m_invI * rnB));
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",142)
						ccp->normalMass = (double(1.0) / double(kNormal));
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",144)
						double kEqualized = ((bodyA->m_mass * bodyA->m_invMass) + (bodyB->m_mass * bodyB->m_invMass));
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",145)
						hx::AddEq(kEqualized,(((bodyA->m_mass * bodyA->m_invI) * rnA) + ((bodyB->m_mass * bodyB->m_invI) * rnB)));
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",147)
						ccp->equalizedMass = (double(1.0) / double(kEqualized));
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",150)
						double tangentX = normalY;
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",151)
						double tangentY = -(normalX);
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",154)
						double rtA = ((rAX * tangentY) - (rAY * tangentX));
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",156)
						double rtB = ((rBX * tangentY) - (rBY * tangentX));
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",158)
						hx::MultEq(rtA,rtA);
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",159)
						hx::MultEq(rtB,rtB);
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",161)
						double kTangent = (((bodyA->m_invMass + bodyB->m_invMass) + (bodyA->m_invI * rtA)) + (bodyB->m_invI * rtB));
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",163)
						ccp->tangentMass = (double(1.0) / double(kTangent));
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",166)
						ccp->velocityBias = 0.0;
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",168)
						double tX = (((vBX + (-(wB) * rBY)) - vAX) - (-(wA) * rAY));
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",169)
						double tY = (((vBY + (wB * rBX)) - vAY) - (wA * rAX));
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",171)
						double vRel = ((cc->normal->x * tX) + (cc->normal->y * tY));
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",172)
						if (((vRel < -(::box2D::common::B2Settings_obj::b2_velocityThreshold)))){
							HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",173)
							hx::AddEq(ccp->velocityBias,(-(cc->restitution) * vRel));
						}
					}
				}
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",179)
				if (((cc->pointCount == (int)2))){
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",181)
					::box2D::dynamics::contacts::B2ContactConstraintPoint ccp1 = cc->points->__get((int)0);
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",182)
					::box2D::dynamics::contacts::B2ContactConstraintPoint ccp2 = cc->points->__get((int)1);
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",184)
					double invMassA = bodyA->m_invMass;
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",185)
					double invIA = bodyA->m_invI;
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",186)
					double invMassB = bodyB->m_invMass;
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",187)
					double invIB = bodyB->m_invI;
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",193)
					double rn1A = ((ccp1->rA->x * normalY) - (ccp1->rA->y * normalX));
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",194)
					double rn1B = ((ccp1->rB->x * normalY) - (ccp1->rB->y * normalX));
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",195)
					double rn2A = ((ccp2->rA->x * normalY) - (ccp2->rA->y * normalX));
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",196)
					double rn2B = ((ccp2->rB->x * normalY) - (ccp2->rB->y * normalX));
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",198)
					double k11 = (((invMassA + invMassB) + ((invIA * rn1A) * rn1A)) + ((invIB * rn1B) * rn1B));
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",199)
					double k22 = (((invMassA + invMassB) + ((invIA * rn2A) * rn2A)) + ((invIB * rn2B) * rn2B));
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",200)
					double k12 = (((invMassA + invMassB) + ((invIA * rn1A) * rn2A)) + ((invIB * rn1B) * rn2B));
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",203)
					double k_maxConditionNumber = 100.0;
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",204)
					if ((((k11 * k11) < (k_maxConditionNumber * (((k11 * k22) - (k12 * k12))))))){
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",207)
						cc->K->col1->set(k11,k12);
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",208)
						cc->K->col2->set(k12,k22);
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",209)
						cc->K->getInverse(cc->normalMass);
					}
					else{
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",212)
						cc->pointCount = (int)1;
					}
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(B2ContactSolver_obj,initialize,(void))

Void B2ContactSolver_obj::initVelocityConstraints( ::box2D::dynamics::B2TimeStep step){
{
		HX_SOURCE_PUSH("B2ContactSolver_obj::initVelocityConstraints")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",225)
		::box2D::common::math::B2Vec2 tVec;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",226)
		::box2D::common::math::B2Vec2 tVec2;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",227)
		::box2D::common::math::B2Mat22 tMat;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",230)
		{
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",230)
			int _g1 = (int)0;
			int _g = this->m_constraintCount;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",230)
			while(((_g1 < _g))){
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",230)
				int i = (_g1)++;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",232)
				::box2D::dynamics::contacts::B2ContactConstraint c = this->m_constraints->__get(i);
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",234)
				::box2D::dynamics::B2Body bodyA = c->bodyA;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",235)
				::box2D::dynamics::B2Body bodyB = c->bodyB;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",236)
				double invMassA = bodyA->m_invMass;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",237)
				double invIA = bodyA->m_invI;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",238)
				double invMassB = bodyB->m_invMass;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",239)
				double invIB = bodyB->m_invI;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",241)
				double normalX = c->normal->x;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",242)
				double normalY = c->normal->y;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",244)
				double tangentX = normalY;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",245)
				double tangentY = -(normalX);
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",247)
				double tX;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",249)
				int j;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",250)
				int tCount;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",251)
				if ((step->warmStarting)){
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",253)
					tCount = c->pointCount;
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",254)
					{
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",254)
						int _g2 = (int)0;
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",254)
						while(((_g2 < tCount))){
							HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",254)
							int j1 = (_g2)++;
							HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",256)
							::box2D::dynamics::contacts::B2ContactConstraintPoint ccp = c->points->__get(j1);
							HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",257)
							hx::MultEq(ccp->normalImpulse,step->dtRatio);
							HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",258)
							hx::MultEq(ccp->tangentImpulse,step->dtRatio);
							HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",260)
							double PX = ((ccp->normalImpulse * normalX) + (ccp->tangentImpulse * tangentX));
							HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",261)
							double PY = ((ccp->normalImpulse * normalY) + (ccp->tangentImpulse * tangentY));
							HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",264)
							hx::SubEq(bodyA->m_angularVelocity,(invIA * (((ccp->rA->x * PY) - (ccp->rA->y * PX)))));
							HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",266)
							hx::SubEq(bodyA->m_linearVelocity->x,(invMassA * PX));
							HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",267)
							hx::SubEq(bodyA->m_linearVelocity->y,(invMassA * PY));
							HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",269)
							hx::AddEq(bodyB->m_angularVelocity,(invIB * (((ccp->rB->x * PY) - (ccp->rB->y * PX)))));
							HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",271)
							hx::AddEq(bodyB->m_linearVelocity->x,(invMassB * PX));
							HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",272)
							hx::AddEq(bodyB->m_linearVelocity->y,(invMassB * PY));
						}
					}
				}
				else{
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",277)
					tCount = c->pointCount;
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",278)
					{
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",278)
						int _g2 = (int)0;
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",278)
						while(((_g2 < tCount))){
							HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",278)
							int j1 = (_g2)++;
							HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",280)
							::box2D::dynamics::contacts::B2ContactConstraintPoint ccp2 = c->points->__get(j1);
							HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",281)
							ccp2->normalImpulse = 0.0;
							HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",282)
							ccp2->tangentImpulse = 0.0;
						}
					}
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2ContactSolver_obj,initVelocityConstraints,(void))

Void B2ContactSolver_obj::solveVelocityConstraints( ){
{
		HX_SOURCE_PUSH("B2ContactSolver_obj::solveVelocityConstraints")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",288)
		int j;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",289)
		::box2D::dynamics::contacts::B2ContactConstraintPoint ccp;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",290)
		double rAX;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",291)
		double rAY;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",292)
		double rBX;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",293)
		double rBY;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",294)
		double dvX;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",295)
		double dvY;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",296)
		double vn;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",297)
		double vt;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",298)
		double lambda;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",299)
		double maxFriction;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",300)
		double newImpulse;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",301)
		double PX;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",302)
		double PY;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",303)
		double dX;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",304)
		double dY;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",305)
		double P1X;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",306)
		double P1Y;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",307)
		double P2X;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",308)
		double P2Y;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",310)
		::box2D::common::math::B2Mat22 tMat;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",311)
		::box2D::common::math::B2Vec2 tVec;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",313)
		{
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",313)
			int _g1 = (int)0;
			int _g = this->m_constraintCount;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",313)
			while(((_g1 < _g))){
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",313)
				int i = (_g1)++;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",315)
				::box2D::dynamics::contacts::B2ContactConstraint c = this->m_constraints->__get(i);
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",316)
				::box2D::dynamics::B2Body bodyA = c->bodyA;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",317)
				::box2D::dynamics::B2Body bodyB = c->bodyB;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",318)
				double wA = bodyA->m_angularVelocity;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",319)
				double wB = bodyB->m_angularVelocity;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",320)
				::box2D::common::math::B2Vec2 vA = bodyA->m_linearVelocity;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",321)
				::box2D::common::math::B2Vec2 vB = bodyB->m_linearVelocity;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",323)
				double invMassA = bodyA->m_invMass;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",324)
				double invIA = bodyA->m_invI;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",325)
				double invMassB = bodyB->m_invMass;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",326)
				double invIB = bodyB->m_invI;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",328)
				double normalX = c->normal->x;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",329)
				double normalY = c->normal->y;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",331)
				double tangentX = normalY;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",332)
				double tangentY = -(normalX);
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",333)
				double friction = c->friction;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",335)
				double tX;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",339)
				{
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",339)
					int _g3 = (int)0;
					int _g2 = c->pointCount;
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",339)
					while(((_g3 < _g2))){
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",339)
						int j1 = (_g3)++;
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",341)
						ccp = c->points->__get(j1);
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",345)
						dvX = (((vB->x - (wB * ccp->rB->y)) - vA->x) + (wA * ccp->rA->y));
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",346)
						dvY = (((vB->y + (wB * ccp->rB->x)) - vA->y) - (wA * ccp->rA->x));
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",349)
						vt = ((dvX * tangentX) + (dvY * tangentY));
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",350)
						lambda = (ccp->tangentMass * -(vt));
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",353)
						maxFriction = (friction * ccp->normalImpulse);
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",354)
						newImpulse = ::box2D::common::math::B2Math_obj::clamp((ccp->tangentImpulse + lambda),-(maxFriction),maxFriction);
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",355)
						lambda = (newImpulse - ccp->tangentImpulse);
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",358)
						PX = (lambda * tangentX);
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",359)
						PY = (lambda * tangentY);
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",361)
						hx::SubEq(vA->x,(invMassA * PX));
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",362)
						hx::SubEq(vA->y,(invMassA * PY));
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",363)
						hx::SubEq(wA,(invIA * (((ccp->rA->x * PY) - (ccp->rA->y * PX)))));
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",365)
						hx::AddEq(vB->x,(invMassB * PX));
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",366)
						hx::AddEq(vB->y,(invMassB * PY));
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",367)
						hx::AddEq(wB,(invIB * (((ccp->rB->x * PY) - (ccp->rB->y * PX)))));
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",369)
						ccp->tangentImpulse = newImpulse;
					}
				}
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",373)
				int tCount = c->pointCount;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",374)
				if (((c->pointCount == (int)1))){
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",376)
					ccp = c->points->__get((int)0);
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",380)
					dvX = (((vB->x + (-(wB) * ccp->rB->y)) - vA->x) - (-(wA) * ccp->rA->y));
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",381)
					dvY = (((vB->y + (wB * ccp->rB->x)) - vA->y) - (wA * ccp->rA->x));
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",385)
					vn = ((dvX * normalX) + (dvY * normalY));
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",386)
					lambda = (-(ccp->normalMass) * ((vn - ccp->velocityBias)));
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",390)
					newImpulse = (ccp->normalImpulse + lambda);
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",391)
					newImpulse = (  (((newImpulse > (int)0))) ? double(newImpulse) : double(0.0) );
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",392)
					lambda = (newImpulse - ccp->normalImpulse);
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",396)
					PX = (lambda * normalX);
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",397)
					PY = (lambda * normalY);
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",400)
					hx::SubEq(vA->x,(invMassA * PX));
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",401)
					hx::SubEq(vA->y,(invMassA * PY));
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",402)
					hx::SubEq(wA,(invIA * (((ccp->rA->x * PY) - (ccp->rA->y * PX)))));
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",405)
					hx::AddEq(vB->x,(invMassB * PX));
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",406)
					hx::AddEq(vB->y,(invMassB * PY));
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",407)
					hx::AddEq(wB,(invIB * (((ccp->rB->x * PY) - (ccp->rB->y * PX)))));
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",409)
					ccp->normalImpulse = newImpulse;
				}
				else{
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",441)
					::box2D::dynamics::contacts::B2ContactConstraintPoint cp1 = c->points->__get((int)0);
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",442)
					::box2D::dynamics::contacts::B2ContactConstraintPoint cp2 = c->points->__get((int)1);
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",444)
					double aX = cp1->normalImpulse;
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",445)
					double aY = cp2->normalImpulse;
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",450)
					double dv1X = (((vB->x - (wB * cp1->rB->y)) - vA->x) + (wA * cp1->rA->y));
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",451)
					double dv1Y = (((vB->y + (wB * cp1->rB->x)) - vA->y) - (wA * cp1->rA->x));
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",453)
					double dv2X = (((vB->x - (wB * cp2->rB->y)) - vA->x) + (wA * cp2->rA->y));
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",454)
					double dv2Y = (((vB->y + (wB * cp2->rB->x)) - vA->y) - (wA * cp2->rA->x));
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",458)
					double vn1 = ((dv1X * normalX) + (dv1Y * normalY));
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",460)
					double vn2 = ((dv2X * normalX) + (dv2Y * normalY));
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",462)
					double bX = (vn1 - cp1->velocityBias);
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",463)
					double bY = (vn2 - cp2->velocityBias);
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",466)
					tMat = c->K;
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",467)
					hx::SubEq(bX,((tMat->col1->x * aX) + (tMat->col2->x * aY)));
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",468)
					hx::SubEq(bY,((tMat->col1->y * aX) + (tMat->col2->y * aY)));
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",470)
					double k_errorTol = 0.001;
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",471)
					{
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",471)
						int _g2 = (int)0;
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",471)
						while(((_g2 < (int)1))){
							HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",471)
							int i1 = (_g2)++;
							HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",484)
							tMat = c->normalMass;
							HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",485)
							double xX = -((((tMat->col1->x * bX) + (tMat->col2->x * bY))));
							HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",486)
							double xY = -((((tMat->col1->y * bX) + (tMat->col2->y * bY))));
							HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",488)
							if (((bool((xX >= 0.0)) && bool((xY >= 0.0))))){
								HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",491)
								dX = (xX - aX);
								HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",492)
								dY = (xY - aY);
								HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",496)
								P1X = (dX * normalX);
								HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",497)
								P1Y = (dX * normalY);
								HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",499)
								P2X = (dY * normalX);
								HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",500)
								P2Y = (dY * normalY);
								HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",503)
								hx::SubEq(vA->x,(invMassA * ((P1X + P2X))));
								HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",504)
								hx::SubEq(vA->y,(invMassA * ((P1Y + P2Y))));
								HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",506)
								hx::SubEq(wA,(invIA * (((((cp1->rA->x * P1Y) - (cp1->rA->y * P1X)) + (cp2->rA->x * P2Y)) - (cp2->rA->y * P2X)))));
								HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",509)
								hx::AddEq(vB->x,(invMassB * ((P1X + P2X))));
								HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",510)
								hx::AddEq(vB->y,(invMassB * ((P1Y + P2Y))));
								HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",512)
								hx::AddEq(wB,(invIB * (((((cp1->rB->x * P1Y) - (cp1->rB->y * P1X)) + (cp2->rB->x * P2Y)) - (cp2->rB->y * P2X)))));
								HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",515)
								cp1->normalImpulse = xX;
								HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",516)
								cp2->normalImpulse = xY;
								HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",535)
								break;
							}
							HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",545)
							xX = (-(cp1->normalMass) * bX);
							HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",546)
							xY = 0.0;
							HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",547)
							vn1 = 0.0;
							HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",548)
							vn2 = ((c->K->col1->y * xX) + bY);
							HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",550)
							if (((bool((xX >= 0.0)) && bool((vn2 >= 0.0))))){
								HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",554)
								dX = (xX - aX);
								HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",555)
								dY = (xY - aY);
								HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",559)
								P1X = (dX * normalX);
								HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",560)
								P1Y = (dX * normalY);
								HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",562)
								P2X = (dY * normalX);
								HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",563)
								P2Y = (dY * normalY);
								HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",566)
								hx::SubEq(vA->x,(invMassA * ((P1X + P2X))));
								HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",567)
								hx::SubEq(vA->y,(invMassA * ((P1Y + P2Y))));
								HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",569)
								hx::SubEq(wA,(invIA * (((((cp1->rA->x * P1Y) - (cp1->rA->y * P1X)) + (cp2->rA->x * P2Y)) - (cp2->rA->y * P2X)))));
								HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",572)
								hx::AddEq(vB->x,(invMassB * ((P1X + P2X))));
								HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",573)
								hx::AddEq(vB->y,(invMassB * ((P1Y + P2Y))));
								HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",575)
								hx::AddEq(wB,(invIB * (((((cp1->rB->x * P1Y) - (cp1->rB->y * P1X)) + (cp2->rB->x * P2Y)) - (cp2->rB->y * P2X)))));
								HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",578)
								cp1->normalImpulse = xX;
								HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",579)
								cp2->normalImpulse = xY;
								HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",598)
								break;
							}
							HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",608)
							xX = 0.0;
							HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",609)
							xY = (-(cp2->normalMass) * bY);
							HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",610)
							vn1 = ((c->K->col2->x * xY) + bX);
							HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",611)
							vn2 = 0.0;
							HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",612)
							if (((bool((xY >= 0.0)) && bool((vn1 >= 0.0))))){
								HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",616)
								dX = (xX - aX);
								HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",617)
								dY = (xY - aY);
								HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",621)
								P1X = (dX * normalX);
								HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",622)
								P1Y = (dX * normalY);
								HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",624)
								P2X = (dY * normalX);
								HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",625)
								P2Y = (dY * normalY);
								HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",628)
								hx::SubEq(vA->x,(invMassA * ((P1X + P2X))));
								HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",629)
								hx::SubEq(vA->y,(invMassA * ((P1Y + P2Y))));
								HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",631)
								hx::SubEq(wA,(invIA * (((((cp1->rA->x * P1Y) - (cp1->rA->y * P1X)) + (cp2->rA->x * P2Y)) - (cp2->rA->y * P2X)))));
								HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",634)
								hx::AddEq(vB->x,(invMassB * ((P1X + P2X))));
								HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",635)
								hx::AddEq(vB->y,(invMassB * ((P1Y + P2Y))));
								HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",637)
								hx::AddEq(wB,(invIB * (((((cp1->rB->x * P1Y) - (cp1->rB->y * P1X)) + (cp2->rB->x * P2Y)) - (cp2->rB->y * P2X)))));
								HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",640)
								cp1->normalImpulse = xX;
								HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",641)
								cp2->normalImpulse = xY;
								HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",660)
								break;
							}
							HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",669)
							xX = 0.0;
							HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",670)
							xY = 0.0;
							HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",671)
							vn1 = bX;
							HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",672)
							vn2 = bY;
							HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",674)
							if (((bool((vn1 >= 0.0)) && bool((vn2 >= 0.0))))){
								HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",677)
								dX = (xX - aX);
								HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",678)
								dY = (xY - aY);
								HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",682)
								P1X = (dX * normalX);
								HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",683)
								P1Y = (dX * normalY);
								HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",685)
								P2X = (dY * normalX);
								HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",686)
								P2Y = (dY * normalY);
								HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",689)
								hx::SubEq(vA->x,(invMassA * ((P1X + P2X))));
								HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",690)
								hx::SubEq(vA->y,(invMassA * ((P1Y + P2Y))));
								HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",692)
								hx::SubEq(wA,(invIA * (((((cp1->rA->x * P1Y) - (cp1->rA->y * P1X)) + (cp2->rA->x * P2Y)) - (cp2->rA->y * P2X)))));
								HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",695)
								hx::AddEq(vB->x,(invMassB * ((P1X + P2X))));
								HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",696)
								hx::AddEq(vB->y,(invMassB * ((P1Y + P2Y))));
								HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",698)
								hx::AddEq(wB,(invIB * (((((cp1->rB->x * P1Y) - (cp1->rB->y * P1X)) + (cp2->rB->x * P2Y)) - (cp2->rB->y * P2X)))));
								HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",701)
								cp1->normalImpulse = xX;
								HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",702)
								cp2->normalImpulse = xY;
								HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",721)
								break;
							}
							HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",725)
							break;
						}
					}
				}
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",736)
				bodyA->m_angularVelocity = wA;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",737)
				bodyB->m_angularVelocity = wB;
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(B2ContactSolver_obj,solveVelocityConstraints,(void))

Void B2ContactSolver_obj::finalizeVelocityConstraints( ){
{
		HX_SOURCE_PUSH("B2ContactSolver_obj::finalizeVelocityConstraints")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",743)
		int _g1 = (int)0;
		int _g = this->m_constraintCount;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",743)
		while(((_g1 < _g))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",743)
			int i = (_g1)++;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",745)
			::box2D::dynamics::contacts::B2ContactConstraint c = this->m_constraints->__get(i);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",746)
			::box2D::collision::B2Manifold m = c->manifold;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",748)
			{
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",748)
				int _g3 = (int)0;
				int _g2 = c->pointCount;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",748)
				while(((_g3 < _g2))){
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",748)
					int j = (_g3)++;
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",750)
					::box2D::collision::B2ManifoldPoint point1 = m->m_points->__get(j);
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",751)
					::box2D::dynamics::contacts::B2ContactConstraintPoint point2 = c->points->__get(j);
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",752)
					point1->m_normalImpulse = point2->normalImpulse;
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",753)
					point1->m_tangentImpulse = point2->tangentImpulse;
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(B2ContactSolver_obj,finalizeVelocityConstraints,(void))

bool B2ContactSolver_obj::solvePositionConstraints( double baumgarte){
	HX_SOURCE_PUSH("B2ContactSolver_obj::solvePositionConstraints")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",865)
	double minSeparation = 0.0;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",867)
	{
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",867)
		int _g1 = (int)0;
		int _g = this->m_constraintCount;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",867)
		while(((_g1 < _g))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",867)
			int i = (_g1)++;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",869)
			::box2D::dynamics::contacts::B2ContactConstraint c = this->m_constraints->__get(i);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",870)
			::box2D::dynamics::B2Body bodyA = c->bodyA;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",871)
			::box2D::dynamics::B2Body bodyB = c->bodyB;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",873)
			double invMassA = (bodyA->m_mass * bodyA->m_invMass);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",874)
			double invIA = (bodyA->m_mass * bodyA->m_invI);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",875)
			double invMassB = (bodyB->m_mass * bodyB->m_invMass);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",876)
			double invIB = (bodyB->m_mass * bodyB->m_invI);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",879)
			::box2D::dynamics::contacts::B2ContactSolver_obj::s_psm->initialize(c);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",880)
			::box2D::common::math::B2Vec2 normal = ::box2D::dynamics::contacts::B2ContactSolver_obj::s_psm->m_normal;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",883)
			{
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",883)
				int _g3 = (int)0;
				int _g2 = c->pointCount;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",883)
				while(((_g3 < _g2))){
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",883)
					int j = (_g3)++;
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",885)
					::box2D::dynamics::contacts::B2ContactConstraintPoint ccp = c->points->__get(j);
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",887)
					::box2D::common::math::B2Vec2 point = ::box2D::dynamics::contacts::B2ContactSolver_obj::s_psm->m_points->__get(j);
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",888)
					double separation = ::box2D::dynamics::contacts::B2ContactSolver_obj::s_psm->m_separations->__get(j);
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",890)
					double rAX = (point->x - bodyA->m_sweep->c->x);
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",891)
					double rAY = (point->y - bodyA->m_sweep->c->y);
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",892)
					double rBX = (point->x - bodyB->m_sweep->c->x);
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",893)
					double rBY = (point->y - bodyB->m_sweep->c->y);
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",896)
					minSeparation = (  (((minSeparation < separation))) ? double(minSeparation) : double(separation) );
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",899)
					double C = ::box2D::common::math::B2Math_obj::clamp((baumgarte * ((separation + ::box2D::common::B2Settings_obj::b2_linearSlop))),-(::box2D::common::B2Settings_obj::b2_maxLinearCorrection),0.0);
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",902)
					double impulse = (-(ccp->equalizedMass) * C);
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",904)
					double PX = (impulse * normal->x);
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",905)
					double PY = (impulse * normal->y);
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",908)
					hx::SubEq(bodyA->m_sweep->c->x,(invMassA * PX));
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",909)
					hx::SubEq(bodyA->m_sweep->c->y,(invMassA * PY));
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",911)
					hx::SubEq(bodyA->m_sweep->a,(invIA * (((rAX * PY) - (rAY * PX)))));
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",912)
					bodyA->synchronizeTransform();
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",915)
					hx::AddEq(bodyB->m_sweep->c->x,(invMassB * PX));
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",916)
					hx::AddEq(bodyB->m_sweep->c->y,(invMassB * PY));
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",918)
					hx::AddEq(bodyB->m_sweep->a,(invIB * (((rBX * PY) - (rBY * PX)))));
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",919)
					bodyB->synchronizeTransform();
				}
			}
		}
	}
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactSolver.hx",925)
	return (minSeparation > (-1.5 * ::box2D::common::B2Settings_obj::b2_linearSlop));
}


HX_DEFINE_DYNAMIC_FUNC1(B2ContactSolver_obj,solvePositionConstraints,return )

int B2ContactSolver_obj::staticFix;

::box2D::collision::B2WorldManifold B2ContactSolver_obj::s_worldManifold;

::box2D::dynamics::contacts::B2PositionSolverManifold B2ContactSolver_obj::s_psm;


B2ContactSolver_obj::B2ContactSolver_obj()
{
}

void B2ContactSolver_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(B2ContactSolver);
	HX_MARK_MEMBER_NAME(m_step,"m_step");
	HX_MARK_MEMBER_NAME(m_allocator,"m_allocator");
	HX_MARK_MEMBER_NAME(m_constraints,"m_constraints");
	HX_MARK_MEMBER_NAME(m_constraintCount,"m_constraintCount");
	HX_MARK_END_CLASS();
}

Dynamic B2ContactSolver_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"s_psm") ) { return s_psm; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"m_step") ) { return m_step; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"staticFix") ) { return staticFix; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"initialize") ) { return initialize_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"m_allocator") ) { return m_allocator; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"m_constraints") ) { return m_constraints; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"s_worldManifold") ) { return s_worldManifold; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"m_constraintCount") ) { return m_constraintCount; }
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

Dynamic B2ContactSolver_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"s_psm") ) { s_psm=inValue.Cast< ::box2D::dynamics::contacts::B2PositionSolverManifold >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"m_step") ) { m_step=inValue.Cast< ::box2D::dynamics::B2TimeStep >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"staticFix") ) { staticFix=inValue.Cast< int >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"m_allocator") ) { m_allocator=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"m_constraints") ) { m_constraints=inValue.Cast< Array< ::box2D::dynamics::contacts::B2ContactConstraint > >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"s_worldManifold") ) { s_worldManifold=inValue.Cast< ::box2D::collision::B2WorldManifold >(); return inValue; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"m_constraintCount") ) { m_constraintCount=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void B2ContactSolver_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("m_step"));
	outFields->push(HX_CSTRING("m_allocator"));
	outFields->push(HX_CSTRING("m_constraints"));
	outFields->push(HX_CSTRING("m_constraintCount"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("staticFix"),
	HX_CSTRING("s_worldManifold"),
	HX_CSTRING("s_psm"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("initialize"),
	HX_CSTRING("initVelocityConstraints"),
	HX_CSTRING("solveVelocityConstraints"),
	HX_CSTRING("finalizeVelocityConstraints"),
	HX_CSTRING("solvePositionConstraints"),
	HX_CSTRING("m_step"),
	HX_CSTRING("m_allocator"),
	HX_CSTRING("m_constraints"),
	HX_CSTRING("m_constraintCount"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(B2ContactSolver_obj::staticFix,"staticFix");
	HX_MARK_MEMBER_NAME(B2ContactSolver_obj::s_worldManifold,"s_worldManifold");
	HX_MARK_MEMBER_NAME(B2ContactSolver_obj::s_psm,"s_psm");
};

Class B2ContactSolver_obj::__mClass;

void B2ContactSolver_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.dynamics.contacts.B2ContactSolver"), hx::TCanCast< B2ContactSolver_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void B2ContactSolver_obj::__boot()
{
	hx::Static(staticFix) = ::box2D::common::B2Settings_obj::b2_maxManifoldPoints;
	hx::Static(s_worldManifold) = ::box2D::collision::B2WorldManifold_obj::__new();
	hx::Static(s_psm) = ::box2D::dynamics::contacts::B2PositionSolverManifold_obj::__new();
}

} // end namespace box2D
} // end namespace dynamics
} // end namespace contacts
