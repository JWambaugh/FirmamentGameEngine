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
    public function new(gameInstance:firmament.core.FGame){
        super(gameInstance);

    }

    private function setup(config:firmament.core.FConfig){
        if(config.hasField('listen')){
            on(_entity, config.get('listen'), function(e:FEvent){
                _tweener = new FLinearTweener(_entity, config);
                getGameInstance().addProcess(_tweener);
            });
        }else{
            _tweener = new FLinearTweener(_entity, config);
            getGameInstance().addProcess(_tweener);
        }

        if(config.hasField('trigger')){
            on(_tweener, firmament.process.base.FProcess.COMPLETE, function(e:FEvent){
                _entity.trigger(config.get('trigger',String));
            });
        }
    }

    override public function init(config:firmament.core.FConfig){
        setup(config);
        on(_entity,FEntity.ACTIVE_STATE_CHANGE, function(e:FEvent){
            if(_entity.isActive()){
                if(_tweener!=null)_tweener.abort();
                removeEventListener(null,this);
            }else{
                setup(_config);
            }
        });
    }


    override public function getType(){
        return "linearTween";
    }

}