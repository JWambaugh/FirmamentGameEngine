
package firmament.component.sound;

import firmament.component.base.FEntityComponent;
import firmament.sound.FSoundManager;
import nme.events.Event;
class FSoundComponent extends FEntityComponent  {
	var _events:Dynamic;
	public function new(){
		super();
		
	}

	override public function init(config:Dynamic){
		if(Reflect.isObject(config.events)){
			_events = config.events;
		}else{
			throw "map property missing for eventMap";
		}

		for(event in Reflect.fields(_events)){
			addEventListenerToEntity(event,function(e:Event){
				var sound = FSoundManager.getSound(Reflect.field(Reflect.field(_events,event),"fileName"));
				if(sound!=null)sound.play();
				else{
					trace("Can't find sound "+Reflect.field(_events,event));
				}

			});
		}
	}

	override public function getType(){
		return "eventMapper";
	}	
	

}