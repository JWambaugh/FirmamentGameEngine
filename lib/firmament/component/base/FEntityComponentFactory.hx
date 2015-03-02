package firmament.component.base;

import firmament.component.animation.FAnimationComponent;
import firmament.component.base.FEntityComponent;
import firmament.component.entity.FChildComponent;
import firmament.component.entity.FDecrementComponent;
import firmament.component.entity.FDecrementModComponent;
import firmament.component.entity.FDestroyEntityComponent;
import firmament.component.entity.FIncrementComponent;
import firmament.component.entity.FIncrementModComponent;
import firmament.component.entity.FFollowEntityComponent;
import firmament.component.entity.FLinearTweenComponent;
import firmament.component.entity.FTweenerComponent;
import firmament.component.entity.FMovementComponent;
import firmament.component.event.FBroadcastSceneEventsComponent;
import firmament.component.event.FCaptureSceneEventsComponent;
import firmament.component.event.FCollisionEventMapperComponent;
import firmament.component.event.FEntityEmitterComponent;
import firmament.component.event.FEventMapperComponent;
import firmament.component.event.FEventRelayComponent;
import firmament.component.event.FLoopingTimerComponent;
import firmament.component.event.FSetPropertiesComponent;
import firmament.component.event.FSetRepositoryComponent;
import firmament.component.event.FSetScenePropertiesComponent;
import firmament.component.event.FTimerComponent;
import firmament.component.event.FTriggerAfterStepComponent;
import firmament.component.physics.FBox2DComponent;
import firmament.component.physics.FChildPhysicsComponent;
import firmament.component.physics.FNoPhysicsComponent;
import firmament.component.physics.FParticleComponent;
import firmament.component.render.FLineRenderComponent;
import firmament.component.render.FSpriteRenderComponent;
import firmament.component.render.FTextRenderComponent;
import firmament.component.render.FTilesheetRenderComponent;
import firmament.component.render.FWireframeRenderComponent;
import firmament.component.sound.FSoundComponent;
import firmament.component.spline.FSimpleFollowSplineComponent;
import firmament.component.system.FCameraControlComponent;
import firmament.component.system.FComponentFactoryComponent;
import firmament.component.system.FEntityScriptComponent;
import firmament.component.system.FSceneLoaderComponent;
import firmament.component.ui.FButtonComponent;
import firmament.component.ui.FEntityContainerComponent;


class FEntityComponentFactory{
	public static function createComponent(type:String, gameInstance:firmament.core.FGame):FEntityComponent {
		var className = getClassFromType(type);
		var c =Type.resolveClass(className);
		if(c==null){
			throw "class "+className+" could not be found.";
		}
		var component:FEntityComponent = Type.createInstance(c,[gameInstance]);
		if(component == null){
			throw "Component of type "+type+" with class "+className+" could not be instantiated!";
		}
		return component;
	}

	public static function getClassFromType(type:String){
            var map = {
            "animation":"firmament.component.animation.FAnimationComponent"
            ,"areaTweener":"firmament.component.entity.FMovementComponent"
            ,"box2d":"firmament.component.physics.FBox2DComponent"
            ,"broadcastSceneEvents":"firmament.component.event.FBroadcastSceneEventsComponent"
            ,"button":"firmament.component.ui.FButtonComponent"
            ,"cameraControl":"firmament.component.system.FCameraControlComponent"
            ,"captureSceneEvents":"firmament.component.event.FCaptureSceneEventsComponent"
            ,"child":"firmament.component.entity.FChildComponent"
            ,"childPhysics":"firmament.component.physics.FChildPhysicsComponent"
            ,"collisionEventMapper":"firmament.component.event.FCollisionEventMapperComponent"
            ,"componentFactory":"firmament.component.system.FComponentFactoryComponent"
            ,"decrement":"firmament.component.entity.FDecrementComponent"
            ,"decrementmod":"firmament.component.entity.FDecrementModComponent"
            ,"destroy":"firmament.component.entity.FDestroyEntityComponent"
            ,"entityContainer":"firmament.component.ui.FEntityContainerComponent"
            ,"entityEmitter":"firmament.component.event.FEntityEmitterComponent"
            ,"eventMapper":"firmament.component.event.FEventMapperComponent"
            ,"eventRelay":"firmament.component.event.FEventRelayComponent"
            ,"followEntity":"firmament.component.entity.FFollowEntityComponent"
            ,"followSpline":"firmament.component.spline.FSimpleFollowSplineComponent"
            ,"increment":"firmament.component.entity.FIncrementComponent"
            ,"incrementmod":"firmament.component.entity.FIncrementModComponent"
            ,"line":"firmament.component.render.FLineRenderComponent"
            ,"linearTween":"firmament.component.entity.FLinearTweenComponent"
            ,"loopingTimer":"firmament.component.event.FLoopingTimerComponent"
            ,"noPhysics":"firmament.component.physics.FNoPhysicsComponent"
            ,"particle":"firmament.component.physics.FParticleComponent"
            ,"sceneLoader":"firmament.component.system.FSceneLoaderComponent"
            ,"script":"firmament.component.system.FEntityScriptComponent"
            ,"setProperties":"firmament.component.event.FSetPropertiesComponent"
            ,"setRepository":"firmament.component.event.FSetRepositoryComponent"
            ,"setSceneProperties":"firmament.component.event.FSetScenePropertiesComponent"
            ,"sound":"firmament.component.sound.FSoundComponent"
            ,"sprite":"firmament.component.render.FSpriteRenderComponent"
            ,"text":"firmament.component.render.FTextRenderComponent"
            ,"tilesheet":"firmament.component.render.FTilesheetRenderComponent"
            ,"timer":"firmament.component.event.FTimerComponent"
            ,"triggerAfterStep":"firmament.component.event.FTriggerAfterStepComponent"
            ,"tweener":"firmament.component.entity.FTweenerComponent"
            ,"wireframe":"firmament.component.render.FWireframeRenderComponent"
		};

		var cls = Reflect.field(map,type);
		if(cls == null) return type;
		return cls;
	}

}



