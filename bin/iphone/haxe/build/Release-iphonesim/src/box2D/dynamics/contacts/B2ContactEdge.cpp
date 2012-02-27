#include <hxcpp.h>

#ifndef INCLUDED_box2D_dynamics_B2Body
#include <box2D/dynamics/B2Body.h>
#endif
#ifndef INCLUDED_box2D_dynamics_contacts_B2Contact
#include <box2D/dynamics/contacts/B2Contact.h>
#endif
#ifndef INCLUDED_box2D_dynamics_contacts_B2ContactEdge
#include <box2D/dynamics/contacts/B2ContactEdge.h>
#endif
namespace box2D{
namespace dynamics{
namespace contacts{

Void B2ContactEdge_obj::__construct()
{
{
}
;
	return null();
}

B2ContactEdge_obj::~B2ContactEdge_obj() { }

Dynamic B2ContactEdge_obj::__CreateEmpty() { return  new B2ContactEdge_obj; }
hx::ObjectPtr< B2ContactEdge_obj > B2ContactEdge_obj::__new()
{  hx::ObjectPtr< B2ContactEdge_obj > result = new B2ContactEdge_obj();
	result->__construct();
	return result;}

Dynamic B2ContactEdge_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2ContactEdge_obj > result = new B2ContactEdge_obj();
	result->__construct();
	return result;}


B2ContactEdge_obj::B2ContactEdge_obj()
{
}

void B2ContactEdge_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(B2ContactEdge);
	HX_MARK_MEMBER_NAME(other,"other");
	HX_MARK_MEMBER_NAME(contact,"contact");
	HX_MARK_MEMBER_NAME(prev,"prev");
	HX_MARK_MEMBER_NAME(next,"next");
	HX_MARK_END_CLASS();
}

Dynamic B2ContactEdge_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"prev") ) { return prev; }
		if (HX_FIELD_EQ(inName,"next") ) { return next; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"other") ) { return other; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"contact") ) { return contact; }
	}
	return super::__Field(inName);
}

Dynamic B2ContactEdge_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"prev") ) { prev=inValue.Cast< ::box2D::dynamics::contacts::B2ContactEdge >(); return inValue; }
		if (HX_FIELD_EQ(inName,"next") ) { next=inValue.Cast< ::box2D::dynamics::contacts::B2ContactEdge >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"other") ) { other=inValue.Cast< ::box2D::dynamics::B2Body >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"contact") ) { contact=inValue.Cast< ::box2D::dynamics::contacts::B2Contact >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void B2ContactEdge_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("other"));
	outFields->push(HX_CSTRING("contact"));
	outFields->push(HX_CSTRING("prev"));
	outFields->push(HX_CSTRING("next"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("other"),
	HX_CSTRING("contact"),
	HX_CSTRING("prev"),
	HX_CSTRING("next"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class B2ContactEdge_obj::__mClass;

void B2ContactEdge_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.dynamics.contacts.B2ContactEdge"), hx::TCanCast< B2ContactEdge_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void B2ContactEdge_obj::__boot()
{
}

} // end namespace box2D
} // end namespace dynamics
} // end namespace contacts
