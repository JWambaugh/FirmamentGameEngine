
package firmament.component.event;
import firmament.component.base.FEntityComponent;
import firmament.core.FEvent;


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
			on(_entity,item,function(e:FEvent){
				_entity.trigger(new FEvent(Reflect.field(_map,e.name)));
			});
		}
	}

	override public function getType(){
		return "eventMapper";
	}	

}