#ifndef INCLUDED_box2D_dynamics_controllers_B2Controller
#define INCLUDED_box2D_dynamics_controllers_B2Controller

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(box2D,dynamics,B2Body)
HX_DECLARE_CLASS2(box2D,dynamics,B2DebugDraw)
HX_DECLARE_CLASS2(box2D,dynamics,B2TimeStep)
HX_DECLARE_CLASS2(box2D,dynamics,B2World)
HX_DECLARE_CLASS3(box2D,dynamics,controllers,B2Controller)
HX_DECLARE_CLASS3(box2D,dynamics,controllers,B2ControllerEdge)
namespace box2D{
namespace dynamics{
namespace controllers{


class B2Controller_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef B2Controller_obj OBJ_;
		B2Controller_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< B2Controller_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~B2Controller_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("B2Controller"); }

		virtual Void step( ::box2D::dynamics::B2TimeStep step);
		Dynamic step_dyn();

		virtual Void draw( ::box2D::dynamics::B2DebugDraw debugDraw);
		Dynamic draw_dyn();

		virtual Void addBody( ::box2D::dynamics::B2Body body);
		Dynamic addBody_dyn();

		virtual Void removeBody( ::box2D::dynamics::B2Body body);
		Dynamic removeBody_dyn();

		virtual Void clear( );
		Dynamic clear_dyn();

		virtual ::box2D::dynamics::controllers::B2Controller getNext( );
		Dynamic getNext_dyn();

		virtual ::box2D::dynamics::B2World getWorld( );
		Dynamic getWorld_dyn();

		virtual ::box2D::dynamics::controllers::B2ControllerEdge getBodyList( );
		Dynamic getBodyList_dyn();

		::box2D::dynamics::controllers::B2Controller m_next; /* REM */ 
		::box2D::dynamics::controllers::B2Controller m_prev; /* REM */ 
		::box2D::dynamics::controllers::B2ControllerEdge m_bodyList; /* REM */ 
		int m_bodyCount; /* REM */ 
		::box2D::dynamics::B2World m_world; /* REM */ 
};

} // end namespace box2D
} // end namespace dynamics
} // end namespace controllers

#endif /* INCLUDED_box2D_dynamics_controllers_B2Controller */ 
