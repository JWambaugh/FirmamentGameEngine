#ifndef INCLUDED_box2D_dynamics_B2Body
#define INCLUDED_box2D_dynamics_B2Body

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(box2D,collision,shapes,B2EdgeShape)
HX_DECLARE_CLASS3(box2D,collision,shapes,B2MassData)
HX_DECLARE_CLASS3(box2D,collision,shapes,B2Shape)
HX_DECLARE_CLASS3(box2D,common,math,B2Sweep)
HX_DECLARE_CLASS3(box2D,common,math,B2Transform)
HX_DECLARE_CLASS3(box2D,common,math,B2Vec2)
HX_DECLARE_CLASS2(box2D,dynamics,B2Body)
HX_DECLARE_CLASS2(box2D,dynamics,B2BodyDef)
HX_DECLARE_CLASS2(box2D,dynamics,B2Fixture)
HX_DECLARE_CLASS2(box2D,dynamics,B2FixtureDef)
HX_DECLARE_CLASS2(box2D,dynamics,B2World)
HX_DECLARE_CLASS3(box2D,dynamics,contacts,B2ContactEdge)
HX_DECLARE_CLASS3(box2D,dynamics,controllers,B2ControllerEdge)
HX_DECLARE_CLASS3(box2D,dynamics,joints,B2JointEdge)
namespace box2D{
namespace dynamics{


class B2Body_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef B2Body_obj OBJ_;
		B2Body_obj();
		Void __construct(::box2D::dynamics::B2BodyDef bd,::box2D::dynamics::B2World world);

	public:
		static hx::ObjectPtr< B2Body_obj > __new(::box2D::dynamics::B2BodyDef bd,::box2D::dynamics::B2World world);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~B2Body_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("B2Body"); }

		virtual double connectEdges( ::box2D::collision::shapes::B2EdgeShape s1,::box2D::collision::shapes::B2EdgeShape s2,double angle1);
		Dynamic connectEdges_dyn();

		virtual ::box2D::dynamics::B2Fixture createFixture( ::box2D::dynamics::B2FixtureDef def);
		Dynamic createFixture_dyn();

		virtual ::box2D::dynamics::B2Fixture createFixture2( ::box2D::collision::shapes::B2Shape shape,Dynamic density);
		Dynamic createFixture2_dyn();

		virtual Void DestroyFixture( ::box2D::dynamics::B2Fixture fixture);
		Dynamic DestroyFixture_dyn();

		virtual Void setPositionAndAngle( ::box2D::common::math::B2Vec2 position,double angle);
		Dynamic setPositionAndAngle_dyn();

		virtual Void setTransform( ::box2D::common::math::B2Transform xf);
		Dynamic setTransform_dyn();

		virtual ::box2D::common::math::B2Transform getTransform( );
		Dynamic getTransform_dyn();

		virtual ::box2D::common::math::B2Vec2 getPosition( );
		Dynamic getPosition_dyn();

		virtual Void setPosition( ::box2D::common::math::B2Vec2 position);
		Dynamic setPosition_dyn();

		virtual double getAngle( );
		Dynamic getAngle_dyn();

		virtual Void setAngle( double angle);
		Dynamic setAngle_dyn();

		virtual ::box2D::common::math::B2Vec2 getWorldCenter( );
		Dynamic getWorldCenter_dyn();

		virtual ::box2D::common::math::B2Vec2 getLocalCenter( );
		Dynamic getLocalCenter_dyn();

		virtual Void setLinearVelocity( ::box2D::common::math::B2Vec2 v);
		Dynamic setLinearVelocity_dyn();

		virtual ::box2D::common::math::B2Vec2 getLinearVelocity( );
		Dynamic getLinearVelocity_dyn();

		virtual Void setAngularVelocity( double omega);
		Dynamic setAngularVelocity_dyn();

		virtual double getAngularVelocity( );
		Dynamic getAngularVelocity_dyn();

		virtual ::box2D::dynamics::B2BodyDef getDefinition( );
		Dynamic getDefinition_dyn();

		virtual Void applyForce( ::box2D::common::math::B2Vec2 force,::box2D::common::math::B2Vec2 point);
		Dynamic applyForce_dyn();

		virtual Void applyTorque( double torque);
		Dynamic applyTorque_dyn();

		virtual Void applyImpulse( ::box2D::common::math::B2Vec2 impulse,::box2D::common::math::B2Vec2 point);
		Dynamic applyImpulse_dyn();

		virtual ::box2D::dynamics::B2Body split( Dynamic callbackMethod);
		Dynamic split_dyn();

		virtual Void merge( ::box2D::dynamics::B2Body other);
		Dynamic merge_dyn();

		virtual double getMass( );
		Dynamic getMass_dyn();

		virtual double getInertia( );
		Dynamic getInertia_dyn();

		virtual Void getMassData( ::box2D::collision::shapes::B2MassData data);
		Dynamic getMassData_dyn();

		virtual Void setMassData( ::box2D::collision::shapes::B2MassData massData);
		Dynamic setMassData_dyn();

		virtual Void resetMassData( );
		Dynamic resetMassData_dyn();

		virtual ::box2D::common::math::B2Vec2 getWorldPoint( ::box2D::common::math::B2Vec2 localPoint);
		Dynamic getWorldPoint_dyn();

		virtual ::box2D::common::math::B2Vec2 getWorldVector( ::box2D::common::math::B2Vec2 localVector);
		Dynamic getWorldVector_dyn();

