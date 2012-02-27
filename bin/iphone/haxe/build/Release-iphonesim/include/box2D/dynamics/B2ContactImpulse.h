#ifndef INCLUDED_box2D_dynamics_B2ContactImpulse
#define INCLUDED_box2D_dynamics_B2ContactImpulse

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(box2D,dynamics,B2ContactImpulse)
namespace box2D{
namespace dynamics{


class B2ContactImpulse_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef B2ContactImpulse_obj OBJ_;
		B2ContactImpulse_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< B2ContactImpulse_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~B2ContactImpulse_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("B2ContactImpulse"); }

		Array< double > normalImpulses; /* REM */ 
		Array< double > tangentImpulses; /* REM */ 
};

} // end namespace box2D
} // end namespace dynamics

#endif /* INCLUDED_box2D_dynamics_B2ContactImpulse */ 
