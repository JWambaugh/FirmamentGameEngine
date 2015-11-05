package firmament.process.timer;

import firmament.process.base.FProcess;
import firmament.process.base.FProcessManager;

import firmament.process.timer.FTimer;
import firmament.core.FSortedLinkedList;
import firmament.core.FSortedLinkedListCell;
import firmament.core.FEvent;
import haxe.Timer;

class FTimerManager extends FProcess {

	var _timers:FSortedLinkedList<FTimer>;

	public function new(){
		super();
		_timers = new FSortedLinkedList();
	}

	/**
	 * Called when the process is added to the manager queue, before the process is started.
	 */
	override public function beforeStart(processManager:FProcessManager):Void{
		super.beforeStart(processManager);
		processManager.on(FProcessManager.PAUSED, this, pause);
		processManager.on(FProcessManager.UNPAUSED, this, unPause);
		//firmament.util.FLog.debug('TIMER BEFORE START');
	}

	public function addTimer(seconds:Float, cb:Void->Void,?scope:Dynamic=null){
		var timer = new FTimer(seconds,cb,scope,this);
		var cell = _timers.add(timer,Timer.stamp()+seconds);
		timer.setCell(cell);
		return timer;
	}

	override public function step(delta:Float){
		//firmament.util.FLog.debug("TimeManager step");
		var timerCell:FSortedLinkedListCell<FTimer>;

		timerCell = _timers.getLowestCell();
		while(timerCell!=null){
			var result = timerCell.getValue().step(); //run step on the timer
			if(result == true){ //timer DID expire
				_timers.getRemoveLowestCell(); //remove the lowest cell (should be this one)
				timerCell = timerCell.getNext(); //move on to next timer
			}else{
				//if this timer didn't expire, none of the other will either (since we are ordered)
				break;
			}
			
		}
		super.step(delta);
		//firmament.util.FLog.debug(_timers.getCellCount());
	}

	public function pause(e:FEvent=null){
		//firmament.util.FLog.debug("Timer Paused");
		var timerCell:FSortedLinkedListCell<FTimer>;

		timerCell = _timers.getLowestCell();
		while(timerCell!=null){
			timerCell.getValue().pause();
			timerCell = timerCell.getNext();
		}
	}

	public function unPause(e:FEvent=null){
		//firmament.util.FLog.debug("Timer UnPaused");

		var timerCell:FSortedLinkedListCell<FTimer>;

		timerCell = _timers.getLowestCell();
		while(timerCell!=null){
			timerCell.getValue().unPause();
			timerCell = timerCell.getNext();
		}
	}

}