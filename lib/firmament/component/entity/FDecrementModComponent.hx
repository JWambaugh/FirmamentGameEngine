package firmament.component.entity;

import firmament.component.base.FEntityComponent;
import firmament.core.FEntity;
import firmament.core.FGame;
import firmament.component.physics.FBox2DComponent;
import firmament.core.FVector;
import firmament.util.FEntityUtils;
import firmament.event.FPhysicsCollisionEvent;

import firmament.util.FMisc;
import firmament.process.timer.FTimerManager;
import firmament.core.FEvent;
import firmament.component.entity.FDecrementComponent;

class FDecrementModComponent extends FDecrementComponent {
    override public function onDecEvent(e:FEvent){
        var h = _entity.getProp(_propertyName);
        h-=_decSize;
        if(h<=_min) {
            log("Triggered - resetting value");
            _entity.trigger(new FEvent(_deathEvent));
        }
        var inc:Int = _startValue - _min;
        while(h<=_min) {
            h+=inc;
        }
        log("Start - " + _startValue + "\nEnd - " + _min + "\nValue - " + h);
        _entity.setProp(_propertyName, h);
    }
}