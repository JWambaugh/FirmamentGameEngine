#ifndef INCLUDED_box2D_dynamics_joints_B2DistanceJoint
#define INCLUDED_box2D_dynamics_joints_B2DistanceJoint

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <box2D/dynamics/joints/B2Joint.h>
HX_DECLARE_CLASS3(box2D,common,math,B2Vec2)
HX_DECLARE_CLASS2(box2D,dynamics,B2TimeStep)
HX_DECLARE_CLASS3(box2D,dynamics,joints,B2DistanceJoint)
HX_DECLARE_CLASS3(box2D,dynamics,joints,B2DistanceJointDef)
HX_DECLARE_CLASS3(box2D,dynamics,joints,B2Joint)
HX_DECLARE_CLASS3(box2D,dynamics,joints,B2JointDef)
namespace box2D{
namespace dynamics{
namespace joints{


class B2DistanceJoint_obj : public ::box2D::dynamics::joints::B2Joint_obj{
	public:
		typedef ::box2D::dynamics::joints::B2Joint_obj super;
		typedef B2DistanceJoint_obj OBJ_;
		B2DistanceJoint_obj();
		Void __construct(::box2D::dynamics::joints::B2DistanceJointDef def);

	public:
		static hx::ObjectPtr< B2DistanceJoint_obj > __new(::box2D::dynamics::joints::B2DistanceJointDef def);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~B2DistanceJoint_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("B2DistanceJoint"); }

		virtual ::box2D::common::math::B2Vec2 getAnchorA( );
		Dynamic getAnchorA_dyn();

		virtual ::box2D::common::math::B2Vec2 getAnchorB( );
		Dynamic getAnchorB_dyn();

		virtual ::box2D::common::math::B2Vec2 getReactionForce( double inv_dt);
		Dynamic getReactionForce_dyn();

		virtual double getReactionTorque( double inv_dt);
		Dynamic getReactionTorque_dyn();

		virtual double getLength( );
		Dynamic getLength_dyn();

		virtual Void setLength( double length);
		Dynamic setLength_dyn();

		virtual double getFrequency( );
		Dynamic getFrequency_dyn();

		virtual Void setFrequency( double hz);
		Dynamic setFrequency_dyn();

		virtual double getDampingRatio( );
		Dynamic getDampingRatio_dyn();

		virtual Void setDampingRatio( double ratio);
		Dynamic setDampingRatio_dyn();

		virtual Void initVelocityConstraints( ::box2D::dynamics::B2TimeStep step);
		Dynamic initVelocityConstraints_dyn();

		virtual Void solveVelocityConstraints( ::box2D::dynamics::B2TimeStep step);
		Dynamic solveVelocityConstraints_dyn();

		virtual bool solvePositionConstraints( double baumgarte);
		Dynamic solvePositionConstraints_dyn();

		::box2D::common::math::B2Vec2 m_localAnchor1; /* REM */ 
		::box2D::common::math::B2Vec2 m_localAnchor2; /* REM */ 
		::box2D::common::math::B2Vec2 m_u; /* REM */ 
		double m_frequencyHz; /* REM */ 
		double m_dampingRatio; /* REM */ 
		double m_gamma; /* REM */ 
		double m_bias; /* REM */ 
		double m_impulse; /* REM */ 
		double m_mass; /* REM */ 
		double m_length; /* REM */ 
};

} // end namespace box2D
} // end namespace dynamics
} // end namespace joints

#endif /* INCLUDED_box2D_dynamics_joints_B2DistanceJoint */ 
