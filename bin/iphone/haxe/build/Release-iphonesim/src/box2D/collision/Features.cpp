#include <hxcpp.h>

#ifndef INCLUDED_box2D_collision_B2ContactID
#include <box2D/collision/B2ContactID.h>
#endif
#ifndef INCLUDED_box2D_collision_Features
#include <box2D/collision/Features.h>
#endif
namespace box2D{
namespace collision{

Void Features_obj::__construct()
{
{
}
;
	return null();
}

Features_obj::~Features_obj() { }

Dynamic Features_obj::__CreateEmpty() { return  new Features_obj; }
hx::ObjectPtr< Features_obj > Features_obj::__new()
{  hx::ObjectPtr< Features_obj > result = new Features_obj();
	result->__construct();
	return result;}

Dynamic Features_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Features_obj > result = new Features_obj();
	result->__construct();
	return result;}

int Features_obj::getReferenceEdge( ){
	HX_SOURCE_PUSH("Features_obj::getReferenceEdge")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/Features.hx",39)
	return this->_referenceEdge;
}


HX_DEFINE_DYNAMIC_FUNC0(Features_obj,getReferenceEdge,return )

int Features_obj::setReferenceEdge( int value){
	HX_SOURCE_PUSH("Features_obj::setReferenceEdge")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/Features.hx",43)
	this->_referenceEdge = value;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/Features.hx",44)
	this->_m_id->_key = (int((int(this->_m_id->_key) & int((int)-256))) | int((int(this->_referenceEdge) & int((int)255))));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/Features.hx",45)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(Features_obj,setReferenceEdge,return )

int Features_obj::getIncidentEdge( ){
	HX_SOURCE_PUSH("Features_obj::getIncidentEdge")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/Features.hx",54)
	return this->_incidentEdge;
}


HX_DEFINE_DYNAMIC_FUNC0(Features_obj,getIncidentEdge,return )

int Features_obj::setIncidentEdge( int value){
	HX_SOURCE_PUSH("Features_obj::setIncidentEdge")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/Features.hx",58)
	this->_incidentEdge = value;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/Features.hx",59)
	this->_m_id->_key = (int((int(this->_m_id->_key) & int((int)-65281))) | int((int((int(this->_incidentEdge) << int((int)8))) & int((int)65280))));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/Features.hx",60)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(Features_obj,setIncidentEdge,return )

int Features_obj::getIncidentVertex( ){
	HX_SOURCE_PUSH("Features_obj::getIncidentVertex")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/Features.hx",69)
	return this->_incidentVertex;
}


HX_DEFINE_DYNAMIC_FUNC0(Features_obj,getIncidentVertex,return )

int Features_obj::setIncidentVertex( int value){
	HX_SOURCE_PUSH("Features_obj::setIncidentVertex")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/Features.hx",73)
	this->_incidentVertex = value;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/Features.hx",74)
	this->_m_id->_key = (int((int(this->_m_id->_key) & int((int)-16711681))) | int((int((int(this->_incidentVertex) << int((int)16))) & int((int)16711680))));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/Features.hx",75)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(Features_obj,setIncidentVertex,return )

int Features_obj::getFlip( ){
	HX_SOURCE_PUSH("Features_obj::getFlip")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/Features.hx",84)
	return this->_flip;
}


HX_DEFINE_DYNAMIC_FUNC0(Features_obj,getFlip,return )

int Features_obj::setFlip( int value){
	HX_SOURCE_PUSH("Features_obj::setFlip")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/Features.hx",88)
	this->_flip = value;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/Features.hx",89)
	this->_m_id->_key = (int((int(this->_m_id->_key) & int((int)16777215))) | int((int((int(this->_flip) << int((int)24))) & int((int)-16777216))));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/Features.hx",90)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(Features_obj,setFlip,return )


Features_obj::Features_obj()
{
}

void Features_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Features);
	HX_MARK_MEMBER_NAME(referenceEdge,"referenceEdge");
	HX_MARK_MEMBER_NAME(_referenceEdge,"_referenceEdge");
	HX_MARK_MEMBER_NAME(incidentEdge,"incidentEdge");
	HX_MARK_MEMBER_NAME(_incidentEdge,"_incidentEdge");
	HX_MARK_MEMBER_NAME(incidentVertex,"incidentVertex");
	HX_MARK_MEMBER_NAME(_incidentVertex,"_incidentVertex");
	HX_MARK_MEMBER_NAME(flip,"flip");
	HX_MARK_MEMBER_NAME(_flip,"_flip");
	HX_MARK_MEMBER_NAME(_m_id,"_m_id");
	HX_MARK_END_CLASS();
}

Dynamic Features_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"flip") ) { return getFlip(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_flip") ) { return _flip; }
		if (HX_FIELD_EQ(inName,"_m_id") ) { return _m_id; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"getFlip") ) { return getFlip_dyn(); }
		if (HX_FIELD_EQ(inName,"setFlip") ) { return setFlip_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"incidentEdge") ) { return getIncidentEdge(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"referenceEdge") ) { return getReferenceEdge(); }
		if (HX_FIELD_EQ(inName,"_incidentEdge") ) { return _incidentEdge; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"_referenceEdge") ) { return _referenceEdge; }
		if (HX_FIELD_EQ(inName,"incidentVertex") ) { return getIncidentVertex(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"getIncidentEdge") ) { return getIncidentEdge_dyn(); }
		if (HX_FIELD_EQ(inName,"setIncidentEdge") ) { return setIncidentEdge_dyn(); }
		if (HX_FIELD_EQ(inName,"_incidentVertex") ) { return _incidentVertex; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"getReferenceEdge") ) { return getReferenceEdge_dyn(); }
		if (HX_FIELD_EQ(inName,"setReferenceEdge") ) { return setReferenceEdge_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"getIncidentVertex") ) { return getIncidentVertex_dyn(); }
		if (HX_FIELD_EQ(inName,"setIncidentVertex") ) { return setIncidentVertex_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic Features_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"flip") ) { return setFlip(inValue); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_flip") ) { _flip=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_m_id") ) { _m_id=inValue.Cast< ::box2D::collision::B2ContactID >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"incidentEdge") ) { return setIncidentEdge(inValue); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"referenceEdge") ) { return setReferenceEdge(inValue); }
		if (HX_FIELD_EQ(inName,"_incidentEdge") ) { _incidentEdge=inValue.Cast< int >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"_referenceEdge") ) { _referenceEdge=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"incidentVertex") ) { return setIncidentVertex(inValue); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"_incidentVertex") ) { _incidentVertex=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Features_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("referenceEdge"));
	outFields->push(HX_CSTRING("_referenceEdge"));
	outFields->push(HX_CSTRING("incidentEdge"));
	outFields->push(HX_CSTRING("_incidentEdge"));
	outFields->push(HX_CSTRING("incidentVertex"));
	outFields->push(HX_CSTRING("_incidentVertex"));
	outFields->push(HX_CSTRING("flip"));
	outFields->push(HX_CSTRING("_flip"));
	outFields->push(HX_CSTRING("_m_id"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("referenceEdge"),
	HX_CSTRING("getReferenceEdge"),
	HX_CSTRING("setReferenceEdge"),
	HX_CSTRING("_referenceEdge"),
	HX_CSTRING("incidentEdge"),
	HX_CSTRING("getIncidentEdge"),
	HX_CSTRING("setIncidentEdge"),
	HX_CSTRING("_incidentEdge"),
	HX_CSTRING("incidentVertex"),
	HX_CSTRING("getIncidentVertex"),
	HX_CSTRING("setIncidentVertex"),
	HX_CSTRING("_incidentVertex"),
	HX_CSTRING("flip"),
	HX_CSTRING("getFlip"),
	HX_CSTRING("setFlip"),
	HX_CSTRING("_flip"),
	HX_CSTRING("_m_id"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class Features_obj::__mClass;

void Features_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.collision.Features"), hx::TCanCast< Features_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Features_obj::__boot()
{
}

} // end namespace box2D
} // end namespace collision
