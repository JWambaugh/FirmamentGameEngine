
package firmament.component.system;

import firmament.component.base.FEntityComponent;
import firmament.component.physics.FBox2DComponent;
import firmament.core.FGame;
import firmament.core.FInput;
import firmament.core.FVector;
import firmament.event.FPhysicsCollisionEvent;
import firmament.process.engine.FLinearTweener;
import firmament.ui.FAutoVirtualJoystick;
import firmament.util.FEntityUtils;
import firmament.util.FRepository;
import firmament.core.FConfig;
import firmament.util.FLog;


class FCameraControlComponent extends FEntityComponent {

    private var _camera:firmament.core.FCamera = null;
    private var _bounds:Dynamic<FVector>;
    private var _sticky:Float;
    private var _drag:Float;
    private var _clamped:Dynamic<Bool>;

    public function new(){
        super();
        _bounds = { "min" : null, "max" : null };
        _sticky = 0;
        _clamped = {x:false,y:false};
    }

    override public function init(config:FConfig){
        useStep(true);

        var bounds:FConfig = _config.get('bounds');
        for( field in bounds.fields() ) {
            var vbounds:FConfig = bounds.get(field);
            var boundaries:FVector = new FVector(
                vbounds.get("x",Float,Math.NaN),
                vbounds.get("y",Float,Math.NaN)
            ); 
            if( boundaries != null ) {
                Reflect.setField(_bounds,field,boundaries);
            }
        }
        FLog.debug("Bounds - " Std.string(_bounds) );

        _sticky = _config.get('sticky',Float);
        FLog.debug("Sticky - " + Std.string(_sticky));

        _drag = _config.get('drag',Float);
        FLog.debug("Drag - " + Std.string(_drag));
    }

    override public function getType(){
        return "cameraControl";
    }

    private function clamp(value,min,max):Dynamic{

        var clamped = true;
        if( min != Math.NaN && value < min ) {
            value = min + 0.0;
        } else if( min != Math.NaN && value > max ) {
            value  = max + 0.0;
        } else {
            clamped = false;
        }
        return { "value" : value, "clamped" : clamped};
    }

    
    override public function step(delta:Float) {
        if(_camera == null) _camera = FGame.getInstance().getCamera(_config.get('cameraName',String,'main')); 

        var targetPosition:FVector = _entity.getPhysicsComponent().getPosition();
        var currentPosition:FVector = _camera.getPosition().copy();
        var delta:FVector = targetPosition.copy();
        delta.subtract(currentPosition);

        var cclamped = {"x":false,"y":false};
        
        // max distance from center
        var result = clamp(targetPosition.x,_bounds.min.x,_bounds.max.x);
        var newX = result.value; 
        cclamped.x = result.clamped;

        result = clamp(targetPosition.y,_bounds.min.y,_bounds.max.y);
        var newY = result.value;
        cclamped.y = result.clamped;

        var update = false;
        if( _clamped.x == true && cclamped.x != true && (Math.abs(delta.x) <= _sticky) ) {
            newX=currentPosition.x;
        } else {
            _clamped.x = cclamped.x;
        }

        if( _clamped.y == true && cclamped.y != true && (Math.abs(delta.y) <= _sticky)  ) {
            newY=currentPosition.y;
        } else {
            _clamped.y = cclamped.y;
        }

        // drag
        var destPosition = new FVector(newX,newY); // May be the same as target
        var destDelta = destPosition.copy();
        destDelta.subtract(currentPosition);
        destDelta.multiply(1-_drag);
        currentPosition.add(destDelta);
        _camera.setPosition(currentPosition);
    }
}