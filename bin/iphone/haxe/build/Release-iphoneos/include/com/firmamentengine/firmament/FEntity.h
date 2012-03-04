#ifndef INCLUDED_com_firmamentengine_firmament_FEntity
#define INCLUDED_com_firmamentengine_firmament_FEntity

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <com/firmamentengine/firmament/FRenderable.h>
HX_DECLARE_CLASS3(com,firmamentengine,firmament,FEntity)
HX_DECLARE_CLASS3(com,firmamentengine,firmament,FRenderable)
HX_DECLARE_CLASS3(com,firmamentengine,firmament,FWorld)
HX_DECLARE_CLASS3(com,firmamentengine,firmament,FWorldPositional)
HX_DECLARE_CLASS2(nme,events,EventDispatcher)
HX_DECLARE_CLASS2(nme,events,IEventDispatcher)
namespace com{
namespace firmamentengine{
namespace firmament{


class FEntity_obj : public ::com::firmamentengine::firmament::FRenderable_obj{
	public:
		typedef ::com::firmamentengine::firmament::FRenderable_obj super;
		typedef FEntity_obj OBJ_;
		FEntity_obj();
		Void __construct(::com::firmamentengine::firmament::FWorld world,Dynamic config);

	public:
		static hx::ObjectPtr< FEntity_obj > __new(::com::firmamentengine::firmament::FWorld world,Dynamic config);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~FEntity_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("FEntity"); }

		::com::firmamentengine::firmament::FWorld world; /* REM */ 
};

} // end namespace com
} // end namespace firmamentengine
} // end namespace firmament

#endif /* INCLUDED_com_firmamentengine_firmament_FEntity */ 
