package firmament.utils;

import firmament.core.FVector;
import firmament.utils.FTracerVertex;
import nme.display.BitmapData;
import firmament.utils.FPolySimplifier;
/**
 * traces a given bitmap image and returns the resulting polygons
 * @author Jordan Wambaugh
 */

class FBitmapTracer 
{

	var polygons:Array<Array<FVector>>;
	
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
	
	public function getPolys() {
		var verts = this.trace();
		return this.vertexesToPolys(verts);
	}
	
	/**
	 * converts an array of vertexes to an array of FVectors.
	 */
	private function vertexesToPolys(vertexes:Array<FTracerVertex>):Array<FVector> {
		var vectors:Array<FVector> = new Array<FVector>();
		var counter:Int = 0;
		
		
		
		
		
		for (vertex in vertexes) {
	
			var vector = new FVector(vertex.x / 100, vertex.y / 100);
		
			vectors.push(vector);
		}
			
		
		
		
		vectors = FPolySimplifier.simplify(vectors, .3);
		var min:FVector = new FVector();
		var max:FVector = new FVector();
		var counter = 0;
		for (vector in vectors) {
			
			if (counter++ == 0) {
				min.x = vector.x;
				min.y = vector.y;
				max.x = vector.x;
				max.y = vector.y;
			}

			if (vector.x < min.x) min.x = vector.x;
			if (vector.y < min.y) min.y = vector.y;
			if (vector.x > max.x) max.x = vector.x;
			if (vector.y > max.y) max.y = vector.y;
	
		}
		//center all vectors
		var diff = new FVector();
		diff.x = (min.x - max.x )/2;
		diff.y = (min.y - max.y) / 2;
		for (vect in vectors) {
			vect.x += diff.x;
			vect.y += diff.y;
		}
		
		
		
		return vectors;
	}
	
	
	private function trace():Array<FTracerVertex> {
		var vArray:Array<FTracerVertex> = new Array<FTracerVertex>();
		
		//get first edge
		var startPoint:FTracerVertex = this.findEdge();
		if (startPoint == null) return null;
		
		var current:FTracerVertex;
		current = startPoint;
		
		do {
		vArray.push(current);
		//check if front right is content. if not, always head to the right.
		var  frontRight = current.getPixel(this.bitmap, frontRight);
		if (!isContent(bitmap.getPixel32(frontRight.x, frontRight.y))) {
			current = current.getVertexForRelativePosition(right);
			continue;
		} 
		var  frontLeft = current.getPixel(this.bitmap, frontLeft);
		
		//if front left is not content, go straight
		if (!isContent(bitmap.getPixel32(frontLeft.x, frontLeft.y))) {
			current = current.getVertexForRelativePosition(front);
			continue;
		}
		
		//otherwise, turn left
		current = current.getVertexForRelativePosition(left);
		
		}while (current.compare(startPoint) != true);
		
		return vArray;
	}
	
}