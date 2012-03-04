#ifndef INCLUDED_box2D_common_B2Settings
#define INCLUDED_box2D_common_B2Settings

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(box2D,common,B2Settings)
namespace box2D{
namespace common{


class B2Settings_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef B2Settings_obj OBJ_;
		B2Settings_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< B2Settings_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~B2Settings_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("B2Settings"); }

		static ::String VERSION; /* REM */ 
		static double b2_pi; /* REM */ 
		static int b2_maxManifoldPoints; /* REM */ 
		static double b2_aabbExtension; /* REM */ 
		static double b2_aabbMultiplier; /* REM */ 
		static double b2_polygonRadius; /* REM */ 
		static double b2_linearSlop; /* REM */ 
		static double b2_angularSlop; /* REM */ 
		static double b2_toiSlop; /* REM */ 
		static int b2_maxTOIContactsPerIsland; /* REM */ 
		static int b2_maxTOIJointsPerIsland; /* REM */ 
		static double b2_velocityThreshold; /* REM */ 
		static double b2_maxLinearCorrection; /* REM */ 
		static double b2_maxAngularCorrection; /* REM */ 
		static double b2_maxTranslation; /* REM */ 
		static double b2_maxTranslationSquared; /* REM */ 
		static double b2_maxRotation; /* REM */ 
		static double b2_maxRotationSquared; /* REM */ 
		static double b2_contactBaumgarte; /* REM */ 
		static double b2MixFriction( double friction1,double friction2);
		static Dynamic b2MixFriction_dyn();

		static double b2MixRestitution( double restitution1,double restitution2);
		static Dynamic b2MixRestitution_dyn();

		static double b2_timeToSleep; /* REM */ 
		static double b2_linearSleepTolerance; /* REM */ 
		static double b2_angularSleepTolerance; /* REM */ 
		static Void b2Assert( bool a);
		static Dynamic b2Assert_dyn();

};

} // end namespace box2D
} // end namespace common

#endif /* INCLUDED_box2D_common_B2Settings */ 
