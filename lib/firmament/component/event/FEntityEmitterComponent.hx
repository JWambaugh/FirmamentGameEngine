
package firmament.component.event;
import firmament.component.base.FEntityComponent;
import nme.events.Event;
import firmament.util.FEntityUtils;
import firmament.util.FConfigHelper;
import firmament.core.FEntityFactory;

/*
	Class: FEntityEmitterComponent
	emits the specified entities when an event is fired.
*/
class FEntityEmitterComponent extends FEntityComponent{

	public function new(){
		super();
		
	}

	override public function init(config:Dynamic){
		if(Reflect.isObject(config.emitters)){
			for(event in Reflect.fields(config.emitters)){
				var emitter = Reflect.field(config.emitters,event);

				if(Reflect.isObject(emitter)){
					var ec = new FConfigHelper(emitter);
					addEventListenerToEntity(event,function(e:Event){
						var ent = FEntityFactory.createEntity(ec.getNotNull('entity',Dynamic));
						FEntityUtils.emitEntity(_entity
							,ent
							,ec.get("speed",Float)
							,ec.get("angleOffset",Float) 
							,ec.get("distanceOffset",Float) ); 
						ent.setActive(true);
					});
				}else throw "emitter type of '"+event+"' is not an object";
			}
		}else{
			throw "emitters property not valid for entity emitter.";
		}
	}

	override public function getType(){
		return "entityEmitter";
	}	

	

}