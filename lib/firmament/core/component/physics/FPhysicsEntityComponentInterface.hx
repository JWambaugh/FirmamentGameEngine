package firmament.core.component.physics;
import firmament.core.FVector;

/**
 * ...
 * @author Jordan Wambaugh
 */

interface FPhysicsEntityComponentInterface{

	
	
	/**
	 * Function: setPosition
	 * 
	 * Parameters:
		 * pos - <FVector>
	 */
	public function setPosition(pos:FVector);
	
	/**
	 * Function: getPosition
	 * 
	 * Returns:
		 * <FVector>
	 */
	public function getPosition():FVector;
	
	/**
	 * Function: getPositionX
	 * 
	 * Returns:
		 * Float
	 */
	public function getPositionX():Float;
	
		/**
	 * Function: getPositionY
	 * 
	 * Returns:
		 * Float
	 */
	public function getPositionY():Float;
	
	/**
	 * Function: getAngle
	 * 
	 * Returns:
		 * Float
	 */
	public function getAngle():Float;
	
	/**
	 * Function: setAngle
	 * 
	 * Returns:
		 * Float
	 */
	public function setAngle(a:Float):Void ;
	
	
}