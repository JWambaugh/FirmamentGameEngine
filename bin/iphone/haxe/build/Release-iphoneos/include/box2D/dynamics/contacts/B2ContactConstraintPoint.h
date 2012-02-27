#ifndef INCLUDED_box2D_dynamics_contacts_B2ContactConstraintPoint
#define INCLUDED_box2D_dynamics_contacts_B2ContactConstraintPoint

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(box2D,common,math,B2Vec2)
HX_DECLARE_CLASS3(box2D,dynamics,contacts,B2ContactConstraintPoint)
namespace box2D{
namespace dynamics{
namespace contacts{


class B2ContactConstraintPoint_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef B2ContactConstraintPoint_obj OBJ_;
		B2ContactConstraintPoint_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< B2ContactConstraintPoint_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~B2ContactConstraintPoint_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("B2ContactConstraintPoint"); }

		::box2D::common::math::B2Vec2 localPoint; /* REM */ 
		::box2D::common::math::B2Vec2 rA; /* REM */ 
		::box2D::common::math::B2Vec2 rB; /* REM */ 
		double normalImpulse; /* REM */ 
		double tangentImpulse; /* REM */ 
		double normalMass; /* REM */ 
		double tangentMass; /* REM */ 
		double equalizedMass; /* REM */ 
		double velocityBias; /* REM */ 
};

} // end namespace box2D
} // end namespace dynamics
} // end namespace contacts

#endif /* INCLUDED_box2D_dynamics_contacts_B2ContactConstraintPoint */ 
