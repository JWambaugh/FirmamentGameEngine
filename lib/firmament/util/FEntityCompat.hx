/**
 * Class: FEntityCompat
 * To be used with 'using' mixin keyword. Adds methods to help make FEntities more firmament 1.0 compatible.
 */
package firmament.util;

import firmament.core.FEntity;
import firmament.core.FVector;
class FEntityCompat {

	public static function getPosition(e:FEntity){
		return e.getPhysicsComponent().getPosition();
	}
	
	public static function getPositionY(e:FEntity){
		return e.getPhysicsComponent().getPositionY();
	}

	public static function getPositionX(e:FEntity){
		return e.getPhysicsComponent().getPositionX();
	}

	public static function setAngle(e:FEntity,a:Float){
		e.getPhysicsComponent().setAngle(a);
	}

	public static function getAngle(e:FEntity){
		return e.getPhysicsComponent().getAngle();
	}

	public static function setPosition(e:FEntity,pos:FVector){
		e.getPhysicsComponent().setPosition(pos);
	}

}