
package firmament.component.event;

import firmament.component.base.FEntityComponent;
import firmament.core.FConfig;
import firmament.core.FEntity;
import firmament.core.FEvent;
import firmament.process.timer.FTimer;
/*
    Class: FEventMapperComponent
    maps events on the entity of a type to another event of a different type.
*/
class FTimerComponent extends FEntityComponent{
    

    var timer:FTimer;
    public function new(){
        super();
        
    }

    override public function init(config:FConfig){
        var startOn:String = config.get('startOn',String);
        
        var callbackFunc = function(){
            _entity.trigger(new FEvent(config.getNotNull('trigger',String)));
        }

        var startTimerFunc = function(E:FEvent=null){
            var tm = _entity.getGameInstance().getGameTimerManager();
            timer = tm.addTimer(config.getNotNull('seconds',Float),callbackFunc,this);
        }

        //start timer now unless specified
        if(startOn == null && !_entity.isActive()){
            startTimerFunc();
               
        }else{
            _entity.on(startOn,this,startTimerFunc);
        }

        //pause and unpause the timer as the entity changes active states
        _entity.on(FEntity.ACTIVE_STATE_CHANGE,this,function(e:FEvent){
            if(_entity.isActive()){
                if(config.get('startOn',String)==null){
                    startTimerFunc();
                }
            
            }else{
                if(timer!=null)timer.cancel();
                timer = null;
            }

        });

        
    }

    override public function getType(){
        return "timer";
    }   

}