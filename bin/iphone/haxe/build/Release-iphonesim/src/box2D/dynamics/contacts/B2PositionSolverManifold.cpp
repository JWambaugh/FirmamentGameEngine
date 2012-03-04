#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_box2D_collision_B2Manifold
#include <box2D/collision/B2Manifold.h>
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
#ifndef INCLUDED_box2D_dynamics_B2Body
#include <box2D/dynamics/B2Body.h>
#endif
#ifndef INCLUDED_box2D_dynamics_contacts_B2ContactConstraint
#include <box2D/dynamics/contacts/B2ContactConstraint.h>
#endif
#ifndef INCLUDED_box2D_dynamics_contacts_B2ContactConstraintPoint
#include <box2D/dynamics/contacts/B2ContactConstraintPoint.h>
#endif
#ifndef INCLUDED_box2D_dynamics_contacts_B2PositionSolverManifold
#include <box2D/dynamics/contacts/B2PositionSolverManifold.h>
#endif
namespace box2D{
namespace dynamics{
namespace contacts{

Void B2PositionSolverManifold_obj::__construct()
{
{
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2PositionSolverManifold.hx",33)
	this->m_normal = ::box2D::common::math::B2Vec2_obj::__new(null(),null());
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2PositionSolverManifold.hx",34)
	this->m_separations = Array_obj< double >::__new();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2PositionSolverManifold.hx",35)
	this->m_points = Array_obj< ::box2D::common::math::B2Vec2 >::__new();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2PositionSolverManifold.hx",36)
	{
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2PositionSolverManifold.hx",36)
		int _g1 = (int)0;
		int _g = ::box2D::common::B2Settings_obj::b2_maxManifoldPoints;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2PositionSolverManifold.hx",36)
		while(((_g1 < _g))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2PositionSolverManifold.hx",36)
			int i = (_g1)++;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2PositionSolverManifold.hx",38)
			this->m_points[i] = ::box2D::common::math::B2Vec2_obj::__new(null(),null());
		}
	}
}
;
	return null();
}

B2PositionSolverManifold_obj::~B2PositionSolverManifold_obj() { }

Dynamic B2PositionSolverManifold_obj::__CreateEmpty() { return  new B2PositionSolverManifold_obj; }
hx::ObjectPtr< B2PositionSolverManifold_obj > B2PositionSolverManifold_obj::__new()
{  hx::ObjectPtr< B2PositionSolverManifold_obj > result = new B2PositionSolverManifold_obj();
	result->__construct();
	return result;}

Dynamic B2PositionSolverManifold_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2PositionSolverManifold_obj > result = new B2PositionSolverManifold_obj();
	result->__construct();
	return result;}

Void B2PositionSolverManifold_obj::initialize( ::box2D::dynamics::contacts::B2ContactConstraint cc){
{
		HX_SOURCE_PUSH("B2PositionSolverManifold_obj::initialize")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2PositionSolverManifold.hx",46)
		::box2D::common::B2Settings_obj::b2Assert((cc->pointCount > (int)0));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2PositionSolverManifold.hx",48)
		int i;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2PositionSolverManifold.hx",49)
		double clipPointX;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2PositionSolverManifold.hx",50)
		double clipPointY;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2PositionSolverManifold.hx",51)
		::box2D::common::math::B2Mat22 tMat;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2PositionSolverManifold.hx",52)
		::box2D::common::math::B2Vec2 tVec;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2PositionSolverManifold.hx",53)
		double planePointX;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2PositionSolverManifold.hx",54)
		double planePointY;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2PositionSolverManifold.hx",56)
		int _switch_1 = (cc->type);
		if (  ( _switch_1==::box2D::collision::B2Manifold_obj::e_circles)){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2PositionSolverManifold.hx",61)
			tMat = cc->bodyA->m_xf->R;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2PositionSolverManifold.hx",62)
			tVec = cc->localPoint;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2PositionSolverManifold.hx",63)
			double pointAX = (cc->bodyA->m_xf->position->x + (((tMat->col1->x * tVec->x) + (tMat->col2->x * tVec->y))));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2PositionSolverManifold.hx",64)
			double pointAY = (cc->bodyA->m_xf->position->y + (((tMat->col1->y * tVec->x) + (tMat->col2->y * tVec->y))));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2PositionSolverManifold.hx",66)
			tMat = cc->bodyB->m_xf->R;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2PositionSolverManifold.hx",67)
			tVec = cc->points->__get((int)0)->localPoint;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2PositionSolverManifold.hx",68)
			double pointBX = (cc->bodyB->m_xf->position->x + (((tMat->col1->x * tVec->x) + (tMat->col2->x * tVec->y))));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2PositionSolverManifold.hx",69)
			double pointBY = (cc->bodyB->m_xf->position->y + (((tMat->col1->y * tVec->x) + (tMat->col2->y * tVec->y))));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2PositionSolverManifold.hx",70)
			double dX = (pointBX - pointAX);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2PositionSolverManifold.hx",71)
			double dY = (pointBY - pointAY);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2PositionSolverManifold.hx",72)
			double d2 = ((dX * dX) + (dY * dY));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2PositionSolverManifold.hx",73)
			if (((d2 > 0.))){
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2PositionSolverManifold.hx",75)
				double d = ::Math_obj::sqrt(d2);
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2PositionSolverManifold.hx",76)
				this->m_normal->x = (double(dX) / double(d));
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2PositionSolverManifold.hx",77)
				this->m_normal->y = (double(dY) / double(d));
			}
			else{
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2PositionSolverManifold.hx",81)
				this->m_normal->x = 1.0;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2PositionSolverManifold.hx",82)
				this->m_normal->y = 0.0;
			}
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2PositionSolverManifold.hx",84)
			this->m_points->__get((int)0)->x = (0.5 * ((pointAX + pointBX)));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2PositionSolverManifold.hx",85)
			this->m_points->__get((int)0)->y = (0.5 * ((pointAY + pointBY)));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2PositionSolverManifold.hx",86)
			this->m_separations[(int)0] = (((dX * this->m_normal->x) + (dY * this->m_normal->y)) - cc->radius);
		}
		else if (  ( _switch_1==::box2D::collision::B2Manifold_obj::e_faceA)){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2PositionSolverManifold.hx",92)
			tMat = cc->bodyA->m_xf->R;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2PositionSolverManifold.hx",93)
			tVec = cc->localPlaneNormal;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2PositionSolverManifold.hx",94)
			this->m_normal->x = ((tMat->col1->x * tVec->x) + (tMat->col2->x * tVec->y));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2PositionSolverManifold.hx",95)
			this->m_normal->y = ((tMat->col1->y * tVec->x) + (tMat->col2->y * tVec->y));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2PositionSolverManifold.hx",97)
			tMat = cc->bodyA->m_xf->R;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2PositionSolverManifold.hx",98)
			tVec = cc->localPoint;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2PositionSolverManifold.hx",99)
			planePointX = (cc->bodyA->m_xf->position->x + (((tMat->col1->x * tVec->x) + (tMat->col2->x * tVec->y))));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2PositionSolverManifold.hx",100)
			planePointY = (cc->bodyA->m_xf->position->y + (((tMat->col1->y * tVec->x) + (tMat->col2->y * tVec->y))));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2PositionSolverManifold.hx",102)
			tMat = cc->bodyB->m_xf->R;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2PositionSolverManifold.hx",103)
			{
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2PositionSolverManifold.hx",103)
				int _g1 = (int)0;
				int _g = cc->pointCount;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2PositionSolverManifold.hx",103)
				while(((_g1 < _g))){
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2PositionSolverManifold.hx",103)
					int i1 = (_g1)++;
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2PositionSolverManifold.hx",106)
					tVec = cc->points->__get(i1)->localPoint;
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2PositionSolverManifold.hx",107)
					clipPointX = (cc->bodyB->m_xf->position->x + (((tMat->col1->x * tVec->x) + (tMat->col2->x * tVec->y))));
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2PositionSolverManifold.hx",108)
					clipPointY = (cc->bodyB->m_xf->position->y + (((tMat->col1->y * tVec->x) + (tMat->col2->y * tVec->y))));
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2PositionSolverManifold.hx",109)
					this->m_separations[i1] = (((((clipPointX - planePointX)) * this->m_normal->x) + (((clipPointY - planePointY)) * this->m_normal->y)) - cc->radius);
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2PositionSolverManifold.hx",110)
					this->m_points->__get(i1)->x = clipPointX;
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2PositionSolverManifold.hx",111)
					this->m_points->__get(i1)->y = clipPointY;
				}
			}
		}
		else if (  ( _switch_1==::box2D::collision::B2Manifold_obj::e_faceB)){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2PositionSolverManifold.hx",118)
			tMat = cc->bodyB->m_xf->R;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2PositionSolverManifold.hx",119)
			tVec = cc->localPlaneNormal;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2PositionSolverManifold.hx",120)
			this->m_normal->x = ((tMat->col1->x * tVec->x) + (tMat->col2->x * tVec->y));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2PositionSolverManifold.hx",121)
			this->m_normal->y = ((tMat->col1->y * tVec->x) + (tMat->col2->y * tVec->y));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2PositionSolverManifold.hx",123)
			tMat = cc->bodyB->m_xf->R;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2PositionSolverManifold.hx",124)
			tVec = cc->localPoint;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2PositionSolverManifold.hx",125)
			planePointX = (cc->bodyB->m_xf->position->x + (((tMat->col1->x * tVec->x) + (tMat->col2->x * tVec->y))));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2PositionSolverManifold.hx",126)
			planePointY = (cc->bodyB->m_xf->position->y + (((tMat->col1->y * tVec->x) + (tMat->col2->y * tVec->y))));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2PositionSolverManifold.hx",128)
			tMat = cc->bodyA->m_xf->R;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2PositionSolverManifold.hx",129)
			{
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2PositionSolverManifold.hx",129)
				int _g1 = (int)0;
				int _g = cc->pointCount;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2PositionSolverManifold.hx",129)
				while(((_g1 < _g))){
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2PositionSolverManifold.hx",129)
					int i1 = (_g1)++;
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2PositionSolverManifold.hx",132)
					tVec = cc->points->__get(i1)->localPoint;
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2PositionSolverManifold.hx",133)
					clipPointX = (cc->bodyA->m_xf->position->x + (((tMat->col1->x * tVec->x) + (tMat->col2->x * tVec->y))));
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2PositionSolverManifold.hx",134)
					clipPointY = (cc->bodyA->m_xf->position->y + (((tMat->col1->y * tVec->x) + (tMat->col2->y * tVec->y))));
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2PositionSolverManifold.hx",135)
					this->m_separations[i1] = (((((clipPointX - planePointX)) * this->m_normal->x) + (((clipPointY - planePointY)) * this->m_normal->y)) - cc->radius);
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2PositionSolverManifold.hx",136)
					this->m_points->__get(i1)->set(clipPointX,clipPointY);
				}
			}
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2PositionSolverManifold.hx",140)
			hx::MultEq(this->m_normal->x,(int)-1);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2PositionSolverManifold.hx",141)
			hx::MultEq(this->m_normal->y,(int)-1);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2PositionSolverManifold_obj,initialize,(void))

::box2D::common::math::B2Vec2 B2PositionSolverManifold_obj::circlePointA;

::box2D::common::math::B2Vec2 B2PositionSolverManifold_obj::circlePointB;


B2PositionSolverManifold_obj::B2PositionSolverManifold_obj()
{
}

void B2PositionSolverManifold_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(B2PositionSolverManifold);
	HX_MARK_MEMBER_NAME(m_normal,"m_normal");
	HX_MARK_MEMBER_NAME(m_points,"m_points");
	HX_MARK_MEMBER_NAME(m_separations,"m_separations");
	HX_MARK_END_CLASS();
}

Dynamic B2PositionSolverManifold_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"m_normal") ) { return m_normal; }
		if (HX_FIELD_EQ(inName,"m_points") ) { return m_points; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"initialize") ) { return initialize_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"circlePointA") ) { return circlePointA; }
		if (HX_FIELD_EQ(inName,"circlePointB") ) { return circlePointB; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"m_separations") ) { return m_separations; }
	}
	return super::__Field(inName);
}

