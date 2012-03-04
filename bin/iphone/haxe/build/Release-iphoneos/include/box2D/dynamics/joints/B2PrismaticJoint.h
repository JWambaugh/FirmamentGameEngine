#ifndef INCLUDED_box2D_dynamics_joints_B2PrismaticJoint
#define INCLUDED_box2D_dynamics_joints_B2PrismaticJoint

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <box2D/dynamics/joints/B2Joint.h>
HX_DECLARE_CLASS3(box2D,common,math,B2Mat33)
HX_DECLARE_CLASS3(box2D,common,math,B2Vec2)
HX_DECLARE_CLASS3(box2D,common,math,B2Vec3)
HX_DECLARE_CLASS2(box2D,dynamics,B2TimeStep)
HX_DECLARE_CLASS3(box2D,dynamics,joints,B2Joint)
HX_DECLARE_CLASS3(box2D,dynamics,joints,B2JointDef)
HX_DECLARE_CLASS3(box2D,dynamics,joints,B2PrismaticJoint)
HX_DECLARE_CLASS3(box2D,dynamics,joints,B2PrismaticJointDef)
namespace box2D{
namespace dynamics{
namespace joints{


class B2PrismaticJoint_obj : public ::box2D::dynamics::joints::B2Joint_obj{
	public:
		typedef ::box2D::dynamics::joints::B2Joint_obj super;
		typedef B2PrismaticJoint_obj OBJ_;
		B2PrismaticJoint_obj();
		Void __construct(::box2D::dynamics::joints::B2PrismaticJointDef def);

	public:
		static hx::ObjectPtr< B2PrismaticJoint_obj > __new(::box2D::dynamics::joints::B2PrismaticJointDef def);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~B2PrismaticJoint_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("B2PrismaticJoint"); }

		virtual ::box2D::common::math::B2Vec2 getAnchorA( );
		Dynamic getAnchorA_dyn();

		virtual ::box2D::common::math::B2Vec2 getAnchorB( );
		Dynamic getAnchorB_dyn();

		virtual ::box2D::common::math::B2Vec2 getReactionForce( double inv_dt);
		Dynamic getReactionForce_dyn();

		virtual double getReactionTorque( double inv_dt);
		Dynamic getReactionTorque_dyn();

		virtual double getJointTranslation( );
		Dynamic getJointTranslation_dyn();

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

		virtual Void setMaxMotorForce( double force);
		Dynamic setMaxMotorForce_dyn();

		virtual double getMotorForce( );
		Dynamic getMotorForce_dyn();

		virtual Void initVelocityConstraints( ::box2D::dynamics::B2TimeStep step);
		Dynamic initVelocityConstraints_dyn();

		virtual Void solveVelocityConstraints( ::box2D::dynamics::B2TimeStep step);
		Dynamic solveVelocityConstraints_dyn();

		virtual bool solvePositionConstraints( double baumgarte);
		Dynamic solvePositionConstraints_dyn();

		::box2D::common::math::B2Vec2 m_localAnchor1; /* REM */ 
		::box2D::common::math::B2Vec2 m_localAnchor2; /* REM */ 
		::box2D::common::math::B2Vec2 m_localXAxis1; /* REM */ 
		::box2D::common::math::B2Vec2 m_localYAxis1; /* REM */ 
		double m_refAngle; /* REM */ 
		::box2D::common::math::B2Vec2 m_axis; /* REM */ 
		::box2D::common::math::B2Vec2 m_perp; /* REM */ 
		double m_s1; /* REM */ 
		double m_s2; /* REM */ 
		double m_a1; /* REM */ 
		double m_a2; /* REM */ 
		::box2D::common::math::B2Mat33 m_K; /* REM */ 
		::box2D::common::math::B2Vec3 m_impulse; /* REM */ 
		double m_motorMass; /* REM */ 
		double m_motorImpulse; /* REM */ 
		double m_lowerTranslation; /* REM */ 
		double m_upperTranslation; /* REM */ 
		double m_maxMotorForce; /* REM */ 
		double m_motorSpeed; /* REM */ 
		bool m_enableLimit; /* REM */ 
		bool m_enableMotor; /* REM */ 
		int m_limitState; /* REM */ 
};

} // end namespace box2D
} // end namespace dynamics
} // end namespace joints

#endif /* INCLUDED_box2D_dynamics_joints_B2PrismaticJoint */ 
