
package firmament.component.entity;

import firmament.component.base.FEntityComponent;
import firmament.core.FConfig;
import firmament.core.FEntity;
import firmament.core.FEvent;
import firmament.core.FVector;
import firmament.event.FMouseEvent;

/*
    Class: FEventMapperComponent
    maps events on the entity of a type to another event of a different type.
*/

class FPointAtEntityComponent extends FEntityComponent {

    private var _targetAngle:Float;
    private var _translationSpeed:Float;
    private var _direction:Float;
    private var _finishedAngle:Float;

    public function new(gameInstance:firmament.core.FGame){
        super(gameInstance);
    }

    override public function init(config:FConfig){
        useStep(true);

        _translationSpeed = _config.get('speed',Float,1);

        var listener:String = _config.getNotNull("listener",String);
        on(_entity,listener,this,onEvent);

        _targetAngle = _entity.getProp('angle');
    }

    public function onToggleActive(e:FEvent) {
    }

    public function onEvent(e:FEvent) {
        var tgt:FVector = new FVector( 0, 0); // X,Y 0 length vector
        var pos:FVector = new FVector( _entity.getProp('positionX'), _entity.getProp('positionY') );
        var currentAngle = _entity.getProp('angle');
        var rotatedPoint:FVector = tgt.getPointAtAngle( currentAngle, 1 );

        if( Std.is(e,FMouseEvent) ) {
            var me:FMouseEvent = cast(e);
            tgt = me.worldPosition;
        }

        var dstVector = tgt.copy();

        dstVector.subtract(pos); // vector in object space
        dstVector.makeUnit();

        if(currentAngle != _targetAngle) {
            _translationSpeed *= _config.get('acceleration',Float,1.5);
        } else {
            _translationSpeed = _config.get('speed',Float,1);
        }

        _targetAngle = currentAngle + rotatedPoint.angleBetween(dstVector);

        var clampMin:Null<Float> = _config.get('clampMin',Float,null);
        var clampMax:Null<Float> = _config.get('clampMax',Float,null);
        
        if( clampMax != null && _targetAngle > clampMax ) {
            _targetAngle = clampMax;
        } else if( clampMin != null &&  _targetAngle < clampMin ) {
            _targetAngle = clampMin;
        }

        // shortest rotation
        var diff = _targetAngle - currentAngle;
        _direction = (_targetAngle - currentAngle) > 0 ? 1 : -1;
        if( Math.abs(diff) > Math.PI ) {
            _direction = 0-_direction;
            _finishedAngle=Math.abs(Math.abs(diff) - (2*Math.PI));
        } else {
            _finishedAngle=Math.abs(diff);
        }

        log(rotatedPoint);
        log(dstVector);
        log('speed to rotate - ' + _translationSpeed );
        log('Difference - ' + ((_targetAngle - currentAngle) ) );
        log('Current Angle - ' + (currentAngle ) );
        log('Angle to object - ' + (_targetAngle) );
        log('direction - ' + _direction );
    }

    override public function getType(){
        return "pointat";
    }

    override public function step(delta:Float) {
        var currentAngle:Float = _entity.getProp('angle');

        log(currentAngle);
        log(_targetAngle);

        var diff = (_targetAngle - currentAngle);
        if( diff != 0 ) {

            log(_finishedAngle );

            var dist = _translationSpeed * delta;
            _finishedAngle-=dist;
            if( _finishedAngle > 0 ) {
                currentAngle += (_direction * dist);
            } else {
                currentAngle = _targetAngle;
            }
            log(diff);
            log(_targetAngle - currentAngle);
            _entity.setProp('angle',currentAngle);
        }
    }

}