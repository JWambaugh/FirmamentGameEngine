package firmament.component.event;

import firmament.component.base.FEntityComponent;
import firmament.util.FConfigHelper;
import firmament.util.FMisc;
import firmament.core.FVector;
import firmament.core.FEntity;
import firmament.filter.entity.FEntityFilterInterface;
import firmament.core.FGame;
import nme.events.Event;
import firmament.filter.entity.FEntityFilterFactory;

class FEventRelayComponent extends FEntityComponent{

	

	var _eventsToFire:Array<String>;

	var _fireEvent:String;

	public function new(){
		super();
	}

	override public function init(config:Dynamic){
		_config = config;
		var ch = new FConfigHelper(config);

		var events:Array<String> = ch.getNotNull("listenEvents",Array);
		for(e in events){
			addEventListenerToEntity(e,eventFired);
		}
		_config = config;

		_fireEvent = ch.getNotNull("fireEvent");



	}

	override public function getType(){
		return "eventRelay";
	}

	private function eventFired(e:Event){
		var c = FMisc.deepClone(_config);
		c.point = _entity.getPhysicsComponent().getPosition();
		if(Reflect.isObject(c.topLeft)){
			c.topLeft = new FVector(c.topLeft.x + c.point.x,c.topLeft.y+c.point.y);
		}

		if(Reflect.isObject(c.bottomRight)){
			c.bottomRight = new FVector(c.bottomRight.x + c.point.x,c.bottomRight.y+c.point.y);
		}

		var entities = FGame.getInstance().queryEntities(c);
		
		for (ent in entities){
			ent.dispatchEvent(new Event(_fireEvent));
		}

	}
}











































