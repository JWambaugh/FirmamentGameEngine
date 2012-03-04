#ifndef INCLUDED_box2D_collision_shapes_B2Shape
#define INCLUDED_box2D_collision_shapes_B2Shape

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(box2D,collision,B2AABB)
HX_DECLARE_CLASS2(box2D,collision,B2RayCastInput)
HX_DECLARE_CLASS2(box2D,collision,B2RayCastOutput)
HX_DECLARE_CLASS3(box2D,collision,shapes,B2MassData)
HX_DECLARE_CLASS3(box2D,collision,shapes,B2Shape)
HX_DECLARE_CLASS3(box2D,common,math,B2Transform)
HX_DECLARE_CLASS3(box2D,common,math,B2Vec2)
namespace box2D{
namespace collision{
namespace shapes{


class B2Shape_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef B2Shape_obj OBJ_;
		B2Shape_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< B2Shape_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~B2Shape_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("B2Shape"); }

		virtual ::box2D::collision::shapes::B2Shape copy( );
		Dynamic copy_dyn();

		virtual Void set( ::box2D::collision::shapes::B2Shape other);
		Dynamic set_dyn();

		virtual int getType( );
		Dynamic getType_dyn();

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

		int m_type; /* REM */ 
		double m_radius; /* REM */ 
		static bool testOverlap( ::box2D::collision::shapes::B2Shape shape1,::box2D::common::math::B2Transform transform1,::box2D::collision::shapes::B2Shape shape2,::box2D::common::math::B2Transform transform2);
		static Dynamic testOverlap_dyn();

		static int e_unknownShape; /* REM */ 
		static int e_circleShape; /* REM */ 
		static int e_polygonShape; /* REM */ 
		static int e_edgeShape; /* REM */ 
		static int e_shapeTypeCount; /* REM */ 
		static int e_hitCollide; /* REM */ 
		static int e_missCollide; /* REM */ 
		static int e_startsInsideCollide; /* REM */ 
};

} // end namespace box2D
} // end namespace collision
} // end namespace shapes

#endif /* INCLUDED_box2D_collision_shapes_B2Shape */ 
