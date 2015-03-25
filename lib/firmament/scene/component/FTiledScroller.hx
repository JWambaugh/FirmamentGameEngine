package firmament.scene.component;

import firmament.core.FConfig;
import firmament.core.FEvent;
import firmament.scene.FSceneComponent;
import firmament.core.FPropertyDefinition;

class FTiledScroller extends FSceneComponent {

  public function new(gameInstance:Dynamic) {
    super(gameInstance);
  }

  override public function init(config:FConfig):Void {
    
  }

  override public function getProperties():Array<FPropertyDefinition> {
    var props:Array<FPropertyDefinition> = [
          /*{
              key:'cameraPosition'
              ,type:FVector
              ,getter:getPosition
              ,setter:setPosition
          }*/
      ];
      return props;
  }
}
