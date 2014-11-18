
package firmament.component.event;

import firmament.util.FLog;
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
    
    var _timer:FTimer;

    public function new(){
        super();
        
    }

    override public function init(config:FConfig){
        var startOn:String = _config.get('startOn',String);
        var stopOn:String = _config.get('stopOn',String);


        var startTimerFunc = function(E:FEvent=null){
            var tm = _entity.getGameInstance().getGameTimerManager();
            var seconds:Float = _config.getNotNull('seconds',Float);
            //FLog.debug("Starting timer - " + seconds + " " + _config.get('name',String, ""));
            _timer = tm.addTimer(seconds,this.triggerOnExpire,this);
        }

        var stopTimerFunc = function(E:FEvent=null){
            if(_timer!=null) {
                //FLog.debug("Stopping timer " + _config.get('name',String, ""));
                _timer.cancel();
            }
            _timer = null;
        }

        //start timer now unless specified
        if(startOn == null && _entity.isActive()){
            //FLog.debug("Starting timer, entity is active");
            startTimerFunc();
        }else{
            //FLog.debug("Delaying timer start");
            _entity.on(startOn,this,startTimerFunc);
        }

        if(stopOn != null){
           // FLog.debug("Adding listener for timer stop");
            _entity.on(stopOn,this,stopTimerFunc);
        }

        //pause and unpause the timer as the entity changes active states
        _entity.on(FEntity.ACTIVE_STATE_CHANGE,this,function(e:FEvent){
            if(_entity.isActive()){
                if(_config.get('startOn',String)==null){
         //           FLog.debug("Starting timer entity became active");
                    startTimerFunc();
                }
            
            }else{
                stopTimerFunc();
            }
        });
    }

    override public function getType(){
        return "timer";
    }

    private function triggerOnExpire(){
       // FLog.debug("Triggering " + this._config.getNotNull('trigger',String) + " " + _config.get('name',String, "") );
        _entity.trigger(new FEvent(this._config.getNotNull('trigger',String)));
    }
}