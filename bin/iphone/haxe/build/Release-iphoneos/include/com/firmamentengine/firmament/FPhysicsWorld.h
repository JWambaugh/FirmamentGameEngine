#ifndef INCLUDED_com_firmamentengine_firmament_FPhysicsWorld
#define INCLUDED_com_firmamentengine_firmament_FPhysicsWorld

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <com/firmamentengine/firmament/FWorld.h>
HX_DECLARE_CLASS3(box2D,common,math,B2Vec2)
HX_DECLARE_CLASS2(box2D,dynamics,B2World)
HX_DECLARE_CLASS3(com,firmamentengine,firmament,FEntity)
HX_DECLARE_CLASS3(com,firmamentengine,firmament,FPhysicsEntity)
HX_DECLARE_CLASS3(com,firmamentengine,firmament,FPhysicsWorld)
HX_DECLARE_CLASS3(com,firmamentengine,firmament,FRenderable)
HX_DECLARE_CLASS3(com,firmamentengine,firmament,FVector)
HX_DECLARE_CLASS3(com,firmamentengine,firmament,FWorld)
HX_DECLARE_CLASS3(com,firmamentengine,firmament,FWorldPositional)
HX_DECLARE_CLASS2(nme,events,EventDispatcher)
HX_DECLARE_CLASS2(nme,events,IEventDispatcher)
namespace com{
namespace firmamentengine{
namespace firmament{


class FPhysicsWorld_obj : public ::com::firmamentengine::firmament::FWorld_obj{
	public:
		typedef ::com::firmamentengine::firmament::FWorld_obj super;
		typedef FPhysicsWorld_obj OBJ_;
		FPhysicsWorld_obj();
		Void __construct(::com::firmamentengine::firmament::FVector gravity);

	public:
		static hx::ObjectPtr< FPhysicsWorld_obj > __new(::com::firmamentengine::firmament::FVector gravity);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~FPhysicsWorld_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("FPhysicsWorld"); }

		::box2D::dynamics::B2World b2world; /* REM */ 
		virtual Array< ::com::firmamentengine::firmament::FEntity > getEntitiesInBox( int topLeftX,int topLeftY,int bottomRightX,int bottomRightY);
		Dynamic getEntitiesInBox_dyn();

		virtual ::box2D::dynamics::B2World getB2World( );
		Dynamic getB2World_dyn();

		virtual ::com::firmamentengine::firmament::FPhysicsEntity createEntity( Dynamic config);
		Dynamic createEntity_dyn();

		virtual Void step( );
		Dynamic step_dyn();

};

} // end namespace com
} // end namespace firmamentengine
} // end namespace firmament

#endif /* INCLUDED_com_firmamentengine_firmament_FPhysicsWorld */ 
