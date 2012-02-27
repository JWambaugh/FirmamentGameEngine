#include <hxcpp.h>

#ifndef INCLUDED_box2D_collision_B2DistanceProxy
#include <box2D/collision/B2DistanceProxy.h>
#endif
#ifndef INCLUDED_box2D_collision_B2SeparationFunction
#include <box2D/collision/B2SeparationFunction.h>
#endif
#ifndef INCLUDED_box2D_collision_B2SimplexCache
#include <box2D/collision/B2SimplexCache.h>
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

Void B2SeparationFunction_obj::__construct()
{
{
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",322)
	this->m_localPoint = ::box2D::common::math::B2Vec2_obj::__new(null(),null());
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",323)
	this->m_axis = ::box2D::common::math::B2Vec2_obj::__new(null(),null());
}
;
	return null();
}

B2SeparationFunction_obj::~B2SeparationFunction_obj() { }

Dynamic B2SeparationFunction_obj::__CreateEmpty() { return  new B2SeparationFunction_obj; }
hx::ObjectPtr< B2SeparationFunction_obj > B2SeparationFunction_obj::__new()
{  hx::ObjectPtr< B2SeparationFunction_obj > result = new B2SeparationFunction_obj();
	result->__construct();
	return result;}

Dynamic B2SeparationFunction_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2SeparationFunction_obj > result = new B2SeparationFunction_obj();
	result->__construct();
	return result;}

