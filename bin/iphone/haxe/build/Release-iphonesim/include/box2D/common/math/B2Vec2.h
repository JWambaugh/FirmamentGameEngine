#ifndef INCLUDED_box2D_common_math_B2Vec2
#define INCLUDED_box2D_common_math_B2Vec2

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(box2D,common,math,B2Mat22)
HX_DECLARE_CLASS3(box2D,common,math,B2Vec2)
namespace box2D{
namespace common{
namespace math{


class B2Vec2_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef B2Vec2_obj OBJ_;
		B2Vec2_obj();
		Void __construct(Dynamic __o_x_,Dynamic __o_y_);

	public:
		static hx::ObjectPtr< B2Vec2_obj > __new(Dynamic __o_x_,Dynamic __o_y_);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~B2Vec2_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("B2Vec2"); }

		virtual Void setZero( );
		Dynamic setZero_dyn();

		virtual Void set( Dynamic x_,Dynamic y_);
		Dynamic set_dyn();

		virtual Void setV( ::box2D::common::math::B2Vec2 v);
		Dynamic setV_dyn();

		virtual ::box2D::common::math::B2Vec2 getNegative( );
		Dynamic getNegative_dyn();

		virtual Void negativeSelf( );
		Dynamic negativeSelf_dyn();

		virtual ::box2D::common::math::B2Vec2 copy( );
		Dynamic copy_dyn();

		virtual Void add( ::box2D::common::math::B2Vec2 v);
		Dynamic add_dyn();

		virtual Void subtract( ::box2D::common::math::B2Vec2 v);
		Dynamic subtract_dyn();

		virtual Void multiply( double a);
		Dynamic multiply_dyn();

		virtual Void mulM( ::box2D::common::math::B2Mat22 A);
		Dynamic mulM_dyn();

		virtual Void mulTM( ::box2D::common::math::B2Mat22 A);
		Dynamic mulTM_dyn();

		virtual Void crossVF( double s);
		Dynamic crossVF_dyn();

		virtual Void crossFV( double s);
		Dynamic crossFV_dyn();

		virtual Void minV( ::box2D::common::math::B2Vec2 b);
		Dynamic minV_dyn();

		virtual Void maxV( ::box2D::common::math::B2Vec2 b);
		Dynamic maxV_dyn();

		virtual Void abs( );
		Dynamic abs_dyn();

		virtual double length( );
		Dynamic length_dyn();

		virtual double lengthSquared( );
		Dynamic lengthSquared_dyn();

		virtual double normalize( );
		Dynamic normalize_dyn();

		virtual bool isValid( );
		Dynamic isValid_dyn();

		double x; /* REM */ 
		double y; /* REM */ 
		static ::box2D::common::math::B2Vec2 make( double x_,double y_);
		static Dynamic make_dyn();

};

} // end namespace box2D
} // end namespace common
} // end namespace math

#endif /* INCLUDED_box2D_common_math_B2Vec2 */ 
