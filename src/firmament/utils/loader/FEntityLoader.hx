package firmament.utils.loader;
import firmament.core.FEntity;
import firmament.core.FPhysicsEntity;

import firmament.core.FWorld;

import firmament.utils.FMisc;
import firmament.utils.loader.serializer.FSerializerFactory;
import nme.Assets;
/**
 * ...
 * @author Jordan Wambaugh
 */

 
 /**
  * Class: FEntityLoader
  */
class FEntityLoader 
{

	
	
	
	
	/**
	 * Function: loadEntity
	 */
	public static function loadEntity(fileName:String, world:FWorld, config:Dynamic):FEntity {
		var serializer = FSerializerFactory.getSerializerForFile(fileName);
		if (serializer == null) {
			throw ("Appropriate serializer for fileName "+fileName+" could not befound.");
		}
		var string = Assets.getText(fileName);
		var data = serializer.unserialize(string);
		if (data == null) {
			throw("entity data could not be unserialized for "+fileName);
		}
		
		FMisc.cloneInto(config,data);
		
		var ent:FEntity;
		if (Std.is(data.className, String)) {
			trace("Classname is set!");
			var c =Type.resolveClass(data.className);
			if(c==null){
				throw "class "+data.className+" could not be found. Did you remember to include the whole package name?";
			}
			ent = Type.createInstance(c, [world,data]);
		}else {
			ent = new FPhysicsEntity(cast(world), data);
		}
		return ent;
		
	}
	
	public static function loadMap(fileName:String, world:FWorld) {
		
	}
	
}