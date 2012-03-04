#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_box2D_common_B2Settings
#include <box2D/common/B2Settings.h>
#endif
namespace box2D{
namespace common{

Void B2Settings_obj::__construct()
{
	return null();
}

B2Settings_obj::~B2Settings_obj() { }

Dynamic B2Settings_obj::__CreateEmpty() { return  new B2Settings_obj; }
hx::ObjectPtr< B2Settings_obj > B2Settings_obj::__new()
{  hx::ObjectPtr< B2Settings_obj > result = new B2Settings_obj();
	result->__construct();
	return result;}

Dynamic B2Settings_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2Settings_obj > result = new B2Settings_obj();
	result->__construct();
	return result;}

::String B2Settings_obj::VERSION;

double B2Settings_obj::b2_pi;

int B2Settings_obj::b2_maxManifoldPoints;

double B2Settings_obj::b2_aabbExtension;

double B2Settings_obj::b2_aabbMultiplier;

double B2Settings_obj::b2_polygonRadius;

double B2Settings_obj::b2_linearSlop;

double B2Settings_obj::b2_angularSlop;

double B2Settings_obj::b2_toiSlop;

int B2Settings_obj::b2_maxTOIContactsPerIsland;

int B2Settings_obj::b2_maxTOIJointsPerIsland;

double B2Settings_obj::b2_velocityThreshold;

double B2Settings_obj::b2_maxLinearCorrection;

double B2Settings_obj::b2_maxAngularCorrection;

double B2Settings_obj::b2_maxTranslation;

double B2Settings_obj::b2_maxTranslationSquared;

double B2Settings_obj::b2_maxRotation;

double B2Settings_obj::b2_maxRotationSquared;

double B2Settings_obj::b2_contactBaumgarte;

double B2Settings_obj::b2MixFriction( double friction1,double friction2){
	HX_SOURCE_PUSH("B2Settings_obj::b2MixFriction")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/B2Settings.hx",149)
	return ::Math_obj::sqrt((friction1 * friction2));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(B2Settings_obj,b2MixFriction,return )

double B2Settings_obj::b2MixRestitution( double restitution1,double restitution2){
	HX_SOURCE_PUSH("B2Settings_obj::b2MixRestitution")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/B2Settings.hx",157)
	return (  (((restitution1 > restitution2))) ? double(restitution1) : double(restitution2) );
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(B2Settings_obj,b2MixRestitution,return )

double B2Settings_obj::b2_timeToSleep;

double B2Settings_obj::b2_linearSleepTolerance;

double B2Settings_obj::b2_angularSleepTolerance;

Void B2Settings_obj::b2Assert( bool a){
{
		HX_SOURCE_PUSH("B2Settings_obj::b2Assert")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/B2Settings.hx",184)
		if ((!(a))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/common/B2Settings.hx",185)
			hx::Throw (HX_CSTRING("Assertion Failed"));
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(B2Settings_obj,b2Assert,(void))


B2Settings_obj::B2Settings_obj()
{
}

void B2Settings_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(B2Settings);
	HX_MARK_END_CLASS();
}

Dynamic B2Settings_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"b2_pi") ) { return b2_pi; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"VERSION") ) { return VERSION; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"b2Assert") ) { return b2Assert_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"b2_toiSlop") ) { return b2_toiSlop; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"b2_linearSlop") ) { return b2_linearSlop; }
		if (HX_FIELD_EQ(inName,"b2MixFriction") ) { return b2MixFriction_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"b2_angularSlop") ) { return b2_angularSlop; }
		if (HX_FIELD_EQ(inName,"b2_maxRotation") ) { return b2_maxRotation; }
		if (HX_FIELD_EQ(inName,"b2_timeToSleep") ) { return b2_timeToSleep; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"b2_aabbExtension") ) { return b2_aabbExtension; }
		if (HX_FIELD_EQ(inName,"b2_polygonRadius") ) { return b2_polygonRadius; }
		if (HX_FIELD_EQ(inName,"b2MixRestitution") ) { return b2MixRestitution_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"b2_aabbMultiplier") ) { return b2_aabbMultiplier; }
		if (HX_FIELD_EQ(inName,"b2_maxTranslation") ) { return b2_maxTranslation; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"b2_contactBaumgarte") ) { return b2_contactBaumgarte; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"b2_maxManifoldPoints") ) { return b2_maxManifoldPoints; }
		if (HX_FIELD_EQ(inName,"b2_velocityThreshold") ) { return b2_velocityThreshold; }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"b2_maxRotationSquared") ) { return b2_maxRotationSquared; }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"b2_maxLinearCorrection") ) { return b2_maxLinearCorrection; }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"b2_maxAngularCorrection") ) { return b2_maxAngularCorrection; }
		if (HX_FIELD_EQ(inName,"b2_linearSleepTolerance") ) { return b2_linearSleepTolerance; }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"b2_maxTOIJointsPerIsland") ) { return b2_maxTOIJointsPerIsland; }
		if (HX_FIELD_EQ(inName,"b2_maxTranslationSquared") ) { return b2_maxTranslationSquared; }
		if (HX_FIELD_EQ(inName,"b2_angularSleepTolerance") ) { return b2_angularSleepTolerance; }
		break;
	case 26:
		if (HX_FIELD_EQ(inName,"b2_maxTOIContactsPerIsland") ) { return b2_maxTOIContactsPerIsland; }
	}
	return super::__Field(inName);
}

