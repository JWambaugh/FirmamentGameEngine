

package firmament.component.event;

import firmament.component.base.FEntityComponent;
import firmament.core.FConfig;
import firmament.core.FEntity;
import firmament.core.FEvent;
import firmament.core.FProperty;
import firmament.core.FPropertyInterface;
import firmament.core.FVector;
import firmament.process.base.FProcess;
import firmament.process.timer.FTimer;
import firmament.util.FLog;
import haxe.Timer;
/*
    Class: FEventMapperComponent
    maps events on the entity of a type to another event of a different type.
*/

class AnimatorPump extends FProcess {

    private var _currentStep:Float; 
    public var _duration:Float; 
    private var _loop:Bool;
    private var _callee:FTweenerComponent;

    public function new() {
        super();

    }

    public function init(config:FConfig,callee:FTweenerComponent) {
        _callee = callee;
        _currentStep=0.0;

        _duration = config.get("duration",Float,1.0);
        _loop = config.get("loop",Bool,false);
    }

    /*override*/ public function pause() { 
        _isRunning = false; 
    }

    /*override*/ public function resume() { 
        _isRunning = true; 
    }

    /*override*/ public function stop() { 
        _isComplete = true; 
    }

    /*override*/ public function reset() { 
        _currentStep = 0.0; 
        _isComplete = false;
    }

    override public function step(delta:Float) {
        if( _isRunning == false ) { return; }
        if( _isComplete == true ) { return; }
        if( _loop || (_currentStep + delta) < _duration) {
            _callee.processStep(_currentStep,delta,_duration);
        } else {
            _isComplete = true;
            _callee.complete();
        }
        _currentStep += delta;
        super.step(delta);
    }
}

class FTweenerComponent extends FEntityComponent {

    var _pump:AnimatorPump;
    var _processAdded:Bool = false;
    var _events:Map<String,String>; // trigger events
    var _listeners:Map<String,String>;
    var _steps:Map<String,Dynamic>; // precalc steps
    var _props:FConfig;
    var _initialized:Bool;
    var _debug:Bool = false;

    public function new(){
        super();
        _events = new Map();
        _listeners = new Map();
        _steps = new Map<String,Dynamic>();
        _pump = new AnimatorPump();
        _initialized = false;
        _debug = false;
    }

    override public function init(config:FConfig){
        _pump.init(config,this);

        var eventNames:Array<String> = ["pause","resume","stop","reset","step","complete"];
        _debug = config.get("debug",Bool,false);

        var listeners:FConfig = config.get("listen",Dynamic);
        var triggers:FConfig = config.get("trigger",Dynamic);
        for( name in eventNames ) {
            var value:String = triggers.get(name,String,null);
            if( value != null ) {
                _events.set( name, value );
            }
            switch(name) {
                case "complete","step":
                default:
                    if( listeners != null ) {
                        value = listeners.get(name,String,name);
                    }
                    if( value != null ) {
                        _listeners.set(value,name);
                        _entity.on(_entity, value, this, this.onEvent );
                    }
            }
        }
        _props = new FConfig( _config.get("properties") );
        for( prop in _props.fields() ) {
            var property:FProperty = _entity.getProperty( prop );
            var values:FConfig = new FConfig( _props.get(prop) );
            if( _debug ) {FLog.msg( prop + " -> " + property.getDynamic() ); }
            switch( property.type ) {
                case Float,Int:{
                    var start:Float = values.get( "start",property.type,property.getFloat() );
                    var end:Float = values.get( "end",property.type,property.getFloat() );
                    if( _debug ) {FLog.msg( prop + " - " + start ); }
                    _steps.set( prop, (end-start)/(_pump._duration+.0000001) );
                }
                case FVector:{
                    var start:FVector = values.get( "start",property.type,property.getDynamic() );
                    var end:FVector = values.get( "end",property.type,property.getDynamic() );
                    var step:FVector = new FVector(
                            (end.x-start.x)/(_pump._duration+.0000001),
                            (end.y-start.y)/(_pump._duration+.0000001)
                        );
                    _steps.set( prop, step );
                }
            }
        }
        reset();
        if( config.get("paused",Bool,false) == false && _entity.isActive() == true ) {
            resume();
        } else {
            pause();
        }
        _initialized = true;
        _entity.on(FEntity.ACTIVE_STATE_CHANGE,this,onToggleActive);
    }

    public function onEvent(e:FEvent) {
        var target:String = _listeners.get( e.name );
        if( _debug ) { FLog.msg( "Handling message " + e.name + " -> " + target); }
        switch( target ) {
            case "reset": this.reset();
            case "pause": this.pause();
            case "resume": this.resume();
            case "stop": this.stop();
            case "complete": this.complete();
        }
    }

    override public function getType(){
        return "tweener";
    }

    public function onToggleActive(e:FEvent) {
        if( _entity.isActive() == true ) {
            _pump.resume();
        } else {
            _pump.pause();
        }
    }

    /*override*/ public function pause() { 
        _pump.pause();
        if(_initialized == true) {
            _entity.trigger( new FEvent(_events.get("pause")) );
        }
    }

    /*override*/ public function resume() { 
        _pump.resume();
        if(_initialized == true) {
            _entity.trigger( new FEvent(_events.get("resume")) );
        }
    }

    /*override*/ public function stop() { 
        _pump.stop();
        if(_initialized == true) {
            _entity.trigger( new FEvent(_events.get("stop")) );
        }
    }

    /*override*/ public function reset() {
        if( _pump.isComplete() == true || _initialized == false ) {
            _entity.getGameInstance().addProcess( "FTweenerComponent:" + Timer.stamp() +":" + Math.random() ,_pump );
        }
        _pump.reset();
        for( name in _props.fields() ) {
            // if there is no start
            var p:FProperty = _entity.getProperty(name);
            var values:FConfig = new FConfig( _props.get(name) );
            var start:Dynamic = values.get( "start", p.type, null );
            if( _debug ) { FLog.msg( name + " - " + start ); }

            if( start != null ) {
                _entity.setProp( name, start );
            }
        }
        if(_initialized == true) {
            _entity.trigger( new FEvent(_events.get("reset")) );
        }

    }

    /*override*/ public function complete() {
        if(_initialized == true) {
            if( _debug ) {FLog.msg("Firing trigger - complete " + _events.get("complete") );}
            _entity.trigger( new FEvent(_events.get("complete")) );
        }
        // _processAdded = false;// processes is removed when finished
    }

    /*override*/ public function processStep(currentStep:Float,timeDelta:Float,duration:Float) {
        for( prop in _steps.keys() ) {
            var property:FProperty = _entity.getProperty(prop);
            if( _debug && Math.random() < .1) {FLog.msg( prop + " >> " + property.getDynamic() ); }
            switch(property.type){
                case Float,Int:{
                    var step:Float = _steps.get(prop);
                    var current:Float = property.getFloat() + step*timeDelta;
                    _entity.setProp(prop, current );
                }
                case FVector:{
                    var current:FVector = property.getDynamic();
                    var step:Dynamic = _steps.get(prop);
                    current.x+=step.x*timeDelta;
                    current.y+=step.y*timeDelta;
                    _entity.setProp(prop,current);
                }
            }
        }
        _entity.trigger( new FEvent(_events.get("step"),[currentStep,timeDelta,duration]) );
    }

}