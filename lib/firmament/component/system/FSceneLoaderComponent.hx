
package firmament.component.system;

import firmament.component.base.FEntityComponent;

import firmament.core.FEvent;

import firmament.util.loader.FSceneLoader;

import firmament.core.FConfig;

/**
 * 
 */
class FSceneLoaderComponent extends FEntityComponent  {
	var _events:Dynamic;
	public static inline var SCENE_LOADED_EVENT:String = "sceneLoaded";
	public function new(gameInstance:firmament.core.FGame){
		super(gameInstance);
		
	}

	override public function init(config:Dynamic){
		if(Reflect.isObject(config.events)){
			_events = config.events;
		}else{
			throw "events property missing for scene loader component";
		}

		for(eventName in Reflect.fields(_events)){
			on(_entity,eventName,function(e:FEvent){
				var eventValue = Reflect.field(_events,eventName);
				var ech:FConfig = eventValue;
				var gameKey = ech.get('game',String,'main');
				var scene = ech.getNotNull('scene',Dynamic);
				FSceneLoader.loadScene(scene,gameKey);
				_entity.trigger(new FEvent(SCENE_LOADED_EVENT));
			});
		}
	}

	override public function getType(){
		return "sceneLoader";
	}	
}