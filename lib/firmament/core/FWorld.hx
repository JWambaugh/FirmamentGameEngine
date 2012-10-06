package firmament.core;
import box2D.dynamics.B2World;
import firmament.core.FEntity;
import haxe.Timer;
/**
 * ...
 * @author Jordan Wambaugh
 */

class FWorld 
{
	
	var entities:Array<FEntity>;
	var lastStep:Float;

	public function new() 
	{
		this.entities = new Array<FEntity>();
		this.lastStep=Timer.stamp();
	}
	public function addEntity(ent:FEntity) {
		this.entities.push(ent);
	}
	
	public function getAllEntities():Array<FEntity> {
		return this.entities;
	}
	
	public function getEntitiesAtPoint(p:FVector):Array<FEntity> {
		throw "Not implemented";
		return null;
	}
	
	
	public function getEntitiesInBox(topLeftX:Float,topLeftY:Float,bottomRightX:Float,bottomRightY:Float):Array<FEntity> {
			throw("Not implemented");
			return null;
		
	}
	public function step():Void {
	}
	
	/**
	 * This should always be called at the end of a step in a subclass.
	 **/
	private function endOfStep(){
		this.lastStep = Timer.stamp();
	}
	
	/**
	 * returns the elapsed time since the last step in seconds.
	 **/
	private function getTimeSinceLastStep():Float {
			//trace(Timer.stamp() - this.lastStep);
		return Timer.stamp() - this.lastStep;
		
	}
	
	public function deleteEntity(ent:FEntity) {
		this.entities.remove(ent);
	}

	public function getType():String{
		return "base";
	}
	
}