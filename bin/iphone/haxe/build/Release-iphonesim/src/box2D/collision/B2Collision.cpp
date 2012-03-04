#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_box2D_collision_B2AABB
#include <box2D/collision/B2AABB.h>
#endif
#ifndef INCLUDED_box2D_collision_B2Collision
#include <box2D/collision/B2Collision.h>
#endif
#ifndef INCLUDED_box2D_collision_B2ContactID
#include <box2D/collision/B2ContactID.h>
#endif
#ifndef INCLUDED_box2D_collision_B2Manifold
#include <box2D/collision/B2Manifold.h>
#endif
#ifndef INCLUDED_box2D_collision_B2ManifoldPoint
#include <box2D/collision/B2ManifoldPoint.h>
#endif
#ifndef INCLUDED_box2D_collision_ClipVertex
#include <box2D/collision/ClipVertex.h>
#endif
#ifndef INCLUDED_box2D_collision_Features
#include <box2D/collision/Features.h>
#endif
#ifndef INCLUDED_box2D_collision_shapes_B2CircleShape
#include <box2D/collision/shapes/B2CircleShape.h>
#endif
#ifndef INCLUDED_box2D_collision_shapes_B2PolygonShape
#include <box2D/collision/shapes/B2PolygonShape.h>
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
#ifndef INCLUDED_box2D_common_math_B2Transform
#include <box2D/common/math/B2Transform.h>
#endif
#ifndef INCLUDED_box2D_common_math_B2Vec2
#include <box2D/common/math/B2Vec2.h>
#endif
namespace box2D{
namespace collision{

Void B2Collision_obj::__construct()
{
	return null();
}

B2Collision_obj::~B2Collision_obj() { }

Dynamic B2Collision_obj::__CreateEmpty() { return  new B2Collision_obj; }
hx::ObjectPtr< B2Collision_obj > B2Collision_obj::__new()
{  hx::ObjectPtr< B2Collision_obj > result = new B2Collision_obj();
	result->__construct();
	return result;}

Dynamic B2Collision_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2Collision_obj > result = new B2Collision_obj();
	result->__construct();
	return result;}

int B2Collision_obj::b2_nullFeature;

int B2Collision_obj::clipSegmentToLine( Array< ::box2D::collision::ClipVertex > vOut,Array< ::box2D::collision::ClipVertex > vIn,::box2D::common::math::B2Vec2 normal,double offset){
	HX_SOURCE_PUSH("B2Collision_obj::clipSegmentToLine")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",42)
	::box2D::collision::ClipVertex cv;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",45)
	int numOut = (int)0;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",47)
	cv = vIn->__get((int)0);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",48)
	::box2D::common::math::B2Vec2 vIn0 = cv->v;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",49)
	cv = vIn->__get((int)1);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",50)
	::box2D::common::math::B2Vec2 vIn1 = cv->v;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",53)
	double distance0 = (((normal->x * vIn0->x) + (normal->y * vIn0->y)) - offset);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",54)
	double distance1 = (((normal->x * vIn1->x) + (normal->y * vIn1->y)) - offset);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",57)
	if (((distance0 <= 0.0))){
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",57)
		vOut->__get((numOut)++)->set(vIn->__get((int)0));
	}
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",58)
	if (((distance1 <= 0.0))){
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",58)
		vOut->__get((numOut)++)->set(vIn->__get((int)1));
	}
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",61)
	if ((((distance0 * distance1) < 0.0))){
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",64)
		double interp = (double(distance0) / double(((distance0 - distance1))));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",67)
		cv = vOut->__get(numOut);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",68)
		::box2D::common::math::B2Vec2 tVec = cv->v;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",69)
		tVec->x = (vIn0->x + (interp * ((vIn1->x - vIn0->x))));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",70)
		tVec->y = (vIn0->y + (interp * ((vIn1->y - vIn0->y))));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",71)
		cv = vOut->__get(numOut);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",72)
		::box2D::collision::ClipVertex cv2;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",73)
		if (((distance0 > 0.0))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",75)
			cv2 = vIn->__get((int)0);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",76)
			cv->id = cv2->id;
		}
		else{
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",80)
			cv2 = vIn->__get((int)1);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",81)
			cv->id = cv2->id;
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",83)
		++(numOut);
	}
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",86)
	return numOut;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(B2Collision_obj,clipSegmentToLine,return )

double B2Collision_obj::edgeSeparation( ::box2D::collision::shapes::B2PolygonShape poly1,::box2D::common::math::B2Transform xf1,int edge1,::box2D::collision::shapes::B2PolygonShape poly2,::box2D::common::math::B2Transform xf2){
	HX_SOURCE_PUSH("B2Collision_obj::edgeSeparation")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",94)
	int count1 = poly1->m_vertexCount;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",95)
	Array< ::box2D::common::math::B2Vec2 > vertices1 = poly1->m_vertices;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",96)
	Array< ::box2D::common::math::B2Vec2 > normals1 = poly1->m_normals;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",98)
	int count2 = poly2->m_vertexCount;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",99)
	Array< ::box2D::common::math::B2Vec2 > vertices2 = poly2->m_vertices;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",103)
	::box2D::common::math::B2Mat22 tMat;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",104)
	::box2D::common::math::B2Vec2 tVec;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",108)
	tMat = xf1->R;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",109)
	tVec = normals1->__get(edge1);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",110)
	double normal1WorldX = ((tMat->col1->x * tVec->x) + (tMat->col2->x * tVec->y));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",111)
	double normal1WorldY = ((tMat->col1->y * tVec->x) + (tMat->col2->y * tVec->y));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",113)
	tMat = xf2->R;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",114)
	double normal1X = ((tMat->col1->x * normal1WorldX) + (tMat->col1->y * normal1WorldY));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",115)
	double normal1Y = ((tMat->col2->x * normal1WorldX) + (tMat->col2->y * normal1WorldY));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",118)
	int index = (int)0;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",119)
	double minDot = 1.7976931348623158e+308;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",120)
	{
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",120)
		int _g = (int)0;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",120)
		while(((_g < count2))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",120)
			int i = (_g)++;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",123)
			tVec = vertices2->__get(i);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",124)
			double dot = ((tVec->x * normal1X) + (tVec->y * normal1Y));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",125)
			if (((dot < minDot))){
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",127)
				minDot = dot;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",128)
				index = i;
			}
		}
	}
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",133)
	tVec = vertices1->__get(edge1);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",134)
	tMat = xf1->R;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",135)
	double v1X = (xf1->position->x + (((tMat->col1->x * tVec->x) + (tMat->col2->x * tVec->y))));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",136)
	double v1Y = (xf1->position->y + (((tMat->col1->y * tVec->x) + (tMat->col2->y * tVec->y))));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",138)
	tVec = vertices2->__get(index);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",139)
	tMat = xf2->R;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",140)
	double v2X = (xf2->position->x + (((tMat->col1->x * tVec->x) + (tMat->col2->x * tVec->y))));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",141)
	double v2Y = (xf2->position->y + (((tMat->col1->y * tVec->x) + (tMat->col2->y * tVec->y))));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",144)
	hx::SubEq(v2X,v1X);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",145)
	hx::SubEq(v2Y,v1Y);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",147)
	double separation = ((v2X * normal1WorldX) + (v2Y * normal1WorldY));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",148)
	return separation;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC5(B2Collision_obj,edgeSeparation,return )

double B2Collision_obj::findMaxSeparation( Array< int > edgeIndex,::box2D::collision::shapes::B2PolygonShape poly1,::box2D::common::math::B2Transform xf1,::box2D::collision::shapes::B2PolygonShape poly2,::box2D::common::math::B2Transform xf2){
	HX_SOURCE_PUSH("B2Collision_obj::findMaxSeparation")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",160)
	int count1 = poly1->m_vertexCount;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",161)
	Array< ::box2D::common::math::B2Vec2 > normals1 = poly1->m_normals;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",163)
	::box2D::common::math::B2Vec2 tVec;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",164)
	::box2D::common::math::B2Mat22 tMat;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",168)
	tMat = xf2->R;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",169)
	tVec = poly2->m_centroid;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",170)
	double dX = (xf2->position->x + (((tMat->col1->x * tVec->x) + (tMat->col2->x * tVec->y))));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",171)
	double dY = (xf2->position->y + (((tMat->col1->y * tVec->x) + (tMat->col2->y * tVec->y))));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",172)
	tMat = xf1->R;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",173)
	tVec = poly1->m_centroid;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",174)
	hx::SubEq(dX,(xf1->position->x + (((tMat->col1->x * tVec->x) + (tMat->col2->x * tVec->y)))));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",175)
	hx::SubEq(dY,(xf1->position->y + (((tMat->col1->y * tVec->x) + (tMat->col2->y * tVec->y)))));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",178)
	double dLocal1X = ((dX * xf1->R->col1->x) + (dY * xf1->R->col1->y));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",179)
	double dLocal1Y = ((dX * xf1->R->col2->x) + (dY * xf1->R->col2->y));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",182)
	int edge = (int)0;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",183)
	double maxDot = -(1.7976931348623158e+308);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",184)
	{
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",184)
		int _g = (int)0;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",184)
		while(((_g < count1))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",184)
			int i = (_g)++;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",187)
			tVec = normals1->__get(i);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",188)
			double dot = ((tVec->x * dLocal1X) + (tVec->y * dLocal1Y));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",189)
			if (((dot > maxDot))){
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",191)
				maxDot = dot;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",192)
				edge = i;
			}
		}
	}
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",197)
	double s = ::box2D::collision::B2Collision_obj::edgeSeparation(poly1,xf1,edge,poly2,xf2);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",200)
	int prevEdge = (  ((((edge - (int)1) >= (int)0))) ? int((edge - (int)1)) : int((count1 - (int)1)) );
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",201)
	double sPrev = ::box2D::collision::B2Collision_obj::edgeSeparation(poly1,xf1,prevEdge,poly2,xf2);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",204)
	int nextEdge = (  ((((edge + (int)1) < count1))) ? int((edge + (int)1)) : int((int)0) );
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",205)
	double sNext = ::box2D::collision::B2Collision_obj::edgeSeparation(poly1,xf1,nextEdge,poly2,xf2);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",208)
	int bestEdge;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",209)
	double bestSeparation;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",210)
	int increment;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",211)
	if (((bool((sPrev > s)) && bool((sPrev > sNext))))){
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",213)
		increment = (int)-1;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",214)
		bestEdge = prevEdge;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",215)
		bestSeparation = sPrev;
	}
	else{
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",217)
		if (((sNext > s))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",219)
			increment = (int)1;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",220)
			bestEdge = nextEdge;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",221)
			bestSeparation = sNext;
		}
		else{
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",226)
			edgeIndex[(int)0] = edge;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",227)
			return s;
		}
	}
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",231)
	while((true)){
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",234)
		if (((increment == (int)-1))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",235)
			edge = (  ((((bestEdge - (int)1) >= (int)0))) ? int((bestEdge - (int)1)) : int((count1 - (int)1)) );
		}
		else{
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",237)
			edge = (  ((((bestEdge + (int)1) < count1))) ? int((bestEdge + (int)1)) : int((int)0) );
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",239)
		s = ::box2D::collision::B2Collision_obj::edgeSeparation(poly1,xf1,edge,poly2,xf2);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",241)
		if (((s > bestSeparation))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",243)
			bestEdge = edge;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",244)
			bestSeparation = s;
		}
		else{
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",247)
			break;
		}
	}
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",253)
	edgeIndex[(int)0] = bestEdge;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",254)
	return bestSeparation;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC5(B2Collision_obj,findMaxSeparation,return )

Void B2Collision_obj::findIncidentEdge( Array< ::box2D::collision::ClipVertex > c,::box2D::collision::shapes::B2PolygonShape poly1,::box2D::common::math::B2Transform xf1,int edge1,::box2D::collision::shapes::B2PolygonShape poly2,::box2D::common::math::B2Transform xf2){
{
		HX_SOURCE_PUSH("B2Collision_obj::findIncidentEdge")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",263)
		int count1 = poly1->m_vertexCount;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",264)
		Array< ::box2D::common::math::B2Vec2 > normals1 = poly1->m_normals;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",266)
		int count2 = poly2->m_vertexCount;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",267)
		Array< ::box2D::common::math::B2Vec2 > vertices2 = poly2->m_vertices;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",268)
		Array< ::box2D::common::math::B2Vec2 > normals2 = poly2->m_normals;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",272)
		::box2D::common::math::B2Mat22 tMat;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",273)
		::box2D::common::math::B2Vec2 tVec;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",277)
		tMat = xf1->R;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",278)
		tVec = normals1->__get(edge1);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",279)
		double normal1X = ((tMat->col1->x * tVec->x) + (tMat->col2->x * tVec->y));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",280)
		double normal1Y = ((tMat->col1->y * tVec->x) + (tMat->col2->y * tVec->y));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",281)
		tMat = xf2->R;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",282)
		double tX = ((tMat->col1->x * normal1X) + (tMat->col1->y * normal1Y));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",283)
		normal1Y = ((tMat->col2->x * normal1X) + (tMat->col2->y * normal1Y));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",284)
		normal1X = tX;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",287)
		int index = (int)0;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",288)
		double minDot = 1.7976931348623158e+308;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",289)
		{
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",289)
			int _g = (int)0;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",289)
			while(((_g < count2))){
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",289)
				int i = (_g)++;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",292)
				tVec = normals2->__get(i);
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",293)
				double dot = ((normal1X * tVec->x) + (normal1Y * tVec->y));
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",294)
				if (((dot < minDot))){
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",296)
					minDot = dot;
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",297)
					index = i;
				}
			}
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",301)
		::box2D::collision::ClipVertex tClip;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",303)
		int i1 = index;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",304)
		int i2 = (  ((((i1 + (int)1) < count2))) ? int((i1 + (int)1)) : int((int)0) );
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",306)
		tClip = c->__get((int)0);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",308)
		tVec = vertices2->__get(i1);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",309)
		tMat = xf2->R;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",310)
		tClip->v->x = (xf2->position->x + (((tMat->col1->x * tVec->x) + (tMat->col2->x * tVec->y))));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",311)
		tClip->v->y = (xf2->position->y + (((tMat->col1->y * tVec->x) + (tMat->col2->y * tVec->y))));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",313)
		tClip->id->features->setReferenceEdge(edge1);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",314)
		tClip->id->features->setIncidentEdge(i1);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",315)
		tClip->id->features->setIncidentVertex((int)0);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",317)
		tClip = c->__get((int)1);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",319)
		tVec = vertices2->__get(i2);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",320)
		tMat = xf2->R;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",321)
		tClip->v->x = (xf2->position->x + (((tMat->col1->x * tVec->x) + (tMat->col2->x * tVec->y))));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",322)
		tClip->v->y = (xf2->position->y + (((tMat->col1->y * tVec->x) + (tMat->col2->y * tVec->y))));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",324)
		tClip->id->features->setReferenceEdge(edge1);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",325)
		tClip->id->features->setIncidentEdge(i2);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",326)
		tClip->id->features->setIncidentVertex((int)1);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC6(B2Collision_obj,findIncidentEdge,(void))

Array< ::box2D::collision::ClipVertex > B2Collision_obj::makeClipPointVector( ){
	HX_SOURCE_PUSH("B2Collision_obj::makeClipPointVector")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",332)
	Array< ::box2D::collision::ClipVertex > r = Array_obj< ::box2D::collision::ClipVertex >::__new();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",333)
	r[(int)0] = ::box2D::collision::ClipVertex_obj::__new();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",334)
	r[(int)1] = ::box2D::collision::ClipVertex_obj::__new();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",335)
	return r;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(B2Collision_obj,makeClipPointVector,return )

Array< ::box2D::collision::ClipVertex > B2Collision_obj::s_incidentEdge;

Array< ::box2D::collision::ClipVertex > B2Collision_obj::s_clipPoints1;

Array< ::box2D::collision::ClipVertex > B2Collision_obj::s_clipPoints2;

Array< int > B2Collision_obj::s_edgeAO;

Array< int > B2Collision_obj::s_edgeBO;

::box2D::common::math::B2Vec2 B2Collision_obj::s_localTangent;

::box2D::common::math::B2Vec2 B2Collision_obj::s_localNormal;

::box2D::common::math::B2Vec2 B2Collision_obj::s_planePoint;

::box2D::common::math::B2Vec2 B2Collision_obj::s_normal;

::box2D::common::math::B2Vec2 B2Collision_obj::s_tangent;

::box2D::common::math::B2Vec2 B2Collision_obj::s_tangent2;

::box2D::common::math::B2Vec2 B2Collision_obj::s_v11;

::box2D::common::math::B2Vec2 B2Collision_obj::s_v12;

::box2D::common::math::B2Vec2 B2Collision_obj::b2CollidePolyTempVec;

Void B2Collision_obj::collidePolygons( ::box2D::collision::B2Manifold manifold,::box2D::collision::shapes::B2PolygonShape polyA,::box2D::common::math::B2Transform xfA,::box2D::collision::shapes::B2PolygonShape polyB,::box2D::common::math::B2Transform xfB){
{
		HX_SOURCE_PUSH("B2Collision_obj::collidePolygons")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",361)
		::box2D::collision::ClipVertex cv;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",363)
		manifold->m_pointCount = (int)0;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",364)
		double totalRadius = (polyA->m_radius + polyB->m_radius);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",366)
		int edgeA = (int)0;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",367)
		::box2D::collision::B2Collision_obj::s_edgeAO[(int)0] = edgeA;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",368)
		double separationA = ::box2D::collision::B2Collision_obj::findMaxSeparation(::box2D::collision::B2Collision_obj::s_edgeAO,polyA,xfA,polyB,xfB);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",369)
		edgeA = ::box2D::collision::B2Collision_obj::s_edgeAO->__get((int)0);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",370)
		if (((separationA > totalRadius))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",371)
			return null();
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",373)
		int edgeB = (int)0;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",374)
		::box2D::collision::B2Collision_obj::s_edgeBO[(int)0] = edgeB;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",375)
		double separationB = ::box2D::collision::B2Collision_obj::findMaxSeparation(::box2D::collision::B2Collision_obj::s_edgeBO,polyB,xfB,polyA,xfA);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",376)
		edgeB = ::box2D::collision::B2Collision_obj::s_edgeBO->__get((int)0);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",377)
		if (((separationB > totalRadius))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",378)
			return null();
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",380)
		::box2D::collision::shapes::B2PolygonShape poly1;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",381)
		::box2D::collision::shapes::B2PolygonShape poly2;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",382)
		::box2D::common::math::B2Transform xf1;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",383)
		::box2D::common::math::B2Transform xf2;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",384)
		int edge1;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",385)
		int flip;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",386)
		double k_relativeTol = 0.98;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",387)
		double k_absoluteTol = 0.001;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",388)
		::box2D::common::math::B2Mat22 tMat;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",390)
		if (((separationB > ((k_relativeTol * separationA) + k_absoluteTol)))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",392)
			poly1 = polyB;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",393)
			poly2 = polyA;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",394)
			xf1 = xfB;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",395)
			xf2 = xfA;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",396)
			edge1 = edgeB;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",397)
			manifold->m_type = ::box2D::collision::B2Manifold_obj::e_faceB;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",398)
			flip = (int)1;
		}
		else{
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",402)
			poly1 = polyA;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",403)
			poly2 = polyB;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",404)
			xf1 = xfA;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",405)
			xf2 = xfB;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",406)
			edge1 = edgeA;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",407)
			manifold->m_type = ::box2D::collision::B2Manifold_obj::e_faceA;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",408)
			flip = (int)0;
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",411)
		Array< ::box2D::collision::ClipVertex > incidentEdge = ::box2D::collision::B2Collision_obj::s_incidentEdge;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",412)
		::box2D::collision::B2Collision_obj::findIncidentEdge(incidentEdge,poly1,xf1,edge1,poly2,xf2);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",414)
		int count1 = poly1->m_vertexCount;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",415)
		Array< ::box2D::common::math::B2Vec2 > vertices1 = poly1->m_vertices;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",417)
		::box2D::common::math::B2Vec2 local_v11 = vertices1->__get(edge1);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",418)
		::box2D::common::math::B2Vec2 local_v12;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",419)
		if ((((edge1 + (int)1) < count1))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",419)
			local_v12 = vertices1->__get(::Std_obj::_int((edge1 + (int)1)));
		}
		else{
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",421)
			local_v12 = vertices1->__get((int)0);
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",425)
		::box2D::common::math::B2Vec2 localTangent = ::box2D::collision::B2Collision_obj::s_localTangent;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",426)
		localTangent->set((local_v12->x - local_v11->x),(local_v12->y - local_v11->y));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",427)
		localTangent->normalize();
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",429)
		::box2D::common::math::B2Vec2 localNormal = ::box2D::collision::B2Collision_obj::s_localNormal;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",430)
		localNormal->x = localTangent->y;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",431)
		localNormal->y = -(localTangent->x);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",433)
		::box2D::common::math::B2Vec2 planePoint = ::box2D::collision::B2Collision_obj::s_planePoint;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",434)
		planePoint->set((0.5 * ((local_v11->x + local_v12->x))),(0.5 * ((local_v11->y + local_v12->y))));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",436)
		::box2D::common::math::B2Vec2 tangent = ::box2D::collision::B2Collision_obj::s_tangent;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",438)
		tMat = xf1->R;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",439)
		tangent->x = ((tMat->col1->x * localTangent->x) + (tMat->col2->x * localTangent->y));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",440)
		tangent->y = ((tMat->col1->y * localTangent->x) + (tMat->col2->y * localTangent->y));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",441)
		::box2D::common::math::B2Vec2 tangent2 = ::box2D::collision::B2Collision_obj::s_tangent2;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",442)
		tangent2->x = -(tangent->x);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",443)
		tangent2->y = -(tangent->y);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",444)
		::box2D::common::math::B2Vec2 normal = ::box2D::collision::B2Collision_obj::s_normal;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",445)
		normal->x = tangent->y;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",446)
		normal->y = -(tangent->x);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",450)
		::box2D::common::math::B2Vec2 v11 = ::box2D::collision::B2Collision_obj::s_v11;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",451)
		::box2D::common::math::B2Vec2 v12 = ::box2D::collision::B2Collision_obj::s_v12;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",452)
		v11->x = (xf1->position->x + (((tMat->col1->x * local_v11->x) + (tMat->col2->x * local_v11->y))));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",453)
		v11->y = (xf1->position->y + (((tMat->col1->y * local_v11->x) + (tMat->col2->y * local_v11->y))));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",454)
		v12->x = (xf1->position->x + (((tMat->col1->x * local_v12->x) + (tMat->col2->x * local_v12->y))));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",455)
		v12->y = (xf1->position->y + (((tMat->col1->y * local_v12->x) + (tMat->col2->y * local_v12->y))));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",458)
		double frontOffset = ((normal->x * v11->x) + (normal->y * v11->y));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",460)
		double sideOffset1 = (((-(tangent->x) * v11->x) - (tangent->y * v11->y)) + totalRadius);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",461)
		double sideOffset2 = (((tangent->x * v12->x) + (tangent->y * v12->y)) + totalRadius);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",464)
		Array< ::box2D::collision::ClipVertex > clipPoints1 = ::box2D::collision::B2Collision_obj::s_clipPoints1;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",465)
		Array< ::box2D::collision::ClipVertex > clipPoints2 = ::box2D::collision::B2Collision_obj::s_clipPoints2;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",466)
		int np;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",470)
		np = ::box2D::collision::B2Collision_obj::clipSegmentToLine(clipPoints1,incidentEdge,tangent2,sideOffset1);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",472)
		if (((np < (int)2))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",473)
			return null();
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",476)
		np = ::box2D::collision::B2Collision_obj::clipSegmentToLine(clipPoints2,clipPoints1,tangent,sideOffset2);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",478)
		if (((np < (int)2))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",479)
			return null();
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",482)
		manifold->m_localPlaneNormal->setV(localNormal);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",483)
		manifold->m_localPoint->setV(planePoint);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",485)
		int pointCount = (int)0;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",486)
		{
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",486)
			int _g1 = (int)0;
			int _g = ::box2D::common::B2Settings_obj::b2_maxManifoldPoints;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",486)
			while(((_g1 < _g))){
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",486)
				int i = (_g1)++;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",488)
				cv = clipPoints2->__get(i);
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",489)
				double separation = (((normal->x * cv->v->x) + (normal->y * cv->v->y)) - frontOffset);
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",490)
				if (((separation <= totalRadius))){
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",492)
					::box2D::collision::B2ManifoldPoint cp = manifold->m_points->__get(pointCount);
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",494)
					tMat = xf2->R;
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",495)
					double tX = (cv->v->x - xf2->position->x);
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",496)
					double tY = (cv->v->y - xf2->position->y);
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",497)
					cp->m_localPoint->x = ((tX * tMat->col1->x) + (tY * tMat->col1->y));
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",498)
					cp->m_localPoint->y = ((tX * tMat->col2->x) + (tY * tMat->col2->y));
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",499)
					cp->m_id->set(cv->id);
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",500)
					cp->m_id->features->setFlip(flip);
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",501)
					++(pointCount);
				}
			}
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",505)
		manifold->m_pointCount = pointCount;
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC5(B2Collision_obj,collidePolygons,(void))

Void B2Collision_obj::collideCircles( ::box2D::collision::B2Manifold manifold,::box2D::collision::shapes::B2CircleShape circle1,::box2D::common::math::B2Transform xf1,::box2D::collision::shapes::B2CircleShape circle2,::box2D::common::math::B2Transform xf2){
{
		HX_SOURCE_PUSH("B2Collision_obj::collideCircles")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",515)
		manifold->m_pointCount = (int)0;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",517)
		::box2D::common::math::B2Mat22 tMat;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",518)
		::box2D::common::math::B2Vec2 tVec;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",521)
		tMat = xf1->R;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",521)
		tVec = circle1->m_p;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",522)
		double p1X = (xf1->position->x + (((tMat->col1->x * tVec->x) + (tMat->col2->x * tVec->y))));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",523)
		double p1Y = (xf1->position->y + (((tMat->col1->y * tVec->x) + (tMat->col2->y * tVec->y))));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",525)
		tMat = xf2->R;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",525)
		tVec = circle2->m_p;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",526)
		double p2X = (xf2->position->x + (((tMat->col1->x * tVec->x) + (tMat->col2->x * tVec->y))));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",527)
		double p2Y = (xf2->position->y + (((tMat->col1->y * tVec->x) + (tMat->col2->y * tVec->y))));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",529)
		double dX = (p2X - p1X);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",530)
		double dY = (p2Y - p1Y);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",532)
		double distSqr = ((dX * dX) + (dY * dY));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",533)
		double radius = (circle1->m_radius + circle2->m_radius);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",534)
		if (((distSqr > (radius * radius)))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",535)
			return null();
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",538)
		manifold->m_type = ::box2D::collision::B2Manifold_obj::e_circles;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",539)
		manifold->m_localPoint->setV(circle1->m_p);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",540)
		manifold->m_localPlaneNormal->setZero();
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",541)
		manifold->m_pointCount = (int)1;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",542)
		manifold->m_points->__get((int)0)->m_localPoint->setV(circle2->m_p);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",543)
		manifold->m_points->__get((int)0)->m_id->setKey((int)0);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC5(B2Collision_obj,collideCircles,(void))

Void B2Collision_obj::collidePolygonAndCircle( ::box2D::collision::B2Manifold manifold,::box2D::collision::shapes::B2PolygonShape polygon,::box2D::common::math::B2Transform xf1,::box2D::collision::shapes::B2CircleShape circle,::box2D::common::math::B2Transform xf2){
{
		HX_SOURCE_PUSH("B2Collision_obj::collidePolygonAndCircle")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",553)
		manifold->m_pointCount = (int)0;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",554)
		::box2D::collision::B2ManifoldPoint tPoint;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",556)
		double dX;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",557)
		double dY;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",558)
		double positionX;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",559)
		double positionY;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",561)
		::box2D::common::math::B2Vec2 tVec;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",562)
		::box2D::common::math::B2Mat22 tMat;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",566)
		tMat = xf2->R;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",567)
		tVec = circle->m_p;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",568)
		double cX = (xf2->position->x + (((tMat->col1->x * tVec->x) + (tMat->col2->x * tVec->y))));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",569)
		double cY = (xf2->position->y + (((tMat->col1->y * tVec->x) + (tMat->col2->y * tVec->y))));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",572)
		dX = (cX - xf1->position->x);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",573)
		dY = (cY - xf1->position->y);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",574)
		tMat = xf1->R;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",575)
		double cLocalX = ((dX * tMat->col1->x) + (dY * tMat->col1->y));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",576)
		double cLocalY = ((dX * tMat->col2->x) + (dY * tMat->col2->y));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",578)
		double dist;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",581)
		int normalIndex = (int)0;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",582)
		double separation = -(1.7976931348623158e+308);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",583)
		double radius = (polygon->m_radius + circle->m_radius);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",584)
		int vertexCount = polygon->m_vertexCount;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",585)
		Array< ::box2D::common::math::B2Vec2 > vertices = polygon->m_vertices;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",586)
		Array< ::box2D::common::math::B2Vec2 > normals = polygon->m_normals;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",588)
		{
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",588)
			int _g = (int)0;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",588)
			while(((_g < vertexCount))){
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",588)
				int i = (_g)++;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",591)
				tVec = vertices->__get(i);
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",592)
				dX = (cLocalX - tVec->x);
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",593)
				dY = (cLocalY - tVec->y);
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",594)
				tVec = normals->__get(i);
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",595)
				double s = ((tVec->x * dX) + (tVec->y * dY));
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",597)
				if (((s > radius))){
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",598)
					return null();
				}
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",603)
				if (((s > separation))){
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",605)
					separation = s;
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",606)
					normalIndex = i;
				}
			}
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",610)
		int vertIndex1 = normalIndex;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",611)
		int vertIndex2 = (  ((((vertIndex1 + (int)1) < vertexCount))) ? int((vertIndex1 + (int)1)) : int((int)0) );
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",612)
		::box2D::common::math::B2Vec2 v1 = vertices->__get(vertIndex1);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",613)
		::box2D::common::math::B2Vec2 v2 = vertices->__get(vertIndex2);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",616)
		if (((separation < 2.2250738585072014e-308))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",618)
			manifold->m_pointCount = (int)1;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",619)
			manifold->m_type = ::box2D::collision::B2Manifold_obj::e_faceA;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",620)
			manifold->m_localPlaneNormal->setV(normals->__get(normalIndex));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",621)
			manifold->m_localPoint->x = (0.5 * ((v1->x + v2->x)));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",622)
			manifold->m_localPoint->y = (0.5 * ((v1->y + v2->y)));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",623)
			manifold->m_points->__get((int)0)->m_localPoint->setV(circle->m_p);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",624)
			manifold->m_points->__get((int)0)->m_id->setKey((int)0);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",625)
			return null();
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",629)
		double u1 = ((((cLocalX - v1->x)) * ((v2->x - v1->x))) + (((cLocalY - v1->y)) * ((v2->y - v1->y))));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",630)
		double u2 = ((((cLocalX - v2->x)) * ((v1->x - v2->x))) + (((cLocalY - v2->y)) * ((v1->y - v2->y))));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",631)
		if (((u1 <= 0.0))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",633)
			if (((((((cLocalX - v1->x)) * ((cLocalX - v1->x))) + (((cLocalY - v1->y)) * ((cLocalY - v1->y)))) > (radius * radius)))){
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",634)
				return null();
			}
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",635)
			manifold->m_pointCount = (int)1;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",636)
			manifold->m_type = ::box2D::collision::B2Manifold_obj::e_faceA;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",637)
			manifold->m_localPlaneNormal->x = (cLocalX - v1->x);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",638)
			manifold->m_localPlaneNormal->y = (cLocalY - v1->y);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",639)
			manifold->m_localPlaneNormal->normalize();
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",640)
			manifold->m_localPoint->setV(v1);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",641)
			manifold->m_points->__get((int)0)->m_localPoint->setV(circle->m_p);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",642)
			manifold->m_points->__get((int)0)->m_id->setKey((int)0);
		}
		else{
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",644)
			if (((u2 <= (int)0))){
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",646)
				if (((((((cLocalX - v2->x)) * ((cLocalX - v2->x))) + (((cLocalY - v2->y)) * ((cLocalY - v2->y)))) > (radius * radius)))){
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",647)
					return null();
				}
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",648)
				manifold->m_pointCount = (int)1;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",649)
				manifold->m_type = ::box2D::collision::B2Manifold_obj::e_faceA;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",650)
				manifold->m_localPlaneNormal->x = (cLocalX - v2->x);
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",651)
				manifold->m_localPlaneNormal->y = (cLocalY - v2->y);
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",652)
				manifold->m_localPlaneNormal->normalize();
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",653)
				manifold->m_localPoint->setV(v2);
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",654)
				manifold->m_points->__get((int)0)->m_localPoint->setV(circle->m_p);
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",655)
				manifold->m_points->__get((int)0)->m_id->setKey((int)0);
			}
			else{
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",659)
				double faceCenterX = (0.5 * ((v1->x + v2->x)));
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",660)
				double faceCenterY = (0.5 * ((v1->y + v2->y)));
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",661)
				separation = ((((cLocalX - faceCenterX)) * normals->__get(vertIndex1)->x) + (((cLocalY - faceCenterY)) * normals->__get(vertIndex1)->y));
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",662)
				if (((separation > radius))){
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",663)
					return null();
				}
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",664)
				manifold->m_pointCount = (int)1;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",665)
				manifold->m_type = ::box2D::collision::B2Manifold_obj::e_faceA;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",666)
				manifold->m_localPlaneNormal->x = normals->__get(vertIndex1)->x;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",667)
				manifold->m_localPlaneNormal->y = normals->__get(vertIndex1)->y;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",668)
				manifold->m_localPlaneNormal->normalize();
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",669)
				manifold->m_localPoint->set(faceCenterX,faceCenterY);
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",670)
				manifold->m_points->__get((int)0)->m_localPoint->setV(circle->m_p);
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",671)
				manifold->m_points->__get((int)0)->m_id->setKey((int)0);
			}
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC5(B2Collision_obj,collidePolygonAndCircle,(void))

bool B2Collision_obj::testOverlap( ::box2D::collision::B2AABB a,::box2D::collision::B2AABB b){
	HX_SOURCE_PUSH("B2Collision_obj::testOverlap")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",680)
	::box2D::common::math::B2Vec2 t1 = b->lowerBound;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",681)
	::box2D::common::math::B2Vec2 t2 = a->upperBound;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",683)
	double d1X = (t1->x - t2->x);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",684)
	double d1Y = (t1->y - t2->y);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",686)
	t1 = a->lowerBound;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",687)
	t2 = b->upperBound;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",688)
	double d2X = (t1->x - t2->x);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",689)
	double d2Y = (t1->y - t2->y);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",691)
	if (((bool((d1X > 0.0)) || bool((d1Y > 0.0))))){
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",692)
		return false;
	}
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",694)
	if (((bool((d2X > 0.0)) || bool((d2Y > 0.0))))){
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",695)
		return false;
	}
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Collision.hx",697)
	return true;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(B2Collision_obj,testOverlap,return )


B2Collision_obj::B2Collision_obj()
{
}

void B2Collision_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(B2Collision);
	HX_MARK_END_CLASS();
}

Dynamic B2Collision_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"s_v11") ) { return s_v11; }
		if (HX_FIELD_EQ(inName,"s_v12") ) { return s_v12; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"s_edgeAO") ) { return s_edgeAO; }
		if (HX_FIELD_EQ(inName,"s_edgeBO") ) { return s_edgeBO; }
		if (HX_FIELD_EQ(inName,"s_normal") ) { return s_normal; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"s_tangent") ) { return s_tangent; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"s_tangent2") ) { return s_tangent2; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"testOverlap") ) { return testOverlap_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"s_planePoint") ) { return s_planePoint; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"s_clipPoints1") ) { return s_clipPoints1; }
		if (HX_FIELD_EQ(inName,"s_clipPoints2") ) { return s_clipPoints2; }
		if (HX_FIELD_EQ(inName,"s_localNormal") ) { return s_localNormal; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"b2_nullFeature") ) { return b2_nullFeature; }
		if (HX_FIELD_EQ(inName,"edgeSeparation") ) { return edgeSeparation_dyn(); }
		if (HX_FIELD_EQ(inName,"s_incidentEdge") ) { return s_incidentEdge; }
		if (HX_FIELD_EQ(inName,"s_localTangent") ) { return s_localTangent; }
		if (HX_FIELD_EQ(inName,"collideCircles") ) { return collideCircles_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"collidePolygons") ) { return collidePolygons_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"findIncidentEdge") ) { return findIncidentEdge_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"clipSegmentToLine") ) { return clipSegmentToLine_dyn(); }
		if (HX_FIELD_EQ(inName,"findMaxSeparation") ) { return findMaxSeparation_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"makeClipPointVector") ) { return makeClipPointVector_dyn(); }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"b2CollidePolyTempVec") ) { return b2CollidePolyTempVec; }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"collidePolygonAndCircle") ) { return collidePolygonAndCircle_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic B2Collision_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"s_v11") ) { s_v11=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"s_v12") ) { s_v12=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"s_edgeAO") ) { s_edgeAO=inValue.Cast< Array< int > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"s_edgeBO") ) { s_edgeBO=inValue.Cast< Array< int > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"s_normal") ) { s_normal=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"s_tangent") ) { s_tangent=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"s_tangent2") ) { s_tangent2=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"s_planePoint") ) { s_planePoint=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"s_clipPoints1") ) { s_clipPoints1=inValue.Cast< Array< ::box2D::collision::ClipVertex > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"s_clipPoints2") ) { s_clipPoints2=inValue.Cast< Array< ::box2D::collision::ClipVertex > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"s_localNormal") ) { s_localNormal=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"b2_nullFeature") ) { b2_nullFeature=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"s_incidentEdge") ) { s_incidentEdge=inValue.Cast< Array< ::box2D::collision::ClipVertex > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"s_localTangent") ) { s_localTangent=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"b2CollidePolyTempVec") ) { b2CollidePolyTempVec=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void B2Collision_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("b2_nullFeature"),
	HX_CSTRING("clipSegmentToLine"),
	HX_CSTRING("edgeSeparation"),
	HX_CSTRING("findMaxSeparation"),
	HX_CSTRING("findIncidentEdge"),
	HX_CSTRING("makeClipPointVector"),
	HX_CSTRING("s_incidentEdge"),
	HX_CSTRING("s_clipPoints1"),
	HX_CSTRING("s_clipPoints2"),
	HX_CSTRING("s_edgeAO"),
	HX_CSTRING("s_edgeBO"),
	HX_CSTRING("s_localTangent"),
	HX_CSTRING("s_localNormal"),
	HX_CSTRING("s_planePoint"),
	HX_CSTRING("s_normal"),
	HX_CSTRING("s_tangent"),
	HX_CSTRING("s_tangent2"),
	HX_CSTRING("s_v11"),
	HX_CSTRING("s_v12"),
	HX_CSTRING("b2CollidePolyTempVec"),
	HX_CSTRING("collidePolygons"),
	HX_CSTRING("collideCircles"),
	HX_CSTRING("collidePolygonAndCircle"),
	HX_CSTRING("testOverlap"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(B2Collision_obj::b2_nullFeature,"b2_nullFeature");
	HX_MARK_MEMBER_NAME(B2Collision_obj::s_incidentEdge,"s_incidentEdge");
	HX_MARK_MEMBER_NAME(B2Collision_obj::s_clipPoints1,"s_clipPoints1");
	HX_MARK_MEMBER_NAME(B2Collision_obj::s_clipPoints2,"s_clipPoints2");
	HX_MARK_MEMBER_NAME(B2Collision_obj::s_edgeAO,"s_edgeAO");
	HX_MARK_MEMBER_NAME(B2Collision_obj::s_edgeBO,"s_edgeBO");
	HX_MARK_MEMBER_NAME(B2Collision_obj::s_localTangent,"s_localTangent");
	HX_MARK_MEMBER_NAME(B2Collision_obj::s_localNormal,"s_localNormal");
	HX_MARK_MEMBER_NAME(B2Collision_obj::s_planePoint,"s_planePoint");
	HX_MARK_MEMBER_NAME(B2Collision_obj::s_normal,"s_normal");
	HX_MARK_MEMBER_NAME(B2Collision_obj::s_tangent,"s_tangent");
	HX_MARK_MEMBER_NAME(B2Collision_obj::s_tangent2,"s_tangent2");
	HX_MARK_MEMBER_NAME(B2Collision_obj::s_v11,"s_v11");
	HX_MARK_MEMBER_NAME(B2Collision_obj::s_v12,"s_v12");
	HX_MARK_MEMBER_NAME(B2Collision_obj::b2CollidePolyTempVec,"b2CollidePolyTempVec");
};

Class B2Collision_obj::__mClass;

void B2Collision_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.collision.B2Collision"), hx::TCanCast< B2Collision_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void B2Collision_obj::__boot()
{
	hx::Static(b2_nullFeature) = (int)255;
	hx::Static(s_incidentEdge) = ::box2D::collision::B2Collision_obj::makeClipPointVector();
	hx::Static(s_clipPoints1) = ::box2D::collision::B2Collision_obj::makeClipPointVector();
	hx::Static(s_clipPoints2) = ::box2D::collision::B2Collision_obj::makeClipPointVector();
	hx::Static(s_edgeAO) = Array_obj< int >::__new();
	hx::Static(s_edgeBO) = Array_obj< int >::__new();
	hx::Static(s_localTangent) = ::box2D::common::math::B2Vec2_obj::__new(null(),null());
	hx::Static(s_localNormal) = ::box2D::common::math::B2Vec2_obj::__new(null(),null());
	hx::Static(s_planePoint) = ::box2D::common::math::B2Vec2_obj::__new(null(),null());
	hx::Static(s_normal) = ::box2D::common::math::B2Vec2_obj::__new(null(),null());
	hx::Static(s_tangent) = ::box2D::common::math::B2Vec2_obj::__new(null(),null());
	hx::Static(s_tangent2) = ::box2D::common::math::B2Vec2_obj::__new(null(),null());
	hx::Static(s_v11) = ::box2D::common::math::B2Vec2_obj::__new(null(),null());
	hx::Static(s_v12) = ::box2D::common::math::B2Vec2_obj::__new(null(),null());
	hx::Static(b2CollidePolyTempVec) = ::box2D::common::math::B2Vec2_obj::__new(null(),null());
}

} // end namespace box2D
} // end namespace collision
