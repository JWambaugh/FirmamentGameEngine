package firmament.core;
import nme.display.BitmapData;
import nme.geom.Matrix;
import nme.display.IBitmapDrawable;
import nme.geom.Point;
import nme.events.EventDispatcher;
import nme.display.Tilesheet;
import nme.geom.Rectangle;
/**
 * ...
 * @author jordan
 */
class FTilesheetRenderer extends EventDispatcher ,implements FRenderer 
{
	var drawList:Array<Float>;
		
	public function new() 
	
	{
		drawList = new Array<Float>();
		super();
	}
	
	public function render(item:FRenderable, camera:FCamera):Void {
		var TILE_FIELDS = 6; // x+y+index+scale+rotation+alpha
		var bitmap = item.getCurrentImage();
		var tileSheet:Tilesheet = item.getTilesheet();
		if (tileSheet == null) {
			trace('tileSheet is null');
			return;
		}
		
		
		var cameraPos = camera.getTopLeftPosition();
		//var matrix = new Matrix();
		var ratio = camera.getZoom() / item.getImageScale();
		var pos = item.getPosition();
		var nx = ((pos.x - cameraPos.x) * camera.getZoom());
		var ny = ((pos.y - cameraPos.y) * camera.getZoom());
		//matrix.scale(ratio,ratio);
		
		//trace(cameraPos.y);
		var index =0;
		drawList[index] = nx;
		drawList[index + 1] = ny;
		//drawList[index + 2] = 0; // sprite index
		drawList[index + 3] = ratio;
		drawList[index + 4] = item.getAngle();
		drawList[index + 5] = 1;
		
		tileSheet.drawTiles(camera.graphics, drawList, true, 
			Tilesheet.TILE_SCALE | Tilesheet.TILE_ROTATION | Tilesheet.TILE_ALPHA);
		
		
		
	}
	
}