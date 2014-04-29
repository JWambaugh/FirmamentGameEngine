
package firmament.scene;

import firmament.util.loader.FDataLoader;
import firmament.scene.FSceneComponent;
import firmament.core.FGame;
import firmament.core.FConfig;
import firmament.core.FEvent;

class FSceneScriptComponent extends FSceneComponent {

	private var events:FConfig;

	public function new(gameInstance:FGame) 
	{
		super(gameInstance);
	}

	override public function init(config:FConfig):Void {
		if(Reflect.isObject(config['events'])){
			events = config['events'];
		}else{
			throw "events property missing for eventMap";
		}

		for(key in Reflect.fields(events)){
			var value:FConfig = events[key], scriptText:String;
			scriptText = value.get("eval","String",null);
			if( scriptText == null ) {
				scriptText = FDataLoader.loadFile(value.get("file","String",null));
			}

			if( scriptText != null ) {
				on(_scene,key,function(e:FEvent){
					return _gameInstance.eval(scriptText);
				});
			}
		}
	}

	public function getType() {
		return "script";
	}
}