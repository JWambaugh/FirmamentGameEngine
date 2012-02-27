#ifndef INCLUDED_box2D_collision_IBroadPhase
#define INCLUDED_box2D_collision_IBroadPhase

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(box2D,collision,B2AABB)
HX_DECLARE_CLASS2(box2D,collision,B2RayCastInput)
HX_DECLARE_CLASS2(box2D,collision,IBroadPhase)
HX_DECLARE_CLASS3(box2D,common,math,B2Vec2)
namespace box2D{
namespace collision{


class IBroadPhase_obj : public hx::Interface{
	public:
		typedef hx::Interface super;
		typedef IBroadPhase_obj OBJ_;
		HX_DO_INTERFACE_RTTI;
		virtual Dynamic createProxy( ::box2D::collision::B2AABB aabb,Dynamic userData)=0;
		Dynamic createProxy_dyn();
		virtual Void destroyProxy( Dynamic proxy)=0;
		Dynamic destroyProxy_dyn();
		virtual Void moveProxy( Dynamic proxy,::box2D::collision::B2AABB aabb,::box2D::common::math::B2Vec2 displacement)=0;
		Dynamic moveProxy_dyn();
		virtual bool testOverlap( Dynamic proxyA,Dynamic proxyB)=0;
		Dynamic testOverlap_dyn();
		virtual Dynamic getUserData( Dynamic proxy)=0;
		Dynamic getUserData_dyn();
		virtual ::box2D::collision::B2AABB getFatAABB( Dynamic proxy)=0;
		Dynamic getFatAABB_dyn();
		virtual int getProxyCount( )=0;
		Dynamic getProxyCount_dyn();
		virtual Void updatePairs( Dynamic callbackMethod)=0;
		Dynamic updatePairs_dyn();
		virtual Void query( Dynamic callbackMethod,::box2D::collision::B2AABB aabb)=0;
		Dynamic query_dyn();
		virtual Void rayCast( Dynamic callbackMethod,::box2D::collision::B2RayCastInput input)=0;
		Dynamic rayCast_dyn();
		virtual Void validate( )=0;
		Dynamic validate_dyn();
		virtual Void rebalance( int iterations)=0;
		Dynamic rebalance_dyn();
};

#define DELEGATE_box2D_collision_IBroadPhase \
virtual Dynamic createProxy( ::box2D::collision::B2AABB aabb,Dynamic userData) { return mDelegate->createProxy(aabb,userData);}  \
virtual Dynamic createProxy_dyn() { return mDelegate->createProxy_dyn();}  \
virtual Void destroyProxy( Dynamic proxy) { return mDelegate->destroyProxy(proxy);}  \
virtual Dynamic destroyProxy_dyn() { return mDelegate->destroyProxy_dyn();}  \
virtual Void moveProxy( Dynamic proxy,::box2D::collision::B2AABB aabb,::box2D::common::math::B2Vec2 displacement) { return mDelegate->moveProxy(proxy,aabb,displacement);}  \
virtual Dynamic moveProxy_dyn() { return mDelegate->moveProxy_dyn();}  \
virtual bool testOverlap( Dynamic proxyA,Dynamic proxyB) { return mDelegate->testOverlap(proxyA,proxyB);}  \
virtual Dynamic testOverlap_dyn() { return mDelegate->testOverlap_dyn();}  \
virtual Dynamic getUserData( Dynamic proxy) { return mDelegate->getUserData(proxy);}  \
virtual Dynamic getUserData_dyn() { return mDelegate->getUserData_dyn();}  \
virtual ::box2D::collision::B2AABB getFatAABB( Dynamic proxy) { return mDelegate->getFatAABB(proxy);}  \
virtual Dynamic getFatAABB_dyn() { return mDelegate->getFatAABB_dyn();}  \
virtual int getProxyCount( ) { return mDelegate->getProxyCount();}  \
virtual Dynamic getProxyCount_dyn() { return mDelegate->getProxyCount_dyn();}  \
virtual Void updatePairs( Dynamic callbackMethod) { return mDelegate->updatePairs(callbackMethod);}  \
virtual Dynamic updatePairs_dyn() { return mDelegate->updatePairs_dyn();}  \
virtual Void query( Dynamic callbackMethod,::box2D::collision::B2AABB aabb) { return mDelegate->query(callbackMethod,aabb);}  \
virtual Dynamic query_dyn() { return mDelegate->query_dyn();}  \
virtual Void rayCast( Dynamic callbackMethod,::box2D::collision::B2RayCastInput input) { return mDelegate->rayCast(callbackMethod,input);}  \
virtual Dynamic rayCast_dyn() { return mDelegate->rayCast_dyn();}  \
virtual Void validate( ) { return mDelegate->validate();}  \
virtual Dynamic validate_dyn() { return mDelegate->validate_dyn();}  \
virtual Void rebalance( int iterations) { return mDelegate->rebalance(iterations);}  \
virtual Dynamic rebalance_dyn() { return mDelegate->rebalance_dyn();}  \


template<typename IMPL>
class IBroadPhase_delegate_ : public IBroadPhase_obj
{
	protected:
		IMPL *mDelegate;
	public:
		IBroadPhase_delegate_(IMPL *inDelegate) : mDelegate(inDelegate) {}
		hx::Object *__GetRealObject() { return mDelegate; }
		DELEGATE_box2D_collision_IBroadPhase
};

} // end namespace box2D
} // end namespace collision

#endif /* INCLUDED_box2D_collision_IBroadPhase */ 
