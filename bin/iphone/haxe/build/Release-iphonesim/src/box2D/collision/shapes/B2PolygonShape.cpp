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
#ifndef INCLUDED_box2D_collision_B2OBB
#include <box2D/collision/B2OBB.h>
#endif
#ifndef INCLUDED_box2D_collision_B2RayCastInput
#include <box2D/collision/B2RayCastInput.h>
#endif
#ifndef INCLUDED_box2D_collision_B2RayCastOutput
#include <box2D/collision/B2RayCastOutput.h>
#endif
#ifndef INCLUDED_box2D_collision_shapes_B2MassData
#include <box2D/collision/shapes/B2MassData.h>
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

Void B2PolygonShape_obj::__construct()
{
{
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",725)
	super::__construct();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",728)
	this->m_type = ::box2D::collision::shapes::B2Shape_obj::e_polygonShape;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",730)
	this->m_centroid = ::box2D::common::math::B2Vec2_obj::__new(null(),null());
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",731)
	this->m_vertices = Array_obj< ::box2D::common::math::B2Vec2 >::__new();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",732)
	this->m_normals = Array_obj< ::box2D::common::math::B2Vec2 >::__new();
}
;
	return null();
}

B2PolygonShape_obj::~B2PolygonShape_obj() { }

Dynamic B2PolygonShape_obj::__CreateEmpty() { return  new B2PolygonShape_obj; }
hx::ObjectPtr< B2PolygonShape_obj > B2PolygonShape_obj::__new()
{  hx::ObjectPtr< B2PolygonShape_obj > result = new B2PolygonShape_obj();
	result->__construct();
	return result;}

Dynamic B2PolygonShape_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2PolygonShape_obj > result = new B2PolygonShape_obj();
	result->__construct();
	return result;}

::box2D::collision::shapes::B2Shape B2PolygonShape_obj::copy( ){
	HX_SOURCE_PUSH("B2PolygonShape_obj::copy")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",43)
	::box2D::collision::shapes::B2PolygonShape s = ::box2D::collision::shapes::B2PolygonShape_obj::__new();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",44)
	s->set(hx::ObjectPtr<OBJ_>(this));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",45)
	return s;
}


HX_DEFINE_DYNAMIC_FUNC0(B2PolygonShape_obj,copy,return )

