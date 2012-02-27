#ifndef INCLUDED_box2D_collision_B2Simplex
#define INCLUDED_box2D_collision_B2Simplex

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(box2D,collision,B2DistanceProxy)
HX_DECLARE_CLASS2(box2D,collision,B2Simplex)
HX_DECLARE_CLASS2(box2D,collision,B2SimplexCache)
HX_DECLARE_CLASS2(box2D,collision,B2SimplexVertex)
HX_DECLARE_CLASS3(box2D,common,math,B2Transform)
HX_DECLARE_CLASS3(box2D,common,math,B2Vec2)
namespace box2D{
namespace collision{


class B2Simplex_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef B2Simplex_obj OBJ_;
		B2Simplex_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< B2Simplex_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~B2Simplex_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("B2Simplex"); }

		virtual Void readCache( ::box2D::collision::B2SimplexCache cache,::box2D::collision::B2DistanceProxy proxyA,::box2D::common::math::B2Transform transformA,::box2D::collision::B2DistanceProxy proxyB,::box2D::common::math::B2Transform transformB);
		Dynamic readCache_dyn();

		virtual Void writeCache( ::box2D::collision::B2SimplexCache cache);
		Dynamic writeCache_dyn();

		virtual ::box2D::common::math::B2Vec2 getSearchDirection( );
		Dynamic getSearchDirection_dyn();

		virtual ::box2D::common::math::B2Vec2 getClosestPoint( );
		Dynamic getClosestPoint_dyn();

		virtual Void getWitnessPoints( ::box2D::common::math::B2Vec2 pA,::box2D::common::math::B2Vec2 pB);
		Dynamic getWitnessPoints_dyn();

		virtual double getMetric( );
		Dynamic getMetric_dyn();

		virtual Void solve2( );
		Dynamic solve2_dyn();

		virtual Void solve3( );
		Dynamic solve3_dyn();

		::box2D::collision::B2SimplexVertex m_v1; /* REM */ 
		::box2D::collision::B2SimplexVertex m_v2; /* REM */ 
		::box2D::collision::B2SimplexVertex m_v3; /* REM */ 
		Array< ::box2D::collision::B2SimplexVertex > m_vertices; /* REM */ 
		int m_count; /* REM */ 
};

} // end namespace box2D
} // end namespace collision

#endif /* INCLUDED_box2D_collision_B2Simplex */ 
