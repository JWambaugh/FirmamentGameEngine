#ifndef INCLUDED_box2D_dynamics_B2Island
#define INCLUDED_box2D_dynamics_B2Island

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(box2D,common,math,B2Vec2)
HX_DECLARE_CLASS2(box2D,dynamics,B2Body)
HX_DECLARE_CLASS2(box2D,dynamics,B2ContactImpulse)
HX_DECLARE_CLASS2(box2D,dynamics,B2ContactListener)
HX_DECLARE_CLASS2(box2D,dynamics,B2Island)
HX_DECLARE_CLASS2(box2D,dynamics,B2TimeStep)
HX_DECLARE_CLASS3(box2D,dynamics,contacts,B2Contact)
HX_DECLARE_CLASS3(box2D,dynamics,contacts,B2ContactConstraint)
HX_DECLARE_CLASS3(box2D,dynamics,contacts,B2ContactSolver)
HX_DECLARE_CLASS3(box2D,dynamics,joints,B2Joint)
namespace box2D{
namespace dynamics{


class B2Island_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef B2Island_obj OBJ_;
		B2Island_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< B2Island_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~B2Island_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("B2Island"); }

		virtual Void initialize( int bodyCapacity,int contactCapacity,int jointCapacity,Dynamic allocator,::box2D::dynamics::B2ContactListener listener,::box2D::dynamics::contacts::B2ContactSolver contactSolver);
		Dynamic initialize_dyn();

		virtual Void clear( );
		Dynamic clear_dyn();

		virtual Void solve( ::box2D::dynamics::B2TimeStep step,::box2D::common::math::B2Vec2 gravity,bool allowSleep);
		Dynamic solve_dyn();

		virtual Void solveTOI( ::box2D::dynamics::B2TimeStep subStep);
		Dynamic solveTOI_dyn();

		virtual Void report( Array< ::box2D::dynamics::contacts::B2ContactConstraint > constraints);
		Dynamic report_dyn();

		virtual Void addBody( ::box2D::dynamics::B2Body body);
		Dynamic addBody_dyn();

		virtual Void addContact( ::box2D::dynamics::contacts::B2Contact contact);
		Dynamic addContact_dyn();

		virtual Void addJoint( ::box2D::dynamics::joints::B2Joint joint);
		Dynamic addJoint_dyn();

		Dynamic m_allocator; /* REM */ 
		::box2D::dynamics::B2ContactListener m_listener; /* REM */ 
		::box2D::dynamics::contacts::B2ContactSolver m_contactSolver; /* REM */ 
		Array< ::box2D::dynamics::B2Body > m_bodies; /* REM */ 
		Array< ::box2D::dynamics::contacts::B2Contact > m_contacts; /* REM */ 
		Array< ::box2D::dynamics::joints::B2Joint > m_joints; /* REM */ 
		int m_bodyCount; /* REM */ 
		int m_jointCount; /* REM */ 
		int m_contactCount; /* REM */ 
		int m_bodyCapacity; /* REM */ 
		int m_contactCapacity; /* REM */ 
		int m_jointCapacity; /* REM */ 
		static ::box2D::dynamics::B2ContactImpulse s_impulse; /* REM */ 
};

} // end namespace box2D
} // end namespace dynamics

#endif /* INCLUDED_box2D_dynamics_B2Island */ 
