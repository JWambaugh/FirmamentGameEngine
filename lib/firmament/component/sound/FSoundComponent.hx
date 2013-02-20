
package firmament.component.sound;

import firmament.component.base.FEntityComponent;
import firmament.sound.FSoundManager;
import nme.events.Event;
import nme.media.SoundTransform;



/**
 * Plays a sound when event(s) are fired on the entity.
 * Example usage:
 * ,sound:{
 *			componentName:"sound"
 *			,events:{
 *				destroyed:{
 *					fileName:"assets/sounds/SciFiMediumExplosion.wav" //This sound is played when the 'destroyed' event is fired on the entity
 *				}
 *			}
 *		}
 */
class FSoundComponent extends FEntityComponent  {
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
				var eventConfig = Reflect.field(_events,event);
				var sound = FSoundManager.getSound(Reflect.field(eventConfig,"fileName"));
				
				if(sound!=null){
					var volume = FSoundManager.getEffectiveSoundVolume();
					var soundChannel = sound.play();
					if(Std.is(eventConfig.volume,Float)){
						volume*=eventConfig.volume;
					}
					var transform = new SoundTransform(volume);
					soundChannel.soundTransform = transform;
				}
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