#ifndef INCLUDED_com_firmamentengine_firmament_FGame
#define INCLUDED_com_firmamentengine_firmament_FGame

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(com,firmamentengine,firmament,FCamera)
HX_DECLARE_CLASS3(com,firmamentengine,firmament,FGame)
HX_DECLARE_CLASS3(com,firmamentengine,firmament,FPhysicsWorld)
HX_DECLARE_CLASS3(com,firmamentengine,firmament,FWorld)
HX_DECLARE_CLASS3(com,firmamentengine,firmament,FWorldPositionalInterface)
HX_DECLARE_CLASS2(nme,display,DisplayObject)
HX_DECLARE_CLASS2(nme,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(nme,display,IBitmapDrawable)
HX_DECLARE_CLASS2(nme,display,InteractiveObject)
HX_DECLARE_CLASS2(nme,display,Sprite)
HX_DECLARE_CLASS2(nme,events,Event)
HX_DECLARE_CLASS2(nme,events,EventDispatcher)
HX_DECLARE_CLASS2(nme,events,IEventDispatcher)
namespace com{
namespace firmamentengine{
namespace firmament{


class FGame_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef FGame_obj OBJ_;
		FGame_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< FGame_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~FGame_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("FGame"); }

		::com::firmamentengine::firmament::FCamera camera; /* REM */ 
		::com::firmamentengine::firmament::FPhysicsWorld world; /* REM */ 
		Array< ::com::firmamentengine::firmament::FWorld > worldArray; /* REM */ 
		virtual Void this_onEnterFrame( ::nme::events::Event event);
		Dynamic this_onEnterFrame_dyn();

};

} // end namespace com
} // end namespace firmamentengine
} // end namespace firmament

#endif /* INCLUDED_com_firmamentengine_firmament_FGame */ 
