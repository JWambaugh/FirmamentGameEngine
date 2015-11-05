package firmament.process.base;
import firmament.process.base.FProcessManager;
import firmament.core.FEvent;
/**
 * Basic process implementation that does nothing. Extend for easy process implementation.
 * @author Jordan Wambaugh
 */

class FProcess extends firmament.core.FObject implements FProcessInterface
{

	public static inline var COMPLETE:String = "FProcess.COMPLETE";

	var _isComplete:Bool;
	var _isRunning:Bool;
	var _manager:FProcessManager;

	public function new() 
	{
		super();
		_isComplete = false;
		_isRunning = false;
	}
	
	
	/**
	 * Called when the process is added to the manager queue, before the process is started.
	 */
	public function beforeStart(processManager:FProcessManager):Void{
		_manager = processManager;
		_isRunning = true;
	}
	
	/**
	 * Called after each step. This method should do a bit of work and then finish. Each step should not be too long.
	 */
	public function step(delta:Float):Void {
		if(_isComplete){
			this.trigger(new FEvent(FProcess.COMPLETE));
		}
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
	public function isRunning():Bool {
		return _isRunning;
	}
	
	
	/**
	 * called after the process has successfully finished, right before it is removed from the queue.
	 */
	public function afterFinish():Void {
		_isRunning = false;
	}
	
	public function abort(){
        if(_manager!=null){
            _manager.abortProcess(this);
        }
    }
	
	
}