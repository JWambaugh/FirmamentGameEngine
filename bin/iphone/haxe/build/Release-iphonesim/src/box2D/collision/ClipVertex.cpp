#include <hxcpp.h>

#ifndef INCLUDED_box2D_collision_B2ContactID
#include <box2D/collision/B2ContactID.h>
#endif
#ifndef INCLUDED_box2D_collision_ClipVertex
#include <box2D/collision/ClipVertex.h>
#endif
#ifndef INCLUDED_box2D_common_math_B2Vec2
#include <box2D/common/math/B2Vec2.h>
#endif
namespace box2D{
namespace collision{

Void ClipVertex_obj::__construct()
{
{
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/ClipVertex.hx",34)
	this->v = ::box2D::common::math::B2Vec2_obj::__new(null(),null());
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/ClipVertex.hx",35)
	this->id = ::box2D::collision::B2ContactID_obj::__new();
}
;
	return null();
}

ClipVertex_obj::~ClipVertex_obj() { }

Dynamic ClipVertex_obj::__CreateEmpty() { return  new ClipVertex_obj; }
hx::ObjectPtr< ClipVertex_obj > ClipVertex_obj::__new()
{  hx::ObjectPtr< ClipVertex_obj > result = new ClipVertex_obj();
	result->__construct();
	return result;}

Dynamic ClipVertex_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< ClipVertex_obj > result = new ClipVertex_obj();
	result->__construct();
	return result;}

Void ClipVertex_obj::set( ::box2D::collision::ClipVertex other){
{
		HX_SOURCE_PUSH("ClipVertex_obj::set")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/ClipVertex.hx",41)
		this->v->setV(other->v);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/ClipVertex.hx",42)
		this->id->set(other->id);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ClipVertex_obj,set,(void))


ClipVertex_obj::ClipVertex_obj()
{
}

void ClipVertex_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(ClipVertex);
	HX_MARK_MEMBER_NAME(v,"v");
	HX_MARK_MEMBER_NAME(id,"id");
	HX_MARK_END_CLASS();
}

Dynamic ClipVertex_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"v") ) { return v; }
		break;
	case 2:
		if (HX_FIELD_EQ(inName,"id") ) { return id; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"set") ) { return set_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic ClipVertex_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"v") ) { v=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		break;
	case 2:
		if (HX_FIELD_EQ(inName,"id") ) { id=inValue.Cast< ::box2D::collision::B2ContactID >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void ClipVertex_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("v"));
	outFields->push(HX_CSTRING("id"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("set"),
	HX_CSTRING("v"),
	HX_CSTRING("id"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class ClipVertex_obj::__mClass;

void ClipVertex_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.collision.ClipVertex"), hx::TCanCast< ClipVertex_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void ClipVertex_obj::__boot()
{
}

} // end namespace box2D
} // end namespace collision