Void B2SeparationFunction_obj::initialize( ::box2D::collision::B2SimplexCache cache,::box2D::collision::B2DistanceProxy proxyA,::box2D::common::math::B2Transform transformA,::box2D::collision::B2DistanceProxy proxyB,::box2D::common::math::B2Transform transformB){
{
		HX_SOURCE_PUSH("B2SeparationFunction_obj::initialize")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",40)
		this->m_proxyA = proxyA;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",41)
		this->m_proxyB = proxyB;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",42)
		int count = cache->count;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",43)
		::box2D::common::B2Settings_obj::b2Assert((bool(((int)0 < count)) && bool((count < (int)3))));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",45)
		::box2D::common::math::B2Vec2 localPointA = ::box2D::common::math::B2Vec2_obj::__new(null(),null());
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",46)
		::box2D::common::math::B2Vec2 localPointA1;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",47)
		::box2D::common::math::B2Vec2 localPointA2;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",48)
		::box2D::common::math::B2Vec2 localPointB = ::box2D::common::math::B2Vec2_obj::__new(null(),null());
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",49)
		::box2D::common::math::B2Vec2 localPointB1;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",50)
		::box2D::common::math::B2Vec2 localPointB2;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",51)
		double pointAX;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",52)
		double pointAY;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",53)
		double pointBX;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",54)
		double pointBY;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",55)
		double normalX;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",56)
		double normalY;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",57)
		::box2D::common::math::B2Mat22 tMat;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",58)
		::box2D::common::math::B2Vec2 tVec;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",59)
		double s;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",60)
		double sgn;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",62)
		if (((count == (int)1))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",64)
			this->m_type = ::box2D::collision::B2SeparationFunction_obj::e_points;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",65)
			localPointA = this->m_proxyA->getVertex(cache->indexA->__get((int)0));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",66)
			localPointB = this->m_proxyB->getVertex(cache->indexB->__get((int)0));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",68)
			tVec = localPointA;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",69)
			tMat = transformA->R;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",70)
			pointAX = (transformA->position->x + (((tMat->col1->x * tVec->x) + (tMat->col2->x * tVec->y))));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",71)
			pointAY = (transformA->position->y + (((tMat->col1->y * tVec->x) + (tMat->col2->y * tVec->y))));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",73)
			tVec = localPointB;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",74)
			tMat = transformB->R;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",75)
			pointBX = (transformB->position->x + (((tMat->col1->x * tVec->x) + (tMat->col2->x * tVec->y))));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",76)
			pointBY = (transformB->position->y + (((tMat->col1->y * tVec->x) + (tMat->col2->y * tVec->y))));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",78)
			this->m_axis->x = (pointBX - pointAX);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",79)
			this->m_axis->y = (pointBY - pointAY);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",80)
			this->m_axis->normalize();
		}
		else{
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",82)
			if (((cache->indexB->__get((int)0) == cache->indexB->__get((int)1)))){
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",85)
				this->m_type = ::box2D::collision::B2SeparationFunction_obj::e_faceA;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",86)
				localPointA1 = this->m_proxyA->getVertex(cache->indexA->__get((int)0));
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",87)
				localPointA2 = this->m_proxyA->getVertex(cache->indexA->__get((int)1));
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",88)
				localPointB = this->m_proxyB->getVertex(cache->indexB->__get((int)0));
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",89)
				this->m_localPoint->x = (0.5 * ((localPointA1->x + localPointA2->x)));
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",90)
				this->m_localPoint->y = (0.5 * ((localPointA1->y + localPointA2->y)));
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",91)
				this->m_axis = ::box2D::common::math::B2Math_obj::crossVF(::box2D::common::math::B2Math_obj::subtractVV(localPointA2,localPointA1),1.0);
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",92)
				this->m_axis->normalize();
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",95)
				tVec = this->m_axis;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",96)
				tMat = transformA->R;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",97)
				normalX = ((tMat->col1->x * tVec->x) + (tMat->col2->x * tVec->y));
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",98)
				normalY = ((tMat->col1->y * tVec->x) + (tMat->col2->y * tVec->y));
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",100)
				tVec = this->m_localPoint;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",101)
				tMat = transformA->R;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",102)
				pointAX = (transformA->position->x + (((tMat->col1->x * tVec->x) + (tMat->col2->x * tVec->y))));
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",103)
				pointAY = (transformA->position->y + (((tMat->col1->y * tVec->x) + (tMat->col2->y * tVec->y))));
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",105)
				tVec = localPointB;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",106)
				tMat = transformB->R;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",107)
				pointBX = (transformB->position->x + (((tMat->col1->x * tVec->x) + (tMat->col2->x * tVec->y))));
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",108)
				pointBY = (transformB->position->y + (((tMat->col1->y * tVec->x) + (tMat->col2->y * tVec->y))));
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",111)
				s = ((((pointBX - pointAX)) * normalX) + (((pointBY - pointAY)) * normalY));
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",112)
				if (((s < 0.0))){
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",113)
					this->m_axis->negativeSelf();
				}
			}
			else{
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",117)
				if (((cache->indexA->__get((int)0) == cache->indexA->__get((int)0)))){
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",120)
					this->m_type = ::box2D::collision::B2SeparationFunction_obj::e_faceB;
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",121)
					localPointB1 = this->m_proxyB->getVertex(cache->indexB->__get((int)0));
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",122)
					localPointB2 = this->m_proxyB->getVertex(cache->indexB->__get((int)1));
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",123)
					localPointA = this->m_proxyA->getVertex(cache->indexA->__get((int)0));
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",124)
					this->m_localPoint->x = (0.5 * ((localPointB1->x + localPointB2->x)));
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",125)
					this->m_localPoint->y = (0.5 * ((localPointB1->y + localPointB2->y)));
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",126)
					this->m_axis = ::box2D::common::math::B2Math_obj::crossVF(::box2D::common::math::B2Math_obj::subtractVV(localPointB2,localPointB1),1.0);
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",127)
					this->m_axis->normalize();
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",130)
					tVec = this->m_axis;
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",131)
					tMat = transformB->R;
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",132)
					normalX = ((tMat->col1->x * tVec->x) + (tMat->col2->x * tVec->y));
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",133)
					normalY = ((tMat->col1->y * tVec->x) + (tMat->col2->y * tVec->y));
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",135)
					tVec = this->m_localPoint;
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",136)
					tMat = transformB->R;
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",137)
					pointBX = (transformB->position->x + (((tMat->col1->x * tVec->x) + (tMat->col2->x * tVec->y))));
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",138)
					pointBY = (transformB->position->y + (((tMat->col1->y * tVec->x) + (tMat->col2->y * tVec->y))));
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",140)
					tVec = localPointA;
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",141)
					tMat = transformA->R;
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",142)
					pointAX = (transformA->position->x + (((tMat->col1->x * tVec->x) + (tMat->col2->x * tVec->y))));
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",143)
					pointAY = (transformA->position->y + (((tMat->col1->y * tVec->x) + (tMat->col2->y * tVec->y))));
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",146)
					s = ((((pointAX - pointBX)) * normalX) + (((pointAY - pointBY)) * normalY));
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",147)
					if (((s < 0.0))){
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",148)
						this->m_axis->negativeSelf();
					}
				}
				else{
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",156)
					localPointA1 = this->m_proxyA->getVertex(cache->indexA->__get((int)0));
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",157)
					localPointA2 = this->m_proxyA->getVertex(cache->indexA->__get((int)1));
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",158)
					localPointB1 = this->m_proxyB->getVertex(cache->indexB->__get((int)0));
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",159)
					localPointB2 = this->m_proxyB->getVertex(cache->indexB->__get((int)1));
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",161)
					::box2D::common::math::B2Vec2 pA = ::box2D::common::math::B2Math_obj::mulX(transformA,localPointA);
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",162)
					::box2D::common::math::B2Vec2 dA = ::box2D::common::math::B2Math_obj::mulMV(transformA->R,::box2D::common::math::B2Math_obj::subtractVV(localPointA2,localPointA1));
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",163)
					::box2D::common::math::B2Vec2 pB = ::box2D::common::math::B2Math_obj::mulX(transformB,localPointB);
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",164)
					::box2D::common::math::B2Vec2 dB = ::box2D::common::math::B2Math_obj::mulMV(transformB->R,::box2D::common::math::B2Math_obj::subtractVV(localPointB2,localPointB1));
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",166)
					double a = ((dA->x * dA->x) + (dA->y * dA->y));
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",167)
					double e = ((dB->x * dB->x) + (dB->y * dB->y));
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",168)
					::box2D::common::math::B2Vec2 r = ::box2D::common::math::B2Math_obj::subtractVV(dB,dA);
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",169)
					double c = ((dA->x * r->x) + (dA->y * r->y));
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",170)
					double f = ((dB->x * r->x) + (dB->y * r->y));
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",172)
					double b = ((dA->x * dB->x) + (dA->y * dB->y));
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",173)
					double denom = ((a * e) - (b * b));
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",175)
					s = 0.0;
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",176)
					if (((denom != 0.0))){
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",177)
						s = ::box2D::common::math::B2Math_obj::clamp((double((((b * f) - (c * e)))) / double(denom)),0.0,1.0);
					}
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",181)
					double t = (double((((b * s) + f))) / double(e));
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",182)
					if (((t < 0.0))){
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",184)
						t = 0.0;
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",185)
						s = ::box2D::common::math::B2Math_obj::clamp((double(((b - c))) / double(a)),0.0,1.0);
					}
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",189)
					localPointA = ::box2D::common::math::B2Vec2_obj::__new(null(),null());
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",190)
					localPointA->x = (localPointA1->x + (s * ((localPointA2->x - localPointA1->x))));
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",191)
					localPointA->y = (localPointA1->y + (s * ((localPointA2->y - localPointA1->y))));
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",193)
					localPointB = ::box2D::common::math::B2Vec2_obj::__new(null(),null());
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",194)
					localPointB->x = (localPointB1->x + (s * ((localPointB2->x - localPointB1->x))));
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",195)
					localPointB->y = (localPointB1->y + (s * ((localPointB2->y - localPointB1->y))));
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",197)
					if (((bool((s == 0.0)) || bool((s == 1.0))))){
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",199)
						this->m_type = ::box2D::collision::B2SeparationFunction_obj::e_faceB;
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",200)
						this->m_axis = ::box2D::common::math::B2Math_obj::crossVF(::box2D::common::math::B2Math_obj::subtractVV(localPointB2,localPointB1),1.0);
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",201)
						this->m_axis->normalize();
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",203)
						this->m_localPoint = localPointB;
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",206)
						tVec = this->m_axis;
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",207)
						tMat = transformB->R;
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",208)
						normalX = ((tMat->col1->x * tVec->x) + (tMat->col2->x * tVec->y));
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",209)
						normalY = ((tMat->col1->y * tVec->x) + (tMat->col2->y * tVec->y));
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",211)
						tVec = this->m_localPoint;
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",212)
						tMat = transformB->R;
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",213)
						pointBX = (transformB->position->x + (((tMat->col1->x * tVec->x) + (tMat->col2->x * tVec->y))));
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",214)
						pointBY = (transformB->position->y + (((tMat->col1->y * tVec->x) + (tMat->col2->y * tVec->y))));
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",216)
						tVec = localPointA;
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",217)
						tMat = transformA->R;
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",218)
						pointAX = (transformA->position->x + (((tMat->col1->x * tVec->x) + (tMat->col2->x * tVec->y))));
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",219)
						pointAY = (transformA->position->y + (((tMat->col1->y * tVec->x) + (tMat->col2->y * tVec->y))));
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",222)
						sgn = ((((pointAX - pointBX)) * normalX) + (((pointAY - pointBY)) * normalY));
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",223)
						if (((s < 0.0))){
							HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",224)
							this->m_axis->negativeSelf();
						}
					}
					else{
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",230)
						this->m_type = ::box2D::collision::B2SeparationFunction_obj::e_faceA;
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",231)
						this->m_axis = ::box2D::common::math::B2Math_obj::crossVF(::box2D::common::math::B2Math_obj::subtractVV(localPointA2,localPointA1),1.0);
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",233)
						this->m_localPoint = localPointA;
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",236)
						tVec = this->m_axis;
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",237)
						tMat = transformA->R;
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",238)
						normalX = ((tMat->col1->x * tVec->x) + (tMat->col2->x * tVec->y));
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",239)
						normalY = ((tMat->col1->y * tVec->x) + (tMat->col2->y * tVec->y));
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",241)
						tVec = this->m_localPoint;
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",242)
						tMat = transformA->R;
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",243)
						pointAX = (transformA->position->x + (((tMat->col1->x * tVec->x) + (tMat->col2->x * tVec->y))));
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",244)
						pointAY = (transformA->position->y + (((tMat->col1->y * tVec->x) + (tMat->col2->y * tVec->y))));
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",246)
						tVec = localPointB;
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",247)
						tMat = transformB->R;
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",248)
						pointBX = (transformB->position->x + (((tMat->col1->x * tVec->x) + (tMat->col2->x * tVec->y))));
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",249)
						pointBY = (transformB->position->y + (((tMat->col1->y * tVec->x) + (tMat->col2->y * tVec->y))));
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",252)
						sgn = ((((pointBX - pointAX)) * normalX) + (((pointBY - pointAY)) * normalY));
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",253)
						if (((s < 0.0))){
							HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",254)
							this->m_axis->negativeSelf();
						}
					}
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC5(B2SeparationFunction_obj,initialize,(void))

double B2SeparationFunction_obj::evaluate( ::box2D::common::math::B2Transform transformA,::box2D::common::math::B2Transform transformB){
	HX_SOURCE_PUSH("B2SeparationFunction_obj::evaluate")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",263)
	::box2D::common::math::B2Vec2 axisA;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",264)
	::box2D::common::math::B2Vec2 axisB;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",265)
	::box2D::common::math::B2Vec2 localPointA;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",266)
	::box2D::common::math::B2Vec2 localPointB;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",267)
	::box2D::common::math::B2Vec2 pointA;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",268)
	::box2D::common::math::B2Vec2 pointB;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",269)
	double seperation;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",270)
	::box2D::common::math::B2Vec2 normal;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",271)
	int _switch_1 = (this->m_type);
	if (  ( _switch_1==::box2D::collision::B2SeparationFunction_obj::e_points)){
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",275)
		axisA = ::box2D::common::math::B2Math_obj::mulTMV(transformA->R,this->m_axis);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",276)
		axisB = ::box2D::common::math::B2Math_obj::mulTMV(transformB->R,this->m_axis->getNegative());
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",277)
		localPointA = this->m_proxyA->getSupportVertex(axisA);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",278)
		localPointB = this->m_proxyB->getSupportVertex(axisB);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",279)
		pointA = ::box2D::common::math::B2Math_obj::mulX(transformA,localPointA);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",280)
		pointB = ::box2D::common::math::B2Math_obj::mulX(transformB,localPointB);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",282)
		seperation = ((((pointB->x - pointA->x)) * this->m_axis->x) + (((pointB->y - pointA->y)) * this->m_axis->y));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",283)
		return seperation;
	}
	else if (  ( _switch_1==::box2D::collision::B2SeparationFunction_obj::e_faceA)){
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",287)
		normal = ::box2D::common::math::B2Math_obj::mulMV(transformA->R,this->m_axis);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",288)
		pointA = ::box2D::common::math::B2Math_obj::mulX(transformA,this->m_localPoint);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",290)
		axisB = ::box2D::common::math::B2Math_obj::mulTMV(transformB->R,normal->getNegative());
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",292)
		localPointB = this->m_proxyB->getSupportVertex(axisB);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",293)
		pointB = ::box2D::common::math::B2Math_obj::mulX(transformB,localPointB);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",296)
		seperation = ((((pointB->x - pointA->x)) * normal->x) + (((pointB->y - pointA->y)) * normal->y));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",297)
		return seperation;
	}
	else if (  ( _switch_1==::box2D::collision::B2SeparationFunction_obj::e_faceB)){
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",301)
		normal = ::box2D::common::math::B2Math_obj::mulMV(transformB->R,this->m_axis);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",302)
		pointB = ::box2D::common::math::B2Math_obj::mulX(transformB,this->m_localPoint);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",304)
		axisA = ::box2D::common::math::B2Math_obj::mulTMV(transformA->R,normal->getNegative());
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",306)
		localPointA = this->m_proxyA->getSupportVertex(axisA);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",307)
		pointA = ::box2D::common::math::B2Math_obj::mulX(transformA,localPointA);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",310)
		seperation = ((((pointA->x - pointB->x)) * normal->x) + (((pointA->y - pointB->y)) * normal->y));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",311)
		return seperation;
	}
	else  {
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",314)
		::box2D::common::B2Settings_obj::b2Assert(false);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2SeparationFunction.hx",315)
		return 0.0;
	}
;
;
}


HX_DEFINE_DYNAMIC_FUNC2(B2SeparationFunction_obj,evaluate,return )

int B2SeparationFunction_obj::e_points;

int B2SeparationFunction_obj::e_faceA;

int B2SeparationFunction_obj::e_faceB;


B2SeparationFunction_obj::B2SeparationFunction_obj()
{
}

void B2SeparationFunction_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(B2SeparationFunction);
	HX_MARK_MEMBER_NAME(m_proxyA,"m_proxyA");
	HX_MARK_MEMBER_NAME(m_proxyB,"m_proxyB");
	HX_MARK_MEMBER_NAME(m_type,"m_type");
	HX_MARK_MEMBER_NAME(m_localPoint,"m_localPoint");
	HX_MARK_MEMBER_NAME(m_axis,"m_axis");
	HX_MARK_END_CLASS();
}

Dynamic B2SeparationFunction_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"m_type") ) { return m_type; }
		if (HX_FIELD_EQ(inName,"m_axis") ) { return m_axis; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"e_faceA") ) { return e_faceA; }
		if (HX_FIELD_EQ(inName,"e_faceB") ) { return e_faceB; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"e_points") ) { return e_points; }
		if (HX_FIELD_EQ(inName,"evaluate") ) { return evaluate_dyn(); }
		if (HX_FIELD_EQ(inName,"m_proxyA") ) { return m_proxyA; }
		if (HX_FIELD_EQ(inName,"m_proxyB") ) { return m_proxyB; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"initialize") ) { return initialize_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"m_localPoint") ) { return m_localPoint; }
	}
	return super::__Field(inName);
}

