
package firmament.component.system;
import firmament.component.base.FEntityComponent;
import firmament.core.FEvent;
import firmament.component.base.FEntityComponentFactory;

/*
	Class: FComponentFactoryComponent
	Adds a component on event fire
*/

class FComponentFactoryComponent extends FEntityComponent{

	var _event: Dynamic;

	public function new(gameInstance:firmament.core.FGame){
		super(gameInstance);
	}

	override public function init(config:Dynamic){
		if (Reflect.isObject(config.events)){
			_event = config.events;
		}else{
			throw "No event fired to trigger new component";
		}

		for(eventName in Reflect.fields(_event)){
			on(_entity,eventName,function(e:FEvent){
				var cConfig = Reflect.field(_event, eventName);
				var component = FEntityComponentFactory.createComponent(cConfig.componentName,_gameInstance);
				component.setConfig(cConfig);
				_entity.setComponent(component);
				component._init(cConfig);
			});
		}
	}

	override public function getType(){
		return "ComponentFactoryComponent";
	}
}