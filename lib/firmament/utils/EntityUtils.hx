
package firmament.utils;

import firmament.core.FEntity;
class EntityUtils {

	
	/**
	 * Function: emitEntity
	 * Shoots an entity entity from the sourceEntity in the direction the entity is currently pointing
	 * 
	 * Params: 
	 * 		sourceEntity 	{FEntity} The entity to shoot the bullet from
	 * 		entity 			{FEntity} The entity to emit
	 *		speed 			Float the speed at which the entity should travel
	 *		angleOffset 	Float the angle that should be added to sourceEntity's angle
	 *		positionOffset  Float the distance from sourceEntity that the entity should start from.
	 */
	static public function emitEntity(sourceEntity:FEntity, entity:FEntity, ?speed:Float=10, ?angleOffset:Float=0, ?positionOffset:Float=.1){
	    var p = entity.getPhysicsComponent();
	    var sp = sourceEntity.getPhysicsComponent();

	    var cos = Math.cos(sp.getAngle()+angleOffset);
	    var sin = Math.cos(sp.getAngle()+angleOffset);
	    var posMult = 1+positionOffset;
	    p.setPosition(new FVector(sourceEntity.getPositionX()+cos*posMult
	    	,sourceEntity.getPositionY()+sin*posMult)) ;
	    
	   
	    p.setVelocity({x:cos*speed,y:cos*speed});
	}

}