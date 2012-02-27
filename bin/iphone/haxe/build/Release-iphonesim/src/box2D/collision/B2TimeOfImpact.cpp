#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_box2D_collision_B2Distance
#include <box2D/collision/B2Distance.h>
#endif
#ifndef INCLUDED_box2D_collision_B2DistanceInput
#include <box2D/collision/B2DistanceInput.h>
#endif
#ifndef INCLUDED_box2D_collision_B2DistanceOutput
#include <box2D/collision/B2DistanceOutput.h>
#endif
#ifndef INCLUDED_box2D_collision_B2DistanceProxy
#include <box2D/collision/B2DistanceProxy.h>
#endif
#ifndef INCLUDED_box2D_collision_B2SeparationFunction
#include <box2D/collision/B2SeparationFunction.h>
#endif
#ifndef INCLUDED_box2D_collision_B2SimplexCache
#include <box2D/collision/B2SimplexCache.h>
#endif
#ifndef INCLUDED_box2D_collision_B2TOIInput
#include <box2D/collision/B2TOIInput.h>
#endif
#ifndef INCLUDED_box2D_collision_B2TimeOfImpact
#include <box2D/collision/B2TimeOfImpact.h>
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
#ifndef INCLUDED_box2D_common_math_B2Sweep
#include <box2D/common/math/B2Sweep.h>
#endif
#ifndef INCLUDED_box2D_common_math_B2Transform
#include <box2D/common/math/B2Transform.h>
#endif
#ifndef INCLUDED_box2D_common_math_B2Vec2
#include <box2D/common/math/B2Vec2.h>
#endif
namespace box2D{
namespace collision{

Void B2TimeOfImpact_obj::__construct()
{
	return null();
}

B2TimeOfImpact_obj::~B2TimeOfImpact_obj() { }

Dynamic B2TimeOfImpact_obj::__CreateEmpty() { return  new B2TimeOfImpact_obj; }
hx::ObjectPtr< B2TimeOfImpact_obj > B2TimeOfImpact_obj::__new()
{  hx::ObjectPtr< B2TimeOfImpact_obj > result = new B2TimeOfImpact_obj();
	result->__construct();
	return result;}

Dynamic B2TimeOfImpact_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2TimeOfImpact_obj > result = new B2TimeOfImpact_obj();
	result->__construct();
	return result;}

int B2TimeOfImpact_obj::b2_toiCalls;

int B2TimeOfImpact_obj::b2_toiIters;

int B2TimeOfImpact_obj::b2_toiMaxIters;

int B2TimeOfImpact_obj::b2_toiRootIters;

int B2TimeOfImpact_obj::b2_toiMaxRootIters;

::box2D::collision::B2SimplexCache B2TimeOfImpact_obj::s_cache;

::box2D::collision::B2DistanceInput B2TimeOfImpact_obj::s_distanceInput;

::box2D::common::math::B2Transform B2TimeOfImpact_obj::s_xfA;

::box2D::common::math::B2Transform B2TimeOfImpact_obj::s_xfB;

::box2D::collision::B2SeparationFunction B2TimeOfImpact_obj::s_fcn;

::box2D::collision::B2DistanceOutput B2TimeOfImpact_obj::s_distanceOutput;

double B2TimeOfImpact_obj::timeOfImpact( ::box2D::collision::B2TOIInput input){
	HX_SOURCE_PUSH("B2TimeOfImpact_obj::timeOfImpact")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2TimeOfImpact.hx",48)
	++(::box2D::collision::B2TimeOfImpact_obj::b2_toiCalls);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2TimeOfImpact.hx",50)
	::box2D::collision::B2DistanceProxy proxyA = input->proxyA;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2TimeOfImpact.hx",51)
	::box2D::collision::B2DistanceProxy proxyB = input->proxyB;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2TimeOfImpact.hx",53)
	::box2D::common::math::B2Sweep sweepA = input->sweepA;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2TimeOfImpact.hx",54)
	::box2D::common::math::B2Sweep sweepB = input->sweepB;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2TimeOfImpact.hx",56)
	::box2D::common::B2Settings_obj::b2Assert((sweepA->t0 == sweepB->t0));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2TimeOfImpact.hx",57)
	::box2D::common::B2Settings_obj::b2Assert(((1.0 - sweepA->t0) > 2.2250738585072014e-308));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2TimeOfImpact.hx",59)
	double radius = (proxyA->m_radius + proxyB->m_radius);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2TimeOfImpact.hx",60)
	double tolerance = input->tolerance;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2TimeOfImpact.hx",62)
	double alpha = 0.0;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2TimeOfImpact.hx",64)
	int k_maxIterations = (int)1000;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2TimeOfImpact.hx",65)
	int iter = (int)0;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2TimeOfImpact.hx",66)
	double target = 0.0;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2TimeOfImpact.hx",69)
	::box2D::collision::B2TimeOfImpact_obj::s_cache->count = (int)0;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2TimeOfImpact.hx",70)
	::box2D::collision::B2TimeOfImpact_obj::s_distanceInput->useRadii = false;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2TimeOfImpact.hx",72)
	while((true)){
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2TimeOfImpact.hx",74)
		sweepA->getTransform(::box2D::collision::B2TimeOfImpact_obj::s_xfA,alpha);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2TimeOfImpact.hx",75)
		sweepB->getTransform(::box2D::collision::B2TimeOfImpact_obj::s_xfB,alpha);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2TimeOfImpact.hx",78)
		::box2D::collision::B2TimeOfImpact_obj::s_distanceInput->proxyA = proxyA;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2TimeOfImpact.hx",79)
		::box2D::collision::B2TimeOfImpact_obj::s_distanceInput->proxyB = proxyB;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2TimeOfImpact.hx",80)
		::box2D::collision::B2TimeOfImpact_obj::s_distanceInput->transformA = ::box2D::collision::B2TimeOfImpact_obj::s_xfA;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2TimeOfImpact.hx",81)
		::box2D::collision::B2TimeOfImpact_obj::s_distanceInput->transformB = ::box2D::collision::B2TimeOfImpact_obj::s_xfB;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2TimeOfImpact.hx",83)
		::box2D::collision::B2Distance_obj::distance(::box2D::collision::B2TimeOfImpact_obj::s_distanceOutput,::box2D::collision::B2TimeOfImpact_obj::s_cache,::box2D::collision::B2TimeOfImpact_obj::s_distanceInput);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2TimeOfImpact.hx",85)
		if (((::box2D::collision::B2TimeOfImpact_obj::s_distanceOutput->distance <= 0.0))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2TimeOfImpact.hx",87)
			alpha = 1.0;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2TimeOfImpact.hx",88)
			break;
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2TimeOfImpact.hx",91)
		::box2D::collision::B2TimeOfImpact_obj::s_fcn->initialize(::box2D::collision::B2TimeOfImpact_obj::s_cache,proxyA,::box2D::collision::B2TimeOfImpact_obj::s_xfA,proxyB,::box2D::collision::B2TimeOfImpact_obj::s_xfB);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2TimeOfImpact.hx",93)
		double separation = ::box2D::collision::B2TimeOfImpact_obj::s_fcn->evaluate(::box2D::collision::B2TimeOfImpact_obj::s_xfA,::box2D::collision::B2TimeOfImpact_obj::s_xfB);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2TimeOfImpact.hx",94)
		if (((separation <= 0.0))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2TimeOfImpact.hx",96)
			alpha = 1.0;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2TimeOfImpact.hx",97)
			break;
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2TimeOfImpact.hx",100)
		if (((iter == (int)0))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2TimeOfImpact.hx",101)
			if (((separation > radius))){
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2TimeOfImpact.hx",106)
				target = ::box2D::common::math::B2Math_obj::max((radius - tolerance),(0.75 * radius));
			}
			else{
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2TimeOfImpact.hx",110)
				target = ::box2D::common::math::B2Math_obj::max((separation - tolerance),(0.02 * radius));
			}
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2TimeOfImpact.hx",115)
		if ((((separation - target) < (0.5 * tolerance)))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2TimeOfImpact.hx",117)
			if (((iter == (int)0))){
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2TimeOfImpact.hx",119)
				alpha = 1.0;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2TimeOfImpact.hx",120)
				break;
			}
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2TimeOfImpact.hx",122)
			break;
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2TimeOfImpact.hx",149)
		double newAlpha = alpha;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2TimeOfImpact.hx",150)
		{
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2TimeOfImpact.hx",151)
			double x1 = alpha;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2TimeOfImpact.hx",152)
			double x2 = 1.0;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2TimeOfImpact.hx",154)
			double f1 = separation;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2TimeOfImpact.hx",156)
			sweepA->getTransform(::box2D::collision::B2TimeOfImpact_obj::s_xfA,x2);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2TimeOfImpact.hx",157)
			sweepB->getTransform(::box2D::collision::B2TimeOfImpact_obj::s_xfB,x2);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2TimeOfImpact.hx",159)
			double f2 = ::box2D::collision::B2TimeOfImpact_obj::s_fcn->evaluate(::box2D::collision::B2TimeOfImpact_obj::s_xfA,::box2D::collision::B2TimeOfImpact_obj::s_xfB);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2TimeOfImpact.hx",162)
			if (((f2 >= target))){
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2TimeOfImpact.hx",164)
				alpha = 1.0;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2TimeOfImpact.hx",165)
				break;
			}
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2TimeOfImpact.hx",169)
			int rootIterCount = (int)0;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2TimeOfImpact.hx",170)
			while((true)){
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2TimeOfImpact.hx",173)
				double x;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2TimeOfImpact.hx",174)
				if (((((int(rootIterCount) & int((int)1))) != (int)0))){
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2TimeOfImpact.hx",175)
					x = (x1 + (double((((target - f1)) * ((x2 - x1)))) / double(((f2 - f1)))));
				}
				else{
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2TimeOfImpact.hx",180)
					x = (0.5 * ((x1 + x2)));
				}
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2TimeOfImpact.hx",185)
				sweepA->getTransform(::box2D::collision::B2TimeOfImpact_obj::s_xfA,x);
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2TimeOfImpact.hx",186)
				sweepB->getTransform(::box2D::collision::B2TimeOfImpact_obj::s_xfB,x);
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2TimeOfImpact.hx",188)
				double f = ::box2D::collision::B2TimeOfImpact_obj::s_fcn->evaluate(::box2D::collision::B2TimeOfImpact_obj::s_xfA,::box2D::collision::B2TimeOfImpact_obj::s_xfB);
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2TimeOfImpact.hx",190)
				if (((::box2D::common::math::B2Math_obj::abs((f - target)) < (0.025 * tolerance)))){
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2TimeOfImpact.hx",192)
					newAlpha = x;
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2TimeOfImpact.hx",193)
					break;
				}
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2TimeOfImpact.hx",197)
				if (((f > target))){
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2TimeOfImpact.hx",199)
					x1 = x;
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2TimeOfImpact.hx",200)
					f1 = f;
				}
				else{
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2TimeOfImpact.hx",204)
					x2 = x;
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2TimeOfImpact.hx",205)
					f2 = f;
				}
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2TimeOfImpact.hx",208)
				++(rootIterCount);
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2TimeOfImpact.hx",209)
				++(::box2D::collision::B2TimeOfImpact_obj::b2_toiRootIters);
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2TimeOfImpact.hx",210)
				if (((rootIterCount == (int)50))){
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2TimeOfImpact.hx",211)
					break;
				}
			}
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2TimeOfImpact.hx",216)
			::box2D::collision::B2TimeOfImpact_obj::b2_toiMaxRootIters = ::Std_obj::_int(::box2D::common::math::B2Math_obj::max(::box2D::collision::B2TimeOfImpact_obj::b2_toiMaxRootIters,rootIterCount));
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2TimeOfImpact.hx",220)
		if (((newAlpha < (((1.0 + (100.0 * 2.2250738585072014e-308))) * alpha)))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2TimeOfImpact.hx",221)
			break;
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2TimeOfImpact.hx",225)
		alpha = newAlpha;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2TimeOfImpact.hx",227)
		(iter)++;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2TimeOfImpact.hx",228)
		++(::box2D::collision::B2TimeOfImpact_obj::b2_toiIters);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2TimeOfImpact.hx",230)
		if (((iter == k_maxIterations))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2TimeOfImpact.hx",231)
			break;
		}
	}
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2TimeOfImpact.hx",236)
	::box2D::collision::B2TimeOfImpact_obj::b2_toiMaxIters = ::Std_obj::_int(::box2D::common::math::B2Math_obj::max(::box2D::collision::B2TimeOfImpact_obj::b2_toiMaxIters,iter));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2TimeOfImpact.hx",238)
	return alpha;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(B2TimeOfImpact_obj,timeOfImpact,return )


B2TimeOfImpact_obj::B2TimeOfImpact_obj()
{
}

void B2TimeOfImpact_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(B2TimeOfImpact);
	HX_MARK_END_CLASS();
}

Dynamic B2TimeOfImpact_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"s_xfA") ) { return s_xfA; }
		if (HX_FIELD_EQ(inName,"s_xfB") ) { return s_xfB; }
		if (HX_FIELD_EQ(inName,"s_fcn") ) { return s_fcn; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"s_cache") ) { return s_cache; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"b2_toiCalls") ) { return b2_toiCalls; }
		if (HX_FIELD_EQ(inName,"b2_toiIters") ) { return b2_toiIters; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"timeOfImpact") ) { return timeOfImpact_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"b2_toiMaxIters") ) { return b2_toiMaxIters; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"b2_toiRootIters") ) { return b2_toiRootIters; }
		if (HX_FIELD_EQ(inName,"s_distanceInput") ) { return s_distanceInput; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"s_distanceOutput") ) { return s_distanceOutput; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"b2_toiMaxRootIters") ) { return b2_toiMaxRootIters; }
	}
	return super::__Field(inName);
}

