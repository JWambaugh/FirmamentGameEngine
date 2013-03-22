
package firmament.component.event;
import firmament.component.base.FEntityComponent;
import nme.events.Event;
import firmament.util.FEntityUtils;
import firmament.util.FConfigHelper;
import firmament.core.FEntityFactory;
import firmament.core.FEntity;
import firmament.event.FEntityEvent;
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
						var angle:Float;
						if(ec.get("angleOffset",String)=="random"){
							angle = Math.random()*6.28318530718;
						}else{
							angle=ec.get("angleOffset",Float);
						}
						
						var originEntity = _entity;
						
						//if event received is an entity event, use that entity as the origin instead
						if(Std.is(e,FEntityEvent)){
							originEntity = cast(e,FEntityEvent).getEntity();
						}
						
						FEntityUtils.emitEntity(originEntity
							,ent
							,ec.get("speed",Float)
							,angle
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