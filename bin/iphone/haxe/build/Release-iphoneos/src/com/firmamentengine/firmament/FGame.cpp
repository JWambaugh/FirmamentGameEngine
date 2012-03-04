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
#ifndef INCLUDED_com_firmamentengine_firmament_FGame
#include <com/firmamentengine/firmament/FGame.h>
#endif
#ifndef INCLUDED_com_firmamentengine_firmament_FPhysicsEntity
#include <com/firmamentengine/firmament/FPhysicsEntity.h>
#endif
#ifndef INCLUDED_com_firmamentengine_firmament_FPhysicsWorld
#include <com/firmamentengine/firmament/FPhysicsWorld.h>
#endif
#ifndef INCLUDED_com_firmamentengine_firmament_FRenderable
#include <com/firmamentengine/firmament/FRenderable.h>
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
#ifndef INCLUDED_nme_Lib
#include <nme/Lib.h>
#endif
#ifndef INCLUDED_nme_display_DisplayObject
#include <nme/display/DisplayObject.h>
#endif
#ifndef INCLUDED_nme_display_DisplayObjectContainer
#include <nme/display/DisplayObjectContainer.h>
#endif
#ifndef INCLUDED_nme_display_IBitmapDrawable
#include <nme/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_nme_display_InteractiveObject
#include <nme/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_nme_display_MovieClip
#include <nme/display/MovieClip.h>
#endif
#ifndef INCLUDED_nme_display_Sprite
#include <nme/display/Sprite.h>
#endif
#ifndef INCLUDED_nme_display_Stage
#include <nme/display/Stage.h>
#endif
#ifndef INCLUDED_nme_display_StageAlign
#include <nme/display/StageAlign.h>
#endif
#ifndef INCLUDED_nme_display_StageScaleMode
#include <nme/display/StageScaleMode.h>
#endif
#ifndef INCLUDED_nme_events_Event
#include <nme/events/Event.h>
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

Void FGame_obj::__construct()
{
{
	HX_SOURCE_POS("/Users/jordan/source/Firmament.hx/src/com/firmamentengine/firmament/FGame.hx",25)
	::nme::display::Stage stage = ::nme::Lib_obj::nmeGetCurrent()->nmeGetStage();
	HX_SOURCE_POS("/Users/jordan/source/Firmament.hx/src/com/firmamentengine/firmament/FGame.hx",26)
	stage->nmeSetScaleMode(::nme::display::StageScaleMode_obj::NO_SCALE_dyn());
	HX_SOURCE_POS("/Users/jordan/source/Firmament.hx/src/com/firmamentengine/firmament/FGame.hx",27)
	stage->nmeSetAlign(::nme::display::StageAlign_obj::TOP_LEFT_dyn());
	HX_SOURCE_POS("/Users/jordan/source/Firmament.hx/src/com/firmamentengine/firmament/FGame.hx",30)
	this->world = ::com::firmamentengine::firmament::FPhysicsWorld_obj::__new(::com::firmamentengine::firmament::FVector_obj::__new((int)0,(int)1));
	struct _Function_1_1{
		inline static Dynamic Block( ){
			hx::Anon __result = hx::Anon_obj::Create();
			__result->Add(HX_CSTRING("test") , HX_CSTRING("blah"),false);
			__result->Add(HX_CSTRING("position") , ::com::firmamentengine::firmament::FVector_obj::__new((int)0,(int)1),false);
			return __result;
		}
	};
	HX_SOURCE_POS("/Users/jordan/source/Firmament.hx/src/com/firmamentengine/firmament/FGame.hx",31)
	this->world->createEntity(_Function_1_1::Block());
	struct _Function_1_2{
		inline static Dynamic Block( ){
			hx::Anon __result = hx::Anon_obj::Create();
			__result->Add(HX_CSTRING("test") , HX_CSTRING("blah"),false);
			__result->Add(HX_CSTRING("position") , ::com::firmamentengine::firmament::FVector_obj::__new(.5,(int)1),false);
			return __result;
		}
	};
	HX_SOURCE_POS("/Users/jordan/source/Firmament.hx/src/com/firmamentengine/firmament/FGame.hx",35)
	this->world->createEntity(_Function_1_2::Block());
	HX_SOURCE_POS("/Users/jordan/source/Firmament.hx/src/com/firmamentengine/firmament/FGame.hx",39)
	this->camera = ::com::firmamentengine::firmament::FCamera_obj::__new((int)500,(int)500);
	HX_SOURCE_POS("/Users/jordan/source/Firmament.hx/src/com/firmamentengine/firmament/FGame.hx",40)
	this->worldArray = Array_obj< ::com::firmamentengine::firmament::FWorld >::__new();
	HX_SOURCE_POS("/Users/jordan/source/Firmament.hx/src/com/firmamentengine/firmament/FGame.hx",41)
	this->worldArray->push(this->world);
	HX_SOURCE_POS("/Users/jordan/source/Firmament.hx/src/com/firmamentengine/firmament/FGame.hx",42)
	stage->addEventListener(::nme::events::Event_obj::ENTER_FRAME,this->this_onEnterFrame_dyn(),null(),null(),null());
	HX_SOURCE_POS("/Users/jordan/source/Firmament.hx/src/com/firmamentengine/firmament/FGame.hx",46)
	stage->addChild(this->camera);
}
;
	return null();
}

