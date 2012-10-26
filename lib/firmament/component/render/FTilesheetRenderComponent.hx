package firmament.component.render;
import firmament.component.base.FEntityComponent;
import firmament.component.render.FRenderComponentInterface;
import firmament.component.physics.FPhysicsComponentInterface;
import firmament.core.FCamera;
import nme.display.BitmapData;
import nme.geom.Matrix;
import nme.display.IBitmapDrawable;
import nme.geom.Point;
import nme.events.EventDispatcher;
import nme.display.Tilesheet;
import nme.geom.Rectangle;
import nme.Assets;
/**
 * ...
 * @author jordan
 */
class FTilesheetRenderComponent extends FEntityComponent ,implements FRenderComponentInterface 
{
	var drawList:Array<Float>;
	var tileSheet:Tilesheet;
	var imageScale:Int;
		
	public function new() 
	
	{
		super();
		drawList = new Array<Float>();
		
	}

	override public function init(config:Dynamic){
		this._config = config;
		var fileName = config.tileSheetImage;
		
		if(Std.is(fileName,Tilesheet)){
			tileSheet = cast(fileName);
		}else{
			var bd:BitmapData;
			if(Std.is(fileName,String)){
				trace("Filename: " + Std.string(fileName));
				bd = Assets.getBitmapData(cast(fileName,String));
			}
			else if(Std.is(fileName,BitmapData)){
				bd = cast(fileName,BitmapData);
			}
			else{
				throw("invalid tileSheetImage");
			}
			tileSheet = new Tilesheet(bd);
			tileSheet.addTileRect(new Rectangle (0, 0, bd.width, bd.height),new Point(bd.width/2,bd.height/2));
		}

		this.setupTileSheet();
		
		imageScale = 100;
	}
	

	public function setupTileSheet(){

				
	}

	public function render(camera:FCamera):Void {
		var TILE_FIELDS = 6; // x+y+index+scale+rotation+alpha
		
		camera.graphics.lineStyle(null,0,0);
		if (tileSheet == null) {
			trace('tileSheet is null');
			return;
		}
		
		var physicsComponent:FPhysicsComponentInterface = cast(this._entity.getComponent("physics"));
		var cameraPos = camera.getTopLeftPosition();
		//var matrix = new Matrix();
		var ratio = camera.getZoom() / imageScale;
		var pos = physicsComponent.getPosition();
		var nx = ((pos.x - cameraPos.x) * camera.getZoom());
		var ny = ((pos.y - cameraPos.y) * camera.getZoom());
		//matrix.scale(ratio,ratio);
		
		//trace(cameraPos.y);
		var index =0;
		drawList[index] = nx;
		drawList[index + 1] = ny;
		//drawList[index + 2] = 0; // sprite index
		drawList[index + 3] = ratio;
		drawList[index + 4] = -physicsComponent.getAngle();
		drawList[index + 5] = 1;
		
		tileSheet.drawTiles(camera.graphics, drawList, true, 
			Tilesheet.TILE_SCALE | Tilesheet.TILE_ROTATION | Tilesheet.TILE_ALPHA);
	}
	
	override public function getType():String {
		return "render";
	}
	
	
}