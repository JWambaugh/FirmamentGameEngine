#ifndef INCLUDED_com_firmamentengine_firmament_FRenderer
#define INCLUDED_com_firmamentengine_firmament_FRenderer

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(com,firmamentengine,firmament,FCamera)
HX_DECLARE_CLASS3(com,firmamentengine,firmament,FRenderable)
HX_DECLARE_CLASS3(com,firmamentengine,firmament,FRenderer)
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


class FRenderer_obj : public hx::Interface{
	public:
		typedef hx::Interface super;
		typedef FRenderer_obj OBJ_;
		HX_DO_INTERFACE_RTTI;
		virtual Void render( ::com::firmamentengine::firmament::FRenderable item,::com::firmamentengine::firmament::FCamera camera)=0;
		Dynamic render_dyn();
};

#define DELEGATE_com_firmamentengine_firmament_FRenderer \
virtual Void render( ::com::firmamentengine::firmament::FRenderable item,::com::firmamentengine::firmament::FCamera camera) { return mDelegate->render(item,camera);}  \
virtual Dynamic render_dyn() { return mDelegate->render_dyn();}  \


template<typename IMPL>
class FRenderer_delegate_ : public FRenderer_obj
{
	protected:
		IMPL *mDelegate;
	public:
		FRenderer_delegate_(IMPL *inDelegate) : mDelegate(inDelegate) {}
		hx::Object *__GetRealObject() { return mDelegate; }
		DELEGATE_com_firmamentengine_firmament_FRenderer
};

} // end namespace com
} // end namespace firmamentengine
} // end namespace firmament

#endif /* INCLUDED_com_firmamentengine_firmament_FRenderer */ 
