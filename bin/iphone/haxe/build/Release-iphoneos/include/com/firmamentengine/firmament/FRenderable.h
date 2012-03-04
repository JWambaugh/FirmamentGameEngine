#ifndef INCLUDED_com_firmamentengine_firmament_FRenderable
#define INCLUDED_com_firmamentengine_firmament_FRenderable

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <com/firmamentengine/firmament/FWorldPositional.h>
HX_DECLARE_CLASS3(com,firmamentengine,firmament,FRenderable)
HX_DECLARE_CLASS3(com,firmamentengine,firmament,FRenderer)
HX_DECLARE_CLASS3(com,firmamentengine,firmament,FWorldPositional)
HX_DECLARE_CLASS2(nme,events,EventDispatcher)
HX_DECLARE_CLASS2(nme,events,IEventDispatcher)
namespace com{
namespace firmamentengine{
namespace firmament{


class FRenderable_obj : public ::com::firmamentengine::firmament::FWorldPositional_obj{
	public:
		typedef ::com::firmamentengine::firmament::FWorldPositional_obj super;
		typedef FRenderable_obj OBJ_;
		FRenderable_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< FRenderable_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~FRenderable_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("FRenderable"); }

		::com::firmamentengine::firmament::FRenderer renderer; /* REM */ 
		double imageScale; /* REM */ 
		double zPosition; /* REM */ 
		virtual ::com::firmamentengine::firmament::FRenderer getRenderer( );
		Dynamic getRenderer_dyn();

		virtual Void setRenderer( ::com::firmamentengine::firmament::FRenderer r);
		Dynamic setRenderer_dyn();

};

} // end namespace com
} // end namespace firmamentengine
} // end namespace firmament

#endif /* INCLUDED_com_firmamentengine_firmament_FRenderable */ 
