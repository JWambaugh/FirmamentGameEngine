#ifndef INCLUDED_box2D_collision_ClipVertex
#define INCLUDED_box2D_collision_ClipVertex

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(box2D,collision,B2ContactID)
HX_DECLARE_CLASS2(box2D,collision,ClipVertex)
HX_DECLARE_CLASS3(box2D,common,math,B2Vec2)
namespace box2D{
namespace collision{


class ClipVertex_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef ClipVertex_obj OBJ_;
		ClipVertex_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< ClipVertex_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~ClipVertex_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("ClipVertex"); }

		virtual Void set( ::box2D::collision::ClipVertex other);
		Dynamic set_dyn();

		::box2D::common::math::B2Vec2 v; /* REM */ 
		::box2D::collision::B2ContactID id; /* REM */ 
};

} // end namespace box2D
} // end namespace collision

#endif /* INCLUDED_box2D_collision_ClipVertex */ 
