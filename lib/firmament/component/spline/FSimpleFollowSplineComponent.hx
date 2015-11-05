
package firmament.component.spline;

import firmament.component.base.FEntityComponent;
import firmament.component.physics.FBox2DComponent;
import firmament.core.FCamera;
import firmament.core.FEntity;
import firmament.core.FGame;
import firmament.core.FVector;
import firmament.event.FPhysicsCollisionEvent;
import firmament.process.base.FProcess;
import firmament.process.engine.CatmullRom;
import firmament.process.engine.FLinearTweener;
import firmament.util.FEntityUtils;
import firmament.core.FEvent;
import flash.events.Event;


import firmament.process.engine.FSplineTweener;

class FSimpleFollowSplineComponent extends FEntityComponent {

	var _path:FSplineTweener;
	var _camera:FCamera;
	public function new(gameInstance:firmament.core.FGame){
		super(gameInstance);
	}	

	override public function init(config:Dynamic){
		_config = config;
		_camera = FGame.getInstance().getCamera("main");
		//firmament.util.FLog.debug("Dumping SimpleFollowSpline Config");

		on(_entity,FEntity.COMPONENTS_INITIALIZED,postInit);
		_camera.addEventListener(FCamera.AFTER_RENDER_EVENT,this.postRender);
	}

	public function postInit(e:FEvent){
//		firmament.util.FLog.debug(Std.string(_entity));
		/*
		{ totalTime : 10.1, componentName : com.celestia.component.SimpleFollowSpline, points : [[0,0],[10,20],[20,0],[30,40],[40,0],[50,-80],[60,0]], offset : { y : 50, x : -50 } }
		*/

		//firmament.util.FLog.debug(Std.string(_config));
		_path = new FSplineTweener(_config,_entity,_camera.graphics);
	}

	public function postRender(e:Event) {
		_path.render();
	}

	override public function getType():String{
		return "SimpleFollowSpline";
	}

}