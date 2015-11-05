package firmament.scene;

import firmament.core.FGame;
import firmament.scene.component.FSceneAudioComponent;
import firmament.scene.component.FSceneDisplayStatisticsComponent;
import firmament.scene.component.FSceneIncrementStatisticsComponent;
import firmament.scene.component.FSceneLoadComponent;
import firmament.scene.component.FScenePauseComponent;
import firmament.scene.component.FSceneSetStatisticsComponent;
import firmament.scene.component.FSceneTiledScrollerComponent;
import firmament.scene.FSceneScriptComponent;
import firmament.util.FLog;

class FSceneComponentFactory{
	public static function createComponent(type:String,game:FGame,?componentKey:String=''):FSceneComponent {
		FLog.msg('Examining scene config ' + type + (componentKey!='' ? " ("+componentKey+")" : "") );
		var className = getClassFromType(type);
		var c =Type.resolveClass(className);
		if(c==null){
			throw "class "+className+" could not be found.";
		}
		var component:FSceneComponent = Type.createInstance(c,[game]);
		FLog.debug(" created instance of " + c);
		//component.setComponentKey(componentKey);
		if(component == null){
			throw "Component of type "+type+" with class "+className+" could not be instantiated!";
		}
		FLog.debug(" component sucessfully created");
		return component;
	}

	public static function getClassFromType(type:String){
		var map = {
			"script":"firmament.scene.FSceneScriptComponent"
			,"pause":"firmament.scene.component.FScenePauseComponent"
			,"load":"firmament.scene.component.FSceneLoadComponent"
			,"soundTrack":"firmament.scene.component.FSceneAudioComponent"
			,"tiledScroller":"firmament.scene.component.FSceneTiledScrollerComponent"
			,"displayStats":"firmament.scene.component.FSceneDisplayStatisticsComponent"
			,"setStat":"firmament.scene.component.FSceneSetStatisticsComponent"
			,"incrementStat":"firmament.scene.component.FSceneIncrementStatisticsComponent"
		};

		var cls = Reflect.field(map,type);
		if(cls == null) { 
			FLog.debug(" assuming class path " + type);
			return type;
		};
		FLog.debug(" found class name from type " + cls);
		return cls;
	}

}
