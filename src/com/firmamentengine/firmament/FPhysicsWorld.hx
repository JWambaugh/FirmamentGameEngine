package com.firmamentengine.firmament;

import com.firmamentengine.firmament.FWorld;
import com.firmamentengine.firmament.FEntity;
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
	public function getEntitiesInBox(topLeftX:Int,topLeftY:Int,bottomRightX:Int,bottomRightY:Int):Array<FEntity>{
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
	
	
}