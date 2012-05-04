package firmament.utils.loader;
import firmament.core.FEntity;
import firmament.core.FPhysicsEntity;
import nme.events.EventDispatcher;

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
class FEntityLoader extends EventDispatcher
{

	private static var _instance:FEntityLoader; 
	
	private function new() {
		super();
	}
	
	public static function getInstance() {
		if (_instance == null) {
				_instance = new FEntityLoader();
		}
		return _instance;
	}
	
	/**
	 * Function: loadEntity
	 */
	public function loadEntity(fileName:String, world:FWorld, config:Dynamic):FEntity {
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
	
	public function loadMap(fileName:String, world:FWorld) {
		var serializer = FSerializerFactory.getSerializerForFile(fileName);
		if (serializer == null) {
			throw ("Appropriate serializer for fileName "+fileName+" could not befound.");
		}
		var string = Assets.getText(fileName);
		var data = serializer.unserialize(string);
		if (data == null) {
			throw("entity data could not be unserialized for "+fileName);
		}
		
		
		if (!Std.is(data.entities, Array)) {
			throw "Entities property is not a valid array. Cannot load map "+fileName;
		}
		
		for (ent in cast(data.entities,Array<Dynamic>)) {
				if (!Std.is(ent.entityFile, String)) {
					throw("entityFile missing for entity while loading " + fileName);
				}
				var config:Dynamic;
				if (Reflect.isObject(ent.config)) {
					config = ent.config;
				}else {
					config = { };
				}
				loadEntity(ent.entityFile, world, config);
		}
		
		
	}
	
}