package firmament.core;

/**
 * Basic process implementation that does nothing. Extend for easy process implementation.
 * @author Jordan Wambaugh
 */

class FProcess implements FProcessInterface
{
	var _isComplete:Bool;
	var _isRunning:Bool;

	public function new() 
	{
		_isComplete = false;
		_isRunning = false;
	}
	
	
	/**
	 * Called when the process is added to the manager queue, before the process is started.
	 */
	public function beforeStart():Void {
		_isRunning = true;
	}
	
	/**
	 * Called after each step. This method should do a bit of work and then finish. Each step should not be too long.
	 */
	public function step():Void {
		
	}
	
	
	/**
	 * Celled if the process is aborted before it is completed.
	 */
	public function beforeAbort():Bool {
		return true;
	}
	
	/**
	 * Should return true if the process is done and may be removed from the queue.
	 * @return
	 */
	public function isComplete():Bool {
		return this._isComplete;
	}
	
	/**
	 * Should return true if the process is currently running.
	 */
	public function isRunning():Void {
		return _isRunning;
	}
	
	
	/**
	 * called after the process has successfully finished, right before it is removed from the queue.
	 */
	public function afterFinish():Void {
		_isRunning = false;
	}
	
	
	
	
}