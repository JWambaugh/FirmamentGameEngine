
package firmament.component.event;
import firmament.component.base.FEntityComponent;
import firmament.core.FObject;
import firmament.core.FEvent;

import firmament.event.FPhysicsCollisionEvent;


/*
	Class: FCollisionEventMapperComponent
	maps collision events on the entity of a type to another event of a different type, if specified criteria are met.
*/
class FCollisionEventMapperComponent extends FEntityComponent{
	var _map:Dynamic;
	var _types:Array<String>;
	public function new(){
		super();
		
	}

	override public function init(config:Dynamic){
		if(Reflect.isObject(config.map)){
			_map = config.map;
		}else{
			throw "map property missing for eventMap";
		}
		if(Std.is(config.types,Array)){
			_types = config.types;
		}

		for(item in Reflect.fields(_map)){
			on(_entity,item,function(e:FPhysicsCollisionEvent){
				if(_types!=null){
					var otherEnt = e.getOtherEntity(_entity);
					var entType = otherEnt.getTypeId();
					for(type in _types){
						if(type == entType){
							_entity.trigger(new FEvent(Reflect.field(_map,e.name)));
							return;
						}
					}
				}else{
					_entity.trigger(new FEvent(Reflect.field(_map,e.name)));
				}
			});
		}
	}

	override public function getType(){
		return "eventMapper";
	}	

}