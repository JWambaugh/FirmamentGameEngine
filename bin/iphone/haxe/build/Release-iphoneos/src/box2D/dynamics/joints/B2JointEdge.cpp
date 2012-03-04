#include <hxcpp.h>

#ifndef INCLUDED_box2D_dynamics_B2Body
#include <box2D/dynamics/B2Body.h>
#endif
#ifndef INCLUDED_box2D_dynamics_joints_B2Joint
#include <box2D/dynamics/joints/B2Joint.h>
#endif
#ifndef INCLUDED_box2D_dynamics_joints_B2JointEdge
#include <box2D/dynamics/joints/B2JointEdge.h>
#endif
namespace box2D{
namespace dynamics{
namespace joints{

Void B2JointEdge_obj::__construct()
{
{
}
;
	return null();
}

B2JointEdge_obj::~B2JointEdge_obj() { }

Dynamic B2JointEdge_obj::__CreateEmpty() { return  new B2JointEdge_obj; }
hx::ObjectPtr< B2JointEdge_obj > B2JointEdge_obj::__new()
{  hx::ObjectPtr< B2JointEdge_obj > result = new B2JointEdge_obj();
	result->__construct();
	return result;}

Dynamic B2JointEdge_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2JointEdge_obj > result = new B2JointEdge_obj();
	result->__construct();
	return result;}


B2JointEdge_obj::B2JointEdge_obj()
{
}

void B2JointEdge_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(B2JointEdge);
	HX_MARK_MEMBER_NAME(other,"other");
	HX_MARK_MEMBER_NAME(joint,"joint");
	HX_MARK_MEMBER_NAME(prev,"prev");
	HX_MARK_MEMBER_NAME(next,"next");
	HX_MARK_END_CLASS();
}

Dynamic B2JointEdge_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"prev") ) { return prev; }
		if (HX_FIELD_EQ(inName,"next") ) { return next; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"other") ) { return other; }
		if (HX_FIELD_EQ(inName,"joint") ) { return joint; }
	}
	return super::__Field(inName);
}

Dynamic B2JointEdge_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"prev") ) { prev=inValue.Cast< ::box2D::dynamics::joints::B2JointEdge >(); return inValue; }
		if (HX_FIELD_EQ(inName,"next") ) { next=inValue.Cast< ::box2D::dynamics::joints::B2JointEdge >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"other") ) { other=inValue.Cast< ::box2D::dynamics::B2Body >(); return inValue; }
		if (HX_FIELD_EQ(inName,"joint") ) { joint=inValue.Cast< ::box2D::dynamics::joints::B2Joint >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void B2JointEdge_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("other"));
	outFields->push(HX_CSTRING("joint"));
	outFields->push(HX_CSTRING("prev"));
	outFields->push(HX_CSTRING("next"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("other"),
	HX_CSTRING("joint"),
	HX_CSTRING("prev"),
	HX_CSTRING("next"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class B2JointEdge_obj::__mClass;

void B2JointEdge_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.dynamics.joints.B2JointEdge"), hx::TCanCast< B2JointEdge_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void B2JointEdge_obj::__boot()
{
}

} // end namespace box2D
} // end namespace dynamics
} // end namespace joints
