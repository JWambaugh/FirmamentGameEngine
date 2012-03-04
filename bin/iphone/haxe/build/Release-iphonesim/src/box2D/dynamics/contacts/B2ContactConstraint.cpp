#include <hxcpp.h>

#ifndef INCLUDED_box2D_collision_B2Manifold
#include <box2D/collision/B2Manifold.h>
#endif
#ifndef INCLUDED_box2D_common_B2Settings
#include <box2D/common/B2Settings.h>
#endif
#ifndef INCLUDED_box2D_common_math_B2Mat22
#include <box2D/common/math/B2Mat22.h>
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
namespace box2D{
namespace dynamics{
namespace contacts{

Void B2ContactConstraint_obj::__construct()
{
{
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactConstraint.hx",35)
	this->localPlaneNormal = ::box2D::common::math::B2Vec2_obj::__new(null(),null());
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactConstraint.hx",36)
	this->localPoint = ::box2D::common::math::B2Vec2_obj::__new(null(),null());
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactConstraint.hx",37)
	this->normal = ::box2D::common::math::B2Vec2_obj::__new(null(),null());
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactConstraint.hx",38)
	this->normalMass = ::box2D::common::math::B2Mat22_obj::__new();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactConstraint.hx",39)
	this->K = ::box2D::common::math::B2Mat22_obj::__new();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactConstraint.hx",40)
	this->points = Array_obj< ::box2D::dynamics::contacts::B2ContactConstraintPoint >::__new();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactConstraint.hx",41)
	{
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactConstraint.hx",41)
		int _g1 = (int)0;
		int _g = ::box2D::common::B2Settings_obj::b2_maxManifoldPoints;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactConstraint.hx",41)
		while(((_g1 < _g))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactConstraint.hx",41)
			int i = (_g1)++;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactConstraint.hx",42)
			this->points[i] = ::box2D::dynamics::contacts::B2ContactConstraintPoint_obj::__new();
		}
	}
}
;
	return null();
}

B2ContactConstraint_obj::~B2ContactConstraint_obj() { }

Dynamic B2ContactConstraint_obj::__CreateEmpty() { return  new B2ContactConstraint_obj; }
hx::ObjectPtr< B2ContactConstraint_obj > B2ContactConstraint_obj::__new()
{  hx::ObjectPtr< B2ContactConstraint_obj > result = new B2ContactConstraint_obj();
	result->__construct();
	return result;}

Dynamic B2ContactConstraint_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2ContactConstraint_obj > result = new B2ContactConstraint_obj();
	result->__construct();
	return result;}


B2ContactConstraint_obj::B2ContactConstraint_obj()
{
}

void B2ContactConstraint_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(B2ContactConstraint);
	HX_MARK_MEMBER_NAME(points,"points");
	HX_MARK_MEMBER_NAME(localPlaneNormal,"localPlaneNormal");
	HX_MARK_MEMBER_NAME(localPoint,"localPoint");
	HX_MARK_MEMBER_NAME(normal,"normal");
	HX_MARK_MEMBER_NAME(normalMass,"normalMass");
	HX_MARK_MEMBER_NAME(K,"K");
	HX_MARK_MEMBER_NAME(bodyA,"bodyA");
	HX_MARK_MEMBER_NAME(bodyB,"bodyB");
	HX_MARK_MEMBER_NAME(type,"type");
	HX_MARK_MEMBER_NAME(radius,"radius");
	HX_MARK_MEMBER_NAME(friction,"friction");
	HX_MARK_MEMBER_NAME(restitution,"restitution");
	HX_MARK_MEMBER_NAME(pointCount,"pointCount");
	HX_MARK_MEMBER_NAME(manifold,"manifold");
	HX_MARK_END_CLASS();
}

Dynamic B2ContactConstraint_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"K") ) { return K; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"type") ) { return type; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"bodyA") ) { return bodyA; }
		if (HX_FIELD_EQ(inName,"bodyB") ) { return bodyB; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"points") ) { return points; }
		if (HX_FIELD_EQ(inName,"normal") ) { return normal; }
		if (HX_FIELD_EQ(inName,"radius") ) { return radius; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"friction") ) { return friction; }
		if (HX_FIELD_EQ(inName,"manifold") ) { return manifold; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"localPoint") ) { return localPoint; }
		if (HX_FIELD_EQ(inName,"normalMass") ) { return normalMass; }
		if (HX_FIELD_EQ(inName,"pointCount") ) { return pointCount; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"restitution") ) { return restitution; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"localPlaneNormal") ) { return localPlaneNormal; }
	}
	return super::__Field(inName);
}

Dynamic B2ContactConstraint_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"K") ) { K=inValue.Cast< ::box2D::common::math::B2Mat22 >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"type") ) { type=inValue.Cast< int >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"bodyA") ) { bodyA=inValue.Cast< ::box2D::dynamics::B2Body >(); return inValue; }
		if (HX_FIELD_EQ(inName,"bodyB") ) { bodyB=inValue.Cast< ::box2D::dynamics::B2Body >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"points") ) { points=inValue.Cast< Array< ::box2D::dynamics::contacts::B2ContactConstraintPoint > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"normal") ) { normal=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"radius") ) { radius=inValue.Cast< double >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"friction") ) { friction=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"manifold") ) { manifold=inValue.Cast< ::box2D::collision::B2Manifold >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"localPoint") ) { localPoint=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"normalMass") ) { normalMass=inValue.Cast< ::box2D::common::math::B2Mat22 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"pointCount") ) { pointCount=inValue.Cast< int >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"restitution") ) { restitution=inValue.Cast< double >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"localPlaneNormal") ) { localPlaneNormal=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void B2ContactConstraint_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("points"));
	outFields->push(HX_CSTRING("localPlaneNormal"));
	outFields->push(HX_CSTRING("localPoint"));
	outFields->push(HX_CSTRING("normal"));
	outFields->push(HX_CSTRING("normalMass"));
	outFields->push(HX_CSTRING("K"));
	outFields->push(HX_CSTRING("bodyA"));
	outFields->push(HX_CSTRING("bodyB"));
	outFields->push(HX_CSTRING("type"));
	outFields->push(HX_CSTRING("radius"));
	outFields->push(HX_CSTRING("friction"));
	outFields->push(HX_CSTRING("restitution"));
	outFields->push(HX_CSTRING("pointCount"));
	outFields->push(HX_CSTRING("manifold"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("points"),
	HX_CSTRING("localPlaneNormal"),
	HX_CSTRING("localPoint"),
	HX_CSTRING("normal"),
	HX_CSTRING("normalMass"),
	HX_CSTRING("K"),
	HX_CSTRING("bodyA"),
	HX_CSTRING("bodyB"),
	HX_CSTRING("type"),
	HX_CSTRING("radius"),
	HX_CSTRING("friction"),
	HX_CSTRING("restitution"),
	HX_CSTRING("pointCount"),
	HX_CSTRING("manifold"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class B2ContactConstraint_obj::__mClass;

void B2ContactConstraint_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.dynamics.contacts.B2ContactConstraint"), hx::TCanCast< B2ContactConstraint_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void B2ContactConstraint_obj::__boot()
{
}

} // end namespace box2D
} // end namespace dynamics
} // end namespace contacts
