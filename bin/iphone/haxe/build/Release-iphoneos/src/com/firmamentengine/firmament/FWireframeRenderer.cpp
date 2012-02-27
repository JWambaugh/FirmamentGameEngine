#include <hxcpp.h>

#ifndef INCLUDED_box2D_common_math_B2Vec2
#include <box2D/common/math/B2Vec2.h>
#endif
#ifndef INCLUDED_com_firmamentengine_firmament_FCamera
#include <com/firmamentengine/firmament/FCamera.h>
#endif
#ifndef INCLUDED_com_firmamentengine_firmament_FRenderable
#include <com/firmamentengine/firmament/FRenderable.h>
#endif
#ifndef INCLUDED_com_firmamentengine_firmament_FRenderer
#include <com/firmamentengine/firmament/FRenderer.h>
#endif
#ifndef INCLUDED_com_firmamentengine_firmament_FVector
#include <com/firmamentengine/firmament/FVector.h>
#endif
#ifndef INCLUDED_com_firmamentengine_firmament_FWireframeRenderer
#include <com/firmamentengine/firmament/FWireframeRenderer.h>
#endif
#ifndef INCLUDED_com_firmamentengine_firmament_FWorldPositional
#include <com/firmamentengine/firmament/FWorldPositional.h>
#endif
#ifndef INCLUDED_com_firmamentengine_firmament_FWorldPositionalInterface
#include <com/firmamentengine/firmament/FWorldPositionalInterface.h>
#endif
#ifndef INCLUDED_nme_display_CapsStyle
#include <nme/display/CapsStyle.h>
#endif
#ifndef INCLUDED_nme_display_DisplayObject
#include <nme/display/DisplayObject.h>
#endif
#ifndef INCLUDED_nme_display_DisplayObjectContainer
#include <nme/display/DisplayObjectContainer.h>
#endif
#ifndef INCLUDED_nme_display_Graphics
#include <nme/display/Graphics.h>
#endif
#ifndef INCLUDED_nme_display_IBitmapDrawable
#include <nme/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_nme_display_InteractiveObject
#include <nme/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_nme_display_JointStyle
#include <nme/display/JointStyle.h>
#endif
#ifndef INCLUDED_nme_display_LineScaleMode
#include <nme/display/LineScaleMode.h>
#endif
#ifndef INCLUDED_nme_display_Sprite
#include <nme/display/Sprite.h>
#endif
#ifndef INCLUDED_nme_events_EventDispatcher
#include <nme/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_nme_events_IEventDispatcher
#include <nme/events/IEventDispatcher.h>
#endif
namespace com{
namespace firmamentengine{
namespace firmament{

Void FWireframeRenderer_obj::__construct()
{
{
}
;
	return null();
}

FWireframeRenderer_obj::~FWireframeRenderer_obj() { }

Dynamic FWireframeRenderer_obj::__CreateEmpty() { return  new FWireframeRenderer_obj; }
hx::ObjectPtr< FWireframeRenderer_obj > FWireframeRenderer_obj::__new()
{  hx::ObjectPtr< FWireframeRenderer_obj > result = new FWireframeRenderer_obj();
	result->__construct();
	return result;}

Dynamic FWireframeRenderer_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FWireframeRenderer_obj > result = new FWireframeRenderer_obj();
	result->__construct();
	return result;}

hx::Object *FWireframeRenderer_obj::__ToInterface(const type_info &inType) {
	if (inType==typeid( ::com::firmamentengine::firmament::FRenderer_obj)) return operator ::com::firmamentengine::firmament::FRenderer_obj *();
	return super::__ToInterface(inType);
}

Void FWireframeRenderer_obj::render( ::com::firmamentengine::firmament::FRenderable item,::com::firmamentengine::firmament::FCamera camera){
{
		HX_SOURCE_PUSH("FWireframeRenderer_obj::render")
		HX_SOURCE_POS("/Users/jordan/source/Firmament.hx/src/com/firmamentengine/firmament/FWireframeRenderer.hx",24)
		camera->nmeGetGraphics()->lineStyle((int)1,(int)0,null(),null(),null(),null(),null(),null());
		HX_SOURCE_POS("/Users/jordan/source/Firmament.hx/src/com/firmamentengine/firmament/FWireframeRenderer.hx",25)
		::com::firmamentengine::firmament::FVector pos = item->getPosition();
		HX_SOURCE_POS("/Users/jordan/source/Firmament.hx/src/com/firmamentengine/firmament/FWireframeRenderer.hx",27)
		::com::firmamentengine::firmament::FVector cameraPos = camera->getTopLeftPosition();
		HX_SOURCE_POS("/Users/jordan/source/Firmament.hx/src/com/firmamentengine/firmament/FWireframeRenderer.hx",29)
		camera->nmeGetGraphics()->drawCircle((((pos->x - cameraPos->x)) * camera->getZoom()),(((pos->y - cameraPos->y)) * camera->getZoom()),camera->getZoom());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(FWireframeRenderer_obj,render,(void))


FWireframeRenderer_obj::FWireframeRenderer_obj()
{
}

void FWireframeRenderer_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(FWireframeRenderer);
	HX_MARK_END_CLASS();
}

Dynamic FWireframeRenderer_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"render") ) { return render_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic FWireframeRenderer_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	return super::__SetField(inName,inValue);
}

void FWireframeRenderer_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("render"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class FWireframeRenderer_obj::__mClass;

void FWireframeRenderer_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.firmamentengine.firmament.FWireframeRenderer"), hx::TCanCast< FWireframeRenderer_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void FWireframeRenderer_obj::__boot()
{
}

} // end namespace com
} // end namespace firmamentengine
} // end namespace firmament
