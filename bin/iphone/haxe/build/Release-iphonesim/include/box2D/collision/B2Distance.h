#ifndef INCLUDED_box2D_collision_B2Distance
#define INCLUDED_box2D_collision_B2Distance

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(box2D,collision,B2Distance)
HX_DECLARE_CLASS2(box2D,collision,B2DistanceInput)
HX_DECLARE_CLASS2(box2D,collision,B2DistanceOutput)
HX_DECLARE_CLASS2(box2D,collision,B2Simplex)
HX_DECLARE_CLASS2(box2D,collision,B2SimplexCache)
namespace box2D{
namespace collision{


class B2Distance_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef B2Distance_obj OBJ_;
		B2Distance_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< B2Distance_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~B2Distance_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("B2Distance"); }

		static int b2_gjkCalls; /* REM */ 
		static int b2_gjkIters; /* REM */ 
		static int b2_gjkMaxIters; /* REM */ 
		static ::box2D::collision::B2Simplex s_simplex; /* REM */ 
		static Array< int > s_saveA; /* REM */ 
		static Array< int > s_saveB; /* REM */ 
		static Void distance( ::box2D::collision::B2DistanceOutput output,::box2D::collision::B2SimplexCache cache,::box2D::collision::B2DistanceInput input);
		static Dynamic distance_dyn();

};

} // end namespace box2D
} // end namespace collision

#endif /* INCLUDED_box2D_collision_B2Distance */ 
