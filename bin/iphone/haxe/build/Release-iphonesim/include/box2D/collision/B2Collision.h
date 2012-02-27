#ifndef INCLUDED_box2D_collision_B2Collision
#define INCLUDED_box2D_collision_B2Collision

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(box2D,collision,B2AABB)
HX_DECLARE_CLASS2(box2D,collision,B2Collision)
HX_DECLARE_CLASS2(box2D,collision,B2Manifold)
HX_DECLARE_CLASS2(box2D,collision,ClipVertex)
HX_DECLARE_CLASS3(box2D,collision,shapes,B2CircleShape)
HX_DECLARE_CLASS3(box2D,collision,shapes,B2PolygonShape)
HX_DECLARE_CLASS3(box2D,collision,shapes,B2Shape)
HX_DECLARE_CLASS3(box2D,common,math,B2Transform)
HX_DECLARE_CLASS3(box2D,common,math,B2Vec2)
namespace box2D{
namespace collision{


class B2Collision_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef B2Collision_obj OBJ_;
		B2Collision_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< B2Collision_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~B2Collision_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("B2Collision"); }

		static int b2_nullFeature; /* REM */ 
		static int clipSegmentToLine( Array< ::box2D::collision::ClipVertex > vOut,Array< ::box2D::collision::ClipVertex > vIn,::box2D::common::math::B2Vec2 normal,double offset);
		static Dynamic clipSegmentToLine_dyn();

		static double edgeSeparation( ::box2D::collision::shapes::B2PolygonShape poly1,::box2D::common::math::B2Transform xf1,int edge1,::box2D::collision::shapes::B2PolygonShape poly2,::box2D::common::math::B2Transform xf2);
		static Dynamic edgeSeparation_dyn();

		static double findMaxSeparation( Array< int > edgeIndex,::box2D::collision::shapes::B2PolygonShape poly1,::box2D::common::math::B2Transform xf1,::box2D::collision::shapes::B2PolygonShape poly2,::box2D::common::math::B2Transform xf2);
		static Dynamic findMaxSeparation_dyn();

		static Void findIncidentEdge( Array< ::box2D::collision::ClipVertex > c,::box2D::collision::shapes::B2PolygonShape poly1,::box2D::common::math::B2Transform xf1,int edge1,::box2D::collision::shapes::B2PolygonShape poly2,::box2D::common::math::B2Transform xf2);
		static Dynamic findIncidentEdge_dyn();

		static Array< ::box2D::collision::ClipVertex > makeClipPointVector( );
		static Dynamic makeClipPointVector_dyn();

		static Array< ::box2D::collision::ClipVertex > s_incidentEdge; /* REM */ 
		static Array< ::box2D::collision::ClipVertex > s_clipPoints1; /* REM */ 
		static Array< ::box2D::collision::ClipVertex > s_clipPoints2; /* REM */ 
		static Array< int > s_edgeAO; /* REM */ 
		static Array< int > s_edgeBO; /* REM */ 
		static ::box2D::common::math::B2Vec2 s_localTangent; /* REM */ 
		static ::box2D::common::math::B2Vec2 s_localNormal; /* REM */ 
		static ::box2D::common::math::B2Vec2 s_planePoint; /* REM */ 
		static ::box2D::common::math::B2Vec2 s_normal; /* REM */ 
		static ::box2D::common::math::B2Vec2 s_tangent; /* REM */ 
		static ::box2D::common::math::B2Vec2 s_tangent2; /* REM */ 
		static ::box2D::common::math::B2Vec2 s_v11; /* REM */ 
		static ::box2D::common::math::B2Vec2 s_v12; /* REM */ 
		static ::box2D::common::math::B2Vec2 b2CollidePolyTempVec; /* REM */ 
		static Void collidePolygons( ::box2D::collision::B2Manifold manifold,::box2D::collision::shapes::B2PolygonShape polyA,::box2D::common::math::B2Transform xfA,::box2D::collision::shapes::B2PolygonShape polyB,::box2D::common::math::B2Transform xfB);
		static Dynamic collidePolygons_dyn();

		static Void collideCircles( ::box2D::collision::B2Manifold manifold,::box2D::collision::shapes::B2CircleShape circle1,::box2D::common::math::B2Transform xf1,::box2D::collision::shapes::B2CircleShape circle2,::box2D::common::math::B2Transform xf2);
		static Dynamic collideCircles_dyn();

		static Void collidePolygonAndCircle( ::box2D::collision::B2Manifold manifold,::box2D::collision::shapes::B2PolygonShape polygon,::box2D::common::math::B2Transform xf1,::box2D::collision::shapes::B2CircleShape circle,::box2D::common::math::B2Transform xf2);
		static Dynamic collidePolygonAndCircle_dyn();

		static bool testOverlap( ::box2D::collision::B2AABB a,::box2D::collision::B2AABB b);
		static Dynamic testOverlap_dyn();

};

} // end namespace box2D
} // end namespace collision

#endif /* INCLUDED_box2D_collision_B2Collision */ 