Dynamic B2Settings_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"b2_pi") ) { b2_pi=inValue.Cast< double >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"VERSION") ) { VERSION=inValue.Cast< ::String >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"b2_toiSlop") ) { b2_toiSlop=inValue.Cast< double >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"b2_linearSlop") ) { b2_linearSlop=inValue.Cast< double >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"b2_angularSlop") ) { b2_angularSlop=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"b2_maxRotation") ) { b2_maxRotation=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"b2_timeToSleep") ) { b2_timeToSleep=inValue.Cast< double >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"b2_aabbExtension") ) { b2_aabbExtension=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"b2_polygonRadius") ) { b2_polygonRadius=inValue.Cast< double >(); return inValue; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"b2_aabbMultiplier") ) { b2_aabbMultiplier=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"b2_maxTranslation") ) { b2_maxTranslation=inValue.Cast< double >(); return inValue; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"b2_contactBaumgarte") ) { b2_contactBaumgarte=inValue.Cast< double >(); return inValue; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"b2_maxManifoldPoints") ) { b2_maxManifoldPoints=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"b2_velocityThreshold") ) { b2_velocityThreshold=inValue.Cast< double >(); return inValue; }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"b2_maxRotationSquared") ) { b2_maxRotationSquared=inValue.Cast< double >(); return inValue; }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"b2_maxLinearCorrection") ) { b2_maxLinearCorrection=inValue.Cast< double >(); return inValue; }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"b2_maxAngularCorrection") ) { b2_maxAngularCorrection=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"b2_linearSleepTolerance") ) { b2_linearSleepTolerance=inValue.Cast< double >(); return inValue; }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"b2_maxTOIJointsPerIsland") ) { b2_maxTOIJointsPerIsland=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"b2_maxTranslationSquared") ) { b2_maxTranslationSquared=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"b2_angularSleepTolerance") ) { b2_angularSleepTolerance=inValue.Cast< double >(); return inValue; }
		break;
	case 26:
		if (HX_FIELD_EQ(inName,"b2_maxTOIContactsPerIsland") ) { b2_maxTOIContactsPerIsland=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void B2Settings_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("VERSION"),
	HX_CSTRING("b2_pi"),
	HX_CSTRING("b2_maxManifoldPoints"),
	HX_CSTRING("b2_aabbExtension"),
	HX_CSTRING("b2_aabbMultiplier"),
	HX_CSTRING("b2_polygonRadius"),
	HX_CSTRING("b2_linearSlop"),
	HX_CSTRING("b2_angularSlop"),
	HX_CSTRING("b2_toiSlop"),
	HX_CSTRING("b2_maxTOIContactsPerIsland"),
	HX_CSTRING("b2_maxTOIJointsPerIsland"),
	HX_CSTRING("b2_velocityThreshold"),
	HX_CSTRING("b2_maxLinearCorrection"),
	HX_CSTRING("b2_maxAngularCorrection"),
	HX_CSTRING("b2_maxTranslation"),
	HX_CSTRING("b2_maxTranslationSquared"),
	HX_CSTRING("b2_maxRotation"),
	HX_CSTRING("b2_maxRotationSquared"),
	HX_CSTRING("b2_contactBaumgarte"),
	HX_CSTRING("b2MixFriction"),
	HX_CSTRING("b2MixRestitution"),
	HX_CSTRING("b2_timeToSleep"),
	HX_CSTRING("b2_linearSleepTolerance"),
	HX_CSTRING("b2_angularSleepTolerance"),
	HX_CSTRING("b2Assert"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(B2Settings_obj::VERSION,"VERSION");
	HX_MARK_MEMBER_NAME(B2Settings_obj::b2_pi,"b2_pi");
	HX_MARK_MEMBER_NAME(B2Settings_obj::b2_maxManifoldPoints,"b2_maxManifoldPoints");
	HX_MARK_MEMBER_NAME(B2Settings_obj::b2_aabbExtension,"b2_aabbExtension");
	HX_MARK_MEMBER_NAME(B2Settings_obj::b2_aabbMultiplier,"b2_aabbMultiplier");
	HX_MARK_MEMBER_NAME(B2Settings_obj::b2_polygonRadius,"b2_polygonRadius");
	HX_MARK_MEMBER_NAME(B2Settings_obj::b2_linearSlop,"b2_linearSlop");
	HX_MARK_MEMBER_NAME(B2Settings_obj::b2_angularSlop,"b2_angularSlop");
	HX_MARK_MEMBER_NAME(B2Settings_obj::b2_toiSlop,"b2_toiSlop");
	HX_MARK_MEMBER_NAME(B2Settings_obj::b2_maxTOIContactsPerIsland,"b2_maxTOIContactsPerIsland");
	HX_MARK_MEMBER_NAME(B2Settings_obj::b2_maxTOIJointsPerIsland,"b2_maxTOIJointsPerIsland");
	HX_MARK_MEMBER_NAME(B2Settings_obj::b2_velocityThreshold,"b2_velocityThreshold");
	HX_MARK_MEMBER_NAME(B2Settings_obj::b2_maxLinearCorrection,"b2_maxLinearCorrection");
	HX_MARK_MEMBER_NAME(B2Settings_obj::b2_maxAngularCorrection,"b2_maxAngularCorrection");
	HX_MARK_MEMBER_NAME(B2Settings_obj::b2_maxTranslation,"b2_maxTranslation");
	HX_MARK_MEMBER_NAME(B2Settings_obj::b2_maxTranslationSquared,"b2_maxTranslationSquared");
	HX_MARK_MEMBER_NAME(B2Settings_obj::b2_maxRotation,"b2_maxRotation");
	HX_MARK_MEMBER_NAME(B2Settings_obj::b2_maxRotationSquared,"b2_maxRotationSquared");
	HX_MARK_MEMBER_NAME(B2Settings_obj::b2_contactBaumgarte,"b2_contactBaumgarte");
	HX_MARK_MEMBER_NAME(B2Settings_obj::b2_timeToSleep,"b2_timeToSleep");
	HX_MARK_MEMBER_NAME(B2Settings_obj::b2_linearSleepTolerance,"b2_linearSleepTolerance");
	HX_MARK_MEMBER_NAME(B2Settings_obj::b2_angularSleepTolerance,"b2_angularSleepTolerance");
};

Class B2Settings_obj::__mClass;

void B2Settings_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.common.B2Settings"), hx::TCanCast< B2Settings_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void B2Settings_obj::__boot()
{
	hx::Static(VERSION) = HX_CSTRING("2.1alpha");
	hx::Static(b2_pi) = ::Math_obj::PI;
	hx::Static(b2_maxManifoldPoints) = (int)2;
	hx::Static(b2_aabbExtension) = 0.1;
	hx::Static(b2_aabbMultiplier) = 2.0;
	hx::Static(b2_polygonRadius) = (2.0 * ::box2D::common::B2Settings_obj::b2_linearSlop);
	hx::Static(b2_linearSlop) = 0.005;
	hx::Static(b2_angularSlop) = ((double(2.0) / double(180.0)) * ::box2D::common::B2Settings_obj::b2_pi);
	hx::Static(b2_toiSlop) = (8.0 * ::box2D::common::B2Settings_obj::b2_linearSlop);
	hx::Static(b2_maxTOIContactsPerIsland) = (int)32;
	hx::Static(b2_maxTOIJointsPerIsland) = (int)32;
	hx::Static(b2_velocityThreshold) = 1.0;
	hx::Static(b2_maxLinearCorrection) = 0.2;
	hx::Static(b2_maxAngularCorrection) = ((double(8.0) / double(180.0)) * ::box2D::common::B2Settings_obj::b2_pi);
	hx::Static(b2_maxTranslation) = 2.0;
	hx::Static(b2_maxTranslationSquared) = (::box2D::common::B2Settings_obj::b2_maxTranslation * ::box2D::common::B2Settings_obj::b2_maxTranslation);
	hx::Static(b2_maxRotation) = (0.5 * ::box2D::common::B2Settings_obj::b2_pi);
	hx::Static(b2_maxRotationSquared) = (::box2D::common::B2Settings_obj::b2_maxRotation * ::box2D::common::B2Settings_obj::b2_maxRotation);
	hx::Static(b2_contactBaumgarte) = 0.2;
	hx::Static(b2_timeToSleep) = 0.5;
	hx::Static(b2_linearSleepTolerance) = 0.01;
	hx::Static(b2_angularSleepTolerance) = ((double(2.0) / double(180.0)) * ::box2D::common::B2Settings_obj::b2_pi);
}

} // end namespace box2D
} // end namespace common
