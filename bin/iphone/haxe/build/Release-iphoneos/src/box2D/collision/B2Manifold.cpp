#include <hxcpp.h>

#ifndef INCLUDED_box2D_collision_B2Manifold
#include <box2D/collision/B2Manifold.h>
#endif
#ifndef INCLUDED_box2D_collision_B2ManifoldPoint
#include <box2D/collision/B2ManifoldPoint.h>
#endif
#ifndef INCLUDED_box2D_common_B2Settings
#include <box2D/common/B2Settings.h>
#endif
#ifndef INCLUDED_box2D_common_math_B2Vec2
#include <box2D/common/math/B2Vec2.h>
#endif
namespace box2D{
namespace collision{

Void B2Manifold_obj::__construct()
{
{
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Manifold.hx",47)
	this->m_pointCount = (int)0;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Manifold.hx",48)
	this->m_points = Array_obj< ::box2D::collision::B2ManifoldPoint >::__new();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Manifold.hx",49)
	{
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Manifold.hx",49)
		int _g1 = (int)0;
		int _g = ::box2D::common::B2Settings_obj::b2_maxManifoldPoints;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Manifold.hx",49)
		while(((_g1 < _g))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Manifold.hx",49)
			int i = (_g1)++;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Manifold.hx",50)
			this->m_points[i] = ::box2D::collision::B2ManifoldPoint_obj::__new();
		}
	}
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Manifold.hx",52)
	this->m_localPlaneNormal = ::box2D::common::math::B2Vec2_obj::__new(null(),null());
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Manifold.hx",53)
	this->m_localPoint = ::box2D::common::math::B2Vec2_obj::__new(null(),null());
}
;
	return null();
}

B2Manifold_obj::~B2Manifold_obj() { }

Dynamic B2Manifold_obj::__CreateEmpty() { return  new B2Manifold_obj; }
hx::ObjectPtr< B2Manifold_obj > B2Manifold_obj::__new()
{  hx::ObjectPtr< B2Manifold_obj > result = new B2Manifold_obj();
	result->__construct();
	return result;}

Dynamic B2Manifold_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2Manifold_obj > result = new B2Manifold_obj();
	result->__construct();
	return result;}

Void B2Manifold_obj::reset( ){
{
		HX_SOURCE_PUSH("B2Manifold_obj::reset")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Manifold.hx",56)
		{
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Manifold.hx",56)
			int _g1 = (int)0;
			int _g = ::box2D::common::B2Settings_obj::b2_maxManifoldPoints;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Manifold.hx",56)
			while(((_g1 < _g))){
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Manifold.hx",56)
				int i = (_g1)++;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Manifold.hx",57)
				this->m_points->__get(i)->reset();
			}
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Manifold.hx",59)
		this->m_localPlaneNormal->setZero();
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Manifold.hx",60)
		this->m_localPoint->setZero();
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Manifold.hx",61)
		this->m_type = (int)0;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Manifold.hx",62)
		this->m_pointCount = (int)0;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(B2Manifold_obj,reset,(void))

Void B2Manifold_obj::set( ::box2D::collision::B2Manifold m){
{
		HX_SOURCE_PUSH("B2Manifold_obj::set")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Manifold.hx",65)
		this->m_pointCount = m->m_pointCount;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Manifold.hx",66)
		{
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Manifold.hx",66)
			int _g1 = (int)0;
			int _g = ::box2D::common::B2Settings_obj::b2_maxManifoldPoints;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Manifold.hx",66)
			while(((_g1 < _g))){
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Manifold.hx",66)
				int i = (_g1)++;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Manifold.hx",67)
				this->m_points->__get(i)->set(m->m_points->__get(i));
			}
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Manifold.hx",69)
		this->m_localPlaneNormal->setV(m->m_localPlaneNormal);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Manifold.hx",70)
		this->m_localPoint->setV(m->m_localPoint);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Manifold.hx",71)
		this->m_type = m->m_type;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2Manifold_obj,set,(void))

::box2D::collision::B2Manifold B2Manifold_obj::copy( ){
	HX_SOURCE_PUSH("B2Manifold_obj::copy")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Manifold.hx",75)
	::box2D::collision::B2Manifold copy = ::box2D::collision::B2Manifold_obj::__new();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Manifold.hx",76)
	copy->set(hx::ObjectPtr<OBJ_>(this));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2Manifold.hx",77)
	return copy;
}


HX_DEFINE_DYNAMIC_FUNC0(B2Manifold_obj,copy,return )

int B2Manifold_obj::e_circles;

int B2Manifold_obj::e_faceA;

int B2Manifold_obj::e_faceB;


B2Manifold_obj::B2Manifold_obj()
{
}

void B2Manifold_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(B2Manifold);
	HX_MARK_MEMBER_NAME(m_points,"m_points");
	HX_MARK_MEMBER_NAME(m_localPlaneNormal,"m_localPlaneNormal");
	HX_MARK_MEMBER_NAME(m_localPoint,"m_localPoint");
	HX_MARK_MEMBER_NAME(m_type,"m_type");
	HX_MARK_MEMBER_NAME(m_pointCount,"m_pointCount");
	HX_MARK_END_CLASS();
}

Dynamic B2Manifold_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"set") ) { return set_dyn(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"copy") ) { return copy_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"reset") ) { return reset_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"m_type") ) { return m_type; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"e_faceA") ) { return e_faceA; }
		if (HX_FIELD_EQ(inName,"e_faceB") ) { return e_faceB; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"m_points") ) { return m_points; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"e_circles") ) { return e_circles; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"m_localPoint") ) { return m_localPoint; }
		if (HX_FIELD_EQ(inName,"m_pointCount") ) { return m_pointCount; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"m_localPlaneNormal") ) { return m_localPlaneNormal; }
	}
	return super::__Field(inName);
}

