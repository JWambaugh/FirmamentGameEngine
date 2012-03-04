#ifndef INCLUDED_box2D_dynamics_joints_B2GearJoint
#define INCLUDED_box2D_dynamics_joints_B2GearJoint

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <box2D/dynamics/joints/B2Joint.h>
HX_DECLARE_CLASS3(box2D,common,math,B2Vec2)
HX_DECLARE_CLASS2(box2D,dynamics,B2Body)
HX_DECLARE_CLASS2(box2D,dynamics,B2TimeStep)
HX_DECLARE_CLASS3(box2D,dynamics,joints,B2GearJoint)
HX_DECLARE_CLASS3(box2D,dynamics,joints,B2GearJointDef)
HX_DECLARE_CLASS3(box2D,dynamics,joints,B2Jacobian)
HX_DECLARE_CLASS3(box2D,dynamics,joints,B2Joint)
HX_DECLARE_CLASS3(box2D,dynamics,joints,B2JointDef)
HX_DECLARE_CLASS3(box2D,dynamics,joints,B2PrismaticJoint)
HX_DECLARE_CLASS3(box2D,dynamics,joints,B2RevoluteJoint)
namespace box2D{
namespace dynamics{
namespace joints{


class B2GearJoint_obj : public ::box2D::dynamics::joints::B2Joint_obj{
	public:
		typedef ::box2D::dynamics::joints::B2Joint_obj super;
		typedef B2GearJoint_obj OBJ_;
		B2GearJoint_obj();
		Void __construct(::box2D::dynamics::joints::B2GearJointDef def);

	public:
		static hx::ObjectPtr< B2GearJoint_obj > __new(::box2D::dynamics::joints::B2GearJointDef def);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~B2GearJoint_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("B2GearJoint"); }

		virtual ::box2D::common::math::B2Vec2 getAnchorA( );
		Dynamic getAnchorA_dyn();

		virtual ::box2D::common::math::B2Vec2 getAnchorB( );
		Dynamic getAnchorB_dyn();

		virtual ::box2D::common::math::B2Vec2 getReactionForce( double inv_dt);
		Dynamic getReactionForce_dyn();

		virtual double getReactionTorque( double inv_dt);
		Dynamic getReactionTorque_dyn();

		virtual double getRatio( );
		Dynamic getRatio_dyn();

		virtual Void setRatio( double ratio);
		Dynamic setRatio_dyn();

		virtual Void initVelocityConstraints( ::box2D::dynamics::B2TimeStep step);
		Dynamic initVelocityConstraints_dyn();

		virtual Void solveVelocityConstraints( ::box2D::dynamics::B2TimeStep step);
		Dynamic solveVelocityConstraints_dyn();

		virtual bool solvePositionConstraints( double baumgarte);
		Dynamic solvePositionConstraints_dyn();

		::box2D::dynamics::B2Body m_ground1; /* REM */ 
		::box2D::dynamics::B2Body m_ground2; /* REM */ 
		::box2D::dynamics::joints::B2RevoluteJoint m_revolute1; /* REM */ 
		::box2D::dynamics::joints::B2PrismaticJoint m_prismatic1; /* REM */ 
		::box2D::dynamics::joints::B2RevoluteJoint m_revolute2; /* REM */ 
		::box2D::dynamics::joints::B2PrismaticJoint m_prismatic2; /* REM */ 
		::box2D::common::math::B2Vec2 m_groundAnchor1; /* REM */ 
		::box2D::common::math::B2Vec2 m_groundAnchor2; /* REM */ 
		::box2D::common::math::B2Vec2 m_localAnchor1; /* REM */ 
		::box2D::common::math::B2Vec2 m_localAnchor2; /* REM */ 
		::box2D::dynamics::joints::B2Jacobian m_J; /* REM */ 
		double m_constant; /* REM */ 
		double m_ratio; /* REM */ 
		double m_mass; /* REM */ 
		double m_impulse; /* REM */ 
};

} // end namespace box2D
} // end namespace dynamics
} // end namespace joints

#endif /* INCLUDED_box2D_dynamics_joints_B2GearJoint */ 
