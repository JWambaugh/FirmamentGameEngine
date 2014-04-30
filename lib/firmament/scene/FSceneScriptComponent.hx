
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

		for(event in Reflect.fields(events)){
			var value:FConfig = events[event], scriptText:String = null;
			for( field in Reflect.fields(value) ) {
				var val = value.get(field,String,null);
				switch(field) {
					case "file":
						scriptText = FDataLoader.loadFile(val);
						break;
					default:
						scriptText = val;
						break;
				}
			}
			trace("Processing <"+event+"> -> " + scriptText );
			if( scriptText != null ) {
				on(_scene, event, this,function(e:FEvent){
					return _gameInstance.eval(scriptText);
				});
			}
		}
	}

	public function getType() {
		return "script";
	}
}