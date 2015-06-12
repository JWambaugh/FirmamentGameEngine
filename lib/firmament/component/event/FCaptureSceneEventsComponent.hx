
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

	private var _mapping:Map<String,String>;

	public function new(gameInstance:firmament.core.FGame){
		super(gameInstance);
		_mapping = new Map();
	}

	override public function init(config:FConfig){
		var scene:FScene = FGame.getInstance().getCurrentScene();
	    var events:FConfig = config.getNotNull("events",Dynamic);
	    events.setScope( config.getScope() ); 
		for(event in events.fields() ) {
			var eventName:String = Std.string(event); 
			var value = events.get(event,String); // this is wierd, if an [] event and value 
			                                      // will be the same.  If and {} event will
			                                      // be value of property
			log("Adding entity listener for " + eventName + ( eventName != value  ? " as <"+value+">": "" ) );
			_mapping.set(eventName,value);
			scene.on(eventName,this,this.bubbleEvent);
		}
	}

	public function bubbleEvent(e:FEvent) {
	    var value = _mapping.get(e.name);
		log("Bubbling event <"+e.name+">" + ( e.name != value  ? " as <"+value+">": "" ) );
		_entity.trigger( new FEvent(value) );
	}

	override public function getType(){
		return "captureSceneEvents";
	}

	override public function destruct(){
		var scene:FScene = FGame.getInstance().getCurrentScene();
		try {
			var events:Array<String> = _config.getNotNull("events");
			for(event in events) {
				log("Cleaning up listening scene event - " + event);
				scene.removeEventListener(event,this,this.bubbleEvent);
			}
		} catch(e:Dynamic) {
			FLog.error( e );
		}
		super.destruct();
	}
}