#ifndef INCLUDED_box2D_dynamics_contacts_B2EdgeAndCircleContact
#define INCLUDED_box2D_dynamics_contacts_B2EdgeAndCircleContact

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <box2D/dynamics/contacts/B2Contact.h>
HX_DECLARE_CLASS2(box2D,collision,B2Manifold)
HX_DECLARE_CLASS3(box2D,collision,shapes,B2CircleShape)
HX_DECLARE_CLASS3(box2D,collision,shapes,B2EdgeShape)
HX_DECLARE_CLASS3(box2D,collision,shapes,B2Shape)
HX_DECLARE_CLASS3(box2D,common,math,B2Transform)
HX_DECLARE_CLASS2(box2D,dynamics,B2Fixture)
HX_DECLARE_CLASS3(box2D,dynamics,contacts,B2Contact)
HX_DECLARE_CLASS3(box2D,dynamics,contacts,B2EdgeAndCircleContact)
namespace box2D{
namespace dynamics{
namespace contacts{


class B2EdgeAndCircleContact_obj : public ::box2D::dynamics::contacts::B2Contact_obj{
	public:
		typedef ::box2D::dynamics::contacts::B2Contact_obj super;
		typedef B2EdgeAndCircleContact_obj OBJ_;
		B2EdgeAndCircleContact_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< B2EdgeAndCircleContact_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~B2EdgeAndCircleContact_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("B2EdgeAndCircleContact"); }

		virtual Void reset( ::box2D::dynamics::B2Fixture fixtureA,::box2D::dynamics::B2Fixture fixtureB);
		Dynamic reset_dyn();

		virtual Void evaluate( );
		Dynamic evaluate_dyn();

		virtual Void b2CollideEdgeAndCircle( ::box2D::collision::B2Manifold manifold,::box2D::collision::shapes::B2EdgeShape edge,::box2D::common::math::B2Transform xf1,::box2D::collision::shapes::B2CircleShape circle,::box2D::common::math::B2Transform xf2);
		Dynamic b2CollideEdgeAndCircle_dyn();

		static ::box2D::dynamics::contacts::B2Contact create( Dynamic allocator);
		static Dynamic create_dyn();

		static Void destroy( ::box2D::dynamics::contacts::B2Contact contact,Dynamic allocator);
		static Dynamic destroy_dyn();

};

} // end namespace box2D
} // end namespace dynamics
} // end namespace contacts

#endif /* INCLUDED_box2D_dynamics_contacts_B2EdgeAndCircleContact */ 
