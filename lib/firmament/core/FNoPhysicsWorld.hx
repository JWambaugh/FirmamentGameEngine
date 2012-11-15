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
import firmament.utils.rtree.RTree;

/**
 * ...
 * @author Jordan Wambaugh
 */

 

 
class FNoPhysicsWorld extends FWorld
{

	
	
	var _inStep:Bool;
	
	var _activeAwakeEntities:Array<FEntity>;
	var _rtree:RTree<FEntity>;
	public function new() 
	{
		super();
		_inStep=false;
		_activeAwakeEntities = new Array<FEntity>();
		_rtree = new RTree<FEntity>(Math.NEGATIVE_INFINITY, Math.NEGATIVE_INFINITY, Math.POSITIVE_INFINITY, Math.POSITIVE_INFINITY, 25, 1e-10, -1e6, -1e6, 1e6, 1e6);
	}
	
	
	override public function step():Void {
		_inStep = true;
		var elapsedTime = FGame.getInstance().getProcessManager().getFrameDelta();
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
	
	public function updateSleepState(component:FNoPhysicsComponent){
		if(component.isSleeping()){
			_activeAwakeEntities.remove(component.getEntity());
		} else{
			_activeAwakeEntities.remove(component.getEntity());
			_activeAwakeEntities.push(component.getEntity());
		}
	}

	public function updatePositionState(component:FNoPhysicsComponent,oldTopX:Float,oldTopY:Float){
		_rtree.updateObject(component.getEntity(),oldTopX,oldTopY,component.getTopX(), component.getTopY(), component.getBottomX(), component.getBottomY());
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
		return _rtree.getObjectsFromPosition(p.x,p.y,200,200);
	}
	
	override public function addEntity(ent:FEntity) {
		super.addEntity(ent);
		var component:FNoPhysicsComponent = cast(ent.getPhysicsComponent());
		
		_rtree.insertObj(ent, component.getTopX(), component.getTopY(), component.getBottomX(), component.getBottomY());
		updateSleepState(component);
	}
	
	override public function getEntitiesInBox(topLeftX:Float,topLeftY:Float,bottomRightX:Float,bottomRightY:Float):Array<FEntity> {
		//right now just returning all entities
		return _rtree.getObjectsFromRange(topLeftX,topLeftY,bottomRightX,bottomRightY,200,200);
		
	}

	
	override public function deleteEntity(ent:FEntity) {
		var component:FNoPhysicsComponent = cast(ent.getPhysicsComponent());
		_rtree.deleteObject(ent,component.getTopX(),component.getTopY());
		super.deleteEntity(ent);

		
		
	}
	
}