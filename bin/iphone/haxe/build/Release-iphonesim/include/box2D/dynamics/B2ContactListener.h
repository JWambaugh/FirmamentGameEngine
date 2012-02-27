#ifndef INCLUDED_box2D_dynamics_B2ContactListener
#define INCLUDED_box2D_dynamics_B2ContactListener

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(box2D,collision,B2Manifold)
HX_DECLARE_CLASS2(box2D,dynamics,B2ContactImpulse)
HX_DECLARE_CLASS2(box2D,dynamics,B2ContactListener)
HX_DECLARE_CLASS3(box2D,dynamics,contacts,B2Contact)
namespace box2D{
namespace dynamics{


class B2ContactListener_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef B2ContactListener_obj OBJ_;
		B2ContactListener_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< B2ContactListener_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~B2ContactListener_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("B2ContactListener"); }

		virtual Void beginContact( ::box2D::dynamics::contacts::B2Contact contact);
		Dynamic beginContact_dyn();

		virtual Void endContact( ::box2D::dynamics::contacts::B2Contact contact);
		Dynamic endContact_dyn();

		virtual Void preSolve( ::box2D::dynamics::contacts::B2Contact contact,::box2D::collision::B2Manifold oldManifold);
		Dynamic preSolve_dyn();

		virtual Void postSolve( ::box2D::dynamics::contacts::B2Contact contact,::box2D::dynamics::B2ContactImpulse impulse);
		Dynamic postSolve_dyn();

		static ::box2D::dynamics::B2ContactListener b2_defaultListener; /* REM */ 
};

} // end namespace box2D
} // end namespace dynamics

#endif /* INCLUDED_box2D_dynamics_B2ContactListener */ 
