
package firmament.component.event;
import firmament.component.base.FEntityComponent;
import firmament.core.FEvent;
import firmament.util.FEntityUtils;
import firmament.util.FConfigHelper;
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

	public function new(){
		super();
		
	}

	override public function init(config:FConfig){
		var scene:FScene = FGame.getInstance().getCurrentScene();
	    var events:Array<String> = config.getNotNull("events");
		for(event in events) {
			FLog.msg("Adding entity listener for " + event);
			scene.on(scene,event,this.bubbleEvent);
		}
	}

	public function bubbleEvent(e:FEvent) {
	    FLog.msg("Bubbling event " + e);
		_entity.trigger(e);
	}

	override public function getType(){
		return "captureSceneEvents";
	}	

	

}