
package firmament.component.event;

import firmament.component.base.FEntityComponent;
import firmament.core.FConfig;
import firmament.core.FEntity;
import firmament.core.FEvent;
import firmament.util.FLog;
import firmament.process.timer.FTimer;
/*
    Class: FEventMapperComponent
    maps events on the entity of a type to another event of a different type.
*/
class FLoopingTimerComponent extends FTimerComponent{
    
    var _paused:Bool = false;

    public function new(gameInstance:firmament.core.FGame){
        super(gameInstance);
        
    }

    override public function init(config:FConfig){
        log("Initialized loopingtimer");
        super.init(config);

        var listeners:FConfig = _config.get('listeners',Dynamic);
        for( listener in listeners.fields() ) {
            switch(listener) {
                case 'unpause':
                    on( _entity,cast(listener,String),this,unpauseHandler);
                    break;
            }
        }
    }

    override public function getType(){
        return "loopingtimer";
    }

    private function unpauseHandler(E:FEvent=null){
        _paused = false;

        // do I need to restart??
    }

    override  private function stopTimerFunc(E:FEvent=null){ 
        if(E != null ) {
            log("Pausing looping timer");
            _paused = true; // stop the looping elements
        }
        super.stopTimerFunc(E);
    }

    override private function startTimerFunc(E:FEvent=null){
        if(_paused == false) {
            log("Starting looping timer");
            super.startTimerFunc(E);
        }
    }

    override private function triggerOnExpire() {
        log("Trigger Expired");
        super.triggerOnExpire();
        super.initialize(this._config);
        _paused = false; // reset so on the next event the timer will start
    }

}