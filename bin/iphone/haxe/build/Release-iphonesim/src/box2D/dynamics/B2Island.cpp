#include <hxcpp.h>

#ifndef INCLUDED_box2D_common_B2Settings
#include <box2D/common/B2Settings.h>
#endif
#ifndef INCLUDED_box2D_common_math_B2Math
#include <box2D/common/math/B2Math.h>
#endif
#ifndef INCLUDED_box2D_common_math_B2Sweep
#include <box2D/common/math/B2Sweep.h>
#endif
#ifndef INCLUDED_box2D_common_math_B2Vec2
#include <box2D/common/math/B2Vec2.h>
#endif
#ifndef INCLUDED_box2D_dynamics_B2Body
#include <box2D/dynamics/B2Body.h>
#endif
#ifndef INCLUDED_box2D_dynamics_B2ContactImpulse
#include <box2D/dynamics/B2ContactImpulse.h>
#endif
#ifndef INCLUDED_box2D_dynamics_B2ContactListener
#include <box2D/dynamics/B2ContactListener.h>
#endif
#ifndef INCLUDED_box2D_dynamics_B2Island
#include <box2D/dynamics/B2Island.h>
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
#ifndef INCLUDED_box2D_dynamics_joints_B2Joint
#include <box2D/dynamics/joints/B2Joint.h>
#endif
namespace box2D{
namespace dynamics{

Void B2Island_obj::__construct()
{
{
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",119)
	this->m_bodies = Array_obj< ::box2D::dynamics::B2Body >::__new();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",120)
	this->m_contacts = Array_obj< ::box2D::dynamics::contacts::B2Contact >::__new();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",121)
	this->m_joints = Array_obj< ::box2D::dynamics::joints::B2Joint >::__new();
}
;
	return null();
}

B2Island_obj::~B2Island_obj() { }

Dynamic B2Island_obj::__CreateEmpty() { return  new B2Island_obj; }
hx::ObjectPtr< B2Island_obj > B2Island_obj::__new()
{  hx::ObjectPtr< B2Island_obj > result = new B2Island_obj();
	result->__construct();
	return result;}

Dynamic B2Island_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2Island_obj > result = new B2Island_obj();
	result->__construct();
	return result;}

Void B2Island_obj::initialize( int bodyCapacity,int contactCapacity,int jointCapacity,Dynamic allocator,::box2D::dynamics::B2ContactListener listener,::box2D::dynamics::contacts::B2ContactSolver contactSolver){
{
		HX_SOURCE_PUSH("B2Island_obj::initialize")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",132)
		int i;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",134)
		this->m_bodyCapacity = bodyCapacity;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",135)
		this->m_contactCapacity = contactCapacity;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",136)
		this->m_jointCapacity = jointCapacity;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",137)
		this->m_bodyCount = (int)0;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",138)
		this->m_contactCount = (int)0;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",139)
		this->m_jointCount = (int)0;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",141)
		this->m_allocator = allocator;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",142)
		this->m_listener = listener;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",143)
		this->m_contactSolver = contactSolver;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",145)
		{
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",145)
			int _g = this->m_bodies->length;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",145)
			while(((_g < bodyCapacity))){
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",145)
				int i1 = (_g)++;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",146)
				this->m_bodies[i1] = null();
			}
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",148)
		{
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",148)
			int _g = this->m_contacts->length;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",148)
			while(((_g < contactCapacity))){
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",148)
				int i1 = (_g)++;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",149)
				this->m_contacts[i1] = null();
			}
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",151)
		{
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",151)
			int _g = this->m_joints->length;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",151)
			while(((_g < jointCapacity))){
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",151)
				int i1 = (_g)++;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",152)
				this->m_joints[i1] = null();
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC6(B2Island_obj,initialize,(void))

Void B2Island_obj::clear( ){
{
		HX_SOURCE_PUSH("B2Island_obj::clear")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",159)
		this->m_bodyCount = (int)0;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",160)
		this->m_contactCount = (int)0;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",161)
		this->m_jointCount = (int)0;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(B2Island_obj,clear,(void))

Void B2Island_obj::solve( ::box2D::dynamics::B2TimeStep step,::box2D::common::math::B2Vec2 gravity,bool allowSleep){
{
		HX_SOURCE_PUSH("B2Island_obj::solve")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",166)
		int i;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",167)
		int j;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",168)
		::box2D::dynamics::B2Body b;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",169)
		::box2D::dynamics::joints::B2Joint joint;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",172)
		{
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",172)
			int _g1 = (int)0;
			int _g = this->m_bodyCount;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",172)
			while(((_g1 < _g))){
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",172)
				int i1 = (_g1)++;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",174)
				b = this->m_bodies->__get(i1);
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",176)
				if (((b->getType() != ::box2D::dynamics::B2Body_obj::b2_dynamicBody))){
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",177)
					continue;
				}
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",181)
				hx::AddEq(b->m_linearVelocity->x,(step->dt * ((gravity->x + (b->m_invMass * b->m_force->x)))));
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",182)
				hx::AddEq(b->m_linearVelocity->y,(step->dt * ((gravity->y + (b->m_invMass * b->m_force->y)))));
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",183)
				hx::AddEq(b->m_angularVelocity,((step->dt * b->m_invI) * b->m_torque));
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",192)
				b->m_linearVelocity->multiply(::box2D::common::math::B2Math_obj::clamp((1.0 - (step->dt * b->m_linearDamping)),0.0,1.0));
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",193)
				hx::MultEq(b->m_angularVelocity,::box2D::common::math::B2Math_obj::clamp((1.0 - (step->dt * b->m_angularDamping)),0.0,1.0));
			}
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",196)
		this->m_contactSolver->initialize(step,this->m_contacts,this->m_contactCount,this->m_allocator);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",197)
		::box2D::dynamics::contacts::B2ContactSolver contactSolver = this->m_contactSolver;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",200)
		contactSolver->initVelocityConstraints(step);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",202)
		{
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",202)
			int _g1 = (int)0;
			int _g = this->m_jointCount;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",202)
			while(((_g1 < _g))){
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",202)
				int i1 = (_g1)++;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",204)
				joint = this->m_joints->__get(i1);
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",205)
				joint->initVelocityConstraints(step);
			}
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",209)
		{
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",209)
			int _g1 = (int)0;
			int _g = step->velocityIterations;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",209)
			while(((_g1 < _g))){
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",209)
				int i1 = (_g1)++;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",211)
				{
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",211)
					int _g3 = (int)0;
					int _g2 = this->m_jointCount;
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",211)
					while(((_g3 < _g2))){
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",211)
						int j1 = (_g3)++;
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",213)
						joint = this->m_joints->__get(j1);
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",214)
						joint->solveVelocityConstraints(step);
					}
				}
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",217)
				contactSolver->solveVelocityConstraints();
			}
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",221)
		{
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",221)
			int _g1 = (int)0;
			int _g = this->m_jointCount;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",221)
			while(((_g1 < _g))){
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",221)
				int i1 = (_g1)++;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",223)
				joint = this->m_joints->__get(i1);
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",224)
				joint->finalizeVelocityConstraints();
			}
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",226)
		contactSolver->finalizeVelocityConstraints();
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",229)
		{
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",229)
			int _g1 = (int)0;
			int _g = this->m_bodyCount;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",229)
			while(((_g1 < _g))){
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",229)
				int i1 = (_g1)++;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",231)
				b = this->m_bodies->__get(i1);
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",233)
				if (((b->getType() == ::box2D::dynamics::B2Body_obj::b2_staticBody))){
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",234)
					continue;
				}
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",238)
				double translationX = (step->dt * b->m_linearVelocity->x);
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",239)
				double translationY = (step->dt * b->m_linearVelocity->y);
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",241)
				if (((((translationX * translationX) + (translationY * translationY)) > ::box2D::common::B2Settings_obj::b2_maxTranslationSquared))){
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",243)
					b->m_linearVelocity->normalize();
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",244)
					hx::MultEq(b->m_linearVelocity->x,(::box2D::common::B2Settings_obj::b2_maxTranslation * step->inv_dt));
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",245)
					hx::MultEq(b->m_linearVelocity->y,(::box2D::common::B2Settings_obj::b2_maxTranslation * step->inv_dt));
				}
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",247)
				double rotation = (step->dt * b->m_angularVelocity);
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",248)
				if ((((rotation * rotation) > ::box2D::common::B2Settings_obj::b2_maxRotationSquared))){
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",249)
					if (((b->m_angularVelocity < 0.0))){
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",251)
						b->m_angularVelocity = (-(::box2D::common::B2Settings_obj::b2_maxRotation) * step->inv_dt);
					}
					else{
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",255)
						b->m_angularVelocity = (::box2D::common::B2Settings_obj::b2_maxRotation * step->inv_dt);
					}
				}
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",261)
				b->m_sweep->c0->setV(b->m_sweep->c);
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",262)
				b->m_sweep->a0 = b->m_sweep->a;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",266)
				hx::AddEq(b->m_sweep->c->x,(step->dt * b->m_linearVelocity->x));
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",267)
				hx::AddEq(b->m_sweep->c->y,(step->dt * b->m_linearVelocity->y));
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",268)
				hx::AddEq(b->m_sweep->a,(step->dt * b->m_angularVelocity));
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",271)
				b->synchronizeTransform();
			}
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",277)
		{
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",277)
			int _g1 = (int)0;
			int _g = step->positionIterations;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",277)
			while(((_g1 < _g))){
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",277)
				int i1 = (_g1)++;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",279)
				bool contactsOkay = contactSolver->solvePositionConstraints(::box2D::common::B2Settings_obj::b2_contactBaumgarte);
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",281)
				bool jointsOkay = true;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",282)
				{
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",282)
					int _g3 = (int)0;
					int _g2 = this->m_jointCount;
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",282)
					while(((_g3 < _g2))){
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",282)
						int j1 = (_g3)++;
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",284)
						joint = this->m_joints->__get(j1);
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",285)
						bool jointOkay = joint->solvePositionConstraints(::box2D::common::B2Settings_obj::b2_contactBaumgarte);
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",286)
						jointsOkay = (bool(jointsOkay) && bool(jointOkay));
					}
				}
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",289)
				if (((bool(contactsOkay) && bool(jointsOkay)))){
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",290)
					break;
				}
			}
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",295)
		this->report(contactSolver->m_constraints);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",297)
		if ((allowSleep)){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",299)
			double minSleepTime = 1.7976931348623158e+308;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",301)
			double linTolSqr = (::box2D::common::B2Settings_obj::b2_linearSleepTolerance * ::box2D::common::B2Settings_obj::b2_linearSleepTolerance);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",302)
			double angTolSqr = (::box2D::common::B2Settings_obj::b2_angularSleepTolerance * ::box2D::common::B2Settings_obj::b2_angularSleepTolerance);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",304)
			{
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",304)
				int _g1 = (int)0;
				int _g = this->m_bodyCount;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",304)
				while(((_g1 < _g))){
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",304)
					int i1 = (_g1)++;
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",306)
					b = this->m_bodies->__get(i1);
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",307)
					if (((b->getType() == ::box2D::dynamics::B2Body_obj::b2_staticBody))){
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",308)
						continue;
					}
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",312)
					if (((((int(b->m_flags) & int(::box2D::dynamics::B2Body_obj::e_allowSleepFlag))) == (int)0))){
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",314)
						b->m_sleepTime = 0.0;
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",315)
						minSleepTime = 0.0;
					}
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",318)
					if (((bool((bool((((int(b->m_flags) & int(::box2D::dynamics::B2Body_obj::e_allowSleepFlag))) == (int)0)) || bool(((b->m_angularVelocity * b->m_angularVelocity) > angTolSqr)))) || bool((::box2D::common::math::B2Math_obj::dot(b->m_linearVelocity,b->m_linearVelocity) > linTolSqr))))){
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",322)
						b->m_sleepTime = 0.0;
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",323)
						minSleepTime = 0.0;
					}
					else{
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",327)
						hx::AddEq(b->m_sleepTime,step->dt);
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",328)
						minSleepTime = ::box2D::common::math::B2Math_obj::min(minSleepTime,b->m_sleepTime);
					}
				}
			}
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",332)
			if (((minSleepTime >= ::box2D::common::B2Settings_obj::b2_timeToSleep))){
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",334)
				int _g1 = (int)0;
				int _g = this->m_bodyCount;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",334)
				while(((_g1 < _g))){
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",334)
					int i1 = (_g1)++;
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",336)
					b = this->m_bodies->__get(i1);
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",337)
					b->setAwake(false);
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(B2Island_obj,solve,(void))

Void B2Island_obj::solveTOI( ::box2D::dynamics::B2TimeStep subStep){
{
		HX_SOURCE_PUSH("B2Island_obj::solveTOI")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",346)
		int i;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",347)
		int j;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",348)
		this->m_contactSolver->initialize(subStep,this->m_contacts,this->m_contactCount,this->m_allocator);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",349)
		::box2D::dynamics::contacts::B2ContactSolver contactSolver = this->m_contactSolver;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",356)
		{
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",356)
			int _g1 = (int)0;
			int _g = this->m_jointCount;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",356)
			while(((_g1 < _g))){
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",356)
				int i1 = (_g1)++;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",358)
				this->m_joints->__get(i1)->initVelocityConstraints(subStep);
			}
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",363)
		{
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",363)
			int _g1 = (int)0;
			int _g = subStep->velocityIterations;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",363)
			while(((_g1 < _g))){
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",363)
				int i1 = (_g1)++;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",365)
				contactSolver->solveVelocityConstraints();
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",366)
				{
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",366)
					int _g3 = (int)0;
					int _g2 = this->m_jointCount;
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",366)
					while(((_g3 < _g2))){
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",366)
						int j1 = (_g3)++;
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",368)
						this->m_joints->__get(j1)->solveVelocityConstraints(subStep);
					}
				}
			}
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",376)
		{
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",376)
			int _g1 = (int)0;
			int _g = this->m_bodyCount;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",376)
			while(((_g1 < _g))){
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",376)
				int i1 = (_g1)++;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",378)
				::box2D::dynamics::B2Body b = this->m_bodies->__get(i1);
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",380)
				if (((b->getType() == ::box2D::dynamics::B2Body_obj::b2_staticBody))){
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",381)
					continue;
				}
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",385)
				double translationX = (subStep->dt * b->m_linearVelocity->x);
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",386)
				double translationY = (subStep->dt * b->m_linearVelocity->y);
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",388)
				if (((((translationX * translationX) + (translationY * translationY)) > ::box2D::common::B2Settings_obj::b2_maxTranslationSquared))){
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",390)
					b->m_linearVelocity->normalize();
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",391)
					hx::MultEq(b->m_linearVelocity->x,(::box2D::common::B2Settings_obj::b2_maxTranslation * subStep->inv_dt));
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",392)
					hx::MultEq(b->m_linearVelocity->y,(::box2D::common::B2Settings_obj::b2_maxTranslation * subStep->inv_dt));
				}
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",395)
				double rotation = (subStep->dt * b->m_angularVelocity);
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",396)
				if ((((rotation * rotation) > ::box2D::common::B2Settings_obj::b2_maxRotationSquared))){
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",397)
					if (((b->m_angularVelocity < 0.0))){
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",399)
						b->m_angularVelocity = (-(::box2D::common::B2Settings_obj::b2_maxRotation) * subStep->inv_dt);
					}
					else{
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",403)
						b->m_angularVelocity = (::box2D::common::B2Settings_obj::b2_maxRotation * subStep->inv_dt);
					}
				}
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",409)
				b->m_sweep->c0->setV(b->m_sweep->c);
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",410)
				b->m_sweep->a0 = b->m_sweep->a;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",413)
				hx::AddEq(b->m_sweep->c->x,(subStep->dt * b->m_linearVelocity->x));
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",414)
				hx::AddEq(b->m_sweep->c->y,(subStep->dt * b->m_linearVelocity->y));
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",415)
				hx::AddEq(b->m_sweep->a,(subStep->dt * b->m_angularVelocity));
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",418)
				b->synchronizeTransform();
			}
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",424)
		double k_toiBaumgarte = 0.75;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",425)
		{
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",425)
			int _g1 = (int)0;
			int _g = subStep->positionIterations;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",425)
			while(((_g1 < _g))){
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",425)
				int i1 = (_g1)++;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",427)
				bool contactsOkay = contactSolver->solvePositionConstraints(k_toiBaumgarte);
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",428)
				bool jointsOkay = true;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",429)
				{
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",429)
					int _g3 = (int)0;
					int _g2 = this->m_jointCount;
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",429)
					while(((_g3 < _g2))){
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",429)
						int j1 = (_g3)++;
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",431)
						bool jointOkay = this->m_joints->__get(j1)->solvePositionConstraints(::box2D::common::B2Settings_obj::b2_contactBaumgarte);
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",432)
						jointsOkay = (bool(jointsOkay) && bool(jointOkay));
					}
				}
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",435)
				if (((bool(contactsOkay) && bool(jointsOkay)))){
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",436)
					break;
				}
			}
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",440)
		this->report(contactSolver->m_constraints);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2Island_obj,solveTOI,(void))

Void B2Island_obj::report( Array< ::box2D::dynamics::contacts::B2ContactConstraint > constraints){
{
		HX_SOURCE_PUSH("B2Island_obj::report")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",446)
		if (((this->m_listener == null()))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",447)
			return null();
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",451)
		{
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",451)
			int _g1 = (int)0;
			int _g = this->m_contactCount;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",451)
			while(((_g1 < _g))){
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",451)
				int i = (_g1)++;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",453)
				::box2D::dynamics::contacts::B2Contact c = this->m_contacts->__get(i);
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",454)
				::box2D::dynamics::contacts::B2ContactConstraint cc = constraints->__get(i);
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",456)
				{
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",456)
					int _g3 = (int)0;
					int _g2 = cc->pointCount;
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",456)
					while(((_g3 < _g2))){
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",456)
						int j = (_g3)++;
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",458)
						::box2D::dynamics::B2Island_obj::s_impulse->normalImpulses[j] = cc->points->__get(j)->normalImpulse;
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",459)
						::box2D::dynamics::B2Island_obj::s_impulse->tangentImpulses[j] = cc->points->__get(j)->tangentImpulse;
					}
				}
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",461)
				this->m_listener->postSolve(c,::box2D::dynamics::B2Island_obj::s_impulse);
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2Island_obj,report,(void))

Void B2Island_obj::addBody( ::box2D::dynamics::B2Body body){
{
		HX_SOURCE_PUSH("B2Island_obj::addBody")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",469)
		body->m_islandIndex = this->m_bodyCount;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",470)
		this->m_bodies[(this->m_bodyCount)++] = body;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2Island_obj,addBody,(void))

Void B2Island_obj::addContact( ::box2D::dynamics::contacts::B2Contact contact){
{
		HX_SOURCE_PUSH("B2Island_obj::addContact")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",474)
		this->m_contacts[(this->m_contactCount)++] = contact;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2Island_obj,addContact,(void))

Void B2Island_obj::addJoint( ::box2D::dynamics::joints::B2Joint joint){
{
		HX_SOURCE_PUSH("B2Island_obj::addJoint")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Island.hx",480)
		this->m_joints[(this->m_jointCount)++] = joint;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2Island_obj,addJoint,(void))

::box2D::dynamics::B2ContactImpulse B2Island_obj::s_impulse;


B2Island_obj::B2Island_obj()
{
}

void B2Island_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(B2Island);
	HX_MARK_MEMBER_NAME(m_allocator,"m_allocator");
	HX_MARK_MEMBER_NAME(m_listener,"m_listener");
	HX_MARK_MEMBER_NAME(m_contactSolver,"m_contactSolver");
	HX_MARK_MEMBER_NAME(m_bodies,"m_bodies");
	HX_MARK_MEMBER_NAME(m_contacts,"m_contacts");
	HX_MARK_MEMBER_NAME(m_joints,"m_joints");
	HX_MARK_MEMBER_NAME(m_bodyCount,"m_bodyCount");
	HX_MARK_MEMBER_NAME(m_jointCount,"m_jointCount");
	HX_MARK_MEMBER_NAME(m_contactCount,"m_contactCount");
	HX_MARK_MEMBER_NAME(m_bodyCapacity,"m_bodyCapacity");
	HX_MARK_MEMBER_NAME(m_contactCapacity,"m_contactCapacity");
	HX_MARK_MEMBER_NAME(m_jointCapacity,"m_jointCapacity");
	HX_MARK_END_CLASS();
}

Dynamic B2Island_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"clear") ) { return clear_dyn(); }
		if (HX_FIELD_EQ(inName,"solve") ) { return solve_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"report") ) { return report_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"addBody") ) { return addBody_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"solveTOI") ) { return solveTOI_dyn(); }
		if (HX_FIELD_EQ(inName,"addJoint") ) { return addJoint_dyn(); }
		if (HX_FIELD_EQ(inName,"m_bodies") ) { return m_bodies; }
		if (HX_FIELD_EQ(inName,"m_joints") ) { return m_joints; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"s_impulse") ) { return s_impulse; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"initialize") ) { return initialize_dyn(); }
		if (HX_FIELD_EQ(inName,"addContact") ) { return addContact_dyn(); }
		if (HX_FIELD_EQ(inName,"m_listener") ) { return m_listener; }
		if (HX_FIELD_EQ(inName,"m_contacts") ) { return m_contacts; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"m_allocator") ) { return m_allocator; }
		if (HX_FIELD_EQ(inName,"m_bodyCount") ) { return m_bodyCount; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"m_jointCount") ) { return m_jointCount; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"m_contactCount") ) { return m_contactCount; }
		if (HX_FIELD_EQ(inName,"m_bodyCapacity") ) { return m_bodyCapacity; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"m_contactSolver") ) { return m_contactSolver; }
		if (HX_FIELD_EQ(inName,"m_jointCapacity") ) { return m_jointCapacity; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"m_contactCapacity") ) { return m_contactCapacity; }
	}
	return super::__Field(inName);
}

Dynamic B2Island_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"m_bodies") ) { m_bodies=inValue.Cast< Array< ::box2D::dynamics::B2Body > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_joints") ) { m_joints=inValue.Cast< Array< ::box2D::dynamics::joints::B2Joint > >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"s_impulse") ) { s_impulse=inValue.Cast< ::box2D::dynamics::B2ContactImpulse >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"m_listener") ) { m_listener=inValue.Cast< ::box2D::dynamics::B2ContactListener >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_contacts") ) { m_contacts=inValue.Cast< Array< ::box2D::dynamics::contacts::B2Contact > >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"m_allocator") ) { m_allocator=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_bodyCount") ) { m_bodyCount=inValue.Cast< int >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"m_jointCount") ) { m_jointCount=inValue.Cast< int >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"m_contactCount") ) { m_contactCount=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_bodyCapacity") ) { m_bodyCapacity=inValue.Cast< int >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"m_contactSolver") ) { m_contactSolver=inValue.Cast< ::box2D::dynamics::contacts::B2ContactSolver >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_jointCapacity") ) { m_jointCapacity=inValue.Cast< int >(); return inValue; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"m_contactCapacity") ) { m_contactCapacity=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void B2Island_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("m_allocator"));
	outFields->push(HX_CSTRING("m_listener"));
	outFields->push(HX_CSTRING("m_contactSolver"));
	outFields->push(HX_CSTRING("m_bodies"));
	outFields->push(HX_CSTRING("m_contacts"));
	outFields->push(HX_CSTRING("m_joints"));
	outFields->push(HX_CSTRING("m_bodyCount"));
	outFields->push(HX_CSTRING("m_jointCount"));
	outFields->push(HX_CSTRING("m_contactCount"));
	outFields->push(HX_CSTRING("m_bodyCapacity"));
	outFields->push(HX_CSTRING("m_contactCapacity"));
	outFields->push(HX_CSTRING("m_jointCapacity"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("s_impulse"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("initialize"),
	HX_CSTRING("clear"),
	HX_CSTRING("solve"),
	HX_CSTRING("solveTOI"),
	HX_CSTRING("report"),
	HX_CSTRING("addBody"),
	HX_CSTRING("addContact"),
	HX_CSTRING("addJoint"),
	HX_CSTRING("m_allocator"),
	HX_CSTRING("m_listener"),
	HX_CSTRING("m_contactSolver"),
	HX_CSTRING("m_bodies"),
	HX_CSTRING("m_contacts"),
	HX_CSTRING("m_joints"),
	HX_CSTRING("m_bodyCount"),
	HX_CSTRING("m_jointCount"),
	HX_CSTRING("m_contactCount"),
	HX_CSTRING("m_bodyCapacity"),
	HX_CSTRING("m_contactCapacity"),
	HX_CSTRING("m_jointCapacity"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(B2Island_obj::s_impulse,"s_impulse");
};

Class B2Island_obj::__mClass;

void B2Island_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.dynamics.B2Island"), hx::TCanCast< B2Island_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void B2Island_obj::__boot()
{
	hx::Static(s_impulse) = ::box2D::dynamics::B2ContactImpulse_obj::__new();
}

} // end namespace box2D
} // end namespace dynamics
