#ifndef INCLUDED_box2D_dynamics_contacts_B2ContactConstraint
#define INCLUDED_box2D_dynamics_contacts_B2ContactConstraint

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(box2D,collision,B2Manifold)
HX_DECLARE_CLASS3(box2D,common,math,B2Mat22)
HX_DECLARE_CLASS3(box2D,common,math,B2Vec2)
HX_DECLARE_CLASS2(box2D,dynamics,B2Body)
HX_DECLARE_CLASS3(box2D,dynamics,contacts,B2ContactConstraint)
HX_DECLARE_CLASS3(box2D,dynamics,contacts,B2ContactConstraintPoint)
namespace box2D{
namespace dynamics{
namespace contacts{


class B2ContactConstraint_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef B2ContactConstraint_obj OBJ_;
		B2ContactConstraint_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< B2ContactConstraint_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~B2ContactConstraint_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("B2ContactConstraint"); }

		Array< ::box2D::dynamics::contacts::B2ContactConstraintPoint > points; /* REM */ 
		::box2D::common::math::B2Vec2 localPlaneNormal; /* REM */ 
		::box2D::common::math::B2Vec2 localPoint; /* REM */ 
		::box2D::common::math::B2Vec2 normal; /* REM */ 
		::box2D::common::math::B2Mat22 normalMass; /* REM */ 
		::box2D::common::math::B2Mat22 K; /* REM */ 
		::box2D::dynamics::B2Body bodyA; /* REM */ 
		::box2D::dynamics::B2Body bodyB; /* REM */ 
		int type; /* REM */ 
		double radius; /* REM */ 
		double friction; /* REM */ 
		double restitution; /* REM */ 
		int pointCount; /* REM */ 
		::box2D::collision::B2Manifold manifold; /* REM */ 
};

} // end namespace box2D
} // end namespace dynamics
} // end namespace contacts

#endif /* INCLUDED_box2D_dynamics_contacts_B2ContactConstraint */ 
