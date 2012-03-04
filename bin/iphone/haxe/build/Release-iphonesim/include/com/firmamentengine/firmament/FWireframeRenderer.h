#ifndef INCLUDED_com_firmamentengine_firmament_FWireframeRenderer
#define INCLUDED_com_firmamentengine_firmament_FWireframeRenderer

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <com/firmamentengine/firmament/FRenderer.h>
HX_DECLARE_CLASS3(com,firmamentengine,firmament,FCamera)
HX_DECLARE_CLASS3(com,firmamentengine,firmament,FRenderable)
HX_DECLARE_CLASS3(com,firmamentengine,firmament,FRenderer)
HX_DECLARE_CLASS3(com,firmamentengine,firmament,FWireframeRenderer)
HX_DECLARE_CLASS3(com,firmamentengine,firmament,FWorldPositional)
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


class FWireframeRenderer_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef FWireframeRenderer_obj OBJ_;
		FWireframeRenderer_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< FWireframeRenderer_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~FWireframeRenderer_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		inline operator ::com::firmamentengine::firmament::FRenderer_obj *()
			{ return new ::com::firmamentengine::firmament::FRenderer_delegate_< FWireframeRenderer_obj >(this); }
		hx::Object *__ToInterface(const type_info &inType);
		::String __ToString() const { return HX_CSTRING("FWireframeRenderer"); }

		virtual Void render( ::com::firmamentengine::firmament::FRenderable item,::com::firmamentengine::firmament::FCamera camera);
		Dynamic render_dyn();

};

} // end namespace com
} // end namespace firmamentengine
} // end namespace firmament

#endif /* INCLUDED_com_firmamentengine_firmament_FWireframeRenderer */ 
