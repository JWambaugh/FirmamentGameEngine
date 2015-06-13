package firmament.core;

import firmament.component.base.FEntityComponent;
import firmament.component.base.FEntityComponentFactory;
import firmament.core.FConfig;
import firmament.core.FEntity;
import firmament.core.FObject;
import firmament.core.FProperty;
import firmament.util.FLog;
import firmament.util.loader.FDataLoader;

class FEntityFactory{

	public static function createEntity(config:Dynamic,?gameInstanceName:String='main'):FEntity{
		var entity:FEntity;
		if(Std.is(config,String)){
			//pool support
			var str:String = config;
			//if string starts with "pool:" then get the entity from the specified pool
			if(str.indexOf("pool:") == 0){
				str = str.substr(5);
				return FGame.getInstance(gameInstanceName).getPoolManager().getPool(str).getEntity();
			}
			config = FDataLoader.loadData(str);
		}
		
		if(Std.is(config.className, String)){
			var c =Type.resolveClass(config.className);
			if(c==null){
				throw "class "+config.className+" could not be found. Did you remember to include the whole package name?";
			}
			entity = Type.createInstance(c,[config,gameInstanceName]);
		} else {
			entity = new FEntity(config,gameInstanceName);
		}
        var game = FGame.getInstance(gameInstanceName);
		applyComponents(entity,config, game);
        entity.registerComponentProperties();
        applyProperties(entity, config);
		initComponents(entity,config);

        for(c in entity.getAllComponents()){
            c.afterInit();
        }
		entity.trigger(new FEvent(FEntity.COMPONENTS_INITIALIZED));
		return entity;
	}


	public static function applyComponents(entity:FEntity, config:Dynamic, game:firmament.core.FGame){
		if(config.components == null){
			throw("no components specified in entity config.");
		}

        if(Std.is(config.components, Array) ){
            var ca:Array<Dynamic> = cast config.components;
            for(cConfig in ca){
                var component = FEntityComponentFactory.createComponent(cConfig.componentName,game);
                component.setConfig(cConfig);
                entity.setComponent(component);
            }
        }
        else{
            for(componentKey in Reflect.fields(config.components)){
                var cConfig= Reflect.field(config.components,componentKey);
                var component = FEntityComponentFactory.createComponent(cConfig.componentName,game);
                component.setConfig(cConfig);
                entity.setComponent(component);
            }
        }
		
	}


	public static function initComponents(entity:FEntity, config:Dynamic){
		for(component in entity.getAllComponents()){
			component._init(component.getConfig());
		}
	}

	public static function applyProperties(entity:FEntity, config:FConfig){
        
		if(config.hasField('properties')){
            var props:FConfig = config.get('properties');
			for (key in props.fields()) {
                var property:FProperty;
                var type:Dynamic;
                var value:Dynamic;
                try {
                	property = entity.getProperty(key);	
                	type = property.type;
                } catch (e:Dynamic) {
					type = Type.resolveClass( props.get([key,"type"],String,"Float") );
					property = FProperty.createBasic(key,type);
					entity.registerProperty(property);
                }
                value = props.get([key,"value"], type, 
                				props.getNotNull(key, type) 
                			);
                FLog.debug( 'Property ' + key + ' -> ' + value );
				entity.setProp(key,props.get(key,property.type));
			}
		}
	}

}


