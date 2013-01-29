package firmament.process.timer;
import haxe.Timer;
import firmament.process.timer.FTimerManager;

class FTimer {
	var _callback:Void->Dynamic;
	var _endTime:Float;
	var _callbackScope:Dynamic;
	var _pausedTime:Float;
	var _manager:FTimerManager;


	public function new(seconds:Float, cb:Void->Dynamic, scope:Dynamic, manager:FTimerManager){
		_callback = cb;
		_endTime = Timer.stamp() + seconds;
		_callbackScope = scope;
		_pausedTime = 0;
		_manager = manager;
	}

	public function getEndTime(){
		return _endTime;
	}

	public function step(){
		if(Timer.stamp() >= _endTime){
				if(_callbackScope!=null){
					Reflect.callMethod(_callbackScope,_callback,[]);
				}else{
					_callback();
				}
				return true;
			}else{
				return false;
			}
	}

	public function pause(){
		if(_pausedTime == 0){
			_pausedTime = Timer.stamp();
		}
	}

	public function unPause(){
		if(_pausedTime !=0){
			var delta = Timer.stamp() - _pausedTime;
			_endTime+=delta;
			_pausedTime = 0;
		}
	}

}