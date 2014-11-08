
package firmament.process.engine;


import firmament.core.FGame;
import firmament.core.FVector;
import firmament.world.FWorld;
import firmament.core.FPropertyInterface;
import firmament.process.base.FProcess;
import firmament.core.FConfig;
import firmament.core.FProperty;
import Type;

typedef FTweenEntry={
    property:FProperty
    ,targetVal:Dynamic
}

class FLinearTweener extends FProcess {

	private var _object:FPropertyInterface;
	private var _config:FConfig;
    private var _tweenEntries:Array<FTweenEntry>;
    private var _timeRemaining:Float;

	public function new(object:FPropertyInterface, config:FConfig) {
        super();
		_timeRemaining = config.getNotNull("duration", Float);
        _config = config;
        _object = object;
        _tweenEntries = new Array<FTweenEntry>();
        var properties:FConfig=config.getNotNull("properties");
        var relative:Bool = config.get('mode',String,'absolute')=='relative';
        for(propName in properties.fields()){
            var property:FProperty = _object.getProperty(propName);
            var targetVal:Dynamic = properties.getNotNull(propName, property.type);
            if(relative){
                switch(property.type){
                    case Float,Int:{
                        targetVal = property.getFloat()+targetVal;
                    };
                    case FVector:{
                        var currentVal:FVector = property.getDynamic();
                        targetVal.x+=currentVal.x;
                        targetVal.y+=currentVal.y;
                    }
                }
            }
            _tweenEntries.push({
                 property: property
                ,targetVal: targetVal
                });
        }
	}


	override public function step(delta:Float) {
		// TODO: Parent needs to handle these
		if( _isRunning == false ) { return; } 
		if( _isComplete == true ) { return; }
<<<<<<< HEAD
		// TODO: Parent needs to handle these
		var timeDelta = this._manager.getFrameDelta();
		if( _infinite || (_currentStep + timeDelta) < _duration) {
			var pos = getCopyOfFVector(_object.getPosition());
			var angle = _object.getAngle();
			var stepDelta:FVector = new FVector(_step.x*timeDelta,_step.y*timeDelta);
			pos.add(stepDelta);
			angle += _stepAngle * timeDelta;
			_object.setPosition(pos);
			_object.setAngle(angle);
		} else {
			_object.setPosition(_end);
			_object.setAngle(_endAngle);
			_isComplete = true;
=======
>>>>>>> origin/master

        _timeRemaining-=delta;
     

        for(entry in _tweenEntries){
            if(_timeRemaining <= 0.0){
                entry.property.set(entry.targetVal);
                _isComplete = true;
            }else{
                switch(entry.property.type){
                    case Int,Float:{
                        var currentVal = entry.property.getFloat() ;
                        entry.property.set(currentVal +  (entry.targetVal- currentVal)/_timeRemaining*delta);
                    }
                    case FVector:{
                        var currentVal:FVector = entry.property.getDynamic();
                        currentVal.x+=(entry.targetVal.x - currentVal.x)/_timeRemaining*delta;
                        currentVal.y+=(entry.targetVal.y - currentVal.y)/_timeRemaining*delta;
                        entry.property.set(currentVal);
                    }
                }

            }

        }


		super.step(delta);
	}
	
}
