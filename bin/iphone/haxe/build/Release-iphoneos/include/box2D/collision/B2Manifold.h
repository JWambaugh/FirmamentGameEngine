#ifndef INCLUDED_box2D_collision_B2Manifold
#define INCLUDED_box2D_collision_B2Manifold

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(box2D,collision,B2Manifold)
HX_DECLARE_CLASS2(box2D,collision,B2ManifoldPoint)
HX_DECLARE_CLASS3(box2D,common,math,B2Vec2)
namespace box2D{
namespace collision{


class B2Manifold_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef B2Manifold_obj OBJ_;
		B2Manifold_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< B2Manifold_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~B2Manifold_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("B2Manifold"); }

		virtual Void reset( );
		Dynamic reset_dyn();

		virtual Void set( ::box2D::collision::B2Manifold m);
		Dynamic set_dyn();

		virtual ::box2D::collision::B2Manifold copy( );
		Dynamic copy_dyn();

		Array< ::box2D::collision::B2ManifoldPoint > m_points; /* REM */ 
		::box2D::common::math::B2Vec2 m_localPlaneNormal; /* REM */ 
		::box2D::common::math::B2Vec2 m_localPoint; /* REM */ 
		int m_type; /* REM */ 
		int m_pointCount; /* REM */ 
		static int e_circles; /* REM */ 
		static int e_faceA; /* REM */ 
		static int e_faceB; /* REM */ 
};

} // end namespace box2D
} // end namespace collision

#endif /* INCLUDED_box2D_collision_B2Manifold */ 
