
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
				on(_entity,event,this,function(e:FEvent){
					return _entity.getGameInstance().eval(scriptText);
				});
			}
		}
	}

	override public function getType() {
		return "script";
	}

}