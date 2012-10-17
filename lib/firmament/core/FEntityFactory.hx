package firmament.core;

import firmament.core.FEntity;
import firmament.component.base.FEntityComponent;
import firmament.component.base.FEntityComponentFactory;

class FEntityFactory{

	public static function createEntity(config:Dynamic):FEntity{
		var entity:FEntity = new FEntity(config);
		applyComponents(entity,config);
		return entity;
	}


	public static function applyComponents(entity:FEntity, config:Dynamic){
		if(!Std.is(config.components,Dynamic)){
			throw("no components specified in entity config.");
		}
		for(componentName in Reflect.fields(config.components)){
			var component = FEntityComponentFactory.createComponent(componentName);
			entity.setComponent(component);
			component.init(Reflect.field(config.components,componentName));
		}
	}

}


