#include <hxcpp.h>

#ifndef INCLUDED_box2D_collision_B2AABB
#include <box2D/collision/B2AABB.h>
#endif
#ifndef INCLUDED_box2D_collision_B2DynamicTreeNode
#include <box2D/collision/B2DynamicTreeNode.h>
#endif
namespace box2D{
namespace collision{

Void B2DynamicTreeNode_obj::__construct()
{
{
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTreeNode.hx",33)
	this->aabb = ::box2D::collision::B2AABB_obj::__new();
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTreeNode.hx",34)
	this->id = (::box2D::collision::B2DynamicTreeNode_obj::currentID)++;
}
;
	return null();
}

B2DynamicTreeNode_obj::~B2DynamicTreeNode_obj() { }

Dynamic B2DynamicTreeNode_obj::__CreateEmpty() { return  new B2DynamicTreeNode_obj; }
hx::ObjectPtr< B2DynamicTreeNode_obj > B2DynamicTreeNode_obj::__new()
{  hx::ObjectPtr< B2DynamicTreeNode_obj > result = new B2DynamicTreeNode_obj();
	result->__construct();
	return result;}

Dynamic B2DynamicTreeNode_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2DynamicTreeNode_obj > result = new B2DynamicTreeNode_obj();
	result->__construct();
	return result;}

bool B2DynamicTreeNode_obj::isLeaf( ){
	HX_SOURCE_PUSH("B2DynamicTreeNode_obj::isLeaf")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/collision/B2DynamicTreeNode.hx",38)
	return (this->child1 == null());
}


HX_DEFINE_DYNAMIC_FUNC0(B2DynamicTreeNode_obj,isLeaf,return )

int B2DynamicTreeNode_obj::currentID;


B2DynamicTreeNode_obj::B2DynamicTreeNode_obj()
{
}

void B2DynamicTreeNode_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(B2DynamicTreeNode);
	HX_MARK_MEMBER_NAME(id,"id");
	HX_MARK_MEMBER_NAME(userData,"userData");
	HX_MARK_MEMBER_NAME(aabb,"aabb");
	HX_MARK_MEMBER_NAME(parent,"parent");
	HX_MARK_MEMBER_NAME(child1,"child1");
	HX_MARK_MEMBER_NAME(child2,"child2");
	HX_MARK_END_CLASS();
}

Dynamic B2DynamicTreeNode_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"id") ) { return id; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"aabb") ) { return aabb; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"isLeaf") ) { return isLeaf_dyn(); }
		if (HX_FIELD_EQ(inName,"parent") ) { return parent; }
		if (HX_FIELD_EQ(inName,"child1") ) { return child1; }
		if (HX_FIELD_EQ(inName,"child2") ) { return child2; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"userData") ) { return userData; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"currentID") ) { return currentID; }
	}
	return super::__Field(inName);
}

Dynamic B2DynamicTreeNode_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"id") ) { id=inValue.Cast< int >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"aabb") ) { aabb=inValue.Cast< ::box2D::collision::B2AABB >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"parent") ) { parent=inValue.Cast< ::box2D::collision::B2DynamicTreeNode >(); return inValue; }
		if (HX_FIELD_EQ(inName,"child1") ) { child1=inValue.Cast< ::box2D::collision::B2DynamicTreeNode >(); return inValue; }
		if (HX_FIELD_EQ(inName,"child2") ) { child2=inValue.Cast< ::box2D::collision::B2DynamicTreeNode >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"userData") ) { userData=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"currentID") ) { currentID=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void B2DynamicTreeNode_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("id"));
	outFields->push(HX_CSTRING("userData"));
	outFields->push(HX_CSTRING("aabb"));
	outFields->push(HX_CSTRING("parent"));
	outFields->push(HX_CSTRING("child1"));
	outFields->push(HX_CSTRING("child2"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("currentID"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("id"),
	HX_CSTRING("isLeaf"),
	HX_CSTRING("userData"),
	HX_CSTRING("aabb"),
	HX_CSTRING("parent"),
	HX_CSTRING("child1"),
	HX_CSTRING("child2"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(B2DynamicTreeNode_obj::currentID,"currentID");
};

Class B2DynamicTreeNode_obj::__mClass;

void B2DynamicTreeNode_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.collision.B2DynamicTreeNode"), hx::TCanCast< B2DynamicTreeNode_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void B2DynamicTreeNode_obj::__boot()
{
	hx::Static(currentID) = (int)0;
}

} // end namespace box2D
} // end namespace collision
