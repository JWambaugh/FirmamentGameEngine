#ifndef INCLUDED_box2D_dynamics_joints_B2Jacobian
#define INCLUDED_box2D_dynamics_joints_B2Jacobian

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(box2D,common,math,B2Vec2)
HX_DECLARE_CLASS3(box2D,dynamics,joints,B2Jacobian)
namespace box2D{
namespace dynamics{
namespace joints{


class B2Jacobian_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef B2Jacobian_obj OBJ_;
		B2Jacobian_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< B2Jacobian_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~B2Jacobian_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("B2Jacobian"); }

		::box2D::common::math::B2Vec2 linearA; /* REM */ 
		double angularA; /* REM */ 
		::box2D::common::math::B2Vec2 linearB; /* REM */ 
		double angularB; /* REM */ 
		virtual Void setZero( );
		Dynamic setZero_dyn();

		virtual Void set( ::box2D::common::math::B2Vec2 x1,double a1,::box2D::common::math::B2Vec2 x2,double a2);
		Dynamic set_dyn();

		virtual double compute( ::box2D::common::math::B2Vec2 x1,double a1,::box2D::common::math::B2Vec2 x2,double a2);
		Dynamic compute_dyn();

};

} // end namespace box2D
} // end namespace dynamics
} // end namespace joints

#endif /* INCLUDED_box2D_dynamics_joints_B2Jacobian */ 
