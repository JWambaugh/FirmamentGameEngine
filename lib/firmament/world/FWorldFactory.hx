package firmament.world;

import firmament.world.FNoPhysicsWorld;
import firmament.world.FBox2DWorld;

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
			case "box2d" : "firmament.world.FBox2DWorld";
			case "noPhysics" : "firmament.world.FNoPhysicsWorld";
			default: throw "World type '"+type+"' not found";
		}
	}

}



