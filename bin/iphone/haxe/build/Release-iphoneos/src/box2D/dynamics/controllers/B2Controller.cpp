#include <hxcpp.h>

#ifndef INCLUDED_box2D_dynamics_B2Body
#include <box2D/dynamics/B2Body.h>
#endif
#ifndef INCLUDED_box2D_dynamics_B2DebugDraw
#include <box2D/dynamics/B2DebugDraw.h>
#endif
#ifndef INCLUDED_box2D_dynamics_B2TimeStep
#include <box2D/dynamics/B2TimeStep.h>
#endif
#ifndef INCLUDED_box2D_dynamics_B2World
#include <box2D/dynamics/B2World.h>
#endif
#ifndef INCLUDED_box2D_dynamics_controllers_B2Controller
#include <box2D/dynamics/controllers/B2Controller.h>
#endif
#ifndef INCLUDED_box2D_dynamics_controllers_B2ControllerEdge
#include <box2D/dynamics/controllers/B2ControllerEdge.h>
#endif
namespace box2D{
namespace dynamics{
namespace controllers{

Void B2Controller_obj::__construct()
{
	return null();
}

B2Controller_obj::~B2Controller_obj() { }

Dynamic B2Controller_obj::__CreateEmpty() { return  new B2Controller_obj; }
hx::ObjectPtr< B2Controller_obj > B2Controller_obj::__new()
{  hx::ObjectPtr< B2Controller_obj > result = new B2Controller_obj();
	result->__construct();
	return result;}

Dynamic B2Controller_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2Controller_obj > result = new B2Controller_obj();
	result->__construct();
	return result;}

Void B2Controller_obj::step( ::box2D::dynamics::B2TimeStep step){
{
		HX_SOURCE_PUSH("B2Controller_obj::step")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2Controller_obj,step,(void))

Void B2Controller_obj::draw( ::box2D::dynamics::B2DebugDraw debugDraw){
{
		HX_SOURCE_PUSH("B2Controller_obj::draw")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2Controller_obj,draw,(void))

Void B2Controller_obj::addBody( ::box2D::dynamics::B2Body body){
{
		HX_SOURCE_PUSH("B2Controller_obj::addBody")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/controllers/B2Controller.hx",40)
		::box2D::dynamics::controllers::B2ControllerEdge edge = ::box2D::dynamics::controllers::B2ControllerEdge_obj::__new();
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/controllers/B2Controller.hx",41)
		edge->controller = hx::ObjectPtr<OBJ_>(this);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/controllers/B2Controller.hx",42)
		edge->body = body;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/controllers/B2Controller.hx",44)
		edge->nextBody = this->m_bodyList;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/controllers/B2Controller.hx",45)
		edge->prevBody = null();
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/controllers/B2Controller.hx",46)
		this->m_bodyList = edge;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/controllers/B2Controller.hx",47)
		if (((edge->nextBody != null()))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/controllers/B2Controller.hx",48)
			edge->nextBody->prevBody = edge;
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/controllers/B2Controller.hx",49)
		(this->m_bodyCount)++;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/controllers/B2Controller.hx",51)
		edge->nextController = body->m_controllerList;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/controllers/B2Controller.hx",52)
		edge->prevController = null();
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/controllers/B2Controller.hx",53)
		body->m_controllerList = edge;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/controllers/B2Controller.hx",54)
		if (((edge->nextController != null()))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/controllers/B2Controller.hx",55)
			edge->nextController->prevController = edge;
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/controllers/B2Controller.hx",56)
		(body->m_controllerCount)++;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2Controller_obj,addBody,(void))

Void B2Controller_obj::removeBody( ::box2D::dynamics::B2Body body){
{
		HX_SOURCE_PUSH("B2Controller_obj::removeBody")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/controllers/B2Controller.hx",61)
		::box2D::dynamics::controllers::B2ControllerEdge edge = body->m_controllerList;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/controllers/B2Controller.hx",62)
		while(((bool((edge != null())) && bool((edge->controller != hx::ObjectPtr<OBJ_>(this)))))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/controllers/B2Controller.hx",63)
			edge = edge->nextController;
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/controllers/B2Controller.hx",68)
		if (((edge->prevBody != null()))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/controllers/B2Controller.hx",69)
			edge->prevBody->nextBody = edge->nextBody;
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/controllers/B2Controller.hx",70)
		if (((edge->nextBody != null()))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/controllers/B2Controller.hx",71)
			edge->nextBody->prevBody = edge->prevBody;
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/controllers/B2Controller.hx",72)
		if (((edge->nextController != null()))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/controllers/B2Controller.hx",73)
			edge->nextController->prevController = edge->prevController;
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/controllers/B2Controller.hx",74)
		if (((edge->prevController != null()))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/controllers/B2Controller.hx",75)
			edge->prevController->nextController = edge->nextController;
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/controllers/B2Controller.hx",76)
		if (((this->m_bodyList == edge))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/controllers/B2Controller.hx",77)
			this->m_bodyList = edge->nextBody;
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/controllers/B2Controller.hx",78)
		if (((body->m_controllerList == edge))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/controllers/B2Controller.hx",79)
			body->m_controllerList = edge->nextController;
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/controllers/B2Controller.hx",80)
		(body->m_controllerCount)--;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/controllers/B2Controller.hx",81)
		(this->m_bodyCount)--;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2Controller_obj,removeBody,(void))

Void B2Controller_obj::clear( ){
{
		HX_SOURCE_PUSH("B2Controller_obj::clear")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/controllers/B2Controller.hx",87)
		while(((this->m_bodyList != null()))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/controllers/B2Controller.hx",89)
			this->removeBody(this->m_bodyList->body);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(B2Controller_obj,clear,(void))

::box2D::dynamics::controllers::B2Controller B2Controller_obj::getNext( ){
	HX_SOURCE_PUSH("B2Controller_obj::getNext")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/controllers/B2Controller.hx",92)
	return this->m_next;
}


HX_DEFINE_DYNAMIC_FUNC0(B2Controller_obj,getNext,return )

::box2D::dynamics::B2World B2Controller_obj::getWorld( ){
	HX_SOURCE_PUSH("B2Controller_obj::getWorld")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/controllers/B2Controller.hx",93)
	return this->m_world;
}


HX_DEFINE_DYNAMIC_FUNC0(B2Controller_obj,getWorld,return )

::box2D::dynamics::controllers::B2ControllerEdge B2Controller_obj::getBodyList( ){
	HX_SOURCE_PUSH("B2Controller_obj::getBodyList")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/controllers/B2Controller.hx",96)
	return this->m_bodyList;
}


HX_DEFINE_DYNAMIC_FUNC0(B2Controller_obj,getBodyList,return )


B2Controller_obj::B2Controller_obj()
{
}

void B2Controller_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(B2Controller);
	HX_MARK_MEMBER_NAME(m_next,"m_next");
	HX_MARK_MEMBER_NAME(m_prev,"m_prev");
	HX_MARK_MEMBER_NAME(m_bodyList,"m_bodyList");
	HX_MARK_MEMBER_NAME(m_bodyCount,"m_bodyCount");
	HX_MARK_MEMBER_NAME(m_world,"m_world");
	HX_MARK_END_CLASS();
}

Dynamic B2Controller_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"step") ) { return step_dyn(); }
		if (HX_FIELD_EQ(inName,"draw") ) { return draw_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"clear") ) { return clear_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"m_next") ) { return m_next; }
		if (HX_FIELD_EQ(inName,"m_prev") ) { return m_prev; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"addBody") ) { return addBody_dyn(); }
		if (HX_FIELD_EQ(inName,"getNext") ) { return getNext_dyn(); }
		if (HX_FIELD_EQ(inName,"m_world") ) { return m_world; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"getWorld") ) { return getWorld_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"removeBody") ) { return removeBody_dyn(); }
		if (HX_FIELD_EQ(inName,"m_bodyList") ) { return m_bodyList; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"getBodyList") ) { return getBodyList_dyn(); }
		if (HX_FIELD_EQ(inName,"m_bodyCount") ) { return m_bodyCount; }
	}
	return super::__Field(inName);
}

Dynamic B2Controller_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"m_next") ) { m_next=inValue.Cast< ::box2D::dynamics::controllers::B2Controller >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_prev") ) { m_prev=inValue.Cast< ::box2D::dynamics::controllers::B2Controller >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"m_world") ) { m_world=inValue.Cast< ::box2D::dynamics::B2World >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"m_bodyList") ) { m_bodyList=inValue.Cast< ::box2D::dynamics::controllers::B2ControllerEdge >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"m_bodyCount") ) { m_bodyCount=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void B2Controller_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("m_next"));
	outFields->push(HX_CSTRING("m_prev"));
	outFields->push(HX_CSTRING("m_bodyList"));
	outFields->push(HX_CSTRING("m_bodyCount"));
	outFields->push(HX_CSTRING("m_world"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("step"),
	HX_CSTRING("draw"),
	HX_CSTRING("addBody"),
	HX_CSTRING("removeBody"),
	HX_CSTRING("clear"),
	HX_CSTRING("getNext"),
	HX_CSTRING("getWorld"),
	HX_CSTRING("getBodyList"),
	HX_CSTRING("m_next"),
	HX_CSTRING("m_prev"),
	HX_CSTRING("m_bodyList"),
	HX_CSTRING("m_bodyCount"),
	HX_CSTRING("m_world"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class B2Controller_obj::__mClass;

void B2Controller_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.dynamics.controllers.B2Controller"), hx::TCanCast< B2Controller_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void B2Controller_obj::__boot()
{
}

} // end namespace box2D
} // end namespace dynamics
} // end namespace controllers
