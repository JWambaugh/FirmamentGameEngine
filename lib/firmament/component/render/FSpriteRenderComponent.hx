package firmament.component.render;
import flash.display.BitmapData;
import flash.geom.Matrix;
import flash.display.IBitmapDrawable;
import flash.geom.Point;
import flash.events.EventDispatcher;
import firmament.core.FConfig;
import firmament.tilesheet.FTilesheetManager;
import firmament.component.render.FTilesheetRenderComponent;
import firmament.core.FCamera;
import firmament.core.FVector;
/**
 * 
 * @author Jordan Wambaugh
 * render component for providing completely transparent tilesheet packing and rendering
 */

class FSpriteRenderComponent extends FTilesheetRenderComponent  implements FRenderComponentInterface
{
	
	var _currentImagePath:String = null;

	public function new() 
	{
		super();
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
			imageScale = config.imageScale;
		}

		if(Std.is(config.parallax,Float)){
			_parallax = config.parallax;
		}

		if(Std.is(config.flipX,Bool)){
			_flipX = config.flipX;
		}
		if(Std.is(config.flipY,Bool)){
			_flipY = config.flipY;
		}

		_r=ch.get('red',Float,1.);
		_g=ch.get('green',Float,1.);
		_b=ch.get('blue',Float,1.);
		_alpha=ch.get('alpha',Float,1.);
		setImage(ch.get("image",String));

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
