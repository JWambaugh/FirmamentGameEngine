#ifndef INCLUDED_box2D_collision_shapes_B2CircleShape
#define INCLUDED_box2D_collision_shapes_B2CircleShape

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <box2D/collision/shapes/B2Shape.h>
HX_DECLARE_CLASS2(box2D,collision,B2AABB)
HX_DECLARE_CLASS2(box2D,collision,B2RayCastInput)
HX_DECLARE_CLASS2(box2D,collision,B2RayCastOutput)
HX_DECLARE_CLASS3(box2D,collision,shapes,B2CircleShape)
HX_DECLARE_CLASS3(box2D,collision,shapes,B2MassData)
HX_DECLARE_CLASS3(box2D,collision,shapes,B2Shape)
HX_DECLARE_CLASS3(box2D,common,math,B2Transform)
HX_DECLARE_CLASS3(box2D,common,math,B2Vec2)
namespace box2D{
namespace collision{
namespace shapes{


class B2CircleShape_obj : public ::box2D::collision::shapes::B2Shape_obj{
	public:
		typedef ::box2D::collision::shapes::B2Shape_obj super;
		typedef B2CircleShape_obj OBJ_;
		B2CircleShape_obj();
		Void __construct(Dynamic __o_radius);

	public:
		static hx::ObjectPtr< B2CircleShape_obj > __new(Dynamic __o_radius);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~B2CircleShape_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("B2CircleShape"); }

		virtual ::box2D::collision::shapes::B2Shape copy( );
		Dynamic copy_dyn();

		virtual Void set( ::box2D::collision::shapes::B2Shape other);
		Dynamic set_dyn();

		virtual bool testPoint( ::box2D::common::math::B2Transform transform,::box2D::common::math::B2Vec2 p);
		Dynamic testPoint_dyn();

		virtual bool rayCast( ::box2D::collision::B2RayCastOutput output,::box2D::collision::B2RayCastInput input,::box2D::common::math::B2Transform transform);
		Dynamic rayCast_dyn();

		virtual Void computeAABB( ::box2D::collision::B2AABB aabb,::box2D::common::math::B2Transform transform);
		Dynamic computeAABB_dyn();

		virtual Void computeMass( ::box2D::collision::shapes::B2MassData massData,double density);
		Dynamic computeMass_dyn();

		virtual double computeSubmergedArea( ::box2D::common::math::B2Vec2 normal,double offset,::box2D::common::math::B2Transform xf,::box2D::common::math::B2Vec2 c);
		Dynamic computeSubmergedArea_dyn();

		virtual ::box2D::common::math::B2Vec2 getLocalPosition( );
		Dynamic getLocalPosition_dyn();

		virtual Void setLocalPosition( ::box2D::common::math::B2Vec2 position);
		Dynamic setLocalPosition_dyn();

		virtual double getRadius( );
		Dynamic getRadius_dyn();

		virtual Void setRadius( double radius);
		Dynamic setRadius_dyn();

		::box2D::common::math::B2Vec2 m_p; /* REM */ 
};

} // end namespace box2D
} // end namespace collision
} // end namespace shapes

#endif /* INCLUDED_box2D_collision_shapes_B2CircleShape */ 
