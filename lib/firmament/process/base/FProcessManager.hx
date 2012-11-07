package firmament.process.base;

import haxe.Timer;

/**
 * ...
 * @author Jordan Wambaugh
 */

class FProcessManager 
{
	var processQueue:Array<FProcessInterface>;
	var iteration:Int;
	var frameDelta:Float; // in seconds
	var lastTime:Float; // in seconds
	
	public function new() 
	{
		processQueue = new Array<FProcessInterface>();
		iteration = 0;
		lastTime = 0; // Timer.stamp();
		frameDelta = .03;
	}

	public function getFrameDelta():Float {
		return frameDelta;
	}
	
	public function getIteration(){
		return iteration;
	}

	public function addProcess(p:FProcessInterface) {
		processQueue.push(p);
		p.beforeStart(this);
	}
	
	/**
	 * Runs a step for each registered process.
	 */
	public function step() {
		if(lastTime == 0) {
		    lastTime = Timer.stamp();
		} else {
			var ctime = Timer.stamp();
			frameDelta = ctime - lastTime;
			lastTime = ctime;
		}
		iteration++;
		for (p in processQueue) {
			if(!p.isComplete()){
				p.step();
			}
		}
		//clean up left over processes every 10 steps
		if (iteration % 10 == 0) {
			cleanupProcesses();
		}
	}
	
	private function cleanupProcesses() {
		for (p in processQueue) {
			if (p.isComplete()) {
				processQueue.remove(p);
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
		processQueue.remove(p);
		
		
	}
	
}