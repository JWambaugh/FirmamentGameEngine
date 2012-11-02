package firmament.component.render;



import firmament.component.base.FEntityComponent;
import firmament.component.physics.FPhysicsComponentInterface;
import firmament.component.render.FRenderComponentInterface;
import firmament.core.FCamera;
import firmament.core.FGame;
import firmament.core.FTilesheet;
import firmament.core.FTilesheetManager;
import firmament.core.FTilesheetRenderHelper;
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
	var tilesheet:FTilesheet;
	var imageScale:Int;
	var tile:Int;
		
	public function new() {
		super();
		drawList = new Array<Float>();
		tile = 0;
		
	}

	override public function init(config:Dynamic){
		this._config = config;
		var image = config.image;
		var imageIsFileName = false;
		if(Std.is(config.tilesheetFile,String)){
			tilesheet = FTilesheetManager.getInstance().getTilesheetFromDifinitionFile(config.tilesheetFile);

		}
		else if(image !=null){
			if(Std.is(image,FTilesheet)){
				tilesheet = cast(image);
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
				tilesheet = new FTilesheet(bd);
				if(imageIsFileName){
					tilesheet.setImageFileName(cast(image,String));
				}
				tilesheet.addTileRect(new Rectangle (0, 0, bd.width, bd.height),new Point(bd.width/2,bd.height/2));
			}
		}
		if(Std.is(config.tile,Int)){
			this.tile = config.tile;
		}

		imageScale = 100;
	}
	

	public function render(camera:FCamera):Void {
		var TILE_FIELDS = 6; // x+y+index+scale+rotation+alpha
		FTilesheetRenderHelper.getInstance().initCamera(camera);
		if (tilesheet == null) {
			trace('tilesheet is null');
			return;
		}

		this.dispatchEvent(new Event(FGame.BEFORE_RENDER));
		
		var physicsComponent:FPhysicsComponentInterface = cast(this._entity.getComponent("physics"));
		var cameraPos = camera.getTopLeftPosition();
		var ratio = camera.getZoom() / imageScale;
		var pos = physicsComponent.getPosition();
		var nx = ((pos.x - cameraPos.x) * camera.getZoom());
		var ny = ((pos.y - cameraPos.y) * camera.getZoom());
		
		var index =0;
		drawList[index] = nx;
		drawList[index + 1] = ny;
		drawList[index + 2] = this.tile; // sprite index
		drawList[index + 3] = ratio;
		drawList[index + 4] = -physicsComponent.getAngle();
		drawList[index + 5] = 1;
		
		FTilesheetRenderHelper.getInstance().addToDrawList(tilesheet, drawList);
	}

	public function getBitmapData():BitmapData{
		var sprite:Sprite = new Sprite();
		var index =0;
		drawList[index] = 0;
		drawList[index + 1] = 0;
		drawList[index + 2] = this.tile; // sprite index
		drawList[index + 3] = 1;
		tilesheet.drawTiles(sprite.graphics, drawList, true, Tilesheet.TILE_ALPHA);
		return new BitmapData(0,0);
	}
	
	override public function getType():String {
		return "render";
	}
	
	
}