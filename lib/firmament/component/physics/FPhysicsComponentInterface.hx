package firmament.component.physics;
import firmament.core.FVector;
import firmament.core.FWorld;
import firmament.core.FShape;

/**
 * Interface: FPhysicsComponentInterface
 * Author: Jordan Wambaugh
 */

interface FPhysicsComponentInterface{

	public function init(config:Dynamic):Void;
	
	/**
	 * Function: setPosition
	 * 
	 * Parameters:
		 * pos - <FVector>
	 */
	public function setPosition(pos:FVector):Void;
	
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
	
	public function getZPosition():Float;

	public function setZPosition(p:Float):Void;

	public function setWorld(world:FWorld):Void;

	public function getWorld():FWorld;

	public function applyLinearForce(v:FVector,?point:FVector=null):Void;

	public function setLinearVelocity(v:FVector):Void;

	public function getLinearVelocity():FVector;

	public function setAngularVelocity(omega:Float):Void ;

	public function getAngularVelocity():Float;

	public function addAngularVelocity(omega:Float):Void;

	public function getShapes():Array<FShape>;

}