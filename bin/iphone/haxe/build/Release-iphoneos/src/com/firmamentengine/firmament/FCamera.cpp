#include <hxcpp.h>

#ifndef INCLUDED_box2D_common_math_B2Vec2
#include <box2D/common/math/B2Vec2.h>
#endif
#ifndef INCLUDED_com_firmamentengine_firmament_FCamera
#include <com/firmamentengine/firmament/FCamera.h>
#endif
#ifndef INCLUDED_com_firmamentengine_firmament_FEntity
#include <com/firmamentengine/firmament/FEntity.h>
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
#ifndef INCLUDED_com_firmamentengine_firmament_FWorld
#include <com/firmamentengine/firmament/FWorld.h>
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

Void FCamera_obj::__construct(int height,int width)
{
{
	HX_SOURCE_POS("/Users/jordan/source/Firmament.hx/src/com/firmamentengine/firmament/FCamera.hx",25)
	super::__construct();
	HX_SOURCE_POS("/Users/jordan/source/Firmament.hx/src/com/firmamentengine/firmament/FCamera.hx",26)
	this->zoom = (int)100;
	HX_SOURCE_POS("/Users/jordan/source/Firmament.hx/src/com/firmamentengine/firmament/FCamera.hx",28)
	this->position = ::com::firmamentengine::firmament::FVector_obj::__new((int)0,(int)0);
	HX_SOURCE_POS("/Users/jordan/source/Firmament.hx/src/com/firmamentengine/firmament/FCamera.hx",29)
	this->calculatedTopLeft = false;
	HX_SOURCE_POS("/Users/jordan/source/Firmament.hx/src/com/firmamentengine/firmament/FCamera.hx",30)
	this->topLeftPosition = ::com::firmamentengine::firmament::FVector_obj::__new((int)0,(int)0);
	HX_SOURCE_POS("/Users/jordan/source/Firmament.hx/src/com/firmamentengine/firmament/FCamera.hx",31)
	this->displayHeight = height;
	HX_SOURCE_POS("/Users/jordan/source/Firmament.hx/src/com/firmamentengine/firmament/FCamera.hx",32)
	this->displayWidth = width;
}
;
	return null();
}

FCamera_obj::~FCamera_obj() { }

Dynamic FCamera_obj::__CreateEmpty() { return  new FCamera_obj; }
hx::ObjectPtr< FCamera_obj > FCamera_obj::__new(int height,int width)
{  hx::ObjectPtr< FCamera_obj > result = new FCamera_obj();
	result->__construct(height,width);
	return result;}

Dynamic FCamera_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FCamera_obj > result = new FCamera_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

hx::Object *FCamera_obj::__ToInterface(const type_info &inType) {
	if (inType==typeid( ::com::firmamentengine::firmament::FWorldPositionalInterface_obj)) return operator ::com::firmamentengine::firmament::FWorldPositionalInterface_obj *();
	return super::__ToInterface(inType);
}

