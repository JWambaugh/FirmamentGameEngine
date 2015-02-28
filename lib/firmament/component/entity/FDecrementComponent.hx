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
class FDecrementComponent extends FEntityComponent{
    var _deathEvent:String;
    var _propertyName:String;
    var _min:Int;
    
    var _triggered:Bool = false;
    var _startValue:Int;
    public function new(gameInstance:firmament.core.FGame){
        super(gameInstance);
    }

    override public function init(config:firmament.core.FConfig){
        _startValue = config.getNotNull('startValue',Int);
        var dEvent:String = config.getNotNull('decrementEvent',String);
        _deathEvent = config.getNotNull('deathEvent',String);
        _propertyName = config.getNotNull('property',String);
        
        _min = config.get('min', Int, 0);

        //register the property if it doesn't exist
        if(!_entity.hasProperty(_propertyName))
            _entity.registerProperty(new firmament.core.FBasicProperty<Int>(_propertyName));
        _entity.setProp(_propertyName, _startValue);
        _entity.on(dEvent,onDecEvent);
    }


    override public function getType(){
        return "decrement";
    }

    public function onDecEvent(e:FEvent){
        firmament.util.FLog.debug("got click!");
        var h = _entity.getProp(_propertyName);
        h-= cast _config.get('decrementSize', Int, 1);
        if(h<=_min && !_triggered){
            firmament.util.FLog.debug("you died");
            h=_min;
            _triggered = true;
            _entity.setProp(_propertyName, h);
            _entity.trigger(new FEvent(_deathEvent));
        }else{
            _entity.setProp(_propertyName, h);
        }
        
        
    }
}