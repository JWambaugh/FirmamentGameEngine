#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_box2D_collision_B2DistanceProxy
#include <box2D/collision/B2DistanceProxy.h>
#endif
#ifndef INCLUDED_box2D_collision_B2Simplex
#include <box2D/collision/B2Simplex.h>
#endif
#ifndef INCLUDED_box2D_collision_B2SimplexCache
#include <box2D/collision/B2SimplexCache.h>
#endif
#ifndef INCLUDED_box2D_collision_B2SimplexVertex
#include <box2D/collision/B2SimplexVertex.h>
#endif
#ifndef INCLUDED_box2D_common_B2Settings
#include <box2D/common/B2Settings.h>
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

Void B2Simplex_obj::__construct()
{
{
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",33)
	this->m_v1 = ::box2D::collision::B2SimplexVertex_obj::__new();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",34)
	this->m_v2 = ::box2D::collision::B2SimplexVertex_obj::__new();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",35)
	this->m_v3 = ::box2D::collision::B2SimplexVertex_obj::__new();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",36)
	this->m_vertices = Array_obj< ::box2D::collision::B2SimplexVertex >::__new();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",38)
	this->m_vertices[(int)0] = this->m_v1;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",39)
	this->m_vertices[(int)1] = this->m_v2;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",40)
	this->m_vertices[(int)2] = this->m_v3;
}
;
	return null();
}

B2Simplex_obj::~B2Simplex_obj() { }

Dynamic B2Simplex_obj::__CreateEmpty() { return  new B2Simplex_obj; }
hx::ObjectPtr< B2Simplex_obj > B2Simplex_obj::__new()
{  hx::ObjectPtr< B2Simplex_obj > result = new B2Simplex_obj();
	result->__construct();
	return result;}

Dynamic B2Simplex_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2Simplex_obj > result = new B2Simplex_obj();
	result->__construct();
	return result;}

