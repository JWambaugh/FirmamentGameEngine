
package firmament.component.event;
import firmament.component.base.FEntityComponent;
import flash.events.Event;
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
			addEventListenerToEntity(item,function(e:FPhysicsCollisionEvent){
				if(_types!=null){
					var otherEnt = e.getOtherEntity(_entity);
					var entType = otherEnt.getTypeId();
					for(type in _types){
						if(type == entType){
							_entity.dispatchEvent(new Event(Reflect.field(_map,e.type)));
							return;
						}
					}
				}else{
					_entity.dispatchEvent(new Event(Reflect.field(_map,e.type)));
				}
			});
		}
	}

	override public function getType(){
		return "eventMapper";
	}	

}