package firmament.util.rtree;

class RTLeaf<T>
{
	private var obj:T;
	public var parentNode:RTNode<T>;
	public var topX:Float;
	public var topY:Float;
	public var botX:Float;
	public var botY:Float;
	
	public function new(obj:T, parentNode:RTNode<T>, topX:Float, topY:Float, botX:Float, botY:Float) 
	{
		this.obj = obj;
		this.parentNode = parentNode;
		this.topX = topX;
		this.topY = topY;
		this.botX = botX;
		this.botY = botY;
	}
	
	//returns the object of this leaf
	public function getObj():T
	{
		return obj;
	}
}