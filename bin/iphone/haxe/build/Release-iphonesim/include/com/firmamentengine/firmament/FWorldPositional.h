#ifndef INCLUDED_com_firmamentengine_firmament_FWorldPositional
#define INCLUDED_com_firmamentengine_firmament_FWorldPositional

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <nme/events/EventDispatcher.h>
HX_DECLARE_CLASS3(box2D,common,math,B2Vec2)
HX_DECLARE_CLASS3(com,firmamentengine,firmament,FVector)
HX_DECLARE_CLASS3(com,firmamentengine,firmament,FWorldPositional)
HX_DECLARE_CLASS2(nme,events,EventDispatcher)
HX_DECLARE_CLASS2(nme,events,IEventDispatcher)
namespace com{
namespace firmamentengine{
namespace firmament{


class FWorldPositional_obj : public ::nme::events::EventDispatcher_obj{
	public:
		typedef ::nme::events::EventDispatcher_obj super;
		typedef FWorldPositional_obj OBJ_;
		FWorldPositional_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< FWorldPositional_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~FWorldPositional_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("FWorldPositional"); }

		::com::firmamentengine::firmament::FVector position; /* REM */ 
		::String positionBase; /* REM */ 
		double angle; /* REM */ 
		virtual Void setPosition( ::com::firmamentengine::firmament::FVector pos);
		Dynamic setPosition_dyn();

		virtual ::com::firmamentengine::firmament::FVector getPosition( );
		Dynamic getPosition_dyn();

		virtual double getPositionX( );
		Dynamic getPositionX_dyn();

		virtual double getPositionY( );
		Dynamic getPositionY_dyn();

};

} // end namespace com
} // end namespace firmamentengine
} // end namespace firmament

#endif /* INCLUDED_com_firmamentengine_firmament_FWorldPositional */ 
