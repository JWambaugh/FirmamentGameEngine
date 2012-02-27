#include <hxcpp.h>

#ifndef INCLUDED_box2D_collision_B2SimplexVertex
#include <box2D/collision/B2SimplexVertex.h>
#endif
#ifndef INCLUDED_box2D_common_math_B2Vec2
#include <box2D/common/math/B2Vec2.h>
#endif
namespace box2D{
namespace collision{

Void B2SimplexVertex_obj::__construct()
{
{
}
;
	return null();
}

B2SimplexVertex_obj::~B2SimplexVertex_obj() { }

Dynamic B2SimplexVertex_obj::__CreateEmpty() { return  new B2SimplexVertex_obj; }
hx::ObjectPtr< B2SimplexVertex_obj > B2SimplexVertex_obj::__new()
{  hx::ObjectPtr< B2SimplexVertex_obj > result = new B2SimplexVertex_obj();
	result->__construct();
	return result;}

Dynamic B2SimplexVertex_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2SimplexVertex_obj > result = new B2SimplexVertex_obj();
	result->__construct();
	return result;}

Void B2SimplexVertex_obj::set( ::box2D::collision::B2SimplexVertex other){
{
		HX_SOURCE_PUSH("B2SimplexVertex_obj::set")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SimplexVertex.hx",30)
		this->wA->setV(other->wA);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SimplexVertex.hx",31)
		this->wB->setV(other->wB);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SimplexVertex.hx",32)
		this->w->setV(other->w);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SimplexVertex.hx",33)
		this->a = other->a;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SimplexVertex.hx",34)
		this->indexA = other->indexA;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SimplexVertex.hx",35)
		this->indexB = other->indexB;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2SimplexVertex_obj,set,(void))


B2SimplexVertex_obj::B2SimplexVertex_obj()
{
}

void B2SimplexVertex_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(B2SimplexVertex);
	HX_MARK_MEMBER_NAME(wA,"wA");
	HX_MARK_MEMBER_NAME(wB,"wB");
	HX_MARK_MEMBER_NAME(w,"w");
	HX_MARK_MEMBER_NAME(a,"a");
	HX_MARK_MEMBER_NAME(indexA,"indexA");
	HX_MARK_MEMBER_NAME(indexB,"indexB");
	HX_MARK_END_CLASS();
}

Dynamic B2SimplexVertex_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"w") ) { return w; }
		if (HX_FIELD_EQ(inName,"a") ) { return a; }
		break;
	case 2:
		if (HX_FIELD_EQ(inName,"wA") ) { return wA; }
		if (HX_FIELD_EQ(inName,"wB") ) { return wB; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"set") ) { return set_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"indexA") ) { return indexA; }
		if (HX_FIELD_EQ(inName,"indexB") ) { return indexB; }
	}
	return super::__Field(inName);
}

Dynamic B2SimplexVertex_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"w") ) { w=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"a") ) { a=inValue.Cast< double >(); return inValue; }
		break;
	case 2:
		if (HX_FIELD_EQ(inName,"wA") ) { wA=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"wB") ) { wB=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"indexA") ) { indexA=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"indexB") ) { indexB=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void B2SimplexVertex_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("wA"));
	outFields->push(HX_CSTRING("wB"));
	outFields->push(HX_CSTRING("w"));
	outFields->push(HX_CSTRING("a"));
	outFields->push(HX_CSTRING("indexA"));
	outFields->push(HX_CSTRING("indexB"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("set"),
	HX_CSTRING("wA"),
	HX_CSTRING("wB"),
	HX_CSTRING("w"),
	HX_CSTRING("a"),
	HX_CSTRING("indexA"),
	HX_CSTRING("indexB"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class B2SimplexVertex_obj::__mClass;

void B2SimplexVertex_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.collision.B2SimplexVertex"), hx::TCanCast< B2SimplexVertex_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void B2SimplexVertex_obj::__boot()
{
}

} // end namespace box2D
} // end namespace collision
