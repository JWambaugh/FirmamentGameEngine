
package firmament.util;

import firmament.core.FEntity;
import firmament.core.FVector;
import firmament.component.physics.FPhysicsComponentInterface;
class FEntityUtils {

	
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
	static public function emitEntity(sourceEntity:FEntity, entity:FEntity, ?speed:Float=10, ?angleOffset:Float=0, ?distanceOffset:Float=0, ?ignoreParent:Bool=false){
	    var p = entity.getPhysicsComponent();
	    var sp = sourceEntity.getPhysicsComponent();
		if( p == null || sp == null ) {
			return;
		}
		var origin = (ignoreParent==false) ? sp : p;
	    var cos = Math.cos(origin.getAngle()+angleOffset);
	    var sin = Math.sin(origin.getAngle()+angleOffset);
	    var posMult = distanceOffset;
	    p.setPosition(new FVector(origin.getPositionX()+cos*posMult
	    	,origin.getPositionY()+sin*posMult));
	    
	    p.setAngle(origin.getAngle()+angleOffset);
	    p.setLinearVelocity(new FVector(cos*speed,sin*speed));
	}

	/**
	 * Function: emitEntity
	 * Shoots an entity entity from the sourceEntity in the direction the entity is currently pointing
	 * 
	 * Params: 
	 * 		sourceEntity 	{FEntity} The entity to shoot the bullet from
	 * 		entity 			{FEntity} The entity to emit
	 *		angleOffset 	Float the angle that should be added to sourceEntity's angle
	 *		speed 			Float the speed at which the entity should travel
	 *		positionOffset  Float the distance from sourceEntity that the entity should start from.
	 */
	static public function emitEntityFromPoint( entity:FEntity, position:FVector,angle:Float, ?speed:Float=10,?distanceOffset:Float=0,?matchAngle=true){
	    var p = entity.getPhysicsComponent();
	    
	    var cos = Math.cos(angle);
	    var sin = Math.sin(angle);
	    var posMult = distanceOffset;
	    p.setPosition(new FVector(position.x+cos*posMult
	    	,position.y+sin*posMult)) ;
	    if(matchAngle)
	    	p.setAngle(angle);
	    p.setLinearVelocity(new FVector(cos*speed,sin*speed));
	}



}