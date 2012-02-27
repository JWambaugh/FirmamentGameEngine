#include <hxcpp.h>

#ifndef INCLUDED_box2D_dynamics_B2Body
#include <box2D/dynamics/B2Body.h>
#endif
#ifndef INCLUDED_box2D_dynamics_controllers_B2Controller
#include <box2D/dynamics/controllers/B2Controller.h>
#endif
#ifndef INCLUDED_box2D_dynamics_controllers_B2ControllerEdge
#include <box2D/dynamics/controllers/B2ControllerEdge.h>
#endif
namespace box2D{
namespace dynamics{
namespace controllers{

Void B2ControllerEdge_obj::__construct()
{
{
}
;
	return null();
}

B2ControllerEdge_obj::~B2ControllerEdge_obj() { }

Dynamic B2ControllerEdge_obj::__CreateEmpty() { return  new B2ControllerEdge_obj; }
hx::ObjectPtr< B2ControllerEdge_obj > B2ControllerEdge_obj::__new()
{  hx::ObjectPtr< B2ControllerEdge_obj > result = new B2ControllerEdge_obj();
	result->__construct();
	return result;}

Dynamic B2ControllerEdge_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2ControllerEdge_obj > result = new B2ControllerEdge_obj();
	result->__construct();
	return result;}


B2ControllerEdge_obj::B2ControllerEdge_obj()
{
}

void B2ControllerEdge_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(B2ControllerEdge);
	HX_MARK_MEMBER_NAME(controller,"controller");
	HX_MARK_MEMBER_NAME(body,"body");
	HX_MARK_MEMBER_NAME(prevBody,"prevBody");
	HX_MARK_MEMBER_NAME(nextBody,"nextBody");
	HX_MARK_MEMBER_NAME(prevController,"prevController");
	HX_MARK_MEMBER_NAME(nextController,"nextController");
	HX_MARK_END_CLASS();
}

Dynamic B2ControllerEdge_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"body") ) { return body; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"prevBody") ) { return prevBody; }
		if (HX_FIELD_EQ(inName,"nextBody") ) { return nextBody; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"controller") ) { return controller; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"prevController") ) { return prevController; }
		if (HX_FIELD_EQ(inName,"nextController") ) { return nextController; }
	}
	return super::__Field(inName);
}

Dynamic B2ControllerEdge_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"body") ) { body=inValue.Cast< ::box2D::dynamics::B2Body >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"prevBody") ) { prevBody=inValue.Cast< ::box2D::dynamics::controllers::B2ControllerEdge >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nextBody") ) { nextBody=inValue.Cast< ::box2D::dynamics::controllers::B2ControllerEdge >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"controller") ) { controller=inValue.Cast< ::box2D::dynamics::controllers::B2Controller >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"prevController") ) { prevController=inValue.Cast< ::box2D::dynamics::controllers::B2ControllerEdge >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nextController") ) { nextController=inValue.Cast< ::box2D::dynamics::controllers::B2ControllerEdge >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void B2ControllerEdge_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("controller"));
	outFields->push(HX_CSTRING("body"));
	outFields->push(HX_CSTRING("prevBody"));
	outFields->push(HX_CSTRING("nextBody"));
	outFields->push(HX_CSTRING("prevController"));
	outFields->push(HX_CSTRING("nextController"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("controller"),
	HX_CSTRING("body"),
	HX_CSTRING("prevBody"),
	HX_CSTRING("nextBody"),
	HX_CSTRING("prevController"),
	HX_CSTRING("nextController"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class B2ControllerEdge_obj::__mClass;

void B2ControllerEdge_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.dynamics.controllers.B2ControllerEdge"), hx::TCanCast< B2ControllerEdge_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void B2ControllerEdge_obj::__boot()
{
}

} // end namespace box2D
} // end namespace dynamics
} // end namespace controllers
