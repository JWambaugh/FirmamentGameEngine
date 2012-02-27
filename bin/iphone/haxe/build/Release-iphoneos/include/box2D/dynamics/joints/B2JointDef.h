#ifndef INCLUDED_box2D_dynamics_joints_B2JointDef
#define INCLUDED_box2D_dynamics_joints_B2JointDef

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(box2D,dynamics,B2Body)
HX_DECLARE_CLASS3(box2D,dynamics,joints,B2JointDef)
namespace box2D{
namespace dynamics{
namespace joints{


class B2JointDef_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef B2JointDef_obj OBJ_;
		B2JointDef_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< B2JointDef_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~B2JointDef_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("B2JointDef"); }

		int type; /* REM */ 
		Dynamic userData; /* REM */ 
		::box2D::dynamics::B2Body bodyA; /* REM */ 
		::box2D::dynamics::B2Body bodyB; /* REM */ 
		bool collideConnected; /* REM */ 
};

} // end namespace box2D
} // end namespace dynamics
} // end namespace joints

#endif /* INCLUDED_box2D_dynamics_joints_B2JointDef */ 
