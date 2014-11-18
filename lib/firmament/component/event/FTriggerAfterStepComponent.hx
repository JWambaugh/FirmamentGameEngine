package firmament.component.event;

import firmament.component.base.FEntityComponent;
import firmament.core.FEvent;
import firmament.util.FEntityUtils;
import firmament.core.FEntityFactory;
import firmament.core.FEntity;
import firmament.event.FEntityEvent;
import firmament.util.FLog;
import firmament.core.FConfig;
import firmament.scene.FScene;
import firmament.core.FGame;

class FTriggerAfterStepComponent extends FEntityComponent{

    public function new(){
        super();
        
    }

    override public function init(config:FConfig){
        var scene:FScene = FGame.getInstance().getCurrentScene();
        var listeners:FConfig = _config.getNotNull("listen");
        for(evt in listeners.fields() ){
            _entity.on(cast(evt,String),this,function(e:FEvent){
                scene.trigger(new FEvent(e.name));
                getGameInstance().doAfterStep(function(){
                    scene.trigger(new FEvent(listeners.get(evt,String)));
                });
            });
        }
    }

    override public function getType(){
        return "broadcastSceneEvents";
    }   
}