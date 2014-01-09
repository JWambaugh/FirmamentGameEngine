package firmament.core;

/**
 * Class: FVector
 * @author Jordan Wambaugh
 */

class FVector
{
	public var x:Float;
	public var y:Float;

	/**
	 * Constructor: new
	 * 
	 */
	public function new(x:Float =0,y:Float =0) 
	{
		this.x=x;
		this.y=y;
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

	


	public function setZero() : Void { x = 0.0; y = 0.0; }
	public function set(x_:Float=0, y_:Float=0) : Void {x=x_; y=y_;}
	public function setV(v:FVector) : Void {x=v.x; y=v.y;}

	public function getNegative():FVector { return new FVector(-x, -y); }
	public function negativeSelf():Void { x = -x; y = -y; }
	
	static public function make(x_:Float, y_:Float):FVector
	{
		return new FVector(x_, y_);
	}
	
	public function copy():FVector{
		return new FVector(x,y);
	}
	
	public function add(v:FVector) : Void
	{
		x += v.x; y += v.y;
	}
	
	public function subtract(v:FVector) : Void
	{
		x -= v.x; y -= v.y;
	}

	public function multiply(a:Float) : Void
	{
		x *= a; y *= a;
	}
	
	
	
	public function crossVF(s:Float) : Void
	{
		var tX:Float = x;
		x = s * y;
		y = -s * tX;
	}
	
	public function crossFV(s:Float) : Void
	{
		var tX:Float = x;
		x = -s * y;
		y = s * tX;
	}
	
	public function minV(b:FVector) : Void
	{
		x = x < b.x ? x : b.x;
		y = y < b.y ? y : b.y;
	}
	
	public function maxV(b:FVector) : Void
	{
		x = x > b.x ? x : b.x;
		y = y > b.y ? y : b.y;
	}
	
	public function abs() : Void
	{
		if (x < 0) x = -x;
		if (y < 0) y = -y;
	}

	public function length():Float
	{
		return Math.sqrt(x * x + y * y);
	}
	
	public function lengthSquared():Float
	{
		return (x * x + y * y);
	}

	

	public function isValid():Bool
	{
		return isValidFloat(x) && isValidFloat(y);
	}

	private function isValidFloat(x:Float) : Bool
	{
		if (Math.isNaN (x) || x == Math.NEGATIVE_INFINITY || x == Math.POSITIVE_INFINITY) {
			return false;
		}
		return true;
	}

	
	
	
}