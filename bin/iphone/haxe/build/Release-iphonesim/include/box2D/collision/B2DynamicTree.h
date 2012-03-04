#ifndef INCLUDED_box2D_collision_B2DynamicTree
#define INCLUDED_box2D_collision_B2DynamicTree

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(box2D,collision,B2AABB)
HX_DECLARE_CLASS2(box2D,collision,B2DynamicTree)
HX_DECLARE_CLASS2(box2D,collision,B2DynamicTreeNode)
HX_DECLARE_CLASS2(box2D,collision,B2RayCastInput)
HX_DECLARE_CLASS3(box2D,common,math,B2Vec2)
namespace box2D{
namespace collision{


class B2DynamicTree_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef B2DynamicTree_obj OBJ_;
		B2DynamicTree_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< B2DynamicTree_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~B2DynamicTree_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("B2DynamicTree"); }

		virtual ::box2D::collision::B2DynamicTreeNode createProxy( ::box2D::collision::B2AABB aabb,Dynamic userData);
		Dynamic createProxy_dyn();

		virtual Void destroyProxy( ::box2D::collision::B2DynamicTreeNode proxy);
		Dynamic destroyProxy_dyn();

		virtual bool moveProxy( ::box2D::collision::B2DynamicTreeNode proxy,::box2D::collision::B2AABB aabb,::box2D::common::math::B2Vec2 displacement);
		Dynamic moveProxy_dyn();

		virtual Void rebalance( int iterations);
		Dynamic rebalance_dyn();

		virtual ::box2D::collision::B2AABB getFatAABB( ::box2D::collision::B2DynamicTreeNode proxy);
		Dynamic getFatAABB_dyn();

		virtual Dynamic getUserData( ::box2D::collision::B2DynamicTreeNode proxy);
		Dynamic getUserData_dyn();

		virtual Void query( Dynamic callbackMethod,::box2D::collision::B2AABB aabb);
		Dynamic query_dyn();

		virtual Void rayCast( Dynamic callbackMethod,::box2D::collision::B2RayCastInput input);
		Dynamic rayCast_dyn();

		virtual ::box2D::collision::B2DynamicTreeNode allocateNode( );
		Dynamic allocateNode_dyn();

		virtual Void freeNode( ::box2D::collision::B2DynamicTreeNode node);
		Dynamic freeNode_dyn();

		virtual Void insertLeaf( ::box2D::collision::B2DynamicTreeNode leaf);
		Dynamic insertLeaf_dyn();

		virtual Void removeLeaf( ::box2D::collision::B2DynamicTreeNode leaf);
		Dynamic removeLeaf_dyn();

		::box2D::collision::B2DynamicTreeNode m_root; /* REM */ 
		::box2D::collision::B2DynamicTreeNode m_freeList; /* REM */ 
		int m_path; /* REM */ 
		int m_insertionCount; /* REM */ 
};

} // end namespace box2D
} // end namespace collision

#endif /* INCLUDED_box2D_collision_B2DynamicTree */ 
