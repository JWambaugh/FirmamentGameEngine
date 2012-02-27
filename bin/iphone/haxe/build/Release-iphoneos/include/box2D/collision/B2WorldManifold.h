#ifndef INCLUDED_box2D_collision_B2WorldManifold
#define INCLUDED_box2D_collision_B2WorldManifold

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(box2D,collision,B2Manifold)
HX_DECLARE_CLASS2(box2D,collision,B2WorldManifold)
HX_DECLARE_CLASS3(box2D,common,math,B2Transform)
HX_DECLARE_CLASS3(box2D,common,math,B2Vec2)
namespace box2D{
namespace collision{


class B2WorldManifold_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef B2WorldManifold_obj OBJ_;
		B2WorldManifold_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< B2WorldManifold_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~B2WorldManifold_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("B2WorldManifold"); }

		virtual Void initialize( ::box2D::collision::B2Manifold manifold,::box2D::common::math::B2Transform xfA,double radiusA,::box2D::common::math::B2Transform xfB,double radiusB);
		Dynamic initialize_dyn();

		::box2D::common::math::B2Vec2 m_normal; /* REM */ 
		Array< ::box2D::common::math::B2Vec2 > m_points; /* REM */ 
};

} // end namespace box2D
} // end namespace collision

#endif /* INCLUDED_box2D_collision_B2WorldManifold */ 
