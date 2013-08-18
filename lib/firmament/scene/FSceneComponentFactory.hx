package firmament.scene;


import firmament.core.FGame;

class FSceneComponentFactory{
	public static function createComponent(type:String,game:FGame,?componentKey:String=''):FSceneComponent {
		var className = getClassFromType(type);
		var c =Type.resolveClass(className);
		if(c==null){
			throw "class "+className+" could not be found.";
		}
		var component:FSceneComponent = Type.createInstance(c,[game]);
		component.setComponentKey(componentKey);
		if(component == null){
			throw "Component of type "+type+" with class "+className+" could not be instantiated!";
		}
		return component;
	}

	public static function getClassFromType(type:String){
		var map = {
			"box2d":"firmament.component.physics.FBox2DComponent"
		};

		var cls = Reflect.field(map,type);
		if(cls == null) return type;
		return cls;
	}

}