		virtual ::box2D::common::math::B2Vec2 getLocalPoint( ::box2D::common::math::B2Vec2 worldPoint);
		Dynamic getLocalPoint_dyn();

		virtual ::box2D::common::math::B2Vec2 getLocalVector( ::box2D::common::math::B2Vec2 worldVector);
		Dynamic getLocalVector_dyn();

		virtual ::box2D::common::math::B2Vec2 getLinearVelocityFromWorldPoint( ::box2D::common::math::B2Vec2 worldPoint);
		Dynamic getLinearVelocityFromWorldPoint_dyn();

		virtual ::box2D::common::math::B2Vec2 getLinearVelocityFromLocalPoint( ::box2D::common::math::B2Vec2 localPoint);
		Dynamic getLinearVelocityFromLocalPoint_dyn();

		virtual double getLinearDamping( );
		Dynamic getLinearDamping_dyn();

		virtual Void setLinearDamping( double linearDamping);
		Dynamic setLinearDamping_dyn();

		virtual double getAngularDamping( );
		Dynamic getAngularDamping_dyn();

		virtual Void setAngularDamping( double angularDamping);
		Dynamic setAngularDamping_dyn();

		virtual Void setType( int type);
		Dynamic setType_dyn();

		virtual int getType( );
		Dynamic getType_dyn();

		virtual Void setBullet( bool flag);
		Dynamic setBullet_dyn();

		virtual bool isBullet( );
		Dynamic isBullet_dyn();

		virtual Void setSleepingAllowed( bool flag);
		Dynamic setSleepingAllowed_dyn();

		virtual Void setAwake( bool flag);
		Dynamic setAwake_dyn();

		virtual bool isAwake( );
		Dynamic isAwake_dyn();

		virtual Void setFixedRotation( bool fixed);
		Dynamic setFixedRotation_dyn();

		virtual bool isFixedRotation( );
		Dynamic isFixedRotation_dyn();

		virtual Void setActive( bool flag);
		Dynamic setActive_dyn();

		virtual bool isActive( );
		Dynamic isActive_dyn();

		virtual bool isSleepingAllowed( );
		Dynamic isSleepingAllowed_dyn();

		virtual ::box2D::dynamics::B2Fixture getFixtureList( );
		Dynamic getFixtureList_dyn();

		virtual ::box2D::dynamics::joints::B2JointEdge getJointList( );
		Dynamic getJointList_dyn();

		virtual ::box2D::dynamics::controllers::B2ControllerEdge getControllerList( );
		Dynamic getControllerList_dyn();

		virtual ::box2D::dynamics::contacts::B2ContactEdge getContactList( );
		Dynamic getContactList_dyn();

		virtual ::box2D::dynamics::B2Body getNext( );
		Dynamic getNext_dyn();

		virtual Dynamic getUserData( );
		Dynamic getUserData_dyn();

		virtual Void setUserData( Dynamic data);
		Dynamic setUserData_dyn();

		virtual ::box2D::dynamics::B2World getWorld( );
		Dynamic getWorld_dyn();

		virtual Void synchronizeFixtures( );
		Dynamic synchronizeFixtures_dyn();

		virtual Void synchronizeTransform( );
		Dynamic synchronizeTransform_dyn();

		virtual bool shouldCollide( ::box2D::dynamics::B2Body other);
		Dynamic shouldCollide_dyn();

		virtual Void advance( double t);
		Dynamic advance_dyn();

		int m_flags; /* REM */ 
		int m_type; /* REM */ 
		int m_islandIndex; /* REM */ 
		::box2D::common::math::B2Transform m_xf; /* REM */ 
		::box2D::common::math::B2Sweep m_sweep; /* REM */ 
		::box2D::common::math::B2Vec2 m_linearVelocity; /* REM */ 
		double m_angularVelocity; /* REM */ 
		::box2D::common::math::B2Vec2 m_force; /* REM */ 
		double m_torque; /* REM */ 
		::box2D::dynamics::B2World m_world; /* REM */ 
		::box2D::dynamics::B2Body m_prev; /* REM */ 
		::box2D::dynamics::B2Body m_next; /* REM */ 
		::box2D::dynamics::B2Fixture m_fixtureList; /* REM */ 
		int m_fixtureCount; /* REM */ 
		::box2D::dynamics::controllers::B2ControllerEdge m_controllerList; /* REM */ 
		int m_controllerCount; /* REM */ 
		::box2D::dynamics::joints::B2JointEdge m_jointList; /* REM */ 
		::box2D::dynamics::contacts::B2ContactEdge m_contactList; /* REM */ 
		double m_mass; /* REM */ 
		double m_invMass; /* REM */ 
		double m_I; /* REM */ 
		double m_invI; /* REM */ 
		double m_inertiaScale; /* REM */ 
		double m_linearDamping; /* REM */ 
		double m_angularDamping; /* REM */ 
		double m_sleepTime; /* REM */ 
		Dynamic m_userData; /* REM */ 
		static ::box2D::common::math::B2Transform s_xf1; /* REM */ 
		static int e_islandFlag; /* REM */ 
		static int e_awakeFlag; /* REM */ 
		static int e_allowSleepFlag; /* REM */ 
		static int e_bulletFlag; /* REM */ 
		static int e_fixedRotationFlag; /* REM */ 
		static int e_activeFlag; /* REM */ 
		static int b2_staticBody; /* REM */ 
		static int b2_kinematicBody; /* REM */ 
		static int b2_dynamicBody; /* REM */ 
};

} // end namespace box2D
} // end namespace dynamics

#endif /* INCLUDED_box2D_dynamics_B2Body */ 
