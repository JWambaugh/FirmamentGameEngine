package firmament.core;


import firmament.component.physics.FBox2DComponent;
import firmament.core.FEntity;
import firmament.core.FWorld;
import firmament.events.FBox2DCollisionEvent;
import firmament.events.FPhysicsCollisionEvent;
import firmament.ui.FDialog;
import nme.events.Event;
/**
 * ...
 * @author Jordan Wambaugh
 */

 

 
class FNoPhysicsWorld extends FWorld
{

	
	
	var _inStep:Bool;
	
	var _activeAwakeEntities:Array<FEntity>;
	
	public function new() 
	{
		super();
		_inStep=false;
		_activeAwakeEntities = new Array<FEntity>();
	}
	
	
	override public function step():Void {
		_inStep = true;
		


		_inStep = false;
		this.endOfStep();
		
		
	}
	
	
	override public function getType():String{
		return "noPhysics";
	}


	override public function insideStep():Bool{
		return _inStep;
	}

	override public function getAllEntities():Array<FEntity> {
		return this.entities;
	}
	
	override public function getEntitiesAtPoint(p:FVector):Array<FEntity> {
		throw "Not implemented";
		return null;
	}
	
	
	override public function getEntitiesInBox(topLeftX:Float,topLeftY:Float,bottomRightX:Float,bottomRightY:Float):Array<FEntity> {
		//right now just returning all entities
		return this.entities;
		
	}
	
}