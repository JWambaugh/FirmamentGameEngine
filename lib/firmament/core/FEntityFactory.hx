package firmament.core;

import firmament.core.FEntity;
import firmament.component.base.FEntityComponent;


class FEntityFactory{

	public static function createEntity(config:Dynamic):FEntity{
		var entity:FEntity = new FEntity(config);
	}


	public static function applyComponents(entity:FEntity, config:Dyanamic){
		if(!std.is(config.components,Dynamic)){
			throw("no components specified in entity config.");
		}
		for(var componentName in Reflect.fields(config.components){
			var component = 
		}
	}

}