Dynamic B2TimeOfImpact_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"s_xfA") ) { s_xfA=inValue.Cast< ::box2D::common::math::B2Transform >(); return inValue; }
		if (HX_FIELD_EQ(inName,"s_xfB") ) { s_xfB=inValue.Cast< ::box2D::common::math::B2Transform >(); return inValue; }
		if (HX_FIELD_EQ(inName,"s_fcn") ) { s_fcn=inValue.Cast< ::box2D::collision::B2SeparationFunction >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"s_cache") ) { s_cache=inValue.Cast< ::box2D::collision::B2SimplexCache >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"b2_toiCalls") ) { b2_toiCalls=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"b2_toiIters") ) { b2_toiIters=inValue.Cast< int >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"b2_toiMaxIters") ) { b2_toiMaxIters=inValue.Cast< int >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"b2_toiRootIters") ) { b2_toiRootIters=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"s_distanceInput") ) { s_distanceInput=inValue.Cast< ::box2D::collision::B2DistanceInput >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"s_distanceOutput") ) { s_distanceOutput=inValue.Cast< ::box2D::collision::B2DistanceOutput >(); return inValue; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"b2_toiMaxRootIters") ) { b2_toiMaxRootIters=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void B2TimeOfImpact_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("b2_toiCalls"),
	HX_CSTRING("b2_toiIters"),
	HX_CSTRING("b2_toiMaxIters"),
	HX_CSTRING("b2_toiRootIters"),
	HX_CSTRING("b2_toiMaxRootIters"),
	HX_CSTRING("s_cache"),
	HX_CSTRING("s_distanceInput"),
	HX_CSTRING("s_xfA"),
	HX_CSTRING("s_xfB"),
	HX_CSTRING("s_fcn"),
	HX_CSTRING("s_distanceOutput"),
	HX_CSTRING("timeOfImpact"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(B2TimeOfImpact_obj::b2_toiCalls,"b2_toiCalls");
	HX_MARK_MEMBER_NAME(B2TimeOfImpact_obj::b2_toiIters,"b2_toiIters");
	HX_MARK_MEMBER_NAME(B2TimeOfImpact_obj::b2_toiMaxIters,"b2_toiMaxIters");
	HX_MARK_MEMBER_NAME(B2TimeOfImpact_obj::b2_toiRootIters,"b2_toiRootIters");
	HX_MARK_MEMBER_NAME(B2TimeOfImpact_obj::b2_toiMaxRootIters,"b2_toiMaxRootIters");
	HX_MARK_MEMBER_NAME(B2TimeOfImpact_obj::s_cache,"s_cache");
	HX_MARK_MEMBER_NAME(B2TimeOfImpact_obj::s_distanceInput,"s_distanceInput");
	HX_MARK_MEMBER_NAME(B2TimeOfImpact_obj::s_xfA,"s_xfA");
	HX_MARK_MEMBER_NAME(B2TimeOfImpact_obj::s_xfB,"s_xfB");
	HX_MARK_MEMBER_NAME(B2TimeOfImpact_obj::s_fcn,"s_fcn");
	HX_MARK_MEMBER_NAME(B2TimeOfImpact_obj::s_distanceOutput,"s_distanceOutput");
};

Class B2TimeOfImpact_obj::__mClass;

void B2TimeOfImpact_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.collision.B2TimeOfImpact"), hx::TCanCast< B2TimeOfImpact_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void B2TimeOfImpact_obj::__boot()
{
	hx::Static(b2_toiCalls) = (int)0;
	hx::Static(b2_toiIters) = (int)0;
	hx::Static(b2_toiMaxIters) = (int)0;
	hx::Static(b2_toiRootIters) = (int)0;
	hx::Static(b2_toiMaxRootIters) = (int)0;
	hx::Static(s_cache) = ::box2D::collision::B2SimplexCache_obj::__new();
	hx::Static(s_distanceInput) = ::box2D::collision::B2DistanceInput_obj::__new();
	hx::Static(s_xfA) = ::box2D::common::math::B2Transform_obj::__new(null(),null());
	hx::Static(s_xfB) = ::box2D::common::math::B2Transform_obj::__new(null(),null());
	hx::Static(s_fcn) = ::box2D::collision::B2SeparationFunction_obj::__new();
	hx::Static(s_distanceOutput) = ::box2D::collision::B2DistanceOutput_obj::__new();
}

} // end namespace box2D
} // end namespace collision
