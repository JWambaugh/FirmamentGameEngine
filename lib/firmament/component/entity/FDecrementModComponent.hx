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

class FDecrementModComponent extends FEntityComponent{
    var _deathEvent:String;
    var _propertyName:String;
    var _min:Int;
    var _decSize:Int;
    var _startValue:Int;

    public function new(gameInstance:firmament.core.FGame){
        super(gameInstance);
    }

    override public function init(config:firmament.core.FConfig){
        _startValue = config.getNotNull('startValue',Int);
        var dEvent:String = config.getNotNull('decrementEvent',String,
                                config.getNotNull('listen',String) ); // compatibility changes
        _deathEvent = config.getNotNull('deathEvent',String,
                                config.getNotNull('trigger',String) );  // compatibility changes
        _propertyName = config.getNotNull('property',String);
        _decSize = Math.floor( Math.max(1,config.get('decrementSize', Int, 0)));
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
        var h = _entity.getProp(_propertyName);
        h-=_decSize;
        if(h<=_min) {
            _entity.trigger(new FEvent(_deathEvent));
        }
        var inc:Int = _startValue - _min;
        while(h<=_min) {
            h+=inc;
        }
        _entity.setProp(_propertyName, h);
        
        
    }
}