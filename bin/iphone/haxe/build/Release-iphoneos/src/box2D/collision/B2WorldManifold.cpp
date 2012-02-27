#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_box2D_collision_B2Manifold
#include <box2D/collision/B2Manifold.h>
#endif
#ifndef INCLUDED_box2D_collision_B2ManifoldPoint
#include <box2D/collision/B2ManifoldPoint.h>
#endif
#ifndef INCLUDED_box2D_collision_B2WorldManifold
#include <box2D/collision/B2WorldManifold.h>
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

Void B2WorldManifold_obj::__construct()
{
{
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2WorldManifold.hx",36)
	this->m_normal = ::box2D::common::math::B2Vec2_obj::__new(null(),null());
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2WorldManifold.hx",38)
	this->m_points = Array_obj< ::box2D::common::math::B2Vec2 >::__new();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2WorldManifold.hx",39)
	{
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2WorldManifold.hx",39)
		int _g1 = (int)0;
		int _g = ::box2D::common::B2Settings_obj::b2_maxManifoldPoints;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2WorldManifold.hx",39)
		while(((_g1 < _g))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2WorldManifold.hx",39)
			int i = (_g1)++;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2WorldManifold.hx",41)
			this->m_points[i] = ::box2D::common::math::B2Vec2_obj::__new(null(),null());
		}
	}
}
;
	return null();
}

B2WorldManifold_obj::~B2WorldManifold_obj() { }

Dynamic B2WorldManifold_obj::__CreateEmpty() { return  new B2WorldManifold_obj; }
hx::ObjectPtr< B2WorldManifold_obj > B2WorldManifold_obj::__new()
{  hx::ObjectPtr< B2WorldManifold_obj > result = new B2WorldManifold_obj();
	result->__construct();
	return result;}

Dynamic B2WorldManifold_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2WorldManifold_obj > result = new B2WorldManifold_obj();
	result->__construct();
	return result;}

