package firmament.util.rtree;

class RTree<T> 
{
	//settings
	private var maxChildsPerNode:Int; //howmany childs (leaf or node) a node may have (must be 4 or higher and have a square root without decimals)
	private var toleranceEpsilon:Float; //the tolerance epsilon used for float comparison
	
	//main node
	private var mainNode:RTNode<T>;

	public function new(mainTopX:Float, mainTopY:Float, mainBotX:Float, mainBotY:Float, ?maxChildsPerNode:Int = 25, ?toleranceEpsilon:Float = 1e-10, ?workNodeTopX:Float, ?workNodeTopY:Float, ?workNodeBotX:Float, ?workNodeBotY:Float) 
	{
		//setup settings
		if ((maxChildsPerNode >= 4) && (Math.sqrt(maxChildsPerNode) % 1 == 0)) this.maxChildsPerNode = maxChildsPerNode;
		this.toleranceEpsilon = toleranceEpsilon;
		
		//setup main node
		mainNode = new RTNode<T>(mainTopX, mainTopY, mainBotX, mainBotY, maxChildsPerNode, toleranceEpsilon);
		
		//setup working node if set
		if ((workNodeTopX != null) && (workNodeTopY != null) && (workNodeBotX != null) && (workNodeBotY != null)) {
			mainNode.addCustomNode(workNodeTopX, workNodeTopY, workNodeBotX, workNodeBotY);
		}
	}
	
	//adds an object to the tree
	public function insertObj(obj:T, topX:Float, topY:Float, botX:Float, botY:Float):Void
	{
		mainNode.insertObj(obj, topX, topY, botX, botY);
	}
	
	//returns all Ts in an array which are located at the given position or null when no results were found
	public function getObjectsFromPosition(topX:Float, topY:Float, ?overlapX:Float = 0, ?overlapY:Float = 0):Array<T>
	{
		return mainNode.getObjectsFromPosition(topX, topY, overlapX, overlapY);
	}
	
	//returns all Ts in an array which are located within the given range or null when no results were found
	public function getObjectsFromRange(topX:Float, topY:Float, botX:Float, botY:Float, ?overlapX:Float = 0, ?overlapY:Float = 0):Array<T>
	{
		return mainNode.getObjectsFromRange(topX, topY, botX, botY, overlapX, overlapY);
	}
	
	//returns all leafs with object T in an array which are located at the given position or null when no results were found
	public function getLeafsFromPosition(topX:Float, topY:Float, ?overlapX:Float = 0, ?overlapY:Float = 0):Array<RTLeaf<T>>
	{
		return mainNode.getLeafsFromPosition(topX, topY, overlapX, overlapY);
	}
	
	//returns all leafs containing T in an array which are located within the given range or null when no results were found
	public function getLeafsFromRange(topX:Float, topY:Float, botX:Float, botY:Float, ?overlapX:Float = 0, ?overlapY:Float = 0):Array<RTLeaf<T>>
	{
		return mainNode.getLeafsFromRange(topX, topY, botX, botY, overlapX, overlapY);
	}
	
	//updates the leaf of the given object
	public function updateObject(obj:T, objTopX:Float, objTopY:Float, ?newTopX:Float, ?newTopY:Float, ?newBotX:Float, ?newBotY:Float):Void
	{
		mainNode.updateObject(obj, objTopX, objTopY, newTopX, newTopY, newBotX, newBotY);
	}
	
	//updates the data of the given leaf
	public function updateLeaf(leaf:RTLeaf<T>, ?topX:Float = null, ?topY = null, ?botX = null, ?botY = null):Void
	{
		mainNode.updateLeaf(leaf, topX, topY, botX, botY);
	}

	//updates the leaf of the given object
	public function deleteObject(obj:T, objTopX:Float, objTopY:Float):Void
	{
		mainNode.deleteObject(obj, objTopX, objTopY);
	}



}