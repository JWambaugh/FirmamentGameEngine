
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

/*
	Class: FEntityEmitterComponent
	emits the specified entities when an event is fired.
*/
class FEntityEmitterComponent extends FEntityComponent{

	public function new(){
		super();
		
	}

	override public function init(config:FConfig){

		on(_entity,config.get('listen',String),function(e:FEvent){
            
            var amount:Int = config.get('amount', Int, 1);
            FLog.debug("amount to spawn: "+amount);
            for(n in 0...amount){
				var ent = FEntityFactory.createEntity(
						config.getNotNull('entity',Dynamic));
				var angle:Float;
				if(config.get("angleOffset",String)=="random"){
					angle = Math.random()*6.28318530718;
				}else{
					angle=config.get("angleOffset",Float);
				}
				
				var originEntity = _entity;
				
				//if event received is an entity event, use that entity as the origin instead
				if(Std.is(e,FEntityEvent)){
					originEntity = cast(e,FEntityEvent).getEntity();
				}
				
				FEntityUtils.emitEntity(originEntity
					,ent
					,config.get("speed",Float,0)
					,angle
					,config.get("distanceOffset",Float,0.01) ); 
				ent.setActive(true);
            }
            var trigger = config.get('trigger',String);
            if(trigger != null){
                _entity.trigger(new FEvent(trigger));
            }
		});
		
	}
		
	

	override public function getType(){
		return "entityEmitter";
	}	

	

}