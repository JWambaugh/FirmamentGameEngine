#ifndef INCLUDED_box2D_dynamics_joints_B2PulleyJointDef
#define INCLUDED_box2D_dynamics_joints_B2PulleyJointDef

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <box2D/dynamics/joints/B2JointDef.h>
HX_DECLARE_CLASS3(box2D,common,math,B2Vec2)
HX_DECLARE_CLASS2(box2D,dynamics,B2Body)
HX_DECLARE_CLASS3(box2D,dynamics,joints,B2JointDef)
HX_DECLARE_CLASS3(box2D,dynamics,joints,B2PulleyJointDef)
namespace box2D{
namespace dynamics{
namespace joints{


class B2PulleyJointDef_obj : public ::box2D::dynamics::joints::B2JointDef_obj{
	public:
		typedef ::box2D::dynamics::joints::B2JointDef_obj super;
		typedef B2PulleyJointDef_obj OBJ_;
		B2PulleyJointDef_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< B2PulleyJointDef_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~B2PulleyJointDef_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("B2PulleyJointDef"); }

		virtual Void initialize( ::box2D::dynamics::B2Body bA,::box2D::dynamics::B2Body bB,::box2D::common::math::B2Vec2 gaA,::box2D::common::math::B2Vec2 gaB,::box2D::common::math::B2Vec2 anchorA,::box2D::common::math::B2Vec2 anchorB,double r);
		Dynamic initialize_dyn();

		::box2D::common::math::B2Vec2 groundAnchorA; /* REM */ 
		::box2D::common::math::B2Vec2 groundAnchorB; /* REM */ 
		::box2D::common::math::B2Vec2 localAnchorA; /* REM */ 
		::box2D::common::math::B2Vec2 localAnchorB; /* REM */ 
		double lengthA; /* REM */ 
		double maxLengthA; /* REM */ 
		double lengthB; /* REM */ 
		double maxLengthB; /* REM */ 
		double ratio; /* REM */ 
};

} // end namespace box2D
} // end namespace dynamics
} // end namespace joints

#endif /* INCLUDED_box2D_dynamics_joints_B2PulleyJointDef */ 
