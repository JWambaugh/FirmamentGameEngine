#ifndef INCLUDED_box2D_collision_B2TimeOfImpact
#define INCLUDED_box2D_collision_B2TimeOfImpact

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(box2D,collision,B2DistanceInput)
HX_DECLARE_CLASS2(box2D,collision,B2DistanceOutput)
HX_DECLARE_CLASS2(box2D,collision,B2SeparationFunction)
HX_DECLARE_CLASS2(box2D,collision,B2SimplexCache)
HX_DECLARE_CLASS2(box2D,collision,B2TOIInput)
HX_DECLARE_CLASS2(box2D,collision,B2TimeOfImpact)
HX_DECLARE_CLASS3(box2D,common,math,B2Transform)
namespace box2D{
namespace collision{


class B2TimeOfImpact_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef B2TimeOfImpact_obj OBJ_;
		B2TimeOfImpact_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< B2TimeOfImpact_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~B2TimeOfImpact_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("B2TimeOfImpact"); }

		static int b2_toiCalls; /* REM */ 
		static int b2_toiIters; /* REM */ 
		static int b2_toiMaxIters; /* REM */ 
		static int b2_toiRootIters; /* REM */ 
		static int b2_toiMaxRootIters; /* REM */ 
		static ::box2D::collision::B2SimplexCache s_cache; /* REM */ 
		static ::box2D::collision::B2DistanceInput s_distanceInput; /* REM */ 
		static ::box2D::common::math::B2Transform s_xfA; /* REM */ 
		static ::box2D::common::math::B2Transform s_xfB; /* REM */ 
		static ::box2D::collision::B2SeparationFunction s_fcn; /* REM */ 
		static ::box2D::collision::B2DistanceOutput s_distanceOutput; /* REM */ 
		static double timeOfImpact( ::box2D::collision::B2TOIInput input);
		static Dynamic timeOfImpact_dyn();

};

} // end namespace box2D
} // end namespace collision

#endif /* INCLUDED_box2D_collision_B2TimeOfImpact */ 
