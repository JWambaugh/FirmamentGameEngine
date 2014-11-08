

package firmament.component.event;

import haxe.Timer;
import firmament.component.base.FEntityComponent;
import firmament.core.FConfig;
import firmament.core.FEntity;
import firmament.core.FEvent;
import firmament.util.FLog;
import firmament.process.timer.FTimer;
import firmament.process.base.FProcess;
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

    override public function step() {
        // TODO: Parent needs to handle these
        if( _isRunning == false ) { return; }
        if( _isComplete == true ) { return; }
        // TODO: Parent needs to handle these
        var timeDelta = this._manager.getFrameDelta();
        if( _loop || (_currentStep + timeDelta) < _duration) {
            _callee.processStep(_currentStep,timeDelta,_duration);
        } else {
            _isComplete = true;
            if( Reflect.hasField(_callee,"complete") ) {
                Reflect.callMethod(_callee,Reflect.field(_callee,"complete"),[]);
            }
        }
        _currentStep += timeDelta;
        super.step();
    }
}

class FTweenerComponent extends FEntityComponent {

    var _pump:AnimatorPump;
    var _processAdded:Bool = false;
    var _events:Map<String,String>; // trigger events
    var _steps:Map<String,Dynamic>; // precalc steps
    var _count:Int;

    public function new(){
        super();
        _events = new Map();
        _steps = new Map<String,Dynamic>();
        _pump = new AnimatorPump();
    }

    override public function init(config:FConfig){
        _pump.init(config,this);
        if( _processAdded == false ) {
            _processAdded=true;
            _entity.getGameInstance().addProcess( 
                 "FTweenerComponent" + Timer.stamp() + ":" + Math.random(), 
                _pump );
        }

        var eventNames:Array<String> = ["pause","resume","stop","reset","step","complete"];
        var listeners:FConfig = config.get("listen",Dynamic);
        var triggers:FConfig = config.get("trigger",Dynamic);
        for( name in eventNames ) {
            var value:String = triggers.get(name,String,name);
            switch(name) {
                case "complete": 
                    _events.set( name, value );
                case "step":
                    _events.set( name, value );
                default:
                    _events.set( name, value );
                    if( listeners != null ) {value = listeners.get(name,String,name);}
                    _entity.on(value, this, Reflect.field(this,name) );
            }
        }

        _count = 1;
        _pump.reset();
        if( config.get("paused",Bool,false) == false && _entity.isActive() == true ) {
            _pump.resume();
        } else {
            _pump.pause();
        }
        var props:FConfig = new FConfig( _config.get("properties") );
        for( prop in props.fields() ) {
            var p = _entity.getProperty( prop );
            var values:FConfig = new FConfig( props.get(prop) );
            var start:Float = values.get( "start",p.type,_entity.getProp(prop) );
            var end:Float = values.get( "end",p.type,_entity.getProp(prop) );
            _steps.set( prop, (end-start)/(_pump._duration+.0000001) );
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
        _entity.trigger( new FEvent(_events.get("pause")) );
        FLog.msg("pause");
    }

    /*override*/ public function resume() { 
        _pump.resume();
        _entity.trigger( new FEvent(_events.get("resume")) );
        FLog.msg("resume");
    }

    /*override*/ public function stop() { 
        _pump.stop();
        _entity.trigger( new FEvent(_events.get("stop")) );
        FLog.msg("stop");
    }

    /*override*/ public function reset() { 
        _pump.reset();
        _entity.trigger( new FEvent(_events.get("reset")) );
        FLog.msg("reset");
    }

    /*override*/ public function complete() {
        _entity.trigger( new FEvent(_events.get("complete")) );
        FLog.msg("complete");
    }

    /*override*/ public function processStep(currentStep:Float,timeDelta:Float,duration:Float) {
        _count++;
        for( prop in _steps.keys() ) {
            var current:Float = _entity.getProp(prop);
            var step:Float = _steps.get(prop);
// trace("Property - " + prop + " (" + current + "," + step + ")" );
            step*=timeDelta;
            _entity.setProp(prop, current + step );
        }
        _entity.trigger( new FEvent(_events.get("step"),[currentStep,timeDelta,duration]) );
    }

}