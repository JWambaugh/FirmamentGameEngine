#include <hxcpp.h>

#ifndef INCLUDED_box2D_collision_B2AABB
#include <box2D/collision/B2AABB.h>
#endif
#ifndef INCLUDED_box2D_collision_B2DynamicTree
#include <box2D/collision/B2DynamicTree.h>
#endif
#ifndef INCLUDED_box2D_collision_B2DynamicTreeBroadPhase
#include <box2D/collision/B2DynamicTreeBroadPhase.h>
#endif
#ifndef INCLUDED_box2D_collision_B2DynamicTreeNode
#include <box2D/collision/B2DynamicTreeNode.h>
#endif
#ifndef INCLUDED_box2D_collision_B2DynamicTreePair
#include <box2D/collision/B2DynamicTreePair.h>
#endif
#ifndef INCLUDED_box2D_collision_B2RayCastInput
#include <box2D/collision/B2RayCastInput.h>
#endif
#ifndef INCLUDED_box2D_collision_IBroadPhase
#include <box2D/collision/IBroadPhase.h>
#endif
#ifndef INCLUDED_box2D_common_math_B2Vec2
#include <box2D/common/math/B2Vec2.h>
#endif
namespace box2D{
namespace collision{

Void B2DynamicTreeBroadPhase_obj::__construct()
{
{
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTreeBroadPhase.hx",217)
	this->m_tree = ::box2D::collision::B2DynamicTree_obj::__new();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTreeBroadPhase.hx",218)
	this->m_moveBuffer = Array_obj< ::box2D::collision::B2DynamicTreeNode >::__new();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTreeBroadPhase.hx",220)
	this->m_pairBuffer = Array_obj< ::box2D::collision::B2DynamicTreePair >::__new();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTreeBroadPhase.hx",221)
	this->m_pairCount = (int)0;
}
;
	return null();
}

B2DynamicTreeBroadPhase_obj::~B2DynamicTreeBroadPhase_obj() { }

Dynamic B2DynamicTreeBroadPhase_obj::__CreateEmpty() { return  new B2DynamicTreeBroadPhase_obj; }
hx::ObjectPtr< B2DynamicTreeBroadPhase_obj > B2DynamicTreeBroadPhase_obj::__new()
{  hx::ObjectPtr< B2DynamicTreeBroadPhase_obj > result = new B2DynamicTreeBroadPhase_obj();
	result->__construct();
	return result;}

Dynamic B2DynamicTreeBroadPhase_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2DynamicTreeBroadPhase_obj > result = new B2DynamicTreeBroadPhase_obj();
	result->__construct();
	return result;}

hx::Object *B2DynamicTreeBroadPhase_obj::__ToInterface(const type_info &inType) {
	if (inType==typeid( ::box2D::collision::IBroadPhase_obj)) return operator ::box2D::collision::IBroadPhase_obj *();
	return super::__ToInterface(inType);
}

Dynamic B2DynamicTreeBroadPhase_obj::createProxy( ::box2D::collision::B2AABB aabb,Dynamic userData){
	HX_SOURCE_PUSH("B2DynamicTreeBroadPhase_obj::createProxy")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTreeBroadPhase.hx",20)
	::box2D::collision::B2DynamicTreeNode proxy = this->m_tree->createProxy(aabb,userData);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTreeBroadPhase.hx",21)
	++(this->m_proxyCount);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTreeBroadPhase.hx",22)
	this->bufferMove(proxy);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTreeBroadPhase.hx",23)
	return proxy;
}


HX_DEFINE_DYNAMIC_FUNC2(B2DynamicTreeBroadPhase_obj,createProxy,return )

Void B2DynamicTreeBroadPhase_obj::destroyProxy( Dynamic proxy){
{
		HX_SOURCE_PUSH("B2DynamicTreeBroadPhase_obj::destroyProxy")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTreeBroadPhase.hx",31)
		this->unBufferMove(proxy);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTreeBroadPhase.hx",32)
		--(this->m_proxyCount);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTreeBroadPhase.hx",33)
		this->m_tree->destroyProxy(proxy);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2DynamicTreeBroadPhase_obj,destroyProxy,(void))

Void B2DynamicTreeBroadPhase_obj::moveProxy( Dynamic proxy,::box2D::collision::B2AABB aabb,::box2D::common::math::B2Vec2 displacement){
{
		HX_SOURCE_PUSH("B2DynamicTreeBroadPhase_obj::moveProxy")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTreeBroadPhase.hx",42)
		bool buffer = this->m_tree->moveProxy(proxy,aabb,displacement);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTreeBroadPhase.hx",43)
		if ((buffer)){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTreeBroadPhase.hx",44)
			this->bufferMove(proxy);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(B2DynamicTreeBroadPhase_obj,moveProxy,(void))

bool B2DynamicTreeBroadPhase_obj::testOverlap( Dynamic proxyA,Dynamic proxyB){
	HX_SOURCE_PUSH("B2DynamicTreeBroadPhase_obj::testOverlap")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTreeBroadPhase.hx",51)
	::box2D::collision::B2AABB aabbA = this->m_tree->getFatAABB(proxyA);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTreeBroadPhase.hx",52)
	::box2D::collision::B2AABB aabbB = this->m_tree->getFatAABB(proxyB);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTreeBroadPhase.hx",53)
	return aabbA->testOverlap(aabbB);
}


HX_DEFINE_DYNAMIC_FUNC2(B2DynamicTreeBroadPhase_obj,testOverlap,return )

Dynamic B2DynamicTreeBroadPhase_obj::getUserData( Dynamic proxy){
	HX_SOURCE_PUSH("B2DynamicTreeBroadPhase_obj::getUserData")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTreeBroadPhase.hx",60)
	return this->m_tree->getUserData(proxy);
}


HX_DEFINE_DYNAMIC_FUNC1(B2DynamicTreeBroadPhase_obj,getUserData,return )

::box2D::collision::B2AABB B2DynamicTreeBroadPhase_obj::getFatAABB( Dynamic proxy){
	HX_SOURCE_PUSH("B2DynamicTreeBroadPhase_obj::getFatAABB")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTreeBroadPhase.hx",68)
	return this->m_tree->getFatAABB(proxy);
}


HX_DEFINE_DYNAMIC_FUNC1(B2DynamicTreeBroadPhase_obj,getFatAABB,return )

int B2DynamicTreeBroadPhase_obj::getProxyCount( ){
	HX_SOURCE_PUSH("B2DynamicTreeBroadPhase_obj::getProxyCount")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTreeBroadPhase.hx",76)
	return this->m_proxyCount;
}


HX_DEFINE_DYNAMIC_FUNC0(B2DynamicTreeBroadPhase_obj,getProxyCount,return )

Void B2DynamicTreeBroadPhase_obj::updatePairs( Dynamic callbackMethod){
{
		HX_SOURCE_PUSH("B2DynamicTreeBroadPhase_obj::updatePairs")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTreeBroadPhase.hx",83)
		Array< ::box2D::collision::B2DynamicTreeBroadPhase > me = Array_obj< ::box2D::collision::B2DynamicTreeBroadPhase >::__new().Add(hx::ObjectPtr<OBJ_>(this));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTreeBroadPhase.hx",85)
		this->m_pairCount = (int)0;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTreeBroadPhase.hx",87)
		{
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTreeBroadPhase.hx",87)
			int _g = (int)0;
			Array< ::box2D::collision::B2DynamicTreeNode > _g1 = this->m_moveBuffer;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTreeBroadPhase.hx",87)
			while(((_g < _g1->length))){
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTreeBroadPhase.hx",87)
				Array< ::box2D::collision::B2DynamicTreeNode > queryProxy = Array_obj< ::box2D::collision::B2DynamicTreeNode >::__new().Add(_g1->__get(_g));
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTreeBroadPhase.hx",87)
				++(_g);

				HX_BEGIN_LOCAL_FUNC_S2(hx::LocalFunc,_Function_3_1,Array< ::box2D::collision::B2DynamicTreeNode >,queryProxy,Array< ::box2D::collision::B2DynamicTreeBroadPhase >,me)
				bool run(::box2D::collision::B2DynamicTreeNode proxy){
{
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTreeBroadPhase.hx",92)
						if (((proxy == queryProxy->__get((int)0)))){
							HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTreeBroadPhase.hx",93)
							return true;
						}
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTreeBroadPhase.hx",96)
						if (((me->__get((int)0)->m_pairCount == me->__get((int)0)->m_pairBuffer->length))){
							HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTreeBroadPhase.hx",97)
							me->__get((int)0)->m_pairBuffer[me->__get((int)0)->m_pairCount] = ::box2D::collision::B2DynamicTreePair_obj::__new();
						}
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTreeBroadPhase.hx",101)
						::box2D::collision::B2DynamicTreePair pair = me->__get((int)0)->m_pairBuffer->__get(me->__get((int)0)->m_pairCount);
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTreeBroadPhase.hx",103)
						if (((proxy->id < queryProxy->__get((int)0)->id))){
							HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTreeBroadPhase.hx",105)
							pair->proxyA = proxy;
							HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTreeBroadPhase.hx",106)
							pair->proxyB = queryProxy->__get((int)0);
						}
						else{
							HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTreeBroadPhase.hx",110)
							pair->proxyA = queryProxy->__get((int)0);
							HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTreeBroadPhase.hx",111)
							pair->proxyB = proxy;
						}
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTreeBroadPhase.hx",116)
						++(me->__get((int)0)->m_pairCount);
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTreeBroadPhase.hx",118)
						return true;
					}
					return null();
				}
				HX_END_LOCAL_FUNC1(return)

				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTreeBroadPhase.hx",89)
				Dynamic queryCallback =  Dynamic(new _Function_3_1(queryProxy,me));
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTreeBroadPhase.hx",122)
				::box2D::collision::B2AABB fatAABB = this->m_tree->getFatAABB(queryProxy->__get((int)0));
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTreeBroadPhase.hx",123)
				this->m_tree->query(queryCallback,fatAABB);
			}
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTreeBroadPhase.hx",127)
		this->m_moveBuffer = Array_obj< ::box2D::collision::B2DynamicTreeNode >::__new();
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTreeBroadPhase.hx",136)
		bool pairing = true;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTreeBroadPhase.hx",137)
		int i = (int)0;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTreeBroadPhase.hx",138)
		while((pairing)){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTreeBroadPhase.hx",139)
			if (((i >= this->m_pairCount))){
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTreeBroadPhase.hx",140)
				pairing = false;
			}
			else{
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTreeBroadPhase.hx",146)
				::box2D::collision::B2DynamicTreePair primaryPair = this->m_pairBuffer->__get(i);
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTreeBroadPhase.hx",147)
				Dynamic userDataA = this->m_tree->getUserData(primaryPair->proxyA);
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTreeBroadPhase.hx",148)
				Dynamic userDataB = this->m_tree->getUserData(primaryPair->proxyB);
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTreeBroadPhase.hx",149)
				callbackMethod(userDataA,userDataB);
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTreeBroadPhase.hx",150)
				++(i);
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTreeBroadPhase.hx",153)
				while(((i < this->m_pairCount))){
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTreeBroadPhase.hx",155)
					::box2D::collision::B2DynamicTreePair pair = this->m_pairBuffer->__get(i);
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTreeBroadPhase.hx",156)
					if (((bool((pair->proxyA != primaryPair->proxyA)) || bool((pair->proxyB != primaryPair->proxyB))))){
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTreeBroadPhase.hx",157)
						break;
					}
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTreeBroadPhase.hx",160)
					++(i);
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2DynamicTreeBroadPhase_obj,updatePairs,(void))

Void B2DynamicTreeBroadPhase_obj::query( Dynamic callbackMethod,::box2D::collision::B2AABB aabb){
{
		HX_SOURCE_PUSH("B2DynamicTreeBroadPhase_obj::query")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTreeBroadPhase.hx",171)
		this->m_tree->query(callbackMethod,aabb);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(B2DynamicTreeBroadPhase_obj,query,(void))

Void B2DynamicTreeBroadPhase_obj::rayCast( Dynamic callbackMethod,::box2D::collision::B2RayCastInput input){
{
		HX_SOURCE_PUSH("B2DynamicTreeBroadPhase_obj::rayCast")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTreeBroadPhase.hx",179)
		this->m_tree->rayCast(callbackMethod,input);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(B2DynamicTreeBroadPhase_obj,rayCast,(void))

Void B2DynamicTreeBroadPhase_obj::validate( ){
{
		HX_SOURCE_PUSH("B2DynamicTreeBroadPhase_obj::validate")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(B2DynamicTreeBroadPhase_obj,validate,(void))

Void B2DynamicTreeBroadPhase_obj::rebalance( int iterations){
{
		HX_SOURCE_PUSH("B2DynamicTreeBroadPhase_obj::rebalance")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTreeBroadPhase.hx",190)
		this->m_tree->rebalance(iterations);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2DynamicTreeBroadPhase_obj,rebalance,(void))

Void B2DynamicTreeBroadPhase_obj::bufferMove( ::box2D::collision::B2DynamicTreeNode proxy){
{
		HX_SOURCE_PUSH("B2DynamicTreeBroadPhase_obj::bufferMove")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTreeBroadPhase.hx",198)
		this->m_moveBuffer[this->m_moveBuffer->length] = proxy;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2DynamicTreeBroadPhase_obj,bufferMove,(void))

Void B2DynamicTreeBroadPhase_obj::unBufferMove( ::box2D::collision::B2DynamicTreeNode proxy){
{
		HX_SOURCE_PUSH("B2DynamicTreeBroadPhase_obj::unBufferMove")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTreeBroadPhase.hx",203)
		this->m_moveBuffer->remove(proxy);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2DynamicTreeBroadPhase_obj,unBufferMove,(void))

int B2DynamicTreeBroadPhase_obj::comparePairs( ::box2D::collision::B2DynamicTreePair pair1,::box2D::collision::B2DynamicTreePair pair2){
	HX_SOURCE_PUSH("B2DynamicTreeBroadPhase_obj::comparePairs")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTreeBroadPhase.hx",208)
	return (int)0;
}


HX_DEFINE_DYNAMIC_FUNC2(B2DynamicTreeBroadPhase_obj,comparePairs,return )


B2DynamicTreeBroadPhase_obj::B2DynamicTreeBroadPhase_obj()
{
}

void B2DynamicTreeBroadPhase_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(B2DynamicTreeBroadPhase);
	HX_MARK_MEMBER_NAME(m_tree,"m_tree");
	HX_MARK_MEMBER_NAME(m_proxyCount,"m_proxyCount");
	HX_MARK_MEMBER_NAME(m_moveBuffer,"m_moveBuffer");
	HX_MARK_MEMBER_NAME(m_pairBuffer,"m_pairBuffer");
	HX_MARK_MEMBER_NAME(m_pairCount,"m_pairCount");
	HX_MARK_END_CLASS();
}

Dynamic B2DynamicTreeBroadPhase_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"query") ) { return query_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"m_tree") ) { return m_tree; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"rayCast") ) { return rayCast_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"validate") ) { return validate_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"moveProxy") ) { return moveProxy_dyn(); }
		if (HX_FIELD_EQ(inName,"rebalance") ) { return rebalance_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"getFatAABB") ) { return getFatAABB_dyn(); }
		if (HX_FIELD_EQ(inName,"bufferMove") ) { return bufferMove_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"createProxy") ) { return createProxy_dyn(); }
		if (HX_FIELD_EQ(inName,"testOverlap") ) { return testOverlap_dyn(); }
		if (HX_FIELD_EQ(inName,"getUserData") ) { return getUserData_dyn(); }
		if (HX_FIELD_EQ(inName,"updatePairs") ) { return updatePairs_dyn(); }
		if (HX_FIELD_EQ(inName,"m_pairCount") ) { return m_pairCount; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"destroyProxy") ) { return destroyProxy_dyn(); }
		if (HX_FIELD_EQ(inName,"unBufferMove") ) { return unBufferMove_dyn(); }
		if (HX_FIELD_EQ(inName,"comparePairs") ) { return comparePairs_dyn(); }
		if (HX_FIELD_EQ(inName,"m_proxyCount") ) { return m_proxyCount; }
		if (HX_FIELD_EQ(inName,"m_moveBuffer") ) { return m_moveBuffer; }
		if (HX_FIELD_EQ(inName,"m_pairBuffer") ) { return m_pairBuffer; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"getProxyCount") ) { return getProxyCount_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic B2DynamicTreeBroadPhase_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"m_tree") ) { m_tree=inValue.Cast< ::box2D::collision::B2DynamicTree >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"m_pairCount") ) { m_pairCount=inValue.Cast< int >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"m_proxyCount") ) { m_proxyCount=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_moveBuffer") ) { m_moveBuffer=inValue.Cast< Array< ::box2D::collision::B2DynamicTreeNode > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_pairBuffer") ) { m_pairBuffer=inValue.Cast< Array< ::box2D::collision::B2DynamicTreePair > >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void B2DynamicTreeBroadPhase_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("m_tree"));
	outFields->push(HX_CSTRING("m_proxyCount"));
	outFields->push(HX_CSTRING("m_moveBuffer"));
	outFields->push(HX_CSTRING("m_pairBuffer"));
	outFields->push(HX_CSTRING("m_pairCount"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("createProxy"),
	HX_CSTRING("destroyProxy"),
	HX_CSTRING("moveProxy"),
	HX_CSTRING("testOverlap"),
	HX_CSTRING("getUserData"),
	HX_CSTRING("getFatAABB"),
	HX_CSTRING("getProxyCount"),
	HX_CSTRING("updatePairs"),
	HX_CSTRING("query"),
	HX_CSTRING("rayCast"),
	HX_CSTRING("validate"),
	HX_CSTRING("rebalance"),
	HX_CSTRING("bufferMove"),
	HX_CSTRING("unBufferMove"),
	HX_CSTRING("comparePairs"),
	HX_CSTRING("m_tree"),
	HX_CSTRING("m_proxyCount"),
	HX_CSTRING("m_moveBuffer"),
	HX_CSTRING("m_pairBuffer"),
	HX_CSTRING("m_pairCount"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class B2DynamicTreeBroadPhase_obj::__mClass;

void B2DynamicTreeBroadPhase_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.collision.B2DynamicTreeBroadPhase"), hx::TCanCast< B2DynamicTreeBroadPhase_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void B2DynamicTreeBroadPhase_obj::__boot()
{
}

} // end namespace box2D
} // end namespace collision
