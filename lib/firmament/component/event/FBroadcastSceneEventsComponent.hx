package firmament.component.event;

import firmament.component.base.FEntityComponent;
import firmament.core.FEvent;
import firmament.util.FEntityUtils;
import firmament.core.FEntityFactory;
import firmament.core.FEntity;
import firmament.event.FEntityEvent;
import firmament.util.FLog;
import firmament.core.FConfig;
import firmament.scene.FScene;
import firmament.core.FGame;

/*

*/
class FBroadcastSceneEventsComponent extends FEntityComponent{

	public function new(gameInstance:firmament.core.FGame){
		super(gameInstance);

	}

	override public function init(config:FConfig){
		var scene:FScene = FGame.getInstance().getCurrentScene();
		var listeners:FConfig = _config.get("listen");
		var isMap:Bool = false;
		if(listeners == null) {
			listeners = _config.getNotNull("listeners");
			isMap = !Std.is( _config.get("listeners",Dynamic),Array);
		}

		for(evt in listeners.fields() ){
			log("Adding scene broadcaster for " + evt + ( isMap  ? " as <"+listeners.get(evt,String)+">": "" ) );
 			on(_entity,cast(evt,String),this,function(e:FEvent){
				var value:String;
				if( ! isMap ) {value = e.name; } 
				else {value = listeners.get(e.name,String); }
			    log("Triggering scene event for " + e.name + ( e.name != value  ? " as <"+value+">": "" ) );
				scene.trigger(new FEvent(value));
			});
		}
	}

	override public function getType(){
		return "broadcastSceneEvents";
	}
}
