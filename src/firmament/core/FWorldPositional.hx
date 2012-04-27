package firmament.core;
import firmament.core.FVector;
import nme.events.EventDispatcher;


/**
 * Class: FWorldPositional
 * Extends: <EventDispatcher>
 * Author: Jordan Wambaugh
 */

 
class FWorldPositional extends EventDispatcher
{

	var position:FVector;
	var positionBase:String;
	var angle:Float;
	public function new() {
		super();
		this.position = new FVector(0, 0);
	}
	
	/**
	 * Function: setPosition
	 * 
	 * Parameters:
		 * pos - <FVector>
	 */
	public function setPosition(pos:FVector) {
		this.position = pos;
	}
	
	/**
	 * Function: getPosition
	 * 
	 * Returns:
		 * <FVector>
	 */
	public function getPosition():FVector {
		return this.position;
	}
	
	/**
	 * Function: getPositionX
	 * 
	 * Returns:
		 * Float
	 */
	public function getPositionX():Float {
		return this.position.x;
	}
	
		/**
	 * Function: getPositionY
	 * 
	 * Returns:
		 * Float
	 */
	public function getPositionY():Float {
		return this.position.y;
	}
	
		/**
	 * Function: getAngle
	 * 
	 * Returns:
		 * Float
	 */
	public function getAngle():Float {
		return this.angle;
	}
	
}