package firmament.utils;
import firmament.core.FVector;
import nme.display.BitmapData;

/**
 * ...
 * @author Jordan Wambaugh
 */

 enum FVertexPointedDirection {
	
	}
	enum FVertexRelativeDirection {
		frontLeft;
		frontRight;
		backLeft;
		backRight;
		
	}
	enum FVertexCompassDirection {
		north;
		south;
		east;
		west;
		northEast;
		northWest;
		southEast;
		southWest;
	}
class FTracerVertex 
{
	
	public var x:Int;
	public var y:Int;
	
	//the direction traveled from the last vertex.
	var directionPointed:FVertexCompassDirection;
	
	
	public function new(x:Int,y:Int,?direction:FVertexCompassDirection) 
	{
		this.x = x;
		this.y = y;
		//default to up, because when we first find an edge, we know we are at the left-most point.
		if (direction == null) this.directionPointed = north;
		else this.directionPointed = direction;
	}
	
	/**
	 * returns the compass direction based on the vertex's pointed direction.
	 * @param	relDirection
	 */
	private function getCompassDirection(relDirection:FVertexRelativeDirection):FVertexCompassDirection {
		switch(this.directionPointed){
			case north: return switch(relDirection) {
				case frontLeft:northWest;
				case frontRight:northEast;
				case backLeft:southWest;
				case backRight:southEast;
			};
			case east: return switch(relDirection) {
				case frontLeft:northEast;
				case frontRight:southEast;
				case backLeft:northWest;
				case backRight:southWest;
			};
			case south: return switch(relDirection) {
				case frontLeft:southEast;
				case frontRight:southWest;
				case backLeft:northEast;
				case backRight:northWest;
			};
			case west: return switch(relDirection) {
				case frontLeft:southWest;
				case frontRight:northWest;
				case backLeft:southEast;
				case backRight:northEast;
			};
		default: return null;
			
		}
	}
	
	function getVertexForPosition(direction:FVertexCompassDirection):FTracerVertex {
		var x = this.x;
		var y = this.y;
		
		switch(direction) {
			case north:y--;
			case south:y++;
			case west:x--;
			case east:x++;
			default:return null;
		}
		return new FTracerVertex(x, y,direction);
	}
	
	
	
	
	function getPixelCompass(bitmap:BitmapData, direction:FVertexCompassDirection):{x:Int,y:Int} {
		return switch(direction) {
			case northWest: return {x:this.x - 1, y:this.y - 1};
			case northEast: return {x:this.x,y: this.y - 1};
			case southEast: return {x:this.x, y:this.y};
			case southWest: return {x:this.x - 1,y: this.y};
			default: throw "Invalid direction";
		}
	}
	
	public function getPixel(bitmap:BitmapData, direction:FVertexRelativeDirection):{x:Int,y:Int} {
		return this.getPixelCompass(bitmap, this.getCompassDirection(direction));
	}
	
	public function compare(v:FTracerVertex):Bool {
		if (v.x == this.x && v.y == this.y) return true;
		return false;
	}
	 
	
}