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
		var fileName = config.tileSheetImage;
		
		var i:Dynamic=null;
		if(Std.is(fileName,String)){
			trace("Filename: " + Std.string(fileName));
			i = Assets.getBitmapData(cast(fileName,String));
			tileSheet = new Tilesheet(i);
			tileSheet.addTileRect(new Rectangle (0, 0, i.width, i.height),new Point(i.width/2,i.height/2));
		}
		else if(Std.is(fileName,BitmapData)){
			i = cast(fileName,BitmapData);
			tileSheet = new Tilesheet(i);

			tileSheet.addTileRect(new Rectangle (0, 0, i.width, i.height),new Point(i.width/2,i.height/2));

		}
		else if(Std.is(fileName,Tilesheet)){
			tileSheet = cast(fileName);
		}
		else{
			throw("invalid tileSheetImage");
		}

		
		

		
		imageScale = 100;
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