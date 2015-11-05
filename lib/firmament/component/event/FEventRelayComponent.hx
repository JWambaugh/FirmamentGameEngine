package firmament.component.event;

import firmament.component.base.FEntityComponent;
import firmament.core.FEntityCollection;
import firmament.core.FEntity;
import firmament.core.FGame;
import firmament.core.FVector;
import firmament.event.FEventRelayEvent;
import firmament.filter.entity.FEntityFilterFactory;
import firmament.filter.entity.FEntityFilterInterface;
import firmament.util.FMisc;
import firmament.core.FEvent;
import firmament.core.FConfig;
import firmament.util.FLog;

class FEventRelayComponent extends FEntityComponent{

	var _eventsToFire:Array<String>;
	var _fireEvent:String;
	var _reflect:Bool;

	public function new(gameInstance:firmament.core.FGame){
		super(gameInstance);
	}

	override public function init(config:FConfig){
		_config = config;

		var events:Array<String> = config.get("listenEvents",Array);
		if( events == null ) {
			events = config.getNotNull("listeners",Array);
		}
		for(e in events){
			on(_entity,e,eventFired);
		}

		_reflect = config.get("reflect",Bool,false);

		_fireEvent = config.get("fireEvent",String);
		if( _fireEvent == null ) {
			_fireEvent = config.get("trigger",String);
			if(_reflect == false) {
				throw "Missing field - trigger, to reflect events, add reflect : true";
			}
		}
	}

	override public function getType(){
		return "eventRelay";
	}

	private function eventFired(e:FEvent){
		var c:Dynamic = {}; // FMisc.deepClone(_config); // caused program to hang
		
		Reflect.setField(c, 'point', _entity.getProp('position') );
		if(Reflect.isObject(_config['topLeft'])) {
			Reflect.setField(c,'topLeft', new FVector(_config['topLeft'].x + c.point.x, _config['topLeft'].y + c.point.y ) );
		}
		if(Reflect.isObject(_config['bottomRight'])){ // ironically this requires the first to have worked
			Reflect.setField(c,'bottomRight', new FVector(_config['bottomRight'].x + c.point.x, _config['bottomRight'].y+ c.point.y ) );
		}
		if(_config.hasField('selector')){
			Reflect.setField(c,'selector',_config.get('selector',String));
		}
		if(Reflect.isObject(_config['filters'])) {
			Reflect.setField(c,'filters', FMisc.deepClone( Reflect.field(_config,'filters' ) ) );

			if( Reflect.hasField(c.filters,'radius') &&
			    ! Reflect.hasField(c.filters.radius,'point') ) {
				Reflect.setField(c.filters.radius,'point', _entity.getProp('position') );
			}
		}

		var entities:FEntityCollection = FGame.getInstance().queryEntities(c,getEntity());
		var relayEvent:String = (_reflect == true) ? e.name : _fireEvent; 
		log("Relaying event " + relayEvent + " -> " + Std.string(entities.length) + " items");
		log( "config - " + Std.string(c) );
		for (ent in entities) {
			log("Relaying to " + ent.getTypeId() );
			ent.trigger(new FEventRelayEvent(relayEvent,_entity,_config));
		}
	}
}
