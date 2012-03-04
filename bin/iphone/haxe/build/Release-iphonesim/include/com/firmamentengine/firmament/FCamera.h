#ifndef INCLUDED_com_firmamentengine_firmament_FCamera
#define INCLUDED_com_firmamentengine_firmament_FCamera

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <nme/display/Sprite.h>
#include <com/firmamentengine/firmament/FWorldPositionalInterface.h>
HX_DECLARE_CLASS3(box2D,common,math,B2Vec2)
HX_DECLARE_CLASS3(com,firmamentengine,firmament,FCamera)
HX_DECLARE_CLASS3(com,firmamentengine,firmament,FVector)
HX_DECLARE_CLASS3(com,firmamentengine,firmament,FWorld)
HX_DECLARE_CLASS3(com,firmamentengine,firmament,FWorldPositionalInterface)
HX_DECLARE_CLASS2(nme,display,DisplayObject)
HX_DECLARE_CLASS2(nme,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(nme,display,IBitmapDrawable)
HX_DECLARE_CLASS2(nme,display,InteractiveObject)
HX_DECLARE_CLASS2(nme,display,Sprite)
HX_DECLARE_CLASS2(nme,events,EventDispatcher)
HX_DECLARE_CLASS2(nme,events,IEventDispatcher)
namespace com{
namespace firmamentengine{
namespace firmament{


class FCamera_obj : public ::nme::display::Sprite_obj{
	public:
		typedef ::nme::display::Sprite_obj super;
		typedef FCamera_obj OBJ_;
		FCamera_obj();
		Void __construct(int height,int width);

	public:
		static hx::ObjectPtr< FCamera_obj > __new(int height,int width);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~FCamera_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		inline operator ::com::firmamentengine::firmament::FWorldPositionalInterface_obj *()
			{ return new ::com::firmamentengine::firmament::FWorldPositionalInterface_delegate_< FCamera_obj >(this); }
		hx::Object *__ToInterface(const type_info &inType);
		::String __ToString() const { return HX_CSTRING("FCamera"); }

		::com::firmamentengine::firmament::FVector position; /* REM */ 
		::com::firmamentengine::firmament::FVector topLeftPosition; /* REM */ 
		::String positionBase; /* REM */ 
		double angle; /* REM */ 
		double zoom; /* REM */ 
		int displayWidth; /* REM */ 
		int displayHeight; /* REM */ 
		bool calculatedTopLeft; /* REM */ 
		virtual Void render( Array< ::com::firmamentengine::firmament::FWorld > worlds);
		Dynamic render_dyn();

		virtual Void calculateTopLeftPosition( );
		Dynamic calculateTopLeftPosition_dyn();

		virtual ::com::firmamentengine::firmament::FVector getTopLeftPosition( );
		Dynamic getTopLeftPosition_dyn();

		virtual Void setPosition( ::com::firmamentengine::firmament::FVector pos);
		Dynamic setPosition_dyn();

		virtual ::com::firmamentengine::firmament::FVector getPosition( );
		Dynamic getPosition_dyn();

		virtual double getPositionX( );
		Dynamic getPositionX_dyn();

		virtual double getPositionY( );
		Dynamic getPositionY_dyn();

		virtual double getZoom( );
		Dynamic getZoom_dyn();

};

} // end namespace com
} // end namespace firmamentengine
} // end namespace firmament

#endif /* INCLUDED_com_firmamentengine_firmament_FCamera */ 
