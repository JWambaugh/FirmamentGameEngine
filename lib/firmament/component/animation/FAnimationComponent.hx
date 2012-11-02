package firmament.component.animation;

import firmament.core.FAnimation;
import firmament.component.animation.FAnimationComponentInterface;
import firmament.component.base.FEntityComponent;
import firmament.core.FAnimationManager;

class FAnimationComponent extends FEntityComponent, implements FAnimationComponentInterface{
	
	var _currentAnimation:FAnimation;
	var _currentFrame:Int;
	var _timeSinceLastFrameChange:Float;

	public function new(){
		super();
		_currentFrame = 0;
		_timeSinceLastFrameChange = 0;
	}

	override public function init(config:Dynamic){
		if(Std.is(config.animationFile,String)){
			var animationFile:String = config.animationFile;
			_currentAnimation = FAnimationManager.getInstance().getAnimationByFileName(animationFile);
		}
	}

	override public function getType(){
		return "animation";
	}	

}