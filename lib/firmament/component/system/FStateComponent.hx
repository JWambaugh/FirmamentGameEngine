
package firmament.component.system;

import firmament.util.FConfigHelper;
import firmament.component.base.FEntityComponent;
import flash.events.Event;

class FStateComponent extends FEntityComponent {

	private var _events:Map<String,Dynamic>;
	private var _state:Map<String,Dynamic>;
	private var _stateOperations:Dynamic;

	public function new(){
		super();
		trace("Creating new state object");
		_state = new Map<String,Dynamic>();
		_events = new Map<String,Dynamic>();
		_stateOperations = {};
	}

	override public function init(config:Dynamic){
		// how do I add in the defaults?
		// and apply the event handlers?
		var configHelper = new FConfigHelper(config);

		if(Reflect.isObject(config.events)){
			_events = config.events;
			for(eventName in Reflect.fields(_events)){
				var eventValue = Reflect.field(_events,eventName);
				trace( "Stubbed: Processing event <"+ eventName +"> " + eventValue );
				// TODO: add automatic fix up for state objects
				// addEventListenerToEntity(eventName, this.handleEvent);
			}
		}
	}

	override public function getType(): String {
		return "state";
	}

	public function handleEvent(e:Event): Void {
		trace( "Handling event: " + Std.string(e));
	}

	public function get(name:String):Dynamic {
		if( _state.exists(name) ) {
			trace("Getting <" + name + "> " + Std.string(_state.get(name)) );
			return _state.get(name);
		}
		trace("Getting <" + name + "> Not found!" );
		return false;
	}

	public function set(name:String,value:Dynamic): Void {
		trace("Setting <" + name + "> " + Std.string(value) );
		_state.set(name,value);
	}
}