FGame_obj::~FGame_obj() { }

Dynamic FGame_obj::__CreateEmpty() { return  new FGame_obj; }
hx::ObjectPtr< FGame_obj > FGame_obj::__new()
{  hx::ObjectPtr< FGame_obj > result = new FGame_obj();
	result->__construct();
	return result;}

Dynamic FGame_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FGame_obj > result = new FGame_obj();
	result->__construct();
	return result;}

Void FGame_obj::this_onEnterFrame( ::nme::events::Event event){
{
		HX_SOURCE_PUSH("FGame_obj::this_onEnterFrame")
		HX_SOURCE_POS("/Users/jordan/source/Firmament.hx/src/com/firmamentengine/firmament/FGame.hx",51)
		this->camera->render(this->worldArray);
		HX_SOURCE_POS("/Users/jordan/source/Firmament.hx/src/com/firmamentengine/firmament/FGame.hx",52)
		{
			HX_SOURCE_POS("/Users/jordan/source/Firmament.hx/src/com/firmamentengine/firmament/FGame.hx",52)
			int _g = (int)0;
			Array< ::com::firmamentengine::firmament::FWorld > _g1 = this->worldArray;
			HX_SOURCE_POS("/Users/jordan/source/Firmament.hx/src/com/firmamentengine/firmament/FGame.hx",52)
			while(((_g < _g1->length))){
				HX_SOURCE_POS("/Users/jordan/source/Firmament.hx/src/com/firmamentengine/firmament/FGame.hx",52)
				::com::firmamentengine::firmament::FWorld world = _g1->__get(_g);
				HX_SOURCE_POS("/Users/jordan/source/Firmament.hx/src/com/firmamentengine/firmament/FGame.hx",52)
				++(_g);
				HX_SOURCE_POS("/Users/jordan/source/Firmament.hx/src/com/firmamentengine/firmament/FGame.hx",53)
				world->step();
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FGame_obj,this_onEnterFrame,(void))


FGame_obj::FGame_obj()
{
}

void FGame_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(FGame);
	HX_MARK_MEMBER_NAME(camera,"camera");
	HX_MARK_MEMBER_NAME(world,"world");
	HX_MARK_MEMBER_NAME(worldArray,"worldArray");
	HX_MARK_END_CLASS();
}

Dynamic FGame_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"world") ) { return world; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"camera") ) { return camera; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"worldArray") ) { return worldArray; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"this_onEnterFrame") ) { return this_onEnterFrame_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic FGame_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"world") ) { world=inValue.Cast< ::com::firmamentengine::firmament::FPhysicsWorld >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"camera") ) { camera=inValue.Cast< ::com::firmamentengine::firmament::FCamera >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"worldArray") ) { worldArray=inValue.Cast< Array< ::com::firmamentengine::firmament::FWorld > >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void FGame_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("camera"));
	outFields->push(HX_CSTRING("world"));
	outFields->push(HX_CSTRING("worldArray"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("camera"),
	HX_CSTRING("world"),
	HX_CSTRING("worldArray"),
	HX_CSTRING("this_onEnterFrame"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class FGame_obj::__mClass;

void FGame_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.firmamentengine.firmament.FGame"), hx::TCanCast< FGame_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void FGame_obj::__boot()
{
}

} // end namespace com
} // end namespace firmamentengine
} // end namespace firmament
