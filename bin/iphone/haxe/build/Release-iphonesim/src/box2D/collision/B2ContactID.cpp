#include <hxcpp.h>

#ifndef INCLUDED_box2D_collision_B2ContactID
#include <box2D/collision/B2ContactID.h>
#endif
#ifndef INCLUDED_box2D_collision_Features
#include <box2D/collision/Features.h>
#endif
namespace box2D{
namespace collision{

Void B2ContactID_obj::__construct()
{
{
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2ContactID.hx",29)
	this->features = ::box2D::collision::Features_obj::__new();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2ContactID.hx",30)
	this->features->_m_id = hx::ObjectPtr<OBJ_>(this);
}
;
	return null();
}

B2ContactID_obj::~B2ContactID_obj() { }

Dynamic B2ContactID_obj::__CreateEmpty() { return  new B2ContactID_obj; }
hx::ObjectPtr< B2ContactID_obj > B2ContactID_obj::__new()
{  hx::ObjectPtr< B2ContactID_obj > result = new B2ContactID_obj();
	result->__construct();
	return result;}

Dynamic B2ContactID_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2ContactID_obj > result = new B2ContactID_obj();
	result->__construct();
	return result;}

Void B2ContactID_obj::set( ::box2D::collision::B2ContactID id){
{
		HX_SOURCE_PUSH("B2ContactID_obj::set")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2ContactID.hx",32)
		this->setKey(id->_key);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2ContactID_obj,set,(void))

::box2D::collision::B2ContactID B2ContactID_obj::copy( ){
	HX_SOURCE_PUSH("B2ContactID_obj::copy")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2ContactID.hx",36)
	::box2D::collision::B2ContactID id = ::box2D::collision::B2ContactID_obj::__new();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2ContactID.hx",37)
	id->setKey(this->getKey());
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2ContactID.hx",38)
	return id;
}


HX_DEFINE_DYNAMIC_FUNC0(B2ContactID_obj,copy,return )

int B2ContactID_obj::getKey( ){
	HX_SOURCE_PUSH("B2ContactID_obj::getKey")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2ContactID.hx",43)
	return this->_key;
}


HX_DEFINE_DYNAMIC_FUNC0(B2ContactID_obj,getKey,return )

int B2ContactID_obj::setKey( int value){
	HX_SOURCE_PUSH("B2ContactID_obj::setKey")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2ContactID.hx",47)
	this->_key = value;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2ContactID.hx",48)
	this->features->_referenceEdge = (int(this->_key) & int((int)255));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2ContactID.hx",49)
	this->features->_incidentEdge = (int((int(((int(this->_key) & int((int)65280)))) >> int((int)8))) & int((int)255));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2ContactID.hx",50)
	this->features->_incidentVertex = (int((int(((int(this->_key) & int((int)16711680)))) >> int((int)16))) & int((int)255));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2ContactID.hx",51)
	this->features->_flip = (int((int(((int(this->_key) & int((int)-16777216)))) >> int((int)24))) & int((int)255));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2ContactID.hx",52)
	return this->_key;
}


HX_DEFINE_DYNAMIC_FUNC1(B2ContactID_obj,setKey,return )


B2ContactID_obj::B2ContactID_obj()
{
}

void B2ContactID_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(B2ContactID);
	HX_MARK_MEMBER_NAME(key,"key");
	HX_MARK_MEMBER_NAME(features,"features");
	HX_MARK_MEMBER_NAME(_key,"_key");
	HX_MARK_END_CLASS();
}

Dynamic B2ContactID_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"set") ) { return set_dyn(); }
		if (HX_FIELD_EQ(inName,"key") ) { return getKey(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"copy") ) { return copy_dyn(); }
		if (HX_FIELD_EQ(inName,"_key") ) { return _key; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"getKey") ) { return getKey_dyn(); }
		if (HX_FIELD_EQ(inName,"setKey") ) { return setKey_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"features") ) { return features; }
	}
	return super::__Field(inName);
}

Dynamic B2ContactID_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"key") ) { return setKey(inValue); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"_key") ) { _key=inValue.Cast< int >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"features") ) { features=inValue.Cast< ::box2D::collision::Features >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void B2ContactID_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("key"));
	outFields->push(HX_CSTRING("features"));
	outFields->push(HX_CSTRING("_key"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("set"),
	HX_CSTRING("copy"),
	HX_CSTRING("key"),
	HX_CSTRING("getKey"),
	HX_CSTRING("setKey"),
	HX_CSTRING("features"),
	HX_CSTRING("_key"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class B2ContactID_obj::__mClass;

void B2ContactID_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.collision.B2ContactID"), hx::TCanCast< B2ContactID_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void B2ContactID_obj::__boot()
{
}

} // end namespace box2D
} // end namespace collision
