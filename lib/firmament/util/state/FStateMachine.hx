package firmament.util;
import firmament.util.state.FState;

/**
 * ...
 * @author Jordan Wambaugh
 */

class FStateMachine 
{

	private var currentState:FState;
	
	
	public function new() 
	{
		
	}
	
	public function setCurrentState(s:FState) {
		if (this.currentState != null) {
			this.currentState.deactivateState();
		}
		this.currentState = s;
		this.currentState.activateState(this);
	}
	
	public function getCurrentState():FState {
		return this.currentState;
	}
	
	public function call(funcName, ?args=[]) {
		if (this.currentState == null) {
			throw "can't do state call because state is not yet set.";
		}
		Reflect.callMethod(this.currentState, Reflect.field(this.currentState, funcName), args);
	}
	
}