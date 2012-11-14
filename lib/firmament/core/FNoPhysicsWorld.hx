package firmament.core;


import firmament.component.physics.FBox2DComponent;
import firmament.core.FEntity;
import firmament.core.FWorld;
import firmament.events.FBox2DCollisionEvent;
import firmament.events.FPhysicsCollisionEvent;
import firmament.ui.FDialog;
import nme.events.Event;
import firmament.core.FGame;
import firmament.process.base.FProcessManager;
import firmament.component.physics.FNoPhysicsComponent;
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
		var elapsedTime = FGame.getInstance().getProcessManager().getFrameDelta();
		trace(_activeAwakeEntities.length);
		for(ent in _activeAwakeEntities){
			var pc = ent.getPhysicsComponent();
			var lv = pc.getLinearVelocity();
			var av = pc.getAngularVelocity();
			if(av!=0){
				pc.setAngle(pc.getAngle() + av * elapsedTime);
			}

			if(lv.x!=0 || lv.y!=0){
				var pos = pc.getPosition();
				pc.setPosition(new FVector(pos.x+lv.x * elapsedTime, pos.y + lv.y * elapsedTime));
			}

		}

		_inStep = false;
		this.endOfStep();
		
		
	}
	
	public function checkSleepingState(component:FNoPhysicsComponent){
		if(component.isSleeping()){
			_activeAwakeEntities.remove(component.getEntity());
		} else{
			trace("not sleeping");
			_activeAwakeEntities.remove(component.getEntity());
			_activeAwakeEntities.push(component.getEntity());
		}
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
	
	override public function addEntity(ent:FEntity) {
		super.addEntity(ent);
		checkSleepingState(cast(ent.getPhysicsComponent()));
	}
	
	override public function getEntitiesInBox(topLeftX:Float,topLeftY:Float,bottomRightX:Float,bottomRightY:Float):Array<FEntity> {
		//right now just returning all entities
		return this.entities;
		
	}
	
}