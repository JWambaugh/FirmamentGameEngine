#ifndef INCLUDED_box2D_dynamics_B2ContactManager
#define INCLUDED_box2D_dynamics_B2ContactManager

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(box2D,collision,B2ContactPoint)
HX_DECLARE_CLASS2(box2D,collision,IBroadPhase)
HX_DECLARE_CLASS2(box2D,dynamics,B2ContactFilter)
HX_DECLARE_CLASS2(box2D,dynamics,B2ContactListener)
HX_DECLARE_CLASS2(box2D,dynamics,B2ContactManager)
HX_DECLARE_CLASS2(box2D,dynamics,B2World)
HX_DECLARE_CLASS3(box2D,dynamics,contacts,B2Contact)
HX_DECLARE_CLASS3(box2D,dynamics,contacts,B2ContactFactory)
namespace box2D{
namespace dynamics{


class B2ContactManager_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef B2ContactManager_obj OBJ_;
		B2ContactManager_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< B2ContactManager_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~B2ContactManager_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("B2ContactManager"); }

		virtual Void addPair( Dynamic proxyUserDataA,Dynamic proxyUserDataB);
		Dynamic addPair_dyn();

		virtual Void findNewContacts( );
		Dynamic findNewContacts_dyn();

		virtual Void destroy( ::box2D::dynamics::contacts::B2Contact c);
		Dynamic destroy_dyn();

		virtual Void collide( );
		Dynamic collide_dyn();

		::box2D::dynamics::B2World m_world; /* REM */ 
		::box2D::collision::IBroadPhase m_broadPhase; /* REM */ 
		::box2D::dynamics::contacts::B2Contact m_contactList; /* REM */ 
		int m_contactCount; /* REM */ 
		::box2D::dynamics::B2ContactFilter m_contactFilter; /* REM */ 
		::box2D::dynamics::B2ContactListener m_contactListener; /* REM */ 
		::box2D::dynamics::contacts::B2ContactFactory m_contactFactory; /* REM */ 
		Dynamic m_allocator; /* REM */ 
		static ::box2D::collision::B2ContactPoint s_evalCP; /* REM */ 
};

} // end namespace box2D
} // end namespace dynamics

#endif /* INCLUDED_box2D_dynamics_B2ContactManager */ 
