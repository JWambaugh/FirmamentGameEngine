package firmament.process.base;

/**
 * Interface for a process. A process performs a job over a length of time.
 * @author Jordan Wambaugh
 */

interface FProcessInterface 
{

	/**
	 * Called when the process is added to the manager queue, before the process is started.
	 */
	public function beforeStart(processManager:FProcessManager):Void;
	
	/**
	 * Called after each step. This method should do a bit of work and then finish. Each step should not be too long.
	 */
	public function step():Void;
	
	
	/**
	 * Should return true if the process is done and may be removed from the queue.
	 * @return
	 */
	public function isComplete():Bool;
	
	/**
	 * Should return true if the process is currently running.
	 */
	public function isRunning():Bool;
	
	
	/**
	 * called after the process has successfully finished, right before it is removed from the queue.
	 */
	public function afterFinish():Void;
	
	
	
	/**
	 * Celled if the process is aborted before it is completed.
	 * Should return true if can successfully be aborted. If return false, the abortion will fail.
	 */
	public function beforeAbort():Bool;
	
	
	
}