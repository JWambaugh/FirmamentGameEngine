#ifndef INCLUDED_box2D_dynamics_contacts_B2CircleContact
#define INCLUDED_box2D_dynamics_contacts_B2CircleContact

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <box2D/dynamics/contacts/B2Contact.h>
HX_DECLARE_CLASS2(box2D,dynamics,B2Fixture)
HX_DECLARE_CLASS3(box2D,dynamics,contacts,B2CircleContact)
HX_DECLARE_CLASS3(box2D,dynamics,contacts,B2Contact)
namespace box2D{
namespace dynamics{
namespace contacts{


class B2CircleContact_obj : public ::box2D::dynamics::contacts::B2Contact_obj{
	public:
		typedef ::box2D::dynamics::contacts::B2Contact_obj super;
		typedef B2CircleContact_obj OBJ_;
		B2CircleContact_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< B2CircleContact_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~B2CircleContact_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("B2CircleContact"); }

		virtual Void reset( ::box2D::dynamics::B2Fixture fixtureA,::box2D::dynamics::B2Fixture fixtureB);
		Dynamic reset_dyn();

		virtual Void evaluate( );
		Dynamic evaluate_dyn();

		static ::box2D::dynamics::contacts::B2Contact create( Dynamic allocator);
		static Dynamic create_dyn();

		static Void destroy( ::box2D::dynamics::contacts::B2Contact contact,Dynamic allocator);
		static Dynamic destroy_dyn();

};

} // end namespace box2D
} // end namespace dynamics
} // end namespace contacts

#endif /* INCLUDED_box2D_dynamics_contacts_B2CircleContact */ 
