
package firmament.component.ui;

import firmament.component.base.FEntityComponent;
import firmament.core.FEvent;




/**
 * 
 */
class FButtonComponent extends FEntityComponent  {
	var _events:Dynamic;
	public function new(gameInstance:firmament.core.FGame){
		super(gameInstance);
		
	}

	override public function init(config:Dynamic){
		if(Reflect.isObject(config.events)){
			_events = config.events;
		}else{
			throw "events property missing for button component";
		}

		for(event in Reflect.fields(_events)){
			on(_entity,event,function(e:FEvent){
				var eventValue = Reflect.field(_events,event);
				if(Std.is(eventValue,String)){
					_entity.trigger(new FEvent(eventValue));
				}
			});
		}
	}

	override public function getType(){
		return "button";
	}	
}