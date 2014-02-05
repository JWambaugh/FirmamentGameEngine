package firmament.world;
import flash.events.Event;
import firmament.core.FEntity;
import haxe.Timer;
import firmament.core.FVector;
/**
 * ...
 * @author Jordan Wambaugh
 */

class FWorld 
{
	
	var entities:Array<FEntity>;
	var lastStep:Float;
	var _alwaysRenderEntities:Array<FEntity>;
	var _config:Dynamic;

	public function new() 
	{
		this.entities = new Array<FEntity>();
		this._alwaysRenderEntities= new Array<FEntity>();
		this.lastStep=Timer.stamp();
	}

	public function init(config:Dynamic){
		_config = config;
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
	public function getTimeSinceLastStep():Float {
		//trace(Timer.stamp() - this.lastStep);
		return Timer.stamp() - this.lastStep;
		
	}
	
	public function deleteEntity(ent:FEntity) {
		this.entities.remove(ent);
		_alwaysRenderEntities.remove(ent);
	}

	public function getType():String{
		return "base";
	}

	public function setGravity(gravity:FVector){
		throw('not implemented');
	}
	
	public function insideStep():Bool{
		return false;
	}

	public function addToAlwaysRenderList(ent:FEntity){
		_alwaysRenderEntities.push(ent);
	}

	public function removeFromAlwaysRenderList(ent:FEntity){
		_alwaysRenderEntities.remove(ent);
	}
	
	public function getAlwaysRenderEntities():Array<FEntity>{
		return _alwaysRenderEntities;
	}

	public function destruct(){
		for (ent in entities){
			ent.delete();
		}
		entities = null;
		_alwaysRenderEntities = null;
	}
}