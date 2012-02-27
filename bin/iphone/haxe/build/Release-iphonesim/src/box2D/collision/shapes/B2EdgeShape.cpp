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
#ifndef INCLUDED_box2D_collision_shapes_B2EdgeShape
#include <box2D/collision/shapes/B2EdgeShape.h>
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

Void B2EdgeShape_obj::__construct(::box2D::common::math::B2Vec2 v1,::box2D::common::math::B2Vec2 v2)
{
{
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2EdgeShape.hx",344)
	super::__construct();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2EdgeShape.hx",346)
	this->s_supportVec = ::box2D::common::math::B2Vec2_obj::__new(null(),null());
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2EdgeShape.hx",347)
	this->m_v1 = ::box2D::common::math::B2Vec2_obj::__new(null(),null());
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2EdgeShape.hx",348)
	this->m_v2 = ::box2D::common::math::B2Vec2_obj::__new(null(),null());
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2EdgeShape.hx",350)
	this->m_coreV1 = ::box2D::common::math::B2Vec2_obj::__new(null(),null());
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2EdgeShape.hx",351)
	this->m_coreV2 = ::box2D::common::math::B2Vec2_obj::__new(null(),null());
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2EdgeShape.hx",353)
	this->m_normal = ::box2D::common::math::B2Vec2_obj::__new(null(),null());
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2EdgeShape.hx",355)
	this->m_direction = ::box2D::common::math::B2Vec2_obj::__new(null(),null());
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2EdgeShape.hx",357)
	this->m_cornerDir1 = ::box2D::common::math::B2Vec2_obj::__new(null(),null());
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2EdgeShape.hx",359)
	this->m_cornerDir2 = ::box2D::common::math::B2Vec2_obj::__new(null(),null());
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2EdgeShape.hx",361)
	this->m_type = ::box2D::collision::shapes::B2Shape_obj::e_edgeShape;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2EdgeShape.hx",363)
	this->m_prevEdge = null();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2EdgeShape.hx",364)
	this->m_nextEdge = null();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2EdgeShape.hx",366)
	this->m_v1 = v1;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2EdgeShape.hx",367)
	this->m_v2 = v2;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2EdgeShape.hx",369)
	this->m_direction->set((this->m_v2->x - this->m_v1->x),(this->m_v2->y - this->m_v1->y));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2EdgeShape.hx",370)
	this->m_length = this->m_direction->normalize();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2EdgeShape.hx",371)
	this->m_normal->set(this->m_direction->y,-(this->m_direction->x));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2EdgeShape.hx",373)
	this->m_coreV1->set(((-(::box2D::common::B2Settings_obj::b2_toiSlop) * ((this->m_normal->x - this->m_direction->x))) + this->m_v1->x),((-(::box2D::common::B2Settings_obj::b2_toiSlop) * ((this->m_normal->y - this->m_direction->y))) + this->m_v1->y));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2EdgeShape.hx",375)
	this->m_coreV2->set(((-(::box2D::common::B2Settings_obj::b2_toiSlop) * ((this->m_normal->x + this->m_direction->x))) + this->m_v2->x),((-(::box2D::common::B2Settings_obj::b2_toiSlop) * ((this->m_normal->y + this->m_direction->y))) + this->m_v2->y));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2EdgeShape.hx",378)
	this->m_cornerDir1 = this->m_normal;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2EdgeShape.hx",379)
	this->m_cornerDir2->set(-(this->m_normal->x),-(this->m_normal->y));
}
;
	return null();
}

B2EdgeShape_obj::~B2EdgeShape_obj() { }

Dynamic B2EdgeShape_obj::__CreateEmpty() { return  new B2EdgeShape_obj; }
hx::ObjectPtr< B2EdgeShape_obj > B2EdgeShape_obj::__new(::box2D::common::math::B2Vec2 v1,::box2D::common::math::B2Vec2 v2)
{  hx::ObjectPtr< B2EdgeShape_obj > result = new B2EdgeShape_obj();
	result->__construct(v1,v2);
	return result;}

Dynamic B2EdgeShape_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2EdgeShape_obj > result = new B2EdgeShape_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

