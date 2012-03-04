#ifndef INCLUDED_box2D_dynamics_controllers_B2ControllerEdge
#define INCLUDED_box2D_dynamics_controllers_B2ControllerEdge

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(box2D,dynamics,B2Body)
HX_DECLARE_CLASS3(box2D,dynamics,controllers,B2Controller)
HX_DECLARE_CLASS3(box2D,dynamics,controllers,B2ControllerEdge)
namespace box2D{
namespace dynamics{
namespace controllers{


class B2ControllerEdge_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef B2ControllerEdge_obj OBJ_;
		B2ControllerEdge_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< B2ControllerEdge_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~B2ControllerEdge_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("B2ControllerEdge"); }

		::box2D::dynamics::controllers::B2Controller controller; /* REM */ 
		::box2D::dynamics::B2Body body; /* REM */ 
		::box2D::dynamics::controllers::B2ControllerEdge prevBody; /* REM */ 
		::box2D::dynamics::controllers::B2ControllerEdge nextBody; /* REM */ 
		::box2D::dynamics::controllers::B2ControllerEdge prevController; /* REM */ 
		::box2D::dynamics::controllers::B2ControllerEdge nextController; /* REM */ 
};

} // end namespace box2D
} // end namespace dynamics
} // end namespace controllers

#endif /* INCLUDED_box2D_dynamics_controllers_B2ControllerEdge */ 
