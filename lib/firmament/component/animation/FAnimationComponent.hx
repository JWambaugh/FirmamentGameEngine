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

class FAnimationComponent extends FEntityComponent, implements FAnimationComponentInterface{
	
	var _currentAnimation:FAnimation;
	var _currentFrame:Int;
	var _timeOfLastFrameChange:Float;

	public function new(){
		super();
		_currentFrame = 0;
		_timeOfLastFrameChange = Timer.stamp();
	}

	override public function init(config:Dynamic){
		if(Std.is(config.animationFile,String)){
			var animationFile:String = config.animationFile;
			_currentAnimation = FAnimationManager.getInstance().getAnimationByFileName(animationFile);
		}
		this._entity.addEventListener(FGame.BEFORE_RENDER,this.beforeRender);
	}

	override public function getType(){
		return "animation";
	}	

	public function beforeRender(e:Event){
		//see if enough time has elapsed to change frames
		var stamp = Timer.stamp(); 
		if(stamp - _timeOfLastFrameChange >= _currentAnimation.getTimeBetweenFrames()){
			_timeOfLastFrameChange = stamp;
			jumpToFrame(_currentAnimation.getNextFrame(_currentFrame));
		}

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
		}else{
			throw "Animations are only work with FTilesheet render components";
		}
	}





}