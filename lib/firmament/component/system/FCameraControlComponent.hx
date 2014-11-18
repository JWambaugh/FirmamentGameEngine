
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


class FCameraControlComponent extends FEntityComponent {

    private var _camera:firmament.core.FCamera = null;

    public function new(){
        super();
    }

    override public function init(config:firmament.core.FConfig){
        useStep(true);
    }

    override public function getType(){
        return "cameraControl";
    }

    
    override public function step(delta:Float) {
        if(_camera == null) _camera = FGame.getInstance().getCamera(_config.get('cameraName',String)); 
        _camera.setPosition(_entity.getPhysicsComponent().getPosition());
    }
}