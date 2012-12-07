package firmament.core;

import firmament.core.FEntity;
import firmament.component.base.FEntityComponent;
import firmament.component.base.FEntityComponentFactory;
import firmament.util.loader.FDataLoader;

class FEntityFactory{

	public static function createEntity(config:Dynamic):FEntity{
		var entity:FEntity;

		//if config is a string, assume it's a file name to be loaded.
		if(Std.is(config,String)){
			//pool support
			var str:String = config;
			//if string starts with "pool:" then get the entity from the specified pool
			if(str.indexOf("pool:") == 0){
				str = str.substr(5);
				return FGame.getInstance().getPoolManager().getPool(str).getEntity();
			}
			config = FDataLoader.loadData(str);
		}
		
		if(Std.is(config.className, String)){
			var c =Type.resolveClass(config.className);
			if(c==null){
				throw "class "+config.className+" could not be found. Did you remember to include the whole package name?";
			}
			entity = Type.createInstance(c,[config]);
		} else {
			entity = new FEntity(config);
		}
		applyComponents(entity,config);
		initComponents(entity,config);
		return entity;
	}


	public static function applyComponents(entity:FEntity, config:Dynamic){
		if(!Std.is(config.components,Dynamic)){
			throw("no components specified in entity config.");
		}
		for(componentType in Reflect.fields(config.components)){
			var cConfig= Reflect.field(config.components,componentType);
			var component = FEntityComponentFactory.createComponent(cConfig.componentName);
			component.setConfig(cConfig);
			entity.setComponent(component);
		}
	}


	public static function initComponents(entity:FEntity, config:Dynamic){
		for(component in entity.getAllComponents()){
			
			component.init(component.getConfig());
		}
	}

}


