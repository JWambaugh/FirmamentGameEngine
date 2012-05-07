package firmament.core;

/**
 * Interface: FWorldPositionalInterface 
 * 
 * @author Jordan Wambaugh
 */

interface FWorldPositionalInterface 
{
	public function setPosition(pos:FVector):Void;
	
	public function getPosition():FVector;
	
	public function getPositionX():Float;
	
	public function getPositionY():Float ;
	
	
}