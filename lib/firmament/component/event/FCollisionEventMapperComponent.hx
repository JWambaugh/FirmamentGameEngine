
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
	var _tags:Array<String>;
	public function new(gameInstance:firmament.core.FGame){
		super(gameInstance);
		
	}

	override public function init(config:Dynamic){
		if(Reflect.isObject(config.map)){
			_map = config.map;
		}else{
			throw "map property missing for eventMap";
		}
		if(Std.is(config.types,Array)){
			_types = config.types;
			log("Types - " + Std.string(_types));
		}
		if(Std.is(config.tags,Array)){
			_tags = config.tags;
			log("Tags - " + Std.string(_tags));
		}

		for(item in Reflect.fields(_map)){
			on(_entity,item,function(e:FPhysicsCollisionEvent){
				// log("Checking collision - " + Std.string(e));
				// trace("Checking collision - " + Std.string(e));
				if(_types!=null || _tags!=null){
					var otherEnt = e.getOtherEntity(_entity);
					var entType = otherEnt.getTypeId();
					if( _types != null ) {
						//trace("Types - " + Std.string(_types));
						//log("Checking other entity - " + Std.string(entType));
						//trace("Checking other entity - " + Std.string(entType));
						for(type in _types){
							if(type == entType){
								log("Triggering event - " + e.name + " : " + type);
								// trace("Triggering event - " + e.name + " : " + type);
								_entity.trigger(new FEvent(Reflect.field(_map,e.name)));
								break;
							}
						}
					}
					if( _tags != null )
					{
						//trace("Tags - " + Std.string(_tags));
						for(tag in _tags){
							// trace("Tag - " + Std.string(tag));
							// trace("oTag - " + Std.string(otherEnt.getTags() ));
							if( otherEnt.hasTag( tag ) ){
								//log("Triggering event - " + e.name + " : " + tag);
								_entity.trigger(new FEvent(Reflect.field(_map,e.name)));
								break;
							}
						}
					}
				} else {
					log("Triggering event - " + e.name);
					_entity.trigger(new FEvent(Reflect.field(_map,e.name)));
				}
			});
		}
	}

	override public function getType(){
		return "eventMapper";
	}	

}