#include <hxcpp.h>

#ifndef INCLUDED_box2D_dynamics_B2ContactFilter
#include <box2D/dynamics/B2ContactFilter.h>
#endif
#ifndef INCLUDED_box2D_dynamics_B2FilterData
#include <box2D/dynamics/B2FilterData.h>
#endif
#ifndef INCLUDED_box2D_dynamics_B2Fixture
#include <box2D/dynamics/B2Fixture.h>
#endif
namespace box2D{
namespace dynamics{

Void B2ContactFilter_obj::__construct()
{
{
}
;
	return null();
}

B2ContactFilter_obj::~B2ContactFilter_obj() { }

Dynamic B2ContactFilter_obj::__CreateEmpty() { return  new B2ContactFilter_obj; }
hx::ObjectPtr< B2ContactFilter_obj > B2ContactFilter_obj::__new()
{  hx::ObjectPtr< B2ContactFilter_obj > result = new B2ContactFilter_obj();
	result->__construct();
	return result;}

Dynamic B2ContactFilter_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2ContactFilter_obj > result = new B2ContactFilter_obj();
	result->__construct();
	return result;}

bool B2ContactFilter_obj::shouldCollide( ::box2D::dynamics::B2Fixture fixtureA,::box2D::dynamics::B2Fixture fixtureB){
	HX_SOURCE_PUSH("B2ContactFilter_obj::shouldCollide")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2ContactFilter.hx",37)
	::box2D::dynamics::B2FilterData filter1 = fixtureA->getFilterData();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2ContactFilter.hx",38)
	::box2D::dynamics::B2FilterData filter2 = fixtureB->getFilterData();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2ContactFilter.hx",40)
	if (((bool((filter1->groupIndex == filter2->groupIndex)) && bool((filter1->groupIndex != (int)0))))){
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2ContactFilter.hx",41)
		return (filter1->groupIndex > (int)0);
	}
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2ContactFilter.hx",45)
	bool collide = (bool((((int(filter1->maskBits) & int(filter2->categoryBits))) != (int)0)) && bool((((int(filter1->categoryBits) & int(filter2->maskBits))) != (int)0)));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2ContactFilter.hx",46)
	return collide;
}


HX_DEFINE_DYNAMIC_FUNC2(B2ContactFilter_obj,shouldCollide,return )

bool B2ContactFilter_obj::rayCollide( Dynamic userData,::box2D::dynamics::B2Fixture fixture){
	HX_SOURCE_PUSH("B2ContactFilter_obj::rayCollide")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2ContactFilter.hx",59)
	if (((userData == null()))){
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2ContactFilter.hx",60)
		return true;
	}
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2ContactFilter.hx",61)
	return this->shouldCollide(hx::TCast< box2D::dynamics::B2Fixture >::cast(userData),fixture);
}


HX_DEFINE_DYNAMIC_FUNC2(B2ContactFilter_obj,rayCollide,return )

::box2D::dynamics::B2ContactFilter B2ContactFilter_obj::b2_defaultFilter;


B2ContactFilter_obj::B2ContactFilter_obj()
{
}

void B2ContactFilter_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(B2ContactFilter);
	HX_MARK_END_CLASS();
}

Dynamic B2ContactFilter_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 10:
		if (HX_FIELD_EQ(inName,"rayCollide") ) { return rayCollide_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"shouldCollide") ) { return shouldCollide_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"b2_defaultFilter") ) { return b2_defaultFilter; }
	}
	return super::__Field(inName);
}

Dynamic B2ContactFilter_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 16:
		if (HX_FIELD_EQ(inName,"b2_defaultFilter") ) { b2_defaultFilter=inValue.Cast< ::box2D::dynamics::B2ContactFilter >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void B2ContactFilter_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("b2_defaultFilter"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("shouldCollide"),
	HX_CSTRING("rayCollide"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(B2ContactFilter_obj::b2_defaultFilter,"b2_defaultFilter");
};

Class B2ContactFilter_obj::__mClass;

void B2ContactFilter_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.dynamics.B2ContactFilter"), hx::TCanCast< B2ContactFilter_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void B2ContactFilter_obj::__boot()
{
	hx::Static(b2_defaultFilter) = ::box2D::dynamics::B2ContactFilter_obj::__new();
}

} // end namespace box2D
} // end namespace dynamics
