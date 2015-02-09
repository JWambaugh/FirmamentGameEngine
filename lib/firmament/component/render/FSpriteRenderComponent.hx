package firmament.component.render;

import firmament.component.base.FEntityComponent;
import firmament.component.render.FTilesheetRenderComponent;
import firmament.core.*;
import firmament.core.FCamera;
import firmament.core.FConfig;
import firmament.core.FPropertyInterface;
import firmament.core.FPropertyDefinition;
import firmament.core.FVector;
import firmament.tilesheet.FTilesheetManager;
import flash.display.BitmapData;
import flash.display.IBitmapDrawable;
import flash.events.EventDispatcher;
import flash.geom.Matrix;
import flash.geom.Point;
/**
 * 
 * @author Jordan Wambaugh
 * render component for providing completely transparent tilesheet packing and rendering
 */

class FSpriteRenderComponent extends FTilesheetRenderComponent  implements FRenderComponentInterface
{
	
	var _currentImagePath:String = null;

	public function new(gameInstance:firmament.core.FGame) 
	{
		super(gameInstance);
		imageScale=100;
		drawList = new Array<Float>();
		_tile = 0;
		_parallax = 1;
		_flipX = false;
		_flipY = false;
		_positionOffset = new FVector(0,0);
		_angleOffset = 0;
	}
	
	override public function init(config:Dynamic){
		this._config = config;
		var ch:FConfig = config;


        if(Std.is(config.imageScale,Float)) {
			imageScale = ch.get("imageScale",Float);
		}
		if(Std.is(config.parallax,Float)){
			_parallax = ch.get("parallax",Float);
		}
		if(Std.is(config.flipX,Bool)){
			_flipX = ch.get("flipX",Bool);
		}
		if(Std.is(config.flipY,Bool)){
			_flipY = ch.get("flipY",Bool);
		}

		_r=ch.get('red',Float,1.0);
		_g=ch.get('green',Float,1.0);
		_b=ch.get('blue',Float,1.0);
		_alpha=ch.get('alpha',Float,1.0);

		setImage(ch.get("image",String));
	}

    override public function getProperties():Array<FPropertyDefinition>{
        var props:Array<FPropertyDefinition> = super.getProperties();
         
            props.push({   // this is a fake property until it can be fixed
                key:'image'
                ,type:String
                ,getter:function(){return _currentImagePath;}
                ,setter:setImage
            });
            
        
        return props;
    }


    


	public function setImage(image:Dynamic){
		if(Std.is(image,String)){
			_currentImagePath = image;
			_tilesheet = null;
			//see if it's already in a loaded sheet
			var tm = FTilesheetManager.getInstance();
			var tdata = tm.getTilesheetForPath(cast image);
			if(tdata != null){
				_tilesheet = tm.getTilesheetWithId(tdata.tilesheetId);
				_tile = tdata.tileId;
			}else{
				//tilesheet manager doesn't have record of it so queue for autoloading
				tm.queueTilesheetForPath(image);
			}
		}else{
			throw "Image isn't a string!?";
		}
	}

	
	override public function render(camera:FCamera):Void {
		if(_tilesheet == null){
			//firmament.util.FLog.debug("tilesheet is null");
			var tm = FTilesheetManager.getInstance();
			var tdata = tm.getTilesheetForQueuedPath(_currentImagePath);
			if(tdata == null)throw "There was apparently a problem with auto-generating our tilesheet!";
			_tilesheet = tm.getTilesheetWithId(tdata.tilesheetId);
			_tile = tdata.tileId;
		}
		super.render(camera);
	}


	override public function getType():String {
		return "render";
	}


	
}
