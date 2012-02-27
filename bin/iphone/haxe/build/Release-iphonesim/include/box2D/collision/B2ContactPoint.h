#ifndef INCLUDED_box2D_collision_B2ContactPoint
#define INCLUDED_box2D_collision_B2ContactPoint

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(box2D,collision,B2ContactID)
HX_DECLARE_CLASS2(box2D,collision,B2ContactPoint)
HX_DECLARE_CLASS3(box2D,collision,shapes,B2Shape)
HX_DECLARE_CLASS3(box2D,common,math,B2Vec2)
namespace box2D{
namespace collision{


class B2ContactPoint_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef B2ContactPoint_obj OBJ_;
		B2ContactPoint_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< B2ContactPoint_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~B2ContactPoint_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("B2ContactPoint"); }

		::box2D::collision::shapes::B2Shape shape1; /* REM */ 
		::box2D::collision::shapes::B2Shape shape2; /* REM */ 
		::box2D::common::math::B2Vec2 position; /* REM */ 
		::box2D::common::math::B2Vec2 velocity; /* REM */ 
		::box2D::common::math::B2Vec2 normal; /* REM */ 
		double separation; /* REM */ 
		double friction; /* REM */ 
		double restitution; /* REM */ 
		::box2D::collision::B2ContactID id; /* REM */ 
};

} // end namespace box2D
} // end namespace collision

#endif /* INCLUDED_box2D_collision_B2ContactPoint */ 
