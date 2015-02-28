package firmament.component.physics;
import firmament.core.FVector;
import firmament.world.FWorld;
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
	 * Sets the position of the entity.
	 *
	 */
	public function setPositionXY(x:Float,y:Float):Void;
	
	/**
	 * Function: getPosition
	 * 
	 * Returns:
		 * <FVector>
	 */
	public function getPosition(p:FVector=null):FVector;
	
	/**
	 * Function: getPositionX
	 * 
	 * Returns:
		 * Float
	 */
	public function getPositionX(p:Float=0):Float;
	
	/**
	 * Function: getPositionY
	 * 
	 * Returns:
		 * Float
	 */
	public function getPositionY(p:Float=0):Float;
	
	/**
	 * Function: getAngle
	 * 
	 * Returns:
		 * Float
	 */
	public function getAngle(p:Float=0):Float;
	
	/**
	 * Function: setAngle
	 * 
	 * Returns:
		 * Float
	 */
	public function setAngle(a:Float):Void ;
	
	public function getPositionZ(p:Float=0):Float;

	public function setPositionZ(p:Float):Void;

	public function setWorld(world:FWorld):Void;

	public function getWorld():FWorld;

	public function applyLinearForce(v:FVector,?point:FVector=null):Void;

	public function setLinearVelocity(v:FVector):Void;

	public function getLinearVelocity(p:FVector=null):FVector;

	public function setAngularVelocity(omega:Float):Void ;

	public function getAngularVelocity(p:Float=0):Float;

	public function addAngularVelocity(omega:Float):Void;

	public function getShapes():Array<FShape>;

}