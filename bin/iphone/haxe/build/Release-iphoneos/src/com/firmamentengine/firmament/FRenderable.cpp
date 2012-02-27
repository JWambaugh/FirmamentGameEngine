#include <hxcpp.h>

#ifndef INCLUDED_com_firmamentengine_firmament_FRenderable
#include <com/firmamentengine/firmament/FRenderable.h>
#endif
#ifndef INCLUDED_com_firmamentengine_firmament_FRenderer
#include <com/firmamentengine/firmament/FRenderer.h>
#endif
#ifndef INCLUDED_com_firmamentengine_firmament_FWorldPositional
#include <com/firmamentengine/firmament/FWorldPositional.h>
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

Void FRenderable_obj::__construct()
{
{
	HX_SOURCE_POS("/Users/jordan/source/Firmament.hx/src/com/firmamentengine/firmament/FRenderable.hx",15)
	super::__construct();
	HX_SOURCE_POS("/Users/jordan/source/Firmament.hx/src/com/firmamentengine/firmament/FRenderable.hx",16)
	this->imageScale = (int)100;
	HX_SOURCE_POS("/Users/jordan/source/Firmament.hx/src/com/firmamentengine/firmament/FRenderable.hx",17)
	this->zPosition = (int)0;
}
;
	return null();
}

FRenderable_obj::~FRenderable_obj() { }

Dynamic FRenderable_obj::__CreateEmpty() { return  new FRenderable_obj; }
hx::ObjectPtr< FRenderable_obj > FRenderable_obj::__new()
{  hx::ObjectPtr< FRenderable_obj > result = new FRenderable_obj();
	result->__construct();
	return result;}

Dynamic FRenderable_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FRenderable_obj > result = new FRenderable_obj();
	result->__construct();
	return result;}

::com::firmamentengine::firmament::FRenderer FRenderable_obj::getRenderer( ){
	HX_SOURCE_PUSH("FRenderable_obj::getRenderer")
	HX_SOURCE_POS("/Users/jordan/source/Firmament.hx/src/com/firmamentengine/firmament/FRenderable.hx",22)
	return this->renderer;
}


HX_DEFINE_DYNAMIC_FUNC0(FRenderable_obj,getRenderer,return )

Void FRenderable_obj::setRenderer( ::com::firmamentengine::firmament::FRenderer r){
{
		HX_SOURCE_PUSH("FRenderable_obj::setRenderer")
		HX_SOURCE_POS("/Users/jordan/source/Firmament.hx/src/com/firmamentengine/firmament/FRenderable.hx",26)
		this->renderer = r;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FRenderable_obj,setRenderer,(void))


FRenderable_obj::FRenderable_obj()
{
}

void FRenderable_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(FRenderable);
	HX_MARK_MEMBER_NAME(renderer,"renderer");
	HX_MARK_MEMBER_NAME(imageScale,"imageScale");
	HX_MARK_MEMBER_NAME(zPosition,"zPosition");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic FRenderable_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"renderer") ) { return renderer; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"zPosition") ) { return zPosition; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"imageScale") ) { return imageScale; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"getRenderer") ) { return getRenderer_dyn(); }
		if (HX_FIELD_EQ(inName,"setRenderer") ) { return setRenderer_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic FRenderable_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"renderer") ) { renderer=inValue.Cast< ::com::firmamentengine::firmament::FRenderer >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"zPosition") ) { zPosition=inValue.Cast< double >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"imageScale") ) { imageScale=inValue.Cast< double >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void FRenderable_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("renderer"));
	outFields->push(HX_CSTRING("imageScale"));
	outFields->push(HX_CSTRING("zPosition"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("renderer"),
	HX_CSTRING("imageScale"),
	HX_CSTRING("zPosition"),
	HX_CSTRING("getRenderer"),
	HX_CSTRING("setRenderer"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class FRenderable_obj::__mClass;

void FRenderable_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.firmamentengine.firmament.FRenderable"), hx::TCanCast< FRenderable_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void FRenderable_obj::__boot()
{
}

} // end namespace com
} // end namespace firmamentengine
} // end namespace firmament
