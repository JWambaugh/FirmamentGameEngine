#ifndef INCLUDED_box2D_dynamics_contacts_B2ContactFactory
#define INCLUDED_box2D_dynamics_contacts_B2ContactFactory

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(box2D,dynamics,B2Fixture)
HX_DECLARE_CLASS3(box2D,dynamics,contacts,B2Contact)
HX_DECLARE_CLASS3(box2D,dynamics,contacts,B2ContactFactory)
HX_DECLARE_CLASS3(box2D,dynamics,contacts,B2ContactRegister)
namespace box2D{
namespace dynamics{
namespace contacts{


class B2ContactFactory_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef B2ContactFactory_obj OBJ_;
		B2ContactFactory_obj();
		Void __construct(Dynamic allocator);

	public:
		static hx::ObjectPtr< B2ContactFactory_obj > __new(Dynamic allocator);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~B2ContactFactory_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("B2ContactFactory"); }

		virtual Void addType( Dynamic createFcn,Dynamic destroyFcn,int type1,int type2);
		Dynamic addType_dyn();

		virtual Void initializeRegisters( );
		Dynamic initializeRegisters_dyn();

		virtual ::box2D::dynamics::contacts::B2Contact create( ::box2D::dynamics::B2Fixture fixtureA,::box2D::dynamics::B2Fixture fixtureB);
		Dynamic create_dyn();

		virtual Void destroy( ::box2D::dynamics::contacts::B2Contact contact);
		Dynamic destroy_dyn();

		Array< Array< ::box2D::dynamics::contacts::B2ContactRegister > > m_registers; /* REM */ 
		Dynamic m_allocator; /* REM */ 
};

} // end namespace box2D
} // end namespace dynamics
} // end namespace contacts

#endif /* INCLUDED_box2D_dynamics_contacts_B2ContactFactory */ 
