#ifndef INCLUDED_nme_utils_Timer
#define INCLUDED_nme_utils_Timer

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <nme/events/EventDispatcher.h>
HX_DECLARE_CLASS1(haxe,Timer)
HX_DECLARE_CLASS2(nme,events,EventDispatcher)
HX_DECLARE_CLASS2(nme,events,IEventDispatcher)
HX_DECLARE_CLASS2(nme,utils,Timer)
namespace nme{
namespace utils{


class Timer_obj : public ::nme::events::EventDispatcher_obj{
	public:
		typedef ::nme::events::EventDispatcher_obj super;
		typedef Timer_obj OBJ_;
		Timer_obj();
		Void __construct(double delay,Dynamic __o_repeatCount);

	public:
		static hx::ObjectPtr< Timer_obj > __new(double delay,Dynamic __o_repeatCount);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Timer_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("Timer"); }

		int currentCount; /* REM */ 
		double delay; /* REM */ 
		int repeatCount; /* REM */ 
		bool running; /* REM */ 
		::haxe::Timer timer; /* REM */ 
		virtual Void reset( );
		Dynamic reset_dyn();

		virtual Void start( );
		Dynamic start_dyn();

		virtual Void stop( );
		Dynamic stop_dyn();

		virtual Void timer_onTimer( );
		Dynamic timer_onTimer_dyn();

};

} // end namespace nme
} // end namespace utils

#endif /* INCLUDED_nme_utils_Timer */ 
