#ifndef INCLUDED_box2D_collision_B2ManifoldPoint
#define INCLUDED_box2D_collision_B2ManifoldPoint

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(box2D,collision,B2ContactID)
HX_DECLARE_CLASS2(box2D,collision,B2ManifoldPoint)
HX_DECLARE_CLASS3(box2D,common,math,B2Vec2)
namespace box2D{
namespace collision{


class B2ManifoldPoint_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef B2ManifoldPoint_obj OBJ_;
		B2ManifoldPoint_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< B2ManifoldPoint_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~B2ManifoldPoint_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("B2ManifoldPoint"); }

		virtual Void reset( );
		Dynamic reset_dyn();

		virtual Void set( ::box2D::collision::B2ManifoldPoint m);
		Dynamic set_dyn();

		::box2D::common::math::B2Vec2 m_localPoint; /* REM */ 
		double m_normalImpulse; /* REM */ 
		double m_tangentImpulse; /* REM */ 
		::box2D::collision::B2ContactID m_id; /* REM */ 
};

} // end namespace box2D
} // end namespace collision

#endif /* INCLUDED_box2D_collision_B2ManifoldPoint */ 
