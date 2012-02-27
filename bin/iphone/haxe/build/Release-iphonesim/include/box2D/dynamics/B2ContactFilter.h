#ifndef INCLUDED_box2D_dynamics_B2ContactFilter
#define INCLUDED_box2D_dynamics_B2ContactFilter

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(box2D,dynamics,B2ContactFilter)
HX_DECLARE_CLASS2(box2D,dynamics,B2Fixture)
namespace box2D{
namespace dynamics{


class B2ContactFilter_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef B2ContactFilter_obj OBJ_;
		B2ContactFilter_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< B2ContactFilter_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~B2ContactFilter_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("B2ContactFilter"); }

		virtual bool shouldCollide( ::box2D::dynamics::B2Fixture fixtureA,::box2D::dynamics::B2Fixture fixtureB);
		Dynamic shouldCollide_dyn();

		virtual bool rayCollide( Dynamic userData,::box2D::dynamics::B2Fixture fixture);
		Dynamic rayCollide_dyn();

		static ::box2D::dynamics::B2ContactFilter b2_defaultFilter; /* REM */ 
};

} // end namespace box2D
} // end namespace dynamics

#endif /* INCLUDED_box2D_dynamics_B2ContactFilter */ 