Void FCamera_obj::render( Array< ::com::firmamentengine::firmament::FWorld > worlds){
{
		HX_SOURCE_PUSH("FCamera_obj::render")
		HX_SOURCE_POS("/Users/jordan/source/Firmament.hx/src/com/firmamentengine/firmament/FCamera.hx",36)
		this->nmeGetGraphics()->clear();
		HX_SOURCE_POS("/Users/jordan/source/Firmament.hx/src/com/firmamentengine/firmament/FCamera.hx",37)
		this->nmeGetGraphics()->lineStyle((int)1,(int)0,null(),null(),null(),null(),null(),null());
		HX_SOURCE_POS("/Users/jordan/source/Firmament.hx/src/com/firmamentengine/firmament/FCamera.hx",38)
		this->nmeGetGraphics()->drawRect((int)0,(int)0,this->displayWidth,this->displayHeight);
		HX_SOURCE_POS("/Users/jordan/source/Firmament.hx/src/com/firmamentengine/firmament/FCamera.hx",39)
		{
			HX_SOURCE_POS("/Users/jordan/source/Firmament.hx/src/com/firmamentengine/firmament/FCamera.hx",39)
			int _g = (int)0;
			HX_SOURCE_POS("/Users/jordan/source/Firmament.hx/src/com/firmamentengine/firmament/FCamera.hx",39)
			while(((_g < worlds->length))){
				HX_SOURCE_POS("/Users/jordan/source/Firmament.hx/src/com/firmamentengine/firmament/FCamera.hx",39)
				::com::firmamentengine::firmament::FWorld world = worlds->__get(_g);
				HX_SOURCE_POS("/Users/jordan/source/Firmament.hx/src/com/firmamentengine/firmament/FCamera.hx",39)
				++(_g);
				HX_SOURCE_POS("/Users/jordan/source/Firmament.hx/src/com/firmamentengine/firmament/FCamera.hx",40)
				Array< ::com::firmamentengine::firmament::FEntity > entities = world->getAllEntities();
				HX_SOURCE_POS("/Users/jordan/source/Firmament.hx/src/com/firmamentengine/firmament/FCamera.hx",41)
				{
					HX_SOURCE_POS("/Users/jordan/source/Firmament.hx/src/com/firmamentengine/firmament/FCamera.hx",41)
					int _g1 = (int)0;
					HX_SOURCE_POS("/Users/jordan/source/Firmament.hx/src/com/firmamentengine/firmament/FCamera.hx",41)
					while(((_g1 < entities->length))){
						HX_SOURCE_POS("/Users/jordan/source/Firmament.hx/src/com/firmamentengine/firmament/FCamera.hx",41)
						::com::firmamentengine::firmament::FEntity ent = entities->__get(_g1);
						HX_SOURCE_POS("/Users/jordan/source/Firmament.hx/src/com/firmamentengine/firmament/FCamera.hx",41)
						++(_g1);
						HX_SOURCE_POS("/Users/jordan/source/Firmament.hx/src/com/firmamentengine/firmament/FCamera.hx",42)
						ent->getRenderer()->render(ent,hx::ObjectPtr<OBJ_>(this));
					}
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FCamera_obj,render,(void))

Void FCamera_obj::calculateTopLeftPosition( ){
{
		HX_SOURCE_PUSH("FCamera_obj::calculateTopLeftPosition")
		HX_SOURCE_POS("/Users/jordan/source/Firmament.hx/src/com/firmamentengine/firmament/FCamera.hx",48)
		this->topLeftPosition->x = (this->position->x - (double((double(this->displayWidth) / double(this->zoom))) / double((int)2)));
		HX_SOURCE_POS("/Users/jordan/source/Firmament.hx/src/com/firmamentengine/firmament/FCamera.hx",49)
		this->topLeftPosition->y = (this->position->y - (double((double(this->displayHeight) / double(this->zoom))) / double((int)2)));
		HX_SOURCE_POS("/Users/jordan/source/Firmament.hx/src/com/firmamentengine/firmament/FCamera.hx",50)
		this->calculatedTopLeft = true;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FCamera_obj,calculateTopLeftPosition,(void))

::com::firmamentengine::firmament::FVector FCamera_obj::getTopLeftPosition( ){
	HX_SOURCE_PUSH("FCamera_obj::getTopLeftPosition")
	HX_SOURCE_POS("/Users/jordan/source/Firmament.hx/src/com/firmamentengine/firmament/FCamera.hx",55)
	this->calculateTopLeftPosition();
	HX_SOURCE_POS("/Users/jordan/source/Firmament.hx/src/com/firmamentengine/firmament/FCamera.hx",57)
	return this->topLeftPosition;
}


HX_DEFINE_DYNAMIC_FUNC0(FCamera_obj,getTopLeftPosition,return )

Void FCamera_obj::setPosition( ::com::firmamentengine::firmament::FVector pos){
{
		HX_SOURCE_PUSH("FCamera_obj::setPosition")
		HX_SOURCE_POS("/Users/jordan/source/Firmament.hx/src/com/firmamentengine/firmament/FCamera.hx",61)
		this->position = pos;
		HX_SOURCE_POS("/Users/jordan/source/Firmament.hx/src/com/firmamentengine/firmament/FCamera.hx",62)
		this->calculateTopLeftPosition();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FCamera_obj,setPosition,(void))

::com::firmamentengine::firmament::FVector FCamera_obj::getPosition( ){
	HX_SOURCE_PUSH("FCamera_obj::getPosition")
	HX_SOURCE_POS("/Users/jordan/source/Firmament.hx/src/com/firmamentengine/firmament/FCamera.hx",65)
	return this->position;
}


HX_DEFINE_DYNAMIC_FUNC0(FCamera_obj,getPosition,return )

double FCamera_obj::getPositionX( ){
	HX_SOURCE_PUSH("FCamera_obj::getPositionX")
	HX_SOURCE_POS("/Users/jordan/source/Firmament.hx/src/com/firmamentengine/firmament/FCamera.hx",69)
	return this->position->x;
}


HX_DEFINE_DYNAMIC_FUNC0(FCamera_obj,getPositionX,return )

double FCamera_obj::getPositionY( ){
	HX_SOURCE_PUSH("FCamera_obj::getPositionY")
	HX_SOURCE_POS("/Users/jordan/source/Firmament.hx/src/com/firmamentengine/firmament/FCamera.hx",73)
	return this->position->y;
}


HX_DEFINE_DYNAMIC_FUNC0(FCamera_obj,getPositionY,return )

double FCamera_obj::getZoom( ){
	HX_SOURCE_PUSH("FCamera_obj::getZoom")
	HX_SOURCE_POS("/Users/jordan/source/Firmament.hx/src/com/firmamentengine/firmament/FCamera.hx",77)
	return this->zoom;
}


HX_DEFINE_DYNAMIC_FUNC0(FCamera_obj,getZoom,return )


FCamera_obj::FCamera_obj()
{
}

void FCamera_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(FCamera);
	HX_MARK_MEMBER_NAME(position,"position");
	HX_MARK_MEMBER_NAME(topLeftPosition,"topLeftPosition");
	HX_MARK_MEMBER_NAME(positionBase,"positionBase");
	HX_MARK_MEMBER_NAME(angle,"angle");
	HX_MARK_MEMBER_NAME(zoom,"zoom");
	HX_MARK_MEMBER_NAME(displayWidth,"displayWidth");
	HX_MARK_MEMBER_NAME(displayHeight,"displayHeight");
	HX_MARK_MEMBER_NAME(calculatedTopLeft,"calculatedTopLeft");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic FCamera_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"zoom") ) { return zoom; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"angle") ) { return angle; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"render") ) { return render_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"getZoom") ) { return getZoom_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"position") ) { return position; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"setPosition") ) { return setPosition_dyn(); }
		if (HX_FIELD_EQ(inName,"getPosition") ) { return getPosition_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"positionBase") ) { return positionBase; }
		if (HX_FIELD_EQ(inName,"displayWidth") ) { return displayWidth; }
		if (HX_FIELD_EQ(inName,"getPositionX") ) { return getPositionX_dyn(); }
		if (HX_FIELD_EQ(inName,"getPositionY") ) { return getPositionY_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"displayHeight") ) { return displayHeight; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"topLeftPosition") ) { return topLeftPosition; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"calculatedTopLeft") ) { return calculatedTopLeft; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"getTopLeftPosition") ) { return getTopLeftPosition_dyn(); }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"calculateTopLeftPosition") ) { return calculateTopLeftPosition_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic FCamera_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"zoom") ) { zoom=inValue.Cast< double >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"angle") ) { angle=inValue.Cast< double >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"position") ) { position=inValue.Cast< ::com::firmamentengine::firmament::FVector >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"positionBase") ) { positionBase=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"displayWidth") ) { displayWidth=inValue.Cast< int >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"displayHeight") ) { displayHeight=inValue.Cast< int >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"topLeftPosition") ) { topLeftPosition=inValue.Cast< ::com::firmamentengine::firmament::FVector >(); return inValue; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"calculatedTopLeft") ) { calculatedTopLeft=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void FCamera_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("position"));
	outFields->push(HX_CSTRING("topLeftPosition"));
	outFields->push(HX_CSTRING("positionBase"));
	outFields->push(HX_CSTRING("angle"));
	outFields->push(HX_CSTRING("zoom"));
	outFields->push(HX_CSTRING("displayWidth"));
	outFields->push(HX_CSTRING("displayHeight"));
	outFields->push(HX_CSTRING("calculatedTopLeft"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("position"),
	HX_CSTRING("topLeftPosition"),
	HX_CSTRING("positionBase"),
	HX_CSTRING("angle"),
	HX_CSTRING("zoom"),
	HX_CSTRING("displayWidth"),
	HX_CSTRING("displayHeight"),
	HX_CSTRING("calculatedTopLeft"),
	HX_CSTRING("render"),
	HX_CSTRING("calculateTopLeftPosition"),
	HX_CSTRING("getTopLeftPosition"),
	HX_CSTRING("setPosition"),
	HX_CSTRING("getPosition"),
	HX_CSTRING("getPositionX"),
	HX_CSTRING("getPositionY"),
	HX_CSTRING("getZoom"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class FCamera_obj::__mClass;

void FCamera_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.firmamentengine.firmament.FCamera"), hx::TCanCast< FCamera_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void FCamera_obj::__boot()
{
}

} // end namespace com
} // end namespace firmamentengine
} // end namespace firmament
