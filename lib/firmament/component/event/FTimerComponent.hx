
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
    
    var _timer:FTimer = null;

    public function new(){
        super();
        
    }

    private function stopTimerFunc(E:FEvent=null){
        if(_timer!=null) {
            _timer.cancel();
        }
        _timer = null;
    }

    override public function init(config:FConfig){
        super.init(null);

        var startOn:String = _config.get('startOn',String);
        var stopOn:String = _config.get('stopOn',String);

        var startTimerFunc = function(E:FEvent=null){
            if( _timer != null ) {
                // keep a million instances from running
                //stopTimerFunc(E);
                return;
            }
        
            var tm = _entity.getGameInstance().getGameTimerManager();
            var seconds:Float = _config.getNotNull('seconds',Float);
            log("Starting timer - " + seconds + " " + _config.get('name',String, ""));
            _timer = tm.addTimer(seconds,this.triggerOnExpire,this);
        }

        //start timer now unless specified
        if(startOn == null && _entity.isActive()){
            startTimerFunc();
        }else{
            _entity.on(startOn,this,startTimerFunc);
        }

        if(stopOn != null){
            _entity.on(stopOn,this,stopTimerFunc);
        }

        //pause and unpause the timer as the entity changes active states
        _entity.on(FEntity.ACTIVE_STATE_CHANGE,this,function(e:FEvent){
            if(_entity.isActive()){
                if(_config.get('startOn',String)==null){
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
        stopTimerFunc(null);
        _entity.trigger(new FEvent(this._config.getNotNull('trigger',String)));
    }
}