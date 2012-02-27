#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_box2D_collision_IBroadPhase
#include <box2D/collision/IBroadPhase.h>
#endif
#ifndef INCLUDED_box2D_collision_shapes_B2EdgeShape
#include <box2D/collision/shapes/B2EdgeShape.h>
#endif
#ifndef INCLUDED_box2D_collision_shapes_B2MassData
#include <box2D/collision/shapes/B2MassData.h>
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
#ifndef INCLUDED_box2D_dynamics_B2BodyDef
#include <box2D/dynamics/B2BodyDef.h>
#endif
#ifndef INCLUDED_box2D_dynamics_B2ContactManager
#include <box2D/dynamics/B2ContactManager.h>
#endif
#ifndef INCLUDED_box2D_dynamics_B2Fixture
#include <box2D/dynamics/B2Fixture.h>
#endif
#ifndef INCLUDED_box2D_dynamics_B2FixtureDef
#include <box2D/dynamics/B2FixtureDef.h>
#endif
#ifndef INCLUDED_box2D_dynamics_B2World
#include <box2D/dynamics/B2World.h>
#endif
#ifndef INCLUDED_box2D_dynamics_contacts_B2Contact
#include <box2D/dynamics/contacts/B2Contact.h>
#endif
#ifndef INCLUDED_box2D_dynamics_contacts_B2ContactEdge
#include <box2D/dynamics/contacts/B2ContactEdge.h>
#endif
#ifndef INCLUDED_box2D_dynamics_controllers_B2ControllerEdge
#include <box2D/dynamics/controllers/B2ControllerEdge.h>
#endif
#ifndef INCLUDED_box2D_dynamics_joints_B2Joint
#include <box2D/dynamics/joints/B2Joint.h>
#endif
#ifndef INCLUDED_box2D_dynamics_joints_B2JointEdge
#include <box2D/dynamics/joints/B2JointEdge.h>
#endif
namespace box2D{
namespace dynamics{

Void B2Body_obj::__construct(::box2D::dynamics::B2BodyDef bd,::box2D::dynamics::B2World world)
{
{
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",1160)
	this->m_xf = ::box2D::common::math::B2Transform_obj::__new(null(),null());
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",1161)
	this->m_sweep = ::box2D::common::math::B2Sweep_obj::__new();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",1162)
	this->m_linearVelocity = ::box2D::common::math::B2Vec2_obj::__new(null(),null());
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",1163)
	this->m_force = ::box2D::common::math::B2Vec2_obj::__new(null(),null());
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",1175)
	this->m_flags = (int)0;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",1177)
	if ((bd->bullet)){
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",1178)
		hx::OrEq(this->m_flags,::box2D::dynamics::B2Body_obj::e_bulletFlag);
	}
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",1181)
	if ((bd->fixedRotation)){
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",1182)
		hx::OrEq(this->m_flags,::box2D::dynamics::B2Body_obj::e_fixedRotationFlag);
	}
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",1185)
	if ((bd->allowSleep)){
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",1186)
		hx::OrEq(this->m_flags,::box2D::dynamics::B2Body_obj::e_allowSleepFlag);
	}
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",1189)
	if ((bd->awake)){
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",1190)
		hx::OrEq(this->m_flags,::box2D::dynamics::B2Body_obj::e_awakeFlag);
	}
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",1193)
	if ((bd->active)){
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",1194)
		hx::OrEq(this->m_flags,::box2D::dynamics::B2Body_obj::e_activeFlag);
	}
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",1198)
	this->m_world = world;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",1200)
	this->m_xf->position->setV(bd->position);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",1201)
	this->m_xf->R->set(bd->angle);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",1203)
	this->m_sweep->localCenter->setZero();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",1204)
	this->m_sweep->t0 = 1.0;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",1205)
	this->m_sweep->a0 = this->m_sweep->a = bd->angle;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",1209)
	::box2D::common::math::B2Mat22 tMat = this->m_xf->R;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",1210)
	::box2D::common::math::B2Vec2 tVec = this->m_sweep->localCenter;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",1212)
	this->m_sweep->c->x = ((tMat->col1->x * tVec->x) + (tMat->col2->x * tVec->y));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",1214)
	this->m_sweep->c->y = ((tMat->col1->y * tVec->x) + (tMat->col2->y * tVec->y));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",1216)
	hx::AddEq(this->m_sweep->c->x,this->m_xf->position->x);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",1217)
	hx::AddEq(this->m_sweep->c->y,this->m_xf->position->y);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",1219)
	this->m_sweep->c0->setV(this->m_sweep->c);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",1221)
	this->m_jointList = null();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",1222)
	this->m_controllerList = null();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",1223)
	this->m_contactList = null();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",1224)
	this->m_controllerCount = (int)0;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",1225)
	this->m_prev = null();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",1226)
	this->m_next = null();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",1228)
	this->m_linearVelocity->setV(bd->linearVelocity);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",1229)
	this->m_angularVelocity = bd->angularVelocity;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",1231)
	this->m_linearDamping = bd->linearDamping;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",1232)
	this->m_angularDamping = bd->angularDamping;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",1234)
	this->m_force->set(0.0,0.0);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",1235)
	this->m_torque = 0.0;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",1237)
	this->m_sleepTime = 0.0;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",1239)
	this->m_type = bd->type;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",1241)
	if (((this->m_type == ::box2D::dynamics::B2Body_obj::b2_dynamicBody))){
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",1243)
		this->m_mass = 1.0;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",1244)
		this->m_invMass = 1.0;
	}
	else{
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",1248)
		this->m_mass = 0.0;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",1249)
		this->m_invMass = 0.0;
	}
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",1252)
	this->m_I = 0.0;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",1253)
	this->m_invI = 0.0;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",1255)
	this->m_inertiaScale = bd->inertiaScale;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",1257)
	this->m_userData = bd->userData;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",1259)
	this->m_fixtureList = null();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",1260)
	this->m_fixtureCount = (int)0;
}
;
	return null();
}

B2Body_obj::~B2Body_obj() { }

Dynamic B2Body_obj::__CreateEmpty() { return  new B2Body_obj; }
hx::ObjectPtr< B2Body_obj > B2Body_obj::__new(::box2D::dynamics::B2BodyDef bd,::box2D::dynamics::B2World world)
{  hx::ObjectPtr< B2Body_obj > result = new B2Body_obj();
	result->__construct(bd,world);
	return result;}

Dynamic B2Body_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2Body_obj > result = new B2Body_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

double B2Body_obj::connectEdges( ::box2D::collision::shapes::B2EdgeShape s1,::box2D::collision::shapes::B2EdgeShape s2,double angle1){
	HX_SOURCE_PUSH("B2Body_obj::connectEdges")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",47)
	double angle2 = ::Math_obj::atan2(s2->getDirectionVector()->y,s2->getDirectionVector()->x);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",48)
	double coreOffset = ::Math_obj::tan((((angle2 - angle1)) * 0.5));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",49)
	::box2D::common::math::B2Vec2 core = ::box2D::common::math::B2Math_obj::mulFV(coreOffset,s2->getDirectionVector());
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",50)
	core = ::box2D::common::math::B2Math_obj::subtractVV(core,s2->getNormalVector());
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",51)
	core = ::box2D::common::math::B2Math_obj::mulFV(::box2D::common::B2Settings_obj::b2_toiSlop,core);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",52)
	core = ::box2D::common::math::B2Math_obj::addVV(core,s2->getVertex1());
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",53)
	::box2D::common::math::B2Vec2 cornerDir = ::box2D::common::math::B2Math_obj::addVV(s1->getDirectionVector(),s2->getDirectionVector());
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",54)
	cornerDir->normalize();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",55)
	bool convex = (::box2D::common::math::B2Math_obj::dot(s1->getDirectionVector(),s2->getNormalVector()) > 0.0);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",56)
	s1->setNextEdge(s2,core,cornerDir,convex);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",57)
	s2->setPrevEdge(s1,core,cornerDir,convex);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",58)
	return angle2;
}


HX_DEFINE_DYNAMIC_FUNC3(B2Body_obj,connectEdges,return )

::box2D::dynamics::B2Fixture B2Body_obj::createFixture( ::box2D::dynamics::B2FixtureDef def){
	HX_SOURCE_PUSH("B2Body_obj::createFixture")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",72)
	if (((this->m_world->isLocked() == true))){
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",73)
		return null();
	}
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",124)
	::box2D::dynamics::B2Fixture fixture = ::box2D::dynamics::B2Fixture_obj::__new();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",125)
	fixture->create(hx::ObjectPtr<OBJ_>(this),this->m_xf,def);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",128)
	if (((((int(this->m_flags) & int(::box2D::dynamics::B2Body_obj::e_activeFlag))) != (int)0))){
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",130)
		::box2D::collision::IBroadPhase broadPhase = this->m_world->m_contactManager->m_broadPhase;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",131)
		fixture->createProxy(broadPhase,this->m_xf);
	}
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",134)
	fixture->m_next = this->m_fixtureList;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",135)
	this->m_fixtureList = fixture;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",136)
	++(this->m_fixtureCount);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",138)
	fixture->m_body = hx::ObjectPtr<OBJ_>(this);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",141)
	if (((fixture->m_density > 0.0))){
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",142)
		this->resetMassData();
	}
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",148)
	hx::OrEq(this->m_world->m_flags,::box2D::dynamics::B2World_obj::e_newFixture);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",150)
	return fixture;
}


HX_DEFINE_DYNAMIC_FUNC1(B2Body_obj,createFixture,return )

::box2D::dynamics::B2Fixture B2Body_obj::createFixture2( ::box2D::collision::shapes::B2Shape shape,Dynamic __o_density){
double density = __o_density.Default(0.0);
	HX_SOURCE_PUSH("B2Body_obj::createFixture2");
{
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",164)
		::box2D::dynamics::B2FixtureDef def = ::box2D::dynamics::B2FixtureDef_obj::__new();
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",165)
		def->shape = shape;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",166)
		def->density = density;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",168)
		return this->createFixture(def);
	}
}


HX_DEFINE_DYNAMIC_FUNC2(B2Body_obj,createFixture2,return )

Void B2Body_obj::DestroyFixture( ::box2D::dynamics::B2Fixture fixture){
{
		HX_SOURCE_PUSH("B2Body_obj::DestroyFixture")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",182)
		if (((this->m_world->isLocked() == true))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",183)
			return null();
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",189)
		::box2D::dynamics::B2Fixture node = this->m_fixtureList;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",190)
		::box2D::dynamics::B2Fixture ppF = null();
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",191)
		bool found = false;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",192)
		while(((node != null()))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",194)
			if (((node == fixture))){
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",196)
				if (((ppF != null()))){
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",197)
					ppF->m_next = fixture->m_next;
				}
				else{
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",199)
					this->m_fixtureList = fixture->m_next;
				}
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",201)
				found = true;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",202)
				break;
			}
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",205)
			ppF = node;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",206)
			node = node->m_next;
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",213)
		::box2D::dynamics::contacts::B2ContactEdge edge = this->m_contactList;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",214)
		while(((edge != null()))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",216)
			::box2D::dynamics::contacts::B2Contact c = edge->contact;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",217)
			edge = edge->next;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",219)
			::box2D::dynamics::B2Fixture fixtureA = c->getFixtureA();
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",220)
			::box2D::dynamics::B2Fixture fixtureB = c->getFixtureB();
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",221)
			if (((bool((fixture == fixtureA)) || bool((fixture == fixtureB))))){
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",222)
				this->m_world->m_contactManager->destroy(c);
			}
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",230)
		if (((((int(this->m_flags) & int(::box2D::dynamics::B2Body_obj::e_activeFlag))) != (int)0))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",232)
			::box2D::collision::IBroadPhase broadPhase = this->m_world->m_contactManager->m_broadPhase;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",233)
			fixture->destroyProxy(broadPhase);
		}
		else{
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",240)
		fixture->destroy();
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",241)
		fixture->m_body = null();
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",242)
		fixture->m_next = null();
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",244)
		--(this->m_fixtureCount);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",247)
		this->resetMassData();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2Body_obj,DestroyFixture,(void))

Void B2Body_obj::setPositionAndAngle( ::box2D::common::math::B2Vec2 position,double angle){
{
		HX_SOURCE_PUSH("B2Body_obj::setPositionAndAngle")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",259)
		::box2D::dynamics::B2Fixture f;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",262)
		if (((this->m_world->isLocked() == true))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",263)
			return null();
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",267)
		this->m_xf->R->set(angle);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",268)
		this->m_xf->position->setV(position);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",272)
		::box2D::common::math::B2Mat22 tMat = this->m_xf->R;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",273)
		::box2D::common::math::B2Vec2 tVec = this->m_sweep->localCenter;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",275)
		this->m_sweep->c->x = ((tMat->col1->x * tVec->x) + (tMat->col2->x * tVec->y));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",277)
		this->m_sweep->c->y = ((tMat->col1->y * tVec->x) + (tMat->col2->y * tVec->y));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",279)
		hx::AddEq(this->m_sweep->c->x,this->m_xf->position->x);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",280)
		hx::AddEq(this->m_sweep->c->y,this->m_xf->position->y);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",282)
		this->m_sweep->c0->setV(this->m_sweep->c);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",284)
		this->m_sweep->a0 = this->m_sweep->a = angle;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",286)
		::box2D::collision::IBroadPhase broadPhase = this->m_world->m_contactManager->m_broadPhase;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",287)
		f = this->m_fixtureList;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",288)
		while(((f != null()))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",290)
			f->synchronize(broadPhase,this->m_xf,this->m_xf);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",291)
			f = f->m_next;
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",293)
		this->m_world->m_contactManager->findNewContacts();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(B2Body_obj,setPositionAndAngle,(void))

Void B2Body_obj::setTransform( ::box2D::common::math::B2Transform xf){
{
		HX_SOURCE_PUSH("B2Body_obj::setTransform")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",304)
		this->setPositionAndAngle(xf->position,xf->getAngle());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2Body_obj,setTransform,(void))

::box2D::common::math::B2Transform B2Body_obj::getTransform( ){
	HX_SOURCE_PUSH("B2Body_obj::getTransform")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",312)
	return this->m_xf;
}


HX_DEFINE_DYNAMIC_FUNC0(B2Body_obj,getTransform,return )

::box2D::common::math::B2Vec2 B2Body_obj::getPosition( ){
	HX_SOURCE_PUSH("B2Body_obj::getPosition")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",320)
	return this->m_xf->position;
}


HX_DEFINE_DYNAMIC_FUNC0(B2Body_obj,getPosition,return )

Void B2Body_obj::setPosition( ::box2D::common::math::B2Vec2 position){
{
		HX_SOURCE_PUSH("B2Body_obj::setPosition")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",329)
		this->setPositionAndAngle(position,this->getAngle());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2Body_obj,setPosition,(void))

double B2Body_obj::getAngle( ){
	HX_SOURCE_PUSH("B2Body_obj::getAngle")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",337)
	return this->m_sweep->a;
}


HX_DEFINE_DYNAMIC_FUNC0(B2Body_obj,getAngle,return )

Void B2Body_obj::setAngle( double angle){
{
		HX_SOURCE_PUSH("B2Body_obj::setAngle")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",346)
		this->setPositionAndAngle(this->getPosition(),angle);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2Body_obj,setAngle,(void))

::box2D::common::math::B2Vec2 B2Body_obj::getWorldCenter( ){
	HX_SOURCE_PUSH("B2Body_obj::getWorldCenter")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",354)
	return this->m_sweep->c;
}


HX_DEFINE_DYNAMIC_FUNC0(B2Body_obj,getWorldCenter,return )

::box2D::common::math::B2Vec2 B2Body_obj::getLocalCenter( ){
	HX_SOURCE_PUSH("B2Body_obj::getLocalCenter")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",361)
	return this->m_sweep->localCenter;
}


HX_DEFINE_DYNAMIC_FUNC0(B2Body_obj,getLocalCenter,return )

Void B2Body_obj::setLinearVelocity( ::box2D::common::math::B2Vec2 v){
{
		HX_SOURCE_PUSH("B2Body_obj::setLinearVelocity")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",370)
		if (((this->m_type == ::box2D::dynamics::B2Body_obj::b2_staticBody))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",371)
			return null();
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",374)
		this->m_linearVelocity->setV(v);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2Body_obj,setLinearVelocity,(void))

::box2D::common::math::B2Vec2 B2Body_obj::getLinearVelocity( ){
	HX_SOURCE_PUSH("B2Body_obj::getLinearVelocity")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",381)
	return this->m_linearVelocity;
}


HX_DEFINE_DYNAMIC_FUNC0(B2Body_obj,getLinearVelocity,return )

Void B2Body_obj::setAngularVelocity( double omega){
{
		HX_SOURCE_PUSH("B2Body_obj::setAngularVelocity")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",390)
		if (((this->m_type == ::box2D::dynamics::B2Body_obj::b2_staticBody))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",391)
			return null();
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",394)
		this->m_angularVelocity = omega;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2Body_obj,setAngularVelocity,(void))

double B2Body_obj::getAngularVelocity( ){
	HX_SOURCE_PUSH("B2Body_obj::getAngularVelocity")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",401)
	return this->m_angularVelocity;
}


HX_DEFINE_DYNAMIC_FUNC0(B2Body_obj,getAngularVelocity,return )

::box2D::dynamics::B2BodyDef B2Body_obj::getDefinition( ){
	HX_SOURCE_PUSH("B2Body_obj::getDefinition")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",411)
	::box2D::dynamics::B2BodyDef bd = ::box2D::dynamics::B2BodyDef_obj::__new();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",412)
	bd->type = this->getType();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",413)
	bd->allowSleep = (((int(this->m_flags) & int(::box2D::dynamics::B2Body_obj::e_allowSleepFlag))) == ::box2D::dynamics::B2Body_obj::e_allowSleepFlag);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",414)
	bd->angle = this->getAngle();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",415)
	bd->angularDamping = this->m_angularDamping;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",416)
	bd->angularVelocity = this->m_angularVelocity;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",417)
	bd->fixedRotation = (((int(this->m_flags) & int(::box2D::dynamics::B2Body_obj::e_fixedRotationFlag))) == ::box2D::dynamics::B2Body_obj::e_fixedRotationFlag);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",418)
	bd->bullet = (((int(this->m_flags) & int(::box2D::dynamics::B2Body_obj::e_bulletFlag))) == ::box2D::dynamics::B2Body_obj::e_bulletFlag);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",419)
	bd->awake = (((int(this->m_flags) & int(::box2D::dynamics::B2Body_obj::e_awakeFlag))) == ::box2D::dynamics::B2Body_obj::e_awakeFlag);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",420)
	bd->linearDamping = this->m_linearDamping;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",421)
	bd->linearVelocity->setV(this->getLinearVelocity());
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",422)
	bd->position = this->getPosition();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",423)
	bd->userData = this->getUserData();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",424)
	return bd;
}


HX_DEFINE_DYNAMIC_FUNC0(B2Body_obj,getDefinition,return )

Void B2Body_obj::applyForce( ::box2D::common::math::B2Vec2 force,::box2D::common::math::B2Vec2 point){
{
		HX_SOURCE_PUSH("B2Body_obj::applyForce")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",435)
		if (((this->m_type != ::box2D::dynamics::B2Body_obj::b2_dynamicBody))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",436)
			return null();
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",440)
		if (((this->isAwake() == false))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",441)
			this->setAwake(true);
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",446)
		hx::AddEq(this->m_force->x,force->x);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",447)
		hx::AddEq(this->m_force->y,force->y);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",449)
		hx::AddEq(this->m_torque,((((point->x - this->m_sweep->c->x)) * force->y) - (((point->y - this->m_sweep->c->y)) * force->x)));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(B2Body_obj,applyForce,(void))

Void B2Body_obj::applyTorque( double torque){
{
		HX_SOURCE_PUSH("B2Body_obj::applyTorque")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",459)
		if (((this->m_type != ::box2D::dynamics::B2Body_obj::b2_dynamicBody))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",460)
			return null();
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",464)
		if (((this->isAwake() == false))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",465)
			this->setAwake(true);
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",468)
		hx::AddEq(this->m_torque,torque);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2Body_obj,applyTorque,(void))

Void B2Body_obj::applyImpulse( ::box2D::common::math::B2Vec2 impulse,::box2D::common::math::B2Vec2 point){
{
		HX_SOURCE_PUSH("B2Body_obj::applyImpulse")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",479)
		if (((this->m_type != ::box2D::dynamics::B2Body_obj::b2_dynamicBody))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",480)
			return null();
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",484)
		if (((this->isAwake() == false))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",485)
			this->setAwake(true);
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",489)
		hx::AddEq(this->m_linearVelocity->x,(this->m_invMass * impulse->x));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",490)
		hx::AddEq(this->m_linearVelocity->y,(this->m_invMass * impulse->y));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",492)
		hx::AddEq(this->m_angularVelocity,(this->m_invI * (((((point->x - this->m_sweep->c->x)) * impulse->y) - (((point->y - this->m_sweep->c->y)) * impulse->x)))));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(B2Body_obj,applyImpulse,(void))

::box2D::dynamics::B2Body B2Body_obj::split( Dynamic callbackMethod){
	HX_SOURCE_PUSH("B2Body_obj::split")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",504)
	::box2D::common::math::B2Vec2 linearVelocity = this->getLinearVelocity()->copy();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",505)
	double angularVelocity = this->getAngularVelocity();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",506)
	::box2D::common::math::B2Vec2 center = this->getWorldCenter();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",507)
	::box2D::dynamics::B2Body body1 = hx::ObjectPtr<OBJ_>(this);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",508)
	::box2D::dynamics::B2Body body2 = this->m_world->createBody(this->getDefinition());
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",510)
	::box2D::dynamics::B2Fixture prev = null();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",511)
	::box2D::dynamics::B2Fixture f = body1->m_fixtureList;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",512)
	while(((f != null()))){
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",513)
		if ((callbackMethod(f).Cast< bool >())){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",516)
			::box2D::dynamics::B2Fixture next = f->m_next;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",518)
			if (((prev != null()))){
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",519)
				prev->m_next = next;
			}
			else{
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",521)
				body1->m_fixtureList = next;
			}
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",524)
			(body1->m_fixtureCount)--;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",527)
			f->m_next = body2->m_fixtureList;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",528)
			body2->m_fixtureList = f;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",529)
			(body2->m_fixtureCount)++;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",531)
			f->m_body = body2;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",533)
			f = next;
		}
		else{
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",535)
			prev = f;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",536)
			f = f->m_next;
		}
	}
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",540)
	body1->resetMassData();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",541)
	body2->resetMassData();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",544)
	::box2D::common::math::B2Vec2 center1 = body1->getWorldCenter();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",545)
	::box2D::common::math::B2Vec2 center2 = body2->getWorldCenter();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",547)
	::box2D::common::math::B2Vec2 velocity1 = ::box2D::common::math::B2Math_obj::addVV(linearVelocity,::box2D::common::math::B2Math_obj::crossFV(angularVelocity,::box2D::common::math::B2Math_obj::subtractVV(center1,center)));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",551)
	::box2D::common::math::B2Vec2 velocity2 = ::box2D::common::math::B2Math_obj::addVV(linearVelocity,::box2D::common::math::B2Math_obj::crossFV(angularVelocity,::box2D::common::math::B2Math_obj::subtractVV(center2,center)));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",555)
	body1->setLinearVelocity(velocity1);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",556)
	body2->setLinearVelocity(velocity2);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",557)
	body1->setAngularVelocity(angularVelocity);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",558)
	body2->setAngularVelocity(angularVelocity);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",560)
	body1->synchronizeFixtures();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",561)
	body2->synchronizeFixtures();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",563)
	return body2;
}


HX_DEFINE_DYNAMIC_FUNC1(B2Body_obj,split,return )

Void B2Body_obj::merge( ::box2D::dynamics::B2Body other){
{
		HX_SOURCE_PUSH("B2Body_obj::merge")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",573)
		::box2D::dynamics::B2Fixture f;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",574)
		f = other->m_fixtureList;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",577)
		::box2D::dynamics::B2Body body1 = hx::ObjectPtr<OBJ_>(this);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",578)
		::box2D::dynamics::B2Body body2 = other;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",580)
		while(((f != null()))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",582)
			::box2D::dynamics::B2Fixture next = f->m_next;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",585)
			(other->m_fixtureCount)--;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",588)
			f->m_next = this->m_fixtureList;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",589)
			this->m_fixtureList = f;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",590)
			(this->m_fixtureCount)++;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",592)
			f->m_body = body2;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",594)
			f = next;
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",596)
		body1->m_fixtureCount = (int)0;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",599)
		::box2D::common::math::B2Vec2 center1 = body1->getWorldCenter();
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",600)
		::box2D::common::math::B2Vec2 center2 = body2->getWorldCenter();
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",602)
		::box2D::common::math::B2Vec2 velocity1 = body1->getLinearVelocity()->copy();
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",603)
		::box2D::common::math::B2Vec2 velocity2 = body2->getLinearVelocity()->copy();
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",605)
		double angular1 = body1->getAngularVelocity();
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",606)
		double angular = body2->getAngularVelocity();
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",610)
		body1->resetMassData();
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",612)
		this->synchronizeFixtures();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2Body_obj,merge,(void))

double B2Body_obj::getMass( ){
	HX_SOURCE_PUSH("B2Body_obj::getMass")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",619)
	return this->m_mass;
}


HX_DEFINE_DYNAMIC_FUNC0(B2Body_obj,getMass,return )

double B2Body_obj::getInertia( ){
	HX_SOURCE_PUSH("B2Body_obj::getInertia")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",627)
	return this->m_I;
}


HX_DEFINE_DYNAMIC_FUNC0(B2Body_obj,getInertia,return )

Void B2Body_obj::getMassData( ::box2D::collision::shapes::B2MassData data){
{
		HX_SOURCE_PUSH("B2Body_obj::getMassData")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",636)
		data->mass = this->m_mass;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",637)
		data->I = this->m_I;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",638)
		data->center->setV(this->m_sweep->localCenter);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2Body_obj,getMassData,(void))

Void B2Body_obj::setMassData( ::box2D::collision::shapes::B2MassData massData){
{
		HX_SOURCE_PUSH("B2Body_obj::setMassData")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",651)
		::box2D::common::B2Settings_obj::b2Assert((this->m_world->isLocked() == false));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",652)
		if (((this->m_world->isLocked() == true))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",653)
			return null();
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",657)
		if (((this->m_type != ::box2D::dynamics::B2Body_obj::b2_dynamicBody))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",658)
			return null();
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",662)
		this->m_invMass = 0.0;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",663)
		this->m_I = 0.0;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",664)
		this->m_invI = 0.0;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",666)
		this->m_mass = massData->mass;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",669)
		if (((this->m_mass <= 0.0))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",670)
			this->m_mass = 1.0;
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",673)
		this->m_invMass = (double(1.0) / double(this->m_mass));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",675)
		if (((bool((massData->I > 0.0)) && bool((((int(this->m_flags) & int(::box2D::dynamics::B2Body_obj::e_fixedRotationFlag))) == (int)0))))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",678)
			this->m_I = (massData->I - (this->m_mass * (((massData->center->x * massData->center->x) + (massData->center->y * massData->center->y)))));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",679)
			this->m_invI = (double(1.0) / double(this->m_I));
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",683)
		::box2D::common::math::B2Vec2 oldCenter = this->m_sweep->c->copy();
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",684)
		this->m_sweep->localCenter->setV(massData->center);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",685)
		this->m_sweep->c0->setV(::box2D::common::math::B2Math_obj::mulX(this->m_xf,this->m_sweep->localCenter));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",686)
		this->m_sweep->c->setV(this->m_sweep->c0);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",690)
		hx::AddEq(this->m_linearVelocity->x,(this->m_angularVelocity * -(((this->m_sweep->c->y - oldCenter->y)))));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",691)
		hx::AddEq(this->m_linearVelocity->y,(this->m_angularVelocity * ((this->m_sweep->c->x - oldCenter->x))));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2Body_obj,setMassData,(void))

Void B2Body_obj::resetMassData( ){
{
		HX_SOURCE_PUSH("B2Body_obj::resetMassData")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",703)
		this->m_mass = 0.0;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",704)
		this->m_invMass = 0.0;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",705)
		this->m_I = 0.0;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",706)
		this->m_invI = 0.0;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",707)
		this->m_sweep->localCenter->setZero();
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",710)
		if (((bool((this->m_type == ::box2D::dynamics::B2Body_obj::b2_staticBody)) || bool((this->m_type == ::box2D::dynamics::B2Body_obj::b2_kinematicBody))))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",711)
			return null();
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",717)
		::box2D::common::math::B2Vec2 center = ::box2D::common::math::B2Vec2_obj::make((int)0,(int)0);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",719)
		::box2D::dynamics::B2Fixture f = this->m_fixtureList;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",721)
		while(((f != null()))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",723)
			if (((f->m_density == 0.0))){
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",724)
				continue;
			}
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",728)
			::box2D::collision::shapes::B2MassData massData = f->getMassData(null());
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",729)
			hx::AddEq(this->m_mass,massData->mass);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",730)
			hx::AddEq(center->x,(massData->center->x * massData->mass));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",731)
			hx::AddEq(center->y,(massData->center->y * massData->mass));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",732)
			hx::AddEq(this->m_I,massData->I);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",734)
			f = f->m_next;
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",738)
		if (((this->m_mass > 0.0))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",740)
			this->m_invMass = (double(1.0) / double(this->m_mass));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",741)
			hx::MultEq(center->x,this->m_invMass);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",742)
			hx::MultEq(center->y,this->m_invMass);
		}
		else{
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",747)
			this->m_mass = 1.0;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",748)
			this->m_invMass = 1.0;
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",751)
		if (((bool((this->m_I > 0.0)) && bool((((int(this->m_flags) & int(::box2D::dynamics::B2Body_obj::e_fixedRotationFlag))) == (int)0))))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",754)
			hx::SubEq(this->m_I,(this->m_mass * (((center->x * center->x) + (center->y * center->y)))));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",755)
			hx::MultEq(this->m_I,this->m_inertiaScale);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",756)
			::box2D::common::B2Settings_obj::b2Assert((this->m_I > (int)0));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",757)
			this->m_invI = (double(1.0) / double(this->m_I));
		}
		else{
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",759)
			this->m_I = 0.0;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",760)
			this->m_invI = 0.0;
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",764)
		::box2D::common::math::B2Vec2 oldCenter = this->m_sweep->c->copy();
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",765)
		this->m_sweep->localCenter->setV(center);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",766)
		this->m_sweep->c0->setV(::box2D::common::math::B2Math_obj::mulX(this->m_xf,this->m_sweep->localCenter));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",767)
		this->m_sweep->c->setV(this->m_sweep->c0);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",771)
		hx::AddEq(this->m_linearVelocity->x,(this->m_angularVelocity * -(((this->m_sweep->c->y - oldCenter->y)))));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",772)
		hx::AddEq(this->m_linearVelocity->y,(this->m_angularVelocity * ((this->m_sweep->c->x - oldCenter->x))));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(B2Body_obj,resetMassData,(void))

::box2D::common::math::B2Vec2 B2Body_obj::getWorldPoint( ::box2D::common::math::B2Vec2 localPoint){
	HX_SOURCE_PUSH("B2Body_obj::getWorldPoint")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",783)
	::box2D::common::math::B2Mat22 A = this->m_xf->R;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",784)
	::box2D::common::math::B2Vec2 u = ::box2D::common::math::B2Vec2_obj::__new(((A->col1->x * localPoint->x) + (A->col2->x * localPoint->y)),((A->col1->y * localPoint->x) + (A->col2->y * localPoint->y)));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",786)
	hx::AddEq(u->x,this->m_xf->position->x);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",787)
	hx::AddEq(u->y,this->m_xf->position->y);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",788)
	return u;
}


HX_DEFINE_DYNAMIC_FUNC1(B2Body_obj,getWorldPoint,return )

::box2D::common::math::B2Vec2 B2Body_obj::getWorldVector( ::box2D::common::math::B2Vec2 localVector){
	HX_SOURCE_PUSH("B2Body_obj::getWorldVector")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",796)
	return ::box2D::common::math::B2Math_obj::mulMV(this->m_xf->R,localVector);
}


HX_DEFINE_DYNAMIC_FUNC1(B2Body_obj,getWorldVector,return )

::box2D::common::math::B2Vec2 B2Body_obj::getLocalPoint( ::box2D::common::math::B2Vec2 worldPoint){
	HX_SOURCE_PUSH("B2Body_obj::getLocalPoint")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",805)
	return ::box2D::common::math::B2Math_obj::mulXT(this->m_xf,worldPoint);
}


HX_DEFINE_DYNAMIC_FUNC1(B2Body_obj,getLocalPoint,return )

::box2D::common::math::B2Vec2 B2Body_obj::getLocalVector( ::box2D::common::math::B2Vec2 worldVector){
	HX_SOURCE_PUSH("B2Body_obj::getLocalVector")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",814)
	return ::box2D::common::math::B2Math_obj::mulTMV(this->m_xf->R,worldVector);
}


HX_DEFINE_DYNAMIC_FUNC1(B2Body_obj,getLocalVector,return )

::box2D::common::math::B2Vec2 B2Body_obj::getLinearVelocityFromWorldPoint( ::box2D::common::math::B2Vec2 worldPoint){
	HX_SOURCE_PUSH("B2Body_obj::getLinearVelocityFromWorldPoint")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",824)
	return ::box2D::common::math::B2Vec2_obj::__new((this->m_linearVelocity->x - (this->m_angularVelocity * ((worldPoint->y - this->m_sweep->c->y)))),(this->m_linearVelocity->y + (this->m_angularVelocity * ((worldPoint->x - this->m_sweep->c->x)))));
}


HX_DEFINE_DYNAMIC_FUNC1(B2Body_obj,getLinearVelocityFromWorldPoint,return )

::box2D::common::math::B2Vec2 B2Body_obj::getLinearVelocityFromLocalPoint( ::box2D::common::math::B2Vec2 localPoint){
	HX_SOURCE_PUSH("B2Body_obj::getLinearVelocityFromLocalPoint")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",838)
	::box2D::common::math::B2Mat22 A = this->m_xf->R;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",839)
	::box2D::common::math::B2Vec2 worldPoint = ::box2D::common::math::B2Vec2_obj::__new(((A->col1->x * localPoint->x) + (A->col2->x * localPoint->y)),((A->col1->y * localPoint->x) + (A->col2->y * localPoint->y)));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",841)
	hx::AddEq(worldPoint->x,this->m_xf->position->x);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",842)
	hx::AddEq(worldPoint->y,this->m_xf->position->y);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",843)
	return ::box2D::common::math::B2Vec2_obj::__new((this->m_linearVelocity->x - (this->m_angularVelocity * ((worldPoint->y - this->m_sweep->c->y)))),(this->m_linearVelocity->y + (this->m_angularVelocity * ((worldPoint->x - this->m_sweep->c->x)))));
}


HX_DEFINE_DYNAMIC_FUNC1(B2Body_obj,getLinearVelocityFromLocalPoint,return )

double B2Body_obj::getLinearDamping( ){
	HX_SOURCE_PUSH("B2Body_obj::getLinearDamping")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",851)
	return this->m_linearDamping;
}


HX_DEFINE_DYNAMIC_FUNC0(B2Body_obj,getLinearDamping,return )

Void B2Body_obj::setLinearDamping( double linearDamping){
{
		HX_SOURCE_PUSH("B2Body_obj::setLinearDamping")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",859)
		this->m_linearDamping = linearDamping;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2Body_obj,setLinearDamping,(void))

double B2Body_obj::getAngularDamping( ){
	HX_SOURCE_PUSH("B2Body_obj::getAngularDamping")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",867)
	return this->m_angularDamping;
}


HX_DEFINE_DYNAMIC_FUNC0(B2Body_obj,getAngularDamping,return )

Void B2Body_obj::setAngularDamping( double angularDamping){
{
		HX_SOURCE_PUSH("B2Body_obj::setAngularDamping")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",875)
		this->m_angularDamping = angularDamping;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2Body_obj,setAngularDamping,(void))

Void B2Body_obj::setType( int type){
{
		HX_SOURCE_PUSH("B2Body_obj::setType")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",885)
		if (((this->m_type == type))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",886)
			return null();
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",890)
		this->m_type = type;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",892)
		this->resetMassData();
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",894)
		if (((this->m_type == ::box2D::dynamics::B2Body_obj::b2_staticBody))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",896)
			this->m_linearVelocity->setZero();
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",897)
			this->m_angularVelocity = 0.0;
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",900)
		this->setAwake(true);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",902)
		this->m_force->setZero();
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",903)
		this->m_torque = 0.0;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",906)
		::box2D::dynamics::contacts::B2ContactEdge ce = this->m_contactList;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",907)
		while(((ce != null()))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",909)
			ce->contact->flagForFiltering();
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",910)
			ce = ce->next;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2Body_obj,setType,(void))

int B2Body_obj::getType( ){
	HX_SOURCE_PUSH("B2Body_obj::getType")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",919)
	return this->m_type;
}


HX_DEFINE_DYNAMIC_FUNC0(B2Body_obj,getType,return )

Void B2Body_obj::setBullet( bool flag){
{
		HX_SOURCE_PUSH("B2Body_obj::setBullet")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",926)
		if ((flag)){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",928)
			hx::OrEq(this->m_flags,::box2D::dynamics::B2Body_obj::e_bulletFlag);
		}
		else{
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",932)
			hx::AndEq(this->m_flags,~(int)(::box2D::dynamics::B2Body_obj::e_bulletFlag));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2Body_obj,setBullet,(void))

bool B2Body_obj::isBullet( ){
	HX_SOURCE_PUSH("B2Body_obj::isBullet")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",940)
	return (((int(this->m_flags) & int(::box2D::dynamics::B2Body_obj::e_bulletFlag))) == ::box2D::dynamics::B2Body_obj::e_bulletFlag);
}


HX_DEFINE_DYNAMIC_FUNC0(B2Body_obj,isBullet,return )

Void B2Body_obj::setSleepingAllowed( bool flag){
{
		HX_SOURCE_PUSH("B2Body_obj::setSleepingAllowed")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",948)
		if ((flag)){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",950)
			hx::OrEq(this->m_flags,::box2D::dynamics::B2Body_obj::e_allowSleepFlag);
		}
		else{
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",955)
			hx::AndEq(this->m_flags,~(int)(::box2D::dynamics::B2Body_obj::e_allowSleepFlag));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",956)
			this->setAwake(true);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2Body_obj,setSleepingAllowed,(void))

Void B2Body_obj::setAwake( bool flag){
{
		HX_SOURCE_PUSH("B2Body_obj::setAwake")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",964)
		if ((flag)){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",967)
			hx::OrEq(this->m_flags,::box2D::dynamics::B2Body_obj::e_awakeFlag);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",968)
			this->m_sleepTime = 0.0;
		}
		else{
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",972)
			hx::AndEq(this->m_flags,~(int)(::box2D::dynamics::B2Body_obj::e_awakeFlag));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",973)
			this->m_sleepTime = 0.0;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",974)
			this->m_linearVelocity->setZero();
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",975)
			this->m_angularVelocity = 0.0;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",976)
			this->m_force->setZero();
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",977)
			this->m_torque = 0.0;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2Body_obj,setAwake,(void))

bool B2Body_obj::isAwake( ){
	HX_SOURCE_PUSH("B2Body_obj::isAwake")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",985)
	return (((int(this->m_flags) & int(::box2D::dynamics::B2Body_obj::e_awakeFlag))) == ::box2D::dynamics::B2Body_obj::e_awakeFlag);
}


HX_DEFINE_DYNAMIC_FUNC0(B2Body_obj,isAwake,return )

Void B2Body_obj::setFixedRotation( bool fixed){
{
		HX_SOURCE_PUSH("B2Body_obj::setFixedRotation")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",995)
		if ((fixed)){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",996)
			hx::OrEq(this->m_flags,::box2D::dynamics::B2Body_obj::e_fixedRotationFlag);
		}
		else{
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",1000)
			hx::AndEq(this->m_flags,~(int)(::box2D::dynamics::B2Body_obj::e_fixedRotationFlag));
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",1004)
		this->resetMassData();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2Body_obj,setFixedRotation,(void))

bool B2Body_obj::isFixedRotation( ){
	HX_SOURCE_PUSH("B2Body_obj::isFixedRotation")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",1012)
	return (((int(this->m_flags) & int(::box2D::dynamics::B2Body_obj::e_fixedRotationFlag))) == ::box2D::dynamics::B2Body_obj::e_fixedRotationFlag);
}


HX_DEFINE_DYNAMIC_FUNC0(B2Body_obj,isFixedRotation,return )

Void B2Body_obj::setActive( bool flag){
{
		HX_SOURCE_PUSH("B2Body_obj::setActive")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",1031)
		if (((flag == this->isActive()))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",1032)
			return null();
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",1036)
		::box2D::collision::IBroadPhase broadPhase;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",1037)
		::box2D::dynamics::B2Fixture f;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",1038)
		if ((flag)){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",1040)
			hx::OrEq(this->m_flags,::box2D::dynamics::B2Body_obj::e_activeFlag);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",1043)
			broadPhase = this->m_world->m_contactManager->m_broadPhase;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",1044)
			f = this->m_fixtureList;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",1045)
			while(((f != null()))){
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",1047)
				f->createProxy(broadPhase,this->m_xf);
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",1048)
				f = f->m_next;
			}
		}
		else{
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",1054)
			hx::AndEq(this->m_flags,~(int)(::box2D::dynamics::B2Body_obj::e_activeFlag));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",1057)
			broadPhase = this->m_world->m_contactManager->m_broadPhase;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",1058)
			f = this->m_fixtureList;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",1059)
			while(((f != null()))){
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",1061)
				f->destroyProxy(broadPhase);
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",1062)
				f = f->m_next;
			}
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",1066)
			::box2D::dynamics::contacts::B2ContactEdge ce = this->m_contactList;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",1067)
			while(((ce != null()))){
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",1069)
				::box2D::dynamics::contacts::B2ContactEdge ce0 = ce;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",1070)
				ce = ce->next;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",1071)
				this->m_world->m_contactManager->destroy(ce0->contact);
			}
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",1073)
			this->m_contactList = null();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2Body_obj,setActive,(void))

bool B2Body_obj::isActive( ){
	HX_SOURCE_PUSH("B2Body_obj::isActive")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",1081)
	return (((int(this->m_flags) & int(::box2D::dynamics::B2Body_obj::e_activeFlag))) == ::box2D::dynamics::B2Body_obj::e_activeFlag);
}


HX_DEFINE_DYNAMIC_FUNC0(B2Body_obj,isActive,return )

bool B2Body_obj::isSleepingAllowed( ){
	HX_SOURCE_PUSH("B2Body_obj::isSleepingAllowed")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",1089)
	return (((int(this->m_flags) & int(::box2D::dynamics::B2Body_obj::e_allowSleepFlag))) == ::box2D::dynamics::B2Body_obj::e_allowSleepFlag);
}


HX_DEFINE_DYNAMIC_FUNC0(B2Body_obj,isSleepingAllowed,return )

::box2D::dynamics::B2Fixture B2Body_obj::getFixtureList( ){
	HX_SOURCE_PUSH("B2Body_obj::getFixtureList")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",1096)
	return this->m_fixtureList;
}


HX_DEFINE_DYNAMIC_FUNC0(B2Body_obj,getFixtureList,return )

::box2D::dynamics::joints::B2JointEdge B2Body_obj::getJointList( ){
	HX_SOURCE_PUSH("B2Body_obj::getJointList")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",1103)
	return this->m_jointList;
}


HX_DEFINE_DYNAMIC_FUNC0(B2Body_obj,getJointList,return )

::box2D::dynamics::controllers::B2ControllerEdge B2Body_obj::getControllerList( ){
	HX_SOURCE_PUSH("B2Body_obj::getControllerList")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",1110)
	return this->m_controllerList;
}


HX_DEFINE_DYNAMIC_FUNC0(B2Body_obj,getControllerList,return )

::box2D::dynamics::contacts::B2ContactEdge B2Body_obj::getContactList( ){
	HX_SOURCE_PUSH("B2Body_obj::getContactList")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",1117)
	return this->m_contactList;
}


HX_DEFINE_DYNAMIC_FUNC0(B2Body_obj,getContactList,return )

::box2D::dynamics::B2Body B2Body_obj::getNext( ){
	HX_SOURCE_PUSH("B2Body_obj::getNext")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",1124)
	return this->m_next;
}


HX_DEFINE_DYNAMIC_FUNC0(B2Body_obj,getNext,return )

Dynamic B2Body_obj::getUserData( ){
	HX_SOURCE_PUSH("B2Body_obj::getUserData")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",1131)
	return this->m_userData;
}


HX_DEFINE_DYNAMIC_FUNC0(B2Body_obj,getUserData,return )

Void B2Body_obj::setUserData( Dynamic data){
{
		HX_SOURCE_PUSH("B2Body_obj::setUserData")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",1139)
		this->m_userData = data;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2Body_obj,setUserData,(void))

::box2D::dynamics::B2World B2Body_obj::getWorld( ){
	HX_SOURCE_PUSH("B2Body_obj::getWorld")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",1147)
	return this->m_world;
}


HX_DEFINE_DYNAMIC_FUNC0(B2Body_obj,getWorld,return )

Void B2Body_obj::synchronizeFixtures( ){
{
		HX_SOURCE_PUSH("B2Body_obj::synchronizeFixtures")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",1271)
		::box2D::common::math::B2Transform xf1 = ::box2D::dynamics::B2Body_obj::s_xf1;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",1272)
		xf1->R->set(this->m_sweep->a0);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",1274)
		::box2D::common::math::B2Mat22 tMat = xf1->R;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",1275)
		::box2D::common::math::B2Vec2 tVec = this->m_sweep->localCenter;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",1276)
		xf1->position->x = (this->m_sweep->c0->x - (((tMat->col1->x * tVec->x) + (tMat->col2->x * tVec->y))));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",1277)
		xf1->position->y = (this->m_sweep->c0->y - (((tMat->col1->y * tVec->x) + (tMat->col2->y * tVec->y))));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",1279)
		::box2D::dynamics::B2Fixture f;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",1280)
		::box2D::collision::IBroadPhase broadPhase = this->m_world->m_contactManager->m_broadPhase;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",1281)
		f = this->m_fixtureList;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",1282)
		while(((f != null()))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",1284)
			f->synchronize(broadPhase,xf1,this->m_xf);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",1285)
			f = f->m_next;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(B2Body_obj,synchronizeFixtures,(void))

Void B2Body_obj::synchronizeTransform( ){
{
		HX_SOURCE_PUSH("B2Body_obj::synchronizeTransform")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",1290)
		this->m_xf->R->set(this->m_sweep->a);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",1292)
		::box2D::common::math::B2Mat22 tMat = this->m_xf->R;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",1293)
		::box2D::common::math::B2Vec2 tVec = this->m_sweep->localCenter;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",1294)
		this->m_xf->position->x = (this->m_sweep->c->x - (((tMat->col1->x * tVec->x) + (tMat->col2->x * tVec->y))));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",1295)
		this->m_xf->position->y = (this->m_sweep->c->y - (((tMat->col1->y * tVec->x) + (tMat->col2->y * tVec->y))));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(B2Body_obj,synchronizeTransform,(void))

bool B2Body_obj::shouldCollide( ::box2D::dynamics::B2Body other){
	HX_SOURCE_PUSH("B2Body_obj::shouldCollide")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",1302)
	if (((bool((this->m_type != ::box2D::dynamics::B2Body_obj::b2_dynamicBody)) && bool((other->m_type != ::box2D::dynamics::B2Body_obj::b2_dynamicBody))))){
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",1303)
		return false;
	}
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",1307)
	::box2D::dynamics::joints::B2JointEdge jn = this->m_jointList;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",1308)
	while(((jn != null()))){
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",1310)
		if (((jn->other == other))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",1311)
			if (((jn->joint->m_collideConnected == false))){
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",1312)
				return false;
			}
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",1315)
		jn = jn->next;
	}
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",1318)
	return true;
}


HX_DEFINE_DYNAMIC_FUNC1(B2Body_obj,shouldCollide,return )

Void B2Body_obj::advance( double t){
{
		HX_SOURCE_PUSH("B2Body_obj::advance")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",1323)
		this->m_sweep->advance(t);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",1324)
		this->m_sweep->c->setV(this->m_sweep->c0);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",1325)
		this->m_sweep->a = this->m_sweep->a0;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2Body.hx",1326)
		this->synchronizeTransform();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2Body_obj,advance,(void))

::box2D::common::math::B2Transform B2Body_obj::s_xf1;

int B2Body_obj::e_islandFlag;

int B2Body_obj::e_awakeFlag;

int B2Body_obj::e_allowSleepFlag;

int B2Body_obj::e_bulletFlag;

int B2Body_obj::e_fixedRotationFlag;

int B2Body_obj::e_activeFlag;

int B2Body_obj::b2_staticBody;

int B2Body_obj::b2_kinematicBody;

int B2Body_obj::b2_dynamicBody;


B2Body_obj::B2Body_obj()
{
}

void B2Body_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(B2Body);
	HX_MARK_MEMBER_NAME(m_flags,"m_flags");
	HX_MARK_MEMBER_NAME(m_type,"m_type");
	HX_MARK_MEMBER_NAME(m_islandIndex,"m_islandIndex");
	HX_MARK_MEMBER_NAME(m_xf,"m_xf");
	HX_MARK_MEMBER_NAME(m_sweep,"m_sweep");
	HX_MARK_MEMBER_NAME(m_linearVelocity,"m_linearVelocity");
	HX_MARK_MEMBER_NAME(m_angularVelocity,"m_angularVelocity");
	HX_MARK_MEMBER_NAME(m_force,"m_force");
	HX_MARK_MEMBER_NAME(m_torque,"m_torque");
	HX_MARK_MEMBER_NAME(m_world,"m_world");
	HX_MARK_MEMBER_NAME(m_prev,"m_prev");
	HX_MARK_MEMBER_NAME(m_next,"m_next");
	HX_MARK_MEMBER_NAME(m_fixtureList,"m_fixtureList");
	HX_MARK_MEMBER_NAME(m_fixtureCount,"m_fixtureCount");
	HX_MARK_MEMBER_NAME(m_controllerList,"m_controllerList");
	HX_MARK_MEMBER_NAME(m_controllerCount,"m_controllerCount");
	HX_MARK_MEMBER_NAME(m_jointList,"m_jointList");
	HX_MARK_MEMBER_NAME(m_contactList,"m_contactList");
	HX_MARK_MEMBER_NAME(m_mass,"m_mass");
	HX_MARK_MEMBER_NAME(m_invMass,"m_invMass");
	HX_MARK_MEMBER_NAME(m_I,"m_I");
	HX_MARK_MEMBER_NAME(m_invI,"m_invI");
	HX_MARK_MEMBER_NAME(m_inertiaScale,"m_inertiaScale");
	HX_MARK_MEMBER_NAME(m_linearDamping,"m_linearDamping");
	HX_MARK_MEMBER_NAME(m_angularDamping,"m_angularDamping");
	HX_MARK_MEMBER_NAME(m_sleepTime,"m_sleepTime");
	HX_MARK_MEMBER_NAME(m_userData,"m_userData");
	HX_MARK_END_CLASS();
}

Dynamic B2Body_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"m_I") ) { return m_I; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"m_xf") ) { return m_xf; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"s_xf1") ) { return s_xf1; }
		if (HX_FIELD_EQ(inName,"split") ) { return split_dyn(); }
		if (HX_FIELD_EQ(inName,"merge") ) { return merge_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"m_type") ) { return m_type; }
		if (HX_FIELD_EQ(inName,"m_prev") ) { return m_prev; }
		if (HX_FIELD_EQ(inName,"m_next") ) { return m_next; }
		if (HX_FIELD_EQ(inName,"m_mass") ) { return m_mass; }
		if (HX_FIELD_EQ(inName,"m_invI") ) { return m_invI; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"getMass") ) { return getMass_dyn(); }
		if (HX_FIELD_EQ(inName,"setType") ) { return setType_dyn(); }
		if (HX_FIELD_EQ(inName,"getType") ) { return getType_dyn(); }
		if (HX_FIELD_EQ(inName,"isAwake") ) { return isAwake_dyn(); }
		if (HX_FIELD_EQ(inName,"getNext") ) { return getNext_dyn(); }
		if (HX_FIELD_EQ(inName,"advance") ) { return advance_dyn(); }
		if (HX_FIELD_EQ(inName,"m_flags") ) { return m_flags; }
		if (HX_FIELD_EQ(inName,"m_sweep") ) { return m_sweep; }
		if (HX_FIELD_EQ(inName,"m_force") ) { return m_force; }
		if (HX_FIELD_EQ(inName,"m_world") ) { return m_world; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"getAngle") ) { return getAngle_dyn(); }
		if (HX_FIELD_EQ(inName,"setAngle") ) { return setAngle_dyn(); }
		if (HX_FIELD_EQ(inName,"isBullet") ) { return isBullet_dyn(); }
		if (HX_FIELD_EQ(inName,"setAwake") ) { return setAwake_dyn(); }
		if (HX_FIELD_EQ(inName,"isActive") ) { return isActive_dyn(); }
		if (HX_FIELD_EQ(inName,"getWorld") ) { return getWorld_dyn(); }
		if (HX_FIELD_EQ(inName,"m_torque") ) { return m_torque; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"setBullet") ) { return setBullet_dyn(); }
		if (HX_FIELD_EQ(inName,"setActive") ) { return setActive_dyn(); }
		if (HX_FIELD_EQ(inName,"m_invMass") ) { return m_invMass; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"applyForce") ) { return applyForce_dyn(); }
		if (HX_FIELD_EQ(inName,"getInertia") ) { return getInertia_dyn(); }
		if (HX_FIELD_EQ(inName,"m_userData") ) { return m_userData; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"e_awakeFlag") ) { return e_awakeFlag; }
		if (HX_FIELD_EQ(inName,"getPosition") ) { return getPosition_dyn(); }
		if (HX_FIELD_EQ(inName,"setPosition") ) { return setPosition_dyn(); }
		if (HX_FIELD_EQ(inName,"applyTorque") ) { return applyTorque_dyn(); }
		if (HX_FIELD_EQ(inName,"getMassData") ) { return getMassData_dyn(); }
		if (HX_FIELD_EQ(inName,"setMassData") ) { return setMassData_dyn(); }
		if (HX_FIELD_EQ(inName,"getUserData") ) { return getUserData_dyn(); }
		if (HX_FIELD_EQ(inName,"setUserData") ) { return setUserData_dyn(); }
		if (HX_FIELD_EQ(inName,"m_jointList") ) { return m_jointList; }
		if (HX_FIELD_EQ(inName,"m_sleepTime") ) { return m_sleepTime; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"e_islandFlag") ) { return e_islandFlag; }
		if (HX_FIELD_EQ(inName,"e_bulletFlag") ) { return e_bulletFlag; }
		if (HX_FIELD_EQ(inName,"e_activeFlag") ) { return e_activeFlag; }
		if (HX_FIELD_EQ(inName,"connectEdges") ) { return connectEdges_dyn(); }
		if (HX_FIELD_EQ(inName,"setTransform") ) { return setTransform_dyn(); }
		if (HX_FIELD_EQ(inName,"getTransform") ) { return getTransform_dyn(); }
		if (HX_FIELD_EQ(inName,"applyImpulse") ) { return applyImpulse_dyn(); }
		if (HX_FIELD_EQ(inName,"getJointList") ) { return getJointList_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"b2_staticBody") ) { return b2_staticBody; }
		if (HX_FIELD_EQ(inName,"createFixture") ) { return createFixture_dyn(); }
		if (HX_FIELD_EQ(inName,"getDefinition") ) { return getDefinition_dyn(); }
		if (HX_FIELD_EQ(inName,"resetMassData") ) { return resetMassData_dyn(); }
		if (HX_FIELD_EQ(inName,"getWorldPoint") ) { return getWorldPoint_dyn(); }
		if (HX_FIELD_EQ(inName,"getLocalPoint") ) { return getLocalPoint_dyn(); }
		if (HX_FIELD_EQ(inName,"shouldCollide") ) { return shouldCollide_dyn(); }
		if (HX_FIELD_EQ(inName,"m_islandIndex") ) { return m_islandIndex; }
		if (HX_FIELD_EQ(inName,"m_fixtureList") ) { return m_fixtureList; }
		if (HX_FIELD_EQ(inName,"m_contactList") ) { return m_contactList; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"b2_dynamicBody") ) { return b2_dynamicBody; }
		if (HX_FIELD_EQ(inName,"createFixture2") ) { return createFixture2_dyn(); }
		if (HX_FIELD_EQ(inName,"DestroyFixture") ) { return DestroyFixture_dyn(); }
		if (HX_FIELD_EQ(inName,"getWorldCenter") ) { return getWorldCenter_dyn(); }
		if (HX_FIELD_EQ(inName,"getLocalCenter") ) { return getLocalCenter_dyn(); }
		if (HX_FIELD_EQ(inName,"getWorldVector") ) { return getWorldVector_dyn(); }
		if (HX_FIELD_EQ(inName,"getLocalVector") ) { return getLocalVector_dyn(); }
		if (HX_FIELD_EQ(inName,"getFixtureList") ) { return getFixtureList_dyn(); }
		if (HX_FIELD_EQ(inName,"getContactList") ) { return getContactList_dyn(); }
		if (HX_FIELD_EQ(inName,"m_fixtureCount") ) { return m_fixtureCount; }
		if (HX_FIELD_EQ(inName,"m_inertiaScale") ) { return m_inertiaScale; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"isFixedRotation") ) { return isFixedRotation_dyn(); }
		if (HX_FIELD_EQ(inName,"m_linearDamping") ) { return m_linearDamping; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"e_allowSleepFlag") ) { return e_allowSleepFlag; }
		if (HX_FIELD_EQ(inName,"b2_kinematicBody") ) { return b2_kinematicBody; }
		if (HX_FIELD_EQ(inName,"getLinearDamping") ) { return getLinearDamping_dyn(); }
		if (HX_FIELD_EQ(inName,"setLinearDamping") ) { return setLinearDamping_dyn(); }
		if (HX_FIELD_EQ(inName,"setFixedRotation") ) { return setFixedRotation_dyn(); }
		if (HX_FIELD_EQ(inName,"m_linearVelocity") ) { return m_linearVelocity; }
		if (HX_FIELD_EQ(inName,"m_controllerList") ) { return m_controllerList; }
		if (HX_FIELD_EQ(inName,"m_angularDamping") ) { return m_angularDamping; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"setLinearVelocity") ) { return setLinearVelocity_dyn(); }
		if (HX_FIELD_EQ(inName,"getLinearVelocity") ) { return getLinearVelocity_dyn(); }
		if (HX_FIELD_EQ(inName,"getAngularDamping") ) { return getAngularDamping_dyn(); }
		if (HX_FIELD_EQ(inName,"setAngularDamping") ) { return setAngularDamping_dyn(); }
		if (HX_FIELD_EQ(inName,"isSleepingAllowed") ) { return isSleepingAllowed_dyn(); }
		if (HX_FIELD_EQ(inName,"getControllerList") ) { return getControllerList_dyn(); }
		if (HX_FIELD_EQ(inName,"m_angularVelocity") ) { return m_angularVelocity; }
		if (HX_FIELD_EQ(inName,"m_controllerCount") ) { return m_controllerCount; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"setAngularVelocity") ) { return setAngularVelocity_dyn(); }
		if (HX_FIELD_EQ(inName,"getAngularVelocity") ) { return getAngularVelocity_dyn(); }
		if (HX_FIELD_EQ(inName,"setSleepingAllowed") ) { return setSleepingAllowed_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"e_fixedRotationFlag") ) { return e_fixedRotationFlag; }
		if (HX_FIELD_EQ(inName,"setPositionAndAngle") ) { return setPositionAndAngle_dyn(); }
		if (HX_FIELD_EQ(inName,"synchronizeFixtures") ) { return synchronizeFixtures_dyn(); }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"synchronizeTransform") ) { return synchronizeTransform_dyn(); }
		break;
	case 31:
		if (HX_FIELD_EQ(inName,"getLinearVelocityFromWorldPoint") ) { return getLinearVelocityFromWorldPoint_dyn(); }
		if (HX_FIELD_EQ(inName,"getLinearVelocityFromLocalPoint") ) { return getLinearVelocityFromLocalPoint_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic B2Body_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"m_I") ) { m_I=inValue.Cast< double >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"m_xf") ) { m_xf=inValue.Cast< ::box2D::common::math::B2Transform >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"s_xf1") ) { s_xf1=inValue.Cast< ::box2D::common::math::B2Transform >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"m_type") ) { m_type=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_prev") ) { m_prev=inValue.Cast< ::box2D::dynamics::B2Body >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_next") ) { m_next=inValue.Cast< ::box2D::dynamics::B2Body >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_mass") ) { m_mass=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_invI") ) { m_invI=inValue.Cast< double >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"m_flags") ) { m_flags=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_sweep") ) { m_sweep=inValue.Cast< ::box2D::common::math::B2Sweep >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_force") ) { m_force=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_world") ) { m_world=inValue.Cast< ::box2D::dynamics::B2World >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"m_torque") ) { m_torque=inValue.Cast< double >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"m_invMass") ) { m_invMass=inValue.Cast< double >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"m_userData") ) { m_userData=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"e_awakeFlag") ) { e_awakeFlag=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_jointList") ) { m_jointList=inValue.Cast< ::box2D::dynamics::joints::B2JointEdge >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_sleepTime") ) { m_sleepTime=inValue.Cast< double >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"e_islandFlag") ) { e_islandFlag=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"e_bulletFlag") ) { e_bulletFlag=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"e_activeFlag") ) { e_activeFlag=inValue.Cast< int >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"b2_staticBody") ) { b2_staticBody=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_islandIndex") ) { m_islandIndex=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_fixtureList") ) { m_fixtureList=inValue.Cast< ::box2D::dynamics::B2Fixture >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_contactList") ) { m_contactList=inValue.Cast< ::box2D::dynamics::contacts::B2ContactEdge >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"b2_dynamicBody") ) { b2_dynamicBody=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_fixtureCount") ) { m_fixtureCount=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_inertiaScale") ) { m_inertiaScale=inValue.Cast< double >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"m_linearDamping") ) { m_linearDamping=inValue.Cast< double >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"e_allowSleepFlag") ) { e_allowSleepFlag=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"b2_kinematicBody") ) { b2_kinematicBody=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_linearVelocity") ) { m_linearVelocity=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_controllerList") ) { m_controllerList=inValue.Cast< ::box2D::dynamics::controllers::B2ControllerEdge >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_angularDamping") ) { m_angularDamping=inValue.Cast< double >(); return inValue; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"m_angularVelocity") ) { m_angularVelocity=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_controllerCount") ) { m_controllerCount=inValue.Cast< int >(); return inValue; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"e_fixedRotationFlag") ) { e_fixedRotationFlag=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void B2Body_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("m_flags"));
	outFields->push(HX_CSTRING("m_type"));
	outFields->push(HX_CSTRING("m_islandIndex"));
	outFields->push(HX_CSTRING("m_xf"));
	outFields->push(HX_CSTRING("m_sweep"));
	outFields->push(HX_CSTRING("m_linearVelocity"));
	outFields->push(HX_CSTRING("m_angularVelocity"));
	outFields->push(HX_CSTRING("m_force"));
	outFields->push(HX_CSTRING("m_torque"));
	outFields->push(HX_CSTRING("m_world"));
	outFields->push(HX_CSTRING("m_prev"));
	outFields->push(HX_CSTRING("m_next"));
	outFields->push(HX_CSTRING("m_fixtureList"));
	outFields->push(HX_CSTRING("m_fixtureCount"));
	outFields->push(HX_CSTRING("m_controllerList"));
	outFields->push(HX_CSTRING("m_controllerCount"));
	outFields->push(HX_CSTRING("m_jointList"));
	outFields->push(HX_CSTRING("m_contactList"));
	outFields->push(HX_CSTRING("m_mass"));
	outFields->push(HX_CSTRING("m_invMass"));
	outFields->push(HX_CSTRING("m_I"));
	outFields->push(HX_CSTRING("m_invI"));
	outFields->push(HX_CSTRING("m_inertiaScale"));
	outFields->push(HX_CSTRING("m_linearDamping"));
	outFields->push(HX_CSTRING("m_angularDamping"));
	outFields->push(HX_CSTRING("m_sleepTime"));
	outFields->push(HX_CSTRING("m_userData"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("s_xf1"),
	HX_CSTRING("e_islandFlag"),
	HX_CSTRING("e_awakeFlag"),
	HX_CSTRING("e_allowSleepFlag"),
	HX_CSTRING("e_bulletFlag"),
	HX_CSTRING("e_fixedRotationFlag"),
	HX_CSTRING("e_activeFlag"),
	HX_CSTRING("b2_staticBody"),
	HX_CSTRING("b2_kinematicBody"),
	HX_CSTRING("b2_dynamicBody"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("connectEdges"),
	HX_CSTRING("createFixture"),
	HX_CSTRING("createFixture2"),
	HX_CSTRING("DestroyFixture"),
	HX_CSTRING("setPositionAndAngle"),
	HX_CSTRING("setTransform"),
	HX_CSTRING("getTransform"),
	HX_CSTRING("getPosition"),
	HX_CSTRING("setPosition"),
	HX_CSTRING("getAngle"),
	HX_CSTRING("setAngle"),
	HX_CSTRING("getWorldCenter"),
	HX_CSTRING("getLocalCenter"),
	HX_CSTRING("setLinearVelocity"),
	HX_CSTRING("getLinearVelocity"),
	HX_CSTRING("setAngularVelocity"),
	HX_CSTRING("getAngularVelocity"),
	HX_CSTRING("getDefinition"),
	HX_CSTRING("applyForce"),
	HX_CSTRING("applyTorque"),
	HX_CSTRING("applyImpulse"),
	HX_CSTRING("split"),
	HX_CSTRING("merge"),
	HX_CSTRING("getMass"),
	HX_CSTRING("getInertia"),
	HX_CSTRING("getMassData"),
	HX_CSTRING("setMassData"),
	HX_CSTRING("resetMassData"),
	HX_CSTRING("getWorldPoint"),
	HX_CSTRING("getWorldVector"),
	HX_CSTRING("getLocalPoint"),
	HX_CSTRING("getLocalVector"),
	HX_CSTRING("getLinearVelocityFromWorldPoint"),
	HX_CSTRING("getLinearVelocityFromLocalPoint"),
	HX_CSTRING("getLinearDamping"),
	HX_CSTRING("setLinearDamping"),
	HX_CSTRING("getAngularDamping"),
	HX_CSTRING("setAngularDamping"),
	HX_CSTRING("setType"),
	HX_CSTRING("getType"),
	HX_CSTRING("setBullet"),
	HX_CSTRING("isBullet"),
	HX_CSTRING("setSleepingAllowed"),
	HX_CSTRING("setAwake"),
	HX_CSTRING("isAwake"),
	HX_CSTRING("setFixedRotation"),
	HX_CSTRING("isFixedRotation"),
	HX_CSTRING("setActive"),
	HX_CSTRING("isActive"),
	HX_CSTRING("isSleepingAllowed"),
	HX_CSTRING("getFixtureList"),
	HX_CSTRING("getJointList"),
	HX_CSTRING("getControllerList"),
	HX_CSTRING("getContactList"),
	HX_CSTRING("getNext"),
	HX_CSTRING("getUserData"),
	HX_CSTRING("setUserData"),
	HX_CSTRING("getWorld"),
	HX_CSTRING("synchronizeFixtures"),
	HX_CSTRING("synchronizeTransform"),
	HX_CSTRING("shouldCollide"),
	HX_CSTRING("advance"),
	HX_CSTRING("m_flags"),
	HX_CSTRING("m_type"),
	HX_CSTRING("m_islandIndex"),
	HX_CSTRING("m_xf"),
	HX_CSTRING("m_sweep"),
	HX_CSTRING("m_linearVelocity"),
	HX_CSTRING("m_angularVelocity"),
	HX_CSTRING("m_force"),
	HX_CSTRING("m_torque"),
	HX_CSTRING("m_world"),
	HX_CSTRING("m_prev"),
	HX_CSTRING("m_next"),
	HX_CSTRING("m_fixtureList"),
	HX_CSTRING("m_fixtureCount"),
	HX_CSTRING("m_controllerList"),
	HX_CSTRING("m_controllerCount"),
	HX_CSTRING("m_jointList"),
	HX_CSTRING("m_contactList"),
	HX_CSTRING("m_mass"),
	HX_CSTRING("m_invMass"),
	HX_CSTRING("m_I"),
	HX_CSTRING("m_invI"),
	HX_CSTRING("m_inertiaScale"),
	HX_CSTRING("m_linearDamping"),
	HX_CSTRING("m_angularDamping"),
	HX_CSTRING("m_sleepTime"),
	HX_CSTRING("m_userData"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(B2Body_obj::s_xf1,"s_xf1");
	HX_MARK_MEMBER_NAME(B2Body_obj::e_islandFlag,"e_islandFlag");
	HX_MARK_MEMBER_NAME(B2Body_obj::e_awakeFlag,"e_awakeFlag");
	HX_MARK_MEMBER_NAME(B2Body_obj::e_allowSleepFlag,"e_allowSleepFlag");
	HX_MARK_MEMBER_NAME(B2Body_obj::e_bulletFlag,"e_bulletFlag");
	HX_MARK_MEMBER_NAME(B2Body_obj::e_fixedRotationFlag,"e_fixedRotationFlag");
	HX_MARK_MEMBER_NAME(B2Body_obj::e_activeFlag,"e_activeFlag");
	HX_MARK_MEMBER_NAME(B2Body_obj::b2_staticBody,"b2_staticBody");
	HX_MARK_MEMBER_NAME(B2Body_obj::b2_kinematicBody,"b2_kinematicBody");
	HX_MARK_MEMBER_NAME(B2Body_obj::b2_dynamicBody,"b2_dynamicBody");
};

Class B2Body_obj::__mClass;

void B2Body_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.dynamics.B2Body"), hx::TCanCast< B2Body_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void B2Body_obj::__boot()
{
	hx::Static(s_xf1) = ::box2D::common::math::B2Transform_obj::__new(null(),null());
	hx::Static(e_islandFlag) = (int)1;
	hx::Static(e_awakeFlag) = (int)2;
	hx::Static(e_allowSleepFlag) = (int)4;
	hx::Static(e_bulletFlag) = (int)8;
	hx::Static(e_fixedRotationFlag) = (int)16;
	hx::Static(e_activeFlag) = (int)32;
	hx::Static(b2_staticBody) = (int)0;
	hx::Static(b2_kinematicBody) = (int)1;
	hx::Static(b2_dynamicBody) = (int)2;
}

} // end namespace box2D
} // end namespace dynamics
