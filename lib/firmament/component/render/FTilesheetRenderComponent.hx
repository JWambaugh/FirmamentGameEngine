package firmament.component.render;



import firmament.component.base.FEntityComponent;
import firmament.component.physics.FPhysicsComponentInterface;
import firmament.component.render.FRenderComponentInterface;
import firmament.core.FCamera;
import firmament.core.FGame;
import firmament.tilesheet.FTilesheet;
import firmament.tilesheet.FTilesheetManager;
import firmament.tilesheet.FTilesheetRenderHelper;
import firmament.component.animation.FAnimationComponent;
import firmament.core.FVector;
import openfl.Assets;
import flash.display.BitmapData;
import flash.display.IBitmapDrawable;
import flash.display.Sprite;
import openfl.display.Tilesheet;
import flash.events.Event;
import flash.events.EventDispatcher;
import flash.geom.Point;
import flash.geom.Rectangle;
import firmament.core.FEvent;




/**
 * ...
 * @author jordan
 */
class FTilesheetRenderComponent extends FEntityComponent  implements FRenderComponentInterface 
{
	var drawList:Array<Float>;
	var _tilesheet:FTilesheet;
	var imageScale:Float;
	var _tile:Int;
	var _parallax:Float;
	var _flipX:Bool;
	var _flipY:Bool;
	
	var _positionOffset:FVector;
	var _angleOffset:Float;

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
		_flipX = false;
		_flipY = false;
		_positionOffset = new FVector(0,0);
		_angleOffset = 0;
	}

	override public function init(config:Dynamic){
		this._config = config;
		var ch = getConfigHelper();
		initTilesheet();

		if(_tilesheet == null){
			throw 'tilesheet is still null after init';
		}
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
				var bd:BitmapData = null;
				if(Std.is(image,String)){
					//trace("image: " + Std.string(image));
					if(Assets.exists(cast(image,String))){
						bd = Assets.getBitmapData(cast(image,String));
					}
					
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
		
		//make sure we are currently active 
		if(!_entity.isActive())return;

		FTilesheetRenderHelper.getInstance().initCamera(camera);
		if (_tilesheet == null) {
			trace('tilesheet is null');
			return;
		}

		this._entity.trigger(new FEvent(FGame.BEFORE_RENDER));
		
		var cameraPos = camera.getTopLeftPosition(this._parallax);
		var ratio = camera.getZoom() / imageScale;
		var pos = _entity.getPropertyValue("position");
		var nx = (((pos.x+_positionOffset.x) - cameraPos.x) *_parallax * camera.getZoom());
		var ny = (((pos.y+_positionOffset.y) - cameraPos.y) *_parallax * camera.getZoom());
		var a:Float, b:Float,c:Float,d:Float;
		var angle =_entity.getPropertyValue('angle')+_angleOffset;
		//perform rotation and scale
		a = Math.cos(angle)*ratio;
		b = Math.sin(angle)*ratio; 
		c = -Math.sin(angle)*ratio; 
		d = Math.cos(angle)*ratio;
		if(_flipX)a =- a;
		if(_flipY)d =- d;
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
		
		FTilesheetRenderHelper.getInstance().addToDrawList(_tilesheet, drawList, _entity.getProp('positionZ'));
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

	public function setRGB(r:Float,g:Float,b:Float){
		_r=r;
		_g=g;
		_b=b;
	}

	public function getRGB(){
		return {
			r:_r
			,g:_g
			,b:_b
		}
	}

	public function setAlpha(a:Float){
		_alpha = a;
	}

	public function getAlpha(){
		return _alpha;
	}
	
	
}