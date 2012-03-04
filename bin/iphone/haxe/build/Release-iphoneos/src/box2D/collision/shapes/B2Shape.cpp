#include <hxcpp.h>

#ifndef INCLUDED_box2D_collision_B2AABB
#include <box2D/collision/B2AABB.h>
#endif
#ifndef INCLUDED_box2D_collision_B2Distance
#include <box2D/collision/B2Distance.h>
#endif
#ifndef INCLUDED_box2D_collision_B2DistanceInput
#include <box2D/collision/B2DistanceInput.h>
#endif
#ifndef INCLUDED_box2D_collision_B2DistanceOutput
#include <box2D/collision/B2DistanceOutput.h>
#endif
#ifndef INCLUDED_box2D_collision_B2DistanceProxy
#include <box2D/collision/B2DistanceProxy.h>
#endif
#ifndef INCLUDED_box2D_collision_B2RayCastInput
#include <box2D/collision/B2RayCastInput.h>
#endif
#ifndef INCLUDED_box2D_collision_B2RayCastOutput
#include <box2D/collision/B2RayCastOutput.h>
#endif
#ifndef INCLUDED_box2D_collision_B2SimplexCache
#include <box2D/collision/B2SimplexCache.h>
#endif
#ifndef INCLUDED_box2D_collision_shapes_B2MassData
#include <box2D/collision/shapes/B2MassData.h>
#endif
#ifndef INCLUDED_box2D_collision_shapes_B2Shape
#include <box2D/collision/shapes/B2Shape.h>
#endif
#ifndef INCLUDED_box2D_common_B2Settings
#include <box2D/common/B2Settings.h>
#endif
#ifndef INCLUDED_box2D_common_math_B2Transform
#include <box2D/common/math/B2Transform.h>
#endif
#ifndef INCLUDED_box2D_common_math_B2Vec2
#include <box2D/common/math/B2Vec2.h>
#endif
namespace box2D{
namespace collision{
namespace shapes{

Void B2Shape_obj::__construct()
{
{
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2Shape.hx",144)
	this->m_type = ::box2D::collision::shapes::B2Shape_obj::e_unknownShape;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2Shape.hx",145)
	this->m_radius = ::box2D::common::B2Settings_obj::b2_linearSlop;
}
;
	return null();
}

B2Shape_obj::~B2Shape_obj() { }

Dynamic B2Shape_obj::__CreateEmpty() { return  new B2Shape_obj; }
hx::ObjectPtr< B2Shape_obj > B2Shape_obj::__new()
{  hx::ObjectPtr< B2Shape_obj > result = new B2Shape_obj();
	result->__construct();
	return result;}

Dynamic B2Shape_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2Shape_obj > result = new B2Shape_obj();
	result->__construct();
	return result;}

::box2D::collision::shapes::B2Shape B2Shape_obj::copy( ){
	HX_SOURCE_PUSH("B2Shape_obj::copy")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2Shape.hx",49)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(B2Shape_obj,copy,return )

Void B2Shape_obj::set( ::box2D::collision::shapes::B2Shape other){
{
		HX_SOURCE_PUSH("B2Shape_obj::set")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2Shape.hx",60)
		this->m_radius = other->m_radius;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2Shape_obj,set,(void))

int B2Shape_obj::getType( ){
	HX_SOURCE_PUSH("B2Shape_obj::getType")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2Shape.hx",71)
	return this->m_type;
}


HX_DEFINE_DYNAMIC_FUNC0(B2Shape_obj,getType,return )

bool B2Shape_obj::testPoint( ::box2D::common::math::B2Transform xf,::box2D::common::math::B2Vec2 p){
	HX_SOURCE_PUSH("B2Shape_obj::testPoint")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2Shape.hx",80)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC2(B2Shape_obj,testPoint,return )

bool B2Shape_obj::rayCast( ::box2D::collision::B2RayCastOutput output,::box2D::collision::B2RayCastInput input,::box2D::common::math::B2Transform transform){
	HX_SOURCE_PUSH("B2Shape_obj::rayCast")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2Shape.hx",89)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC3(B2Shape_obj,rayCast,return )

Void B2Shape_obj::computeAABB( ::box2D::collision::B2AABB aabb,::box2D::common::math::B2Transform xf){
{
		HX_SOURCE_PUSH("B2Shape_obj::computeAABB")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(B2Shape_obj,computeAABB,(void))

Void B2Shape_obj::computeMass( ::box2D::collision::shapes::B2MassData massData,double density){
{
		HX_SOURCE_PUSH("B2Shape_obj::computeMass")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(B2Shape_obj,computeMass,(void))

double B2Shape_obj::computeSubmergedArea( ::box2D::common::math::B2Vec2 normal,double offset,::box2D::common::math::B2Transform xf,::box2D::common::math::B2Vec2 c){
	HX_SOURCE_PUSH("B2Shape_obj::computeSubmergedArea")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2Shape.hx",119)
	return (int)0;
}


HX_DEFINE_DYNAMIC_FUNC4(B2Shape_obj,computeSubmergedArea,return )

bool B2Shape_obj::testOverlap( ::box2D::collision::shapes::B2Shape shape1,::box2D::common::math::B2Transform transform1,::box2D::collision::shapes::B2Shape shape2,::box2D::common::math::B2Transform transform2){
	HX_SOURCE_PUSH("B2Shape_obj::testOverlap")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2Shape.hx",123)
	::box2D::collision::B2DistanceInput input = ::box2D::collision::B2DistanceInput_obj::__new();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2Shape.hx",124)
	input->proxyA = ::box2D::collision::B2DistanceProxy_obj::__new();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2Shape.hx",125)
	input->proxyA->set(shape1);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2Shape.hx",126)
	input->proxyB = ::box2D::collision::B2DistanceProxy_obj::__new();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2Shape.hx",127)
	input->proxyB->set(shape2);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2Shape.hx",128)
	input->transformA = transform1;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2Shape.hx",129)
	input->transformB = transform2;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2Shape.hx",130)
	input->useRadii = true;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2Shape.hx",131)
	::box2D::collision::B2SimplexCache simplexCache = ::box2D::collision::B2SimplexCache_obj::__new();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2Shape.hx",132)
	simplexCache->count = (int)0;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2Shape.hx",133)
	::box2D::collision::B2DistanceOutput output = ::box2D::collision::B2DistanceOutput_obj::__new();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2Shape.hx",134)
	::box2D::collision::B2Distance_obj::distance(output,simplexCache,input);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2Shape.hx",135)
	return (output->distance < (10.0 * 2.2250738585072014e-308));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(B2Shape_obj,testOverlap,return )

int B2Shape_obj::e_unknownShape;

int B2Shape_obj::e_circleShape;

int B2Shape_obj::e_polygonShape;

int B2Shape_obj::e_edgeShape;

int B2Shape_obj::e_shapeTypeCount;

int B2Shape_obj::e_hitCollide;

int B2Shape_obj::e_missCollide;

int B2Shape_obj::e_startsInsideCollide;


B2Shape_obj::B2Shape_obj()
{
}

void B2Shape_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(B2Shape);
	HX_MARK_MEMBER_NAME(m_type,"m_type");
	HX_MARK_MEMBER_NAME(m_radius,"m_radius");
	HX_MARK_END_CLASS();
}

Dynamic B2Shape_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"set") ) { return set_dyn(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"copy") ) { return copy_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"m_type") ) { return m_type; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"getType") ) { return getType_dyn(); }
		if (HX_FIELD_EQ(inName,"rayCast") ) { return rayCast_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"m_radius") ) { return m_radius; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"testPoint") ) { return testPoint_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"testOverlap") ) { return testOverlap_dyn(); }
		if (HX_FIELD_EQ(inName,"e_edgeShape") ) { return e_edgeShape; }
		if (HX_FIELD_EQ(inName,"computeAABB") ) { return computeAABB_dyn(); }
		if (HX_FIELD_EQ(inName,"computeMass") ) { return computeMass_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"e_hitCollide") ) { return e_hitCollide; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"e_circleShape") ) { return e_circleShape; }
		if (HX_FIELD_EQ(inName,"e_missCollide") ) { return e_missCollide; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"e_unknownShape") ) { return e_unknownShape; }
		if (HX_FIELD_EQ(inName,"e_polygonShape") ) { return e_polygonShape; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"e_shapeTypeCount") ) { return e_shapeTypeCount; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"computeSubmergedArea") ) { return computeSubmergedArea_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"e_startsInsideCollide") ) { return e_startsInsideCollide; }
	}
	return super::__Field(inName);
}

