#include <hxcpp.h>

#ifndef INCLUDED_box2D_collision_B2ContactID
#include <box2D/collision/B2ContactID.h>
#endif
#ifndef INCLUDED_box2D_collision_B2ContactPoint
#include <box2D/collision/B2ContactPoint.h>
#endif
#ifndef INCLUDED_box2D_collision_shapes_B2Shape
#include <box2D/collision/shapes/B2Shape.h>
#endif
#ifndef INCLUDED_box2D_common_math_B2Vec2
#include <box2D/common/math/B2Vec2.h>
#endif
namespace box2D{
namespace collision{

Void B2ContactPoint_obj::__construct()
{
{
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2ContactPoint.hx",34)
	this->position = ::box2D::common::math::B2Vec2_obj::__new(null(),null());
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2ContactPoint.hx",35)
	this->velocity = ::box2D::common::math::B2Vec2_obj::__new(null(),null());
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2ContactPoint.hx",36)
	this->normal = ::box2D::common::math::B2Vec2_obj::__new(null(),null());
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2ContactPoint.hx",37)
	this->id = ::box2D::collision::B2ContactID_obj::__new();
}
;
	return null();
}

B2ContactPoint_obj::~B2ContactPoint_obj() { }

Dynamic B2ContactPoint_obj::__CreateEmpty() { return  new B2ContactPoint_obj; }
hx::ObjectPtr< B2ContactPoint_obj > B2ContactPoint_obj::__new()
{  hx::ObjectPtr< B2ContactPoint_obj > result = new B2ContactPoint_obj();
	result->__construct();
	return result;}

Dynamic B2ContactPoint_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2ContactPoint_obj > result = new B2ContactPoint_obj();
	result->__construct();
	return result;}


B2ContactPoint_obj::B2ContactPoint_obj()
{
}

void B2ContactPoint_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(B2ContactPoint);
	HX_MARK_MEMBER_NAME(shape1,"shape1");
	HX_MARK_MEMBER_NAME(shape2,"shape2");
	HX_MARK_MEMBER_NAME(position,"position");
	HX_MARK_MEMBER_NAME(velocity,"velocity");
	HX_MARK_MEMBER_NAME(normal,"normal");
	HX_MARK_MEMBER_NAME(separation,"separation");
	HX_MARK_MEMBER_NAME(friction,"friction");
	HX_MARK_MEMBER_NAME(restitution,"restitution");
	HX_MARK_MEMBER_NAME(id,"id");
	HX_MARK_END_CLASS();
}

Dynamic B2ContactPoint_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"id") ) { return id; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"shape1") ) { return shape1; }
		if (HX_FIELD_EQ(inName,"shape2") ) { return shape2; }
		if (HX_FIELD_EQ(inName,"normal") ) { return normal; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"position") ) { return position; }
		if (HX_FIELD_EQ(inName,"velocity") ) { return velocity; }
		if (HX_FIELD_EQ(inName,"friction") ) { return friction; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"separation") ) { return separation; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"restitution") ) { return restitution; }
	}
	return super::__Field(inName);
}

Dynamic B2ContactPoint_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"id") ) { id=inValue.Cast< ::box2D::collision::B2ContactID >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"shape1") ) { shape1=inValue.Cast< ::box2D::collision::shapes::B2Shape >(); return inValue; }
		if (HX_FIELD_EQ(inName,"shape2") ) { shape2=inValue.Cast< ::box2D::collision::shapes::B2Shape >(); return inValue; }
		if (HX_FIELD_EQ(inName,"normal") ) { normal=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"position") ) { position=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"velocity") ) { velocity=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"friction") ) { friction=inValue.Cast< double >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"separation") ) { separation=inValue.Cast< double >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"restitution") ) { restitution=inValue.Cast< double >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void B2ContactPoint_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("shape1"));
	outFields->push(HX_CSTRING("shape2"));
	outFields->push(HX_CSTRING("position"));
	outFields->push(HX_CSTRING("velocity"));
	outFields->push(HX_CSTRING("normal"));
	outFields->push(HX_CSTRING("separation"));
	outFields->push(HX_CSTRING("friction"));
	outFields->push(HX_CSTRING("restitution"));
	outFields->push(HX_CSTRING("id"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("shape1"),
	HX_CSTRING("shape2"),
	HX_CSTRING("position"),
	HX_CSTRING("velocity"),
	HX_CSTRING("normal"),
	HX_CSTRING("separation"),
	HX_CSTRING("friction"),
	HX_CSTRING("restitution"),
	HX_CSTRING("id"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class B2ContactPoint_obj::__mClass;

void B2ContactPoint_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.collision.B2ContactPoint"), hx::TCanCast< B2ContactPoint_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void B2ContactPoint_obj::__boot()
{
}

} // end namespace box2D
} // end namespace collision
