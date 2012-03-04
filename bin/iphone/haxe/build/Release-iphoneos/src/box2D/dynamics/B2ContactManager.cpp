#include <hxcpp.h>

#ifndef INCLUDED_box2D_collision_B2ContactPoint
#include <box2D/collision/B2ContactPoint.h>
#endif
#ifndef INCLUDED_box2D_collision_B2DynamicTreeBroadPhase
#include <box2D/collision/B2DynamicTreeBroadPhase.h>
#endif
#ifndef INCLUDED_box2D_collision_IBroadPhase
#include <box2D/collision/IBroadPhase.h>
#endif
#ifndef INCLUDED_box2D_dynamics_B2Body
#include <box2D/dynamics/B2Body.h>
#endif
#ifndef INCLUDED_box2D_dynamics_B2ContactFilter
#include <box2D/dynamics/B2ContactFilter.h>
#endif
#ifndef INCLUDED_box2D_dynamics_B2ContactListener
#include <box2D/dynamics/B2ContactListener.h>
#endif
#ifndef INCLUDED_box2D_dynamics_B2ContactManager
#include <box2D/dynamics/B2ContactManager.h>
#endif
#ifndef INCLUDED_box2D_dynamics_B2Fixture
#include <box2D/dynamics/B2Fixture.h>
#endif
#ifndef INCLUDED_box2D_dynamics_B2World
#include <box2D/dynamics/B2World.h>
#endif
#ifndef INCLUDED_box2D_dynamics_contacts_B2Contact
#include <box2D/dynamics/contacts/B2Contact.h>
#endif
#ifndef INCLUDED_box2D_dynamics_contacts_B2ContactEdge
#include <box2D/dynamics/contacts/B2ContactEdge.h>
#endif
#ifndef INCLUDED_box2D_dynamics_contacts_B2ContactFactory
#include <box2D/dynamics/contacts/B2ContactFactory.h>
#endif
namespace box2D{
namespace dynamics{

Void B2ContactManager_obj::__construct()
{
{
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2ContactManager.hx",37)
	this->m_world = null();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2ContactManager.hx",38)
	this->m_contactCount = (int)0;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2ContactManager.hx",39)
	this->m_contactFilter = ::box2D::dynamics::B2ContactFilter_obj::b2_defaultFilter;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2ContactManager.hx",40)
	this->m_contactListener = ::box2D::dynamics::B2ContactListener_obj::b2_defaultListener;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2ContactManager.hx",41)
	this->m_contactFactory = ::box2D::dynamics::contacts::B2ContactFactory_obj::__new(this->m_allocator);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2ContactManager.hx",42)
	this->m_broadPhase = ::box2D::collision::B2DynamicTreeBroadPhase_obj::__new();
}
;
	return null();
}

B2ContactManager_obj::~B2ContactManager_obj() { }

Dynamic B2ContactManager_obj::__CreateEmpty() { return  new B2ContactManager_obj; }
hx::ObjectPtr< B2ContactManager_obj > B2ContactManager_obj::__new()
{  hx::ObjectPtr< B2ContactManager_obj > result = new B2ContactManager_obj();
	result->__construct();
	return result;}

Dynamic B2ContactManager_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2ContactManager_obj > result = new B2ContactManager_obj();
	result->__construct();
	return result;}

Void B2ContactManager_obj::addPair( Dynamic proxyUserDataA,Dynamic proxyUserDataB){
{
		HX_SOURCE_PUSH("B2ContactManager_obj::addPair")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2ContactManager.hx",48)
		::box2D::dynamics::B2Fixture fixtureA = hx::TCast< box2D::dynamics::B2Fixture >::cast(proxyUserDataA);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2ContactManager.hx",49)
		::box2D::dynamics::B2Fixture fixtureB = hx::TCast< box2D::dynamics::B2Fixture >::cast(proxyUserDataB);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2ContactManager.hx",51)
		::box2D::dynamics::B2Body bodyA = fixtureA->getBody();
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2ContactManager.hx",52)
		::box2D::dynamics::B2Body bodyB = fixtureB->getBody();
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2ContactManager.hx",55)
		if (((bodyA == bodyB))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2ContactManager.hx",56)
			return null();
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2ContactManager.hx",59)
		::box2D::dynamics::contacts::B2ContactEdge edge = bodyB->getContactList();
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2ContactManager.hx",60)
		while(((edge != null()))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2ContactManager.hx",62)
			if (((edge->other == bodyA))){
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2ContactManager.hx",64)
				::box2D::dynamics::B2Fixture fA = edge->contact->getFixtureA();
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2ContactManager.hx",65)
				::box2D::dynamics::B2Fixture fB = edge->contact->getFixtureB();
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2ContactManager.hx",66)
				if (((bool((fA == fixtureA)) && bool((fB == fixtureB))))){
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2ContactManager.hx",67)
					return null();
				}
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2ContactManager.hx",68)
				if (((bool((fA == fixtureB)) && bool((fB == fixtureA))))){
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2ContactManager.hx",69)
					return null();
				}
			}
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2ContactManager.hx",71)
			edge = edge->next;
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2ContactManager.hx",75)
		if (((bodyB->shouldCollide(bodyA) == false))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2ContactManager.hx",76)
			return null();
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2ContactManager.hx",81)
		if (((this->m_contactFilter->shouldCollide(fixtureA,fixtureB) == false))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2ContactManager.hx",82)
			return null();
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2ContactManager.hx",87)
		::box2D::dynamics::contacts::B2Contact c = this->m_contactFactory->create(fixtureA,fixtureB);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2ContactManager.hx",90)
		fixtureA = c->getFixtureA();
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2ContactManager.hx",91)
		fixtureB = c->getFixtureB();
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2ContactManager.hx",92)
		bodyA = fixtureA->m_body;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2ContactManager.hx",93)
		bodyB = fixtureB->m_body;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2ContactManager.hx",96)
		c->m_prev = null();
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2ContactManager.hx",97)
		c->m_next = this->m_world->m_contactList;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2ContactManager.hx",98)
		if (((this->m_world->m_contactList != null()))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2ContactManager.hx",99)
			this->m_world->m_contactList->m_prev = c;
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2ContactManager.hx",102)
		this->m_world->m_contactList = c;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2ContactManager.hx",108)
		c->m_nodeA->contact = c;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2ContactManager.hx",109)
		c->m_nodeA->other = bodyB;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2ContactManager.hx",111)
		c->m_nodeA->prev = null();
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2ContactManager.hx",112)
		c->m_nodeA->next = bodyA->m_contactList;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2ContactManager.hx",113)
		if (((bodyA->m_contactList != null()))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2ContactManager.hx",114)
			bodyA->m_contactList->prev = c->m_nodeA;
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2ContactManager.hx",117)
		bodyA->m_contactList = c->m_nodeA;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2ContactManager.hx",120)
		c->m_nodeB->contact = c;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2ContactManager.hx",121)
		c->m_nodeB->other = bodyA;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2ContactManager.hx",123)
		c->m_nodeB->prev = null();
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2ContactManager.hx",124)
		c->m_nodeB->next = bodyB->m_contactList;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2ContactManager.hx",125)
		if (((bodyB->m_contactList != null()))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2ContactManager.hx",126)
			bodyB->m_contactList->prev = c->m_nodeB;
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2ContactManager.hx",129)
		bodyB->m_contactList = c->m_nodeB;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2ContactManager.hx",131)
		++(this->m_world->m_contactCount);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2ContactManager.hx",132)
		return null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(B2ContactManager_obj,addPair,(void))

Void B2ContactManager_obj::findNewContacts( ){
{
		HX_SOURCE_PUSH("B2ContactManager_obj::findNewContacts")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2ContactManager.hx",137)
		this->m_broadPhase->updatePairs(this->addPair_dyn());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(B2ContactManager_obj,findNewContacts,(void))

Void B2ContactManager_obj::destroy( ::box2D::dynamics::contacts::B2Contact c){
{
		HX_SOURCE_PUSH("B2ContactManager_obj::destroy")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2ContactManager.hx",145)
		::box2D::dynamics::B2Fixture fixtureA = c->getFixtureA();
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2ContactManager.hx",146)
		::box2D::dynamics::B2Fixture fixtureB = c->getFixtureB();
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2ContactManager.hx",147)
		::box2D::dynamics::B2Body bodyA = fixtureA->getBody();
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2ContactManager.hx",148)
		::box2D::dynamics::B2Body bodyB = fixtureB->getBody();
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2ContactManager.hx",150)
		if ((c->isTouching())){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2ContactManager.hx",151)
			this->m_contactListener->endContact(c);
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2ContactManager.hx",156)
		if (((c->m_prev != null()))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2ContactManager.hx",157)
			c->m_prev->m_next = c->m_next;
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2ContactManager.hx",161)
		if (((c->m_next != null()))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2ContactManager.hx",162)
			c->m_next->m_prev = c->m_prev;
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2ContactManager.hx",166)
		if (((c == this->m_world->m_contactList))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2ContactManager.hx",167)
			this->m_world->m_contactList = c->m_next;
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2ContactManager.hx",172)
		if (((c->m_nodeA->prev != null()))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2ContactManager.hx",173)
			c->m_nodeA->prev->next = c->m_nodeA->next;
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2ContactManager.hx",177)
		if (((c->m_nodeA->next != null()))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2ContactManager.hx",178)
			c->m_nodeA->next->prev = c->m_nodeA->prev;
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2ContactManager.hx",182)
		if (((c->m_nodeA == bodyA->m_contactList))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2ContactManager.hx",183)
			bodyA->m_contactList = c->m_nodeA->next;
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2ContactManager.hx",188)
		if (((c->m_nodeB->prev != null()))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2ContactManager.hx",189)
			c->m_nodeB->prev->next = c->m_nodeB->next;
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2ContactManager.hx",193)
		if (((c->m_nodeB->next != null()))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2ContactManager.hx",194)
			c->m_nodeB->next->prev = c->m_nodeB->prev;
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2ContactManager.hx",198)
		if (((c->m_nodeB == bodyB->m_contactList))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2ContactManager.hx",199)
			bodyB->m_contactList = c->m_nodeB->next;
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2ContactManager.hx",204)
		this->m_contactFactory->destroy(c);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2ContactManager.hx",205)
		--(this->m_contactCount);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2ContactManager_obj,destroy,(void))

Void B2ContactManager_obj::collide( ){
{
		HX_SOURCE_PUSH("B2ContactManager_obj::collide")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2ContactManager.hx",215)
		::box2D::dynamics::contacts::B2Contact c = this->m_world->m_contactList;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2ContactManager.hx",216)
		while(((c != null()))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2ContactManager.hx",218)
			::box2D::dynamics::B2Fixture fixtureA = c->getFixtureA();
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2ContactManager.hx",219)
			::box2D::dynamics::B2Fixture fixtureB = c->getFixtureB();
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2ContactManager.hx",220)
			::box2D::dynamics::B2Body bodyA = fixtureA->getBody();
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2ContactManager.hx",221)
			::box2D::dynamics::B2Body bodyB = fixtureB->getBody();
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2ContactManager.hx",222)
			if (((bool((bodyA->isAwake() == false)) && bool((bodyB->isAwake() == false))))){
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2ContactManager.hx",224)
				c = c->getNext();
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2ContactManager.hx",225)
				continue;
			}
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2ContactManager.hx",229)
			if (((((int(c->m_flags) & int(::box2D::dynamics::contacts::B2Contact_obj::e_filterFlag))) != (int)0))){
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2ContactManager.hx",232)
				if (((bodyB->shouldCollide(bodyA) == false))){
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2ContactManager.hx",234)
					::box2D::dynamics::contacts::B2Contact cNuke = c;
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2ContactManager.hx",235)
					c = cNuke->getNext();
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2ContactManager.hx",236)
					this->destroy(cNuke);
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2ContactManager.hx",237)
					continue;
				}
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2ContactManager.hx",241)
				if (((this->m_contactFilter->shouldCollide(fixtureA,fixtureB) == false))){
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2ContactManager.hx",243)
					::box2D::dynamics::contacts::B2Contact cNuke = c;
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2ContactManager.hx",244)
					c = cNuke->getNext();
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2ContactManager.hx",245)
					this->destroy(cNuke);
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2ContactManager.hx",246)
					continue;
				}
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2ContactManager.hx",250)
				hx::AndEq(c->m_flags,~(int)(::box2D::dynamics::contacts::B2Contact_obj::e_filterFlag));
			}
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2ContactManager.hx",253)
			Dynamic proxyA = fixtureA->m_proxy;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2ContactManager.hx",254)
			Dynamic proxyB = fixtureB->m_proxy;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2ContactManager.hx",256)
			bool overlap = this->m_broadPhase->testOverlap(proxyA,proxyB);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2ContactManager.hx",259)
			if (((overlap == false))){
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2ContactManager.hx",261)
				::box2D::dynamics::contacts::B2Contact cNuke = c;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2ContactManager.hx",262)
				c = cNuke->getNext();
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2ContactManager.hx",263)
				this->destroy(cNuke);
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2ContactManager.hx",264)
				continue;
			}
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2ContactManager.hx",267)
			c->update(this->m_contactListener);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2ContactManager.hx",268)
			c = c->getNext();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(B2ContactManager_obj,collide,(void))

::box2D::collision::B2ContactPoint B2ContactManager_obj::s_evalCP;


B2ContactManager_obj::B2ContactManager_obj()
{
}

void B2ContactManager_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(B2ContactManager);
	HX_MARK_MEMBER_NAME(m_world,"m_world");
	HX_MARK_MEMBER_NAME(m_broadPhase,"m_broadPhase");
	HX_MARK_MEMBER_NAME(m_contactList,"m_contactList");
	HX_MARK_MEMBER_NAME(m_contactCount,"m_contactCount");
	HX_MARK_MEMBER_NAME(m_contactFilter,"m_contactFilter");
	HX_MARK_MEMBER_NAME(m_contactListener,"m_contactListener");
	HX_MARK_MEMBER_NAME(m_contactFactory,"m_contactFactory");
	HX_MARK_MEMBER_NAME(m_allocator,"m_allocator");
	HX_MARK_END_CLASS();
}

Dynamic B2ContactManager_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"addPair") ) { return addPair_dyn(); }
		if (HX_FIELD_EQ(inName,"destroy") ) { return destroy_dyn(); }
		if (HX_FIELD_EQ(inName,"collide") ) { return collide_dyn(); }
		if (HX_FIELD_EQ(inName,"m_world") ) { return m_world; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"s_evalCP") ) { return s_evalCP; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"m_allocator") ) { return m_allocator; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"m_broadPhase") ) { return m_broadPhase; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"m_contactList") ) { return m_contactList; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"m_contactCount") ) { return m_contactCount; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"findNewContacts") ) { return findNewContacts_dyn(); }
		if (HX_FIELD_EQ(inName,"m_contactFilter") ) { return m_contactFilter; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"m_contactFactory") ) { return m_contactFactory; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"m_contactListener") ) { return m_contactListener; }
	}
	return super::__Field(inName);
}

Dynamic B2ContactManager_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"m_world") ) { m_world=inValue.Cast< ::box2D::dynamics::B2World >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"s_evalCP") ) { s_evalCP=inValue.Cast< ::box2D::collision::B2ContactPoint >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"m_allocator") ) { m_allocator=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"m_broadPhase") ) { m_broadPhase=inValue.Cast< ::box2D::collision::IBroadPhase >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"m_contactList") ) { m_contactList=inValue.Cast< ::box2D::dynamics::contacts::B2Contact >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"m_contactCount") ) { m_contactCount=inValue.Cast< int >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"m_contactFilter") ) { m_contactFilter=inValue.Cast< ::box2D::dynamics::B2ContactFilter >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"m_contactFactory") ) { m_contactFactory=inValue.Cast< ::box2D::dynamics::contacts::B2ContactFactory >(); return inValue; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"m_contactListener") ) { m_contactListener=inValue.Cast< ::box2D::dynamics::B2ContactListener >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void B2ContactManager_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("m_world"));
	outFields->push(HX_CSTRING("m_broadPhase"));
	outFields->push(HX_CSTRING("m_contactList"));
	outFields->push(HX_CSTRING("m_contactCount"));
	outFields->push(HX_CSTRING("m_contactFilter"));
	outFields->push(HX_CSTRING("m_contactListener"));
	outFields->push(HX_CSTRING("m_contactFactory"));
	outFields->push(HX_CSTRING("m_allocator"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("s_evalCP"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("addPair"),
	HX_CSTRING("findNewContacts"),
	HX_CSTRING("destroy"),
	HX_CSTRING("collide"),
	HX_CSTRING("m_world"),
	HX_CSTRING("m_broadPhase"),
	HX_CSTRING("m_contactList"),
	HX_CSTRING("m_contactCount"),
	HX_CSTRING("m_contactFilter"),
	HX_CSTRING("m_contactListener"),
	HX_CSTRING("m_contactFactory"),
	HX_CSTRING("m_allocator"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(B2ContactManager_obj::s_evalCP,"s_evalCP");
};

Class B2ContactManager_obj::__mClass;

void B2ContactManager_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.dynamics.B2ContactManager"), hx::TCanCast< B2ContactManager_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void B2ContactManager_obj::__boot()
{
	hx::Static(s_evalCP) = ::box2D::collision::B2ContactPoint_obj::__new();
}

} // end namespace box2D
} // end namespace dynamics
