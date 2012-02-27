#include <hxcpp.h>

#ifndef INCLUDED_box2D_dynamics_B2DestructionListener
#include <box2D/dynamics/B2DestructionListener.h>
#endif
#ifndef INCLUDED_box2D_dynamics_B2Fixture
#include <box2D/dynamics/B2Fixture.h>
#endif
#ifndef INCLUDED_box2D_dynamics_joints_B2Joint
#include <box2D/dynamics/joints/B2Joint.h>
#endif
namespace box2D{
namespace dynamics{

Void B2DestructionListener_obj::__construct()
{
	return null();
}

B2DestructionListener_obj::~B2DestructionListener_obj() { }

Dynamic B2DestructionListener_obj::__CreateEmpty() { return  new B2DestructionListener_obj; }
hx::ObjectPtr< B2DestructionListener_obj > B2DestructionListener_obj::__new()
{  hx::ObjectPtr< B2DestructionListener_obj > result = new B2DestructionListener_obj();
	result->__construct();
	return result;}

Dynamic B2DestructionListener_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2DestructionListener_obj > result = new B2DestructionListener_obj();
	result->__construct();
	return result;}

Void B2DestructionListener_obj::sayGoodbyeJoint( ::box2D::dynamics::joints::B2Joint joint){
{
		HX_SOURCE_PUSH("B2DestructionListener_obj::sayGoodbyeJoint")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2DestructionListener_obj,sayGoodbyeJoint,(void))

Void B2DestructionListener_obj::sayGoodbyeFixture( ::box2D::dynamics::B2Fixture fixture){
{
		HX_SOURCE_PUSH("B2DestructionListener_obj::sayGoodbyeFixture")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2DestructionListener_obj,sayGoodbyeFixture,(void))


B2DestructionListener_obj::B2DestructionListener_obj()
{
}

void B2DestructionListener_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(B2DestructionListener);
	HX_MARK_END_CLASS();
}

Dynamic B2DestructionListener_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 15:
		if (HX_FIELD_EQ(inName,"sayGoodbyeJoint") ) { return sayGoodbyeJoint_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"sayGoodbyeFixture") ) { return sayGoodbyeFixture_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic B2DestructionListener_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	return super::__SetField(inName,inValue);
}

void B2DestructionListener_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("sayGoodbyeJoint"),
	HX_CSTRING("sayGoodbyeFixture"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class B2DestructionListener_obj::__mClass;

void B2DestructionListener_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.dynamics.B2DestructionListener"), hx::TCanCast< B2DestructionListener_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void B2DestructionListener_obj::__boot()
{
}

} // end namespace box2D
} // end namespace dynamics
