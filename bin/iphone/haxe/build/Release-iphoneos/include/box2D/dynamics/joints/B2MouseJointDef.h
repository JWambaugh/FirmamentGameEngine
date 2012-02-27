#ifndef INCLUDED_box2D_dynamics_joints_B2MouseJointDef
#define INCLUDED_box2D_dynamics_joints_B2MouseJointDef

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <box2D/dynamics/joints/B2JointDef.h>
HX_DECLARE_CLASS3(box2D,common,math,B2Vec2)
HX_DECLARE_CLASS3(box2D,dynamics,joints,B2JointDef)
HX_DECLARE_CLASS3(box2D,dynamics,joints,B2MouseJointDef)
namespace box2D{
namespace dynamics{
namespace joints{


class B2MouseJointDef_obj : public ::box2D::dynamics::joints::B2JointDef_obj{
	public:
		typedef ::box2D::dynamics::joints::B2JointDef_obj super;
		typedef B2MouseJointDef_obj OBJ_;
		B2MouseJointDef_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< B2MouseJointDef_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~B2MouseJointDef_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("B2MouseJointDef"); }

		::box2D::common::math::B2Vec2 target; /* REM */ 
		double maxForce; /* REM */ 
		double frequencyHz; /* REM */ 
		double dampingRatio; /* REM */ 
};

} // end namespace box2D
} // end namespace dynamics
} // end namespace joints

#endif /* INCLUDED_box2D_dynamics_joints_B2MouseJointDef */ 
