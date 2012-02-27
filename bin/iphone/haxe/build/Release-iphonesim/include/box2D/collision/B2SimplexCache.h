#ifndef INCLUDED_box2D_collision_B2SimplexCache
#define INCLUDED_box2D_collision_B2SimplexCache

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(box2D,collision,B2SimplexCache)
namespace box2D{
namespace collision{


class B2SimplexCache_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef B2SimplexCache_obj OBJ_;
		B2SimplexCache_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< B2SimplexCache_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~B2SimplexCache_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("B2SimplexCache"); }

		double metric; /* REM */ 
		int count; /* REM */ 
		Array< int > indexA; /* REM */ 
		Array< int > indexB; /* REM */ 
};

} // end namespace box2D
} // end namespace collision

#endif /* INCLUDED_box2D_collision_B2SimplexCache */ 
