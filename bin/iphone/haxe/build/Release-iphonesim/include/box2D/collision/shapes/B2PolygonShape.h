#ifndef INCLUDED_box2D_collision_shapes_B2PolygonShape
#define INCLUDED_box2D_collision_shapes_B2PolygonShape

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <box2D/collision/shapes/B2Shape.h>
HX_DECLARE_CLASS2(box2D,collision,B2AABB)
HX_DECLARE_CLASS2(box2D,collision,B2OBB)
HX_DECLARE_CLASS2(box2D,collision,B2RayCastInput)
HX_DECLARE_CLASS2(box2D,collision,B2RayCastOutput)
HX_DECLARE_CLASS3(box2D,collision,shapes,B2MassData)
HX_DECLARE_CLASS3(box2D,collision,shapes,B2PolygonShape)
HX_DECLARE_CLASS3(box2D,collision,shapes,B2Shape)
HX_DECLARE_CLASS3(box2D,common,math,B2Mat22)
HX_DECLARE_CLASS3(box2D,common,math,B2Transform)
HX_DECLARE_CLASS3(box2D,common,math,B2Vec2)
namespace box2D{
namespace collision{
namespace shapes{


class B2PolygonShape_obj : public ::box2D::collision::shapes::B2Shape_obj{
	public:
		typedef ::box2D::collision::shapes::B2Shape_obj super;
		typedef B2PolygonShape_obj OBJ_;
		B2PolygonShape_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< B2PolygonShape_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~B2PolygonShape_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("B2PolygonShape"); }

		virtual ::box2D::collision::shapes::B2Shape copy( );
		Dynamic copy_dyn();

		virtual Void set( ::box2D::collision::shapes::B2Shape other);
		Dynamic set_dyn();

		virtual Void setAsArray( Dynamic vertices,Dynamic vertexCount);
		Dynamic setAsArray_dyn();

		virtual Void setAsVector( Array< ::box2D::common::math::B2Vec2 > vertices,Dynamic vertexCount);
		Dynamic setAsVector_dyn();

		virtual Void setAsBox( double hx,double hy);
		Dynamic setAsBox_dyn();

		virtual Void setAsOrientedBox( double hx,double hy,::box2D::common::math::B2Vec2 center,Dynamic angle);
		Dynamic setAsOrientedBox_dyn();

		virtual Void setAsEdge( ::box2D::common::math::B2Vec2 v1,::box2D::common::math::B2Vec2 v2);
		Dynamic setAsEdge_dyn();

		virtual bool testPoint( ::box2D::common::math::B2Transform xf,::box2D::common::math::B2Vec2 p);
		Dynamic testPoint_dyn();

		virtual bool rayCast( ::box2D::collision::B2RayCastOutput output,::box2D::collision::B2RayCastInput input,::box2D::common::math::B2Transform transform);
		Dynamic rayCast_dyn();

		virtual Void computeAABB( ::box2D::collision::B2AABB aabb,::box2D::common::math::B2Transform xf);
		Dynamic computeAABB_dyn();

		virtual Void computeMass( ::box2D::collision::shapes::B2MassData massData,double density);
		Dynamic computeMass_dyn();

		virtual double computeSubmergedArea( ::box2D::common::math::B2Vec2 normal,double offset,::box2D::common::math::B2Transform xf,::box2D::common::math::B2Vec2 c);
		Dynamic computeSubmergedArea_dyn();

		virtual int getVertexCount( );
		Dynamic getVertexCount_dyn();

		virtual Array< ::box2D::common::math::B2Vec2 > getVertices( );
		Dynamic getVertices_dyn();

		virtual Array< ::box2D::common::math::B2Vec2 > getNormals( );
		Dynamic getNormals_dyn();

		virtual int getSupport( ::box2D::common::math::B2Vec2 d);
		Dynamic getSupport_dyn();

		virtual ::box2D::common::math::B2Vec2 getSupportVertex( ::box2D::common::math::B2Vec2 d);
		Dynamic getSupportVertex_dyn();

		virtual bool validate( );
		Dynamic validate_dyn();

		virtual Void reserve( int count);
		Dynamic reserve_dyn();

		::box2D::common::math::B2Vec2 m_centroid; /* REM */ 
		Array< ::box2D::common::math::B2Vec2 > m_vertices; /* REM */ 
		Array< ::box2D::common::math::B2Vec2 > m_normals; /* REM */ 
		int m_vertexCount; /* REM */ 
		static ::box2D::collision::shapes::B2PolygonShape asArray( Dynamic vertices,double vertexCount);
		static Dynamic asArray_dyn();

		static ::box2D::collision::shapes::B2PolygonShape asVector( Array< ::box2D::common::math::B2Vec2 > vertices,double vertexCount);
		static Dynamic asVector_dyn();

		static ::box2D::collision::shapes::B2PolygonShape asBox( double hx,double hy);
		static Dynamic asBox_dyn();

		static ::box2D::common::math::B2Mat22 s_mat; /* REM */ 
		static ::box2D::collision::shapes::B2PolygonShape asOrientedBox( double hx,double hy,::box2D::common::math::B2Vec2 center,Dynamic angle);
		static Dynamic asOrientedBox_dyn();

		static ::box2D::collision::shapes::B2PolygonShape asEdge( ::box2D::common::math::B2Vec2 v1,::box2D::common::math::B2Vec2 v2);
		static Dynamic asEdge_dyn();

		static ::box2D::common::math::B2Vec2 computeCentroid( Array< ::box2D::common::math::B2Vec2 > vs,int count);
		static Dynamic computeCentroid_dyn();

		static Void computeOBB( ::box2D::collision::B2OBB obb,Array< ::box2D::common::math::B2Vec2 > vs,int count);
		static Dynamic computeOBB_dyn();

};

} // end namespace box2D
} // end namespace collision
} // end namespace shapes

#endif /* INCLUDED_box2D_collision_shapes_B2PolygonShape */ 
