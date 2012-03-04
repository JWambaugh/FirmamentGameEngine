#ifndef INCLUDED_com_firmamentengine_firmament_FWorldPositionalInterface
#define INCLUDED_com_firmamentengine_firmament_FWorldPositionalInterface

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(box2D,common,math,B2Vec2)
HX_DECLARE_CLASS3(com,firmamentengine,firmament,FVector)
HX_DECLARE_CLASS3(com,firmamentengine,firmament,FWorldPositionalInterface)
namespace com{
namespace firmamentengine{
namespace firmament{


class FWorldPositionalInterface_obj : public hx::Interface{
	public:
		typedef hx::Interface super;
		typedef FWorldPositionalInterface_obj OBJ_;
		HX_DO_INTERFACE_RTTI;
		virtual Void setPosition( ::com::firmamentengine::firmament::FVector pos)=0;
		Dynamic setPosition_dyn();
		virtual ::com::firmamentengine::firmament::FVector getPosition( )=0;
		Dynamic getPosition_dyn();
		virtual double getPositionX( )=0;
		Dynamic getPositionX_dyn();
		virtual double getPositionY( )=0;
		Dynamic getPositionY_dyn();
};

#define DELEGATE_com_firmamentengine_firmament_FWorldPositionalInterface \
virtual Void setPosition( ::com::firmamentengine::firmament::FVector pos) { return mDelegate->setPosition(pos);}  \
virtual Dynamic setPosition_dyn() { return mDelegate->setPosition_dyn();}  \
virtual ::com::firmamentengine::firmament::FVector getPosition( ) { return mDelegate->getPosition();}  \
virtual Dynamic getPosition_dyn() { return mDelegate->getPosition_dyn();}  \
virtual double getPositionX( ) { return mDelegate->getPositionX();}  \
virtual Dynamic getPositionX_dyn() { return mDelegate->getPositionX_dyn();}  \
virtual double getPositionY( ) { return mDelegate->getPositionY();}  \
virtual Dynamic getPositionY_dyn() { return mDelegate->getPositionY_dyn();}  \


template<typename IMPL>
class FWorldPositionalInterface_delegate_ : public FWorldPositionalInterface_obj
{
	protected:
		IMPL *mDelegate;
	public:
		FWorldPositionalInterface_delegate_(IMPL *inDelegate) : mDelegate(inDelegate) {}
		hx::Object *__GetRealObject() { return mDelegate; }
		DELEGATE_com_firmamentengine_firmament_FWorldPositionalInterface
};

} // end namespace com
} // end namespace firmamentengine
} // end namespace firmament

#endif /* INCLUDED_com_firmamentengine_firmament_FWorldPositionalInterface */ 
