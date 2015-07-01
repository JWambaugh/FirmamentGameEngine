
package firmament.component.event;

import firmament.component.base.FEntityComponent;
import firmament.core.FConfig;
import firmament.core.FEvent;


/*
	Class: FEventMapperComponent
	maps events on the entity of a type to another event of a different type.
*/
class FEventMapperComponent extends FEntityComponent{
	var _map:FConfig;
	public function new(gameInstance:firmament.core.FGame){
		super(gameInstance);
		
	}

	override public function init(config:FConfig){
		try {
			_map = config.getNotNull("map",Dynamic);
			_map.setScope(this); // ironic.  I built a new FConfig and end up missing the pieces from the parent :(
		} catch (e:Dynamic) {
			throw "map property missing for eventMap";
		}
		
		for( item in _map.fields() ) {
			log( "Adding event " + item, false );
			on(_entity,item,function(e:FEvent){
				var eventName = _map.getNotNull(e.name,String);
				log( "Sending event " + e.name + " as " + eventName );
				_entity.trigger(new FEvent( eventName ));
			});
		}
	}

	override public function getType(){
		return "eventMapper";
	}

}