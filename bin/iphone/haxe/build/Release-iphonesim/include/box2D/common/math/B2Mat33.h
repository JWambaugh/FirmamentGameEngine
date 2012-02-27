#ifndef INCLUDED_box2D_common_math_B2Mat33
#define INCLUDED_box2D_common_math_B2Mat33

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(box2D,common,math,B2Mat33)
HX_DECLARE_CLASS3(box2D,common,math,B2Vec2)
HX_DECLARE_CLASS3(box2D,common,math,B2Vec3)
namespace box2D{
namespace common{
namespace math{


class B2Mat33_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef B2Mat33_obj OBJ_;
		B2Mat33_obj();
		Void __construct(::box2D::common::math::B2Vec3 c1,::box2D::common::math::B2Vec3 c2,::box2D::common::math::B2Vec3 c3);

	public:
		static hx::ObjectPtr< B2Mat33_obj > __new(::box2D::common::math::B2Vec3 c1,::box2D::common::math::B2Vec3 c2,::box2D::common::math::B2Vec3 c3);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~B2Mat33_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("B2Mat33"); }

		virtual Void setVVV( ::box2D::common::math::B2Vec3 c1,::box2D::common::math::B2Vec3 c2,::box2D::common::math::B2Vec3 c3);
		Dynamic setVVV_dyn();

		virtual ::box2D::common::math::B2Mat33 copy( );
		Dynamic copy_dyn();

		virtual Void setM( ::box2D::common::math::B2Mat33 m);
		Dynamic setM_dyn();

		virtual Void addM( ::box2D::common::math::B2Mat33 m);
		Dynamic addM_dyn();

		virtual Void setIdentity( );
		Dynamic setIdentity_dyn();

		virtual Void setZero( );
		Dynamic setZero_dyn();

		virtual ::box2D::common::math::B2Vec2 solve22( ::box2D::common::math::B2Vec2 out,double bX,double bY);
		Dynamic solve22_dyn();

		virtual ::box2D::common::math::B2Vec3 solve33( ::box2D::common::math::B2Vec3 out,double bX,double bY,double bZ);
		Dynamic solve33_dyn();

		::box2D::common::math::B2Vec3 col1; /* REM */ 
		::box2D::common::math::B2Vec3 col2; /* REM */ 
		::box2D::common::math::B2Vec3 col3; /* REM */ 
};

} // end namespace box2D
} // end namespace common
} // end namespace math

#endif /* INCLUDED_box2D_common_math_B2Mat33 */ 
