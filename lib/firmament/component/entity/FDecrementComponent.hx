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
    var _updateEvent:String;
    var _propertyName:String;
    var _min:Int;
    var _decSize:Int;

    var _triggered:Int = -1;
    var _startValue:Int;

    public function new(gameInstance:firmament.core.FGame){
        super(gameInstance);
        _deathEvent =null;
        _updateEvent=null;
    }

    override public function init(config:firmament.core.FConfig){
        _deathEvent = config.get('deathEvent',String,
                        config.get('trigger',String)
                    );  // compatibility changes

        var events = config.get('triggers');
        for( event in Reflect.fields(events) ) {
            switch( event.toLowerCase() ){
                case 'update':
                    _updateEvent = Reflect.field(events,event);
                case 'done':
                    _deathEvent = Reflect.field(events,event);
            }
        }

        //register the property if it doesn't exist
        var dEvent:String = config.getNotNull('decrementEvent',String,
                                     config.get('listen',String)
                            ); // compatibility changes
        on(_entity,dEvent,this,onDecEvent);
    }



    override public function onActivate(){
      _startValue = _config.getNotNull('startValue',Int);
      _min = _config.get('min', Int, 0);
      _decSize = Math.floor( Math.max(0,_config.get('decrementSize', Int, 1)));

      _propertyName = _config.getNotNull('property',String);
      if(!_entity.hasProperty(_propertyName)) {
          _entity.registerProperty(new firmament.core.FBasicProperty<Int>(_propertyName));
      }
      _entity.setProp(_propertyName, _startValue);
      _triggered = -1;
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
        var prev = _entity.getProp(_propertyName);
        var h = prev;
        if(h>_min) { // allows for retriggering when value is changed elsewhere
            _triggered = -1;
        }
        h-= Math.floor(Math.max(0, _config.get('decrementSize', Int, 1)));
        if(h<=_min) {
            h=_min;
            if(_triggered == -1) {
                _triggered = 0;
            }
        }
        if( h != prev ) {
            log("Updating value "+ _propertyName +" from "+prev+" to "+h);
            _entity.setProp(_propertyName, h);
            if( _updateEvent != null ) {
                _entity.trigger(new FEvent(_updateEvent));    
            }
        }
        if( _deathEvent != null && _triggered == 0 ) {
            _entity.trigger(new FEvent(_deathEvent));
            _triggered = 1;
        }
    }
}
