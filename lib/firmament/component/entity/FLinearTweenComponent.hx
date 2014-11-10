package firmament.component.entity;



import firmament.component.base.FEntityComponent;
import firmament.component.physics.FBox2DComponent;
import firmament.core.FEntity;
import firmament.core.FEvent;
import firmament.core.FGame;
import firmament.core.FVector;
import firmament.event.FPhysicsCollisionEvent;
import firmament.process.engine.FLinearTweener;
import firmament.process.timer.FTimerManager;
import firmament.util.FEntityUtils;
import firmament.util.FMisc;

class FLinearTweenComponent extends FEntityComponent{
    var _tweener:FLinearTweener;
    public function new(){
        super();
    }

    override public function init(config:firmament.core.FConfig){
        _tweener = new FLinearTweener(_entity, config);
        getGameInstance().addProcess(_tweener);

        if(config.hasField('trigger'))
            on(_tweener, firmament.process.base.FProcess.COMPLETE, function(e:FEvent){
                _entity.trigger(config.get('trigger',String));
            });
    }


    override public function getType(){
        return "linearTween";
    }

}