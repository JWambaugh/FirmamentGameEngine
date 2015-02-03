package firmament.scene.component;

import firmament.core.FConfig;
import firmament.core.FEvent;
import firmament.scene.FSceneComponent;

class FCameraComponent extends FSceneComponent {
    var _camera:firmament.core.FCamera;

    public function new(gameInstance:Dynamic) 
    {
        super(gameInstance);
    }

    override public function init(config:FConfig):Void {
       
        var cameraName = config.getNotNull("camera",String);
        _camera = _gameInstance.getCamera(cameraName);
    }

    override public function getProperties():Array<FPropertyDefinition>{
        var props:Array<FPropertyDefinition> = [
            {
                key:'cameraPosition'
                ,type:FVector
                ,getter:getPosition
                ,setter:setPosition
            }
            ,{
                key:"cameraPositionX"
                ,type:Float
                ,getter:getPositionX
                ,setter:setPositionX
            }
            ,{
                key:"cameraPositionY"
                ,type:Float
                ,getter:getPositionY
                ,setter:setPositionY
            }
            ,{
                key:"cameraZoom"
                ,type:Float
                ,getter:getZoom
                ,setter:getZoom
            }
            ,{
                key:"cameraFillColor"
                ,type:Float
                ,getter:getFillColor
                ,setter:setFillColor
            }
            
            
        ];
        return props;
    }

    public function getZoom(){
        return _camera.getZoom();
    }

    public function setZoom(z:Float){
        _camera.setZoom(z);
    }

    
    public function setPosition(pos:FVector) {
        _camera.setPosition(pos);
    }
    
   
    public function getPosition():FVector {
        return _camera.getPosition();
    }

   
    public function getPositionX():Float {
        return _camera.getPositionX();
    }

    public function setPositionX(v:Float) {
        _camera.setPositionX(v);
    }
    
    
    public function getPositionY():Float {
        return _camera.getPositionY();
    }

    public function setPositionY(v:Float) {
        _camera.setPositionY(v);
    }

    public function setFillColor(v:Int){
        _camera.setFillColor(v);
    }

    public function getFillColor():Int{
        return _camera.getFillColor();
    }

}