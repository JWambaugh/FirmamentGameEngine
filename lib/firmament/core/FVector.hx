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
		var p1:Float = this.x - v.x;
		var p2:Float = this.y - v.y;
		var d = Math.sqrt(p1*p1 + p2*p2);
		return d;
	}

	/**
	 * Returns the angle to get to the specified FVector.
	 *
	 *
	 */
	public function angleTo(v:FVector){
		return Math.atan2(y-v.y, v.x-x);
	}


	/**
	 * Returns a new point that is distance away at angle.
	 *
	 *
	 */
	public function getPointAtAngle(angle:Float,distance:Float){
	    return new FVector(x+ Math.cos(angle)*distance ,y+Math.sin(angle)*distance);
	}

	public function makeUnit():FVector {
		var l:Float = length();
		var unit:FVector = new FVector(x/l,y/l);
		return unit;
	}

	override public function copy():FVector{
		return new FVector(x,y);
	}
	
	
}