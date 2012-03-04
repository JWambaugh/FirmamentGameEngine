#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
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
#ifndef INCLUDED_box2D_collision_shapes_B2CircleShape
#include <box2D/collision/shapes/B2CircleShape.h>
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
#ifndef INCLUDED_box2D_common_math_B2Mat22
#include <box2D/common/math/B2Mat22.h>
#endif
#ifndef INCLUDED_box2D_common_math_B2Math
#include <box2D/common/math/B2Math.h>
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

Void B2CircleShape_obj::__construct(Dynamic __o_radius)
{
double radius = __o_radius.Default(0);
{
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2CircleShape.hx",219)
	super::__construct();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2CircleShape.hx",220)
	this->m_p = ::box2D::common::math::B2Vec2_obj::__new(null(),null());
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2CircleShape.hx",221)
	this->m_type = ::box2D::collision::shapes::B2Shape_obj::e_circleShape;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2CircleShape.hx",222)
	this->m_radius = radius;
}
;
	return null();
}

B2CircleShape_obj::~B2CircleShape_obj() { }

Dynamic B2CircleShape_obj::__CreateEmpty() { return  new B2CircleShape_obj; }
hx::ObjectPtr< B2CircleShape_obj > B2CircleShape_obj::__new(Dynamic __o_radius)
{  hx::ObjectPtr< B2CircleShape_obj > result = new B2CircleShape_obj();
	result->__construct(__o_radius);
	return result;}

Dynamic B2CircleShape_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2CircleShape_obj > result = new B2CircleShape_obj();
	result->__construct(inArgs[0]);
	return result;}

::box2D::collision::shapes::B2Shape B2CircleShape_obj::copy( ){
	HX_SOURCE_PUSH("B2CircleShape_obj::copy")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2CircleShape.hx",40)
	::box2D::collision::shapes::B2Shape s = ::box2D::collision::shapes::B2CircleShape_obj::__new(null());
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2CircleShape.hx",41)
	s->set(hx::ObjectPtr<OBJ_>(this));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2CircleShape.hx",42)
	return s;
}


HX_DEFINE_DYNAMIC_FUNC0(B2CircleShape_obj,copy,return )