Dynamic B2SeparationFunction_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"m_type") ) { m_type=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_axis") ) { m_axis=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"e_faceA") ) { e_faceA=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"e_faceB") ) { e_faceB=inValue.Cast< int >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"e_points") ) { e_points=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_proxyA") ) { m_proxyA=inValue.Cast< ::box2D::collision::B2DistanceProxy >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_proxyB") ) { m_proxyB=inValue.Cast< ::box2D::collision::B2DistanceProxy >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"m_localPoint") ) { m_localPoint=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void B2SeparationFunction_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("m_proxyA"));
	outFields->push(HX_CSTRING("m_proxyB"));
	outFields->push(HX_CSTRING("m_type"));
	outFields->push(HX_CSTRING("m_localPoint"));
	outFields->push(HX_CSTRING("m_axis"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("e_points"),
	HX_CSTRING("e_faceA"),
	HX_CSTRING("e_faceB"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("initialize"),
	HX_CSTRING("evaluate"),
	HX_CSTRING("m_proxyA"),
	HX_CSTRING("m_proxyB"),
	HX_CSTRING("m_type"),
	HX_CSTRING("m_localPoint"),
	HX_CSTRING("m_axis"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(B2SeparationFunction_obj::e_points,"e_points");
	HX_MARK_MEMBER_NAME(B2SeparationFunction_obj::e_faceA,"e_faceA");
	HX_MARK_MEMBER_NAME(B2SeparationFunction_obj::e_faceB,"e_faceB");
};

Class B2SeparationFunction_obj::__mClass;

void B2SeparationFunction_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.collision.B2SeparationFunction"), hx::TCanCast< B2SeparationFunction_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void B2SeparationFunction_obj::__boot()
{
	hx::Static(e_points) = (int)1;
	hx::Static(e_faceA) = (int)2;
	hx::Static(e_faceB) = (int)4;
}

} // end namespace box2D
} // end namespace collision
