#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_box2D_collision_B2AABB
#include <box2D/collision/B2AABB.h>
#endif
#ifndef INCLUDED_box2D_collision_B2DynamicTree
#include <box2D/collision/B2DynamicTree.h>
#endif
#ifndef INCLUDED_box2D_collision_B2DynamicTreeNode
#include <box2D/collision/B2DynamicTreeNode.h>
#endif
#ifndef INCLUDED_box2D_collision_B2RayCastInput
#include <box2D/collision/B2RayCastInput.h>
#endif
#ifndef INCLUDED_box2D_common_B2Settings
#include <box2D/common/B2Settings.h>
#endif
#ifndef INCLUDED_box2D_common_math_B2Math
#include <box2D/common/math/B2Math.h>
#endif
#ifndef INCLUDED_box2D_common_math_B2Vec2
#include <box2D/common/math/B2Vec2.h>
#endif
namespace box2D{
namespace collision{

Void B2DynamicTree_obj::__construct()
{
{
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",44)
	this->m_root = null();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",47)
	this->m_freeList = null();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",48)
	this->m_path = (int)0;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",50)
	this->m_insertionCount = (int)0;
}
;
	return null();
}

B2DynamicTree_obj::~B2DynamicTree_obj() { }

Dynamic B2DynamicTree_obj::__CreateEmpty() { return  new B2DynamicTree_obj; }
hx::ObjectPtr< B2DynamicTree_obj > B2DynamicTree_obj::__new()
{  hx::ObjectPtr< B2DynamicTree_obj > result = new B2DynamicTree_obj();
	result->__construct();
	return result;}

Dynamic B2DynamicTree_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2DynamicTree_obj > result = new B2DynamicTree_obj();
	result->__construct();
	return result;}

::box2D::collision::B2DynamicTreeNode B2DynamicTree_obj::createProxy( ::box2D::collision::B2AABB aabb,Dynamic userData){
	HX_SOURCE_PUSH("B2DynamicTree_obj::createProxy")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",80)
	::box2D::collision::B2DynamicTreeNode node = this->allocateNode();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",83)
	double extendX = ::box2D::common::B2Settings_obj::b2_aabbExtension;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",84)
	double extendY = ::box2D::common::B2Settings_obj::b2_aabbExtension;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",85)
	node->aabb->lowerBound->x = (aabb->lowerBound->x - extendX);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",86)
	node->aabb->lowerBound->y = (aabb->lowerBound->y - extendY);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",87)
	node->aabb->upperBound->x = (aabb->upperBound->x + extendX);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",88)
	node->aabb->upperBound->y = (aabb->upperBound->y + extendY);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",90)
	node->userData = userData;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",92)
	this->insertLeaf(node);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",93)
	return node;
}


HX_DEFINE_DYNAMIC_FUNC2(B2DynamicTree_obj,createProxy,return )

Void B2DynamicTree_obj::destroyProxy( ::box2D::collision::B2DynamicTreeNode proxy){
{
		HX_SOURCE_PUSH("B2DynamicTree_obj::destroyProxy")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",102)
		this->removeLeaf(proxy);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",103)
		this->freeNode(proxy);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2DynamicTree_obj,destroyProxy,(void))

bool B2DynamicTree_obj::moveProxy( ::box2D::collision::B2DynamicTreeNode proxy,::box2D::collision::B2AABB aabb,::box2D::common::math::B2Vec2 displacement){
	HX_SOURCE_PUSH("B2DynamicTree_obj::moveProxy")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",113)
	::box2D::common::B2Settings_obj::b2Assert(proxy->isLeaf());
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",115)
	if ((proxy->aabb->contains(aabb))){
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",116)
		return false;
	}
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",120)
	this->removeLeaf(proxy);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",123)
	double extendX = (::box2D::common::B2Settings_obj::b2_aabbExtension + (::box2D::common::B2Settings_obj::b2_aabbMultiplier * ((  (((displacement->x > (int)0))) ? double(displacement->x) : double(-(displacement->x)) ))));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",124)
	double extendY = (::box2D::common::B2Settings_obj::b2_aabbExtension + (::box2D::common::B2Settings_obj::b2_aabbMultiplier * ((  (((displacement->y > (int)0))) ? double(displacement->y) : double(-(displacement->y)) ))));
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",125)
	proxy->aabb->lowerBound->x = (aabb->lowerBound->x - extendX);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",126)
	proxy->aabb->lowerBound->y = (aabb->lowerBound->y - extendY);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",127)
	proxy->aabb->upperBound->x = (aabb->upperBound->x + extendX);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",128)
	proxy->aabb->upperBound->y = (aabb->upperBound->y + extendY);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",130)
	this->insertLeaf(proxy);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",131)
	return true;
}


HX_DEFINE_DYNAMIC_FUNC3(B2DynamicTree_obj,moveProxy,return )

Void B2DynamicTree_obj::rebalance( int iterations){
{
		HX_SOURCE_PUSH("B2DynamicTree_obj::rebalance")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",139)
		if (((this->m_root == null()))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",140)
			return null();
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",142)
		{
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",142)
			int _g = (int)0;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",142)
			while(((_g < iterations))){
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",142)
				int i = (_g)++;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",144)
				::box2D::collision::B2DynamicTreeNode node = this->m_root;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",145)
				int bit = (int)0;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",146)
				while(((node->isLeaf() == false))){
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",148)
					node = (  (((((int((int(this->m_path) >> int(bit))) & int((int)1))) != (int)0))) ? ::box2D::collision::B2DynamicTreeNode(node->child2) : ::box2D::collision::B2DynamicTreeNode(node->child1) );
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",149)
					bit = (int((bit + (int)1)) & int((int)31));
				}
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",151)
				++(this->m_path);
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",153)
				this->removeLeaf(node);
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",154)
				this->insertLeaf(node);
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2DynamicTree_obj,rebalance,(void))

::box2D::collision::B2AABB B2DynamicTree_obj::getFatAABB( ::box2D::collision::B2DynamicTreeNode proxy){
	HX_SOURCE_PUSH("B2DynamicTree_obj::getFatAABB")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",159)
	return proxy->aabb;
}


HX_DEFINE_DYNAMIC_FUNC1(B2DynamicTree_obj,getFatAABB,return )

Dynamic B2DynamicTree_obj::getUserData( ::box2D::collision::B2DynamicTreeNode proxy){
	HX_SOURCE_PUSH("B2DynamicTree_obj::getUserData")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",167)
	return proxy->userData;
}


HX_DEFINE_DYNAMIC_FUNC1(B2DynamicTree_obj,getUserData,return )

Void B2DynamicTree_obj::query( Dynamic callbackMethod,::box2D::collision::B2AABB aabb){
{
		HX_SOURCE_PUSH("B2DynamicTree_obj::query")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",180)
		if (((this->m_root == null()))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",181)
			return null();
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",183)
		Array< ::box2D::collision::B2DynamicTreeNode > stack = Array_obj< ::box2D::collision::B2DynamicTreeNode >::__new();
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",185)
		int count = (int)0;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",186)
		stack[(count)++] = this->m_root;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",188)
		while(((count > (int)0))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",190)
			::box2D::collision::B2DynamicTreeNode node = stack->__get(--(count));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",192)
			if ((node->aabb->testOverlap(aabb))){
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",193)
				if ((node->isLeaf())){
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",196)
					bool proceed = callbackMethod(node).Cast< bool >();
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",197)
					if ((!(proceed))){
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",198)
						return null();
					}
				}
				else{
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",203)
					stack[(count)++] = node->child1;
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",204)
					stack[(count)++] = node->child2;
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(B2DynamicTree_obj,query,(void))

Void B2DynamicTree_obj::rayCast( Dynamic callbackMethod,::box2D::collision::B2RayCastInput input){
{
		HX_SOURCE_PUSH("B2DynamicTree_obj::rayCast")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",223)
		if (((this->m_root == null()))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",224)
			return null();
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",226)
		::box2D::common::math::B2Vec2 p1 = input->p1;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",227)
		::box2D::common::math::B2Vec2 p2 = input->p2;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",228)
		::box2D::common::math::B2Vec2 r = ::box2D::common::math::B2Math_obj::subtractVV(p1,p2);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",230)
		r->normalize();
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",233)
		::box2D::common::math::B2Vec2 v = ::box2D::common::math::B2Math_obj::crossFV(1.0,r);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",234)
		::box2D::common::math::B2Vec2 abs_v = ::box2D::common::math::B2Math_obj::absV(v);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",236)
		double maxFraction = input->maxFraction;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",239)
		::box2D::collision::B2AABB segmentAABB = ::box2D::collision::B2AABB_obj::__new();
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",240)
		double tX;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",241)
		double tY;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",242)
		{
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",243)
			tX = (p1->x + (maxFraction * ((p2->x - p1->x))));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",244)
			tY = (p1->y + (maxFraction * ((p2->y - p1->y))));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",245)
			segmentAABB->lowerBound->x = ::Math_obj::min(p1->x,tX);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",246)
			segmentAABB->lowerBound->y = ::Math_obj::min(p1->y,tY);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",247)
			segmentAABB->upperBound->x = ::Math_obj::max(p1->x,tX);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",248)
			segmentAABB->upperBound->y = ::Math_obj::max(p1->y,tY);
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",251)
		Array< ::box2D::collision::B2DynamicTreeNode > stack = Array_obj< ::box2D::collision::B2DynamicTreeNode >::__new();
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",253)
		int count = (int)0;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",254)
		stack[(count)++] = this->m_root;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",256)
		while(((count > (int)0))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",258)
			::box2D::collision::B2DynamicTreeNode node = stack->__get(--(count));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",260)
			if (((node->aabb->testOverlap(segmentAABB) == false))){
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",261)
				continue;
			}
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",268)
			::box2D::common::math::B2Vec2 c = node->aabb->getCenter();
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",269)
			::box2D::common::math::B2Vec2 h = node->aabb->getExtents();
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",270)
			double separation = ((::Math_obj::abs(((v->x * ((p1->x - c->x))) + (v->y * ((p1->y - c->y))))) - (abs_v->x * h->x)) - (abs_v->y * h->y));
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",272)
			if (((separation > 0.0))){
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",273)
				continue;
			}
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",275)
			if ((node->isLeaf())){
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",277)
				::box2D::collision::B2RayCastInput subInput = ::box2D::collision::B2RayCastInput_obj::__new(null(),null(),null());
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",278)
				subInput->p1 = input->p1;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",279)
				subInput->p2 = input->p2;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",280)
				subInput->maxFraction = input->maxFraction;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",282)
				maxFraction = callbackMethod(subInput,node);
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",284)
				if (((maxFraction == 0.0))){
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",285)
					return null();
				}
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",288)
				{
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",289)
					tX = (p1->x + (maxFraction * ((p2->x - p1->x))));
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",290)
					tY = (p1->y + (maxFraction * ((p2->y - p1->y))));
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",291)
					segmentAABB->lowerBound->x = ::Math_obj::min(p1->x,tX);
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",292)
					segmentAABB->lowerBound->y = ::Math_obj::min(p1->y,tY);
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",293)
					segmentAABB->upperBound->x = ::Math_obj::max(p1->x,tX);
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",294)
					segmentAABB->upperBound->y = ::Math_obj::max(p1->y,tY);
				}
			}
			else{
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",300)
				stack[(count)++] = node->child1;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",301)
				stack[(count)++] = node->child2;
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(B2DynamicTree_obj,rayCast,(void))

::box2D::collision::B2DynamicTreeNode B2DynamicTree_obj::allocateNode( ){
	HX_SOURCE_PUSH("B2DynamicTree_obj::allocateNode")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",310)
	if (((this->m_freeList != null()))){
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",312)
		::box2D::collision::B2DynamicTreeNode node = this->m_freeList;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",313)
		this->m_freeList = node->parent;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",314)
		node->parent = null();
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",315)
		node->child1 = null();
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",316)
		node->child2 = null();
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",317)
		return node;
	}
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",322)
	return ::box2D::collision::B2DynamicTreeNode_obj::__new();
}


HX_DEFINE_DYNAMIC_FUNC0(B2DynamicTree_obj,allocateNode,return )

Void B2DynamicTree_obj::freeNode( ::box2D::collision::B2DynamicTreeNode node){
{
		HX_SOURCE_PUSH("B2DynamicTree_obj::freeNode")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",327)
		node->parent = this->m_freeList;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",328)
		this->m_freeList = node;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2DynamicTree_obj,freeNode,(void))

Void B2DynamicTree_obj::insertLeaf( ::box2D::collision::B2DynamicTreeNode leaf){
{
		HX_SOURCE_PUSH("B2DynamicTree_obj::insertLeaf")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",333)
		++(this->m_insertionCount);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",335)
		if (((this->m_root == null()))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",337)
			this->m_root = leaf;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",338)
			this->m_root->parent = null();
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",339)
			return null();
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",342)
		::box2D::common::math::B2Vec2 center = leaf->aabb->getCenter();
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",343)
		::box2D::collision::B2DynamicTreeNode sibling = this->m_root;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",344)
		if (((sibling->isLeaf() == false))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",345)
			do{
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",348)
				::box2D::collision::B2DynamicTreeNode child1 = sibling->child1;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",349)
				::box2D::collision::B2DynamicTreeNode child2 = sibling->child2;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",356)
				double norm1 = (::Math_obj::abs(((double(((child1->aabb->lowerBound->x + child1->aabb->upperBound->x))) / double((int)2)) - center->x)) + ::Math_obj::abs(((double(((child1->aabb->lowerBound->y + child1->aabb->upperBound->y))) / double((int)2)) - center->y)));
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",358)
				double norm2 = (::Math_obj::abs(((double(((child2->aabb->lowerBound->x + child2->aabb->upperBound->x))) / double((int)2)) - center->x)) + ::Math_obj::abs(((double(((child2->aabb->lowerBound->y + child2->aabb->upperBound->y))) / double((int)2)) - center->y)));
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",361)
				if (((norm1 < norm2))){
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",362)
					sibling = child1;
				}
				else{
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",364)
					sibling = child2;
				}
			}
while(((sibling->isLeaf() == false)));
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",372)
		::box2D::collision::B2DynamicTreeNode node1 = sibling->parent;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",373)
		::box2D::collision::B2DynamicTreeNode node2 = this->allocateNode();
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",374)
		node2->parent = node1;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",375)
		node2->userData = null();
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",376)
		node2->aabb->combine(leaf->aabb,sibling->aabb);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",377)
		if (((node1 != null()))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",379)
			if (((sibling->parent->child1 == sibling))){
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",380)
				node1->child1 = node2;
			}
			else{
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",384)
				node1->child2 = node2;
			}
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",388)
			node2->child1 = sibling;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",389)
			node2->child2 = leaf;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",390)
			sibling->parent = node2;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",391)
			leaf->parent = node2;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",392)
			do{
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",394)
				if ((node1->aabb->contains(node2->aabb))){
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",395)
					break;
				}
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",397)
				node1->aabb->combine(node1->child1->aabb,node1->child2->aabb);
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",398)
				node2 = node1;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",399)
				node1 = node1->parent;
			}
while(((node1 != null())));
		}
		else{
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",405)
			node2->child1 = sibling;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",406)
			node2->child2 = leaf;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",407)
			sibling->parent = node2;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",408)
			leaf->parent = node2;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",409)
			this->m_root = node2;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2DynamicTree_obj,insertLeaf,(void))

Void B2DynamicTree_obj::removeLeaf( ::box2D::collision::B2DynamicTreeNode leaf){
{
		HX_SOURCE_PUSH("B2DynamicTree_obj::removeLeaf")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",416)
		if (((leaf == this->m_root))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",418)
			this->m_root = null();
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",419)
			return null();
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",422)
		::box2D::collision::B2DynamicTreeNode node2 = leaf->parent;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",423)
		::box2D::collision::B2DynamicTreeNode node1 = node2->parent;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",424)
		::box2D::collision::B2DynamicTreeNode sibling;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",425)
		if (((node2->child1 == leaf))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",426)
			sibling = node2->child2;
		}
		else{
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",430)
			sibling = node2->child1;
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",434)
		if (((node1 != null()))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",437)
			if (((node1->child1 == node2))){
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",438)
				node1->child1 = sibling;
			}
			else{
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",442)
				node1->child2 = sibling;
			}
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",445)
			sibling->parent = node1;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",446)
			this->freeNode(node2);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",449)
			while(((node1 != null()))){
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",451)
				::box2D::collision::B2AABB oldAABB = node1->aabb;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",453)
				node1->aabb = ::box2D::collision::B2AABB_obj::__new();
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",454)
				node1->aabb->combine(node1->child1->aabb,node1->child2->aabb);
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",456)
				if ((oldAABB->contains(node1->aabb))){
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",457)
					break;
				}
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",459)
				node1 = node1->parent;
			}
		}
		else{
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",464)
			this->m_root = sibling;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",465)
			sibling->parent = null();
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTree.hx",466)
			this->freeNode(node2);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2DynamicTree_obj,removeLeaf,(void))


B2DynamicTree_obj::B2DynamicTree_obj()
{
}

void B2DynamicTree_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(B2DynamicTree);
	HX_MARK_MEMBER_NAME(m_root,"m_root");
	HX_MARK_MEMBER_NAME(m_freeList,"m_freeList");
	HX_MARK_MEMBER_NAME(m_path,"m_path");
	HX_MARK_MEMBER_NAME(m_insertionCount,"m_insertionCount");
	HX_MARK_END_CLASS();
}

Dynamic B2DynamicTree_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"query") ) { return query_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"m_root") ) { return m_root; }
		if (HX_FIELD_EQ(inName,"m_path") ) { return m_path; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"rayCast") ) { return rayCast_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"freeNode") ) { return freeNode_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"moveProxy") ) { return moveProxy_dyn(); }
		if (HX_FIELD_EQ(inName,"rebalance") ) { return rebalance_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"getFatAABB") ) { return getFatAABB_dyn(); }
		if (HX_FIELD_EQ(inName,"insertLeaf") ) { return insertLeaf_dyn(); }
		if (HX_FIELD_EQ(inName,"removeLeaf") ) { return removeLeaf_dyn(); }
		if (HX_FIELD_EQ(inName,"m_freeList") ) { return m_freeList; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"createProxy") ) { return createProxy_dyn(); }
		if (HX_FIELD_EQ(inName,"getUserData") ) { return getUserData_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"destroyProxy") ) { return destroyProxy_dyn(); }
		if (HX_FIELD_EQ(inName,"allocateNode") ) { return allocateNode_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"m_insertionCount") ) { return m_insertionCount; }
	}
	return super::__Field(inName);
}

Dynamic B2DynamicTree_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"m_root") ) { m_root=inValue.Cast< ::box2D::collision::B2DynamicTreeNode >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_path") ) { m_path=inValue.Cast< int >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"m_freeList") ) { m_freeList=inValue.Cast< ::box2D::collision::B2DynamicTreeNode >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"m_insertionCount") ) { m_insertionCount=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void B2DynamicTree_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("m_root"));
	outFields->push(HX_CSTRING("m_freeList"));
	outFields->push(HX_CSTRING("m_path"));
	outFields->push(HX_CSTRING("m_insertionCount"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("createProxy"),
	HX_CSTRING("destroyProxy"),
	HX_CSTRING("moveProxy"),
	HX_CSTRING("rebalance"),
	HX_CSTRING("getFatAABB"),
	HX_CSTRING("getUserData"),
	HX_CSTRING("query"),
	HX_CSTRING("rayCast"),
	HX_CSTRING("allocateNode"),
	HX_CSTRING("freeNode"),
	HX_CSTRING("insertLeaf"),
	HX_CSTRING("removeLeaf"),
	HX_CSTRING("m_root"),
	HX_CSTRING("m_freeList"),
	HX_CSTRING("m_path"),
	HX_CSTRING("m_insertionCount"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class B2DynamicTree_obj::__mClass;

void B2DynamicTree_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.collision.B2DynamicTree"), hx::TCanCast< B2DynamicTree_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void B2DynamicTree_obj::__boot()
{
}

} // end namespace box2D
} // end namespace collision
