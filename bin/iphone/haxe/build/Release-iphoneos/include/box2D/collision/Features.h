#ifndef INCLUDED_box2D_collision_Features
#define INCLUDED_box2D_collision_Features

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(box2D,collision,B2ContactID)
HX_DECLARE_CLASS2(box2D,collision,Features)
namespace box2D{
namespace collision{


class Features_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Features_obj OBJ_;
		Features_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Features_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Features_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("Features"); }

		int referenceEdge; /* REM */ 
		virtual int getReferenceEdge( );
		Dynamic getReferenceEdge_dyn();

		virtual int setReferenceEdge( int value);
		Dynamic setReferenceEdge_dyn();

		int _referenceEdge; /* REM */ 
		int incidentEdge; /* REM */ 
		virtual int getIncidentEdge( );
		Dynamic getIncidentEdge_dyn();

		virtual int setIncidentEdge( int value);
		Dynamic setIncidentEdge_dyn();

		int _incidentEdge; /* REM */ 
		int incidentVertex; /* REM */ 
		virtual int getIncidentVertex( );
		Dynamic getIncidentVertex_dyn();

		virtual int setIncidentVertex( int value);
		Dynamic setIncidentVertex_dyn();

		int _incidentVertex; /* REM */ 
		int flip; /* REM */ 
		virtual int getFlip( );
		Dynamic getFlip_dyn();

		virtual int setFlip( int value);
		Dynamic setFlip_dyn();

		int _flip; /* REM */ 
		::box2D::collision::B2ContactID _m_id; /* REM */ 
};

} // end namespace box2D
} // end namespace collision

#endif /* INCLUDED_box2D_collision_Features */ 
