
package firmament.util;

import firmament.core.FEntity;
import firmament.core.FVector;

class FEntityUtils {


    /**
     * Function: emitEntity
     * Shoots an entity entity from the sourceEntity in the direction the entity is currently pointing
     *
     * Params:
     *         sourceEntity     {FEntity} The entity to shoot the bullet from
     *         entity             {FEntity} The entity to emit
     *        speed             Float the speed at which the entity should travel
     *        angleOffset     Float the angle that should be added to sourceEntity's angle
     *        positionOffset  Float the distance from sourceEntity that the entity should start from.
     */
    static public function emitEntity(sourceEntity:FEntity, entity:FEntity, ?speed:Float=10, ?angleOffset:Float=0, ?distanceOffset:Float=0, ?ignoreParent:Bool=false){
        var origin = (ignoreParent==false) ? sourceEntity : entity;

        try{
            var angle:Float = origin.getProp('angle');
            var cos = Math.cos(angle+angleOffset);
            var sin = Math.sin(angle+angleOffset);
            firmament.util.FLog.warning(origin.getProp('typeId')+" :"+origin.getProp('positionX')+" "+origin.getProp('positionY'));
            entity.setProp('position',new FVector(origin.getProp('positionX')+cos*distanceOffset
                ,origin.getProp('positionY')+sin*distanceOffset));
            entity.setProp('linearVelocity', new FVector(cos*speed,sin*speed));
            entity.setProp('angle',angle+angleOffset);
        } catch(e:String){
            FLog.warning('emitEntity: '+e);
        }
    }

    /**
     * Function: emitEntity
     * Shoots an entity entity from the sourceEntity in the direction the entity is currently pointing
     *
     * Params:
     *         sourceEntity     {FEntity} The entity to shoot the bullet from
     *         entity             {FEntity} The entity to emit
     *        angleOffset     Float the angle that should be added to sourceEntity's angle
     *        speed             Float the speed at which the entity should travel
     *        positionOffset  Float the distance from sourceEntity that the entity should start from.
     */
    static public function emitEntityFromPoint( entity:FEntity, position:FVector,angle:Float, ?speed:Float=10,?distanceOffset:Float=0,?matchAngle=true){


        var cos = Math.cos(angle);
        var sin = Math.sin(angle);
        var posMult = distanceOffset;
        entity.setProp("position",new FVector(position.x+cos*posMult
            ,position.y+sin*posMult)) ;
        if(matchAngle)
            entity.setProp('angle', angle);
        entity.setProp('linearVelocity', new FVector(cos*speed,sin*speed));
    }



}