Dynamic B2Shape_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"m_type") ) { m_type=inValue.Cast< int >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"m_radius") ) { m_radius=inValue.Cast< double >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"e_edgeShape") ) { e_edgeShape=inValue.Cast< int >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"e_hitCollide") ) { e_hitCollide=inValue.Cast< int >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"e_circleShape") ) { e_circleShape=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"e_missCollide") ) { e_missCollide=inValue.Cast< int >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"e_unknownShape") ) { e_unknownShape=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"e_polygonShape") ) { e_polygonShape=inValue.Cast< int >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"e_shapeTypeCount") ) { e_shapeTypeCount=inValue.Cast< int >(); return inValue; }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"e_startsInsideCollide") ) { e_startsInsideCollide=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void B2Shape_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("m_type"));
	outFields->push(HX_CSTRING("m_radius"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("testOverlap"),
	HX_CSTRING("e_unknownShape"),
	HX_CSTRING("e_circleShape"),
	HX_CSTRING("e_polygonShape"),
	HX_CSTRING("e_edgeShape"),
	HX_CSTRING("e_shapeTypeCount"),
	HX_CSTRING("e_hitCollide"),
	HX_CSTRING("e_missCollide"),
	HX_CSTRING("e_startsInsideCollide"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("copy"),
	HX_CSTRING("set"),
	HX_CSTRING("getType"),
	HX_CSTRING("testPoint"),
	HX_CSTRING("rayCast"),
	HX_CSTRING("computeAABB"),
	HX_CSTRING("computeMass"),
	HX_CSTRING("computeSubmergedArea"),
	HX_CSTRING("m_type"),
	HX_CSTRING("m_radius"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(B2Shape_obj::e_unknownShape,"e_unknownShape");
	HX_MARK_MEMBER_NAME(B2Shape_obj::e_circleShape,"e_circleShape");
	HX_MARK_MEMBER_NAME(B2Shape_obj::e_polygonShape,"e_polygonShape");
	HX_MARK_MEMBER_NAME(B2Shape_obj::e_edgeShape,"e_edgeShape");
	HX_MARK_MEMBER_NAME(B2Shape_obj::e_shapeTypeCount,"e_shapeTypeCount");
	HX_MARK_MEMBER_NAME(B2Shape_obj::e_hitCollide,"e_hitCollide");
	HX_MARK_MEMBER_NAME(B2Shape_obj::e_missCollide,"e_missCollide");
	HX_MARK_MEMBER_NAME(B2Shape_obj::e_startsInsideCollide,"e_startsInsideCollide");
};

Class B2Shape_obj::__mClass;

void B2Shape_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.collision.shapes.B2Shape"), hx::TCanCast< B2Shape_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void B2Shape_obj::__boot()
{
	hx::Static(e_unknownShape) = (int)-1;
	hx::Static(e_circleShape) = (int)0;
	hx::Static(e_polygonShape) = (int)1;
	hx::Static(e_edgeShape) = (int)2;
	hx::Static(e_shapeTypeCount) = (int)3;
	hx::Static(e_hitCollide) = (int)1;
	hx::Static(e_missCollide) = (int)0;
	hx::Static(e_startsInsideCollide) = (int)-1;
}

} // end namespace box2D
} // end namespace collision
} // end namespace shapes
