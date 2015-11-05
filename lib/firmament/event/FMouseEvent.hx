
package firmament.event;

import firmament.core.FEvent;
import firmament.core.FEntity;
import firmament.core.FVector;
import firmament.core.FCamera;


class FMouseEvent extends FEvent {

    public var cameraPosition:FVector;
    public var worldPosition(get,null):FVector;
    public var camera:FCamera;

    public function new(event:String, camera:FCamera, cPosition:FVector){
        super(event);
        cameraPosition = cPosition;
        this.camera = camera;
    }

    private function get_worldPosition():FVector{
        return camera.getWorldPosition(cameraPosition.x, cameraPosition.y);
    }


}