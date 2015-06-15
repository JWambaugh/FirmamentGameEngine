
package firmament.scene.component;

import firmament.core.FConfig;
import firmament.core.FEvent;
import firmament.core.FProperty;
import firmament.scene.FSceneComponent;
import firmament.util.FLog;
import firmament.util.FStatistics;

class FSceneIncrementStatisticsComponent extends FSceneComponent {

	private var _statistics:FStatistics;
	private var _uninitalized:Bool;
	private var _triggered:Bool;
	private var _direction:FProperty->Int;

	public function new(gameInstance:Dynamic) 
	{
		super(gameInstance);
		_statistics = FStatistics.getInstance();
	}

    private function listenEventFunc(E:FEvent=null) {
    	var mod:Int;
    	var propKey:String = _config.get('property',String);
        if( _statistics.hasProperty( propKey ) == false ) {
			throw "Property " + propKey + " does not exist";
		}
		var property:FProperty = _statistics.getProperty(propKey);
		if( _uninitalized == true ) {
			mod = 1;
			_uninitalized = false;
			property.set( _config.get("startValue",Float) );
		} else {
			mod = _direction( property );
		}
		var state = 0;
		while( mod > 0 ) {
			// 1,2,3,4,5
			state++;
			mod >>=1;
			var eventName:String = null;
			if( (mod>>state)&1 == 0 ) {
				break; // skip if there is no flag set
			}
			switch( state ){
				case 1: // start
					eventName = _config.get(['triggers','start'],String,null);
				case 2: // incremented
					eventName = _config.get(['triggers','update'],String,null);
				case 3: // end
					if( !_triggered ) {
						_triggered = true;
						eventName = _config.get(['triggers','done'],String,null);
					}
			}
			if( eventName != null ){
				_scene.trigger(new FEvent( eventName ));
			}
		}
    }

    private function decrement(prop:FProperty):Int {
    	var start:Float = _config.get("startValue",Float);
    	var end:Float = _config.get("endValue",Float);
    	var increment:Float = Math.max(0,_config.get("incrementSize",Float,1));
    	var ret = 0;
    	if( increment == 0 ) {return 0;}
    	var cur = cast( prop.getDynamic(), Float);
    	if( cur > end ) { _triggered = false; }
    	var upd = cur - increment;
    	if( cur != upd ) { ret |= 2; }
    	if( upd <= end ) {
    		upd = end;
    		ret |= 4;
    	}
    	prop.set( upd );
    	return ret;
    }

    private function increment(prop:FProperty):Int {
    	var start:Float = _config.get("startValue",Float);
    	var end:Float = _config.get("endValue",Float);
    	var increment:Float = Math.max(0,_config.get("incrementSize",Float,1));
    	var ret = 0;
    	if( increment == 0 ) {return 0;}
    	var cur = prop.getFloat();
    	if( cur < end ) { _triggered = false; }
    	var upd = cur + increment;
    	if( cur != upd ) {ret |= 2; }
    	if( upd >= end ) {
    		upd = end;
    		ret |= 4;
    	}
    	prop.set( upd );
    	return ret;
    }

	override public function init(config:FConfig):Void {
		_triggered = false;
		// evaluation for error purposes
		var propKey = config.getNotNull('property');
		
		var st = config.getNotNull('startValue',Float);
		var en = config.getNotNull('endValue',Float);
		if( st > en ) {
			_direction = this.decrement;
		} else {
			_direction = this.increment;
		}

		_uninitalized = config.get('uninitalized',Bool,false);

		var eventListen:String = config.getNotNull('listen',String);
        _scene.on(eventListen,this,listenEventFunc);
	}

	override public function destruct(){
        super.destruct();
	}
}