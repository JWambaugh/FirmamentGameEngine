package firmament.core;


import firmament.core.FVector;

class FRectangle {
	public var top:Float;
	public var bottom:Float;
	public var left:Float;
	public var right:Float;
	public var height(get,null):Float;
	public var width(get,null):Float;
	public var center(get,null):FVector;

	public function new(left:Float,top:Float,right:Float,bottom:Float){
		this.top = top;
		this.bottom = bottom;
		this.left = left;
		this.right = right;
	}

	public function get_height():Float{
		return Math.abs(bottom-top);
	}
	public function get_width():Float{
		return Math.abs(right-left);
	}

	public function get_center():FVector{
		return new FVector(left+width/2,top+height/2);
	}

}