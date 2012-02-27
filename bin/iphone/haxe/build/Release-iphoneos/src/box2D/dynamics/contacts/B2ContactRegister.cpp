#include <hxcpp.h>

#ifndef INCLUDED_box2D_dynamics_contacts_B2Contact
#include <box2D/dynamics/contacts/B2Contact.h>
#endif
#ifndef INCLUDED_box2D_dynamics_contacts_B2ContactRegister
#include <box2D/dynamics/contacts/B2ContactRegister.h>
#endif
namespace box2D{
namespace dynamics{
namespace contacts{

Void B2ContactRegister_obj::__construct()
{
{
}
;
	return null();
}

B2ContactRegister_obj::~B2ContactRegister_obj() { }

Dynamic B2ContactRegister_obj::__CreateEmpty() { return  new B2ContactRegister_obj; }
hx::ObjectPtr< B2ContactRegister_obj > B2ContactRegister_obj::__new()
{  hx::ObjectPtr< B2ContactRegister_obj > result = new B2ContactRegister_obj();
	result->__construct();
	return result;}

Dynamic B2ContactRegister_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2ContactRegister_obj > result = new B2ContactRegister_obj();
	result->__construct();
	return result;}


B2ContactRegister_obj::B2ContactRegister_obj()
{
}

void B2ContactRegister_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(B2ContactRegister);
	HX_MARK_MEMBER_NAME(createFcn,"createFcn");
	HX_MARK_MEMBER_NAME(destroyFcn,"destroyFcn");
	HX_MARK_MEMBER_NAME(primary,"primary");
	HX_MARK_MEMBER_NAME(pool,"pool");
	HX_MARK_MEMBER_NAME(poolCount,"poolCount");
	HX_MARK_END_CLASS();
}

Dynamic B2ContactRegister_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"pool") ) { return pool; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"primary") ) { return primary; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"createFcn") ) { return createFcn; }
		if (HX_FIELD_EQ(inName,"poolCount") ) { return poolCount; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"destroyFcn") ) { return destroyFcn; }
	}
	return super::__Field(inName);
}

Dynamic B2ContactRegister_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"pool") ) { pool=inValue.Cast< ::box2D::dynamics::contacts::B2Contact >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"primary") ) { primary=inValue.Cast< bool >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"createFcn") ) { createFcn=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"poolCount") ) { poolCount=inValue.Cast< int >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"destroyFcn") ) { destroyFcn=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void B2ContactRegister_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("createFcn"));
	outFields->push(HX_CSTRING("destroyFcn"));
	outFields->push(HX_CSTRING("primary"));
	outFields->push(HX_CSTRING("pool"));
	outFields->push(HX_CSTRING("poolCount"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("createFcn"),
	HX_CSTRING("destroyFcn"),
	HX_CSTRING("primary"),
	HX_CSTRING("pool"),
	HX_CSTRING("poolCount"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class B2ContactRegister_obj::__mClass;

void B2ContactRegister_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.dynamics.contacts.B2ContactRegister"), hx::TCanCast< B2ContactRegister_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void B2ContactRegister_obj::__boot()
{
}

} // end namespace box2D
} // end namespace dynamics
} // end namespace contacts
