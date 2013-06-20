package firmament.process.base;

import haxe.Timer;
import flash.events.EventDispatcher;
import flash.events.Event;
/**
 * ...
 * @author Jordan Wambaugh
 */

class FProcessManager extends flash.events.EventDispatcher
{
	var _processQueue:Array<FProcessInterface>;
	var _iteration:Int;
	var _frameDelta:Float; // in seconds
	var _lastTime:Float; // in seconds
	var _paused:Bool;
	var _stepTime:Float;
	public static inline var PAUSED = "paused";
	public static inline var UNPAUSED = "unpaused";

	public function new() 
	{
		super();
		_paused = false;
		_processQueue = new Array<FProcessInterface>();
		_iteration = 0;
		_lastTime = 0; // Timer.stamp();
		_frameDelta = .03;
	}

	public function getFrameDelta():Float {
		return _frameDelta;
	}
	
	public function getIteration(){
		return _iteration;
	}

	public function addProcess(p:FProcessInterface) {
		_processQueue.push(p);
		p.beforeStart(this);
	}
	
	/**
	 * Runs a step for each registered process.
	 */
	public function step() {
		if(_paused)return;
		if(_lastTime == 0) {
		    _lastTime = Timer.stamp();
		} else {
			var ctime = Timer.stamp();
			_frameDelta = ctime - _lastTime;
			_lastTime = ctime;
		}
		_iteration++;
		for (p in _processQueue) {
			if(!p.isComplete()){
				p.step();
			}
		}
		//clean up left over processes every 10 steps
		if (_iteration % 10 == 0) {
			cleanupProcesses();
		}
		_stepTime = Timer.stamp() - _lastTime;
	}
	
	private function cleanupProcesses() {
		for (p in _processQueue) {
			if (p.isComplete()) {
				_processQueue.remove(p);
				p.afterFinish();
			}
		}
	}
	
	/**
	 * attempts to abort a process
	 * @param	p
	 */
	public function abortProcess(p:FProcessInterface) {
		if (p.isRunning() ) {
			if (!p.beforeAbort()) {
				throw "Cannot abort process";
			}
		}
		_processQueue.remove(p);
	}

	/**
	 * Pauses all processes in the manager
	 */
	public function pause(){
		var ctime = Timer.stamp();
		_frameDelta = ctime - _lastTime;
		_paused = true;
		this.dispatchEvent(new Event(PAUSED));
	}


	/**
	 * Unpauses all processes in the manager
	 */
	public function unPause(){
		_lastTime = Timer.stamp() - _frameDelta;
		_paused = false;
		this.dispatchEvent(new Event(UNPAUSED));

	}

	public function isPaused():Bool{
		return _paused;
	}

	public function destruct(){
		_processQueue = null;
	}

	public function getLastStepTime():Float{
		return _stepTime;
	}
	
}