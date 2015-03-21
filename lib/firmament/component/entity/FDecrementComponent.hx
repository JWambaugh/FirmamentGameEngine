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
    var _decSize:Int;
    
    var _triggered:Bool = false;
    var _startValue:Int;

    public function new(gameInstance:firmament.core.FGame){
        super(gameInstance);
    }

    override public function init(config:firmament.core.FConfig){
        setupComponent(config);

        _deathEvent = config.get('deathEvent',String,
                        config.get('trigger',String) 
                    );  // compatibility changes

        //register the property if it doesn't exist
        var dEvent:String = config.getNotNull('decrementEvent',String,
                                     config.get('listen',String) 
                            ); // compatibility changes

        _entity.on(dEvent,onDecEvent);
    }

    private function setupComponent(config:firmament.core.FConfig) {
        _startValue = config.getNotNull('startValue',Int);
        _min = config.get('min', Int, 0);
        _decSize = Math.floor( Math.max(1,config.get('decrementSize', Int, 0)));

        _propertyName = config.getNotNull('property',String);
        if(!_entity.hasProperty(_propertyName)) {
            _entity.registerProperty(new firmament.core.FBasicProperty<Int>(_propertyName));
        }
        _entity.setProp(_propertyName, _startValue);
        _triggered = false;
    }

    override public function onActivate(){
        setupComponent(_config);
    }

    override public function getType(){
        return "decrement";
    }

    public function onDecEvent(e:FEvent){
        // if paused 
        if( !_entity.isActive() ) {
            log("Paused - waiting");
            return;
        }
        log("got "+e.name+"!");
        var h = _entity.getProp(_propertyName);
        h-= Math.floor(Math.max(1, _config.get('decrementSize', Int, 0)));
        if(h<=_min && !_triggered){
            log("Reached min of " + _min);
            h=_min;
            _triggered = true;
            _entity.setProp(_propertyName, h);
            if(_deathEvent != null){
                _entity.trigger(new FEvent(_deathEvent));
            }
        }else{
            _entity.setProp(_propertyName, h);
        }
        log("Value Remaining - " + _entity.getProp(_propertyName) );
    }
}