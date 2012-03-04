#include <hxcpp.h>

#ifndef INCLUDED_box2D_common_B2Color
#include <box2D/common/B2Color.h>
#endif
#ifndef INCLUDED_box2D_common_math_B2Mat22
#include <box2D/common/math/B2Mat22.h>
#endif
#ifndef INCLUDED_box2D_common_math_B2Transform
#include <box2D/common/math/B2Transform.h>
#endif
#ifndef INCLUDED_box2D_common_math_B2Vec2
#include <box2D/common/math/B2Vec2.h>
#endif
#ifndef INCLUDED_box2D_dynamics_B2DebugDraw
#include <box2D/dynamics/B2DebugDraw.h>
#endif
#ifndef INCLUDED_nme_display_CapsStyle
#include <nme/display/CapsStyle.h>
#endif
#ifndef INCLUDED_nme_display_DisplayObject
#include <nme/display/DisplayObject.h>
#endif
#ifndef INCLUDED_nme_display_DisplayObjectContainer
#include <nme/display/DisplayObjectContainer.h>
#endif
#ifndef INCLUDED_nme_display_Graphics
#include <nme/display/Graphics.h>
#endif
#ifndef INCLUDED_nme_display_IBitmapDrawable
#include <nme/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_nme_display_InteractiveObject
#include <nme/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_nme_display_JointStyle
#include <nme/display/JointStyle.h>
#endif
#ifndef INCLUDED_nme_display_LineScaleMode
#include <nme/display/LineScaleMode.h>
#endif
#ifndef INCLUDED_nme_display_Sprite
#include <nme/display/Sprite.h>
#endif
#ifndef INCLUDED_nme_events_EventDispatcher
#include <nme/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_nme_events_IEventDispatcher
#include <nme/events/IEventDispatcher.h>
#endif
namespace box2D{
namespace dynamics{

Void B2DebugDraw_obj::__construct()
{
{
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2DebugDraw.hx",37)
	this->m_drawScale = 1.0;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2DebugDraw.hx",39)
	this->m_lineThickness = 1.0;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2DebugDraw.hx",40)
	this->m_alpha = 1.0;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2DebugDraw.hx",41)
	this->m_fillAlpha = 1.0;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2DebugDraw.hx",42)
	this->m_xformScale = 1.0;
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2DebugDraw.hx",45)
	this->m_drawFlags = (int)0;
}
;
	return null();
}

B2DebugDraw_obj::~B2DebugDraw_obj() { }

Dynamic B2DebugDraw_obj::__CreateEmpty() { return  new B2DebugDraw_obj; }
hx::ObjectPtr< B2DebugDraw_obj > B2DebugDraw_obj::__new()
{  hx::ObjectPtr< B2DebugDraw_obj > result = new B2DebugDraw_obj();
	result->__construct();
	return result;}

Dynamic B2DebugDraw_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2DebugDraw_obj > result = new B2DebugDraw_obj();
	result->__construct();
	return result;}

Void B2DebugDraw_obj::setFlags( int flags){
{
		HX_SOURCE_PUSH("B2DebugDraw_obj::setFlags")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2DebugDraw.hx",69)
		this->m_drawFlags = flags;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2DebugDraw_obj,setFlags,(void))

int B2DebugDraw_obj::getFlags( ){
	HX_SOURCE_PUSH("B2DebugDraw_obj::getFlags")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2DebugDraw.hx",76)
	return this->m_drawFlags;
}


HX_DEFINE_DYNAMIC_FUNC0(B2DebugDraw_obj,getFlags,return )

Void B2DebugDraw_obj::appendFlags( int flags){
{
		HX_SOURCE_PUSH("B2DebugDraw_obj::appendFlags")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2DebugDraw.hx",83)
		hx::OrEq(this->m_drawFlags,flags);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2DebugDraw_obj,appendFlags,(void))

Void B2DebugDraw_obj::clearFlags( int flags){
{
		HX_SOURCE_PUSH("B2DebugDraw_obj::clearFlags")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2DebugDraw.hx",90)
		hx::AndEq(this->m_drawFlags,~(int)(flags));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2DebugDraw_obj,clearFlags,(void))

Void B2DebugDraw_obj::setSprite( ::nme::display::Sprite sprite){
{
		HX_SOURCE_PUSH("B2DebugDraw_obj::setSprite")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2DebugDraw.hx",97)
		this->m_sprite = sprite;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2DebugDraw_obj,setSprite,(void))

::nme::display::Sprite B2DebugDraw_obj::getSprite( ){
	HX_SOURCE_PUSH("B2DebugDraw_obj::getSprite")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2DebugDraw.hx",104)
	return this->m_sprite;
}


HX_DEFINE_DYNAMIC_FUNC0(B2DebugDraw_obj,getSprite,return )

Void B2DebugDraw_obj::setDrawScale( double drawScale){
{
		HX_SOURCE_PUSH("B2DebugDraw_obj::setDrawScale")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2DebugDraw.hx",111)
		this->m_drawScale = drawScale;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2DebugDraw_obj,setDrawScale,(void))

double B2DebugDraw_obj::getDrawScale( ){
	HX_SOURCE_PUSH("B2DebugDraw_obj::getDrawScale")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2DebugDraw.hx",118)
	return this->m_drawScale;
}


HX_DEFINE_DYNAMIC_FUNC0(B2DebugDraw_obj,getDrawScale,return )

Void B2DebugDraw_obj::setLineThickness( double lineThickness){
{
		HX_SOURCE_PUSH("B2DebugDraw_obj::setLineThickness")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2DebugDraw.hx",125)
		this->m_lineThickness = lineThickness;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2DebugDraw_obj,setLineThickness,(void))

double B2DebugDraw_obj::getLineThickness( ){
	HX_SOURCE_PUSH("B2DebugDraw_obj::getLineThickness")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2DebugDraw.hx",132)
	return this->m_lineThickness;
}


HX_DEFINE_DYNAMIC_FUNC0(B2DebugDraw_obj,getLineThickness,return )

Void B2DebugDraw_obj::setAlpha( double alpha){
{
		HX_SOURCE_PUSH("B2DebugDraw_obj::setAlpha")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2DebugDraw.hx",139)
		this->m_alpha = alpha;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2DebugDraw_obj,setAlpha,(void))

double B2DebugDraw_obj::getAlpha( ){
	HX_SOURCE_PUSH("B2DebugDraw_obj::getAlpha")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2DebugDraw.hx",146)
	return this->m_alpha;
}


HX_DEFINE_DYNAMIC_FUNC0(B2DebugDraw_obj,getAlpha,return )

Void B2DebugDraw_obj::setFillAlpha( double alpha){
{
		HX_SOURCE_PUSH("B2DebugDraw_obj::setFillAlpha")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2DebugDraw.hx",153)
		this->m_fillAlpha = alpha;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2DebugDraw_obj,setFillAlpha,(void))

double B2DebugDraw_obj::getFillAlpha( ){
	HX_SOURCE_PUSH("B2DebugDraw_obj::getFillAlpha")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2DebugDraw.hx",160)
	return this->m_fillAlpha;
}


HX_DEFINE_DYNAMIC_FUNC0(B2DebugDraw_obj,getFillAlpha,return )

Void B2DebugDraw_obj::setXFormScale( double xformScale){
{
		HX_SOURCE_PUSH("B2DebugDraw_obj::setXFormScale")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2DebugDraw.hx",167)
		this->m_xformScale = xformScale;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2DebugDraw_obj,setXFormScale,(void))

double B2DebugDraw_obj::getXFormScale( ){
	HX_SOURCE_PUSH("B2DebugDraw_obj::getXFormScale")
	HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2DebugDraw.hx",174)
	return this->m_xformScale;
}


HX_DEFINE_DYNAMIC_FUNC0(B2DebugDraw_obj,getXFormScale,return )

Void B2DebugDraw_obj::drawPolygon( Array< ::box2D::common::math::B2Vec2 > vertices,int vertexCount,::box2D::common::B2Color color){
{
		HX_SOURCE_PUSH("B2DebugDraw_obj::drawPolygon")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2DebugDraw.hx",183)
		this->m_sprite->nmeGetGraphics()->lineStyle(this->m_lineThickness,color->getColor(),this->m_alpha,null(),null(),null(),null(),null());
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2DebugDraw.hx",184)
		this->m_sprite->nmeGetGraphics()->moveTo((vertices->__get((int)0)->x * this->m_drawScale),(vertices->__get((int)0)->y * this->m_drawScale));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2DebugDraw.hx",185)
		{
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2DebugDraw.hx",185)
			int _g = (int)1;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2DebugDraw.hx",185)
			while(((_g < vertexCount))){
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2DebugDraw.hx",185)
				int i = (_g)++;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2DebugDraw.hx",186)
				this->m_sprite->nmeGetGraphics()->lineTo((vertices->__get(i)->x * this->m_drawScale),(vertices->__get(i)->y * this->m_drawScale));
			}
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2DebugDraw.hx",188)
		this->m_sprite->nmeGetGraphics()->lineTo((vertices->__get((int)0)->x * this->m_drawScale),(vertices->__get((int)0)->y * this->m_drawScale));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(B2DebugDraw_obj,drawPolygon,(void))

Void B2DebugDraw_obj::drawSolidPolygon( Array< ::box2D::common::math::B2Vec2 > vertices,int vertexCount,::box2D::common::B2Color color){
{
		HX_SOURCE_PUSH("B2DebugDraw_obj::drawSolidPolygon")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2DebugDraw.hx",197)
		this->m_sprite->nmeGetGraphics()->lineStyle(this->m_lineThickness,color->getColor(),this->m_alpha,null(),null(),null(),null(),null());
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2DebugDraw.hx",198)
		this->m_sprite->nmeGetGraphics()->moveTo((vertices->__get((int)0)->x * this->m_drawScale),(vertices->__get((int)0)->y * this->m_drawScale));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2DebugDraw.hx",199)
		this->m_sprite->nmeGetGraphics()->beginFill(color->getColor(),this->m_fillAlpha);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2DebugDraw.hx",200)
		{
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2DebugDraw.hx",200)
			int _g = (int)1;
			HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2DebugDraw.hx",200)
			while(((_g < vertexCount))){
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2DebugDraw.hx",200)
				int i = (_g)++;
				HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2DebugDraw.hx",201)
				this->m_sprite->nmeGetGraphics()->lineTo((vertices->__get(i)->x * this->m_drawScale),(vertices->__get(i)->y * this->m_drawScale));
			}
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2DebugDraw.hx",203)
		this->m_sprite->nmeGetGraphics()->lineTo((vertices->__get((int)0)->x * this->m_drawScale),(vertices->__get((int)0)->y * this->m_drawScale));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2DebugDraw.hx",204)
		this->m_sprite->nmeGetGraphics()->endFill();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(B2DebugDraw_obj,drawSolidPolygon,(void))

Void B2DebugDraw_obj::drawCircle( ::box2D::common::math::B2Vec2 center,double radius,::box2D::common::B2Color color){
{
		HX_SOURCE_PUSH("B2DebugDraw_obj::drawCircle")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2DebugDraw.hx",213)
		this->m_sprite->nmeGetGraphics()->lineStyle(this->m_lineThickness,color->getColor(),this->m_alpha,null(),null(),null(),null(),null());
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2DebugDraw.hx",214)
		this->m_sprite->nmeGetGraphics()->drawCircle((center->x * this->m_drawScale),(center->y * this->m_drawScale),(radius * this->m_drawScale));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(B2DebugDraw_obj,drawCircle,(void))

Void B2DebugDraw_obj::drawSolidCircle( ::box2D::common::math::B2Vec2 center,double radius,::box2D::common::math::B2Vec2 axis,::box2D::common::B2Color color){
{
		HX_SOURCE_PUSH("B2DebugDraw_obj::drawSolidCircle")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2DebugDraw.hx",223)
		this->m_sprite->nmeGetGraphics()->lineStyle(this->m_lineThickness,color->getColor(),this->m_alpha,null(),null(),null(),null(),null());
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2DebugDraw.hx",224)
		this->m_sprite->nmeGetGraphics()->moveTo((int)0,(int)0);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2DebugDraw.hx",225)
		this->m_sprite->nmeGetGraphics()->beginFill(color->getColor(),this->m_fillAlpha);
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2DebugDraw.hx",226)
		this->m_sprite->nmeGetGraphics()->drawCircle((center->x * this->m_drawScale),(center->y * this->m_drawScale),(radius * this->m_drawScale));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2DebugDraw.hx",227)
		this->m_sprite->nmeGetGraphics()->endFill();
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2DebugDraw.hx",228)
		this->m_sprite->nmeGetGraphics()->moveTo((center->x * this->m_drawScale),(center->y * this->m_drawScale));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2DebugDraw.hx",229)
		this->m_sprite->nmeGetGraphics()->lineTo((((center->x + (axis->x * radius))) * this->m_drawScale),(((center->y + (axis->y * radius))) * this->m_drawScale));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(B2DebugDraw_obj,drawSolidCircle,(void))

Void B2DebugDraw_obj::drawSegment( ::box2D::common::math::B2Vec2 p1,::box2D::common::math::B2Vec2 p2,::box2D::common::B2Color color){
{
		HX_SOURCE_PUSH("B2DebugDraw_obj::drawSegment")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2DebugDraw.hx",239)
		this->m_sprite->nmeGetGraphics()->lineStyle(this->m_lineThickness,color->getColor(),this->m_alpha,null(),null(),null(),null(),null());
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2DebugDraw.hx",240)
		this->m_sprite->nmeGetGraphics()->moveTo((p1->x * this->m_drawScale),(p1->y * this->m_drawScale));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2DebugDraw.hx",241)
		this->m_sprite->nmeGetGraphics()->lineTo((p2->x * this->m_drawScale),(p2->y * this->m_drawScale));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(B2DebugDraw_obj,drawSegment,(void))

Void B2DebugDraw_obj::drawTransform( ::box2D::common::math::B2Transform xf){
{
		HX_SOURCE_PUSH("B2DebugDraw_obj::drawTransform")
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2DebugDraw.hx",251)
		this->m_sprite->nmeGetGraphics()->lineStyle(this->m_lineThickness,(int)16711680,this->m_alpha,null(),null(),null(),null(),null());
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2DebugDraw.hx",252)
		this->m_sprite->nmeGetGraphics()->moveTo((xf->position->x * this->m_drawScale),(xf->position->y * this->m_drawScale));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2DebugDraw.hx",253)
		this->m_sprite->nmeGetGraphics()->lineTo((((xf->position->x + (this->m_xformScale * xf->R->col1->x))) * this->m_drawScale),(((xf->position->y + (this->m_xformScale * xf->R->col1->y))) * this->m_drawScale));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2DebugDraw.hx",255)
		this->m_sprite->nmeGetGraphics()->lineStyle(this->m_lineThickness,(int)65280,this->m_alpha,null(),null(),null(),null(),null());
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2DebugDraw.hx",256)
		this->m_sprite->nmeGetGraphics()->moveTo((xf->position->x * this->m_drawScale),(xf->position->y * this->m_drawScale));
		HX_SOURCE_POS("/usr/lib/haxe/lib/box2d/1,11/box2D/dynamics/B2DebugDraw.hx",257)
		this->m_sprite->nmeGetGraphics()->lineTo((((xf->position->x + (this->m_xformScale * xf->R->col2->x))) * this->m_drawScale),(((xf->position->y + (this->m_xformScale * xf->R->col2->y))) * this->m_drawScale));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2DebugDraw_obj,drawTransform,(void))

int B2DebugDraw_obj::e_shapeBit;

int B2DebugDraw_obj::e_jointBit;

int B2DebugDraw_obj::e_aabbBit;

int B2DebugDraw_obj::e_pairBit;

int B2DebugDraw_obj::e_centerOfMassBit;

int B2DebugDraw_obj::e_controllerBit;


B2DebugDraw_obj::B2DebugDraw_obj()
{
}

void B2DebugDraw_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(B2DebugDraw);
	HX_MARK_MEMBER_NAME(m_drawFlags,"m_drawFlags");
	HX_MARK_MEMBER_NAME(m_sprite,"m_sprite");
	HX_MARK_MEMBER_NAME(m_drawScale,"m_drawScale");
	HX_MARK_MEMBER_NAME(m_lineThickness,"m_lineThickness");
	HX_MARK_MEMBER_NAME(m_alpha,"m_alpha");
	HX_MARK_MEMBER_NAME(m_fillAlpha,"m_fillAlpha");
	HX_MARK_MEMBER_NAME(m_xformScale,"m_xformScale");
	HX_MARK_END_CLASS();
}

Dynamic B2DebugDraw_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"m_alpha") ) { return m_alpha; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"setFlags") ) { return setFlags_dyn(); }
		if (HX_FIELD_EQ(inName,"getFlags") ) { return getFlags_dyn(); }
		if (HX_FIELD_EQ(inName,"setAlpha") ) { return setAlpha_dyn(); }
		if (HX_FIELD_EQ(inName,"getAlpha") ) { return getAlpha_dyn(); }
		if (HX_FIELD_EQ(inName,"m_sprite") ) { return m_sprite; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"e_aabbBit") ) { return e_aabbBit; }
		if (HX_FIELD_EQ(inName,"e_pairBit") ) { return e_pairBit; }
		if (HX_FIELD_EQ(inName,"setSprite") ) { return setSprite_dyn(); }
		if (HX_FIELD_EQ(inName,"getSprite") ) { return getSprite_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"e_shapeBit") ) { return e_shapeBit; }
		if (HX_FIELD_EQ(inName,"e_jointBit") ) { return e_jointBit; }
		if (HX_FIELD_EQ(inName,"clearFlags") ) { return clearFlags_dyn(); }
		if (HX_FIELD_EQ(inName,"drawCircle") ) { return drawCircle_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"appendFlags") ) { return appendFlags_dyn(); }
		if (HX_FIELD_EQ(inName,"drawPolygon") ) { return drawPolygon_dyn(); }
		if (HX_FIELD_EQ(inName,"drawSegment") ) { return drawSegment_dyn(); }
		if (HX_FIELD_EQ(inName,"m_drawFlags") ) { return m_drawFlags; }
		if (HX_FIELD_EQ(inName,"m_drawScale") ) { return m_drawScale; }
		if (HX_FIELD_EQ(inName,"m_fillAlpha") ) { return m_fillAlpha; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"setDrawScale") ) { return setDrawScale_dyn(); }
		if (HX_FIELD_EQ(inName,"getDrawScale") ) { return getDrawScale_dyn(); }
		if (HX_FIELD_EQ(inName,"setFillAlpha") ) { return setFillAlpha_dyn(); }
		if (HX_FIELD_EQ(inName,"getFillAlpha") ) { return getFillAlpha_dyn(); }
		if (HX_FIELD_EQ(inName,"m_xformScale") ) { return m_xformScale; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"setXFormScale") ) { return setXFormScale_dyn(); }
		if (HX_FIELD_EQ(inName,"getXFormScale") ) { return getXFormScale_dyn(); }
		if (HX_FIELD_EQ(inName,"drawTransform") ) { return drawTransform_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"e_controllerBit") ) { return e_controllerBit; }
		if (HX_FIELD_EQ(inName,"drawSolidCircle") ) { return drawSolidCircle_dyn(); }
		if (HX_FIELD_EQ(inName,"m_lineThickness") ) { return m_lineThickness; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"setLineThickness") ) { return setLineThickness_dyn(); }
		if (HX_FIELD_EQ(inName,"getLineThickness") ) { return getLineThickness_dyn(); }
		if (HX_FIELD_EQ(inName,"drawSolidPolygon") ) { return drawSolidPolygon_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"e_centerOfMassBit") ) { return e_centerOfMassBit; }
	}
	return super::__Field(inName);
}

Dynamic B2DebugDraw_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"m_alpha") ) { m_alpha=inValue.Cast< double >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"m_sprite") ) { m_sprite=inValue.Cast< ::nme::display::Sprite >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"e_aabbBit") ) { e_aabbBit=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"e_pairBit") ) { e_pairBit=inValue.Cast< int >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"e_shapeBit") ) { e_shapeBit=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"e_jointBit") ) { e_jointBit=inValue.Cast< int >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"m_drawFlags") ) { m_drawFlags=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_drawScale") ) { m_drawScale=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_fillAlpha") ) { m_fillAlpha=inValue.Cast< double >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"m_xformScale") ) { m_xformScale=inValue.Cast< double >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"e_controllerBit") ) { e_controllerBit=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_lineThickness") ) { m_lineThickness=inValue.Cast< double >(); return inValue; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"e_centerOfMassBit") ) { e_centerOfMassBit=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void B2DebugDraw_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("m_drawFlags"));
	outFields->push(HX_CSTRING("m_sprite"));
	outFields->push(HX_CSTRING("m_drawScale"));
	outFields->push(HX_CSTRING("m_lineThickness"));
	outFields->push(HX_CSTRING("m_alpha"));
	outFields->push(HX_CSTRING("m_fillAlpha"));
	outFields->push(HX_CSTRING("m_xformScale"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("e_shapeBit"),
	HX_CSTRING("e_jointBit"),
	HX_CSTRING("e_aabbBit"),
	HX_CSTRING("e_pairBit"),
	HX_CSTRING("e_centerOfMassBit"),
	HX_CSTRING("e_controllerBit"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("setFlags"),
	HX_CSTRING("getFlags"),
	HX_CSTRING("appendFlags"),
	HX_CSTRING("clearFlags"),
	HX_CSTRING("setSprite"),
	HX_CSTRING("getSprite"),
	HX_CSTRING("setDrawScale"),
	HX_CSTRING("getDrawScale"),
	HX_CSTRING("setLineThickness"),
	HX_CSTRING("getLineThickness"),
	HX_CSTRING("setAlpha"),
	HX_CSTRING("getAlpha"),
	HX_CSTRING("setFillAlpha"),
	HX_CSTRING("getFillAlpha"),
	HX_CSTRING("setXFormScale"),
	HX_CSTRING("getXFormScale"),
	HX_CSTRING("drawPolygon"),
	HX_CSTRING("drawSolidPolygon"),
	HX_CSTRING("drawCircle"),
	HX_CSTRING("drawSolidCircle"),
	HX_CSTRING("drawSegment"),
	HX_CSTRING("drawTransform"),
	HX_CSTRING("m_drawFlags"),
	HX_CSTRING("m_sprite"),
	HX_CSTRING("m_drawScale"),
	HX_CSTRING("m_lineThickness"),
	HX_CSTRING("m_alpha"),
	HX_CSTRING("m_fillAlpha"),
	HX_CSTRING("m_xformScale"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(B2DebugDraw_obj::e_shapeBit,"e_shapeBit");
	HX_MARK_MEMBER_NAME(B2DebugDraw_obj::e_jointBit,"e_jointBit");
	HX_MARK_MEMBER_NAME(B2DebugDraw_obj::e_aabbBit,"e_aabbBit");
	HX_MARK_MEMBER_NAME(B2DebugDraw_obj::e_pairBit,"e_pairBit");
	HX_MARK_MEMBER_NAME(B2DebugDraw_obj::e_centerOfMassBit,"e_centerOfMassBit");
	HX_MARK_MEMBER_NAME(B2DebugDraw_obj::e_controllerBit,"e_controllerBit");
};

Class B2DebugDraw_obj::__mClass;

void B2DebugDraw_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.dynamics.B2DebugDraw"), hx::TCanCast< B2DebugDraw_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void B2DebugDraw_obj::__boot()
{
	hx::Static(e_shapeBit) = (int)1;
	hx::Static(e_jointBit) = (int)2;
	hx::Static(e_aabbBit) = (int)4;
	hx::Static(e_pairBit) = (int)8;
	hx::Static(e_centerOfMassBit) = (int)16;
	hx::Static(e_controllerBit) = (int)32;
}

} // end namespace box2D
} // end namespace dynamics
