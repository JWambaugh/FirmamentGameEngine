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

class FIncrementModComponent extends FEntityComponent{
    var _triggervent:String;
    var _propertyName:String;
    var _max:Int;
    var _incSize:Int;
    var _startValue:Int;

    public function new(gameInstance:firmament.core.FGame){
        super(gameInstance);
    }

    override public function init(config:firmament.core.FConfig){
        if( !config.hasField('listen') ) {
            throw("Missing field listen");
        }
        _startValue = config.get('startValue',Int,0);
        _triggervent = config.getNotNull('trigger',String);
        _propertyName = config.getNotNull('property',String);
        _incSize = Math.floor(Math.max(1, config.get('IncrementSize', Int, 0)));
        _max = config.get('max', Int, 1);

        //register the property if it doesn't exist
        if(!_entity.hasProperty(_propertyName))
            _entity.registerProperty(new firmament.core.FBasicProperty<Int>(_propertyName));
        _entity.setProp(_propertyName, _startValue);
        _entity.on( cast(_config.getNotNull('listen',String),String) ,onIncEvent );
    }

    override public function getType(){
        return "incrementmod";
    }

    public function onIncEvent(e:FEvent) {
        var h = _entity.getProp(_propertyName);
        h+=_incSize;
        _entity.setProp(_propertyName, h);
        if(h>=_max) {
            h=h%_max;
            _entity.trigger(new FEvent(_triggervent));
        }
    }
}