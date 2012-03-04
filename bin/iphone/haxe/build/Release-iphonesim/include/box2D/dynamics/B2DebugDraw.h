#ifndef INCLUDED_box2D_dynamics_B2DebugDraw
#define INCLUDED_box2D_dynamics_B2DebugDraw

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(box2D,common,B2Color)
HX_DECLARE_CLASS3(box2D,common,math,B2Transform)
HX_DECLARE_CLASS3(box2D,common,math,B2Vec2)
HX_DECLARE_CLASS2(box2D,dynamics,B2DebugDraw)
HX_DECLARE_CLASS2(nme,display,DisplayObject)
HX_DECLARE_CLASS2(nme,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(nme,display,IBitmapDrawable)
HX_DECLARE_CLASS2(nme,display,InteractiveObject)
HX_DECLARE_CLASS2(nme,display,Sprite)
HX_DECLARE_CLASS2(nme,events,EventDispatcher)
HX_DECLARE_CLASS2(nme,events,IEventDispatcher)
namespace box2D{
namespace dynamics{


class B2DebugDraw_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef B2DebugDraw_obj OBJ_;
		B2DebugDraw_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< B2DebugDraw_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~B2DebugDraw_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("B2DebugDraw"); }

		virtual Void setFlags( int flags);
		Dynamic setFlags_dyn();

		virtual int getFlags( );
		Dynamic getFlags_dyn();

		virtual Void appendFlags( int flags);
		Dynamic appendFlags_dyn();

		virtual Void clearFlags( int flags);
		Dynamic clearFlags_dyn();

		virtual Void setSprite( ::nme::display::Sprite sprite);
		Dynamic setSprite_dyn();

		virtual ::nme::display::Sprite getSprite( );
		Dynamic getSprite_dyn();

		virtual Void setDrawScale( double drawScale);
		Dynamic setDrawScale_dyn();

		virtual double getDrawScale( );
		Dynamic getDrawScale_dyn();

		virtual Void setLineThickness( double lineThickness);
		Dynamic setLineThickness_dyn();

		virtual double getLineThickness( );
		Dynamic getLineThickness_dyn();

		virtual Void setAlpha( double alpha);
		Dynamic setAlpha_dyn();

		virtual double getAlpha( );
		Dynamic getAlpha_dyn();

		virtual Void setFillAlpha( double alpha);
		Dynamic setFillAlpha_dyn();

		virtual double getFillAlpha( );
		Dynamic getFillAlpha_dyn();

		virtual Void setXFormScale( double xformScale);
		Dynamic setXFormScale_dyn();

		virtual double getXFormScale( );
		Dynamic getXFormScale_dyn();

		virtual Void drawPolygon( Array< ::box2D::common::math::B2Vec2 > vertices,int vertexCount,::box2D::common::B2Color color);
		Dynamic drawPolygon_dyn();

		virtual Void drawSolidPolygon( Array< ::box2D::common::math::B2Vec2 > vertices,int vertexCount,::box2D::common::B2Color color);
		Dynamic drawSolidPolygon_dyn();

		virtual Void drawCircle( ::box2D::common::math::B2Vec2 center,double radius,::box2D::common::B2Color color);
		Dynamic drawCircle_dyn();

		virtual Void drawSolidCircle( ::box2D::common::math::B2Vec2 center,double radius,::box2D::common::math::B2Vec2 axis,::box2D::common::B2Color color);
		Dynamic drawSolidCircle_dyn();

		virtual Void drawSegment( ::box2D::common::math::B2Vec2 p1,::box2D::common::math::B2Vec2 p2,::box2D::common::B2Color color);
		Dynamic drawSegment_dyn();

		virtual Void drawTransform( ::box2D::common::math::B2Transform xf);
		Dynamic drawTransform_dyn();

		int m_drawFlags; /* REM */ 
		::nme::display::Sprite m_sprite; /* REM */ 
		double m_drawScale; /* REM */ 
		double m_lineThickness; /* REM */ 
		double m_alpha; /* REM */ 
		double m_fillAlpha; /* REM */ 
		double m_xformScale; /* REM */ 
		static int e_shapeBit; /* REM */ 
		static int e_jointBit; /* REM */ 
		static int e_aabbBit; /* REM */ 
		static int e_pairBit; /* REM */ 
		static int e_centerOfMassBit; /* REM */ 
		static int e_controllerBit; /* REM */ 
};

} // end namespace box2D
} // end namespace dynamics

#endif /* INCLUDED_box2D_dynamics_B2DebugDraw */ 