Dynamic B2PositionSolverManifold_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"m_normal") ) { m_normal=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_points") ) { m_points=inValue.Cast< Array< ::box2D::common::math::B2Vec2 > >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"circlePointA") ) { circlePointA=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"circlePointB") ) { circlePointB=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"m_separations") ) { m_separations=inValue.Cast< Array< double > >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void B2PositionSolverManifold_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("m_normal"));
	outFields->push(HX_CSTRING("m_points"));
	outFields->push(HX_CSTRING("m_separations"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("circlePointA"),
	HX_CSTRING("circlePointB"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("initialize"),
	HX_CSTRING("m_normal"),
	HX_CSTRING("m_points"),
	HX_CSTRING("m_separations"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(B2PositionSolverManifold_obj::circlePointA,"circlePointA");
	HX_MARK_MEMBER_NAME(B2PositionSolverManifold_obj::circlePointB,"circlePointB");
};

Class B2PositionSolverManifold_obj::__mClass;

void B2PositionSolverManifold_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.dynamics.contacts.B2PositionSolverManifold"), hx::TCanCast< B2PositionSolverManifold_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void B2PositionSolverManifold_obj::__boot()
{
	hx::Static(circlePointA) = ::box2D::common::math::B2Vec2_obj::__new(null(),null());
	hx::Static(circlePointB) = ::box2D::common::math::B2Vec2_obj::__new(null(),null());
}

} // end namespace box2D
} // end namespace dynamics
} // end namespace contacts
