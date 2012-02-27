#ifndef INCLUDED_box2D_dynamics_B2TimeStep
#define INCLUDED_box2D_dynamics_B2TimeStep

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(box2D,dynamics,B2TimeStep)
namespace box2D{
namespace dynamics{


class B2TimeStep_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef B2TimeStep_obj OBJ_;
		B2TimeStep_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< B2TimeStep_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~B2TimeStep_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("B2TimeStep"); }

		virtual Void set( ::box2D::dynamics::B2TimeStep step);
		Dynamic set_dyn();

		double dt; /* REM */ 
		double inv_dt; /* REM */ 
		double dtRatio; /* REM */ 
		int velocityIterations; /* REM */ 
		int positionIterations; /* REM */ 
		bool warmStarting; /* REM */ 
};

} // end namespace box2D
} // end namespace dynamics

#endif /* INCLUDED_box2D_dynamics_B2TimeStep */ 