Void B2WorldManifold_obj::initialize( ::box2D::collision::B2Manifold manifold,::box2D::common::math::B2Transform xfA,double radiusA,::box2D::common::math::B2Transform xfB,double radiusB){
{
		HX_SOURCE_PUSH("B2WorldManifold_obj::initialize")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2WorldManifold.hx",54)
		if (((manifold->m_pointCount == (int)0))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2WorldManifold.hx",55)
			return null();
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2WorldManifold.hx",59)
		int i;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2WorldManifold.hx",60)
		::box2D::common::math::B2Vec2 tVec;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2WorldManifold.hx",61)
		::box2D::common::math::B2Mat22 tMat;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2WorldManifold.hx",62)
		double normalX;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2WorldManifold.hx",63)
		double normalY;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2WorldManifold.hx",64)
		double planePointX;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2WorldManifold.hx",65)
		double planePointY;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2WorldManifold.hx",66)
		double clipPointX;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2WorldManifold.hx",67)
		double clipPointY;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2WorldManifold.hx",69)
		int _switch_1 = (manifold->m_type);
		if (  ( _switch_1==::box2D::collision::B2Manifold_obj::e_circles)){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2WorldManifold.hx",74)
			tMat = xfA->R;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2WorldManifold.hx",75)
			tVec = manifold->m_localPoint;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2WorldManifold.hx",76)
			double pointAX = ((xfA->position->x + (tMat->col1->x * tVec->x)) + (tMat->col2->x * tVec->y));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2WorldManifold.hx",77)
			double pointAY = ((xfA->position->y + (tMat->col1->y * tVec->x)) + (tMat->col2->y * tVec->y));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2WorldManifold.hx",79)
			tMat = xfB->R;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2WorldManifold.hx",80)
			tVec = manifold->m_points->__get((int)0)->m_localPoint;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2WorldManifold.hx",81)
			double pointBX = ((xfB->position->x + (tMat->col1->x * tVec->x)) + (tMat->col2->x * tVec->y));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2WorldManifold.hx",82)
			double pointBY = ((xfB->position->y + (tMat->col1->y * tVec->x)) + (tMat->col2->y * tVec->y));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2WorldManifold.hx",84)
			double dX = (pointBX - pointAX);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2WorldManifold.hx",85)
			double dY = (pointBY - pointAY);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2WorldManifold.hx",86)
			double d2 = ((dX * dX) + (dY * dY));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2WorldManifold.hx",87)
			if (((d2 > 0.))){
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2WorldManifold.hx",89)
				double d = ::Math_obj::sqrt(d2);
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2WorldManifold.hx",90)
				this->m_normal->x = (double(dX) / double(d));
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2WorldManifold.hx",91)
				this->m_normal->y = (double(dY) / double(d));
			}
			else{
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2WorldManifold.hx",93)
				this->m_normal->x = (int)1;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2WorldManifold.hx",94)
				this->m_normal->y = (int)0;
			}
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2WorldManifold.hx",98)
			double cAX = (pointAX + (radiusA * this->m_normal->x));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2WorldManifold.hx",99)
			double cAY = (pointAY + (radiusA * this->m_normal->y));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2WorldManifold.hx",101)
			double cBX = (pointBX - (radiusB * this->m_normal->x));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2WorldManifold.hx",102)
			double cBY = (pointBY - (radiusB * this->m_normal->y));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2WorldManifold.hx",103)
			this->m_points->__get((int)0)->x = (0.5 * ((cAX + cBX)));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2WorldManifold.hx",104)
			this->m_points->__get((int)0)->y = (0.5 * ((cAY + cBY)));
		}
		else if (  ( _switch_1==::box2D::collision::B2Manifold_obj::e_faceA)){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2WorldManifold.hx",110)
			tMat = xfA->R;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2WorldManifold.hx",111)
			tVec = manifold->m_localPlaneNormal;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2WorldManifold.hx",112)
			normalX = ((tMat->col1->x * tVec->x) + (tMat->col2->x * tVec->y));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2WorldManifold.hx",113)
			normalY = ((tMat->col1->y * tVec->x) + (tMat->col2->y * tVec->y));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2WorldManifold.hx",116)
			tMat = xfA->R;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2WorldManifold.hx",117)
			tVec = manifold->m_localPoint;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2WorldManifold.hx",118)
			planePointX = ((xfA->position->x + (tMat->col1->x * tVec->x)) + (tMat->col2->x * tVec->y));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2WorldManifold.hx",119)
			planePointY = ((xfA->position->y + (tMat->col1->y * tVec->x)) + (tMat->col2->y * tVec->y));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2WorldManifold.hx",122)
			this->m_normal->x = normalX;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2WorldManifold.hx",123)
			this->m_normal->y = normalY;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2WorldManifold.hx",124)
			{
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2WorldManifold.hx",124)
				int _g1 = (int)0;
				int _g = manifold->m_pointCount;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2WorldManifold.hx",124)
				while(((_g1 < _g))){
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2WorldManifold.hx",124)
					int i1 = (_g1)++;
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2WorldManifold.hx",127)
					tMat = xfB->R;
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2WorldManifold.hx",128)
					tVec = manifold->m_points->__get(i1)->m_localPoint;
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2WorldManifold.hx",129)
					clipPointX = ((xfB->position->x + (tMat->col1->x * tVec->x)) + (tMat->col2->x * tVec->y));
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2WorldManifold.hx",130)
					clipPointY = ((xfB->position->y + (tMat->col1->y * tVec->x)) + (tMat->col2->y * tVec->y));
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2WorldManifold.hx",135)
					this->m_points->__get(i1)->x = (clipPointX + ((0.5 * ((((radiusA - (((clipPointX - planePointX)) * normalX)) - (((clipPointY - planePointY)) * normalY)) - radiusB))) * normalX));
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2WorldManifold.hx",136)
					this->m_points->__get(i1)->y = (clipPointY + ((0.5 * ((((radiusA - (((clipPointX - planePointX)) * normalX)) - (((clipPointY - planePointY)) * normalY)) - radiusB))) * normalY));
				}
			}
		}
		else if (  ( _switch_1==::box2D::collision::B2Manifold_obj::e_faceB)){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2WorldManifold.hx",144)
			tMat = xfB->R;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2WorldManifold.hx",145)
			tVec = manifold->m_localPlaneNormal;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2WorldManifold.hx",146)
			normalX = ((tMat->col1->x * tVec->x) + (tMat->col2->x * tVec->y));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2WorldManifold.hx",147)
			normalY = ((tMat->col1->y * tVec->x) + (tMat->col2->y * tVec->y));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2WorldManifold.hx",150)
			tMat = xfB->R;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2WorldManifold.hx",151)
			tVec = manifold->m_localPoint;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2WorldManifold.hx",152)
			planePointX = ((xfB->position->x + (tMat->col1->x * tVec->x)) + (tMat->col2->x * tVec->y));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2WorldManifold.hx",153)
			planePointY = ((xfB->position->y + (tMat->col1->y * tVec->x)) + (tMat->col2->y * tVec->y));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2WorldManifold.hx",156)
			this->m_normal->x = -(normalX);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2WorldManifold.hx",157)
			this->m_normal->y = -(normalY);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2WorldManifold.hx",158)
			{
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2WorldManifold.hx",158)
				int _g1 = (int)0;
				int _g = manifold->m_pointCount;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2WorldManifold.hx",158)
				while(((_g1 < _g))){
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2WorldManifold.hx",158)
					int i1 = (_g1)++;
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2WorldManifold.hx",161)
					tMat = xfA->R;
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2WorldManifold.hx",162)
					tVec = manifold->m_points->__get(i1)->m_localPoint;
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2WorldManifold.hx",163)
					clipPointX = ((xfA->position->x + (tMat->col1->x * tVec->x)) + (tMat->col2->x * tVec->y));
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2WorldManifold.hx",164)
					clipPointY = ((xfA->position->y + (tMat->col1->y * tVec->x)) + (tMat->col2->y * tVec->y));
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2WorldManifold.hx",169)
					this->m_points->__get(i1)->x = (clipPointX + ((0.5 * ((((radiusB - (((clipPointX - planePointX)) * normalX)) - (((clipPointY - planePointY)) * normalY)) - radiusA))) * normalX));
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2WorldManifold.hx",170)
					this->m_points->__get(i1)->y = (clipPointY + ((0.5 * ((((radiusB - (((clipPointX - planePointX)) * normalX)) - (((clipPointY - planePointY)) * normalY)) - radiusA))) * normalY));
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC5(B2WorldManifold_obj,initialize,(void))


B2WorldManifold_obj::B2WorldManifold_obj()
{
}

void B2WorldManifold_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(B2WorldManifold);
	HX_MARK_MEMBER_NAME(m_normal,"m_normal");
	HX_MARK_MEMBER_NAME(m_points,"m_points");
	HX_MARK_END_CLASS();
}

Dynamic B2WorldManifold_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"m_normal") ) { return m_normal; }
		if (HX_FIELD_EQ(inName,"m_points") ) { return m_points; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"initialize") ) { return initialize_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic B2WorldManifold_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"m_normal") ) { m_normal=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_points") ) { m_points=inValue.Cast< Array< ::box2D::common::math::B2Vec2 > >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void B2WorldManifold_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("m_normal"));
	outFields->push(HX_CSTRING("m_points"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("initialize"),
	HX_CSTRING("m_normal"),
	HX_CSTRING("m_points"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class B2WorldManifold_obj::__mClass;

void B2WorldManifold_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.collision.B2WorldManifold"), hx::TCanCast< B2WorldManifold_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void B2WorldManifold_obj::__boot()
{
}

} // end namespace box2D
} // end namespace collision
