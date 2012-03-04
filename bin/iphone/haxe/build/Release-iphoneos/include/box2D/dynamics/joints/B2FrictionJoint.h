#ifndef INCLUDED_box2D_dynamics_joints_B2FrictionJoint
#define INCLUDED_box2D_dynamics_joints_B2FrictionJoint

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <box2D/dynamics/joints/B2Joint.h>
HX_DECLARE_CLASS3(box2D,common,math,B2Mat22)
HX_DECLARE_CLASS3(box2D,common,math,B2Vec2)
HX_DECLARE_CLASS2(box2D,dynamics,B2TimeStep)
HX_DECLARE_CLASS3(box2D,dynamics,joints,B2FrictionJoint)
HX_DECLARE_CLASS3(box2D,dynamics,joints,B2FrictionJointDef)
HX_DECLARE_CLASS3(box2D,dynamics,joints,B2Joint)
HX_DECLARE_CLASS3(box2D,dynamics,joints,B2JointDef)
namespace box2D{
namespace dynamics{
namespace joints{


class B2FrictionJoint_obj : public ::box2D::dynamics::joints::B2Joint_obj{
	public:
		typedef ::box2D::dynamics::joints::B2Joint_obj super;
		typedef B2FrictionJoint_obj OBJ_;
		B2FrictionJoint_obj();
		Void __construct(::box2D::dynamics::joints::B2FrictionJointDef def);

	public:
		static hx::ObjectPtr< B2FrictionJoint_obj > __new(::box2D::dynamics::joints::B2FrictionJointDef def);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~B2FrictionJoint_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("B2FrictionJoint"); }

		virtual ::box2D::common::math::B2Vec2 getAnchorA( );
		Dynamic getAnchorA_dyn();

		virtual ::box2D::common::math::B2Vec2 getAnchorB( );
		Dynamic getAnchorB_dyn();

		virtual ::box2D::common::math::B2Vec2 getReactionForce( double inv_dt);
		Dynamic getReactionForce_dyn();

		virtual double getReactionTorque( double inv_dt);
		Dynamic getReactionTorque_dyn();

		virtual Void setMaxForce( double force);
		Dynamic setMaxForce_dyn();

		virtual double getMaxForce( );
		Dynamic getMaxForce_dyn();

		virtual Void setMaxTorque( double torque);
		Dynamic setMaxTorque_dyn();

		virtual double getMaxTorque( );
		Dynamic getMaxTorque_dyn();

		virtual Void initVelocityConstraints( ::box2D::dynamics::B2TimeStep step);
		Dynamic initVelocityConstraints_dyn();

		virtual Void solveVelocityConstraints( ::box2D::dynamics::B2TimeStep step);
		Dynamic solveVelocityConstraints_dyn();

		virtual bool solvePositionConstraints( double baumgarte);
		Dynamic solvePositionConstraints_dyn();

		::box2D::common::math::B2Vec2 m_localAnchorA; /* REM */ 
		::box2D::common::math::B2Vec2 m_localAnchorB; /* REM */ 
		::box2D::common::math::B2Mat22 m_linearMass; /* REM */ 
		double m_angularMass; /* REM */ 
		::box2D::common::math::B2Vec2 m_linearImpulse; /* REM */ 
		double m_angularImpulse; /* REM */ 
		double m_maxForce; /* REM */ 
		double m_maxTorque; /* REM */ 
};

} // end namespace box2D
} // end namespace dynamics
} // end namespace joints

#endif /* INCLUDED_box2D_dynamics_joints_B2FrictionJoint */ 
