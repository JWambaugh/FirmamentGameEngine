#include <hxcpp.h>

#ifndef INCLUDED_box2D_collision_B2DistanceProxy
#include <box2D/collision/B2DistanceProxy.h>
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
#ifndef INCLUDED_box2D_common_math_B2Vec2
#include <box2D/common/math/B2Vec2.h>
#endif
namespace box2D{
namespace collision{

Void B2DistanceProxy_obj::__construct()
{
{
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DistanceProxy.hx",120)
	this->m_vertices = Array_obj< ::box2D::common::math::B2Vec2 >::__new();
}
;
	return null();
}

B2DistanceProxy_obj::~B2DistanceProxy_obj() { }

Dynamic B2DistanceProxy_obj::__CreateEmpty() { return  new B2DistanceProxy_obj; }
hx::ObjectPtr< B2DistanceProxy_obj > B2DistanceProxy_obj::__new()
{  hx::ObjectPtr< B2DistanceProxy_obj > result = new B2DistanceProxy_obj();
	result->__construct();
	return result;}

Dynamic B2DistanceProxy_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2DistanceProxy_obj > result = new B2DistanceProxy_obj();
	result->__construct();
	return result;}

Void B2DistanceProxy_obj::set( ::box2D::collision::shapes::B2Shape shape){
{
		HX_SOURCE_PUSH("B2DistanceProxy_obj::set")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DistanceProxy.hx",40)
		int _switch_1 = (shape->getType());
		if (  ( _switch_1==::box2D::collision::shapes::B2Shape_obj::e_circleShape)){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DistanceProxy.hx",45)
			::box2D::collision::shapes::B2CircleShape circle = hx::TCast< box2D::collision::shapes::B2CircleShape >::cast(shape);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DistanceProxy.hx",46)
			this->m_vertices = Array_obj< ::box2D::common::math::B2Vec2 >::__new();
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DistanceProxy.hx",47)
			this->m_vertices[(int)0] = circle->m_p;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DistanceProxy.hx",48)
			this->m_count = (int)1;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DistanceProxy.hx",49)
			this->m_radius = circle->m_radius;
		}
		else if (  ( _switch_1==::box2D::collision::shapes::B2Shape_obj::e_polygonShape)){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DistanceProxy.hx",54)
			::box2D::collision::shapes::B2PolygonShape polygon = hx::TCast< box2D::collision::shapes::B2PolygonShape >::cast(shape);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DistanceProxy.hx",55)
			this->m_vertices = polygon->m_vertices;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DistanceProxy.hx",56)
			this->m_count = polygon->m_vertexCount;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DistanceProxy.hx",57)
			this->m_radius = polygon->m_radius;
		}
		else  {
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DistanceProxy.hx",60)
			::box2D::common::B2Settings_obj::b2Assert(false);
		}
;
;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2DistanceProxy_obj,set,(void))

double B2DistanceProxy_obj::getSupport( ::box2D::common::math::B2Vec2 d){
	HX_SOURCE_PUSH("B2DistanceProxy_obj::getSupport")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DistanceProxy.hx",70)
	int bestIndex = (int)0;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DistanceProxy.hx",71)
	double bestValue = ((this->m_vertices->__get((int)0)->x * d->x) + (this->m_vertices->__get((int)0)->y * d->y));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DistanceProxy.hx",72)
	{
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DistanceProxy.hx",72)
		int _g1 = (int)1;
		int _g = this->m_count;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DistanceProxy.hx",72)
		while(((_g1 < _g))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DistanceProxy.hx",72)
			int i = (_g1)++;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DistanceProxy.hx",74)
			double value = ((this->m_vertices->__get(i)->x * d->x) + (this->m_vertices->__get(i)->y * d->y));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DistanceProxy.hx",75)
			if (((value > bestValue))){
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DistanceProxy.hx",77)
				bestIndex = i;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DistanceProxy.hx",78)
				bestValue = value;
			}
		}
	}
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DistanceProxy.hx",81)
	return bestIndex;
}


HX_DEFINE_DYNAMIC_FUNC1(B2DistanceProxy_obj,getSupport,return )

::box2D::common::math::B2Vec2 B2DistanceProxy_obj::getSupportVertex( ::box2D::common::math::B2Vec2 d){
	HX_SOURCE_PUSH("B2DistanceProxy_obj::getSupportVertex")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DistanceProxy.hx",89)
	int bestIndex = (int)0;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DistanceProxy.hx",90)
	double bestValue = ((this->m_vertices->__get((int)0)->x * d->x) + (this->m_vertices->__get((int)0)->y * d->y));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DistanceProxy.hx",91)
	{
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DistanceProxy.hx",91)
		int _g1 = (int)1;
		int _g = this->m_count;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DistanceProxy.hx",91)
		while(((_g1 < _g))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DistanceProxy.hx",91)
			int i = (_g1)++;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DistanceProxy.hx",93)
			double value = ((this->m_vertices->__get(i)->x * d->x) + (this->m_vertices->__get(i)->y * d->y));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DistanceProxy.hx",94)
			if (((value > bestValue))){
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DistanceProxy.hx",96)
				bestIndex = i;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DistanceProxy.hx",97)
				bestValue = value;
			}
		}
	}
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DistanceProxy.hx",100)
	return this->m_vertices->__get(bestIndex);
}


HX_DEFINE_DYNAMIC_FUNC1(B2DistanceProxy_obj,getSupportVertex,return )

int B2DistanceProxy_obj::getVertexCount( ){
	HX_SOURCE_PUSH("B2DistanceProxy_obj::getVertexCount")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DistanceProxy.hx",106)
	return this->m_count;
}


HX_DEFINE_DYNAMIC_FUNC0(B2DistanceProxy_obj,getVertexCount,return )

::box2D::common::math::B2Vec2 B2DistanceProxy_obj::getVertex( int index){
	HX_SOURCE_PUSH("B2DistanceProxy_obj::getVertex")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DistanceProxy.hx",115)
	::box2D::common::B2Settings_obj::b2Assert((bool(((int)0 <= index)) && bool((index < this->m_count))));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DistanceProxy.hx",116)
	return this->m_vertices->__get(index);
}


HX_DEFINE_DYNAMIC_FUNC1(B2DistanceProxy_obj,getVertex,return )


B2DistanceProxy_obj::B2DistanceProxy_obj()
{
}

void B2DistanceProxy_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(B2DistanceProxy);
	HX_MARK_MEMBER_NAME(m_vertices,"m_vertices");
	HX_MARK_MEMBER_NAME(m_count,"m_count");
	HX_MARK_MEMBER_NAME(m_radius,"m_radius");
	HX_MARK_END_CLASS();
}

Dynamic B2DistanceProxy_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"set") ) { return set_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"m_count") ) { return m_count; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"m_radius") ) { return m_radius; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"getVertex") ) { return getVertex_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"getSupport") ) { return getSupport_dyn(); }
		if (HX_FIELD_EQ(inName,"m_vertices") ) { return m_vertices; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"getVertexCount") ) { return getVertexCount_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"getSupportVertex") ) { return getSupportVertex_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic B2DistanceProxy_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"m_count") ) { m_count=inValue.Cast< int >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"m_radius") ) { m_radius=inValue.Cast< double >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"m_vertices") ) { m_vertices=inValue.Cast< Array< ::box2D::common::math::B2Vec2 > >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void B2DistanceProxy_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("m_vertices"));
	outFields->push(HX_CSTRING("m_count"));
	outFields->push(HX_CSTRING("m_radius"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("set"),
	HX_CSTRING("getSupport"),
	HX_CSTRING("getSupportVertex"),
	HX_CSTRING("getVertexCount"),
	HX_CSTRING("getVertex"),
	HX_CSTRING("m_vertices"),
	HX_CSTRING("m_count"),
	HX_CSTRING("m_radius"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class B2DistanceProxy_obj::__mClass;

void B2DistanceProxy_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.collision.B2DistanceProxy"), hx::TCanCast< B2DistanceProxy_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void B2DistanceProxy_obj::__boot()
{
}

} // end namespace box2D
} // end namespace collision
