#ifndef INCLUDED_box2D_collision_B2AABB
#define INCLUDED_box2D_collision_B2AABB

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(box2D,collision,B2AABB)
HX_DECLARE_CLASS2(box2D,collision,B2RayCastInput)
HX_DECLARE_CLASS2(box2D,collision,B2RayCastOutput)
HX_DECLARE_CLASS3(box2D,common,math,B2Vec2)
namespace box2D{
namespace collision{


class B2AABB_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef B2AABB_obj OBJ_;
		B2AABB_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< B2AABB_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~B2AABB_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("B2AABB"); }

		virtual bool isValid( );
		Dynamic isValid_dyn();

		virtual ::box2D::common::math::B2Vec2 getCenter( );
		Dynamic getCenter_dyn();

		virtual ::box2D::common::math::B2Vec2 getExtents( );
		Dynamic getExtents_dyn();

		virtual bool contains( ::box2D::collision::B2AABB aabb);
		Dynamic contains_dyn();

		virtual bool rayCast( ::box2D::collision::B2RayCastOutput output,::box2D::collision::B2RayCastInput input);
		Dynamic rayCast_dyn();

		virtual bool testOverlap( ::box2D::collision::B2AABB other);
		Dynamic testOverlap_dyn();

		virtual Void combine( ::box2D::collision::B2AABB aabb1,::box2D::collision::B2AABB aabb2);
		Dynamic combine_dyn();

		::box2D::common::math::B2Vec2 lowerBound; /* REM */ 
		::box2D::common::math::B2Vec2 upperBound; /* REM */ 
};

} // end namespace box2D
} // end namespace collision

#endif /* INCLUDED_box2D_collision_B2AABB */ 
