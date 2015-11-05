package firmament.world;


import firmament.component.physics.FBox2DComponent;
import firmament.core.FEntity;
import firmament.world.FWorld;
import firmament.event.FBox2DCollisionEvent;
import firmament.event.FPhysicsCollisionEvent;
import firmament.ui.FDialog;
import flash.events.Event;
import firmament.core.FGame;
import firmament.process.base.FProcessManager;
import firmament.component.physics.FParticleComponent;
import firmament.core.FVector;
import firmament.world.grid.FGridSector;
/**
 * ...
 * @author Jordan Wambaugh
 */




class FGridWorld extends FWorld
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
		for(ent in _activeAwakeEntities){
			var lv = ent.getProp('linearVelocity');
			var av = ent.getProp('angularVelocity');

			if(av!=0){
				ent.setProp('angle', ent.getProp('angle')+ av * elapsedTime);
			}

			if(lv.x!=0 || lv.y!=0){
				var pos = ent.getProp('position');
				ent.setProp('position', new FVector(pos.x+lv.x * elapsedTime, pos.y + lv.y * elapsedTime));
			}

		}

		_inStep = false;
		this.endOfStep();


	}

	public function updateSleepState(component:FParticleComponent){
		if(component.isSleeping()){
			_activeAwakeEntities.remove(component.getEntity());
		} else{
			_activeAwakeEntities.remove(component.getEntity());
			_activeAwakeEntities.push(component.getEntity());
		}
	}


	override public function getType():String{
		return "particle";
	}


	override public function insideStep():Bool{
		return _inStep;
	}

	override public function getAllEntities():Array<FEntity> {
		return this.entities;
	}

	override public function getEntitiesAtPoint(p:FVector):Array<FEntity> {
		return new Array<FEntity>();
	}

	override public function addEntity(ent:FEntity) {
		super.addEntity(ent);
		var component:FParticleComponent = cast(ent.getPhysicsComponent());

		updateSleepState(component);
	}

	override public function getEntitiesInBox(topLeftX:Float,topLeftY:Float,bottomRightX:Float,bottomRightY:Float):Array<FEntity> {
		return this._activeAwakeEntities;
	}


	override public function deleteEntity(ent:FEntity) {
		var component:FParticleComponent = cast(ent.getPhysicsComponent());
		super.deleteEntity(ent);
	}


	override public function destruct(){
		super.destruct();
	}



}
