
package firmament.component.system;

import firmament.util.loader.FDataLoader;
import firmament.component.base.FEntityComponent;
import firmament.core.FConfig;
import firmament.core.FEvent;

class FEntityScriptComponent extends FEntityComponent {

	private var events:FConfig;

	public function new() {
		super();
	}

	override public function init(conf:Dynamic) {
		var config:FConfig = conf;
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
				on(_entity,key,function(e:FEvent){
					return _entity.getGameInstance().eval(scriptText);
				});
			}
		}
	}

	override public function getType() {
		return "script";
	}

}