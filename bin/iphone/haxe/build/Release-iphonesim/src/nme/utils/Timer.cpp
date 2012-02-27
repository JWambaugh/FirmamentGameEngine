#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_haxe_Timer
#include <haxe/Timer.h>
#endif
#ifndef INCLUDED_nme_errors_Error
#include <nme/errors/Error.h>
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
#ifndef INCLUDED_nme_events_TimerEvent
#include <nme/events/TimerEvent.h>
#endif
#ifndef INCLUDED_nme_utils_Timer
#include <nme/utils/Timer.h>
#endif
namespace nme{
namespace utils{

Void Timer_obj::__construct(double delay,Dynamic __o_repeatCount)
{
int repeatCount = __o_repeatCount.Default(0);
{
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,2,0/nme/utils/Timer.hx",23)
	if (((bool(::Math_obj::isNaN(delay)) || bool((delay < (int)0))))){
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,2,0/nme/utils/Timer.hx",24)
		hx::Throw (::nme::errors::Error_obj::__new(HX_CSTRING("The delay specified is negative or not a finite number"),null()));
	}
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,2,0/nme/utils/Timer.hx",28)
	super::__construct(null());
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,2,0/nme/utils/Timer.hx",30)
	this->delay = delay;
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,2,0/nme/utils/Timer.hx",31)
	this->repeatCount = repeatCount;
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,2,0/nme/utils/Timer.hx",32)
	this->currentCount = (int)0;
}
;
	return null();
}

Timer_obj::~Timer_obj() { }

Dynamic Timer_obj::__CreateEmpty() { return  new Timer_obj; }
hx::ObjectPtr< Timer_obj > Timer_obj::__new(double delay,Dynamic __o_repeatCount)
{  hx::ObjectPtr< Timer_obj > result = new Timer_obj();
	result->__construct(delay,__o_repeatCount);
	return result;}

Dynamic Timer_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Timer_obj > result = new Timer_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

Void Timer_obj::reset( ){
{
		HX_SOURCE_PUSH("Timer_obj::reset")
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,2,0/nme/utils/Timer.hx",38)
		if ((this->running)){
			HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,2,0/nme/utils/Timer.hx",39)
			this->stop();
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,2,0/nme/utils/Timer.hx",42)
		this->currentCount = (int)0;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Timer_obj,reset,(void))

Void Timer_obj::start( ){
{
		HX_SOURCE_PUSH("Timer_obj::start")
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,2,0/nme/utils/Timer.hx",47)
		if ((!(this->running))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,2,0/nme/utils/Timer.hx",50)
			this->running = true;
			HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,2,0/nme/utils/Timer.hx",51)
			this->timer = ::haxe::Timer_obj::__new(this->delay);
			HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,2,0/nme/utils/Timer.hx",52)
			this->timer->run = this->timer_onTimer_dyn();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Timer_obj,start,(void))

Void Timer_obj::stop( ){
{
		HX_SOURCE_PUSH("Timer_obj::stop")
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,2,0/nme/utils/Timer.hx",59)
		this->running = false;
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,2,0/nme/utils/Timer.hx",61)
		if (((this->timer != null()))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,2,0/nme/utils/Timer.hx",63)
			this->timer->stop();
			HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,2,0/nme/utils/Timer.hx",64)
			this->timer = null();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Timer_obj,stop,(void))

Void Timer_obj::timer_onTimer( ){
{
		HX_SOURCE_PUSH("Timer_obj::timer_onTimer")
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,2,0/nme/utils/Timer.hx",76)
		(this->currentCount)++;
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,2,0/nme/utils/Timer.hx",78)
		if (((bool((this->repeatCount > (int)0)) && bool((this->currentCount >= this->repeatCount))))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,2,0/nme/utils/Timer.hx",80)
			this->stop();
			HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,2,0/nme/utils/Timer.hx",81)
			this->dispatchEvent(::nme::events::TimerEvent_obj::__new(::nme::events::TimerEvent_obj::TIMER,null(),null()));
			HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,2,0/nme/utils/Timer.hx",82)
			this->dispatchEvent(::nme::events::TimerEvent_obj::__new(::nme::events::TimerEvent_obj::TIMER_COMPLETE,null(),null()));
		}
		else{
			HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,2,0/nme/utils/Timer.hx",85)
			this->dispatchEvent(::nme::events::TimerEvent_obj::__new(::nme::events::TimerEvent_obj::TIMER,null(),null()));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Timer_obj,timer_onTimer,(void))


Timer_obj::Timer_obj()
{
}

void Timer_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Timer);
	HX_MARK_MEMBER_NAME(currentCount,"currentCount");
	HX_MARK_MEMBER_NAME(delay,"delay");
	HX_MARK_MEMBER_NAME(repeatCount,"repeatCount");
	HX_MARK_MEMBER_NAME(running,"running");
	HX_MARK_MEMBER_NAME(timer,"timer");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic Timer_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"stop") ) { return stop_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"delay") ) { return delay; }
		if (HX_FIELD_EQ(inName,"timer") ) { return timer; }
		if (HX_FIELD_EQ(inName,"reset") ) { return reset_dyn(); }
		if (HX_FIELD_EQ(inName,"start") ) { return start_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"running") ) { return running; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"repeatCount") ) { return repeatCount; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"currentCount") ) { return currentCount; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"timer_onTimer") ) { return timer_onTimer_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic Timer_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"delay") ) { delay=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"timer") ) { timer=inValue.Cast< ::haxe::Timer >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"running") ) { running=inValue.Cast< bool >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"repeatCount") ) { repeatCount=inValue.Cast< int >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"currentCount") ) { currentCount=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Timer_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("currentCount"));
	outFields->push(HX_CSTRING("delay"));
	outFields->push(HX_CSTRING("repeatCount"));
	outFields->push(HX_CSTRING("running"));
	outFields->push(HX_CSTRING("timer"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("currentCount"),
	HX_CSTRING("delay"),
	HX_CSTRING("repeatCount"),
	HX_CSTRING("running"),
	HX_CSTRING("timer"),
	HX_CSTRING("reset"),
	HX_CSTRING("start"),
	HX_CSTRING("stop"),
	HX_CSTRING("timer_onTimer"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class Timer_obj::__mClass;

void Timer_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("nme.utils.Timer"), hx::TCanCast< Timer_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Timer_obj::__boot()
{
}

} // end namespace nme
} // end namespace utils
