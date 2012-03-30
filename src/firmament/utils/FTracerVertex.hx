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
		front;
		right;
		left;
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
				case front:north;
				case right:east;
				case left:west;
			};
			case east: return switch(relDirection) {
				case frontLeft:northEast;
				case frontRight:southEast;
				case backLeft:northWest;
				case backRight:southWest;
				case front:east;
				case right:south;
				case left:north;
			};
			case south: return switch(relDirection) {
				case frontLeft:southEast;
				case frontRight:southWest;
				case backLeft:northEast;
				case backRight:northWest;
				case front:south;
				case right:west;
				case left:east;
			};
			case west: return switch(relDirection) {
				case frontLeft:southWest;
				case frontRight:northWest;
				case backLeft:southEast;
				case backRight:northEast;
				case front:west;
				case right:north;
				case left:south;
			};
		default: return null;
			
		}
	}
	
	public function getVertexForPosition(direction:FVertexCompassDirection):FTracerVertex {
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
	
	public function getVertexForRelativePosition(direction:FVertexRelativeDirection):FTracerVertex {
		return this.getVertexForPosition(this.getCompassDirection(direction));
	}
	
	
	
	function getPixelCompass(bitmap:BitmapData, direction:FVertexCompassDirection):{x:Int,y:Int} {
		return switch(direction) {
			case northWest:  {x:this.x - 1, y:this.y - 1};
			case northEast: {x:this.x,y: this.y - 1};
			case southEast:  {x:this.x, y:this.y};
			case southWest: {x:this.x - 1,y: this.y};
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