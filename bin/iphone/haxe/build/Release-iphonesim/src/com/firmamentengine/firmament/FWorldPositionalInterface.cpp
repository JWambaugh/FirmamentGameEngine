#include <hxcpp.h>

#ifndef INCLUDED_box2D_common_math_B2Vec2
#include <box2D/common/math/B2Vec2.h>
#endif
#ifndef INCLUDED_com_firmamentengine_firmament_FVector
#include <com/firmamentengine/firmament/FVector.h>
#endif
#ifndef INCLUDED_com_firmamentengine_firmament_FWorldPositionalInterface
#include <com/firmamentengine/firmament/FWorldPositionalInterface.h>
#endif
namespace com{
namespace firmamentengine{
namespace firmament{

HX_DEFINE_DYNAMIC_FUNC1(FWorldPositionalInterface_obj,setPosition,)

HX_DEFINE_DYNAMIC_FUNC0(FWorldPositionalInterface_obj,getPosition,return )

HX_DEFINE_DYNAMIC_FUNC0(FWorldPositionalInterface_obj,getPositionX,return )

HX_DEFINE_DYNAMIC_FUNC0(FWorldPositionalInterface_obj,getPositionY,return )


Class FWorldPositionalInterface_obj::__mClass;

void FWorldPositionalInterface_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.firmamentengine.firmament.FWorldPositionalInterface"), hx::TCanCast< FWorldPositionalInterface_obj> ,0,0,
	0, 0,
	&super::__SGetClass(), 0, 0);
}

} // end namespace com
} // end namespace firmamentengine
} // end namespace firmament
