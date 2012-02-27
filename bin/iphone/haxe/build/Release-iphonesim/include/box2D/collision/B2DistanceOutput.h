#ifndef INCLUDED_box2D_collision_B2DistanceOutput
#define INCLUDED_box2D_collision_B2DistanceOutput

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(box2D,collision,B2DistanceOutput)
HX_DECLARE_CLASS3(box2D,common,math,B2Vec2)
namespace box2D{
namespace collision{


class B2DistanceOutput_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef B2DistanceOutput_obj OBJ_;
		B2DistanceOutput_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< B2DistanceOutput_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~B2DistanceOutput_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("B2DistanceOutput"); }

		::box2D::common::math::B2Vec2 pointA; /* REM */ 
		::box2D::common::math::B2Vec2 pointB; /* REM */ 
		double distance; /* REM */ 
		int iterations; /* REM */ 
};

} // end namespace box2D
} // end namespace collision

#endif /* INCLUDED_box2D_collision_B2DistanceOutput */ 
