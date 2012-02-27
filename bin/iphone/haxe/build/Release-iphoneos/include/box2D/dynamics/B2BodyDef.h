#ifndef INCLUDED_box2D_dynamics_B2BodyDef
#define INCLUDED_box2D_dynamics_B2BodyDef

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(box2D,common,math,B2Vec2)
HX_DECLARE_CLASS2(box2D,dynamics,B2BodyDef)
namespace box2D{
namespace dynamics{


class B2BodyDef_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef B2BodyDef_obj OBJ_;
		B2BodyDef_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< B2BodyDef_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~B2BodyDef_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("B2BodyDef"); }

		int type; /* REM */ 
		::box2D::common::math::B2Vec2 position; /* REM */ 
		double angle; /* REM */ 
		::box2D::common::math::B2Vec2 linearVelocity; /* REM */ 
		double angularVelocity; /* REM */ 
		double linearDamping; /* REM */ 
		double angularDamping; /* REM */ 
		bool allowSleep; /* REM */ 
		bool awake; /* REM */ 
		bool fixedRotation; /* REM */ 
		bool bullet; /* REM */ 
		bool active; /* REM */ 
		Dynamic userData; /* REM */ 
		double inertiaScale; /* REM */ 
};

} // end namespace box2D
} // end namespace dynamics

#endif /* INCLUDED_box2D_dynamics_B2BodyDef */ 
