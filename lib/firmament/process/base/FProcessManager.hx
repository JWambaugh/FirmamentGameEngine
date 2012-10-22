package firmament.process.base;

/**
 * ...
 * @author Jordan Wambaugh
 */

class FProcessManager 
{
	var processQueue:Array<FProcessInterface>;
	var iteration:UInt;
	
	public function new() 
	{
		processQueue = new Array<FProcessInterface>();
		iteration = 0;
	}
	
	public function addProcess(p:FProcessInterface) {
		processQueue.push(p);
		p.beforeStart(this);
	}
	
	/**
	 * Runs a step for each registered process.
	 */
	public function step() {
		iteration++;
		for (p in processQueue) {
			p.step();
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