Void B2PolygonShape_obj::set( ::box2D::collision::shapes::B2Shape other){
{
		HX_SOURCE_PUSH("B2PolygonShape_obj::set")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",50)
		this->super::set(other);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",51)
		if ((::Std_obj::is(other,hx::ClassOf< ::box2D::collision::shapes::B2PolygonShape >()))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",53)
			::box2D::collision::shapes::B2PolygonShape other2 = hx::TCast< box2D::collision::shapes::B2PolygonShape >::cast(other);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",54)
			this->m_centroid->setV(other2->m_centroid);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",55)
			this->m_vertexCount = other2->m_vertexCount;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",56)
			this->reserve(this->m_vertexCount);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",57)
			{
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",57)
				int _g1 = (int)0;
				int _g = this->m_vertexCount;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",57)
				while(((_g1 < _g))){
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",57)
					int i = (_g1)++;
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",59)
					this->m_vertices->__get(i)->setV(other2->m_vertices->__get(i));
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",60)
					this->m_normals->__get(i)->setV(other2->m_normals->__get(i));
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2PolygonShape_obj,set,(void))

Void B2PolygonShape_obj::setAsArray( Dynamic vertices,Dynamic __o_vertexCount){
double vertexCount = __o_vertexCount.Default(0);
	HX_SOURCE_PUSH("B2PolygonShape_obj::setAsArray");
{
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",71)
		Array< ::box2D::common::math::B2Vec2 > v = Array_obj< ::box2D::common::math::B2Vec2 >::__new();
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",72)
		{
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",72)
			int _g = (int)0;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",72)
			while(((_g < vertices->__Field(HX_CSTRING("length"))))){
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",72)
				Dynamic tVec = vertices->__GetItem(_g);
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",72)
				++(_g);
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",74)
				v->push(tVec);
			}
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",76)
		this->setAsVector(v,vertexCount);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(B2PolygonShape_obj,setAsArray,(void))

Void B2PolygonShape_obj::setAsVector( Array< ::box2D::common::math::B2Vec2 > vertices,Dynamic __o_vertexCount){
double vertexCount = __o_vertexCount.Default(0);
	HX_SOURCE_PUSH("B2PolygonShape_obj::setAsVector");
{
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",92)
		if (((vertexCount == (int)0))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",93)
			vertexCount = vertices->length;
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",95)
		::box2D::common::B2Settings_obj::b2Assert(((int)2 <= vertexCount));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",96)
		this->m_vertexCount = ::Std_obj::_int(vertexCount);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",98)
		this->reserve(::Std_obj::_int(vertexCount));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",100)
		int i;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",103)
		{
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",103)
			int _g1 = (int)0;
			int _g = this->m_vertexCount;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",103)
			while(((_g1 < _g))){
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",103)
				int i1 = (_g1)++;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",105)
				this->m_vertices->__get(i1)->setV(vertices->__get(i1));
			}
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",109)
		{
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",109)
			int _g1 = (int)0;
			int _g = this->m_vertexCount;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",109)
			while(((_g1 < _g))){
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",109)
				int i1 = (_g1)++;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",111)
				int i11 = i1;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",112)
				int i2 = (  ((((i1 + (int)1) < this->m_vertexCount))) ? int((i1 + (int)1)) : int((int)0) );
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",113)
				::box2D::common::math::B2Vec2 edge = ::box2D::common::math::B2Math_obj::subtractVV(this->m_vertices->__get(i2),this->m_vertices->__get(i11));
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",114)
				::box2D::common::B2Settings_obj::b2Assert((edge->lengthSquared() > 2.2250738585072014e-308));
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",115)
				this->m_normals->__get(i1)->setV(::box2D::common::math::B2Math_obj::crossVF(edge,1.0));
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",116)
				this->m_normals->__get(i1)->normalize();
			}
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",120)
		this->m_centroid = ::box2D::collision::shapes::B2PolygonShape_obj::computeCentroid(this->m_vertices,this->m_vertexCount);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(B2PolygonShape_obj,setAsVector,(void))

Void B2PolygonShape_obj::setAsBox( double hx,double hy){
{
		HX_SOURCE_PUSH("B2PolygonShape_obj::setAsBox")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",137)
		this->m_vertexCount = (int)4;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",138)
		this->reserve((int)4);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",139)
		this->m_vertices->__get((int)0)->set(-(hx),-(hy));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",140)
		this->m_vertices->__get((int)1)->set(hx,-(hy));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",141)
		this->m_vertices->__get((int)2)->set(hx,hy);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",142)
		this->m_vertices->__get((int)3)->set(-(hx),hy);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",143)
		this->m_normals->__get((int)0)->set(0.0,-1.0);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",144)
		this->m_normals->__get((int)1)->set(1.0,0.0);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",145)
		this->m_normals->__get((int)2)->set(0.0,1.0);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",146)
		this->m_normals->__get((int)3)->set(-1.0,0.0);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",147)
		this->m_centroid->setZero();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(B2PolygonShape_obj,setAsBox,(void))

Void B2PolygonShape_obj::setAsOrientedBox( double hx,double hy,::box2D::common::math::B2Vec2 center,Dynamic __o_angle){
double angle = __o_angle.Default(0.0);
	HX_SOURCE_PUSH("B2PolygonShape_obj::setAsOrientedBox");
{
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",167)
		this->m_vertexCount = (int)4;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",168)
		this->reserve((int)4);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",169)
		this->m_vertices->__get((int)0)->set(-(hx),-(hy));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",170)
		this->m_vertices->__get((int)1)->set(hx,-(hy));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",171)
		this->m_vertices->__get((int)2)->set(hx,hy);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",172)
		this->m_vertices->__get((int)3)->set(-(hx),hy);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",173)
		this->m_normals->__get((int)0)->set(0.0,-1.0);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",174)
		this->m_normals->__get((int)1)->set(1.0,0.0);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",175)
		this->m_normals->__get((int)2)->set(0.0,1.0);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",176)
		this->m_normals->__get((int)3)->set(-1.0,0.0);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",177)
		this->m_centroid = center;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",179)
		::box2D::common::math::B2Transform xf = ::box2D::common::math::B2Transform_obj::__new(null(),null());
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",180)
		xf->position = center;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",181)
		xf->R->set(angle);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",184)
		{
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",184)
			int _g1 = (int)0;
			int _g = this->m_vertexCount;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",184)
			while(((_g1 < _g))){
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",184)
				int i = (_g1)++;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",186)
				this->m_vertices[i] = ::box2D::common::math::B2Math_obj::mulX(xf,this->m_vertices->__get(i));
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",187)
				this->m_normals[i] = ::box2D::common::math::B2Math_obj::mulMV(xf->R,this->m_normals->__get(i));
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(B2PolygonShape_obj,setAsOrientedBox,(void))

Void B2PolygonShape_obj::setAsEdge( ::box2D::common::math::B2Vec2 v1,::box2D::common::math::B2Vec2 v2){
{
		HX_SOURCE_PUSH("B2PolygonShape_obj::setAsEdge")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",203)
		this->m_vertexCount = (int)2;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",204)
		this->reserve((int)2);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",205)
		this->m_vertices->__get((int)0)->setV(v1);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",206)
		this->m_vertices->__get((int)1)->setV(v2);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",207)
		this->m_centroid->x = (0.5 * ((v1->x + v2->x)));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",208)
		this->m_centroid->y = (0.5 * ((v1->y + v2->y)));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",209)
		this->m_normals[(int)0] = ::box2D::common::math::B2Math_obj::crossVF(::box2D::common::math::B2Math_obj::subtractVV(v2,v1),1.0);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",210)
		this->m_normals->__get((int)0)->normalize();
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",211)
		this->m_normals->__get((int)1)->x = -(this->m_normals->__get((int)0)->x);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",212)
		this->m_normals->__get((int)1)->y = -(this->m_normals->__get((int)0)->y);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(B2PolygonShape_obj,setAsEdge,(void))

bool B2PolygonShape_obj::testPoint( ::box2D::common::math::B2Transform xf,::box2D::common::math::B2Vec2 p){
	HX_SOURCE_PUSH("B2PolygonShape_obj::testPoint")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",230)
	::box2D::common::math::B2Vec2 tVec;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",233)
	::box2D::common::math::B2Mat22 tMat = xf->R;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",234)
	double tX = (p->x - xf->position->x);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",235)
	double tY = (p->y - xf->position->y);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",236)
	double pLocalX = ((tX * tMat->col1->x) + (tY * tMat->col1->y));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",237)
	double pLocalY = ((tX * tMat->col2->x) + (tY * tMat->col2->y));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",239)
	{
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",239)
		int _g1 = (int)0;
		int _g = this->m_vertexCount;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",239)
		while(((_g1 < _g))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",239)
			int i = (_g1)++;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",242)
			tVec = this->m_vertices->__get(i);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",243)
			tX = (pLocalX - tVec->x);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",244)
			tY = (pLocalY - tVec->y);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",245)
			tVec = this->m_normals->__get(i);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",246)
			double dot = ((tVec->x * tX) + (tVec->y * tY));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",247)
			if (((dot > 0.0))){
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",248)
				return false;
			}
		}
	}
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",253)
	return true;
}


HX_DEFINE_DYNAMIC_FUNC2(B2PolygonShape_obj,testPoint,return )

bool B2PolygonShape_obj::rayCast( ::box2D::collision::B2RayCastOutput output,::box2D::collision::B2RayCastInput input,::box2D::common::math::B2Transform transform){
	HX_SOURCE_PUSH("B2PolygonShape_obj::rayCast")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",261)
	double lower = 0.0;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",262)
	double upper = input->maxFraction;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",264)
	double tX;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",265)
	double tY;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",266)
	::box2D::common::math::B2Mat22 tMat;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",267)
	::box2D::common::math::B2Vec2 tVec;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",271)
	tX = (input->p1->x - transform->position->x);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",272)
	tY = (input->p1->y - transform->position->y);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",273)
	tMat = transform->R;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",274)
	double p1X = ((tX * tMat->col1->x) + (tY * tMat->col1->y));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",275)
	double p1Y = ((tX * tMat->col2->x) + (tY * tMat->col2->y));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",277)
	tX = (input->p2->x - transform->position->x);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",278)
	tY = (input->p2->y - transform->position->y);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",279)
	tMat = transform->R;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",280)
	double p2X = ((tX * tMat->col1->x) + (tY * tMat->col1->y));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",281)
	double p2Y = ((tX * tMat->col2->x) + (tY * tMat->col2->y));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",283)
	double dX = (p2X - p1X);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",284)
	double dY = (p2Y - p1Y);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",285)
	int index = (int)-1;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",287)
	{
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",287)
		int _g1 = (int)0;
		int _g = this->m_vertexCount;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",287)
		while(((_g1 < _g))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",287)
			int i = (_g1)++;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",294)
			tVec = this->m_vertices->__get(i);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",295)
			tX = (tVec->x - p1X);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",296)
			tY = (tVec->y - p1Y);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",297)
			tVec = this->m_normals->__get(i);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",298)
			double numerator = ((tVec->x * tX) + (tVec->y * tY));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",300)
			double denominator = ((tVec->x * dX) + (tVec->y * dY));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",302)
			if (((denominator == 0.0))){
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",303)
				if (((numerator < 0.0))){
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",305)
					return false;
				}
			}
			else{
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",310)
				if (((bool((denominator < 0.0)) && bool((numerator < (lower * denominator)))))){
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",319)
					lower = (double(numerator) / double(denominator));
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",320)
					index = i;
				}
				else{
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",322)
					if (((bool((denominator > 0.0)) && bool((numerator < (upper * denominator)))))){
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",323)
						upper = (double(numerator) / double(denominator));
					}
				}
			}
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",330)
			if (((upper < (lower - 2.2250738585072014e-308)))){
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",331)
				return false;
			}
		}
	}
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",338)
	if (((index >= (int)0))){
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",340)
		output->fraction = lower;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",342)
		tMat = transform->R;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",343)
		tVec = this->m_normals->__get(index);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",344)
		output->normal->x = ((tMat->col1->x * tVec->x) + (tMat->col2->x * tVec->y));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",345)
		output->normal->y = ((tMat->col1->y * tVec->x) + (tMat->col2->y * tVec->y));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",346)
		return true;
	}
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",349)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC3(B2PolygonShape_obj,rayCast,return )

Void B2PolygonShape_obj::computeAABB( ::box2D::collision::B2AABB aabb,::box2D::common::math::B2Transform xf){
{
		HX_SOURCE_PUSH("B2PolygonShape_obj::computeAABB")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",359)
		::box2D::common::math::B2Mat22 tMat = xf->R;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",360)
		::box2D::common::math::B2Vec2 tVec = this->m_vertices->__get((int)0);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",361)
		double lowerX = (xf->position->x + (((tMat->col1->x * tVec->x) + (tMat->col2->x * tVec->y))));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",362)
		double lowerY = (xf->position->y + (((tMat->col1->y * tVec->x) + (tMat->col2->y * tVec->y))));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",363)
		double upperX = lowerX;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",364)
		double upperY = lowerY;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",366)
		{
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",366)
			int _g1 = (int)1;
			int _g = this->m_vertexCount;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",366)
			while(((_g1 < _g))){
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",366)
				int i = (_g1)++;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",368)
				tVec = this->m_vertices->__get(i);
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",369)
				double vX = (xf->position->x + (((tMat->col1->x * tVec->x) + (tMat->col2->x * tVec->y))));
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",370)
				double vY = (xf->position->y + (((tMat->col1->y * tVec->x) + (tMat->col2->y * tVec->y))));
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",371)
				lowerX = (  (((lowerX < vX))) ? double(lowerX) : double(vX) );
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",372)
				lowerY = (  (((lowerY < vY))) ? double(lowerY) : double(vY) );
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",373)
				upperX = (  (((upperX > vX))) ? double(upperX) : double(vX) );
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",374)
				upperY = (  (((upperY > vY))) ? double(upperY) : double(vY) );
			}
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",377)
		aabb->lowerBound->x = (lowerX - this->m_radius);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",378)
		aabb->lowerBound->y = (lowerY - this->m_radius);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",379)
		aabb->upperBound->x = (upperX + this->m_radius);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",380)
		aabb->upperBound->y = (upperY + this->m_radius);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(B2PolygonShape_obj,computeAABB,(void))

Void B2PolygonShape_obj::computeMass( ::box2D::collision::shapes::B2MassData massData,double density){
{
		HX_SOURCE_PUSH("B2PolygonShape_obj::computeMass")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",415)
		if (((this->m_vertexCount == (int)2))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",417)
			massData->center->x = (0.5 * ((this->m_vertices->__get((int)0)->x + this->m_vertices->__get((int)1)->x)));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",418)
			massData->center->y = (0.5 * ((this->m_vertices->__get((int)0)->y + this->m_vertices->__get((int)1)->y)));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",419)
			massData->mass = 0.0;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",420)
			massData->I = 0.0;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",421)
			return null();
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",425)
		double centerX = 0.0;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",426)
		double centerY = 0.0;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",427)
		double area = 0.0;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",428)
		double I = 0.0;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",433)
		double p1X = 0.0;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",434)
		double p1Y = 0.0;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",444)
		double k_inv3 = (double(1.0) / double(3.0));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",446)
		{
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",446)
			int _g1 = (int)0;
			int _g = this->m_vertexCount;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",446)
			while(((_g1 < _g))){
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",446)
				int i = (_g1)++;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",452)
				::box2D::common::math::B2Vec2 p2 = this->m_vertices->__get(i);
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",454)
				::box2D::common::math::B2Vec2 p3 = (  ((((i + (int)1) < this->m_vertexCount))) ? ::box2D::common::math::B2Vec2(this->m_vertices->__get(::Std_obj::_int((i + (int)1)))) : ::box2D::common::math::B2Vec2(this->m_vertices->__get((int)0)) );
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",457)
				double e1X = (p2->x - p1X);
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",458)
				double e1Y = (p2->y - p1Y);
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",460)
				double e2X = (p3->x - p1X);
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",461)
				double e2Y = (p3->y - p1Y);
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",464)
				double D = ((e1X * e2Y) - (e1Y * e2X));
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",467)
				double triangleArea = (0.5 * D);
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",468)
				hx::AddEq(area,triangleArea);
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",472)
				hx::AddEq(centerX,((triangleArea * k_inv3) * (((p1X + p2->x) + p3->x))));
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",473)
				hx::AddEq(centerY,((triangleArea * k_inv3) * (((p1Y + p2->y) + p3->y))));
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",476)
				double px = p1X;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",477)
				double py = p1Y;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",479)
				double ex1 = e1X;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",480)
				double ey1 = e1Y;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",482)
				double ex2 = e2X;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",483)
				double ey2 = e2Y;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",486)
				double intx2 = ((k_inv3 * (((0.25 * ((((ex1 * ex1) + (ex2 * ex1)) + (ex2 * ex2)))) + (((px * ex1) + (px * ex2)))))) + ((0.5 * px) * px));
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",488)
				double inty2 = ((k_inv3 * (((0.25 * ((((ey1 * ey1) + (ey2 * ey1)) + (ey2 * ey2)))) + (((py * ey1) + (py * ey2)))))) + ((0.5 * py) * py));
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",490)
				hx::AddEq(I,(D * ((intx2 + inty2))));
			}
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",494)
		massData->mass = (density * area);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",499)
		hx::MultEq(centerX,(double(1.0) / double(area)));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",500)
		hx::MultEq(centerY,(double(1.0) / double(area)));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",502)
		massData->center->set(centerX,centerY);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",505)
		massData->I = (density * I);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(B2PolygonShape_obj,computeMass,(void))

double B2PolygonShape_obj::computeSubmergedArea( ::box2D::common::math::B2Vec2 normal,double offset,::box2D::common::math::B2Transform xf,::box2D::common::math::B2Vec2 c){
	HX_SOURCE_PUSH("B2PolygonShape_obj::computeSubmergedArea")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",518)
	::box2D::common::math::B2Vec2 normalL = ::box2D::common::math::B2Math_obj::mulTMV(xf->R,normal);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",519)
	double offsetL = (offset - ::box2D::common::math::B2Math_obj::dot(normal,xf->position));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",521)
	Array< double > depths = Array_obj< double >::__new();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",522)
	int diveCount = (int)0;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",523)
	int intoIndex = (int)-1;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",524)
	int outoIndex = (int)-1;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",526)
	bool lastSubmerged = false;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",527)
	int i;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",528)
	{
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",528)
		int _g1 = (int)0;
		int _g = this->m_vertexCount;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",528)
		while(((_g1 < _g))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",528)
			int i1 = (_g1)++;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",530)
			depths[i1] = (::box2D::common::math::B2Math_obj::dot(normalL,this->m_vertices->__get(i1)) - offsetL);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",531)
			bool isSubmerged = (depths->__get(i1) < -(2.2250738585072014e-308));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",532)
			if (((i1 > (int)0))){
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",533)
				if ((isSubmerged)){
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",535)
					if ((!(lastSubmerged))){
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",538)
						intoIndex = (i1 - (int)1);
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",539)
						(diveCount)++;
					}
				}
				else{
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",543)
					if ((lastSubmerged)){
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",546)
						outoIndex = (i1 - (int)1);
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",547)
						(diveCount)++;
					}
				}
			}
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",551)
			lastSubmerged = isSubmerged;
		}
	}
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",553)
	switch( (int)(diveCount)){
		case (int)0: {
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",555)
			if ((lastSubmerged)){
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",559)
				::box2D::collision::shapes::B2MassData md = ::box2D::collision::shapes::B2MassData_obj::__new();
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",560)
				this->computeMass(md,(int)1);
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",561)
				c->setV(::box2D::common::math::B2Math_obj::mulX(xf,md->center));
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",562)
				return md->mass;
			}
			else{
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",565)
				return (int)0;
			}
		}
		;break;
		case (int)1: {
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",570)
			if (((intoIndex == (int)-1))){
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",572)
				intoIndex = (this->m_vertexCount - (int)1);
			}
			else{
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",576)
				outoIndex = (this->m_vertexCount - (int)1);
			}
		}
		;break;
	}
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",581)
	int intoIndex2 = hx::Mod(((intoIndex + (int)1)),this->m_vertexCount);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",582)
	int outoIndex2 = hx::Mod(((outoIndex + (int)1)),this->m_vertexCount);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",583)
	double intoLamdda = (double((((int)0 - depths->__get(intoIndex)))) / double(((depths->__get(intoIndex2) - depths->__get(intoIndex)))));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",584)
	double outoLamdda = (double((((int)0 - depths->__get(outoIndex)))) / double(((depths->__get(outoIndex2) - depths->__get(outoIndex)))));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",586)
	::box2D::common::math::B2Vec2 intoVec = ::box2D::common::math::B2Vec2_obj::__new(((this->m_vertices->__get(intoIndex)->x * (((int)1 - intoLamdda))) + (this->m_vertices->__get(intoIndex2)->x * intoLamdda)),((this->m_vertices->__get(intoIndex)->y * (((int)1 - intoLamdda))) + (this->m_vertices->__get(intoIndex2)->y * intoLamdda)));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",588)
	::box2D::common::math::B2Vec2 outoVec = ::box2D::common::math::B2Vec2_obj::__new(((this->m_vertices->__get(outoIndex)->x * (((int)1 - outoLamdda))) + (this->m_vertices->__get(outoIndex2)->x * outoLamdda)),((this->m_vertices->__get(outoIndex)->y * (((int)1 - outoLamdda))) + (this->m_vertices->__get(outoIndex2)->y * outoLamdda)));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",592)
	double area = (int)0;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",593)
	::box2D::common::math::B2Vec2 center = ::box2D::common::math::B2Vec2_obj::__new(null(),null());
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",594)
	::box2D::common::math::B2Vec2 p2 = this->m_vertices->__get(intoIndex2);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",595)
	::box2D::common::math::B2Vec2 p3;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",598)
	i = intoIndex2;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",599)
	while(((i != outoIndex2))){
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",601)
		i = hx::Mod(((i + (int)1)),this->m_vertexCount);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",602)
		if (((i == outoIndex2))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",603)
			p3 = outoVec;
		}
		else{
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",605)
			p3 = this->m_vertices->__get(i);
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",607)
		double triangleArea = (0.5 * (((((p2->x - intoVec->x)) * ((p3->y - intoVec->y))) - (((p2->y - intoVec->y)) * ((p3->x - intoVec->x))))));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",608)
		hx::AddEq(area,triangleArea);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",610)
		hx::AddEq(center->x,(double((triangleArea * (((intoVec->x + p2->x) + p3->x)))) / double((int)3)));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",611)
		hx::AddEq(center->y,(double((triangleArea * (((intoVec->y + p2->y) + p3->y)))) / double((int)3)));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",613)
		p2 = p3;
	}
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",617)
	center->multiply((double((int)1) / double(area)));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",618)
	c->setV(::box2D::common::math::B2Math_obj::mulX(xf,center));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",620)
	return area;
}


HX_DEFINE_DYNAMIC_FUNC4(B2PolygonShape_obj,computeSubmergedArea,return )

int B2PolygonShape_obj::getVertexCount( ){
	HX_SOURCE_PUSH("B2PolygonShape_obj::getVertexCount")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",626)
	return this->m_vertexCount;
}


HX_DEFINE_DYNAMIC_FUNC0(B2PolygonShape_obj,getVertexCount,return )

Array< ::box2D::common::math::B2Vec2 > B2PolygonShape_obj::getVertices( ){
	HX_SOURCE_PUSH("B2PolygonShape_obj::getVertices")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",633)
	return this->m_vertices;
}


HX_DEFINE_DYNAMIC_FUNC0(B2PolygonShape_obj,getVertices,return )

Array< ::box2D::common::math::B2Vec2 > B2PolygonShape_obj::getNormals( ){
	HX_SOURCE_PUSH("B2PolygonShape_obj::getNormals")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",641)
	return this->m_normals;
}


HX_DEFINE_DYNAMIC_FUNC0(B2PolygonShape_obj,getNormals,return )

int B2PolygonShape_obj::getSupport( ::box2D::common::math::B2Vec2 d){
	HX_SOURCE_PUSH("B2PolygonShape_obj::getSupport")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",650)
	int bestIndex = (int)0;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",651)
	double bestValue = ((this->m_vertices->__get((int)0)->x * d->x) + (this->m_vertices->__get((int)0)->y * d->y));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",652)
	{
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",652)
		int _g1 = (int)1;
		int _g = this->m_vertexCount;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",652)
		while(((_g1 < _g))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",652)
			int i = (_g1)++;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",654)
			double value = ((this->m_vertices->__get(i)->x * d->x) + (this->m_vertices->__get(i)->y * d->y));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",655)
			if (((value > bestValue))){
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",657)
				bestIndex = i;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",658)
				bestValue = value;
			}
		}
	}
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",661)
	return bestIndex;
}


HX_DEFINE_DYNAMIC_FUNC1(B2PolygonShape_obj,getSupport,return )

::box2D::common::math::B2Vec2 B2PolygonShape_obj::getSupportVertex( ::box2D::common::math::B2Vec2 d){
	HX_SOURCE_PUSH("B2PolygonShape_obj::getSupportVertex")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",666)
	int bestIndex = (int)0;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",667)
	double bestValue = ((this->m_vertices->__get((int)0)->x * d->x) + (this->m_vertices->__get((int)0)->y * d->y));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",668)
	{
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",668)
		int _g1 = (int)1;
		int _g = this->m_vertexCount;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",668)
		while(((_g1 < _g))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",668)
			int i = (_g1)++;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",670)
			double value = ((this->m_vertices->__get(i)->x * d->x) + (this->m_vertices->__get(i)->y * d->y));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",671)
			if (((value > bestValue))){
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",673)
				bestIndex = i;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",674)
				bestValue = value;
			}
		}
	}
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",677)
	return this->m_vertices->__get(bestIndex);
}


HX_DEFINE_DYNAMIC_FUNC1(B2PolygonShape_obj,getSupportVertex,return )

bool B2PolygonShape_obj::validate( ){
	HX_SOURCE_PUSH("B2PolygonShape_obj::validate")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",682)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC0(B2PolygonShape_obj,validate,return )

Void B2PolygonShape_obj::reserve( int count){
{
		HX_SOURCE_PUSH("B2PolygonShape_obj::reserve")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",737)
		int _g = this->m_vertices->length;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",737)
		while(((_g < count))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",737)
			int i = (_g)++;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",739)
			this->m_vertices[i] = ::box2D::common::math::B2Vec2_obj::__new(null(),null());
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",740)
			this->m_normals[i] = ::box2D::common::math::B2Vec2_obj::__new(null(),null());
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2PolygonShape_obj,reserve,(void))

::box2D::collision::shapes::B2PolygonShape B2PolygonShape_obj::asArray( Dynamic vertices,double vertexCount){
	HX_SOURCE_PUSH("B2PolygonShape_obj::asArray")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",81)
	::box2D::collision::shapes::B2PolygonShape polygonShape = ::box2D::collision::shapes::B2PolygonShape_obj::__new();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",82)
	polygonShape->setAsArray(vertices,vertexCount);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",83)
	return polygonShape;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(B2PolygonShape_obj,asArray,return )

::box2D::collision::shapes::B2PolygonShape B2PolygonShape_obj::asVector( Array< ::box2D::common::math::B2Vec2 > vertices,double vertexCount){
	HX_SOURCE_PUSH("B2PolygonShape_obj::asVector")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",125)
	::box2D::collision::shapes::B2PolygonShape polygonShape = ::box2D::collision::shapes::B2PolygonShape_obj::__new();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",126)
	polygonShape->setAsVector(vertices,vertexCount);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",127)
	return polygonShape;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(B2PolygonShape_obj,asVector,return )

::box2D::collision::shapes::B2PolygonShape B2PolygonShape_obj::asBox( double hx,double hy){
	HX_SOURCE_PUSH("B2PolygonShape_obj::asBox")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",152)
	::box2D::collision::shapes::B2PolygonShape polygonShape = ::box2D::collision::shapes::B2PolygonShape_obj::__new();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",153)
	polygonShape->setAsBox(hx,hy);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",154)
	return polygonShape;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(B2PolygonShape_obj,asBox,return )

::box2D::common::math::B2Mat22 B2PolygonShape_obj::s_mat;

::box2D::collision::shapes::B2PolygonShape B2PolygonShape_obj::asOrientedBox( double hx,double hy,::box2D::common::math::B2Vec2 center,Dynamic __o_angle){
double angle = __o_angle.Default(0.0);
	HX_SOURCE_PUSH("B2PolygonShape_obj::asOrientedBox");
{
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",193)
		::box2D::collision::shapes::B2PolygonShape polygonShape = ::box2D::collision::shapes::B2PolygonShape_obj::__new();
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",194)
		polygonShape->setAsOrientedBox(hx,hy,center,angle);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",195)
		return polygonShape;
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(B2PolygonShape_obj,asOrientedBox,return )

::box2D::collision::shapes::B2PolygonShape B2PolygonShape_obj::asEdge( ::box2D::common::math::B2Vec2 v1,::box2D::common::math::B2Vec2 v2){
	HX_SOURCE_PUSH("B2PolygonShape_obj::asEdge")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",220)
	::box2D::collision::shapes::B2PolygonShape polygonShape = ::box2D::collision::shapes::B2PolygonShape_obj::__new();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",221)
	polygonShape->setAsEdge(v1,v2);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",222)
	return polygonShape;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(B2PolygonShape_obj,asEdge,return )

::box2D::common::math::B2Vec2 B2PolygonShape_obj::computeCentroid( Array< ::box2D::common::math::B2Vec2 > vs,int count){
	HX_SOURCE_PUSH("B2PolygonShape_obj::computeCentroid")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",765)
	::box2D::common::math::B2Vec2 c = ::box2D::common::math::B2Vec2_obj::__new(null(),null());
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",766)
	double area = 0.0;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",771)
	double p1X = 0.0;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",772)
	double p1Y = 0.0;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",774)
	double inv3 = (double(1.0) / double(3.0));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",776)
	{
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",776)
		int _g = (int)0;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",776)
		while(((_g < count))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",776)
			int i = (_g)++;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",782)
			::box2D::common::math::B2Vec2 p2 = vs->__get(i);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",784)
			::box2D::common::math::B2Vec2 p3 = (  ((((i + (int)1) < count))) ? ::box2D::common::math::B2Vec2(vs->__get(::Std_obj::_int((i + (int)1)))) : ::box2D::common::math::B2Vec2(vs->__get((int)0)) );
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",787)
			double e1X = (p2->x - p1X);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",788)
			double e1Y = (p2->y - p1Y);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",790)
			double e2X = (p3->x - p1X);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",791)
			double e2Y = (p3->y - p1Y);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",794)
			double D = ((e1X * e2Y) - (e1Y * e2X));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",797)
			double triangleArea = (0.5 * D);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",798)
			hx::AddEq(area,triangleArea);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",802)
			hx::AddEq(c->x,((triangleArea * inv3) * (((p1X + p2->x) + p3->x))));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",803)
			hx::AddEq(c->y,((triangleArea * inv3) * (((p1Y + p2->y) + p3->y))));
		}
	}
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",809)
	hx::MultEq(c->x,(double(1.0) / double(area)));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",810)
	hx::MultEq(c->y,(double(1.0) / double(area)));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",811)
	return c;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(B2PolygonShape_obj,computeCentroid,return )

Void B2PolygonShape_obj::computeOBB( ::box2D::collision::B2OBB obb,Array< ::box2D::common::math::B2Vec2 > vs,int count){
{
		HX_SOURCE_PUSH("B2PolygonShape_obj::computeOBB")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",820)
		int i;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",821)
		Array< ::box2D::common::math::B2Vec2 > p = Array_obj< ::box2D::common::math::B2Vec2 >::__new();
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",822)
		{
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",822)
			int _g = (int)0;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",822)
			while(((_g < count))){
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",822)
				int i1 = (_g)++;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",824)
				p[i1] = vs->__get(i1);
			}
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",826)
		p[count] = p->__get((int)0);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",828)
		double minArea = 1.7976931348623158e+308;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",830)
		{
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",830)
			int _g1 = (int)1;
			int _g = (count + (int)1);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",830)
			while(((_g1 < _g))){
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",830)
				int i1 = (_g1)++;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",832)
				::box2D::common::math::B2Vec2 root = p->__get(::Std_obj::_int((i1 - (int)1)));
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",834)
				double uxX = (p->__get(i1)->x - root->x);
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",835)
				double uxY = (p->__get(i1)->y - root->y);
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",837)
				double length = ::Math_obj::sqrt(((uxX * uxX) + (uxY * uxY)));
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",838)
				hx::DivEq(uxX,length);
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",839)
				hx::DivEq(uxY,length);
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",842)
				double uyX = -(uxY);
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",843)
				double uyY = uxX;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",845)
				double lowerX = 1.7976931348623158e+308;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",846)
				double lowerY = 1.7976931348623158e+308;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",848)
				double upperX = -(1.7976931348623158e+308);
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",849)
				double upperY = -(1.7976931348623158e+308);
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",851)
				{
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",851)
					int _g2 = (int)0;
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",851)
					while(((_g2 < count))){
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",851)
						int j = (_g2)++;
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",854)
						double dX = (p->__get(j)->x - root->x);
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",855)
						double dY = (p->__get(j)->y - root->y);
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",858)
						double rX = ((uxX * dX) + (uxY * dY));
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",860)
						double rY = ((uyX * dX) + (uyY * dY));
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",862)
						if (((rX < lowerX))){
							HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",862)
							lowerX = rX;
						}
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",863)
						if (((rY < lowerY))){
							HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",863)
							lowerY = rY;
						}
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",865)
						if (((rX > upperX))){
							HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",865)
							upperX = rX;
						}
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",866)
						if (((rY > upperY))){
							HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",866)
							upperY = rY;
						}
					}
				}
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",869)
				double area = (((upperX - lowerX)) * ((upperY - lowerY)));
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",870)
				if (((area < (0.95 * minArea)))){
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",872)
					minArea = area;
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",874)
					obb->R->col1->x = uxX;
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",875)
					obb->R->col1->y = uxY;
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",877)
					obb->R->col2->x = uyX;
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",878)
					obb->R->col2->y = uyY;
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",880)
					double centerX = (0.5 * ((lowerX + upperX)));
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",881)
					double centerY = (0.5 * ((lowerY + upperY)));
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",883)
					::box2D::common::math::B2Mat22 tMat = obb->R;
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",884)
					obb->center->x = (root->x + (((tMat->col1->x * centerX) + (tMat->col2->x * centerY))));
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",885)
					obb->center->y = (root->y + (((tMat->col1->y * centerX) + (tMat->col2->y * centerY))));
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",887)
					obb->extents->x = (0.5 * ((upperX - lowerX)));
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/shapes/B2PolygonShape.hx",888)
					obb->extents->y = (0.5 * ((upperY - lowerY)));
				}
			}
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(B2PolygonShape_obj,computeOBB,(void))


B2PolygonShape_obj::B2PolygonShape_obj()
{
}

void B2PolygonShape_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(B2PolygonShape);
	HX_MARK_MEMBER_NAME(m_centroid,"m_centroid");
	HX_MARK_MEMBER_NAME(m_vertices,"m_vertices");
	HX_MARK_MEMBER_NAME(m_normals,"m_normals");
	HX_MARK_MEMBER_NAME(m_vertexCount,"m_vertexCount");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic B2PolygonShape_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"set") ) { return set_dyn(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"copy") ) { return copy_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"asBox") ) { return asBox_dyn(); }
		if (HX_FIELD_EQ(inName,"s_mat") ) { return s_mat; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"asEdge") ) { return asEdge_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"asArray") ) { return asArray_dyn(); }
		if (HX_FIELD_EQ(inName,"rayCast") ) { return rayCast_dyn(); }
		if (HX_FIELD_EQ(inName,"reserve") ) { return reserve_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"asVector") ) { return asVector_dyn(); }
		if (HX_FIELD_EQ(inName,"setAsBox") ) { return setAsBox_dyn(); }
		if (HX_FIELD_EQ(inName,"validate") ) { return validate_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"setAsEdge") ) { return setAsEdge_dyn(); }
		if (HX_FIELD_EQ(inName,"testPoint") ) { return testPoint_dyn(); }
		if (HX_FIELD_EQ(inName,"m_normals") ) { return m_normals; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"computeOBB") ) { return computeOBB_dyn(); }
		if (HX_FIELD_EQ(inName,"setAsArray") ) { return setAsArray_dyn(); }
		if (HX_FIELD_EQ(inName,"getNormals") ) { return getNormals_dyn(); }
		if (HX_FIELD_EQ(inName,"getSupport") ) { return getSupport_dyn(); }
		if (HX_FIELD_EQ(inName,"m_centroid") ) { return m_centroid; }
		if (HX_FIELD_EQ(inName,"m_vertices") ) { return m_vertices; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"setAsVector") ) { return setAsVector_dyn(); }
		if (HX_FIELD_EQ(inName,"computeAABB") ) { return computeAABB_dyn(); }
		if (HX_FIELD_EQ(inName,"computeMass") ) { return computeMass_dyn(); }
		if (HX_FIELD_EQ(inName,"getVertices") ) { return getVertices_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"asOrientedBox") ) { return asOrientedBox_dyn(); }
		if (HX_FIELD_EQ(inName,"m_vertexCount") ) { return m_vertexCount; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"getVertexCount") ) { return getVertexCount_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"computeCentroid") ) { return computeCentroid_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"setAsOrientedBox") ) { return setAsOrientedBox_dyn(); }
		if (HX_FIELD_EQ(inName,"getSupportVertex") ) { return getSupportVertex_dyn(); }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"computeSubmergedArea") ) { return computeSubmergedArea_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic B2PolygonShape_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"s_mat") ) { s_mat=inValue.Cast< ::box2D::common::math::B2Mat22 >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"m_normals") ) { m_normals=inValue.Cast< Array< ::box2D::common::math::B2Vec2 > >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"m_centroid") ) { m_centroid=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_vertices") ) { m_vertices=inValue.Cast< Array< ::box2D::common::math::B2Vec2 > >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"m_vertexCount") ) { m_vertexCount=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void B2PolygonShape_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("m_centroid"));
	outFields->push(HX_CSTRING("m_vertices"));
	outFields->push(HX_CSTRING("m_normals"));
	outFields->push(HX_CSTRING("m_vertexCount"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("asArray"),
	HX_CSTRING("asVector"),
	HX_CSTRING("asBox"),
	HX_CSTRING("s_mat"),
	HX_CSTRING("asOrientedBox"),
	HX_CSTRING("asEdge"),
	HX_CSTRING("computeCentroid"),
	HX_CSTRING("computeOBB"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("copy"),
	HX_CSTRING("set"),
	HX_CSTRING("setAsArray"),
	HX_CSTRING("setAsVector"),
	HX_CSTRING("setAsBox"),
	HX_CSTRING("setAsOrientedBox"),
	HX_CSTRING("setAsEdge"),
	HX_CSTRING("testPoint"),
	HX_CSTRING("rayCast"),
	HX_CSTRING("computeAABB"),
	HX_CSTRING("computeMass"),
	HX_CSTRING("computeSubmergedArea"),
	HX_CSTRING("getVertexCount"),
	HX_CSTRING("getVertices"),
	HX_CSTRING("getNormals"),
	HX_CSTRING("getSupport"),
	HX_CSTRING("getSupportVertex"),
	HX_CSTRING("validate"),
	HX_CSTRING("reserve"),
	HX_CSTRING("m_centroid"),
	HX_CSTRING("m_vertices"),
	HX_CSTRING("m_normals"),
	HX_CSTRING("m_vertexCount"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(B2PolygonShape_obj::s_mat,"s_mat");
};

Class B2PolygonShape_obj::__mClass;

void B2PolygonShape_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.collision.shapes.B2PolygonShape"), hx::TCanCast< B2PolygonShape_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void B2PolygonShape_obj::__boot()
{
	hx::Static(s_mat) = ::box2D::common::math::B2Mat22_obj::__new();
}

} // end namespace box2D
} // end namespace collision
} // end namespace shapes
