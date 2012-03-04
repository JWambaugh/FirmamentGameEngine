#include <hxcpp.h>

#ifndef INCLUDED_box2D_collision_B2SimplexCache
#include <box2D/collision/B2SimplexCache.h>
#endif
namespace box2D{
namespace collision{

Void B2SimplexCache_obj::__construct()
{
{
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SimplexCache.hx",30)
	this->indexA = Array_obj< int >::__new();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SimplexCache.hx",31)
	this->indexB = Array_obj< int >::__new();
}
;
	return null();
}

B2SimplexCache_obj::~B2SimplexCache_obj() { }

Dynamic B2SimplexCache_obj::__CreateEmpty() { return  new B2SimplexCache_obj; }
hx::ObjectPtr< B2SimplexCache_obj > B2SimplexCache_obj::__new()
{  hx::ObjectPtr< B2SimplexCache_obj > result = new B2SimplexCache_obj();
	result->__construct();
	return result;}

Dynamic B2SimplexCache_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2SimplexCache_obj > result = new B2SimplexCache_obj();
	result->__construct();
	return result;}


B2SimplexCache_obj::B2SimplexCache_obj()
{
}

void B2SimplexCache_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(B2SimplexCache);
	HX_MARK_MEMBER_NAME(metric,"metric");
	HX_MARK_MEMBER_NAME(count,"count");
	HX_MARK_MEMBER_NAME(indexA,"indexA");
	HX_MARK_MEMBER_NAME(indexB,"indexB");
	HX_MARK_END_CLASS();
}

Dynamic B2SimplexCache_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"count") ) { return count; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"metric") ) { return metric; }
		if (HX_FIELD_EQ(inName,"indexA") ) { return indexA; }
		if (HX_FIELD_EQ(inName,"indexB") ) { return indexB; }
	}
	return super::__Field(inName);
}

Dynamic B2SimplexCache_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"count") ) { count=inValue.Cast< int >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"metric") ) { metric=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"indexA") ) { indexA=inValue.Cast< Array< int > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"indexB") ) { indexB=inValue.Cast< Array< int > >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void B2SimplexCache_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("metric"));
	outFields->push(HX_CSTRING("count"));
	outFields->push(HX_CSTRING("indexA"));
	outFields->push(HX_CSTRING("indexB"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("metric"),
	HX_CSTRING("count"),
	HX_CSTRING("indexA"),
	HX_CSTRING("indexB"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class B2SimplexCache_obj::__mClass;

void B2SimplexCache_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.collision.B2SimplexCache"), hx::TCanCast< B2SimplexCache_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void B2SimplexCache_obj::__boot()
{
}

} // end namespace box2D
} // end namespace collision
