#ifndef INCLUDED_nme_events_TimerEvent
#define INCLUDED_nme_events_TimerEvent

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <nme/events/Event.h>
HX_DECLARE_CLASS2(nme,events,Event)
HX_DECLARE_CLASS2(nme,events,TimerEvent)
namespace nme{
namespace events{


class TimerEvent_obj : public ::nme::events::Event_obj{
	public:
		typedef ::nme::events::Event_obj super;
		typedef TimerEvent_obj OBJ_;
		TimerEvent_obj();
		Void __construct(::String type,Dynamic __o_bubbles,Dynamic __o_cancelable);

	public:
		static hx::ObjectPtr< TimerEvent_obj > __new(::String type,Dynamic __o_bubbles,Dynamic __o_cancelable);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~TimerEvent_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("TimerEvent"); }

		virtual ::nme::events::Event clone( );
		Dynamic clone_dyn();

		virtual ::String toString( );
		Dynamic toString_dyn();

		virtual Void updateAfterEvent( );
		Dynamic updateAfterEvent_dyn();

		static ::String TIMER; /* REM */ 
		static ::String TIMER_COMPLETE; /* REM */ 
};

} // end namespace nme
} // end namespace events

#endif /* INCLUDED_nme_events_TimerEvent */ 
