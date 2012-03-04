#ifndef INCLUDED_com_firmamentengine_firmament_FPhysicsEntity
#define INCLUDED_com_firmamentengine_firmament_FPhysicsEntity

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <com/firmamentengine/firmament/FEntity.h>
HX_DECLARE_CLASS3(box2D,common,math,B2Vec2)
HX_DECLARE_CLASS2(box2D,dynamics,B2Body)
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


class FPhysicsEntity_obj : public ::com::firmamentengine::firmament::FEntity_obj{
	public:
		typedef ::com::firmamentengine::firmament::FEntity_obj super;
		typedef FPhysicsEntity_obj OBJ_;
		FPhysicsEntity_obj();
		Void __construct(::com::firmamentengine::firmament::FPhysicsWorld world,Dynamic config);

	public:
		static hx::ObjectPtr< FPhysicsEntity_obj > __new(::com::firmamentengine::firmament::FPhysicsWorld world,Dynamic config);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~FPhysicsEntity_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("FPhysicsEntity"); }

		::box2D::dynamics::B2Body body; /* REM */ 
		virtual ::com::firmamentengine::firmament::FVector getPosition( );
		Dynamic getPosition_dyn();

};

} // end namespace com
} // end namespace firmamentengine
} // end namespace firmament

#endif /* INCLUDED_com_firmamentengine_firmament_FPhysicsEntity */ 
