package firmament.component.render;



import firmament.component.base.FEntityComponent;

import firmament.component.render.FRenderComponentInterface;
import firmament.core.FCamera;
import firmament.core.FGame;
import firmament.tilesheet.FTilesheet;
import firmament.tilesheet.FTilesheetManager;
import firmament.tilesheet.FTilesheetRenderHelper;
import firmament.component.animation.FAnimationComponent;
import openfl.Assets;
import flash.display.BitmapData;
import flash.display.IBitmapDrawable;
import flash.display.Sprite;
import openfl.display.Tilesheet;
import firmament.core.FEvent;

import flash.geom.Point;
import flash.geom.Rectangle;
import firmament.core.FVector;



/**
 * ...
 * @author jordan
 */
class FLineRenderComponent extends FEntityComponent  implements FRenderComponentInterface 
{
	var _tilesheet:FTilesheet;
	var imageScale:Float;
	var _tile:Int;
	var _parallax:Float;

	var _startPoint:FVector;
	var _endPoint:FVector;
	var _angle:Float;
	var _distanceBetween:Float;
	var _r:Float=1;
	var _g:Float=1;
	var _b:Float=1;
	var _alpha:Float=1;
	public function new(gameInstance:firmament.core.FGame) {
		imageScale=100;
		super(gameInstance);

		_tile = 0;
		_parallax = 1;
		_angle = 0;
	}

	override public function init(config:Dynamic){
		this._config = config;
		
		initTilesheet();

		if(Std.is(config.tile,Int)){
			this._tile = config.tile;
		}else if(Std.is(config.tile,String)){
			this._tile = _tilesheet.getTileNumber(config.tile);

		}

        if(Std.is(config.imageScale,Float)) {
			imageScale = config.imageScale;
		}

		if(Std.is(config.parallax,Float)){
			_parallax = config.parallax;
		}
		setPoints(
			new FVector(0,0)
			,new FVector(0,-10)
		);

		firmament.util.FLog.debug(_tile);
	}
	

	public function initTilesheet(){
		var image = _config['image'];
		var imageIsFileName = false;
		if(Std.is(_config['tilesheetFile'],String)){
			_tilesheet = FTilesheetManager.getInstance().getTilesheetFromDefinitionFile(_config['tilesheetFile']);
			if(_tilesheet == null){
				throw('tilesheet file "'+_config['tilesheetFile']+'" could not be loaded');
			}
		}
		else if(image !=null){
			if(Std.is(image,FTilesheet)){
				_tilesheet = cast(image);
			}else{
				var bd:BitmapData=null;
				if(Std.is(image,String)){
					//firmament.util.FLog.debug("image: " + Std.string(image));
					if(Assets.exists(cast(image,String))){
						bd = Assets.getBitmapData(cast(image,String));
					}
				}
				else if(Std.is(image,BitmapData)){
					bd = cast(image,BitmapData);
				}
				else if(bd==null){
					throw("invalid tileSheetImage");
				}
				_tilesheet = new FTilesheet(bd);
				if(imageIsFileName){
					_tilesheet.setImageFileName(cast(image,String));
				}
				_tilesheet.addTileRect(new Rectangle (0, 0, bd.width, bd.height),new Point(bd.width/2,bd.height/2));
			}
		}else{
			//try to get a tilesheet from the animation
			var animationC = _entity.getComponent("animation");
			if(animationC!=null){
				var c = cast(animationC,FAnimationComponent);
				c.jumpToFrame(0);
			}
		}
	}

	public function render(camera:FCamera):Void {
		//make sure we are currently active 
		if(!_entity.isActive())return;

		if (_tilesheet == null) {
			firmament.util.FLog.debug('tilesheet is null');
			return;
		}

		_entity.trigger(new FEvent(FGame.BEFORE_RENDER));
		
		var cameraPos = camera.getTopLeftPosition(this._parallax);
		var ratio = camera.getZoom() / imageScale;


		var stepDistance = _tilesheet.getRectangle(_tile).width/camera.getZoom();
		var startDistance = stepDistance/2;
		var start = _startPoint.getPointAtAngle(_angle,startDistance);
		var stepNum = Math.floor(_distanceBetween/stepDistance);
		var pos = start;
		var multiplier = _parallax * camera.getZoom();
		var count:Int = 0;
		var drawList:Array<Float> = new Array();

		for(x in 0 ... stepNum){
			
			if(x>0)pos = pos.getPointAtAngle(_angle,stepDistance);
			var nx = ((pos.x - cameraPos.x) *multiplier);
			var ny = ((pos.y - cameraPos.y) *multiplier);
			
			var a:Float, b:Float,c:Float,d:Float;
			
			a = Math.cos(_angle)*ratio;
			b = Math.sin(_angle)*ratio; 
			c = -Math.sin(_angle)*ratio; 
			d = Math.cos(_angle)*ratio;
			drawList[count++] = nx;
			drawList[count++] = ny;
			drawList[count++] = this._tile; // sprite index
			drawList[count++] = a;
			drawList[count++] = b;
			drawList[count++] = c;
			drawList[count++] = d;

			drawList[count++] = _r;
			drawList[count++] = _g;
			drawList[count++] = _b;
			//drawList[count++] = ratio;
			//drawList[count++] = physicsComponent.getAngle();
			drawList[count++] = _alpha;
			
			FTilesheetRenderHelper.getInstance().addToDrawList(_tilesheet, drawList, _entity.getProp('positionZ'));

		}
	}

	public function setTile(t:Int){
		this._tile = t;
	}

	public function setTileByLabel(label:String){
		this._tile = _tilesheet.getTileNumber(label);
	}

	public function getCurrentTile(){
		return _tile;
	}

	public function getTilesheet():FTilesheet{
		return _tilesheet;
	}


	public function setTilesheet(t:FTilesheet){
		_tilesheet = t;
	}


	public function setImageScale(scale:Float){
		imageScale = scale;
	}

	public function getImageScale(){
		return imageScale;
	}
	
	public function getBitmapData():BitmapData{
		var sprite:Sprite = new Sprite();
		var index =0;
		var drawList:Array<Float> = new Array();

		drawList[index] = _tilesheet.getRectangle(_tile).width/2;
		drawList[index + 1] = _tilesheet.getRectangle(_tile).height/2;
		drawList[index + 2] = this._tile; // sprite index
		drawList[index + 3] = 1;
		_tilesheet.drawTiles(sprite.graphics, drawList, true, Tilesheet.TILE_ALPHA);
		var bd:BitmapData = new BitmapData(Std.int(sprite.width),Std.int(sprite.height));
		bd.draw(sprite);
		return bd;
	}
	
	override public function getType():String {
		return "render";
	}

	public function getParallaxMultiplier(p:Float=0):Float{
		return _parallax;
	}
	
	public function setPoints(start:FVector,end:FVector){
		_startPoint = start;
		_endPoint = end;
		_angle = _startPoint.angleTo(_endPoint);
		_distanceBetween = _startPoint.distanceTo(end);
		//firmament.util.FLog.debug(_distanceBetween);


	}

	//rounds to 4 decimal places.
	/*private function round(val:Float):Float{
		var places:Int = 4;
		var factor:Int = cast(Math.pow(10,places));
		val = val*factor;
		var tmp:Int = Math.round(val);
		return tmp/factor;
	}*/
	
}