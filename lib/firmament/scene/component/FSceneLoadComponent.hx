
package firmament.scene.component;

import firmament.core.FConfig;
import firmament.core.FEvent;
import firmament.scene.FSceneComponent;
import firmament.util.loader.FSceneLoader;

class FSceneLoadComponent extends FSceneComponent {

	private static var _events:FConfig;
	// events shouldn't be hardcoded in this file
	public static inline var SCENE_LOADED_EVENT:String = "sceneLoaded";

	public function new(gameInstance:Dynamic) 
	{
		super(gameInstance);
	}

	override public function init(config:FConfig):Void {
		_events = config.get("events");
		for( eventName in _events.fields() ) {
			on(_scene,eventName,function(e:FEvent) {
					var eventValue:FConfig = Reflect.field(_events,eventName);
					var gameKey = eventValue.get('game',String,'main');
					var scene = eventValue.getNotNull('scene',Dynamic);
					FSceneLoader.loadScene(scene,gameKey);
					_scene.trigger(new FEvent(SCENE_LOADED_EVENT));
				});
		}

	}
}