Dynamic B2Manifold_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"m_type") ) { m_type=inValue.Cast< int >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"e_faceA") ) { e_faceA=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"e_faceB") ) { e_faceB=inValue.Cast< int >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"m_points") ) { m_points=inValue.Cast< Array< ::box2D::collision::B2ManifoldPoint > >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"e_circles") ) { e_circles=inValue.Cast< int >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"m_localPoint") ) { m_localPoint=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_pointCount") ) { m_pointCount=inValue.Cast< int >(); return inValue; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"m_localPlaneNormal") ) { m_localPlaneNormal=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void B2Manifold_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("m_points"));
	outFields->push(HX_CSTRING("m_localPlaneNormal"));
	outFields->push(HX_CSTRING("m_localPoint"));
	outFields->push(HX_CSTRING("m_type"));
	outFields->push(HX_CSTRING("m_pointCount"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("e_circles"),
	HX_CSTRING("e_faceA"),
	HX_CSTRING("e_faceB"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("reset"),
	HX_CSTRING("set"),
	HX_CSTRING("copy"),
	HX_CSTRING("m_points"),
	HX_CSTRING("m_localPlaneNormal"),
	HX_CSTRING("m_localPoint"),
	HX_CSTRING("m_type"),
	HX_CSTRING("m_pointCount"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(B2Manifold_obj::e_circles,"e_circles");
	HX_MARK_MEMBER_NAME(B2Manifold_obj::e_faceA,"e_faceA");
	HX_MARK_MEMBER_NAME(B2Manifold_obj::e_faceB,"e_faceB");
};

Class B2Manifold_obj::__mClass;

void B2Manifold_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.collision.B2Manifold"), hx::TCanCast< B2Manifold_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void B2Manifold_obj::__boot()
{
	hx::Static(e_circles) = (int)1;
	hx::Static(e_faceA) = (int)2;
	hx::Static(e_faceB) = (int)4;
}

} // end namespace box2D
} // end namespace collision
