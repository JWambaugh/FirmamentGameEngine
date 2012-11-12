
package firmament.process.engine;


import firmament.core.FGame;
import firmament.core.FVector;
import firmament.core.FWorld;
import firmament.core.FWorldPositionalInterface;
import firmament.process.base.FProcess;
import Type;

class FLinearTweener extends FProcess {

	private var _object:FWorldPositionalInterface;
	private var _start:FVector; 
	private var _end:FVector;
	private var _step:FVector;
	private var _startAngle:Float;
	private var _endAngle:Float;
	private var _stepAngle:Float;
	private var _currentStep:Float; 
	private var _duration:Float; 
	private var _infinite:Bool;

	private function getCopyOfFVector(pos:FVector):FVector {
		var coords = new FVector(0.0,0.0);
		coords.add(pos);
		return coords;
	}

	public function new(object:FWorldPositionalInterface,parameters:Dynamic,infinite:Bool=false) {
		_step = new FVector(0.0,0.0);
	 	_duration = 0.0;
		_object = object;
	 	_start = getCopyOfFVector(_object.getPosition());
	 	_startAngle = _object.getAngle();
	 	_end = getCopyOfFVector(_start);
	 	_endAngle = _object.getAngle();
		_infinite = infinite;

		trace("FLinearTweener: init, " + parameters);

		if( parameters.start != null) {
			initStart(parameters.start);
			initEnd(parameters.start);
		}
		if( parameters.end != null) {
			initEnd(parameters.end);
		}
		if(parameters.time != null) {
			_duration = parameters.time+0.0;
		}
		_step.x = (_end.x - _start.x) / (_duration+.0000001);
		_step.y = (_end.y - _start.y) / (_duration+.0000001);
		_stepAngle = (_endAngle - _startAngle) / (_duration+.0000001);
		_currentStep=0.0;
		super();
	}

	private function initStart(startParams) {
		_start.x = Math.isNaN(startParams.x)==false?startParams.x+0.0:_start.x;
		_start.y = Math.isNaN(startParams.y)==false?startParams.y+0.0:_start.y;
		_startAngle = Math.isNaN(startParams.angle)==false?startParams.angle+0.0:_startAngle;
	}

	private function initEnd(endParams) { 
		_end.x = Math.isNaN(endParams.x)==false?endParams.x+0.0:_end.x;
		_end.y = Math.isNaN(endParams.y)==false?endParams.y+0.0:_end.y;
		_endAngle = Math.isNaN(endParams.angle)==false?endParams.angle+0.0:_endAngle;
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
		_object.setPosition(_start);
		_object.setAngle(_startAngle);
	}

	override public function step() {
		// TODO: Parent needs to handle these
		if( _isRunning == false ) { return; } 
		if( _isComplete == true ) { return; }
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

		}
		_currentStep += timeDelta;
		super.step();
	}
	
}
