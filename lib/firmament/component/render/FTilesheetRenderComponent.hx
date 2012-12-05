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
import nme.Assets;
import nme.display.BitmapData;
import nme.display.IBitmapDrawable;
import nme.display.Sprite;
import nme.display.Tilesheet;
import nme.events.Event;
import nme.events.EventDispatcher;
import nme.geom.Point;
import nme.geom.Rectangle;



/**
 * ...
 * @author jordan
 */
class FTilesheetRenderComponent extends FEntityComponent ,implements FRenderComponentInterface 
{
	var drawList:Array<Float>;
	var _tilesheet:FTilesheet;
	var imageScale:Float;
	var _tile:Int;
	var _parallax:Float;
		
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
		}

        if(Std.is(config.imageScale,Int)) {
			imageScale = config.imageScale;
		}

		if(Std.is(config.parallax,Float)){
			_parallax = config.parallax;
		}
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
		
		var physicsComponent:FPhysicsComponentInterface = this._entity.getPhysicsComponent();
		if(physicsComponent == null) return;
		var cameraPos = camera.getTopLeftPosition(this._parallax);
		var ratio = camera.getZoom() / imageScale;
		var pos = physicsComponent.getPosition();
		var nx = ((pos.x - cameraPos.x) *_parallax * camera.getZoom());
		var ny = ((pos.y - cameraPos.y) *_parallax * camera.getZoom());
		
		var index =0;
		drawList[index] = nx;
		drawList[index + 1] = ny;
		drawList[index + 2] = this._tile; // sprite index
		drawList[index + 3] = ratio;
		drawList[index + 4] = -physicsComponent.getAngle();
		drawList[index + 5] = 1;
		
		FTilesheetRenderHelper.getInstance().addToDrawList(_tilesheet, drawList);
	}

	public function setTile(t:Int){
		this._tile = t;
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
	
	
}