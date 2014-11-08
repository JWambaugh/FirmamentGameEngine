

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
        _currentStep = 0; 
        _isComplete = false;
    }

    override public function step(delta:Float) {
        if( _isRunning == false ) { return; }
        if( _isComplete == true ) { return; }
        if( _loop || (_currentStep + delta) < _duration) {
            _callee.processStep(_currentStep,delta,_duration);
        } else {
            _isComplete = true;
            if( Reflect.hasField(_callee,"complete") ) {
                Reflect.callMethod(_callee,Reflect.field(_callee,"complete"),[]);
            }
        }
        _currentStep += delta;
        super.step(delta);
    }
}

class FTweenerComponent extends FEntityComponent {

    var _pump:AnimatorPump;
    var _processAdded:Bool = false;
    var _events:Map<String,String>; // trigger events
    var _steps:Map<String,Dynamic>; // precalc steps
    var _props:FConfig;
    var _initialized:Bool;

    public function new(){
        super();
        _events = new Map();
        _steps = new Map<String,Dynamic>();
        _pump = new AnimatorPump();
        _initialized = false;
    }

    override public function init(config:FConfig){
        _pump.init(config,this);
        if( _processAdded == false ) {
            _processAdded=true;
            _entity.getGameInstance().addProcess( _pump );
        }

        var eventNames:Array<String> = ["pause","resume","stop","reset","step","complete"];
        var listeners:FConfig = config.get("listen",Dynamic);
        var triggers:FConfig = config.get("trigger",Dynamic);
        for( name in eventNames ) {
            var value:String = triggers.get(name,String,name);
            switch(name) {
                case "complete","step": 
                    _events.set( name, value );
                default:
                    _events.set( name, value );
                    if( listeners != null ) {value = listeners.get(name,String,name);}
                    _entity.on(value, this, Reflect.field(this,name) );
            }
        }
        _props = new FConfig( _config.get("properties") );
        for( prop in _props.fields() ) {
            var p = _entity.getProperty( prop );
            var values:FConfig = new FConfig( _props.get(prop) );
            switch( p.type ) {
                case Float,Int:{
                    var start:Float = values.get( "start",p.type,p.getFloat() );
                    var end:Float = values.get( "end",p.type,p.getFloat() );
                    _steps.set( prop, (end-start)/(_pump._duration+.0000001) );
                }
                case FVector:{
                    var start:FVector = values.get( "start",p.type,p.getDynamic() );
                    var end:FVector = values.get( "end",p.type,p.getDynamic() );
                    var step:FVector = new FVector(
                            (end.x-start.x)/(_pump._duration+.0000001),
                            (end.y-start.y)/(_pump._duration+.0000001)
                        );
                    _steps.set( prop, step );
                }
            }
        }
        reset();
        _initialized = true;
        if( config.get("paused",Bool,false) == false && _entity.isActive() == true ) {
            _pump.resume();
        } else {
            _pump.pause();
        }
        _entity.on(FEntity.ACTIVE_STATE_CHANGE,this,onToggleActive);
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
        _pump.reset();
        for( name in _props.fields() ) {
            // if there is no start
            var p:FProperty = _entity.getProperty(name);
            var values:FConfig = new FConfig( _props.get(name) );
            var start:Dynamic = _props.get( name, p.type, null );
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
            _entity.trigger( new FEvent(_events.get("complete")) );
        }
    }

    /*override*/ public function processStep(currentStep:Float,timeDelta:Float,duration:Float) {
        for( prop in _steps.keys() ) {
            var property:FProperty = _entity.getProperty(prop);
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