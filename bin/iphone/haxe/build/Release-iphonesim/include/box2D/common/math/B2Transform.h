#ifndef INCLUDED_box2D_common_math_B2Transform
#define INCLUDED_box2D_common_math_B2Transform

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(box2D,common,math,B2Mat22)
HX_DECLARE_CLASS3(box2D,common,math,B2Transform)
HX_DECLARE_CLASS3(box2D,common,math,B2Vec2)
namespace box2D{
namespace common{
namespace math{


class B2Transform_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef B2Transform_obj OBJ_;
		B2Transform_obj();
		Void __construct(::box2D::common::math::B2Vec2 pos,::box2D::common::math::B2Mat22 r);

	public:
		static hx::ObjectPtr< B2Transform_obj > __new(::box2D::common::math::B2Vec2 pos,::box2D::common::math::B2Mat22 r);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~B2Transform_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("B2Transform"); }

		virtual Void initialize( ::box2D::common::math::B2Vec2 pos,::box2D::common::math::B2Mat22 r);
		Dynamic initialize_dyn();

		virtual Void setIdentity( );
		Dynamic setIdentity_dyn();

		virtual Void set( ::box2D::common::math::B2Transform x);
		Dynamic set_dyn();

		virtual double getAngle( );
		Dynamic getAngle_dyn();

		::box2D::common::math::B2Vec2 position; /* REM */ 
		::box2D::common::math::B2Mat22 R; /* REM */ 
};

} // end namespace box2D
} // end namespace common
} // end namespace math

#endif /* INCLUDED_box2D_common_math_B2Transform */ 
