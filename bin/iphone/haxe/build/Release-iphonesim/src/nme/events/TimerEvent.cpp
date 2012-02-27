#include <hxcpp.h>

#ifndef INCLUDED_nme_events_Event
#include <nme/events/Event.h>
#endif
#ifndef INCLUDED_nme_events_TimerEvent
#include <nme/events/TimerEvent.h>
#endif
namespace nme{
namespace events{

Void TimerEvent_obj::__construct(::String type,Dynamic __o_bubbles,Dynamic __o_cancelable)
{
bool bubbles = __o_bubbles.Default(false);
bool cancelable = __o_cancelable.Default(false);
{
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,2,0/nme/events/TimerEvent.hx",13)
	super::__construct(type,bubbles,cancelable);
}
;
	return null();
}

TimerEvent_obj::~TimerEvent_obj() { }

Dynamic TimerEvent_obj::__CreateEmpty() { return  new TimerEvent_obj; }
hx::ObjectPtr< TimerEvent_obj > TimerEvent_obj::__new(::String type,Dynamic __o_bubbles,Dynamic __o_cancelable)
{  hx::ObjectPtr< TimerEvent_obj > result = new TimerEvent_obj();
	result->__construct(type,__o_bubbles,__o_cancelable);
	return result;}

Dynamic TimerEvent_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< TimerEvent_obj > result = new TimerEvent_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

::nme::events::Event TimerEvent_obj::clone( ){
	HX_SOURCE_PUSH("TimerEvent_obj::clone")
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,2,0/nme/events/TimerEvent.hx",19)
	return ::nme::events::TimerEvent_obj::__new(this->nmeGetType(),this->nmeGetBubbles(),this->nmeGetCancelable());
}


HX_DEFINE_DYNAMIC_FUNC0(TimerEvent_obj,clone,return )

::String TimerEvent_obj::toString( ){
	HX_SOURCE_PUSH("TimerEvent_obj::toString")
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,2,0/nme/events/TimerEvent.hx",25)
	return ((((((HX_CSTRING("[TimerEvent type=") + this->nmeGetType()) + HX_CSTRING(" bubbles=")) + this->nmeGetBubbles()) + HX_CSTRING(" cancelable=")) + this->nmeGetCancelable()) + HX_CSTRING("]"));
}


HX_DEFINE_DYNAMIC_FUNC0(TimerEvent_obj,toString,return )

Void TimerEvent_obj::updateAfterEvent( ){
{
		HX_SOURCE_PUSH("TimerEvent_obj::updateAfterEvent")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(TimerEvent_obj,updateAfterEvent,(void))

::String TimerEvent_obj::TIMER;

::String TimerEvent_obj::TIMER_COMPLETE;


TimerEvent_obj::TimerEvent_obj()
{
}

void TimerEvent_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(TimerEvent);
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic TimerEvent_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"TIMER") ) { return TIMER; }
		if (HX_FIELD_EQ(inName,"clone") ) { return clone_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"toString") ) { return toString_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"TIMER_COMPLETE") ) { return TIMER_COMPLETE; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"updateAfterEvent") ) { return updateAfterEvent_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic TimerEvent_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"TIMER") ) { TIMER=inValue.Cast< ::String >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"TIMER_COMPLETE") ) { TIMER_COMPLETE=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void TimerEvent_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("TIMER"),
	HX_CSTRING("TIMER_COMPLETE"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("clone"),
	HX_CSTRING("toString"),
	HX_CSTRING("updateAfterEvent"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(TimerEvent_obj::TIMER,"TIMER");
	HX_MARK_MEMBER_NAME(TimerEvent_obj::TIMER_COMPLETE,"TIMER_COMPLETE");
};

Class TimerEvent_obj::__mClass;

void TimerEvent_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("nme.events.TimerEvent"), hx::TCanCast< TimerEvent_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void TimerEvent_obj::__boot()
{
	hx::Static(TIMER) = HX_CSTRING("timer");
	hx::Static(TIMER_COMPLETE) = HX_CSTRING("timerComplete");
}

} // end namespace nme
} // end namespace events
