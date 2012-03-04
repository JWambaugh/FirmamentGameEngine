#include <hxcpp.h>

#ifndef INCLUDED_box2D_dynamics_B2TimeStep
#include <box2D/dynamics/B2TimeStep.h>
#endif
namespace box2D{
namespace dynamics{

Void B2TimeStep_obj::__construct()
{
{
}
;
	return null();
}

B2TimeStep_obj::~B2TimeStep_obj() { }

Dynamic B2TimeStep_obj::__CreateEmpty() { return  new B2TimeStep_obj; }
hx::ObjectPtr< B2TimeStep_obj > B2TimeStep_obj::__new()
{  hx::ObjectPtr< B2TimeStep_obj > result = new B2TimeStep_obj();
	result->__construct();
	return result;}

Dynamic B2TimeStep_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2TimeStep_obj > result = new B2TimeStep_obj();
	result->__construct();
	return result;}

Void B2TimeStep_obj::set( ::box2D::dynamics::B2TimeStep step){
{
		HX_SOURCE_PUSH("B2TimeStep_obj::set")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2TimeStep.hx",30)
		this->dt = step->dt;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2TimeStep.hx",31)
		this->inv_dt = step->inv_dt;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2TimeStep.hx",32)
		this->positionIterations = step->positionIterations;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2TimeStep.hx",33)
		this->velocityIterations = step->velocityIterations;
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2TimeStep.hx",34)
		this->warmStarting = step->warmStarting;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2TimeStep_obj,set,(void))


B2TimeStep_obj::B2TimeStep_obj()
{
}

void B2TimeStep_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(B2TimeStep);
	HX_MARK_MEMBER_NAME(dt,"dt");
	HX_MARK_MEMBER_NAME(inv_dt,"inv_dt");
	HX_MARK_MEMBER_NAME(dtRatio,"dtRatio");
	HX_MARK_MEMBER_NAME(velocityIterations,"velocityIterations");
	HX_MARK_MEMBER_NAME(positionIterations,"positionIterations");
	HX_MARK_MEMBER_NAME(warmStarting,"warmStarting");
	HX_MARK_END_CLASS();
}

Dynamic B2TimeStep_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"dt") ) { return dt; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"set") ) { return set_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"inv_dt") ) { return inv_dt; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"dtRatio") ) { return dtRatio; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"warmStarting") ) { return warmStarting; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"velocityIterations") ) { return velocityIterations; }
		if (HX_FIELD_EQ(inName,"positionIterations") ) { return positionIterations; }
	}
	return super::__Field(inName);
}

Dynamic B2TimeStep_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"dt") ) { dt=inValue.Cast< double >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"inv_dt") ) { inv_dt=inValue.Cast< double >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"dtRatio") ) { dtRatio=inValue.Cast< double >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"warmStarting") ) { warmStarting=inValue.Cast< bool >(); return inValue; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"velocityIterations") ) { velocityIterations=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"positionIterations") ) { positionIterations=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void B2TimeStep_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("dt"));
	outFields->push(HX_CSTRING("inv_dt"));
	outFields->push(HX_CSTRING("dtRatio"));
	outFields->push(HX_CSTRING("velocityIterations"));
	outFields->push(HX_CSTRING("positionIterations"));
	outFields->push(HX_CSTRING("warmStarting"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("set"),
	HX_CSTRING("dt"),
	HX_CSTRING("inv_dt"),
	HX_CSTRING("dtRatio"),
	HX_CSTRING("velocityIterations"),
	HX_CSTRING("positionIterations"),
	HX_CSTRING("warmStarting"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class B2TimeStep_obj::__mClass;

void B2TimeStep_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.dynamics.B2TimeStep"), hx::TCanCast< B2TimeStep_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void B2TimeStep_obj::__boot()
{
}

} // end namespace box2D
} // end namespace dynamics