Void B2Simplex_obj::readCache( ::box2D::collision::B2SimplexCache cache,::box2D::collision::B2DistanceProxy proxyA,::box2D::common::math::B2Transform transformA,::box2D::collision::B2DistanceProxy proxyB,::box2D::common::math::B2Transform transformB){
{
		HX_SOURCE_PUSH("B2Simplex_obj::readCache")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",47)
		::box2D::common::B2Settings_obj::b2Assert((bool(((int)0 <= cache->count)) && bool((cache->count <= (int)3))));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",49)
		::box2D::common::math::B2Vec2 wALocal;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",50)
		::box2D::common::math::B2Vec2 wBLocal;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",53)
		this->m_count = cache->count;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",54)
		Array< ::box2D::collision::B2SimplexVertex > vertices = this->m_vertices;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",55)
		::box2D::collision::B2SimplexVertex v;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",56)
		{
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",56)
			int _g1 = (int)0;
			int _g = this->m_count;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",56)
			while(((_g1 < _g))){
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",56)
				int i = (_g1)++;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",58)
				v = vertices->__get(i);
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",59)
				v->indexA = cache->indexA->__get(i);
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",60)
				v->indexB = cache->indexB->__get(i);
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",61)
				wALocal = proxyA->getVertex(v->indexA);
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",62)
				wBLocal = proxyB->getVertex(v->indexB);
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",63)
				v->wA = ::box2D::common::math::B2Math_obj::mulX(transformA,wALocal);
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",64)
				v->wB = ::box2D::common::math::B2Math_obj::mulX(transformB,wBLocal);
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",65)
				v->w = ::box2D::common::math::B2Math_obj::subtractVV(v->wB,v->wA);
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",66)
				v->a = (int)0;
			}
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",71)
		if (((this->m_count > (int)1))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",73)
			double metric1 = cache->metric;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",74)
			double metric2 = this->getMetric();
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",75)
			if (((bool((bool((metric2 < (.5 * metric1))) || bool(((2.0 * metric1) < metric2)))) || bool((metric2 < 2.2250738585072014e-308))))){
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",76)
				this->m_count = (int)0;
			}
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",83)
		if (((this->m_count == (int)0))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",85)
			v = vertices->__get((int)0);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",86)
			v->indexA = (int)0;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",87)
			v->indexB = (int)0;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",88)
			wALocal = proxyA->getVertex((int)0);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",89)
			wBLocal = proxyB->getVertex((int)0);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",90)
			v->wA = ::box2D::common::math::B2Math_obj::mulX(transformA,wALocal);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",91)
			v->wB = ::box2D::common::math::B2Math_obj::mulX(transformB,wBLocal);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",92)
			v->w = ::box2D::common::math::B2Math_obj::subtractVV(v->wB,v->wA);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",93)
			this->m_count = (int)1;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC5(B2Simplex_obj,readCache,(void))

Void B2Simplex_obj::writeCache( ::box2D::collision::B2SimplexCache cache){
{
		HX_SOURCE_PUSH("B2Simplex_obj::writeCache")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",99)
		cache->metric = this->getMetric();
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",100)
		cache->count = ::Std_obj::_int(this->m_count);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",101)
		Array< ::box2D::collision::B2SimplexVertex > vertices = this->m_vertices;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",102)
		{
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",102)
			int _g1 = (int)0;
			int _g = this->m_count;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",102)
			while(((_g1 < _g))){
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",102)
				int i = (_g1)++;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",104)
				cache->indexA[i] = ::Std_obj::_int(vertices->__get(i)->indexA);
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",105)
				cache->indexB[i] = ::Std_obj::_int(vertices->__get(i)->indexB);
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2Simplex_obj,writeCache,(void))

::box2D::common::math::B2Vec2 B2Simplex_obj::getSearchDirection( ){
	HX_SOURCE_PUSH("B2Simplex_obj::getSearchDirection")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",110)
	switch( (int)(this->m_count)){
		case (int)1: {
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",113)
			return this->m_v1->w->getNegative();
		}
		;break;
		case (int)2: {
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",118)
			::box2D::common::math::B2Vec2 e12 = ::box2D::common::math::B2Math_obj::subtractVV(this->m_v2->w,this->m_v1->w);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",119)
			double sgn = ::box2D::common::math::B2Math_obj::crossVV(e12,this->m_v1->w->getNegative());
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",120)
			if (((sgn > 0.0))){
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",121)
				return ::box2D::common::math::B2Math_obj::crossFV(1.0,e12);
			}
			else{
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",124)
				return ::box2D::common::math::B2Math_obj::crossVF(e12,1.0);
			}
		}
		;break;
		default: {
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",130)
			::box2D::common::B2Settings_obj::b2Assert(false);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",131)
			return ::box2D::common::math::B2Vec2_obj::__new(null(),null());
		}
	}
}


HX_DEFINE_DYNAMIC_FUNC0(B2Simplex_obj,getSearchDirection,return )

::box2D::common::math::B2Vec2 B2Simplex_obj::getClosestPoint( ){
	HX_SOURCE_PUSH("B2Simplex_obj::getClosestPoint")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",136)
	switch( (int)(this->m_count)){
		case (int)0: {
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",140)
			::box2D::common::B2Settings_obj::b2Assert(false);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",141)
			return ::box2D::common::math::B2Vec2_obj::__new(null(),null());
		}
		;break;
		case (int)1: {
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",142)
			return this->m_v1->w;
		}
		;break;
		case (int)2: {
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",144)
			return ::box2D::common::math::B2Vec2_obj::__new(((this->m_v1->a * this->m_v1->w->x) + (this->m_v2->a * this->m_v2->w->x)),((this->m_v1->a * this->m_v1->w->y) + (this->m_v2->a * this->m_v2->w->y)));
		}
		;break;
		default: {
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",149)
			::box2D::common::B2Settings_obj::b2Assert(false);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",150)
			return ::box2D::common::math::B2Vec2_obj::__new(null(),null());
		}
	}
}


HX_DEFINE_DYNAMIC_FUNC0(B2Simplex_obj,getClosestPoint,return )

Void B2Simplex_obj::getWitnessPoints( ::box2D::common::math::B2Vec2 pA,::box2D::common::math::B2Vec2 pB){
{
		HX_SOURCE_PUSH("B2Simplex_obj::getWitnessPoints")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",155)
		switch( (int)(this->m_count)){
			case (int)0: {
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",158)
				::box2D::common::B2Settings_obj::b2Assert(false);
			}
			;break;
			case (int)1: {
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",162)
				pA->setV(this->m_v1->wA);
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",163)
				pB->setV(this->m_v1->wB);
			}
			;break;
			case (int)2: {
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",166)
				pA->x = ((this->m_v1->a * this->m_v1->wA->x) + (this->m_v2->a * this->m_v2->wA->x));
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",167)
				pA->y = ((this->m_v1->a * this->m_v1->wA->y) + (this->m_v2->a * this->m_v2->wA->y));
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",168)
				pB->x = ((this->m_v1->a * this->m_v1->wB->x) + (this->m_v2->a * this->m_v2->wB->x));
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",169)
				pB->y = ((this->m_v1->a * this->m_v1->wB->y) + (this->m_v2->a * this->m_v2->wB->y));
			}
			;break;
			case (int)3: {
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",172)
				pB->x = pA->x = (((this->m_v1->a * this->m_v1->wA->x) + (this->m_v2->a * this->m_v2->wA->x)) + (this->m_v3->a * this->m_v3->wA->x));
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",173)
				pB->y = pA->y = (((this->m_v1->a * this->m_v1->wA->y) + (this->m_v2->a * this->m_v2->wA->y)) + (this->m_v3->a * this->m_v3->wA->y));
			}
			;break;
			default: {
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",175)
				::box2D::common::B2Settings_obj::b2Assert(false);
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(B2Simplex_obj,getWitnessPoints,(void))

double B2Simplex_obj::getMetric( ){
	HX_SOURCE_PUSH("B2Simplex_obj::getMetric")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",182)
	switch( (int)(this->m_count)){
		case (int)0: {
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",186)
			::box2D::common::B2Settings_obj::b2Assert(false);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",187)
			return 0.0;
		}
		;break;
		case (int)1: {
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",189)
			return 0.0;
		}
		;break;
		case (int)2: {
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",192)
			return ::box2D::common::math::B2Math_obj::subtractVV(this->m_v1->w,this->m_v2->w)->length();
		}
		;break;
		case (int)3: {
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",195)
			return ::box2D::common::math::B2Math_obj::crossVV(::box2D::common::math::B2Math_obj::subtractVV(this->m_v2->w,this->m_v1->w),::box2D::common::math::B2Math_obj::subtractVV(this->m_v3->w,this->m_v1->w));
		}
		;break;
		default: {
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",199)
			::box2D::common::B2Settings_obj::b2Assert(false);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",200)
			return 0.0;
		}
	}
}


HX_DEFINE_DYNAMIC_FUNC0(B2Simplex_obj,getMetric,return )

Void B2Simplex_obj::solve2( ){
{
		HX_SOURCE_PUSH("B2Simplex_obj::solve2")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",229)
		::box2D::common::math::B2Vec2 w1 = this->m_v1->w;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",230)
		::box2D::common::math::B2Vec2 w2 = this->m_v2->w;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",231)
		::box2D::common::math::B2Vec2 e12 = ::box2D::common::math::B2Math_obj::subtractVV(w2,w1);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",234)
		double d12_2 = -((((w1->x * e12->x) + (w1->y * e12->y))));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",235)
		if (((d12_2 <= 0.0))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",238)
			this->m_v1->a = 1.0;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",239)
			this->m_count = (int)1;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",240)
			return null();
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",244)
		double d12_1 = ((w2->x * e12->x) + (w2->y * e12->y));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",245)
		if (((d12_1 <= 0.0))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",248)
			this->m_v2->a = 1.0;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",249)
			this->m_count = (int)1;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",250)
			this->m_v1->set(this->m_v2);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",251)
			return null();
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",255)
		double inv_d12 = (double(1.0) / double(((d12_1 + d12_2))));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",256)
		this->m_v1->a = (d12_1 * inv_d12);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",257)
		this->m_v2->a = (d12_2 * inv_d12);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",258)
		this->m_count = (int)2;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(B2Simplex_obj,solve2,(void))

Void B2Simplex_obj::solve3( ){
{
		HX_SOURCE_PUSH("B2Simplex_obj::solve3")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",263)
		::box2D::common::math::B2Vec2 w1 = this->m_v1->w;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",264)
		::box2D::common::math::B2Vec2 w2 = this->m_v2->w;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",265)
		::box2D::common::math::B2Vec2 w3 = this->m_v3->w;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",271)
		::box2D::common::math::B2Vec2 e12 = ::box2D::common::math::B2Math_obj::subtractVV(w2,w1);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",272)
		double w1e12 = ::box2D::common::math::B2Math_obj::dot(w1,e12);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",273)
		double w2e12 = ::box2D::common::math::B2Math_obj::dot(w2,e12);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",274)
		double d12_1 = w2e12;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",275)
		double d12_2 = -(w1e12);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",281)
		::box2D::common::math::B2Vec2 e13 = ::box2D::common::math::B2Math_obj::subtractVV(w3,w1);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",282)
		double w1e13 = ::box2D::common::math::B2Math_obj::dot(w1,e13);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",283)
		double w3e13 = ::box2D::common::math::B2Math_obj::dot(w3,e13);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",284)
		double d13_1 = w3e13;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",285)
		double d13_2 = -(w1e13);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",291)
		::box2D::common::math::B2Vec2 e23 = ::box2D::common::math::B2Math_obj::subtractVV(w3,w2);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",292)
		double w2e23 = ::box2D::common::math::B2Math_obj::dot(w2,e23);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",293)
		double w3e23 = ::box2D::common::math::B2Math_obj::dot(w3,e23);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",294)
		double d23_1 = w3e23;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",295)
		double d23_2 = -(w2e23);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",298)
		double n123 = ::box2D::common::math::B2Math_obj::crossVV(e12,e13);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",300)
		double d123_1 = (n123 * ::box2D::common::math::B2Math_obj::crossVV(w2,w3));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",301)
		double d123_2 = (n123 * ::box2D::common::math::B2Math_obj::crossVV(w3,w1));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",302)
		double d123_3 = (n123 * ::box2D::common::math::B2Math_obj::crossVV(w1,w2));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",305)
		if (((bool((d12_2 <= 0.0)) && bool((d13_2 <= 0.0))))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",307)
			this->m_v1->a = 1.0;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",308)
			this->m_count = (int)1;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",309)
			return null();
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",313)
		if (((bool((bool((d12_1 > 0.0)) && bool((d12_2 > 0.0)))) && bool((d123_3 <= 0.0))))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",315)
			double inv_d12 = (double(1.0) / double(((d12_1 + d12_2))));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",316)
			this->m_v1->a = (d12_1 * inv_d12);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",317)
			this->m_v2->a = (d12_2 * inv_d12);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",318)
			this->m_count = (int)2;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",319)
			return null();
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",323)
		if (((bool((bool((d13_1 > 0.0)) && bool((d13_2 > 0.0)))) && bool((d123_2 <= 0.0))))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",325)
			double inv_d13 = (double(1.0) / double(((d13_1 + d13_2))));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",326)
			this->m_v1->a = (d13_1 * inv_d13);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",327)
			this->m_v3->a = (d13_2 * inv_d13);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",328)
			this->m_count = (int)2;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",329)
			this->m_v2->set(this->m_v3);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",330)
			return null();
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",334)
		if (((bool((d12_1 <= 0.0)) && bool((d23_2 <= 0.0))))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",336)
			this->m_v2->a = 1.0;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",337)
			this->m_count = (int)1;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",338)
			this->m_v1->set(this->m_v2);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",339)
			return null();
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",343)
		if (((bool((d13_1 <= 0.0)) && bool((d23_1 <= 0.0))))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",345)
			this->m_v3->a = 1.0;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",346)
			this->m_count = (int)1;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",347)
			this->m_v1->set(this->m_v3);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",348)
			return null();
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",352)
		if (((bool((bool((d23_1 > 0.0)) && bool((d23_2 > 0.0)))) && bool((d123_1 <= 0.0))))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",354)
			double inv_d23 = (double(1.0) / double(((d23_1 + d23_2))));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",355)
			this->m_v2->a = (d23_1 * inv_d23);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",356)
			this->m_v3->a = (d23_2 * inv_d23);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",357)
			this->m_count = (int)2;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",358)
			this->m_v1->set(this->m_v3);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",359)
			return null();
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",363)
		double inv_d123 = (double(1.0) / double((((d123_1 + d123_2) + d123_3))));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",364)
		this->m_v1->a = (d123_1 * inv_d123);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",365)
		this->m_v2->a = (d123_2 * inv_d123);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",366)
		this->m_v3->a = (d123_3 * inv_d123);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Simplex.hx",367)
		this->m_count = (int)3;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(B2Simplex_obj,solve3,(void))


B2Simplex_obj::B2Simplex_obj()
{
}

void B2Simplex_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(B2Simplex);
	HX_MARK_MEMBER_NAME(m_v1,"m_v1");
	HX_MARK_MEMBER_NAME(m_v2,"m_v2");
	HX_MARK_MEMBER_NAME(m_v3,"m_v3");
	HX_MARK_MEMBER_NAME(m_vertices,"m_vertices");
	HX_MARK_MEMBER_NAME(m_count,"m_count");
	HX_MARK_END_CLASS();
}

Dynamic B2Simplex_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"m_v1") ) { return m_v1; }
		if (HX_FIELD_EQ(inName,"m_v2") ) { return m_v2; }
		if (HX_FIELD_EQ(inName,"m_v3") ) { return m_v3; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"solve2") ) { return solve2_dyn(); }
		if (HX_FIELD_EQ(inName,"solve3") ) { return solve3_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"m_count") ) { return m_count; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"readCache") ) { return readCache_dyn(); }
		if (HX_FIELD_EQ(inName,"getMetric") ) { return getMetric_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"writeCache") ) { return writeCache_dyn(); }
		if (HX_FIELD_EQ(inName,"m_vertices") ) { return m_vertices; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"getClosestPoint") ) { return getClosestPoint_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"getWitnessPoints") ) { return getWitnessPoints_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"getSearchDirection") ) { return getSearchDirection_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic B2Simplex_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"m_v1") ) { m_v1=inValue.Cast< ::box2D::collision::B2SimplexVertex >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_v2") ) { m_v2=inValue.Cast< ::box2D::collision::B2SimplexVertex >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_v3") ) { m_v3=inValue.Cast< ::box2D::collision::B2SimplexVertex >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"m_count") ) { m_count=inValue.Cast< int >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"m_vertices") ) { m_vertices=inValue.Cast< Array< ::box2D::collision::B2SimplexVertex > >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void B2Simplex_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("m_v1"));
	outFields->push(HX_CSTRING("m_v2"));
	outFields->push(HX_CSTRING("m_v3"));
	outFields->push(HX_CSTRING("m_vertices"));
	outFields->push(HX_CSTRING("m_count"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("readCache"),
	HX_CSTRING("writeCache"),
	HX_CSTRING("getSearchDirection"),
	HX_CSTRING("getClosestPoint"),
	HX_CSTRING("getWitnessPoints"),
	HX_CSTRING("getMetric"),
	HX_CSTRING("solve2"),
	HX_CSTRING("solve3"),
	HX_CSTRING("m_v1"),
	HX_CSTRING("m_v2"),
	HX_CSTRING("m_v3"),
	HX_CSTRING("m_vertices"),
	HX_CSTRING("m_count"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class B2Simplex_obj::__mClass;

void B2Simplex_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.collision.B2Simplex"), hx::TCanCast< B2Simplex_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void B2Simplex_obj::__boot()
{
}

} // end namespace box2D
} // end namespace collision