bool B2EdgeShape_obj::testPoint( ::box2D::common::math::B2Transform transform,::box2D::common::math::B2Vec2 p){
	HX_SOURCE_PUSH("B2EdgeShape_obj::testPoint")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2EdgeShape.hx",42)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC2(B2EdgeShape_obj,testPoint,return )

bool B2EdgeShape_obj::rayCast( ::box2D::collision::B2RayCastOutput output,::box2D::collision::B2RayCastInput input,::box2D::common::math::B2Transform transform){
	HX_SOURCE_PUSH("B2EdgeShape_obj::rayCast")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2EdgeShape.hx",51)
	::box2D::common::math::B2Mat22 tMat;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2EdgeShape.hx",52)
	double rX = (input->p2->x - input->p1->x);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2EdgeShape.hx",53)
	double rY = (input->p2->y - input->p1->y);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2EdgeShape.hx",56)
	tMat = transform->R;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2EdgeShape.hx",57)
	double v1X = (transform->position->x + (((tMat->col1->x * this->m_v1->x) + (tMat->col2->x * this->m_v1->y))));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2EdgeShape.hx",58)
	double v1Y = (transform->position->y + (((tMat->col1->y * this->m_v1->x) + (tMat->col2->y * this->m_v1->y))));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2EdgeShape.hx",61)
	double nX = ((transform->position->y + (((tMat->col1->y * this->m_v2->x) + (tMat->col2->y * this->m_v2->y)))) - v1Y);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2EdgeShape.hx",62)
	double nY = -((((transform->position->x + (((tMat->col1->x * this->m_v2->x) + (tMat->col2->x * this->m_v2->y)))) - v1X)));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2EdgeShape.hx",64)
	double k_slop = (100.0 * 2.2250738585072014e-308);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2EdgeShape.hx",65)
	double denom = -((((rX * nX) + (rY * nY))));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2EdgeShape.hx",68)
	if (((denom > k_slop))){
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2EdgeShape.hx",71)
		double bX = (input->p1->x - v1X);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2EdgeShape.hx",72)
		double bY = (input->p1->y - v1Y);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2EdgeShape.hx",73)
		double a = ((bX * nX) + (bY * nY));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2EdgeShape.hx",75)
		if (((bool((0.0 <= a)) && bool((a <= (input->maxFraction * denom)))))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2EdgeShape.hx",77)
			double mu2 = ((-(rX) * bY) + (rY * bX));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2EdgeShape.hx",80)
			if (((bool(((-(k_slop) * denom) <= mu2)) && bool((mu2 <= (denom * ((1.0 + k_slop)))))))){
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2EdgeShape.hx",82)
				hx::DivEq(a,denom);
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2EdgeShape.hx",83)
				output->fraction = a;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2EdgeShape.hx",84)
				double nLen = ::Math_obj::sqrt(((nX * nX) + (nY * nY)));
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2EdgeShape.hx",85)
				output->normal->x = (double(nX) / double(nLen));
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2EdgeShape.hx",86)
				output->normal->y = (double(nY) / double(nLen));
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2EdgeShape.hx",87)
				return true;
			}
		}
	}
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2EdgeShape.hx",92)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC3(B2EdgeShape_obj,rayCast,return )

Void B2EdgeShape_obj::computeAABB( ::box2D::collision::B2AABB aabb,::box2D::common::math::B2Transform transform){
{
		HX_SOURCE_PUSH("B2EdgeShape_obj::computeAABB")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2EdgeShape.hx",99)
		::box2D::common::math::B2Mat22 tMat = transform->R;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2EdgeShape.hx",101)
		double v1X = (transform->position->x + (((tMat->col1->x * this->m_v1->x) + (tMat->col2->x * this->m_v1->y))));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2EdgeShape.hx",102)
		double v1Y = (transform->position->y + (((tMat->col1->y * this->m_v1->x) + (tMat->col2->y * this->m_v1->y))));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2EdgeShape.hx",104)
		double v2X = (transform->position->x + (((tMat->col1->x * this->m_v2->x) + (tMat->col2->x * this->m_v2->y))));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2EdgeShape.hx",105)
		double v2Y = (transform->position->y + (((tMat->col1->y * this->m_v2->x) + (tMat->col2->y * this->m_v2->y))));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2EdgeShape.hx",106)
		if (((v1X < v2X))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2EdgeShape.hx",107)
			aabb->lowerBound->x = v1X;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2EdgeShape.hx",108)
			aabb->upperBound->x = v2X;
		}
		else{
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2EdgeShape.hx",110)
			aabb->lowerBound->x = v2X;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2EdgeShape.hx",111)
			aabb->upperBound->x = v1X;
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2EdgeShape.hx",113)
		if (((v1Y < v2Y))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2EdgeShape.hx",114)
			aabb->lowerBound->y = v1Y;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2EdgeShape.hx",115)
			aabb->upperBound->y = v2Y;
		}
		else{
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2EdgeShape.hx",117)
			aabb->lowerBound->y = v2Y;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2EdgeShape.hx",118)
			aabb->upperBound->y = v1Y;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(B2EdgeShape_obj,computeAABB,(void))

Void B2EdgeShape_obj::computeMass( ::box2D::collision::shapes::B2MassData massData,double density){
{
		HX_SOURCE_PUSH("B2EdgeShape_obj::computeMass")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2EdgeShape.hx",126)
		massData->mass = (int)0;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2EdgeShape.hx",127)
		massData->center->setV(this->m_v1);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2EdgeShape.hx",128)
		massData->I = (int)0;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(B2EdgeShape_obj,computeMass,(void))

double B2EdgeShape_obj::computeSubmergedArea( ::box2D::common::math::B2Vec2 normal,double offset,::box2D::common::math::B2Transform xf,::box2D::common::math::B2Vec2 c){
	HX_SOURCE_PUSH("B2EdgeShape_obj::computeSubmergedArea")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2EdgeShape.hx",143)
	::box2D::common::math::B2Vec2 v0 = ::box2D::common::math::B2Vec2_obj::__new((normal->x * offset),(normal->y * offset));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2EdgeShape.hx",145)
	::box2D::common::math::B2Vec2 v1 = ::box2D::common::math::B2Math_obj::mulX(xf,this->m_v1);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2EdgeShape.hx",146)
	::box2D::common::math::B2Vec2 v2 = ::box2D::common::math::B2Math_obj::mulX(xf,this->m_v2);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2EdgeShape.hx",148)
	double d1 = (::box2D::common::math::B2Math_obj::dot(normal,v1) - offset);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2EdgeShape.hx",149)
	double d2 = (::box2D::common::math::B2Math_obj::dot(normal,v2) - offset);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2EdgeShape.hx",150)
	if (((d1 > (int)0))){
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2EdgeShape.hx",151)
		if (((d2 > (int)0))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2EdgeShape.hx",153)
			return (int)0;
		}
		else{
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2EdgeShape.hx",159)
			v1->x = (((double(-(d2)) / double(((d1 - d2)))) * v1->x) + ((double(d1) / double(((d1 - d2)))) * v2->x));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2EdgeShape.hx",160)
			v1->y = (((double(-(d2)) / double(((d1 - d2)))) * v1->y) + ((double(d1) / double(((d1 - d2)))) * v2->y));
		}
	}
	else{
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2EdgeShape.hx",164)
		if (((d2 > (int)0))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2EdgeShape.hx",168)
			v2->x = (((double(-(d2)) / double(((d1 - d2)))) * v1->x) + ((double(d1) / double(((d1 - d2)))) * v2->x));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2EdgeShape.hx",169)
			v2->y = (((double(-(d2)) / double(((d1 - d2)))) * v1->y) + ((double(d1) / double(((d1 - d2)))) * v2->y));
		}
		else{
		}
	}
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2EdgeShape.hx",178)
	c->x = (double((((v0->x + v1->x) + v2->x))) / double((int)3));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2EdgeShape.hx",179)
	c->y = (double((((v0->y + v1->y) + v2->y))) / double((int)3));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2EdgeShape.hx",184)
	return (0.5 * (((((v1->x - v0->x)) * ((v2->y - v0->y))) - (((v1->y - v0->y)) * ((v2->x - v0->x))))));
}


HX_DEFINE_DYNAMIC_FUNC4(B2EdgeShape_obj,computeSubmergedArea,return )

double B2EdgeShape_obj::getLength( ){
	HX_SOURCE_PUSH("B2EdgeShape_obj::getLength")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2EdgeShape.hx",191)
	return this->m_length;
}


HX_DEFINE_DYNAMIC_FUNC0(B2EdgeShape_obj,getLength,return )

::box2D::common::math::B2Vec2 B2EdgeShape_obj::getVertex1( ){
	HX_SOURCE_PUSH("B2EdgeShape_obj::getVertex1")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2EdgeShape.hx",199)
	return this->m_v1;
}


HX_DEFINE_DYNAMIC_FUNC0(B2EdgeShape_obj,getVertex1,return )

::box2D::common::math::B2Vec2 B2EdgeShape_obj::getVertex2( ){
	HX_SOURCE_PUSH("B2EdgeShape_obj::getVertex2")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2EdgeShape.hx",207)
	return this->m_v2;
}


HX_DEFINE_DYNAMIC_FUNC0(B2EdgeShape_obj,getVertex2,return )

::box2D::common::math::B2Vec2 B2EdgeShape_obj::getCoreVertex1( ){
	HX_SOURCE_PUSH("B2EdgeShape_obj::getCoreVertex1")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2EdgeShape.hx",217)
	return this->m_coreV1;
}


HX_DEFINE_DYNAMIC_FUNC0(B2EdgeShape_obj,getCoreVertex1,return )

::box2D::common::math::B2Vec2 B2EdgeShape_obj::getCoreVertex2( ){
	HX_SOURCE_PUSH("B2EdgeShape_obj::getCoreVertex2")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2EdgeShape.hx",227)
	return this->m_coreV2;
}


HX_DEFINE_DYNAMIC_FUNC0(B2EdgeShape_obj,getCoreVertex2,return )

::box2D::common::math::B2Vec2 B2EdgeShape_obj::getNormalVector( ){
	HX_SOURCE_PUSH("B2EdgeShape_obj::getNormalVector")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2EdgeShape.hx",236)
	return this->m_normal;
}


HX_DEFINE_DYNAMIC_FUNC0(B2EdgeShape_obj,getNormalVector,return )

::box2D::common::math::B2Vec2 B2EdgeShape_obj::getDirectionVector( ){
	HX_SOURCE_PUSH("B2EdgeShape_obj::getDirectionVector")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2EdgeShape.hx",246)
	return this->m_direction;
}


HX_DEFINE_DYNAMIC_FUNC0(B2EdgeShape_obj,getDirectionVector,return )

::box2D::common::math::B2Vec2 B2EdgeShape_obj::getCorner1Vector( ){
	HX_SOURCE_PUSH("B2EdgeShape_obj::getCorner1Vector")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2EdgeShape.hx",255)
	return this->m_cornerDir1;
}


HX_DEFINE_DYNAMIC_FUNC0(B2EdgeShape_obj,getCorner1Vector,return )

::box2D::common::math::B2Vec2 B2EdgeShape_obj::getCorner2Vector( ){
	HX_SOURCE_PUSH("B2EdgeShape_obj::getCorner2Vector")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2EdgeShape.hx",264)
	return this->m_cornerDir2;
}


HX_DEFINE_DYNAMIC_FUNC0(B2EdgeShape_obj,getCorner2Vector,return )

bool B2EdgeShape_obj::corner1IsConvex( ){
	HX_SOURCE_PUSH("B2EdgeShape_obj::corner1IsConvex")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2EdgeShape.hx",273)
	return this->m_cornerConvex1;
}


HX_DEFINE_DYNAMIC_FUNC0(B2EdgeShape_obj,corner1IsConvex,return )

bool B2EdgeShape_obj::corner2IsConvex( ){
	HX_SOURCE_PUSH("B2EdgeShape_obj::corner2IsConvex")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2EdgeShape.hx",282)
	return this->m_cornerConvex2;
}


HX_DEFINE_DYNAMIC_FUNC0(B2EdgeShape_obj,corner2IsConvex,return )

::box2D::common::math::B2Vec2 B2EdgeShape_obj::getFirstVertex( ::box2D::common::math::B2Transform xf){
	HX_SOURCE_PUSH("B2EdgeShape_obj::getFirstVertex")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2EdgeShape.hx",292)
	::box2D::common::math::B2Mat22 tMat = xf->R;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2EdgeShape.hx",293)
	return ::box2D::common::math::B2Vec2_obj::__new((xf->position->x + (((tMat->col1->x * this->m_coreV1->x) + (tMat->col2->x * this->m_coreV1->y)))),(xf->position->y + (((tMat->col1->y * this->m_coreV1->x) + (tMat->col2->y * this->m_coreV1->y)))));
}


HX_DEFINE_DYNAMIC_FUNC1(B2EdgeShape_obj,getFirstVertex,return )

::box2D::collision::shapes::B2EdgeShape B2EdgeShape_obj::getNextEdge( ){
	HX_SOURCE_PUSH("B2EdgeShape_obj::getNextEdge")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2EdgeShape.hx",301)
	return this->m_nextEdge;
}


HX_DEFINE_DYNAMIC_FUNC0(B2EdgeShape_obj,getNextEdge,return )

::box2D::collision::shapes::B2EdgeShape B2EdgeShape_obj::getPrevEdge( ){
	HX_SOURCE_PUSH("B2EdgeShape_obj::getPrevEdge")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2EdgeShape.hx",309)
	return this->m_prevEdge;
}


HX_DEFINE_DYNAMIC_FUNC0(B2EdgeShape_obj,getPrevEdge,return )

::box2D::common::math::B2Vec2 B2EdgeShape_obj::support( ::box2D::common::math::B2Transform xf,double dX,double dY){
	HX_SOURCE_PUSH("B2EdgeShape_obj::support")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2EdgeShape.hx",319)
	::box2D::common::math::B2Mat22 tMat = xf->R;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2EdgeShape.hx",321)
	double v1X = (xf->position->x + (((tMat->col1->x * this->m_coreV1->x) + (tMat->col2->x * this->m_coreV1->y))));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2EdgeShape.hx",322)
	double v1Y = (xf->position->y + (((tMat->col1->y * this->m_coreV1->x) + (tMat->col2->y * this->m_coreV1->y))));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2EdgeShape.hx",325)
	double v2X = (xf->position->x + (((tMat->col1->x * this->m_coreV2->x) + (tMat->col2->x * this->m_coreV2->y))));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2EdgeShape.hx",326)
	double v2Y = (xf->position->y + (((tMat->col1->y * this->m_coreV2->x) + (tMat->col2->y * this->m_coreV2->y))));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2EdgeShape.hx",328)
	if (((((v1X * dX) + (v1Y * dY)) > ((v2X * dX) + (v2Y * dY))))){
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2EdgeShape.hx",329)
		this->s_supportVec->x = v1X;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2EdgeShape.hx",330)
		this->s_supportVec->y = v1Y;
	}
	else{
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2EdgeShape.hx",332)
		this->s_supportVec->x = v2X;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2EdgeShape.hx",333)
		this->s_supportVec->y = v2Y;
	}
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2EdgeShape.hx",335)
	return this->s_supportVec;
}


HX_DEFINE_DYNAMIC_FUNC3(B2EdgeShape_obj,support,return )

Void B2EdgeShape_obj::setPrevEdge( ::box2D::collision::shapes::B2EdgeShape edge,::box2D::common::math::B2Vec2 core,::box2D::common::math::B2Vec2 cornerDir,bool convex){
{
		HX_SOURCE_PUSH("B2EdgeShape_obj::setPrevEdge")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2EdgeShape.hx",387)
		this->m_prevEdge = edge;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2EdgeShape.hx",388)
		this->m_coreV1 = core;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2EdgeShape.hx",389)
		this->m_cornerDir1 = cornerDir;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2EdgeShape.hx",390)
		this->m_cornerConvex1 = convex;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(B2EdgeShape_obj,setPrevEdge,(void))

Void B2EdgeShape_obj::setNextEdge( ::box2D::collision::shapes::B2EdgeShape edge,::box2D::common::math::B2Vec2 core,::box2D::common::math::B2Vec2 cornerDir,bool convex){
{
		HX_SOURCE_PUSH("B2EdgeShape_obj::setNextEdge")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2EdgeShape.hx",398)
		this->m_nextEdge = edge;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2EdgeShape.hx",399)
		this->m_coreV2 = core;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2EdgeShape.hx",400)
		this->m_cornerDir2 = cornerDir;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2EdgeShape.hx",401)
		this->m_cornerConvex2 = convex;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(B2EdgeShape_obj,setNextEdge,(void))


B2EdgeShape_obj::B2EdgeShape_obj()
{
}

void B2EdgeShape_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(B2EdgeShape);
	HX_MARK_MEMBER_NAME(s_supportVec,"s_supportVec");
	HX_MARK_MEMBER_NAME(m_v1,"m_v1");
	HX_MARK_MEMBER_NAME(m_v2,"m_v2");
	HX_MARK_MEMBER_NAME(m_coreV1,"m_coreV1");
	HX_MARK_MEMBER_NAME(m_coreV2,"m_coreV2");
	HX_MARK_MEMBER_NAME(m_length,"m_length");
	HX_MARK_MEMBER_NAME(m_normal,"m_normal");
	HX_MARK_MEMBER_NAME(m_direction,"m_direction");
	HX_MARK_MEMBER_NAME(m_cornerDir1,"m_cornerDir1");
	HX_MARK_MEMBER_NAME(m_cornerDir2,"m_cornerDir2");
	HX_MARK_MEMBER_NAME(m_cornerConvex1,"m_cornerConvex1");
	HX_MARK_MEMBER_NAME(m_cornerConvex2,"m_cornerConvex2");
	HX_MARK_MEMBER_NAME(m_nextEdge,"m_nextEdge");
	HX_MARK_MEMBER_NAME(m_prevEdge,"m_prevEdge");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic B2EdgeShape_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"m_v1") ) { return m_v1; }
		if (HX_FIELD_EQ(inName,"m_v2") ) { return m_v2; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"rayCast") ) { return rayCast_dyn(); }
		if (HX_FIELD_EQ(inName,"support") ) { return support_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"m_coreV1") ) { return m_coreV1; }
		if (HX_FIELD_EQ(inName,"m_coreV2") ) { return m_coreV2; }
		if (HX_FIELD_EQ(inName,"m_length") ) { return m_length; }
		if (HX_FIELD_EQ(inName,"m_normal") ) { return m_normal; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"testPoint") ) { return testPoint_dyn(); }
		if (HX_FIELD_EQ(inName,"getLength") ) { return getLength_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"getVertex1") ) { return getVertex1_dyn(); }
		if (HX_FIELD_EQ(inName,"getVertex2") ) { return getVertex2_dyn(); }
		if (HX_FIELD_EQ(inName,"m_nextEdge") ) { return m_nextEdge; }
		if (HX_FIELD_EQ(inName,"m_prevEdge") ) { return m_prevEdge; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"computeAABB") ) { return computeAABB_dyn(); }
		if (HX_FIELD_EQ(inName,"computeMass") ) { return computeMass_dyn(); }
		if (HX_FIELD_EQ(inName,"getNextEdge") ) { return getNextEdge_dyn(); }
		if (HX_FIELD_EQ(inName,"getPrevEdge") ) { return getPrevEdge_dyn(); }
		if (HX_FIELD_EQ(inName,"setPrevEdge") ) { return setPrevEdge_dyn(); }
		if (HX_FIELD_EQ(inName,"setNextEdge") ) { return setNextEdge_dyn(); }
		if (HX_FIELD_EQ(inName,"m_direction") ) { return m_direction; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"s_supportVec") ) { return s_supportVec; }
		if (HX_FIELD_EQ(inName,"m_cornerDir1") ) { return m_cornerDir1; }
		if (HX_FIELD_EQ(inName,"m_cornerDir2") ) { return m_cornerDir2; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"getCoreVertex1") ) { return getCoreVertex1_dyn(); }
		if (HX_FIELD_EQ(inName,"getCoreVertex2") ) { return getCoreVertex2_dyn(); }
		if (HX_FIELD_EQ(inName,"getFirstVertex") ) { return getFirstVertex_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"getNormalVector") ) { return getNormalVector_dyn(); }
		if (HX_FIELD_EQ(inName,"corner1IsConvex") ) { return corner1IsConvex_dyn(); }
		if (HX_FIELD_EQ(inName,"corner2IsConvex") ) { return corner2IsConvex_dyn(); }
		if (HX_FIELD_EQ(inName,"m_cornerConvex1") ) { return m_cornerConvex1; }
		if (HX_FIELD_EQ(inName,"m_cornerConvex2") ) { return m_cornerConvex2; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"getCorner1Vector") ) { return getCorner1Vector_dyn(); }
		if (HX_FIELD_EQ(inName,"getCorner2Vector") ) { return getCorner2Vector_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"getDirectionVector") ) { return getDirectionVector_dyn(); }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"computeSubmergedArea") ) { return computeSubmergedArea_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic B2EdgeShape_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"m_v1") ) { m_v1=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_v2") ) { m_v2=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"m_coreV1") ) { m_coreV1=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_coreV2") ) { m_coreV2=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_length") ) { m_length=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_normal") ) { m_normal=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"m_nextEdge") ) { m_nextEdge=inValue.Cast< ::box2D::collision::shapes::B2EdgeShape >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_prevEdge") ) { m_prevEdge=inValue.Cast< ::box2D::collision::shapes::B2EdgeShape >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"m_direction") ) { m_direction=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"s_supportVec") ) { s_supportVec=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_cornerDir1") ) { m_cornerDir1=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_cornerDir2") ) { m_cornerDir2=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"m_cornerConvex1") ) { m_cornerConvex1=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_cornerConvex2") ) { m_cornerConvex2=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void B2EdgeShape_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("s_supportVec"));
	outFields->push(HX_CSTRING("m_v1"));
	outFields->push(HX_CSTRING("m_v2"));
	outFields->push(HX_CSTRING("m_coreV1"));
	outFields->push(HX_CSTRING("m_coreV2"));
	outFields->push(HX_CSTRING("m_length"));
	outFields->push(HX_CSTRING("m_normal"));
	outFields->push(HX_CSTRING("m_direction"));
	outFields->push(HX_CSTRING("m_cornerDir1"));
	outFields->push(HX_CSTRING("m_cornerDir2"));
	outFields->push(HX_CSTRING("m_cornerConvex1"));
	outFields->push(HX_CSTRING("m_cornerConvex2"));
	outFields->push(HX_CSTRING("m_nextEdge"));
	outFields->push(HX_CSTRING("m_prevEdge"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("testPoint"),
	HX_CSTRING("rayCast"),
	HX_CSTRING("computeAABB"),
	HX_CSTRING("computeMass"),
	HX_CSTRING("computeSubmergedArea"),
	HX_CSTRING("getLength"),
	HX_CSTRING("getVertex1"),
	HX_CSTRING("getVertex2"),
	HX_CSTRING("getCoreVertex1"),
	HX_CSTRING("getCoreVertex2"),
	HX_CSTRING("getNormalVector"),
	HX_CSTRING("getDirectionVector"),
	HX_CSTRING("getCorner1Vector"),
	HX_CSTRING("getCorner2Vector"),
	HX_CSTRING("corner1IsConvex"),
	HX_CSTRING("corner2IsConvex"),
	HX_CSTRING("getFirstVertex"),
	HX_CSTRING("getNextEdge"),
	HX_CSTRING("getPrevEdge"),
	HX_CSTRING("s_supportVec"),
	HX_CSTRING("support"),
	HX_CSTRING("setPrevEdge"),
	HX_CSTRING("setNextEdge"),
	HX_CSTRING("m_v1"),
	HX_CSTRING("m_v2"),
	HX_CSTRING("m_coreV1"),
	HX_CSTRING("m_coreV2"),
	HX_CSTRING("m_length"),
	HX_CSTRING("m_normal"),
	HX_CSTRING("m_direction"),
	HX_CSTRING("m_cornerDir1"),
	HX_CSTRING("m_cornerDir2"),
	HX_CSTRING("m_cornerConvex1"),
	HX_CSTRING("m_cornerConvex2"),
	HX_CSTRING("m_nextEdge"),
	HX_CSTRING("m_prevEdge"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class B2EdgeShape_obj::__mClass;

void B2EdgeShape_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.collision.shapes.B2EdgeShape"), hx::TCanCast< B2EdgeShape_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void B2EdgeShape_obj::__boot()
{
}

} // end namespace box2D
} // end namespace collision
} // end namespace shapes
