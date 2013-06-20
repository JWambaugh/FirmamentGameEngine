
package firmament.component.system;

import firmament.component.base.FEntityComponent;

import flash.events.Event;
import firmament.util.FConfigHelper;

import firmament.util.loader.FSceneLoader;
/**
 * 
 */
class FSceneLoaderComponent extends FEntityComponent  {
	var _events:Dynamic;
	public static inline var SCENE_LOADED_EVENT:String = "sceneLoaded";
	public function new(){
		super();
		
	}

	override public function init(config:Dynamic){
		if(Reflect.isObject(config.events)){
			_events = config.events;
		}else{
			throw "events property missing for scene loader component";
		}

		for(eventName in Reflect.fields(_events)){
			addEventListenerToEntity(eventName,function(e:Event){
				var eventValue = Reflect.field(_events,eventName);
				var ech = new FConfigHelper(eventValue);
				var gameKey = ech.get('game',String,'main');
				var scene = ech.getNotNull('scene',Dynamic);
				FSceneLoader.loadScene(scene,gameKey);
				_entity.dispatchEvent(new Event(SCENE_LOADED_EVENT));
			});
		}
	}

	override public function getType(){
		return "sceneLoader";
	}	
}