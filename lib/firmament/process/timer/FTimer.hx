package firmament.process.timer;
import haxe.Timer;
import firmament.process.timer.FTimerManager;
import firmament.core.FSortedLinkedListCell;
class FTimer {
	var _callback:Void->Void;
	var _endTime:Float;
	var _callbackScope:Dynamic;
	var _pausedTime:Float;
	var _manager:FTimerManager;
	var _listCell:FSortedLinkedListCell<FTimer>;
	var _expired:Bool;

	public function new(seconds:Float, cb:Void->Void, scope:Dynamic, manager:FTimerManager){
		_callback = cb;
		_endTime = Timer.stamp() + seconds;
		_callbackScope = scope;
		_pausedTime = 0;
		_manager = manager;
		_expired = false;
	}

	public function setCell(cell){
		_listCell = cell;
	}
	public function getEndTime(){
		return _endTime;
	}

	public function step(){
		if(Timer.stamp() >= _endTime){
				_expired = true;
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

	public function cancel(){
		if(!_expired)
			_listCell.remove();
	}

}