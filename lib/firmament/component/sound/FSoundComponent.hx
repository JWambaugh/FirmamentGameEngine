
package firmament.component.sound;

import firmament.component.base.FEntityComponent;
import firmament.sound.FSoundManager;
import firmament.core.FEvent;
import firmament.core.FConfig;

import flash.media.SoundTransform;



/**
 * Plays a sound when event(s) are fired on the entity.
 * Example usage:
 * ,sound:{
 *			componentName:"sound"
 *			,events:{
 *				destroyed:{
 *					fileName:"asset/sounds/SciFiMediumExplosion.wav" //This sound is played when the 'destroyed' event is fired on the entity
 *				}
 *			}
 *		}
 */
class FSoundComponent extends FEntityComponent  {
	
	var _events:FConfig;

	public function new(gameInstance:firmament.core.FGame){
		super(gameInstance);
		
	}

	override public function init(config:FConfig){
		// _config = config;

		_events = config.getNotNull("events",Dynamic);

		for(event in _events.fields()){
			on(_entity,event,function(e:FEvent){
				var eventConfig:FConfig = _events.get(event,Dynamic);
				var sound = FSoundManager.getSound( eventConfig.getNotNull("fileName") );

				var volume = FSoundManager.getEffectiveSoundVolume();
				var soundChannel = sound.play();

				volume*= eventConfig.get("volume",Float,1.0);
				var transform = new SoundTransform(volume);
				soundChannel.soundTransform = transform;
			});
		}
	}

	override public function getType(){
		return "sound";
	}	
}