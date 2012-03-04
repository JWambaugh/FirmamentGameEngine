#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
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
namespace common{
namespace math{

Void B2Math_obj::__construct()
{
	return null();
}

B2Math_obj::~B2Math_obj() { }

Dynamic B2Math_obj::__CreateEmpty() { return  new B2Math_obj; }
hx::ObjectPtr< B2Math_obj > B2Math_obj::__new()
{  hx::ObjectPtr< B2Math_obj > result = new B2Math_obj();
	result->__construct();
	return result;}

Dynamic B2Math_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2Math_obj > result = new B2Math_obj();
	result->__construct();
	return result;}

bool B2Math_obj::isValid( double x){
	HX_SOURCE_PUSH("B2Math_obj::isValid")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Math.hx",36)
	if (((bool((bool(::Math_obj::isNaN(x)) || bool((x == ::Math_obj::NEGATIVE_INFINITY)))) || bool((x == ::Math_obj::POSITIVE_INFINITY))))){
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Math.hx",36)
		return false;
	}
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Math.hx",42)
	return true;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(B2Math_obj,isValid,return )

double B2Math_obj::dot( ::box2D::common::math::B2Vec2 a,::box2D::common::math::B2Vec2 b){
	HX_SOURCE_PUSH("B2Math_obj::dot")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Math.hx",62)
	return ((a->x * b->x) + (a->y * b->y));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(B2Math_obj,dot,return )

double B2Math_obj::crossVV( ::box2D::common::math::B2Vec2 a,::box2D::common::math::B2Vec2 b){
	HX_SOURCE_PUSH("B2Math_obj::crossVV")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Math.hx",67)
	return ((a->x * b->y) - (a->y * b->x));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(B2Math_obj,crossVV,return )

::box2D::common::math::B2Vec2 B2Math_obj::crossVF( ::box2D::common::math::B2Vec2 a,double s){
	HX_SOURCE_PUSH("B2Math_obj::crossVF")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Math.hx",73)
	::box2D::common::math::B2Vec2 v = ::box2D::common::math::B2Vec2_obj::__new((s * a->y),(-(s) * a->x));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Math.hx",74)
	return v;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(B2Math_obj,crossVF,return )

::box2D::common::math::B2Vec2 B2Math_obj::crossFV( double s,::box2D::common::math::B2Vec2 a){
	HX_SOURCE_PUSH("B2Math_obj::crossFV")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Math.hx",79)
	::box2D::common::math::B2Vec2 v = ::box2D::common::math::B2Vec2_obj::__new((-(s) * a->y),(s * a->x));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Math.hx",80)
	return v;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(B2Math_obj,crossFV,return )

::box2D::common::math::B2Vec2 B2Math_obj::mulMV( ::box2D::common::math::B2Mat22 A,::box2D::common::math::B2Vec2 v){
	HX_SOURCE_PUSH("B2Math_obj::mulMV")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Math.hx",87)
	::box2D::common::math::B2Vec2 u = ::box2D::common::math::B2Vec2_obj::__new(((A->col1->x * v->x) + (A->col2->x * v->y)),((A->col1->y * v->x) + (A->col2->y * v->y)));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Math.hx",88)
	return u;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(B2Math_obj,mulMV,return )

::box2D::common::math::B2Vec2 B2Math_obj::mulTMV( ::box2D::common::math::B2Mat22 A,::box2D::common::math::B2Vec2 v){
	HX_SOURCE_PUSH("B2Math_obj::mulTMV")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Math.hx",95)
	::box2D::common::math::B2Vec2 u = ::box2D::common::math::B2Vec2_obj::__new(::box2D::common::math::B2Math_obj::dot(v,A->col1),::box2D::common::math::B2Math_obj::dot(v,A->col2));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Math.hx",96)
	return u;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(B2Math_obj,mulTMV,return )

::box2D::common::math::B2Vec2 B2Math_obj::mulX( ::box2D::common::math::B2Transform T,::box2D::common::math::B2Vec2 v){
	HX_SOURCE_PUSH("B2Math_obj::mulX")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Math.hx",101)
	::box2D::common::math::B2Vec2 a = ::box2D::common::math::B2Math_obj::mulMV(T->R,v);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Math.hx",102)
	hx::AddEq(a->x,T->position->x);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Math.hx",103)
	hx::AddEq(a->y,T->position->y);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Math.hx",105)
	return a;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(B2Math_obj,mulX,return )

::box2D::common::math::B2Vec2 B2Math_obj::mulXT( ::box2D::common::math::B2Transform T,::box2D::common::math::B2Vec2 v){
	HX_SOURCE_PUSH("B2Math_obj::mulXT")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Math.hx",110)
	::box2D::common::math::B2Vec2 a = ::box2D::common::math::B2Math_obj::subtractVV(v,T->position);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Math.hx",112)
	double tX = ((a->x * T->R->col1->x) + (a->y * T->R->col1->y));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Math.hx",113)
	a->y = ((a->x * T->R->col2->x) + (a->y * T->R->col2->y));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Math.hx",114)
	a->x = tX;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Math.hx",115)
	return a;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(B2Math_obj,mulXT,return )

::box2D::common::math::B2Vec2 B2Math_obj::addVV( ::box2D::common::math::B2Vec2 a,::box2D::common::math::B2Vec2 b){
	HX_SOURCE_PUSH("B2Math_obj::addVV")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Math.hx",120)
	::box2D::common::math::B2Vec2 v = ::box2D::common::math::B2Vec2_obj::__new((a->x + b->x),(a->y + b->y));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Math.hx",121)
	return v;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(B2Math_obj,addVV,return )

::box2D::common::math::B2Vec2 B2Math_obj::subtractVV( ::box2D::common::math::B2Vec2 a,::box2D::common::math::B2Vec2 b){
	HX_SOURCE_PUSH("B2Math_obj::subtractVV")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Math.hx",126)
	::box2D::common::math::B2Vec2 v = ::box2D::common::math::B2Vec2_obj::__new((a->x - b->x),(a->y - b->y));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Math.hx",127)
	return v;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(B2Math_obj,subtractVV,return )

double B2Math_obj::distance( ::box2D::common::math::B2Vec2 a,::box2D::common::math::B2Vec2 b){
	HX_SOURCE_PUSH("B2Math_obj::distance")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Math.hx",131)
	double cX = (a->x - b->x);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Math.hx",132)
	double cY = (a->y - b->y);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Math.hx",133)
	return ::Math_obj::sqrt(((cX * cX) + (cY * cY)));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(B2Math_obj,distance,return )

double B2Math_obj::distanceSquared( ::box2D::common::math::B2Vec2 a,::box2D::common::math::B2Vec2 b){
	HX_SOURCE_PUSH("B2Math_obj::distanceSquared")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Math.hx",137)
	double cX = (a->x - b->x);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Math.hx",138)
	double cY = (a->y - b->y);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Math.hx",139)
	return ((cX * cX) + (cY * cY));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(B2Math_obj,distanceSquared,return )

::box2D::common::math::B2Vec2 B2Math_obj::mulFV( double s,::box2D::common::math::B2Vec2 a){
	HX_SOURCE_PUSH("B2Math_obj::mulFV")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Math.hx",144)
	::box2D::common::math::B2Vec2 v = ::box2D::common::math::B2Vec2_obj::__new((s * a->x),(s * a->y));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Math.hx",145)
	return v;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(B2Math_obj,mulFV,return )

::box2D::common::math::B2Mat22 B2Math_obj::addMM( ::box2D::common::math::B2Mat22 A,::box2D::common::math::B2Mat22 B){
	HX_SOURCE_PUSH("B2Math_obj::addMM")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Math.hx",150)
	::box2D::common::math::B2Mat22 C = ::box2D::common::math::B2Mat22_obj::fromVV(::box2D::common::math::B2Math_obj::addVV(A->col1,B->col1),::box2D::common::math::B2Math_obj::addVV(A->col2,B->col2));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Math.hx",151)
	return C;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(B2Math_obj,addMM,return )

::box2D::common::math::B2Mat22 B2Math_obj::mulMM( ::box2D::common::math::B2Mat22 A,::box2D::common::math::B2Mat22 B){
	HX_SOURCE_PUSH("B2Math_obj::mulMM")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Math.hx",157)
	::box2D::common::math::B2Mat22 C = ::box2D::common::math::B2Mat22_obj::fromVV(::box2D::common::math::B2Math_obj::mulMV(A,B->col1),::box2D::common::math::B2Math_obj::mulMV(A,B->col2));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Math.hx",158)
	return C;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(B2Math_obj,mulMM,return )

::box2D::common::math::B2Mat22 B2Math_obj::mulTMM( ::box2D::common::math::B2Mat22 A,::box2D::common::math::B2Mat22 B){
	HX_SOURCE_PUSH("B2Math_obj::mulTMM")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Math.hx",164)
	::box2D::common::math::B2Vec2 c1 = ::box2D::common::math::B2Vec2_obj::__new(::box2D::common::math::B2Math_obj::dot(A->col1,B->col1),::box2D::common::math::B2Math_obj::dot(A->col2,B->col1));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Math.hx",165)
	::box2D::common::math::B2Vec2 c2 = ::box2D::common::math::B2Vec2_obj::__new(::box2D::common::math::B2Math_obj::dot(A->col1,B->col2),::box2D::common::math::B2Math_obj::dot(A->col2,B->col2));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Math.hx",166)
	::box2D::common::math::B2Mat22 C = ::box2D::common::math::B2Mat22_obj::fromVV(c1,c2);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Math.hx",167)
	return C;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(B2Math_obj,mulTMM,return )

double B2Math_obj::abs( double a){
	HX_SOURCE_PUSH("B2Math_obj::abs")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Math.hx",171)
	return (  (((a > 0.0))) ? double(a) : double(-(a)) );
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(B2Math_obj,abs,return )

::box2D::common::math::B2Vec2 B2Math_obj::absV( ::box2D::common::math::B2Vec2 a){
	HX_SOURCE_PUSH("B2Math_obj::absV")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Math.hx",177)
	::box2D::common::math::B2Vec2 b = ::box2D::common::math::B2Vec2_obj::__new(::box2D::common::math::B2Math_obj::abs(a->x),::box2D::common::math::B2Math_obj::abs(a->y));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Math.hx",178)
	return b;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(B2Math_obj,absV,return )

::box2D::common::math::B2Mat22 B2Math_obj::absM( ::box2D::common::math::B2Mat22 A){
	HX_SOURCE_PUSH("B2Math_obj::absM")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Math.hx",183)
	::box2D::common::math::B2Mat22 B = ::box2D::common::math::B2Mat22_obj::fromVV(::box2D::common::math::B2Math_obj::absV(A->col1),::box2D::common::math::B2Math_obj::absV(A->col2));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Math.hx",184)
	return B;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(B2Math_obj,absM,return )

double B2Math_obj::min( double a,double b){
	HX_SOURCE_PUSH("B2Math_obj::min")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Math.hx",188)
	return (  (((a < b))) ? double(a) : double(b) );
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(B2Math_obj,min,return )

::box2D::common::math::B2Vec2 B2Math_obj::minV( ::box2D::common::math::B2Vec2 a,::box2D::common::math::B2Vec2 b){
	HX_SOURCE_PUSH("B2Math_obj::minV")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Math.hx",194)
	::box2D::common::math::B2Vec2 c = ::box2D::common::math::B2Vec2_obj::__new(::box2D::common::math::B2Math_obj::min(a->x,b->x),::box2D::common::math::B2Math_obj::min(a->y,b->y));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Math.hx",195)
	return c;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(B2Math_obj,minV,return )

double B2Math_obj::max( double a,double b){
	HX_SOURCE_PUSH("B2Math_obj::max")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Math.hx",199)
	return (  (((a > b))) ? double(a) : double(b) );
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(B2Math_obj,max,return )

::box2D::common::math::B2Vec2 B2Math_obj::maxV( ::box2D::common::math::B2Vec2 a,::box2D::common::math::B2Vec2 b){
	HX_SOURCE_PUSH("B2Math_obj::maxV")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Math.hx",205)
	::box2D::common::math::B2Vec2 c = ::box2D::common::math::B2Vec2_obj::__new(::box2D::common::math::B2Math_obj::max(a->x,b->x),::box2D::common::math::B2Math_obj::max(a->y,b->y));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Math.hx",206)
	return c;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(B2Math_obj,maxV,return )

double B2Math_obj::clamp( double a,double low,double high){
	HX_SOURCE_PUSH("B2Math_obj::clamp")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Math.hx",210)
	return (  (((a < low))) ? double(low) : double((  (((a > high))) ? double(high) : double(a) )) );
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(B2Math_obj,clamp,return )

::box2D::common::math::B2Vec2 B2Math_obj::clampV( ::box2D::common::math::B2Vec2 a,::box2D::common::math::B2Vec2 low,::box2D::common::math::B2Vec2 high){
	HX_SOURCE_PUSH("B2Math_obj::clampV")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Math.hx",215)
	return ::box2D::common::math::B2Math_obj::maxV(low,::box2D::common::math::B2Math_obj::minV(a,high));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(B2Math_obj,clampV,return )

Void B2Math_obj::swap( Dynamic a,Dynamic b){
{
		HX_SOURCE_PUSH("B2Math_obj::swap")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Math.hx",221)
		Dynamic tmp = a->__GetItem((int)0);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Math.hx",222)
		hx::IndexRef((a).mPtr,(int)0) = b->__GetItem((int)0);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Math.hx",223)
		hx::IndexRef((b).mPtr,(int)0) = tmp;
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(B2Math_obj,swap,(void))

double B2Math_obj::random( ){
	HX_SOURCE_PUSH("B2Math_obj::random")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Math.hx",228)
	return ((::Math_obj::random() * (int)2) - (int)1);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(B2Math_obj,random,return )

double B2Math_obj::randomRange( double lo,double hi){
	HX_SOURCE_PUSH("B2Math_obj::randomRange")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Math.hx",234)
	double r = ::Math_obj::random();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Math.hx",235)
	r = ((((hi - lo)) * r) + lo);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Math.hx",236)
	return r;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(B2Math_obj,randomRange,return )

int B2Math_obj::nextPowerOfTwo( int x){
	HX_SOURCE_PUSH("B2Math_obj::nextPowerOfTwo")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Math.hx",246)
	hx::OrEq(x,(int((int(x) >> int((int)1))) & int((int)2147483647)));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Math.hx",247)
	hx::OrEq(x,(int((int(x) >> int((int)2))) & int((int)1073741823)));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Math.hx",248)
	hx::OrEq(x,(int((int(x) >> int((int)4))) & int((int)268435455)));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Math.hx",249)
	hx::OrEq(x,(int((int(x) >> int((int)8))) & int((int)16777215)));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Math.hx",250)
	hx::OrEq(x,(int((int(x) >> int((int)16))) & int((int)65535)));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Math.hx",251)
	return (x + (int)1);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(B2Math_obj,nextPowerOfTwo,return )

bool B2Math_obj::isPowerOfTwo( int x){
	HX_SOURCE_PUSH("B2Math_obj::isPowerOfTwo")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Math.hx",256)
	bool result = (bool((x > (int)0)) && bool((((int(x) & int((x - (int)1)))) == (int)0)));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/math/B2Math.hx",257)
	return result;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(B2Math_obj,isPowerOfTwo,return )

::box2D::common::math::B2Vec2 B2Math_obj::b2Vec2_zero;

::box2D::common::math::B2Mat22 B2Math_obj::b2Mat22_identity;

::box2D::common::math::B2Transform B2Math_obj::b2Transform_identity;

double B2Math_obj::MIN_VALUE;

double B2Math_obj::MAX_VALUE;


B2Math_obj::B2Math_obj()
{
}

void B2Math_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(B2Math);
	HX_MARK_END_CLASS();
}

Dynamic B2Math_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"dot") ) { return dot_dyn(); }
		if (HX_FIELD_EQ(inName,"abs") ) { return abs_dyn(); }
		if (HX_FIELD_EQ(inName,"min") ) { return min_dyn(); }
		if (HX_FIELD_EQ(inName,"max") ) { return max_dyn(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"mulX") ) { return mulX_dyn(); }
		if (HX_FIELD_EQ(inName,"absV") ) { return absV_dyn(); }
		if (HX_FIELD_EQ(inName,"absM") ) { return absM_dyn(); }
		if (HX_FIELD_EQ(inName,"minV") ) { return minV_dyn(); }
		if (HX_FIELD_EQ(inName,"maxV") ) { return maxV_dyn(); }
		if (HX_FIELD_EQ(inName,"swap") ) { return swap_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"mulMV") ) { return mulMV_dyn(); }
		if (HX_FIELD_EQ(inName,"mulXT") ) { return mulXT_dyn(); }
		if (HX_FIELD_EQ(inName,"addVV") ) { return addVV_dyn(); }
		if (HX_FIELD_EQ(inName,"mulFV") ) { return mulFV_dyn(); }
		if (HX_FIELD_EQ(inName,"addMM") ) { return addMM_dyn(); }
		if (HX_FIELD_EQ(inName,"mulMM") ) { return mulMM_dyn(); }
		if (HX_FIELD_EQ(inName,"clamp") ) { return clamp_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"mulTMV") ) { return mulTMV_dyn(); }
		if (HX_FIELD_EQ(inName,"mulTMM") ) { return mulTMM_dyn(); }
		if (HX_FIELD_EQ(inName,"clampV") ) { return clampV_dyn(); }
		if (HX_FIELD_EQ(inName,"random") ) { return random_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"isValid") ) { return isValid_dyn(); }
		if (HX_FIELD_EQ(inName,"crossVV") ) { return crossVV_dyn(); }
		if (HX_FIELD_EQ(inName,"crossVF") ) { return crossVF_dyn(); }
		if (HX_FIELD_EQ(inName,"crossFV") ) { return crossFV_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"distance") ) { return distance_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"MIN_VALUE") ) { return MIN_VALUE; }
		if (HX_FIELD_EQ(inName,"MAX_VALUE") ) { return MAX_VALUE; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"subtractVV") ) { return subtractVV_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"randomRange") ) { return randomRange_dyn(); }
		if (HX_FIELD_EQ(inName,"b2Vec2_zero") ) { return b2Vec2_zero; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"isPowerOfTwo") ) { return isPowerOfTwo_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"nextPowerOfTwo") ) { return nextPowerOfTwo_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"distanceSquared") ) { return distanceSquared_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"b2Mat22_identity") ) { return b2Mat22_identity; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"b2Transform_identity") ) { return b2Transform_identity; }
	}
	return super::__Field(inName);
}

Dynamic B2Math_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 9:
		if (HX_FIELD_EQ(inName,"MIN_VALUE") ) { MIN_VALUE=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"MAX_VALUE") ) { MAX_VALUE=inValue.Cast< double >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"b2Vec2_zero") ) { b2Vec2_zero=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"b2Mat22_identity") ) { b2Mat22_identity=inValue.Cast< ::box2D::common::math::B2Mat22 >(); return inValue; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"b2Transform_identity") ) { b2Transform_identity=inValue.Cast< ::box2D::common::math::B2Transform >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void B2Math_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("isValid"),
	HX_CSTRING("dot"),
	HX_CSTRING("crossVV"),
	HX_CSTRING("crossVF"),
	HX_CSTRING("crossFV"),
	HX_CSTRING("mulMV"),
	HX_CSTRING("mulTMV"),
	HX_CSTRING("mulX"),
	HX_CSTRING("mulXT"),
	HX_CSTRING("addVV"),
	HX_CSTRING("subtractVV"),
	HX_CSTRING("distance"),
	HX_CSTRING("distanceSquared"),
	HX_CSTRING("mulFV"),
	HX_CSTRING("addMM"),
	HX_CSTRING("mulMM"),
	HX_CSTRING("mulTMM"),
	HX_CSTRING("abs"),
	HX_CSTRING("absV"),
	HX_CSTRING("absM"),
	HX_CSTRING("min"),
	HX_CSTRING("minV"),
	HX_CSTRING("max"),
	HX_CSTRING("maxV"),
	HX_CSTRING("clamp"),
	HX_CSTRING("clampV"),
	HX_CSTRING("swap"),
	HX_CSTRING("random"),
	HX_CSTRING("randomRange"),
	HX_CSTRING("nextPowerOfTwo"),
	HX_CSTRING("isPowerOfTwo"),
	HX_CSTRING("b2Vec2_zero"),
	HX_CSTRING("b2Mat22_identity"),
	HX_CSTRING("b2Transform_identity"),
	HX_CSTRING("MIN_VALUE"),
	HX_CSTRING("MAX_VALUE"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(B2Math_obj::b2Vec2_zero,"b2Vec2_zero");
	HX_MARK_MEMBER_NAME(B2Math_obj::b2Mat22_identity,"b2Mat22_identity");
	HX_MARK_MEMBER_NAME(B2Math_obj::b2Transform_identity,"b2Transform_identity");
	HX_MARK_MEMBER_NAME(B2Math_obj::MIN_VALUE,"MIN_VALUE");
	HX_MARK_MEMBER_NAME(B2Math_obj::MAX_VALUE,"MAX_VALUE");
};

Class B2Math_obj::__mClass;

void B2Math_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.common.math.B2Math"), hx::TCanCast< B2Math_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void B2Math_obj::__boot()
{
	hx::Static(b2Vec2_zero) = ::box2D::common::math::B2Vec2_obj::__new(0.0,0.0);
	hx::Static(b2Mat22_identity) = ::box2D::common::math::B2Mat22_obj::fromVV(::box2D::common::math::B2Vec2_obj::__new(1.0,0.0),::box2D::common::math::B2Vec2_obj::__new(0.0,1.0));
	hx::Static(b2Transform_identity) = ::box2D::common::math::B2Transform_obj::__new(::box2D::common::math::B2Math_obj::b2Vec2_zero,::box2D::common::math::B2Math_obj::b2Mat22_identity);
	hx::Static(MIN_VALUE) = 2.2250738585072014e-308;
	hx::Static(MAX_VALUE) = 1.7976931348623158e+308;
}

} // end namespace box2D
} // end namespace common
} // end namespace math
