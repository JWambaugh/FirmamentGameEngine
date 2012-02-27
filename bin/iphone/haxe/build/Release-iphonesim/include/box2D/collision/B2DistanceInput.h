#ifndef INCLUDED_box2D_collision_B2DistanceInput
#define INCLUDED_box2D_collision_B2DistanceInput

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(box2D,collision,B2DistanceInput)
HX_DECLARE_CLASS2(box2D,collision,B2DistanceProxy)
HX_DECLARE_CLASS3(box2D,common,math,B2Transform)
namespace box2D{
namespace collision{


class B2DistanceInput_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef B2DistanceInput_obj OBJ_;
		B2DistanceInput_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< B2DistanceInput_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~B2DistanceInput_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("B2DistanceInput"); }

		::box2D::collision::B2DistanceProxy proxyA; /* REM */ 
		::box2D::collision::B2DistanceProxy proxyB; /* REM */ 
		::box2D::common::math::B2Transform transformA; /* REM */ 
		::box2D::common::math::B2Transform transformB; /* REM */ 
		bool useRadii; /* REM */ 
};

} // end namespace box2D
} // end namespace collision

#endif /* INCLUDED_box2D_collision_B2DistanceInput */ 
