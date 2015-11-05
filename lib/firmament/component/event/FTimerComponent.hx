
package firmament.component.event;

import firmament.component.base.FEntityComponent;
import firmament.core.FConfig;
import firmament.core.FEntity;
import firmament.core.FEvent;
import firmament.process.timer.FTimer;
import firmament.util.FLog;
/*
    Class: FEventMapperComponent
    maps events on the entity of a type to another event of a different type.
*/
class FTimerComponent extends FEntityComponent{

    static var _eventNames:Array<String> = ["start","stop"];    

    var _events:Map<String,String>;
    var _timer:FTimer = null;
    var _start:Float;
    var _seconds:Null<Float>;
    var _propertyName:String;

    public function new(gameInstance:firmament.core.FGame){
        super(gameInstance);        
        _events = new Map();
        _propertyName = null;
    }

    private function resetTimerFunc(E:FEvent=null) {
        if(_timer!=null){
            log("Restarting timer!!");
            stopTimerFunc(E);
            startTimerFunc(E);
        }
    }

    private function stopTimerFunc(E:FEvent=null){
        if(_timer!=null) {
            _timer.cancel();
        }
        _timer = null;
    }

    private function startTimerFunc(E:FEvent=null){
        if( _timer != null ) {
            // triggerOnExpire();
            return;
        }
        _start = 0;
        log("Timer starting - " + _start);
        var tm = _entity.getGameInstance().getGameTimerManager();
        _seconds = _config.getNotNull('seconds',Float);
        log("Starting timer - " + _seconds + " " + _config.get('name',String, ""));
        _timer = tm.addTimer(_seconds,this.triggerOnExpire,this);
        // trigger start event for chaining

        if( _events.exists ("start") == true ){ 
            log("Firing <start> trigger as " + _events.get("start") );
            _entity.trigger(new FEvent(_events.get("start")));
        }
    }

    public function initialize(config:FConfig){
        var paused:Bool = _config.get('paused',Bool,true);
        var startOn:String = _config.get('startOn',String);
        var stopOn:String = _config.get('stopOn',String);

        var triggers:FConfig = _config.getNotNull('triggers',Dynamic,{});
        for( name in _eventNames ) {
            var value:String = triggers.get(name,String,null);
            if( value != null ) { 
                log("Setting trigger event " + name + " " + value );
                _events.set(name,value); 
            }
        }
        
        if(_propertyName != null) {
            _entity.setProp(_propertyName, 0);
        }

        //start timer now unless specified
        if( (paused == false || startOn == null) && _entity.isActive()){
            startTimerFunc();
        }
    }

    override public function init(config:FConfig){
        var paused:Bool = _config.get('paused',Bool,true);
        var startOn:String = _config.get('startOn',String);
        var stopOn:String = _config.get('stopOn',String);
        var reset:String = _config.get('reset',String);

        // create property, also start polling
        _propertyName = _config.get('property',String);
        if(_propertyName != null && !_entity.hasProperty(_propertyName))  {
            _entity.registerProperty(new firmament.core.FBasicProperty<Float>(_propertyName));
            // I need polling if I'm going to be updating the timer
            useStep(true);
        }

        initialize(config);

        if( startOn != null ) {
            on(_entity,startOn,this,startTimerFunc);
        }

        if(stopOn != null){
            on(_entity,stopOn,this,stopTimerFunc);
        }

        if(reset != null){
            on(_entity,reset,this,resetTimerFunc);
        }

        //pause and unpause the timer as the entity changes active states
        on(_entity,FEntity.ACTIVE_STATE_CHANGE,this,function(e:FEvent){
            if(_entity.isActive()){
                if(_config.get('startOn',String)==null || _config.get('paused',Bool,true) == false){
                    startTimerFunc();
                }
            }else{
                stopTimerFunc();
            }
        });
    }

    override public function getType(){
        return "timer";
    }

    override public function step(delta:Float){
        var cur:Float=0;
        if( _timer != null ) {
            _start += delta;
            cur = Math.round((_seconds - _start) * 10)/10;
            if( cur < 0 ) {cur = 0;}
            log("Time left - " + cur );
        }
        _entity.setProp(_propertyName, cur );
    }

    private function triggerOnExpire(){
        var eventName;
        stopTimerFunc(null);
        log("Timer expired");

        if( _events.exists("stop") == true ){ 
            eventName = _events.get("stop");
        } else { 
            // deprecated
            eventName = this._config.getNotNull('trigger',String);
        }
        log("Firing <stop> trigger as " + eventName );
        _entity.trigger(new FEvent(eventName));
    }
}