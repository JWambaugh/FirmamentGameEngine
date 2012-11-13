package firmament.core;

import firmament.core.FNoPhysicsWorld;
import firmament.core.FBox2DWorld;

class FWorldFactory{
	public static function createWorld(type:String):FWorld {
		var className = getClassFromType(type);
		var c =Type.resolveClass(className);
		if(c==null){
			throw "class "+className+" could not be found.";
		}
		return Type.createInstance(c,[]);
	}

	public static function getClassFromType(type:String){
		return switch(type){
			case "box2d":"firmament.core.FBox2DWorld";
			case "noPhysics":"firmament.core.FNoPhysicsWorld";
			default: throw "World type '"+type+"' not found";
		}
	}

}



