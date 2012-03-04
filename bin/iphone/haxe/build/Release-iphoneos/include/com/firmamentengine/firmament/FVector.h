#ifndef INCLUDED_com_firmamentengine_firmament_FVector
#define INCLUDED_com_firmamentengine_firmament_FVector

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <box2D/common/math/B2Vec2.h>
HX_DECLARE_CLASS3(box2D,common,math,B2Vec2)
HX_DECLARE_CLASS3(com,firmamentengine,firmament,FVector)
namespace com{
namespace firmamentengine{
namespace firmament{


class FVector_obj : public ::box2D::common::math::B2Vec2_obj{
	public:
		typedef ::box2D::common::math::B2Vec2_obj super;
		typedef FVector_obj OBJ_;
		FVector_obj();
		Void __construct(double x,double y);

	public:
		static hx::ObjectPtr< FVector_obj > __new(double x,double y);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~FVector_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("FVector"); }

};

} // end namespace com
} // end namespace firmamentengine
} // end namespace firmament

#endif /* INCLUDED_com_firmamentengine_firmament_FVector */ 
