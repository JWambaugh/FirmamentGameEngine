package firmament.util.loader;
import firmament.core.FEntity;
import flash.events.EventDispatcher;
import firmament.world.FWorld;
import flash.events.Event;
import firmament.util.FMisc;
import firmament.util.loader.serializer.FSerializerFactory;
import openfl.Assets;
import firmament.ui.FDialog;
import firmament.core.FEntityFactory;
import firmament.util.loader.FDataLoader;
import firmament.core.FGame;
import firmament.core.FEntityPool;
import firmament.core.FConfig;
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
	public function loadEntity(fileName:String = null, config:FConfig,?overrideClass=null,?gameInstanceName:String='main'):FEntity {
		var data:FConfig;

		if(fileName != null) {
			data = FDataLoader.loadData(fileName);
			FMisc.mergeInto(config,data);
		} else {
			data = config;
		}

		if (overrideClass != null) {
			data['className'] = overrideClass;
		}

		if(!Std.is(data['typeId'],String)){
			data['typeId'] = fileName;
		}
		
		var ent:FEntity;

		ent = FEntityFactory.createEntity(data,gameInstanceName);
		this.dispatchEvent(new FEntityLoadEvent(ENTITY_LOADED,ent));
		return ent;
		
	}
	
	/**
	 * Function: loadMap
	 * Loads a map into the provided world. if overrideClass is provided, all entities will be of that class no matter what.
	 * 
	 * 
	 **/
	public function loadMap(map:Dynamic, ?overrideClass=null,?gameInstanceName:String='main') {
		var data:Dynamic;
		var fileName:String='[data]';
		if(Std.is(map,String)){
			data = FDataLoader.loadData(map);
			fileName = map;
		} else if (Std.is(map, FConfig) || Reflect.isObject(map)){
			data = map;
		} else {
			throw "map is invalid";
		}
		
		if (!Std.is(data.entities, Array)) {
			throw "Entities property is not a valid array. Cannot load map "+fileName;
		}
		
		for (ent in cast(data.entities,Array<Dynamic>)) {

			
			var config:Dynamic;
			if (Reflect.isObject(ent.config)) {
				config = ent.config;
			}else {
				config = { };
			}
			if(ent.entityFile != null && Std.is(ent.entityFile, String)){
				loadEntity(ent.entityFile, config,overrideClass, gameInstanceName);
			} else{
				loadEntity(null,config,overrideClass, gameInstanceName);
			}
		}
	}
	

	public function loadPool(fileName,?preAllocate=0,?gameInstanceName:String='main'){
		var data = FDataLoader.loadData(fileName);
		var pool = new FEntityPool(data,preAllocate);
		FGame.getInstance(gameInstanceName).getPoolManager().addPool(pool);
		return pool;
	}
}