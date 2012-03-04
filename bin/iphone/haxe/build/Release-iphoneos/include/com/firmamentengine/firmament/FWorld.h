#ifndef INCLUDED_com_firmamentengine_firmament_FWorld
#define INCLUDED_com_firmamentengine_firmament_FWorld

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(com,firmamentengine,firmament,FEntity)
HX_DECLARE_CLASS3(com,firmamentengine,firmament,FRenderable)
HX_DECLARE_CLASS3(com,firmamentengine,firmament,FWorld)
HX_DECLARE_CLASS3(com,firmamentengine,firmament,FWorldPositional)
HX_DECLARE_CLASS2(nme,events,EventDispatcher)
HX_DECLARE_CLASS2(nme,events,IEventDispatcher)
namespace com{
namespace firmamentengine{
namespace firmament{


class FWorld_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef FWorld_obj OBJ_;
		FWorld_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< FWorld_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~FWorld_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("FWorld"); }

		Array< ::com::firmamentengine::firmament::FEntity > entities; /* REM */ 
		virtual Void addEntity( ::com::firmamentengine::firmament::FEntity ent);
		Dynamic addEntity_dyn();

		virtual Array< ::com::firmamentengine::firmament::FEntity > getAllEntities( );
		Dynamic getAllEntities_dyn();

		virtual Void step( );
		Dynamic step_dyn();

};

} // end namespace com
} // end namespace firmamentengine
} // end namespace firmament

#endif /* INCLUDED_com_firmamentengine_firmament_FWorld */ 
