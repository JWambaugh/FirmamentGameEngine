package firmament.component.base;

import firmament.component.base.FEntityComponent;

import firmament.component.physics.FBox2DComponent;
import firmament.component.render.FWireframeRenderComponent;
import firmament.component.render.FTilesheetRenderComponent;

class FEntityComponentFactory{
	public static function createComponent(type:String):FEntityComponent {
		var className = getClassFromType(type);
		var c =Type.resolveClass(className);
		if(c==null){
			throw "class "+className+" could not be found.";
		}
		var component:FEntityComponent = Type.createInstance(c,[]);
		if(component == null){
			throw "Component of type "+type+" with class "+className+" could not be instantiated!";
		}
		return component;
	}

	public static function getClassFromType(type:String){
		return switch(type){
			case "box2d":"firmament.component.physics.FBox2DComponent";
			case "wireframe":"firmament.component.render.FWireframeRenderComponent";
			case "tileSheet":"firmament.component.render.FTilesheetRenderComponent";
			default: throw "World type '"+type+"' not found";
		}
	}

}



