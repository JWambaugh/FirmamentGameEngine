#ifndef INCLUDED_box2D_common_B2Color
#define INCLUDED_box2D_common_B2Color

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(box2D,common,B2Color)
namespace box2D{
namespace common{


class B2Color_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef B2Color_obj OBJ_;
		B2Color_obj();
		Void __construct(double rr,double gg,double bb);

	public:
		static hx::ObjectPtr< B2Color_obj > __new(double rr,double gg,double bb);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~B2Color_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("B2Color"); }

		virtual Void set( double rr,double gg,double bb);
		Dynamic set_dyn();

		double r; /* REM */ 
		double g; /* REM */ 
		double b; /* REM */ 
		int color; /* REM */ 
		virtual double setR( double rr);
		Dynamic setR_dyn();

		virtual double setG( double gg);
		Dynamic setG_dyn();

		virtual double setB( double bb);
		Dynamic setB_dyn();

		virtual int getColor( );
		Dynamic getColor_dyn();

		int _r; /* REM */ 
		int _g; /* REM */ 
		int _b; /* REM */ 
};

} // end namespace box2D
} // end namespace common

#endif /* INCLUDED_box2D_common_B2Color */ 
