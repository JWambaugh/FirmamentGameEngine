package firmament.utils.loader;
import firmament.core.FEntity;
import firmament.core.FPhysicsEntity;
import nme.events.EventDispatcher;
#if(cpp)
import sys.io.File;
#end
import firmament.core.FWorld;
import nme.events.Event;
import firmament.utils.FMisc;
import firmament.utils.loader.serializer.FSerializerFactory;
import nme.Assets;
import firmament.ui.FDialog;
/**
 * ...
 * @author Jordan Wambaugh
 */

class FEntityLoadEvent extends Event {
	public var entity:FEntity;
	public function new (name:String, entity:FEntity) {
		super(name);
		this.entity = entity;
	}
}
 
 /**
  * Class: FEntityLoader
  */
class FEntityLoader extends EventDispatcher
{

	private static var _instance:FEntityLoader; 
	public static inline var ENTITY_LOADED = 'entityLoaded';
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
	public function loadEntity(fileName:String, world:FWorld, config:Dynamic,?overrideClass=null):FEntity {
		var serializer = FSerializerFactory.getSerializerForFile(fileName);
		if (serializer == null) {
			throw ("Appropriate serializer for fileName "+fileName+" could not befound.");
		}
		var string = Assets.getText(fileName);
		#if cpp
		if (string == null || string == '') {
			string = File.getContent(fileName);
		}
		#end
		var data = serializer.unserialize(string);
		if (data == null) {
			throw("entity data could not be unserialized for "+fileName);
		}
		data.entityFile = fileName;
		FMisc.cloneInto(config,data);
		
		var ent:FEntity;
		
		var className = null;
		if(Std.is(data.className, String)){
			className = data.className;
		}
		if (overrideClass != null) {
			className = overrideClass;
		}
		if (className!=null) {
			trace("Classname is set!");
			var c =Type.resolveClass(className);
			if(c==null){
				throw "class "+data.className+" could not be found. Did you remember to include the whole package name?";
			}
			ent = Type.createInstance(c, [world,data]);
		}else {
			ent = new FPhysicsEntity(cast(world), data);
		}
		this.dispatchEvent(new FEntityLoadEvent(ENTITY_LOADED,ent));
		return ent;
		
	}
	
	/**
	 * Function: loadMap
	 * Loads a map into the provided world. if overrideClass is provided, all entities will be of that class no matter what.
	 * 
	 * 
	 **/
	public function loadMap(fileName:String, world:FWorld, ?overrideClass=null) {
		var serializer = FSerializerFactory.getSerializerForFile(fileName);
		if (serializer == null) {
			throw ("Appropriate serializer for fileName "+fileName+" could not befound.");
		}
		var string = Assets.getText(fileName);
		#if(cpp)
		if (string == null || string == '') {
			string = File.getContent(fileName);
		}
		#end
		
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
				
				loadEntity(ent.entityFile, world, config,overrideClass);
		}
		
		
	}
	
}