#ifndef INCLUDED_box2D_collision_B2DynamicTreePair
#define INCLUDED_box2D_collision_B2DynamicTreePair

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(box2D,collision,B2DynamicTreeNode)
HX_DECLARE_CLASS2(box2D,collision,B2DynamicTreePair)
namespace box2D{
namespace collision{


class B2DynamicTreePair_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef B2DynamicTreePair_obj OBJ_;
		B2DynamicTreePair_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< B2DynamicTreePair_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~B2DynamicTreePair_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("B2DynamicTreePair"); }

		::box2D::collision::B2DynamicTreeNode proxyA; /* REM */ 
		::box2D::collision::B2DynamicTreeNode proxyB; /* REM */ 
};

} // end namespace box2D
} // end namespace collision

#endif /* INCLUDED_box2D_collision_B2DynamicTreePair */ 
