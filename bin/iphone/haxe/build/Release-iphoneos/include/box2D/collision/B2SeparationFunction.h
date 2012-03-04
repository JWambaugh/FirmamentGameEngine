#ifndef INCLUDED_box2D_collision_B2SeparationFunction
#define INCLUDED_box2D_collision_B2SeparationFunction

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(box2D,collision,B2DistanceProxy)
HX_DECLARE_CLASS2(box2D,collision,B2SeparationFunction)
HX_DECLARE_CLASS2(box2D,collision,B2SimplexCache)
HX_DECLARE_CLASS3(box2D,common,math,B2Transform)
HX_DECLARE_CLASS3(box2D,common,math,B2Vec2)
namespace box2D{
namespace collision{


class B2SeparationFunction_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef B2SeparationFunction_obj OBJ_;
		B2SeparationFunction_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< B2SeparationFunction_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~B2SeparationFunction_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("B2SeparationFunction"); }

		virtual Void initialize( ::box2D::collision::B2SimplexCache cache,::box2D::collision::B2DistanceProxy proxyA,::box2D::common::math::B2Transform transformA,::box2D::collision::B2DistanceProxy proxyB,::box2D::common::math::B2Transform transformB);
		Dynamic initialize_dyn();

		virtual double evaluate( ::box2D::common::math::B2Transform transformA,::box2D::common::math::B2Transform transformB);
		Dynamic evaluate_dyn();

		::box2D::collision::B2DistanceProxy m_proxyA; /* REM */ 
		::box2D::collision::B2DistanceProxy m_proxyB; /* REM */ 
		int m_type; /* REM */ 
		::box2D::common::math::B2Vec2 m_localPoint; /* REM */ 
		::box2D::common::math::B2Vec2 m_axis; /* REM */ 
		static int e_points; /* REM */ 
		static int e_faceA; /* REM */ 
		static int e_faceB; /* REM */ 
};

} // end namespace box2D
} // end namespace collision

#endif /* INCLUDED_box2D_collision_B2SeparationFunction */ 
