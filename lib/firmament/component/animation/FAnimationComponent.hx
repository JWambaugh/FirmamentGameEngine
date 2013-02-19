package firmament.component.animation;

import firmament.component.animation.FAnimationComponentInterface;
import firmament.component.base.FEntityComponent;
import firmament.core.FAnimation;
import firmament.core.FAnimationManager;
import firmament.core.FGame;
import nme.events.Event;
import haxe.Timer;
import firmament.component.render.FRenderComponentInterface;
import firmament.component.render.FTilesheetRenderComponent;
import firmament.process.timer.FTimer;
import firmament.core.FEntity;

class FAnimationComponent extends FEntityComponent, implements FAnimationComponentInterface{
	
	var _currentAnimation:FAnimation;
	var _currentFrame:Int;
	var _timer:FTimer;
	public function new(){
		super();
		_currentFrame = 0;
	}

	override public function init(config:Dynamic){
		if(Std.is(config.animationFile,String)){
			var animationFile:String = config.animationFile;
			_currentAnimation = FAnimationManager.getInstance().getAnimationByFileName(animationFile);
		}
		//this._entity.addEventListener(FGame.BEFORE_RENDER,this.beforeRender);
		if(_entity.isActive()){
			_timer = FGame.getInstance().addGameTimer(_currentAnimation.getTimeBetweenFrames(),changeFrame);
		}
		this.addEventListenerToEntity(FEntity.ACTIVE_STATE_CHANGE,stateChange);
	}

	public function stateChange(e:Event){
		if(_entity.isActive()){
			if(_entity.getTypeId()=='fireball')
				trace('animation active');
			if(_timer!=null)_timer.cancel();

			_currentFrame=0;
			jumpToFrame(0);
			_timer = FGame.getInstance().addGameTimer(_currentAnimation.getTimeBetweenFrames(),changeFrame);
		}else{
			if(_timer!=null)_timer.cancel();
			_timer = null;
		}
	}

	override public function getType(){
		return "animation";
	}	

	public function changeFrame(){
		jumpToFrame(_currentAnimation.getNextFrame(_currentFrame));
		_timer = FGame.getInstance().addGameTimer(_currentAnimation.getTimeBetweenFrames(),changeFrame);
	}

	public function setAnimation(animation:FAnimation,?frame:Int=0){
		_currentAnimation = animation;
		_currentFrame = frame;
	}

	public function jumpToFrame(frame:Int){
		//update render component
		var rc:FRenderComponentInterface = _entity.getRenderComponent();
		if(Std.is(rc,FTilesheetRenderComponent)){
			var tsc:FTilesheetRenderComponent = cast(rc,FTilesheetRenderComponent);
			tsc.setTile(_currentAnimation.getTileIndexForFrame(_currentFrame));
			tsc.setTilesheet(_currentAnimation.getTilesheet());
			_currentFrame = frame;
		}else{
			//throw "Animations only work with FTilesheet render components. Entity: "+_entity.getTypeId();
		}
	}





}