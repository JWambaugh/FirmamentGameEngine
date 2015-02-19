package firmament.world;


import firmament.component.physics.FBox2DComponent;
import firmament.component.physics.FNoPhysicsComponent;
import firmament.core.FEntity;
import firmament.core.FGame;
import firmament.core.FVector;
import firmament.event.FBox2DCollisionEvent;
import firmament.event.FPhysicsCollisionEvent;
import firmament.process.base.FProcessManager;
import firmament.ui.FDialog;
import firmament.util.rtree.RTree;
import firmament.world.FWorld;
import flash.events.Event;

/**
 * ...
 * @author Jordan Wambaugh
 */

 

 
class FNoPhysicsWorld extends FWorld
{

	
	
	var _inStep:Bool;
	
	var _activeAwakeEntities:Array<FEntity>;
	var _rtree:RTree<FEntity>;
	var _deleted:Bool;
	public function new() 
	{
		super();
		_deleted = false;
		_inStep=false;
		_activeAwakeEntities = new Array<FEntity>();
		_rtree = new RTree<FEntity>(Math.NEGATIVE_INFINITY, Math.NEGATIVE_INFINITY, Math.POSITIVE_INFINITY, Math.POSITIVE_INFINITY, 25, 1e-10, -1e6, -1e6, 1e6, 1e6);
	}
	
	
	override public function step():Void {
		if(_deleted){
			firmament.util.FLog.debug("______________TRYING TO STEP IN DELETED NOPHYSICS WORLD");
		}
		_inStep = true;
		var elapsedTime = FGame.getInstance().getProcessManager().getFrameDelta();
		for(ent in _activeAwakeEntities){
			var pc:FNoPhysicsComponent = cast(ent.getPhysicsComponent());
			pc.onWorldStep(elapsedTime);
		}

		_inStep = false;
		this.endOfStep();
		
		
	}
	
	public function updateSleepState(component:FNoPhysicsComponent){
		if(component.isSleeping() || !component.getEntity().isActive()){
			_activeAwakeEntities.remove(component.getEntity());
		} else{
			_activeAwakeEntities.remove(component.getEntity());
			_activeAwakeEntities.push(component.getEntity());
		}
	}

	public function updatePositionState(component:FNoPhysicsComponent,oldTopX:Float,oldTopY:Float){
		if(_deleted){
			firmament.util.FLog.debug("______________TRYING TO POSITION DELETED NOPHYSICS WORLD");
		}
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
		var ret:Array<FEntity> =  _rtree.getObjectsFromPosition(p.x,p.y,200,200);
		if(ret==null){
			return new Array();
		}
		return ret;
	}
	
	override public function addEntity(ent:FEntity) {
		super.addEntity(ent);
		var component:FNoPhysicsComponent = cast(ent.getPhysicsComponent());
		
		_rtree.insertObj(ent, component.getTopX(), component.getTopY(), component.getBottomX(), component.getBottomY());
		updateSleepState(component);
	}
	
	override public function getEntitiesInBox(topLeftX:Float,topLeftY:Float,bottomRightX:Float,bottomRightY:Float):Array<FEntity> {
		//right now just returning all entities
		var ret:Array<FEntity> = _rtree.getObjectsFromRange(topLeftX,topLeftY,bottomRightX,bottomRightY,200,200);
		if(ret==null){
			return new Array();
		}
		return ret;
	}

	
	override public function deleteEntity(ent:FEntity) {
		var component:FNoPhysicsComponent = cast(ent.getPhysicsComponent());
		if(component !=null && _rtree !=null){
			_rtree.deleteObject(ent,component.getTopX(),component.getTopY());
		}
		super.deleteEntity(ent);
	}


	override public function destruct(){
		firmament.util.FLog.debug("___________NO PHYSICS WORLD DELETED___________");
		_deleted = true;
		super.destruct();
		_rtree = null;
	}
	

	
}