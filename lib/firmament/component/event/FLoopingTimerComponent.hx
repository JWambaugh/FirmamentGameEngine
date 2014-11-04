
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
class FLoopingTimerComponent extends FTimerComponent{
    
    public function new(){
        super();
        
    }

    override public function init(config:FConfig){
        super.init(config);
    }

    override public function getType(){
        return "loopingtimer";
    }

    override private function triggerOnExpire() {
        super.triggerOnExpire();
        super.init(this._config);
    }

}