Void B2CircleShape_obj::set( ::box2D::collision::shapes::B2Shape other){
{
		HX_SOURCE_PUSH("B2CircleShape_obj::set")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2CircleShape.hx",47)
		this->super::set(other);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2CircleShape.hx",48)
		if ((::Std_obj::is(other,hx::ClassOf< ::box2D::collision::shapes::B2CircleShape >()))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2CircleShape.hx",50)
			::box2D::collision::shapes::B2CircleShape other2 = hx::TCast< box2D::collision::shapes::B2CircleShape >::cast(other);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2CircleShape.hx",51)
			this->m_p->setV(other2->m_p);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2CircleShape_obj,set,(void))

bool B2CircleShape_obj::testPoint( ::box2D::common::math::B2Transform transform,::box2D::common::math::B2Vec2 p){
	HX_SOURCE_PUSH("B2CircleShape_obj::testPoint")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2CircleShape.hx",60)
	::box2D::common::math::B2Mat22 tMat = transform->R;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2CircleShape.hx",61)
	double dX = (transform->position->x + (((tMat->col1->x * this->m_p->x) + (tMat->col2->x * this->m_p->y))));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2CircleShape.hx",62)
	double dY = (transform->position->y + (((tMat->col1->y * this->m_p->x) + (tMat->col2->y * this->m_p->y))));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2CircleShape.hx",64)
	dX = (p->x - dX);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2CircleShape.hx",65)
	dY = (p->y - dY);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2CircleShape.hx",67)
	return (((dX * dX) + (dY * dY)) <= (this->m_radius * this->m_radius));
}


HX_DEFINE_DYNAMIC_FUNC2(B2CircleShape_obj,testPoint,return )

bool B2CircleShape_obj::rayCast( ::box2D::collision::B2RayCastOutput output,::box2D::collision::B2RayCastInput input,::box2D::common::math::B2Transform transform){
	HX_SOURCE_PUSH("B2CircleShape_obj::rayCast")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2CircleShape.hx",76)
	::box2D::common::math::B2Mat22 tMat = transform->R;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2CircleShape.hx",77)
	double positionX = (transform->position->x + (((tMat->col1->x * this->m_p->x) + (tMat->col2->x * this->m_p->y))));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2CircleShape.hx",78)
	double positionY = (transform->position->y + (((tMat->col1->y * this->m_p->x) + (tMat->col2->y * this->m_p->y))));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2CircleShape.hx",81)
	double sX = (input->p1->x - positionX);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2CircleShape.hx",82)
	double sY = (input->p1->y - positionY);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2CircleShape.hx",84)
	double b = (((sX * sX) + (sY * sY)) - (this->m_radius * this->m_radius));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2CircleShape.hx",96)
	double rX = (input->p2->x - input->p1->x);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2CircleShape.hx",97)
	double rY = (input->p2->y - input->p1->y);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2CircleShape.hx",99)
	double c = ((sX * rX) + (sY * rY));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2CircleShape.hx",101)
	double rr = ((rX * rX) + (rY * rY));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2CircleShape.hx",102)
	double sigma = ((c * c) - (rr * b));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2CircleShape.hx",105)
	if (((bool((sigma < 0.0)) || bool((rr < 2.2250738585072014e-308))))){
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2CircleShape.hx",106)
		return false;
	}
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2CircleShape.hx",111)
	double a = -(((c + ::Math_obj::sqrt(sigma))));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2CircleShape.hx",114)
	if (((bool((0.0 <= a)) && bool((a <= (input->maxFraction * rr)))))){
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2CircleShape.hx",116)
		hx::DivEq(a,rr);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2CircleShape.hx",117)
		output->fraction = a;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2CircleShape.hx",119)
		output->normal->x = (sX + (a * rX));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2CircleShape.hx",120)
		output->normal->y = (sY + (a * rY));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2CircleShape.hx",121)
		output->normal->normalize();
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2CircleShape.hx",122)
		return true;
	}
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2CircleShape.hx",125)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC3(B2CircleShape_obj,rayCast,return )

Void B2CircleShape_obj::computeAABB( ::box2D::collision::B2AABB aabb,::box2D::common::math::B2Transform transform){
{
		HX_SOURCE_PUSH("B2CircleShape_obj::computeAABB")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2CircleShape.hx",133)
		::box2D::common::math::B2Mat22 tMat = transform->R;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2CircleShape.hx",134)
		double pX = (transform->position->x + (((tMat->col1->x * this->m_p->x) + (tMat->col2->x * this->m_p->y))));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2CircleShape.hx",135)
		double pY = (transform->position->y + (((tMat->col1->y * this->m_p->x) + (tMat->col2->y * this->m_p->y))));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2CircleShape.hx",136)
		aabb->lowerBound->set((pX - this->m_radius),(pY - this->m_radius));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2CircleShape.hx",137)
		aabb->upperBound->set((pX + this->m_radius),(pY + this->m_radius));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(B2CircleShape_obj,computeAABB,(void))

Void B2CircleShape_obj::computeMass( ::box2D::collision::shapes::B2MassData massData,double density){
{
		HX_SOURCE_PUSH("B2CircleShape_obj::computeMass")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2CircleShape.hx",144)
		massData->mass = (((density * ::box2D::common::B2Settings_obj::b2_pi) * this->m_radius) * this->m_radius);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2CircleShape.hx",145)
		massData->center->setV(this->m_p);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2CircleShape.hx",149)
		massData->I = (massData->mass * ((((0.5 * this->m_radius) * this->m_radius) + (((this->m_p->x * this->m_p->x) + (this->m_p->y * this->m_p->y))))));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(B2CircleShape_obj,computeMass,(void))

double B2CircleShape_obj::computeSubmergedArea( ::box2D::common::math::B2Vec2 normal,double offset,::box2D::common::math::B2Transform xf,::box2D::common::math::B2Vec2 c){
	HX_SOURCE_PUSH("B2CircleShape_obj::computeSubmergedArea")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2CircleShape.hx",161)
	::box2D::common::math::B2Vec2 p = ::box2D::common::math::B2Math_obj::mulX(xf,this->m_p);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2CircleShape.hx",162)
	double l = -(((::box2D::common::math::B2Math_obj::dot(normal,p) - offset)));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2CircleShape.hx",164)
	if (((l < (-(this->m_radius) + 2.2250738585072014e-308)))){
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2CircleShape.hx",165)
		return (int)0;
	}
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2CircleShape.hx",169)
	if (((l > this->m_radius))){
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2CircleShape.hx",172)
		c->setV(p);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2CircleShape.hx",173)
		return ((::Math_obj::PI * this->m_radius) * this->m_radius);
	}
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2CircleShape.hx",177)
	double r2 = (this->m_radius * this->m_radius);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2CircleShape.hx",178)
	double l2 = (l * l);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2CircleShape.hx",179)
	double area = ((r2 * ((::Math_obj::asin((double(l) / double(this->m_radius))) + (double(::Math_obj::PI) / double((int)2))))) + (l * ::Math_obj::sqrt((r2 - l2))));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2CircleShape.hx",180)
	double com = (double(((double((int)-2) / double((int)3)) * ::Math_obj::pow((r2 - l2),1.5))) / double(area));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2CircleShape.hx",182)
	c->x = (p->x + (normal->x * com));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2CircleShape.hx",183)
	c->y = (p->y + (normal->y * com));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2CircleShape.hx",185)
	return area;
}


HX_DEFINE_DYNAMIC_FUNC4(B2CircleShape_obj,computeSubmergedArea,return )

::box2D::common::math::B2Vec2 B2CircleShape_obj::getLocalPosition( ){
	HX_SOURCE_PUSH("B2CircleShape_obj::getLocalPosition")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2CircleShape.hx",191)
	return this->m_p;
}


HX_DEFINE_DYNAMIC_FUNC0(B2CircleShape_obj,getLocalPosition,return )

Void B2CircleShape_obj::setLocalPosition( ::box2D::common::math::B2Vec2 position){
{
		HX_SOURCE_PUSH("B2CircleShape_obj::setLocalPosition")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2CircleShape.hx",198)
		this->m_p->setV(position);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2CircleShape_obj,setLocalPosition,(void))

double B2CircleShape_obj::getRadius( ){
	HX_SOURCE_PUSH("B2CircleShape_obj::getRadius")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2CircleShape.hx",206)
	return this->m_radius;
}


HX_DEFINE_DYNAMIC_FUNC0(B2CircleShape_obj,getRadius,return )

Void B2CircleShape_obj::setRadius( double radius){
{
		HX_SOURCE_PUSH("B2CircleShape_obj::setRadius")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2CircleShape.hx",214)
		this->m_radius = radius;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2CircleShape_obj,setRadius,(void))


B2CircleShape_obj::B2CircleShape_obj()
{
}

void B2CircleShape_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(B2CircleShape);
	HX_MARK_MEMBER_NAME(m_p,"m_p");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic B2CircleShape_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"set") ) { return set_dyn(); }
		if (HX_FIELD_EQ(inName,"m_p") ) { return m_p; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"copy") ) { return copy_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"rayCast") ) { return rayCast_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"testPoint") ) { return testPoint_dyn(); }
		if (HX_FIELD_EQ(inName,"getRadius") ) { return getRadius_dyn(); }
		if (HX_FIELD_EQ(inName,"setRadius") ) { return setRadius_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"computeAABB") ) { return computeAABB_dyn(); }
		if (HX_FIELD_EQ(inName,"computeMass") ) { return computeMass_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"getLocalPosition") ) { return getLocalPosition_dyn(); }
		if (HX_FIELD_EQ(inName,"setLocalPosition") ) { return setLocalPosition_dyn(); }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"computeSubmergedArea") ) { return computeSubmergedArea_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic B2CircleShape_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"m_p") ) { m_p=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void B2CircleShape_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("m_p"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("copy"),
	HX_CSTRING("set"),
	HX_CSTRING("testPoint"),
	HX_CSTRING("rayCast"),
	HX_CSTRING("computeAABB"),
	HX_CSTRING("computeMass"),
	HX_CSTRING("computeSubmergedArea"),
	HX_CSTRING("getLocalPosition"),
	HX_CSTRING("setLocalPosition"),
	HX_CSTRING("getRadius"),
	HX_CSTRING("setRadius"),
	HX_CSTRING("m_p"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class B2CircleShape_obj::__mClass;

void B2CircleShape_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.collision.shapes.B2CircleShape"), hx::TCanCast< B2CircleShape_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void B2CircleShape_obj::__boot()
{
}

} // end namespace box2D
} // end namespace collision
} // end namespace shapes
