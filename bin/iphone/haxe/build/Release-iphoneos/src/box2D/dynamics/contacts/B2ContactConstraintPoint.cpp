#include <hxcpp.h>

#ifndef INCLUDED_box2D_common_math_B2Vec2
#include <box2D/common/math/B2Vec2.h>
#endif
#ifndef INCLUDED_box2D_dynamics_contacts_B2ContactConstraintPoint
#include <box2D/dynamics/contacts/B2ContactConstraintPoint.h>
#endif
namespace box2D{
namespace dynamics{
namespace contacts{

Void B2ContactConstraintPoint_obj::__construct()
{
{
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactConstraintPoint.hx",33)
	this->localPoint = ::box2D::common::math::B2Vec2_obj::__new(null(),null());
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactConstraintPoint.hx",34)
	this->rA = ::box2D::common::math::B2Vec2_obj::__new(null(),null());
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactConstraintPoint.hx",35)
	this->rB = ::box2D::common::math::B2Vec2_obj::__new(null(),null());
}
;
	return null();
}

B2ContactConstraintPoint_obj::~B2ContactConstraintPoint_obj() { }

Dynamic B2ContactConstraintPoint_obj::__CreateEmpty() { return  new B2ContactConstraintPoint_obj; }
hx::ObjectPtr< B2ContactConstraintPoint_obj > B2ContactConstraintPoint_obj::__new()
{  hx::ObjectPtr< B2ContactConstraintPoint_obj > result = new B2ContactConstraintPoint_obj();
	result->__construct();
	return result;}

Dynamic B2ContactConstraintPoint_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2ContactConstraintPoint_obj > result = new B2ContactConstraintPoint_obj();
	result->__construct();
	return result;}


B2ContactConstraintPoint_obj::B2ContactConstraintPoint_obj()
{
}

void B2ContactConstraintPoint_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(B2ContactConstraintPoint);
	HX_MARK_MEMBER_NAME(localPoint,"localPoint");
	HX_MARK_MEMBER_NAME(rA,"rA");
	HX_MARK_MEMBER_NAME(rB,"rB");
	HX_MARK_MEMBER_NAME(normalImpulse,"normalImpulse");
	HX_MARK_MEMBER_NAME(tangentImpulse,"tangentImpulse");
	HX_MARK_MEMBER_NAME(normalMass,"normalMass");
	HX_MARK_MEMBER_NAME(tangentMass,"tangentMass");
	HX_MARK_MEMBER_NAME(equalizedMass,"equalizedMass");
	HX_MARK_MEMBER_NAME(velocityBias,"velocityBias");
	HX_MARK_END_CLASS();
}

Dynamic B2ContactConstraintPoint_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"rA") ) { return rA; }
		if (HX_FIELD_EQ(inName,"rB") ) { return rB; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"localPoint") ) { return localPoint; }
		if (HX_FIELD_EQ(inName,"normalMass") ) { return normalMass; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"tangentMass") ) { return tangentMass; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"velocityBias") ) { return velocityBias; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"normalImpulse") ) { return normalImpulse; }
		if (HX_FIELD_EQ(inName,"equalizedMass") ) { return equalizedMass; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"tangentImpulse") ) { return tangentImpulse; }
	}
	return super::__Field(inName);
}

Dynamic B2ContactConstraintPoint_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"rA") ) { rA=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"rB") ) { rB=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"localPoint") ) { localPoint=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"normalMass") ) { normalMass=inValue.Cast< double >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"tangentMass") ) { tangentMass=inValue.Cast< double >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"velocityBias") ) { velocityBias=inValue.Cast< double >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"normalImpulse") ) { normalImpulse=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"equalizedMass") ) { equalizedMass=inValue.Cast< double >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"tangentImpulse") ) { tangentImpulse=inValue.Cast< double >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void B2ContactConstraintPoint_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("localPoint"));
	outFields->push(HX_CSTRING("rA"));
	outFields->push(HX_CSTRING("rB"));
	outFields->push(HX_CSTRING("normalImpulse"));
	outFields->push(HX_CSTRING("tangentImpulse"));
	outFields->push(HX_CSTRING("normalMass"));
	outFields->push(HX_CSTRING("tangentMass"));
	outFields->push(HX_CSTRING("equalizedMass"));
	outFields->push(HX_CSTRING("velocityBias"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("localPoint"),
	HX_CSTRING("rA"),
	HX_CSTRING("rB"),
	HX_CSTRING("normalImpulse"),
	HX_CSTRING("tangentImpulse"),
	HX_CSTRING("normalMass"),
	HX_CSTRING("tangentMass"),
	HX_CSTRING("equalizedMass"),
	HX_CSTRING("velocityBias"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class B2ContactConstraintPoint_obj::__mClass;

void B2ContactConstraintPoint_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.dynamics.contacts.B2ContactConstraintPoint"), hx::TCanCast< B2ContactConstraintPoint_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void B2ContactConstraintPoint_obj::__boot()
{
}

} // end namespace box2D
} // end namespace dynamics
} // end namespace contacts
