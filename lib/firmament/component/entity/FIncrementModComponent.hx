package firmament.component.entity;

import firmament.component.base.FEntityComponent;
import firmament.core.FEntity;
import firmament.core.FGame;
import firmament.component.physics.FBox2DComponent;
import firmament.core.FVector;
import firmament.util.FEntityUtils;
import firmament.event.FPhysicsCollisionEvent;
import firmament.component.entity.FIncrementComponent;

import firmament.util.FMisc;
import firmament.process.timer.FTimerManager;
import firmament.core.FEvent;

class FIncrementModComponent extends FIncrementComponent{

    public function new(gameInstance:firmament.core.FGame){
        super(gameInstance);
    }

    override public function getType(){
        return "incrementmod";
    }

    override public function onIncEvent(e:FEvent) {
        var h = _entity.getProp(_propertyName);
        h+=_incSize;
        if(h>=_max) {
            log("Triggered - resetting value");
            _entity.trigger(new FEvent(_triggerEvent));
        }
        var inc:Int = _max - _startValue;
        while(h>=_max) {
            h-=inc;
        }
        log("Start - " + _startValue + "\nEnd - " + _max + "\nValue - " + h);
        _entity.setProp(_propertyName, h);
    }
}