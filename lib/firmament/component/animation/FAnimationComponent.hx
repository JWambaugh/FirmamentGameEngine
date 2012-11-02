package firmament.component.animation;

import frimament.core.FAnimation;
import firmament.component.animation.FAnimationComponentInterface;
import firmament.component.base.FEntityComponent;

class FAnimationComponent extends FEntityComponent, implements FAnimationComponentInterface{
	
	var _currentAnimation:FAnimation;
	var _currentFrame:Int;
	var _timeSinceLastFrameChange:Float;

	public function new(){
		super();
		_currentFrame = 0;
		_timeSinceLastFrameChange=0;
	}

	override public function init(config:Dynamic){
		if(Std.is(config.animationFile,String)){
			var animationFile:String = config.animationFile;
			
		}
	}

	override public function getType(){
		return "animation";
	}	

}