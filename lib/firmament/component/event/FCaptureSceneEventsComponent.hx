
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
	Class: FEntityEmitterComponent
	emits the specified entities when an event is fired.
*/
class FCaptureSceneEventsComponent extends FEntityComponent{

	public function new(gameInstance:firmament.core.FGame){
		super(gameInstance);
		
	}

	override public function init(config:FConfig){
		var scene:FScene = FGame.getInstance().getCurrentScene();
	    var events:Array<String> = config.getNotNull("events");
		for(event in events) {
			log("Adding entity listener for " + event);
			scene.on(event,this,this.bubbleEvent);
		}
	}

	public function bubbleEvent(e:FEvent) {
	    FLog.debug("Bubbling event " + e);
		_entity.trigger(e);
	}

	override public function getType(){
		return "captureSceneEvents";
	}

	override public function destruct(){
		var scene:FScene = FGame.getInstance().getCurrentScene();
		var events:Array<String> = _config.getNotNull("events");
		for(event in events) {
			log("Cleaning up listening scene event - " + event);
			scene.removeEventListener(event,this,this.bubbleEvent);
		}
		super.destruct();
	}
}