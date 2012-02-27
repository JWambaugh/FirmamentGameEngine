#ifndef INCLUDED_box2D_dynamics_joints_B2RevoluteJoint
#define INCLUDED_box2D_dynamics_joints_B2RevoluteJoint

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <box2D/dynamics/joints/B2Joint.h>
HX_DECLARE_CLASS3(box2D,common,math,B2Mat22)
HX_DECLARE_CLASS3(box2D,common,math,B2Mat33)
HX_DECLARE_CLASS3(box2D,common,math,B2Vec2)
HX_DECLARE_CLASS3(box2D,common,math,B2Vec3)
HX_DECLARE_CLASS2(box2D,dynamics,B2TimeStep)
HX_DECLARE_CLASS3(box2D,dynamics,joints,B2Joint)
HX_DECLARE_CLASS3(box2D,dynamics,joints,B2JointDef)
HX_DECLARE_CLASS3(box2D,dynamics,joints,B2RevoluteJoint)
HX_DECLARE_CLASS3(box2D,dynamics,joints,B2RevoluteJointDef)
namespace box2D{
namespace dynamics{
namespace joints{


class B2RevoluteJoint_obj : public ::box2D::dynamics::joints::B2Joint_obj{
	public:
		typedef ::box2D::dynamics::joints::B2Joint_obj super;
		typedef B2RevoluteJoint_obj OBJ_;
		B2RevoluteJoint_obj();
		Void __construct(::box2D::dynamics::joints::B2RevoluteJointDef def);

	public:
		static hx::ObjectPtr< B2RevoluteJoint_obj > __new(::box2D::dynamics::joints::B2RevoluteJointDef def);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~B2RevoluteJoint_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("B2RevoluteJoint"); }

		virtual ::box2D::common::math::B2Vec2 getAnchorA( );
		Dynamic getAnchorA_dyn();

		virtual ::box2D::common::math::B2Vec2 getAnchorB( );
		Dynamic getAnchorB_dyn();

		virtual ::box2D::common::math::B2Vec2 getReactionForce( double inv_dt);
		Dynamic getReactionForce_dyn();

		virtual double getReactionTorque( double inv_dt);
		Dynamic getReactionTorque_dyn();

		virtual double getJointAngle( );
		Dynamic getJointAngle_dyn();

		virtual double getJointSpeed( );
		Dynamic getJointSpeed_dyn();

		virtual bool isLimitEnabled( );
		Dynamic isLimitEnabled_dyn();

		virtual Void enableLimit( bool flag);
		Dynamic enableLimit_dyn();

		virtual double getLowerLimit( );
		Dynamic getLowerLimit_dyn();

		virtual double getUpperLimit( );
		Dynamic getUpperLimit_dyn();

		virtual Void setLimits( double lower,double upper);
		Dynamic setLimits_dyn();

		virtual bool isMotorEnabled( );
		Dynamic isMotorEnabled_dyn();

		virtual Void enableMotor( bool flag);
		Dynamic enableMotor_dyn();

		virtual Void setMotorSpeed( double speed);
		Dynamic setMotorSpeed_dyn();

		virtual double getMotorSpeed( );
		Dynamic getMotorSpeed_dyn();

		virtual Void setMaxMotorTorque( double torque);
		Dynamic setMaxMotorTorque_dyn();

		virtual double getMotorTorque( );
		Dynamic getMotorTorque_dyn();

		::box2D::common::math::B2Mat22 K; /* REM */ 
		::box2D::common::math::B2Mat22 K1; /* REM */ 
		::box2D::common::math::B2Mat22 K2; /* REM */ 
		::box2D::common::math::B2Mat22 K3; /* REM */ 
		virtual Void initVelocityConstraints( ::box2D::dynamics::B2TimeStep step);
		Dynamic initVelocityConstraints_dyn();

		::box2D::common::math::B2Vec3 impulse3; /* REM */ 
		::box2D::common::math::B2Vec2 impulse2; /* REM */ 
		::box2D::common::math::B2Vec2 reduced; /* REM */ 
		virtual Void solveVelocityConstraints( ::box2D::dynamics::B2TimeStep step);
		Dynamic solveVelocityConstraints_dyn();

		virtual bool solvePositionConstraints( double baumgarte);
		Dynamic solvePositionConstraints_dyn();

		::box2D::common::math::B2Vec2 m_localAnchor1; /* REM */ 
		::box2D::common::math::B2Vec2 m_localAnchor2; /* REM */ 
		::box2D::common::math::B2Vec3 m_impulse; /* REM */ 
		double m_motorImpulse; /* REM */ 
		::box2D::common::math::B2Mat33 m_mass; /* REM */ 
		double m_motorMass; /* REM */ 
		bool m_enableMotor; /* REM */ 
		double m_maxMotorTorque; /* REM */ 
		double m_motorSpeed; /* REM */ 
		bool m_enableLimit; /* REM */ 
		double m_referenceAngle; /* REM */ 
		double m_lowerAngle; /* REM */ 
		double m_upperAngle; /* REM */ 
		int m_limitState; /* REM */ 
		static ::box2D::common::math::B2Vec2 tImpulse; /* REM */ 
};

} // end namespace box2D
} // end namespace dynamics
} // end namespace joints

#endif /* INCLUDED_box2D_dynamics_joints_B2RevoluteJoint */ 
