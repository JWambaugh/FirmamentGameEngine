#ifndef INCLUDED_box2D_dynamics_joints_B2Joint
#define INCLUDED_box2D_dynamics_joints_B2Joint

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(box2D,common,math,B2Vec2)
HX_DECLARE_CLASS2(box2D,dynamics,B2Body)
HX_DECLARE_CLASS2(box2D,dynamics,B2TimeStep)
HX_DECLARE_CLASS3(box2D,dynamics,joints,B2Joint)
HX_DECLARE_CLASS3(box2D,dynamics,joints,B2JointDef)
HX_DECLARE_CLASS3(box2D,dynamics,joints,B2JointEdge)
namespace box2D{
namespace dynamics{
namespace joints{


class B2Joint_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef B2Joint_obj OBJ_;
		B2Joint_obj();
		Void __construct(::box2D::dynamics::joints::B2JointDef def);

	public:
		static hx::ObjectPtr< B2Joint_obj > __new(::box2D::dynamics::joints::B2JointDef def);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~B2Joint_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("B2Joint"); }

		virtual int getType( );
		Dynamic getType_dyn();

		virtual ::box2D::common::math::B2Vec2 getAnchorA( );
		Dynamic getAnchorA_dyn();

		virtual ::box2D::common::math::B2Vec2 getAnchorB( );
		Dynamic getAnchorB_dyn();

		virtual ::box2D::common::math::B2Vec2 getReactionForce( double inv_dt);
		Dynamic getReactionForce_dyn();

		virtual double getReactionTorque( double inv_dt);
		Dynamic getReactionTorque_dyn();

		virtual ::box2D::dynamics::B2Body getBodyA( );
		Dynamic getBodyA_dyn();

		virtual ::box2D::dynamics::B2Body getBodyB( );
		Dynamic getBodyB_dyn();

		virtual ::box2D::dynamics::joints::B2Joint getNext( );
		Dynamic getNext_dyn();

		virtual Dynamic getUserData( );
		Dynamic getUserData_dyn();

		virtual Void setUserData( Dynamic data);
		Dynamic setUserData_dyn();

		virtual bool isActive( );
		Dynamic isActive_dyn();

		virtual Void initVelocityConstraints( ::box2D::dynamics::B2TimeStep step);
		Dynamic initVelocityConstraints_dyn();

		virtual Void solveVelocityConstraints( ::box2D::dynamics::B2TimeStep step);
		Dynamic solveVelocityConstraints_dyn();

		virtual Void finalizeVelocityConstraints( );
		Dynamic finalizeVelocityConstraints_dyn();

		virtual bool solvePositionConstraints( double baumgarte);
		Dynamic solvePositionConstraints_dyn();

		int m_type; /* REM */ 
		::box2D::dynamics::joints::B2Joint m_prev; /* REM */ 
		::box2D::dynamics::joints::B2Joint m_next; /* REM */ 
		::box2D::dynamics::joints::B2JointEdge m_edgeA; /* REM */ 
		::box2D::dynamics::joints::B2JointEdge m_edgeB; /* REM */ 
		::box2D::dynamics::B2Body m_bodyA; /* REM */ 
		::box2D::dynamics::B2Body m_bodyB; /* REM */ 
		bool m_islandFlag; /* REM */ 
		bool m_collideConnected; /* REM */ 
		Dynamic m_userData; /* REM */ 
		::box2D::common::math::B2Vec2 m_localCenterA; /* REM */ 
		::box2D::common::math::B2Vec2 m_localCenterB; /* REM */ 
		double m_invMassA; /* REM */ 
		double m_invMassB; /* REM */ 
		double m_invIA; /* REM */ 
		double m_invIB; /* REM */ 
		static ::box2D::dynamics::joints::B2Joint create( ::box2D::dynamics::joints::B2JointDef def,Dynamic allocator);
		static Dynamic create_dyn();

		static Void destroy( ::box2D::dynamics::joints::B2Joint joint,Dynamic allocator);
		static Dynamic destroy_dyn();

		static int e_unknownJoint; /* REM */ 
		static int e_revoluteJoint; /* REM */ 
		static int e_prismaticJoint; /* REM */ 
		static int e_distanceJoint; /* REM */ 
		static int e_pulleyJoint; /* REM */ 
		static int e_mouseJoint; /* REM */ 
		static int e_gearJoint; /* REM */ 
		static int e_lineJoint; /* REM */ 
		static int e_weldJoint; /* REM */ 
		static int e_frictionJoint; /* REM */ 
		static int e_inactiveLimit; /* REM */ 
		static int e_atLowerLimit; /* REM */ 
		static int e_atUpperLimit; /* REM */ 
		static int e_equalLimits; /* REM */ 
};

} // end namespace box2D
} // end namespace dynamics
} // end namespace joints

#endif /* INCLUDED_box2D_dynamics_joints_B2Joint */ 
