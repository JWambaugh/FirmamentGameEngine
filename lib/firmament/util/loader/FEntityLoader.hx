package firmament.util.loader;
import firmament.core.FEntity;
import nme.events.EventDispatcher;
#if(cpp)
import sys.io.File;
#end
import firmament.core.FWorld;
import nme.events.Event;
import firmament.util.FMisc;
import firmament.util.loader.serializer.FSerializerFactory;
import nme.Assets;
import firmament.ui.FDialog;
import firmament.core.FEntityFactory;
import firmament.util.loader.FDataLoader;
import firmament.core.FGame;
import firmament.core.FEntityPool;
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
	public function loadEntity(fileName:String, config:Dynamic,?overrideClass=null):FEntity {
		var data = FDataLoader.loadData(fileName);
		FMisc.mergeInto(config,data);
		
		var ent:FEntity;
		
		
		if (overrideClass != null) {
			data.className = overrideClass;
		}

		if(!Std.is(data.typeId,String)){
			data.typeId = fileName;
		}
		
		ent = FEntityFactory.createEntity(data);
		this.dispatchEvent(new FEntityLoadEvent(ENTITY_LOADED,ent));
		return ent;
		
	}
	
	/**
	 * Function: loadMap
	 * Loads a map into the provided world. if overrideClass is provided, all entities will be of that class no matter what.
	 * 
	 * 
	 **/
	public function loadMap(fileName:String, ?overrideClass=null) {
		var data = FDataLoader.loadData(fileName);
		
		
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
				
				loadEntity(ent.entityFile, config,overrideClass);
		}
	}
	

	public function loadPool(fileName,?preAllocate=0){
		var data = FDataLoader.loadData(fileName);
		var pool = new FEntityPool(data,preAllocate);
		FGame.getInstance().getPoolManager().addPool(pool);
		return pool;
	}
}