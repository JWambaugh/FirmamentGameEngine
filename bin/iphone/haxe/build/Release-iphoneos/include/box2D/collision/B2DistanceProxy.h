#ifndef INCLUDED_box2D_collision_B2DistanceProxy
#define INCLUDED_box2D_collision_B2DistanceProxy

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(box2D,collision,B2DistanceProxy)
HX_DECLARE_CLASS3(box2D,collision,shapes,B2Shape)
HX_DECLARE_CLASS3(box2D,common,math,B2Vec2)
namespace box2D{
namespace collision{


class B2DistanceProxy_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef B2DistanceProxy_obj OBJ_;
		B2DistanceProxy_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< B2DistanceProxy_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~B2DistanceProxy_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("B2DistanceProxy"); }

		virtual Void set( ::box2D::collision::shapes::B2Shape shape);
		Dynamic set_dyn();

		virtual double getSupport( ::box2D::common::math::B2Vec2 d);
		Dynamic getSupport_dyn();

		virtual ::box2D::common::math::B2Vec2 getSupportVertex( ::box2D::common::math::B2Vec2 d);
		Dynamic getSupportVertex_dyn();

		virtual int getVertexCount( );
		Dynamic getVertexCount_dyn();

		virtual ::box2D::common::math::B2Vec2 getVertex( int index);
		Dynamic getVertex_dyn();

		Array< ::box2D::common::math::B2Vec2 > m_vertices; /* REM */ 
		int m_count; /* REM */ 
		double m_radius; /* REM */ 
};

} // end namespace box2D
} // end namespace collision

#endif /* INCLUDED_box2D_collision_B2DistanceProxy */ 
