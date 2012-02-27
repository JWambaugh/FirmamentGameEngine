#ifndef INCLUDED_box2D_common_math_B2Sweep
#define INCLUDED_box2D_common_math_B2Sweep

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(box2D,common,math,B2Sweep)
HX_DECLARE_CLASS3(box2D,common,math,B2Transform)
HX_DECLARE_CLASS3(box2D,common,math,B2Vec2)
namespace box2D{
namespace common{
namespace math{


class B2Sweep_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef B2Sweep_obj OBJ_;
		B2Sweep_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< B2Sweep_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~B2Sweep_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("B2Sweep"); }

		virtual Void set( ::box2D::common::math::B2Sweep other);
		Dynamic set_dyn();

		virtual ::box2D::common::math::B2Sweep copy( );
		Dynamic copy_dyn();

		virtual Void getTransform( ::box2D::common::math::B2Transform xf,double alpha);
		Dynamic getTransform_dyn();

		virtual Void advance( double t);
		Dynamic advance_dyn();

		::box2D::common::math::B2Vec2 localCenter; /* REM */ 
		::box2D::common::math::B2Vec2 c0; /* REM */ 
		::box2D::common::math::B2Vec2 c; /* REM */ 
		double a0; /* REM */ 
		double a; /* REM */ 
		double t0; /* REM */ 
};

} // end namespace box2D
} // end namespace common
} // end namespace math

#endif /* INCLUDED_box2D_common_math_B2Sweep */ 
