#ifndef INCLUDED_box2D_dynamics_joints_B2MouseJoint
#define INCLUDED_box2D_dynamics_joints_B2MouseJoint

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <box2D/dynamics/joints/B2Joint.h>
HX_DECLARE_CLASS3(box2D,common,math,B2Mat22)
HX_DECLARE_CLASS3(box2D,common,math,B2Vec2)
HX_DECLARE_CLASS2(box2D,dynamics,B2TimeStep)
HX_DECLARE_CLASS3(box2D,dynamics,joints,B2Joint)
HX_DECLARE_CLASS3(box2D,dynamics,joints,B2JointDef)
HX_DECLARE_CLASS3(box2D,dynamics,joints,B2MouseJoint)
HX_DECLARE_CLASS3(box2D,dynamics,joints,B2MouseJointDef)
namespace box2D{
namespace dynamics{
namespace joints{


class B2MouseJoint_obj : public ::box2D::dynamics::joints::B2Joint_obj{
	public:
		typedef ::box2D::dynamics::joints::B2Joint_obj super;
		typedef B2MouseJoint_obj OBJ_;
		B2MouseJoint_obj();
		Void __construct(::box2D::dynamics::joints::B2MouseJointDef def);

	public:
		static hx::ObjectPtr< B2MouseJoint_obj > __new(::box2D::dynamics::joints::B2MouseJointDef def);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~B2MouseJoint_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("B2MouseJoint"); }

		virtual ::box2D::common::math::B2Vec2 getAnchorA( );
		Dynamic getAnchorA_dyn();

		virtual ::box2D::common::math::B2Vec2 getAnchorB( );
		Dynamic getAnchorB_dyn();

		virtual ::box2D::common::math::B2Vec2 getReactionForce( double inv_dt);
		Dynamic getReactionForce_dyn();

		virtual double getReactionTorque( double inv_dt);
		Dynamic getReactionTorque_dyn();

		virtual ::box2D::common::math::B2Vec2 getTarget( );
		Dynamic getTarget_dyn();

		virtual Void setTarget( ::box2D::common::math::B2Vec2 target);
		Dynamic setTarget_dyn();

		virtual double getMaxForce( );
		Dynamic getMaxForce_dyn();

		virtual Void setMaxForce( double maxForce);
		Dynamic setMaxForce_dyn();

		virtual double getFrequency( );
		Dynamic getFrequency_dyn();

		virtual Void setFrequency( double hz);
		Dynamic setFrequency_dyn();

		virtual double getDampingRatio( );
		Dynamic getDampingRatio_dyn();

		virtual Void setDampingRatio( double ratio);
		Dynamic setDampingRatio_dyn();

		::box2D::common::math::B2Mat22 K; /* REM */ 
		::box2D::common::math::B2Mat22 K1; /* REM */ 
		::box2D::common::math::B2Mat22 K2; /* REM */ 
		virtual Void initVelocityConstraints( ::box2D::dynamics::B2TimeStep step);
		Dynamic initVelocityConstraints_dyn();

		virtual Void solveVelocityConstraints( ::box2D::dynamics::B2TimeStep step);
		Dynamic solveVelocityConstraints_dyn();

		virtual bool solvePositionConstraints( double baumgarte);
		Dynamic solvePositionConstraints_dyn();

		::box2D::common::math::B2Vec2 m_localAnchor; /* REM */ 
		::box2D::common::math::B2Vec2 m_target; /* REM */ 
		::box2D::common::math::B2Vec2 m_impulse; /* REM */ 
		::box2D::common::math::B2Mat22 m_mass; /* REM */ 
		::box2D::common::math::B2Vec2 m_C; /* REM */ 
		double m_maxForce; /* REM */ 
		double m_frequencyHz; /* REM */ 
		double m_dampingRatio; /* REM */ 
		double m_beta; /* REM */ 
		double m_gamma; /* REM */ 
};

} // end namespace box2D
} // end namespace dynamics
} // end namespace joints

#endif /* INCLUDED_box2D_dynamics_joints_B2MouseJoint */ 
