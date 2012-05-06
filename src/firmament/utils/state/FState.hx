package firmament.utils.state;
import firmament.utils.FStateMachine;

/**
 * ...
 * @author Jordan Wambaugh
 */

class FState 
{

	var parentStateMachine:FStateMachine;
	public function new() 
	{
		
	}
	
	public function activateState(machine:FStateMachine) {
		this.parentStateMachine = machine;
	}
	
	public function deactivateState() {
		
	}
	
}