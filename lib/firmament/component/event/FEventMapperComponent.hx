
package firmament.component.event;
import firmament.component.base.FEntityComponent;
import flash.events.Event;


/*
	Class: FEventMapperComponent
	maps events on the entity of a type to another event of a different type.
*/
class FEventMapperComponent extends FEntityComponent{
	var _map:Dynamic;
	public function new(){
		super();
		
	}

	override public function init(config:Dynamic){
		if(Reflect.isObject(config.map)){
			_map = config.map;
		}else{
			throw "map property missing for eventMap";
		}

		for(item in Reflect.fields(_map)){
			addEventListenerToEntity(item,function(e:Event){
				_entity.dispatchEvent(new Event(Reflect.field(_map,e.type)));
			});
		}
	}

	override public function getType(){
		return "eventMapper";
	}	

}