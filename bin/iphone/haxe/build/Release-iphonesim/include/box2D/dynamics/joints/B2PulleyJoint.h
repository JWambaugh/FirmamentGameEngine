#ifndef INCLUDED_box2D_dynamics_joints_B2PulleyJoint
#define INCLUDED_box2D_dynamics_joints_B2PulleyJoint

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <box2D/dynamics/joints/B2Joint.h>
HX_DECLARE_CLASS3(box2D,common,math,B2Vec2)
HX_DECLARE_CLASS2(box2D,dynamics,B2Body)
HX_DECLARE_CLASS2(box2D,dynamics,B2TimeStep)
HX_DECLARE_CLASS3(box2D,dynamics,joints,B2Joint)
HX_DECLARE_CLASS3(box2D,dynamics,joints,B2JointDef)
HX_DECLARE_CLASS3(box2D,dynamics,joints,B2PulleyJoint)
HX_DECLARE_CLASS3(box2D,dynamics,joints,B2PulleyJointDef)
namespace box2D{
namespace dynamics{
namespace joints{


class B2PulleyJoint_obj : public ::box2D::dynamics::joints::B2Joint_obj{
	public:
		typedef ::box2D::dynamics::joints::B2Joint_obj super;
		typedef B2PulleyJoint_obj OBJ_;
		B2PulleyJoint_obj();
		Void __construct(::box2D::dynamics::joints::B2PulleyJointDef def);

	public:
		static hx::ObjectPtr< B2PulleyJoint_obj > __new(::box2D::dynamics::joints::B2PulleyJointDef def);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~B2PulleyJoint_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("B2PulleyJoint"); }

		virtual ::box2D::common::math::B2Vec2 getAnchorA( );
		Dynamic getAnchorA_dyn();

		virtual ::box2D::common::math::B2Vec2 getAnchorB( );
		Dynamic getAnchorB_dyn();

		virtual ::box2D::common::math::B2Vec2 getReactionForce( double inv_dt);
		Dynamic getReactionForce_dyn();

		virtual double getReactionTorque( double inv_dt);
		Dynamic getReactionTorque_dyn();

		virtual ::box2D::common::math::B2Vec2 getGroundAnchorA( );
		Dynamic getGroundAnchorA_dyn();

		virtual ::box2D::common::math::B2Vec2 getGroundAnchorB( );
		Dynamic getGroundAnchorB_dyn();

		virtual double getLength1( );
		Dynamic getLength1_dyn();

		virtual double getLength2( );
		Dynamic getLength2_dyn();

		virtual double getRatio( );
		Dynamic getRatio_dyn();

		virtual Void initVelocityConstraints( ::box2D::dynamics::B2TimeStep step);
		Dynamic initVelocityConstraints_dyn();

		virtual Void solveVelocityConstraints( ::box2D::dynamics::B2TimeStep step);
		Dynamic solveVelocityConstraints_dyn();

		virtual bool solvePositionConstraints( double baumgarte);
		Dynamic solvePositionConstraints_dyn();

		::box2D::dynamics::B2Body m_ground; /* REM */ 
		::box2D::common::math::B2Vec2 m_groundAnchor1; /* REM */ 
		::box2D::common::math::B2Vec2 m_groundAnchor2; /* REM */ 
		::box2D::common::math::B2Vec2 m_localAnchor1; /* REM */ 
		::box2D::common::math::B2Vec2 m_localAnchor2; /* REM */ 
		::box2D::common::math::B2Vec2 m_u1; /* REM */ 
		::box2D::common::math::B2Vec2 m_u2; /* REM */ 
		double m_constant; /* REM */ 
		double m_ratio; /* REM */ 
		double m_maxLength1; /* REM */ 
		double m_maxLength2; /* REM */ 
		double m_pulleyMass; /* REM */ 
		double m_limitMass1; /* REM */ 
		double m_limitMass2; /* REM */ 
		double m_impulse; /* REM */ 
		double m_limitImpulse1; /* REM */ 
		double m_limitImpulse2; /* REM */ 
		int m_state; /* REM */ 
		int m_limitState1; /* REM */ 
		int m_limitState2; /* REM */ 
		static double b2_minPulleyLength; /* REM */ 
};

} // end namespace box2D
} // end namespace dynamics
} // end namespace joints

#endif /* INCLUDED_box2D_dynamics_joints_B2PulleyJoint */ 
