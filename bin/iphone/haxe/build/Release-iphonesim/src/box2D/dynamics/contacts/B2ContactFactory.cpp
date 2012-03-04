#include <hxcpp.h>

#ifndef INCLUDED_box2D_collision_B2Manifold
#include <box2D/collision/B2Manifold.h>
#endif
#ifndef INCLUDED_box2D_collision_shapes_B2Shape
#include <box2D/collision/shapes/B2Shape.h>
#endif
#ifndef INCLUDED_box2D_dynamics_B2Body
#include <box2D/dynamics/B2Body.h>
#endif
#ifndef INCLUDED_box2D_dynamics_B2Fixture
#include <box2D/dynamics/B2Fixture.h>
#endif
#ifndef INCLUDED_box2D_dynamics_contacts_B2CircleContact
#include <box2D/dynamics/contacts/B2CircleContact.h>
#endif
#ifndef INCLUDED_box2D_dynamics_contacts_B2Contact
#include <box2D/dynamics/contacts/B2Contact.h>
#endif
#ifndef INCLUDED_box2D_dynamics_contacts_B2ContactFactory
#include <box2D/dynamics/contacts/B2ContactFactory.h>
#endif
#ifndef INCLUDED_box2D_dynamics_contacts_B2ContactRegister
#include <box2D/dynamics/contacts/B2ContactRegister.h>
#endif
#ifndef INCLUDED_box2D_dynamics_contacts_B2EdgeAndCircleContact
#include <box2D/dynamics/contacts/B2EdgeAndCircleContact.h>
#endif
#ifndef INCLUDED_box2D_dynamics_contacts_B2PolyAndCircleContact
#include <box2D/dynamics/contacts/B2PolyAndCircleContact.h>
#endif
#ifndef INCLUDED_box2D_dynamics_contacts_B2PolyAndEdgeContact
#include <box2D/dynamics/contacts/B2PolyAndEdgeContact.h>
#endif
#ifndef INCLUDED_box2D_dynamics_contacts_B2PolygonContact
#include <box2D/dynamics/contacts/B2PolygonContact.h>
#endif
namespace box2D{
namespace dynamics{
namespace contacts{

Void B2ContactFactory_obj::__construct(Dynamic allocator)
{
{
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactFactory.hx",39)
	this->m_allocator = allocator;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactFactory.hx",40)
	this->initializeRegisters();
}
;
	return null();
}

B2ContactFactory_obj::~B2ContactFactory_obj() { }

Dynamic B2ContactFactory_obj::__CreateEmpty() { return  new B2ContactFactory_obj; }
hx::ObjectPtr< B2ContactFactory_obj > B2ContactFactory_obj::__new(Dynamic allocator)
{  hx::ObjectPtr< B2ContactFactory_obj > result = new B2ContactFactory_obj();
	result->__construct(allocator);
	return result;}

Dynamic B2ContactFactory_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2ContactFactory_obj > result = new B2ContactFactory_obj();
	result->__construct(inArgs[0]);
	return result;}

Void B2ContactFactory_obj::addType( Dynamic createFcn,Dynamic destroyFcn,int type1,int type2){
{
		HX_SOURCE_PUSH("B2ContactFactory_obj::addType")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactFactory.hx",48)
		this->m_registers->__get(type1)->__get(type2)->createFcn = createFcn;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactFactory.hx",49)
		this->m_registers->__get(type1)->__get(type2)->destroyFcn = destroyFcn;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactFactory.hx",50)
		this->m_registers->__get(type1)->__get(type2)->primary = true;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactFactory.hx",52)
		if (((type1 != type2))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactFactory.hx",54)
			this->m_registers->__get(type2)->__get(type1)->createFcn = createFcn;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactFactory.hx",55)
			this->m_registers->__get(type2)->__get(type1)->destroyFcn = destroyFcn;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactFactory.hx",56)
			this->m_registers->__get(type2)->__get(type1)->primary = false;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(B2ContactFactory_obj,addType,(void))

Void B2ContactFactory_obj::initializeRegisters( ){
{
		HX_SOURCE_PUSH("B2ContactFactory_obj::initializeRegisters")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactFactory.hx",60)
		this->m_registers = Array_obj< Array< ::box2D::dynamics::contacts::B2ContactRegister > >::__new();
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactFactory.hx",61)
		{
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactFactory.hx",61)
			int _g1 = (int)0;
			int _g = ::box2D::collision::shapes::B2Shape_obj::e_shapeTypeCount;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactFactory.hx",61)
			while(((_g1 < _g))){
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactFactory.hx",61)
				int i = (_g1)++;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactFactory.hx",62)
				this->m_registers[i] = Array_obj< ::box2D::dynamics::contacts::B2ContactRegister >::__new();
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactFactory.hx",63)
				{
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactFactory.hx",63)
					int _g3 = (int)0;
					int _g2 = ::box2D::collision::shapes::B2Shape_obj::e_shapeTypeCount;
					HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactFactory.hx",63)
					while(((_g3 < _g2))){
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactFactory.hx",63)
						int j = (_g3)++;
						HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactFactory.hx",64)
						this->m_registers->__get(i)[j] = ::box2D::dynamics::contacts::B2ContactRegister_obj::__new();
					}
				}
			}
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactFactory.hx",68)
		this->addType(::box2D::dynamics::contacts::B2CircleContact_obj::create_dyn(),::box2D::dynamics::contacts::B2CircleContact_obj::destroy_dyn(),::box2D::collision::shapes::B2Shape_obj::e_circleShape,::box2D::collision::shapes::B2Shape_obj::e_circleShape);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactFactory.hx",69)
		this->addType(::box2D::dynamics::contacts::B2PolyAndCircleContact_obj::create_dyn(),::box2D::dynamics::contacts::B2PolyAndCircleContact_obj::destroy_dyn(),::box2D::collision::shapes::B2Shape_obj::e_polygonShape,::box2D::collision::shapes::B2Shape_obj::e_circleShape);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactFactory.hx",70)
		this->addType(::box2D::dynamics::contacts::B2PolygonContact_obj::create_dyn(),::box2D::dynamics::contacts::B2PolygonContact_obj::destroy_dyn(),::box2D::collision::shapes::B2Shape_obj::e_polygonShape,::box2D::collision::shapes::B2Shape_obj::e_polygonShape);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactFactory.hx",72)
		this->addType(::box2D::dynamics::contacts::B2EdgeAndCircleContact_obj::create_dyn(),::box2D::dynamics::contacts::B2EdgeAndCircleContact_obj::destroy_dyn(),::box2D::collision::shapes::B2Shape_obj::e_edgeShape,::box2D::collision::shapes::B2Shape_obj::e_circleShape);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactFactory.hx",73)
		this->addType(::box2D::dynamics::contacts::B2PolyAndEdgeContact_obj::create_dyn(),::box2D::dynamics::contacts::B2PolyAndEdgeContact_obj::destroy_dyn(),::box2D::collision::shapes::B2Shape_obj::e_polygonShape,::box2D::collision::shapes::B2Shape_obj::e_edgeShape);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(B2ContactFactory_obj,initializeRegisters,(void))

::box2D::dynamics::contacts::B2Contact B2ContactFactory_obj::create( ::box2D::dynamics::B2Fixture fixtureA,::box2D::dynamics::B2Fixture fixtureB){
	HX_SOURCE_PUSH("B2ContactFactory_obj::create")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactFactory.hx",76)
	int type1 = fixtureA->getType();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactFactory.hx",77)
	int type2 = fixtureB->getType();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactFactory.hx",82)
	::box2D::dynamics::contacts::B2ContactRegister reg = this->m_registers->__get(type1)->__get(type2);
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactFactory.hx",84)
	::box2D::dynamics::contacts::B2Contact c;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactFactory.hx",86)
	if (((reg->pool != null()))){
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactFactory.hx",89)
		c = reg->pool;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactFactory.hx",90)
		reg->pool = c->m_next;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactFactory.hx",91)
		(reg->poolCount)--;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactFactory.hx",92)
		c->reset(fixtureA,fixtureB);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactFactory.hx",93)
		return c;
	}
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactFactory.hx",96)
	Dynamic createFcn = reg->createFcn;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactFactory.hx",97)
	if (((createFcn != null()))){
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactFactory.hx",98)
		if ((reg->primary)){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactFactory.hx",101)
			c = createFcn(this->m_allocator);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactFactory.hx",102)
			c->reset(fixtureA,fixtureB);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactFactory.hx",103)
			return c;
		}
		else{
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactFactory.hx",107)
			c = createFcn(this->m_allocator);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactFactory.hx",108)
			c->reset(fixtureB,fixtureA);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactFactory.hx",109)
			return c;
		}
	}
	else{
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactFactory.hx",113)
		return null();
	}
}


HX_DEFINE_DYNAMIC_FUNC2(B2ContactFactory_obj,create,return )

Void B2ContactFactory_obj::destroy( ::box2D::dynamics::contacts::B2Contact contact){
{
		HX_SOURCE_PUSH("B2ContactFactory_obj::destroy")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactFactory.hx",118)
		if (((contact->m_manifold->m_pointCount > (int)0))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactFactory.hx",120)
			contact->m_fixtureA->m_body->setAwake(true);
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactFactory.hx",121)
			contact->m_fixtureB->m_body->setAwake(true);
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactFactory.hx",124)
		int type1 = contact->m_fixtureA->getType();
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactFactory.hx",125)
		int type2 = contact->m_fixtureB->getType();
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactFactory.hx",130)
		::box2D::dynamics::contacts::B2ContactRegister reg = this->m_registers->__get(type1)->__get(type2);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactFactory.hx",133)
		{
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactFactory.hx",134)
			(reg->poolCount)++;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactFactory.hx",135)
			contact->m_next = reg->pool;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactFactory.hx",136)
			reg->pool = contact;
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactFactory.hx",139)
		Dynamic destroyFcn = reg->destroyFcn;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/contacts/B2ContactFactory.hx",140)
		destroyFcn(contact,this->m_allocator);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2ContactFactory_obj,destroy,(void))


B2ContactFactory_obj::B2ContactFactory_obj()
{
}

void B2ContactFactory_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(B2ContactFactory);
	HX_MARK_MEMBER_NAME(m_registers,"m_registers");
	HX_MARK_MEMBER_NAME(m_allocator,"m_allocator");
	HX_MARK_END_CLASS();
}

Dynamic B2ContactFactory_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"create") ) { return create_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"addType") ) { return addType_dyn(); }
		if (HX_FIELD_EQ(inName,"destroy") ) { return destroy_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"m_registers") ) { return m_registers; }
		if (HX_FIELD_EQ(inName,"m_allocator") ) { return m_allocator; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"initializeRegisters") ) { return initializeRegisters_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic B2ContactFactory_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 11:
		if (HX_FIELD_EQ(inName,"m_registers") ) { m_registers=inValue.Cast< Array< Array< ::box2D::dynamics::contacts::B2ContactRegister > > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_allocator") ) { m_allocator=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void B2ContactFactory_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("m_registers"));
	outFields->push(HX_CSTRING("m_allocator"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("addType"),
	HX_CSTRING("initializeRegisters"),
	HX_CSTRING("create"),
	HX_CSTRING("destroy"),
	HX_CSTRING("m_registers"),
	HX_CSTRING("m_allocator"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class B2ContactFactory_obj::__mClass;

void B2ContactFactory_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.dynamics.contacts.B2ContactFactory"), hx::TCanCast< B2ContactFactory_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void B2ContactFactory_obj::__boot()
{
}

} // end namespace box2D
} // end namespace dynamics
} // end namespace contacts
