package firmament.utils;

import firmament.core.FVector;
import firmament.utils.FTracerVertex;
import nme.display.BitmapData;
/**
 * traces a given bitmap image and returns the resulting polygons
 * @author Jordan Wambaugh
 */

class FBitmapTracer 
{

	var polygons:Array<Array<FVector>>;
	var polyInProgress:Array<FTracerVertex>;
	var bitmap:BitmapData;
	public function new(bitmap:BitmapData) 
	{
		this.polygons = new Array<Array<FVector>>();
		this.bitmap = bitmap.clone();
	}
	
	/**
	 * Decides if the color provided is to be considered content.
	 * @param	color	Must be 32-bit color value.
	 */
	public function isContent(color:Int):Bool {
		var alphaValue:Int = color >> 24 & 0xFF;
		if (alphaValue != 0) return true;
		return false;
	}
	
	private function findEdge():FTracerVertex {
		for (x in 0 ... this.bitmap.width) {
			for (y in 0 ... this.bitmap.height) {
				if (this.isContent( this.bitmap.getPixel32(x, y))) return new FTracerVertex(x, y);
			}
		}
		return null;
	}
	
	
	private function trace() {
		//get first edge
		var startPoint:FTracerVertex = this.findEdge();
		if (startPoint == null) return false;
		
		var current:FTracerVertex;
		current = startPoint;
		do{
		//check if front right is content. if not, always head to the right.
		var  frontRight = current.getPixel(this.bitmap, frontRight);
		if (!isContent(bitmap.getPixel32(frontRight.x, frontRight.y))) {
			
		}
		}while (current.compare(startPoint) != true);
		
		return true;
	}
	
}