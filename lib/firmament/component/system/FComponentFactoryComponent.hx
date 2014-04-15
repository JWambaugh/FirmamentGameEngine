
package firmament.component.system;
import firmament.component.base.FEntityComponent;
import firmament.core.FEvent;

/*
	Class: FComponentFactoryComponent
	Adds a component on event fire
*/
class FComponentFactoryComponent extends FEntityComponent{

	var _eventFired: Dynamic;

	public function new(){
		super();
	}

	override public function init(){
		if (Reflect.isObject(config.event)){
			_eventFired = event;
		}else{
			throw "No event fired to trigger new component";
		}
	
	}

	override public function getType(){
		return "factoryComponent";
	}
}