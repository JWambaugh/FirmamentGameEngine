#ifndef INCLUDED_box2D_collision_B2RayCastInput
#define INCLUDED_box2D_collision_B2RayCastInput

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(box2D,collision,B2RayCastInput)
HX_DECLARE_CLASS3(box2D,common,math,B2Vec2)
namespace box2D{
namespace collision{


class B2RayCastInput_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef B2RayCastInput_obj OBJ_;
		B2RayCastInput_obj();
		Void __construct(::box2D::common::math::B2Vec2 p1,::box2D::common::math::B2Vec2 p2,Dynamic __o_maxFraction);

	public:
		static hx::ObjectPtr< B2RayCastInput_obj > __new(::box2D::common::math::B2Vec2 p1,::box2D::common::math::B2Vec2 p2,Dynamic __o_maxFraction);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~B2RayCastInput_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("B2RayCastInput"); }

		::box2D::common::math::B2Vec2 p1; /* REM */ 
		::box2D::common::math::B2Vec2 p2; /* REM */ 
		double maxFraction; /* REM */ 
};

} // end namespace box2D
} // end namespace collision

#endif /* INCLUDED_box2D_collision_B2RayCastInput */ 
