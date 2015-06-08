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

class FIncrementComponent extends FEntityComponent{
    var _triggervent:String;
    var _propertyName:String;
    var _max:Int;
    var _incSize:Int;
    var _triggered:Int = -1;
    var _startValue:Int;

    public function new(gameInstance:firmament.core.FGame){
        super(gameInstance);
    }

    override public function init(config:firmament.core.FConfig){
        if( !config.hasField('listen') ) {
            throw("Missing field listen");
        }

        setupComponent(config);
        
        _triggervent = config.get('trigger',String);
        _entity.on( cast(_config.getNotNull('listen',String),String) ,onIncEvent );
    }

    private function setupComponent(config:firmament.core.FConfig) {
        _startValue = config.get('startValue',Int,0);
        _propertyName = config.getNotNull('property',String);
        _max = config.get('max', Int, 1);
        _incSize = Math.floor( Math.max(0,config.get('incrementSize', Int, 1)));

        //register the property if it doesn't exist
        if(!_entity.hasProperty(_propertyName))
            _entity.registerProperty(new firmament.core.FBasicProperty<Int>(_propertyName));

        var initialValue = _startValue;
        if( config.get("uninitalized",Bool,false) == true ) {
            initialValue -= 1;
        }
        log("Setting initial value - " + initialValue);
        _entity.setProp(_propertyName, initialValue);
        _triggered = -1;
    }

    override public function onActivate(){
        setupComponent(_config);
    }

    override public function getType(){
        return "increment";
    }

    public function onIncEvent(e:FEvent) {
        // if paused
        if( !_entity.isActive() ) {
            log("Paused - waiting");
            return;
        }
        var h = _entity.getProp(_propertyName);
        if(h<_max) { // allows for retriggering when value is changed elsewhere
            _triggered = -1;
        }
        h+= Math.floor(Math.max(0, _config.get('incrementSize', Int, 1)));
        if(_max>0 && h>=_max){
            h=_max;
            _triggered = 0;
        }
        log("Updating value to " + h);
        _entity.setProp(_propertyName, h);
        if( _triggervent != null && _triggered == 0) {
            _entity.trigger(new FEvent(_triggervent));
            _triggered = 1;
        }
    }
}