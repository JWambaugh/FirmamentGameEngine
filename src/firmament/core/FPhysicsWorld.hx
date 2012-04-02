package firmament.core;

import firmament.core.FWorld;
import firmament.core.FEntity;
import box2D.dynamics.B2World;
import box2D.collision.B2AABB;
/**
 * ...
 * @author Jordan Wambaugh
 */

class FPhysicsWorld extends FWorld
{

	
	var b2world:B2World;
	public function new(gravity:FVector) 
	{
		super();
		this.b2world = new B2World(gravity,true);
	}
	override public function getEntitiesInBox(topLeftX:Int,topLeftY:Int,bottomRightX:Int,bottomRightY:Int):Array<FEntity>{
		var selectEntities:Array<FEntity> = new Array();
		var query = new B2AABB();
		
		query.upperBound.set(bottomRightX,bottomRightY);
		query.lowerBound.set(topLeftX,topLeftY);
		//Firmament.log(query,true);
		//Firmament.log(query);
		this.b2world.queryAABB(function(fixture){
			//Firmament.log("here");
			selectEntities.push(fixture.getBody().getUserData());
			return true;
		},query);
	   // Firmament.log(selectEntities.length);
		return selectEntities;
	}
	
	public function getB2World():B2World {
		return this.b2world;
	}
	
	public function createEntity(config:Dynamic):FPhysicsEntity {
		var ent:FPhysicsEntity = new FPhysicsEntity(this,config);
		//this.addEntity(ent);
		return ent;
		
	}
	
	override public function step():Void {
		this.b2world.step(1 / 30, 10, 10);
	}
	
	
	
}