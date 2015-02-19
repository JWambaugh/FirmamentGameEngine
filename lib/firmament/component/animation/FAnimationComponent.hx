package firmament.component.animation;

import firmament.component.animation.FAnimationComponentInterface;
import firmament.component.base.FEntityComponent;
import firmament.component.render.FRenderComponentInterface;
import firmament.component.render.FTilesheetRenderComponent;
import firmament.core.FAnimation;
import firmament.core.FAnimationManager;
import firmament.core.FConfig;
import firmament.core.FEntity;
import firmament.core.FPropertyDefinition;
import firmament.core.FEvent;
import firmament.core.FGame;
import firmament.core.FPropertyInterface;
import firmament.process.timer.FTimer;
import haxe.Timer;

class FAnimationComponent extends FEntityComponent implements FAnimationComponentInterface{
	
	var _currentAnimation:FAnimation;
	var _currentFrame:Int;
	var _timer:FTimer;
    var _animationFile:String;
	public function new(gameInstance:firmament.core.FGame){
		super(gameInstance);
		_currentFrame = 0;
	}

	override public function init(config:FConfig){
		
		_animationFile = config.getNotNull('animationFile', String,_animationFile);
		_currentAnimation = FAnimationManager.getInstance().getAnimationByFileName(_animationFile);
		
		//this._entity.addEventListener(FGame.BEFORE_RENDER,this.beforeRender);
		if(_entity.isActive()){
			_timer = getGameInstance().addGameTimer(_currentAnimation.getTimeBetweenFrames(),changeFrame);
		}
		on(_entity,FEntity.ACTIVE_STATE_CHANGE,stateChange);
	}

    override public function getProperties():Array<FPropertyDefinition>{
        var props:Array<FPropertyDefinition> = [
            {
                key:'animationFile'
                ,type:String
                ,getter:getAnimationFile
                ,setter:setAnimationFile
                ,sortOrder:1
            }
            ,{
                key:'frame'
                ,type:Int
                ,getter:getFrame
                ,setter:setFrame
                ,sortOrder:1
                
            }
           
        ];
        return props;
    }

	public function stateChange(e:FEvent){
		if(_entity.isActive()){
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

    public function getFrame(f:Int=0){
        return _currentFrame;
    }

    public function setFrame(f:Int){
        _currentFrame = f;
        jumpToFrame(_currentAnimation.getNextFrame(_currentFrame));
        if(_timer!=null)_timer.cancel();
        _timer = FGame.getInstance().addGameTimer(_currentAnimation.getTimeBetweenFrames(),changeFrame);
    }

	public function setAnimation(animation:FAnimation,?frame:Int=0){
		_currentAnimation = animation;
		_currentFrame = frame;
	}

    public function setAnimationFile(fileName:String){
        _animationFile = fileName;
        _currentAnimation = FAnimationManager.getInstance().getAnimationByFileName(_animationFile);
    }

    public function getAnimationFile(f:String=''){
        return _animationFile;
    }

	public function jumpToFrame(frame:Int){
		//update render component
		var tdata = _currentAnimation.getTilesheetDataForFrame(frame);
        _entity.setProp("tileId",tdata.tileId);
		_entity.setProp("tilesheetId",tdata.tilesheetId);
		_currentFrame = frame;
	}


}