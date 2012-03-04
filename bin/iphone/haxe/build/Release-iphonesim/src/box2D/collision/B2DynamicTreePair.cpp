#include <hxcpp.h>

#ifndef INCLUDED_box2D_collision_B2DynamicTreeNode
#include <box2D/collision/B2DynamicTreeNode.h>
#endif
#ifndef INCLUDED_box2D_collision_B2DynamicTreePair
#include <box2D/collision/B2DynamicTreePair.h>
#endif
namespace box2D{
namespace collision{

Void B2DynamicTreePair_obj::__construct()
{
{
}
;
	return null();
}

B2DynamicTreePair_obj::~B2DynamicTreePair_obj() { }

Dynamic B2DynamicTreePair_obj::__CreateEmpty() { return  new B2DynamicTreePair_obj; }
hx::ObjectPtr< B2DynamicTreePair_obj > B2DynamicTreePair_obj::__new()
{  hx::ObjectPtr< B2DynamicTreePair_obj > result = new B2DynamicTreePair_obj();
	result->__construct();
	return result;}

Dynamic B2DynamicTreePair_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2DynamicTreePair_obj > result = new B2DynamicTreePair_obj();
	result->__construct();
	return result;}


B2DynamicTreePair_obj::B2DynamicTreePair_obj()
{
}

void B2DynamicTreePair_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(B2DynamicTreePair);
	HX_MARK_MEMBER_NAME(proxyA,"proxyA");
	HX_MARK_MEMBER_NAME(proxyB,"proxyB");
	HX_MARK_END_CLASS();
}

Dynamic B2DynamicTreePair_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"proxyA") ) { return proxyA; }
		if (HX_FIELD_EQ(inName,"proxyB") ) { return proxyB; }
	}
	return super::__Field(inName);
}

Dynamic B2DynamicTreePair_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"proxyA") ) { proxyA=inValue.Cast< ::box2D::collision::B2DynamicTreeNode >(); return inValue; }
		if (HX_FIELD_EQ(inName,"proxyB") ) { proxyB=inValue.Cast< ::box2D::collision::B2DynamicTreeNode >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void B2DynamicTreePair_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("proxyA"));
	outFields->push(HX_CSTRING("proxyB"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("proxyA"),
	HX_CSTRING("proxyB"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class B2DynamicTreePair_obj::__mClass;

void B2DynamicTreePair_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.collision.B2DynamicTreePair"), hx::TCanCast< B2DynamicTreePair_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void B2DynamicTreePair_obj::__boot()
{
}

} // end namespace box2D
} // end namespace collision
