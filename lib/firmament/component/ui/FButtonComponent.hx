
package firmament.component.ui;

import firmament.component.base.FEntityComponent;

import flash.events.Event;



/**
 * s
 */
class FButtonComponent extends FEntityComponent  {
	var _events:Dynamic;
	public function new(){
		super();
		
	}

	override public function init(config:Dynamic){
		if(Reflect.isObject(config.events)){
			_events = config.events;
		}else{
			throw "events property missing for sound component";
		}

		for(event in Reflect.fields(_events)){
			addEventListenerToEntity(event,function(e:Event){
				var eventValue = Reflect.field(_events,event);
				if(Std.is(eventValue,String)){
					_entity.dispatchEvent(new Event(eventValue));
				}

			});
		}
	}

	override public function getType(){
		return "button";
	}	
}