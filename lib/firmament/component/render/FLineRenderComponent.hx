package firmament.component.render;



import firmament.component.base.FEntityComponent;
import firmament.component.physics.FPhysicsComponentInterface;
import firmament.component.render.FRenderComponentInterface;
import firmament.core.FCamera;
import firmament.core.FGame;
import firmament.core.FTilesheet;
import firmament.core.FTilesheetManager;
import firmament.core.FTilesheetRenderHelper;
import firmament.component.animation.FAnimationComponent;
import openfl.Assets;
import flash.display.BitmapData;
import flash.display.IBitmapDrawable;
import flash.display.Sprite;
import openfl.display.Tilesheet;
import flash.events.Event;
import flash.events.EventDispatcher;
import flash.geom.Point;
import flash.geom.Rectangle;
import firmament.core.FVector;



/**
 * ...
 * @author jordan
 */
class FLineRenderComponent extends FEntityComponent  implements FRenderComponentInterface 
{
	var drawList:Array<Float>;
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
	public function new() {
		imageScale=100;
		super();
		drawList = new Array<Float>();
		_tile = 0;
		_parallax = 1;
		
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
	}
	

	public function initTilesheet(){
		var image = _config.image;
		var imageIsFileName = false;
		if(Std.is(_config.tilesheetFile,String)){
			_tilesheet = FTilesheetManager.getInstance().getTilesheetFromDifinitionFile(_config.tilesheetFile);

		}
		else if(image !=null){
			if(Std.is(image,FTilesheet)){
				_tilesheet = cast(image);
			}else{
				var bd:BitmapData;
				if(Std.is(image,String)){
					//trace("image: " + Std.string(image));
					bd = Assets.getBitmapData(cast(image,String));
					
				}
				else if(Std.is(image,BitmapData)){
					bd = cast(image,BitmapData);
				}
				else{
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
		var TILE_FIELDS = 6; // x+y+index+scale+rotation+alpha
		
		//make sure we are currently active 
		if(!_entity.isActive())return;

		FTilesheetRenderHelper.getInstance().initCamera(camera);
		if (_tilesheet == null) {
			trace('tilesheet is null');
			return;
		}

		this._entity.dispatchEvent(new Event(FGame.BEFORE_RENDER));
		
		var cameraPos = camera.getTopLeftPosition(this._parallax);
		var ratio = camera.getZoom() / imageScale;


		var stepDistance = _tilesheet.getRectangle(_tile).width/camera.getZoom();
		var startDistance = stepDistance/2;
		var start = _startPoint.getPointAtAngle(_angle,startDistance);
		var stepNum = Math.floor(_distanceBetween/stepDistance);
		var pos = start;
		var multiplier = _parallax * camera.getZoom();
		//trace(stepNum);
		for(x in 0 ... stepNum){
			
			if(x>0)pos = pos.getPointAtAngle(_angle,stepDistance);
			var nx = ((pos.x - cameraPos.x) *multiplier);
			var ny = ((pos.y - cameraPos.y) *multiplier);
			/*
			var index =0;
			drawList[index] = nx;
			drawList[index + 1] = ny;
			drawList[index + 2] = this._tile; // sprite index
			drawList[index + 3] = ratio;
			drawList[index + 4] = -_angle;
			drawList[index + 5] = 1;*/
			var a:Float, b:Float,c:Float,d:Float;
			
			a = Math.cos(_angle)*ratio;
			b = Math.sin(_angle)*ratio; 
			c = -Math.sin(_angle)*ratio; 
			d = Math.cos(_angle)*ratio;
			drawList[0] = nx;
			drawList[1] = ny;
			drawList[2] = this._tile; // sprite index
			drawList[3] = a;
			drawList[4] = b;
			drawList[5] = c;
			drawList[6] = d;
			drawList[7] = _r;
			drawList[8] = _g;
			drawList[9] = _b;
			//drawList[3] = ratio;
			//drawList[4] = physicsComponent.getAngle();
			drawList[10] = _alpha;
			
			FTilesheetRenderHelper.getInstance().addToDrawList(_tilesheet, drawList);

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

	public function getParallaxMultiplier():Float{
		return _parallax;
	}
	
	public function setPoints(start:FVector,end:FVector){
		_startPoint = start;
		_endPoint = end;
		_angle = _startPoint.angleTo(_endPoint);
		_distanceBetween = _startPoint.distanceTo(end);
	}
	
}