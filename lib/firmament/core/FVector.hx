package firmament.core;

import box2D.common.math.B2Vec2;
/**
 * Class: FVector
 * @author Jordan Wambaugh
 */

class FVector extends B2Vec2
{

	/**
	 * Constructor: new
	 * 
	 */
	public function new(x:Float =0,y:Float =0) 
	{
		super(x, y);
	}
	
	
	public function toString() {
		return this.x + ',' + this.y;
	}
	
	/**
	 * Returns the distance between this and another vector.
	 * Always returns a positive value.
	 * @param	v
	 * @return
	 */
	public function distanceTo(v:FVector):Float {
		var d = Math.sqrt(Math.pow(this.x - v.x, 2) + Math.pow(this.y - v.y, 2));
		if (d < 0) d = -d;
		return d;
	}

	override public function copy():FVector{
		return new FVector(x,y);
	}
	
	
}