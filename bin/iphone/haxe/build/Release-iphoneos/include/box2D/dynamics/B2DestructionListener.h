#ifndef INCLUDED_box2D_dynamics_B2DestructionListener
#define INCLUDED_box2D_dynamics_B2DestructionListener

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(box2D,dynamics,B2DestructionListener)
HX_DECLARE_CLASS2(box2D,dynamics,B2Fixture)
HX_DECLARE_CLASS3(box2D,dynamics,joints,B2Joint)
namespace box2D{
namespace dynamics{


class B2DestructionListener_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef B2DestructionListener_obj OBJ_;
		B2DestructionListener_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< B2DestructionListener_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~B2DestructionListener_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("B2DestructionListener"); }

		virtual Void sayGoodbyeJoint( ::box2D::dynamics::joints::B2Joint joint);
		Dynamic sayGoodbyeJoint_dyn();

		virtual Void sayGoodbyeFixture( ::box2D::dynamics::B2Fixture fixture);
		Dynamic sayGoodbyeFixture_dyn();

};

} // end namespace box2D
} // end namespace dynamics

#endif /* INCLUDED_box2D_dynamics_B2DestructionListener */ 
