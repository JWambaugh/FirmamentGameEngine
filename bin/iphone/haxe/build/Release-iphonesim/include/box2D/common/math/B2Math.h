#ifndef INCLUDED_box2D_common_math_B2Math
#define INCLUDED_box2D_common_math_B2Math

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(box2D,common,math,B2Mat22)
HX_DECLARE_CLASS3(box2D,common,math,B2Math)
HX_DECLARE_CLASS3(box2D,common,math,B2Transform)
HX_DECLARE_CLASS3(box2D,common,math,B2Vec2)
namespace box2D{
namespace common{
namespace math{


class B2Math_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef B2Math_obj OBJ_;
		B2Math_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< B2Math_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~B2Math_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("B2Math"); }

		static bool isValid( double x);
		static Dynamic isValid_dyn();

		static double dot( ::box2D::common::math::B2Vec2 a,::box2D::common::math::B2Vec2 b);
		static Dynamic dot_dyn();

		static double crossVV( ::box2D::common::math::B2Vec2 a,::box2D::common::math::B2Vec2 b);
		static Dynamic crossVV_dyn();

		static ::box2D::common::math::B2Vec2 crossVF( ::box2D::common::math::B2Vec2 a,double s);
		static Dynamic crossVF_dyn();

		static ::box2D::common::math::B2Vec2 crossFV( double s,::box2D::common::math::B2Vec2 a);
		static Dynamic crossFV_dyn();

		static ::box2D::common::math::B2Vec2 mulMV( ::box2D::common::math::B2Mat22 A,::box2D::common::math::B2Vec2 v);
		static Dynamic mulMV_dyn();

		static ::box2D::common::math::B2Vec2 mulTMV( ::box2D::common::math::B2Mat22 A,::box2D::common::math::B2Vec2 v);
		static Dynamic mulTMV_dyn();

		static ::box2D::common::math::B2Vec2 mulX( ::box2D::common::math::B2Transform T,::box2D::common::math::B2Vec2 v);
		static Dynamic mulX_dyn();

		static ::box2D::common::math::B2Vec2 mulXT( ::box2D::common::math::B2Transform T,::box2D::common::math::B2Vec2 v);
		static Dynamic mulXT_dyn();

		static ::box2D::common::math::B2Vec2 addVV( ::box2D::common::math::B2Vec2 a,::box2D::common::math::B2Vec2 b);
		static Dynamic addVV_dyn();

		static ::box2D::common::math::B2Vec2 subtractVV( ::box2D::common::math::B2Vec2 a,::box2D::common::math::B2Vec2 b);
		static Dynamic subtractVV_dyn();

		static double distance( ::box2D::common::math::B2Vec2 a,::box2D::common::math::B2Vec2 b);
		static Dynamic distance_dyn();

		static double distanceSquared( ::box2D::common::math::B2Vec2 a,::box2D::common::math::B2Vec2 b);
		static Dynamic distanceSquared_dyn();

		static ::box2D::common::math::B2Vec2 mulFV( double s,::box2D::common::math::B2Vec2 a);
		static Dynamic mulFV_dyn();

		static ::box2D::common::math::B2Mat22 addMM( ::box2D::common::math::B2Mat22 A,::box2D::common::math::B2Mat22 B);
		static Dynamic addMM_dyn();

		static ::box2D::common::math::B2Mat22 mulMM( ::box2D::common::math::B2Mat22 A,::box2D::common::math::B2Mat22 B);
		static Dynamic mulMM_dyn();

		static ::box2D::common::math::B2Mat22 mulTMM( ::box2D::common::math::B2Mat22 A,::box2D::common::math::B2Mat22 B);
		static Dynamic mulTMM_dyn();

		static double abs( double a);
		static Dynamic abs_dyn();

		static ::box2D::common::math::B2Vec2 absV( ::box2D::common::math::B2Vec2 a);
		static Dynamic absV_dyn();

		static ::box2D::common::math::B2Mat22 absM( ::box2D::common::math::B2Mat22 A);
		static Dynamic absM_dyn();

		static double min( double a,double b);
		static Dynamic min_dyn();

		static ::box2D::common::math::B2Vec2 minV( ::box2D::common::math::B2Vec2 a,::box2D::common::math::B2Vec2 b);
		static Dynamic minV_dyn();

		static double max( double a,double b);
		static Dynamic max_dyn();

		static ::box2D::common::math::B2Vec2 maxV( ::box2D::common::math::B2Vec2 a,::box2D::common::math::B2Vec2 b);
		static Dynamic maxV_dyn();

		static double clamp( double a,double low,double high);
		static Dynamic clamp_dyn();

		static ::box2D::common::math::B2Vec2 clampV( ::box2D::common::math::B2Vec2 a,::box2D::common::math::B2Vec2 low,::box2D::common::math::B2Vec2 high);
		static Dynamic clampV_dyn();

		static Void swap( Dynamic a,Dynamic b);
		static Dynamic swap_dyn();

		static double random( );
		static Dynamic random_dyn();

		static double randomRange( double lo,double hi);
		static Dynamic randomRange_dyn();

		static int nextPowerOfTwo( int x);
		static Dynamic nextPowerOfTwo_dyn();

		static bool isPowerOfTwo( int x);
		static Dynamic isPowerOfTwo_dyn();

		static ::box2D::common::math::B2Vec2 b2Vec2_zero; /* REM */ 
		static ::box2D::common::math::B2Mat22 b2Mat22_identity; /* REM */ 
		static ::box2D::common::math::B2Transform b2Transform_identity; /* REM */ 
		static double MIN_VALUE; /* REM */ 
		static double MAX_VALUE; /* REM */ 
};

} // end namespace box2D
} // end namespace common
} // end namespace math

#endif /* INCLUDED_box2D_common_math_B2Math */ 
