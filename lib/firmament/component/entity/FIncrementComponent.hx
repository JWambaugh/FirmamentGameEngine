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
import firmament.core.FProperty;
import firmament.core.FPropertyContainer;

class FIncrementComponent extends FEntityComponent{
    var _triggerEvent:String;
    var _updateEvent:String;
    var _propertyName:String;
    var _property:FProperty;
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
        
        _triggerEvent = config.get('trigger',String);
        on( _entity,_config.getNotNull('listen',String),this,onIncEvent );

        var events = config.get('triggers');
        for( event in Reflect.fields(events) ) {
            switch( event.toLowerCase() ){
                case 'update':
                    _updateEvent = Reflect.field(events,event);
                case 'done':
                    _triggerEvent = Reflect.field(events,event);
            }
        }
    }

    private function getPropertyObject( propertyName:String ):FProperty {
        
        var container:FPropertyContainer = _entity; // scene or entity
        if( propertyName.indexOf('@scene.') == 0 ) {
            propertyName = propertyName.substr(7);
            container = _entity.getGameInstance().getCurrentScene();
        } else if ( propertyName.indexOf('@this.') == 0  ) {
            propertyName = propertyName.substr(6);
        } 

        //register the property if it doesn't exist
        if( !container.hasProperty(propertyName) ) {
            container.registerProperty(
                new firmament.core.FBasicProperty<Int>(propertyName));
        }

        return container.getProperty(propertyName);
    }

    private function setupComponent(config:firmament.core.FConfig) {
        _startValue = config.get('startValue',Int,0);
        _propertyName = config.getNotNull('property',String);
        _max = config.get('max', Int, 1);
        _incSize = Math.floor( Math.max(0,config.get('incrementSize', Int, 1)));
        _property = this.getPropertyObject(_propertyName);
        
        var initialValue = _startValue;
        if( config.get("uninitalized",Bool,false) == true ) {
            initialValue -= 1;
        }
        log("Setting initial value - " + initialValue);
        _property.set(initialValue);
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
        var prev = _property.getDynamic();
        var h = prev;
        if(h<_max) { // allows for retriggering when value is changed elsewhere
            _triggered = -1;
        }
        h+= Math.floor(Math.max(0, _config.get('incrementSize', Int, 1)));
        if(_max>0 && h>=_max){
            h=_max;
            if(_triggered == -1) {
                _triggered = 0;
            }
        }
        if( h != prev ) {
            log("Updating value "+ _propertyName +" from "+prev+" to "+h);
            _property.set(h);
            if(_updateEvent != null) {
                _entity.trigger(new FEvent(_updateEvent));
            }
        }
        if( _triggerEvent != null && _triggered == 0) {
            _entity.trigger(new FEvent(_triggerEvent));
            _triggered = 1;
        }
    }
}