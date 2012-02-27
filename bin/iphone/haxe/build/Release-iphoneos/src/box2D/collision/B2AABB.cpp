#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_box2D_collision_B2AABB
#include <box2D/collision/B2AABB.h>
#endif
#ifndef INCLUDED_box2D_collision_B2RayCastInput
#include <box2D/collision/B2RayCastInput.h>
#endif
#ifndef INCLUDED_box2D_collision_B2RayCastOutput
#include <box2D/collision/B2RayCastOutput.h>
#endif
#ifndef INCLUDED_box2D_common_math_B2Vec2
#include <box2D/common/math/B2Vec2.h>
#endif
namespace box2D{
namespace collision{

Void B2AABB_obj::__construct()
{
{
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2AABB.hx",217)
	this->lowerBound = ::box2D::common::math::B2Vec2_obj::__new(null(),null());
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2AABB.hx",218)
	this->upperBound = ::box2D::common::math::B2Vec2_obj::__new(null(),null());
}
;
	return null();
}

B2AABB_obj::~B2AABB_obj() { }

Dynamic B2AABB_obj::__CreateEmpty() { return  new B2AABB_obj; }
hx::ObjectPtr< B2AABB_obj > B2AABB_obj::__new()
{  hx::ObjectPtr< B2AABB_obj > result = new B2AABB_obj();
	result->__construct();
	return result;}

Dynamic B2AABB_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2AABB_obj > result = new B2AABB_obj();
	result->__construct();
	return result;}

bool B2AABB_obj::isValid( ){
	HX_SOURCE_PUSH("B2AABB_obj::isValid")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2AABB.hx",36)
	double dX = (this->upperBound->x - this->lowerBound->x);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2AABB.hx",37)
	double dY = (this->upperBound->y - this->lowerBound->y);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2AABB.hx",38)
	bool valid = (bool((dX >= 0.0)) && bool((dY >= 0.0)));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2AABB.hx",39)
	valid = (bool((bool(valid) && bool(this->lowerBound->isValid()))) && bool(this->upperBound->isValid()));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2AABB.hx",40)
	return valid;
}


HX_DEFINE_DYNAMIC_FUNC0(B2AABB_obj,isValid,return )

::box2D::common::math::B2Vec2 B2AABB_obj::getCenter( ){
	HX_SOURCE_PUSH("B2AABB_obj::getCenter")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2AABB.hx",45)
	return ::box2D::common::math::B2Vec2_obj::__new((double(((this->lowerBound->x + this->upperBound->x))) / double((int)2)),(double(((this->lowerBound->y + this->upperBound->y))) / double((int)2)));
}


HX_DEFINE_DYNAMIC_FUNC0(B2AABB_obj,getCenter,return )

::box2D::common::math::B2Vec2 B2AABB_obj::getExtents( ){
	HX_SOURCE_PUSH("B2AABB_obj::getExtents")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2AABB.hx",52)
	return ::box2D::common::math::B2Vec2_obj::__new((double(((this->upperBound->x - this->lowerBound->x))) / double((int)2)),(double(((this->upperBound->y - this->lowerBound->y))) / double((int)2)));
}


HX_DEFINE_DYNAMIC_FUNC0(B2AABB_obj,getExtents,return )

bool B2AABB_obj::contains( ::box2D::collision::B2AABB aabb){
	HX_SOURCE_PUSH("B2AABB_obj::contains")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2AABB.hx",62)
	bool result = true;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2AABB.hx",63)
	result = (bool(result) && bool((this->lowerBound->x <= aabb->lowerBound->x)));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2AABB.hx",64)
	result = (bool(result) && bool((this->lowerBound->y <= aabb->lowerBound->y)));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2AABB.hx",65)
	result = (bool(result) && bool((aabb->upperBound->x <= this->upperBound->x)));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2AABB.hx",66)
	result = (bool(result) && bool((aabb->upperBound->y <= this->upperBound->y)));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2AABB.hx",67)
	return result;
}


HX_DEFINE_DYNAMIC_FUNC1(B2AABB_obj,contains,return )

bool B2AABB_obj::rayCast( ::box2D::collision::B2RayCastOutput output,::box2D::collision::B2RayCastInput input){
	HX_SOURCE_PUSH("B2AABB_obj::rayCast")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2AABB.hx",76)
	double tmin = -(1.7976931348623158e+308);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2AABB.hx",77)
	double tmax = 1.7976931348623158e+308;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2AABB.hx",79)
	double pX = input->p1->x;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2AABB.hx",80)
	double pY = input->p1->y;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2AABB.hx",81)
	double dX = (input->p2->x - input->p1->x);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2AABB.hx",82)
	double dY = (input->p2->y - input->p1->y);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2AABB.hx",83)
	double absDX = ::Math_obj::abs(dX);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2AABB.hx",84)
	double absDY = ::Math_obj::abs(dY);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2AABB.hx",86)
	::box2D::common::math::B2Vec2 normal = output->normal;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2AABB.hx",88)
	double inv_d;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2AABB.hx",89)
	double t1;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2AABB.hx",90)
	double t2;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2AABB.hx",91)
	double t3;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2AABB.hx",92)
	double s;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2AABB.hx",95)
	if (((absDX < 2.2250738585072014e-308))){
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2AABB.hx",97)
		if (((bool((pX < this->lowerBound->x)) || bool((this->upperBound->x < pX))))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2AABB.hx",100)
			return false;
		}
	}
	else{
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2AABB.hx",104)
		inv_d = (double(1.0) / double(dX));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2AABB.hx",105)
		t1 = (((this->lowerBound->x - pX)) * inv_d);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2AABB.hx",106)
		t2 = (((this->upperBound->x - pX)) * inv_d);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2AABB.hx",109)
		s = -1.0;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2AABB.hx",111)
		if (((t1 > t2))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2AABB.hx",113)
			t3 = t1;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2AABB.hx",114)
			t1 = t2;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2AABB.hx",115)
			t2 = t3;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2AABB.hx",116)
			s = 1.0;
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2AABB.hx",120)
		if (((t1 > tmin))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2AABB.hx",122)
			normal->x = s;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2AABB.hx",123)
			normal->y = (int)0;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2AABB.hx",124)
			tmin = t1;
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2AABB.hx",128)
		tmax = ::Math_obj::min(tmax,t2);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2AABB.hx",130)
		if (((tmin > tmax))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2AABB.hx",131)
			return false;
		}
	}
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2AABB.hx",135)
	if (((absDY < 2.2250738585072014e-308))){
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2AABB.hx",137)
		if (((bool((pY < this->lowerBound->y)) || bool((this->upperBound->y < pY))))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2AABB.hx",140)
			return false;
		}
	}
	else{
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2AABB.hx",144)
		inv_d = (double(1.0) / double(dY));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2AABB.hx",145)
		t1 = (((this->lowerBound->y - pY)) * inv_d);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2AABB.hx",146)
		t2 = (((this->upperBound->y - pY)) * inv_d);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2AABB.hx",149)
		s = -1.0;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2AABB.hx",151)
		if (((t1 > t2))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2AABB.hx",153)
			t3 = t1;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2AABB.hx",154)
			t1 = t2;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2AABB.hx",155)
			t2 = t3;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2AABB.hx",156)
			s = 1.0;
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2AABB.hx",160)
		if (((t1 > tmin))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2AABB.hx",162)
			normal->y = s;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2AABB.hx",163)
			normal->x = (int)0;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2AABB.hx",164)
			tmin = t1;
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2AABB.hx",168)
		tmax = ::Math_obj::min(tmax,t2);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2AABB.hx",170)
		if (((tmin > tmax))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2AABB.hx",171)
			return false;
		}
	}
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2AABB.hx",175)
	output->fraction = tmin;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2AABB.hx",176)
	return true;
}


HX_DEFINE_DYNAMIC_FUNC2(B2AABB_obj,rayCast,return )

bool B2AABB_obj::testOverlap( ::box2D::collision::B2AABB other){
	HX_SOURCE_PUSH("B2AABB_obj::testOverlap")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2AABB.hx",184)
	double d1X = (other->lowerBound->x - this->upperBound->x);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2AABB.hx",185)
	double d1Y = (other->lowerBound->y - this->upperBound->y);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2AABB.hx",186)
	double d2X = (this->lowerBound->x - other->upperBound->x);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2AABB.hx",187)
	double d2Y = (this->lowerBound->y - other->upperBound->y);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2AABB.hx",189)
	if (((bool((d1X > 0.0)) || bool((d1Y > 0.0))))){
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2AABB.hx",190)
		return false;
	}
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2AABB.hx",192)
	if (((bool((d2X > 0.0)) || bool((d2Y > 0.0))))){
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2AABB.hx",193)
		return false;
	}
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2AABB.hx",195)
	return true;
}


HX_DEFINE_DYNAMIC_FUNC1(B2AABB_obj,testOverlap,return )

Void B2AABB_obj::combine( ::box2D::collision::B2AABB aabb1,::box2D::collision::B2AABB aabb2){
{
		HX_SOURCE_PUSH("B2AABB_obj::combine")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2AABB.hx",209)
		this->lowerBound->x = ::Math_obj::min(aabb1->lowerBound->x,aabb2->lowerBound->x);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2AABB.hx",210)
		this->lowerBound->y = ::Math_obj::min(aabb1->lowerBound->y,aabb2->lowerBound->y);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2AABB.hx",211)
		this->upperBound->x = ::Math_obj::max(aabb1->upperBound->x,aabb2->upperBound->x);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2AABB.hx",212)
		this->upperBound->y = ::Math_obj::max(aabb1->upperBound->y,aabb2->upperBound->y);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(B2AABB_obj,combine,(void))


B2AABB_obj::B2AABB_obj()
{
}

void B2AABB_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(B2AABB);
	HX_MARK_MEMBER_NAME(lowerBound,"lowerBound");
	HX_MARK_MEMBER_NAME(upperBound,"upperBound");
	HX_MARK_END_CLASS();
}

Dynamic B2AABB_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"isValid") ) { return isValid_dyn(); }
		if (HX_FIELD_EQ(inName,"rayCast") ) { return rayCast_dyn(); }
		if (HX_FIELD_EQ(inName,"combine") ) { return combine_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"contains") ) { return contains_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"getCenter") ) { return getCenter_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"getExtents") ) { return getExtents_dyn(); }
		if (HX_FIELD_EQ(inName,"lowerBound") ) { return lowerBound; }
		if (HX_FIELD_EQ(inName,"upperBound") ) { return upperBound; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"testOverlap") ) { return testOverlap_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic B2AABB_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 10:
		if (HX_FIELD_EQ(inName,"lowerBound") ) { lowerBound=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"upperBound") ) { upperBound=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void B2AABB_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("lowerBound"));
	outFields->push(HX_CSTRING("upperBound"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("isValid"),
	HX_CSTRING("getCenter"),
	HX_CSTRING("getExtents"),
	HX_CSTRING("contains"),
	HX_CSTRING("rayCast"),
	HX_CSTRING("testOverlap"),
	HX_CSTRING("combine"),
	HX_CSTRING("lowerBound"),
	HX_CSTRING("upperBound"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class B2AABB_obj::__mClass;

void B2AABB_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.collision.B2AABB"), hx::TCanCast< B2AABB_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void B2AABB_obj::__boot()
{
}

} // end namespace box2D
} // end namespace collision
