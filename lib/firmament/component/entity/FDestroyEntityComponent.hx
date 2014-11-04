package firmament.component.entity;

import firmament.component.base.FEntityComponent;
import firmament.core.FEntity;
import firmament.core.FGame;

import firmament.component.physics.FBox2DComponent;
import firmament.core.FVector;
import firmament.util.FEntityUtils;
import firmament.event.FPhysicsCollisionEvent;

import firmament.util.FMisc;
import firmament.process.timer.FTimerManager;
import firmament.core.FEvent;
class FDestroyEntityComponent extends FEntityComponent{

    var _destroyAction:String;
    public function new(){
        super();
    }

    override public function init(config:firmament.core.FConfig){
        _destroyAction = config.get("destroyAction",String,"destroy");
        var event:String = config.getNotNull("listen",String);
        _entity.on(event,destroyEvent);
    }


    override public function getType(){
        return "destroy";
    }

    public function destroyEvent(e:FEvent){
        _entity.getGameInstance().doAfterStep(function(){
            if(this._destroyAction=='repool'){
                _entity.returnToPool();
            }else{
                _entity.delete();
            }
        });
    }
}