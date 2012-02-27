#include <hxcpp.h>

#ifndef INCLUDED_cpp_Lib
#include <cpp/Lib.h>
#endif
#ifndef INCLUDED_nme_Loader
#include <nme/Loader.h>
#endif
namespace nme{

Void Loader_obj::__construct()
{
	return null();
}

Loader_obj::~Loader_obj() { }

Dynamic Loader_obj::__CreateEmpty() { return  new Loader_obj; }
hx::ObjectPtr< Loader_obj > Loader_obj::__new()
{  hx::ObjectPtr< Loader_obj > result = new Loader_obj();
	result->__construct();
	return result;}

Dynamic Loader_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Loader_obj > result = new Loader_obj();
	result->__construct();
	return result;}

bool Loader_obj::moduleInit;

::String Loader_obj::moduleName;

Dynamic Loader_obj::load( ::String func,int args){
	HX_SOURCE_PUSH("Loader_obj::load")
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/3,2,0/nme/Loader.hx",27)
	return ::cpp::Lib_obj::load(HX_CSTRING("nme"),func,args);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Loader_obj,load,return )


Loader_obj::Loader_obj()
{
}

void Loader_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Loader);
	HX_MARK_END_CLASS();
}

Dynamic Loader_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"load") ) { return load_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"moduleInit") ) { return moduleInit; }
		if (HX_FIELD_EQ(inName,"moduleName") ) { return moduleName; }
	}
	return super::__Field(inName);
}

Dynamic Loader_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 10:
		if (HX_FIELD_EQ(inName,"moduleInit") ) { moduleInit=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"moduleName") ) { moduleName=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Loader_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("moduleInit"),
	HX_CSTRING("moduleName"),
	HX_CSTRING("load"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Loader_obj::moduleInit,"moduleInit");
	HX_MARK_MEMBER_NAME(Loader_obj::moduleName,"moduleName");
};

Class Loader_obj::__mClass;

void Loader_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("nme.Loader"), hx::TCanCast< Loader_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Loader_obj::__boot()
{
	hx::Static(moduleInit) = false;
	hx::Static(moduleName) = HX_CSTRING("");
}

} // end namespace nme
