#ifndef INCLUDED_box2D_collision_B2DynamicTreeNode
#define INCLUDED_box2D_collision_B2DynamicTreeNode

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(box2D,collision,B2AABB)
HX_DECLARE_CLASS2(box2D,collision,B2DynamicTreeNode)
namespace box2D{
namespace collision{


class B2DynamicTreeNode_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef B2DynamicTreeNode_obj OBJ_;
		B2DynamicTreeNode_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< B2DynamicTreeNode_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~B2DynamicTreeNode_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("B2DynamicTreeNode"); }

		int id; /* REM */ 
		virtual bool isLeaf( );
		Dynamic isLeaf_dyn();

		Dynamic userData; /* REM */ 
		::box2D::collision::B2AABB aabb; /* REM */ 
		::box2D::collision::B2DynamicTreeNode parent; /* REM */ 
		::box2D::collision::B2DynamicTreeNode child1; /* REM */ 
		::box2D::collision::B2DynamicTreeNode child2; /* REM */ 
		static int currentID; /* REM */ 
};

} // end namespace box2D
} // end namespace collision

#endif /* INCLUDED_box2D_collision_B2DynamicTreeNode */ 
