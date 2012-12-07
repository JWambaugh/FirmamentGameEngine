package firmament.util.rtree;

class RTNode<T>
{
	//settings
	private var maxChildsPerNode:Int;
	private var toleranceEpsilon:Float;
	private var mainNode:RTNode<T>;
		
	//node contents
	public var nodes:Array<RTNode<T>>;
	public var leafs:Array<RTLeaf<T>>;
	
	//node info
	public var topXBoundary:Float;
	public var topYBoundary:Float;
	public var botXBoundary:Float;
	public var botYBoundary:Float;
	
	public function new(topXBoundary:Float, topYBoundary:Float, botXBoundary:Float, botYBoundary:Float, maxChildsPerNode:Int, toleranceEpsilon:Float, ?mainNode:RTNode<T>)
	{
		this.nodes = new Array<RTNode<T>>();
		this.leafs = new Array<RTLeaf<T>>();
		this.topXBoundary = topXBoundary;
		this.topYBoundary = topYBoundary;
		this.botXBoundary = botXBoundary;
		this.botYBoundary = botYBoundary;
		this.maxChildsPerNode = maxChildsPerNode;
		this.toleranceEpsilon = toleranceEpsilon;
		if (mainNode == null) mainNode = this;
		this.mainNode = mainNode;
	}
	
	//adds an object to the tree
	public function insertObj(obj:T, topX:Float, topY:Float, botX:Float, botY:Float):Void
	{
		//if we have childs, go one level deeper
		var nodesLength:Int = nodes.length;
		if (nodesLength > 0) {
			for (i in 0...nodesLength) { //loop every node
				if ((topX >= nodes[i].topXBoundary) && (topY >= nodes[i].topYBoundary) && (topX <= nodes[i].botXBoundary) && (topY <= nodes[i].botYBoundary)) { //if our position is inside this node
					nodes[i].insertObj(obj, topX, topY, botX, botY); //go deeper into this node
					return;
				}
			}
			//we have not yet returned, apparently we need to add more nodes to make this object fit (happens only if this is the main node and it has infinite boundaries)
			expandAroundThisNode();
			//re-insert this object and return
			insertObj(obj, topX, topY, botX, botY);
			return;
		}
		else {
			//add leaf if this node is not yet full, one exception: if it is full, but all our objects have the same position, there is no way to split and thus we are still going to add these objects
			if (leafs.length < maxChildsPerNode) {
				leafs.push(new RTLeaf(obj, this, topX, topY, botX, botY));
				return;
			}
			else { //node is full: create new nodes and move leafs to the new nodes			
				//temporarily store leafs to an array
				var tempLeafArr:Array<RTLeaf<T>> = leafs.copy();
				
				//clear the current leaf array
				leafs = new Array<RTLeaf<T>>();
				
				//if we have reached maximum precision, create 2 nodes: fill the second, add this object to the first (the first one will be filled up by new identical position objects in the future)
				var deltaX:Float = botXBoundary - topXBoundary;
				var deltaY:Float = botYBoundary - topYBoundary;
				if ((deltaX < toleranceEpsilon) && (deltaY < toleranceEpsilon)) {
					nodes.push(new RTNode(topXBoundary, topYBoundary, botXBoundary, botYBoundary, maxChildsPerNode, toleranceEpsilon, mainNode));
					nodes.push(new RTNode(topXBoundary, topYBoundary, botXBoundary, botYBoundary, maxChildsPerNode, toleranceEpsilon, mainNode));
					nodes[1].leafs = tempLeafArr;
					nodes[0].leafs.push(new RTLeaf(obj, this, topX, topY, botX, botY));
					return;
				}
				else { //otherwise, we are going to split this node with childs each reflecting an even part of this node
					var curX:Float = topXBoundary;
					var curY:Float = topYBoundary;
					var deltaDivider:Int = Std.int(Math.sqrt(maxChildsPerNode));
					var nodeDeltaX:Float = deltaX / deltaDivider;
					var nodeDeltaY:Float = deltaY / deltaDivider;
					var nodeBotX:Float;
					var nodeBotY:Float;
					for (i in 0...deltaDivider) {
						//set the bottom x coord, make sure that the last one is exactly the same as this node's bottom coord
						nodeBotX = curX + nodeDeltaX;
						if (i == deltaDivider - 1) nodeBotX = botXBoundary;
						for (i in 0...deltaDivider) {
							//set the bottom y coord, make sure that the last one is exactly the same as this node's bottom coord
							nodeBotY = curY + nodeDeltaY;
							if (i == deltaDivider - 1) nodeBotY = botYBoundary;
							//push the new node to the list
							nodes.push(new RTNode(curX, curY, nodeBotX, nodeBotY, maxChildsPerNode, toleranceEpsilon, mainNode));
							curY += nodeDeltaY; //increment next Y
						}
						curX += nodeDeltaX; //increment next X
						curY = topYBoundary; //reset Y
					}
					
					//move leafs to the new nodes
					for (i in 0...tempLeafArr.length) {
						insertObj(tempLeafArr[i].getObj(), tempLeafArr[i].topX, tempLeafArr[i].topY, tempLeafArr[i].botX, tempLeafArr[i].botY);
					}
					tempLeafArr = null;
					
					//after creating new nodes and moving leafs, re-insert obj for this node and return
					insertObj(obj, topX, topY, botX, botY);
					return;
				}
			}
		}
	}
	
	//adds more nodes to around this node (happens only if this is the main node and it has infinite boundaries), this is the only case where we ignore the maximum amount of childs
	private inline function expandAroundThisNode():Void
	{
		var oldTopX:Float = Math.POSITIVE_INFINITY;
		var oldTopY:Float = Math.POSITIVE_INFINITY;
		var oldBotX:Float = Math.NEGATIVE_INFINITY;
		var oldBotY:Float = Math.NEGATIVE_INFINITY;
		for (i in 0...nodes.length) { //retrieve the current boundaries of our "infinite" main node
			if ((nodes[i].topXBoundary < oldTopX)) oldTopX = nodes[i].topXBoundary;
			if ((nodes[i].topYBoundary < oldTopY)) oldTopY = nodes[i].topYBoundary;
			if ((nodes[i].botXBoundary > oldBotX)) oldBotX = nodes[i].botXBoundary;
			if ((nodes[i].botYBoundary > oldBotY)) oldBotY = nodes[i].botYBoundary;
		}
		//we'll treat the above boundaries as our new center node, we're going to add 8 new nodes with the same size around it
		var nodeWidth:Float = oldBotX - oldTopX;
		var nodeHeight:Float = oldBotY - oldTopY;
		nodes.push(new RTNode(oldTopX - nodeWidth, oldTopY - nodeHeight, oldTopX, oldTopY, maxChildsPerNode, toleranceEpsilon, mainNode)); //top left
		nodes.push(new RTNode(oldTopX, oldTopY - nodeHeight, oldBotX, oldTopY, maxChildsPerNode, toleranceEpsilon, mainNode)); //top
		nodes.push(new RTNode(oldBotX, oldTopY - nodeHeight, oldBotX + nodeWidth, oldTopY, maxChildsPerNode, toleranceEpsilon, mainNode)); //top right
		nodes.push(new RTNode(oldBotX, oldTopY, oldBotX + nodeWidth, oldBotY, maxChildsPerNode, toleranceEpsilon, mainNode)); //right
		nodes.push(new RTNode(oldBotX, oldBotY, oldBotX + nodeWidth, oldBotY + nodeHeight, maxChildsPerNode, toleranceEpsilon, mainNode)); //bottom right
		nodes.push(new RTNode(oldTopX, oldBotY, oldBotX, oldBotY + nodeHeight, maxChildsPerNode, toleranceEpsilon, mainNode)); //bottom
		nodes.push(new RTNode(oldTopX - nodeWidth, oldBotY, oldTopX, oldBotY + nodeHeight, maxChildsPerNode, toleranceEpsilon, mainNode)); //bottom left
		nodes.push(new RTNode(oldTopX - nodeWidth, oldTopY, oldTopX, oldBotY, maxChildsPerNode, toleranceEpsilon, mainNode)); //left
	}
	
	//returns all Ts in an array which are located at the given position or null when no results were found
	public function getObjectsFromPosition(topX:Float, topY:Float, ?overlapX:Float = 0, ?overlapY:Float = 0):Array<T>
	{
		//check if our point is within this node's boundaries
		if ((topX >= topXBoundary) && (topY >= topYBoundary) && (topX - overlapX <= botXBoundary) && (topY - overlapY <= botYBoundary)) {
			
			//initialize the array we're going to return
			var returnArr:Array<T> = new Array<T>();
			
			//if this node has leafs, check if they are what we are looking for
			if (leafs.length > 0) {
				for (i in 0...leafs.length) { //loop every leaf
					if ((topX >= leafs[i].topX) && (topY >= leafs[i].topY) && (topX <= leafs[i].botX) && (topY <= leafs[i].botY)) { //check if this leaf exists at our position
						returnArr.push(leafs[i].getObj()); //put the leaf's object (T) in our list
					}
				}
			}
			else if (nodes.length > 0) { //otherwise, if this node has childs, check if they got what we are looking for too
				for (i in 0...nodes.length) { //loop every node (we need to check them all in case of overlapping leafs)
					var nodeArr:Array<T> = nodes[i].getObjectsFromPosition(topX, topY, overlapX, overlapY); //get the Ts we are interested in
					if ((nodeArr != null) && (nodeArr.length > 0)) returnArr = returnArr.concat(nodeArr); //if we found some, add them to our current list
				}
			}
			if (returnArr.length > 0) return returnArr; //return our results if applicable
		}
		return null; //no results, return null
	}
	
	//returns all Ts in an array which are located within the given range or null when no results were found
	public function getObjectsFromRange(topX:Float, topY:Float, botX:Float, botY:Float, ?overlapX:Float = 0, ?overlapY:Float = 0):Array<T>
	{
		//check if our range intersects with this node
		if (topX - overlapX <= botXBoundary && botX >= topXBoundary && topY - overlapY <= botYBoundary && botY >= topYBoundary) {
			//initialize the array we're going to return
			var returnArr:Array<T> = new Array<T>();
			
			//if this node has leafs, check if they are what we are looking for
			if (leafs.length > 0) {
				for (i in 0...leafs.length) { //loop every leaf
					if ((leafs[i].botX >= topX) && (leafs[i].botY >= topY) && (leafs[i].topX <= botX) && (leafs[i].topY <= botY)) { //check if this object resides within our field
						returnArr.push(leafs[i].getObj()); //put the leaf's object (T) in our list
					}
				}
			}
			else if (nodes.length > 0) { //otherwise, if this node has childs, check if they got what we are looking for too
				for (i in 0...nodes.length) { //loop every node (we need to check them all in case of overlapping leafs)
					var nodeArr:Array<T> = nodes[i].getObjectsFromRange(topX, topY, botX, botY, overlapX, overlapY); //get the Ts we are interested in
					if ((nodeArr != null) && (nodeArr.length > 0)) returnArr = returnArr.concat(nodeArr); //if we found some, add them to our current list
				}
			}
			if (returnArr.length > 0) return returnArr; //return our results if applicable
		}
		return null; //no results, return null
	}
	
	//returns all leafs with object T in an array which are located at the given position or null when no results were found
	public function getLeafsFromPosition(topX:Float, topY:Float, ?overlapX:Float = 0, ?overlapY:Float = 0):Array<RTLeaf<T>>
	{
		//check if our point is within this node's boundaries
		if ((topX >= topXBoundary) && (topY >= topYBoundary) && (topX - overlapX <= botXBoundary) && (topY - overlapY <= botYBoundary)) {
			
			//initialize the array we're going to return
			var returnArr:Array<RTLeaf<T>> = new Array<RTLeaf<T>>();
			
			//if this node has leafs, check if they are what we are looking for
			if (leafs.length > 0) {
				for (i in 0...leafs.length) { //loop every leaf
					if ((topX >= leafs[i].topX) && (topY >= leafs[i].topY) && (topX <= leafs[i].botX) && (topY <= leafs[i].botY)) { //check if this leaf exists at our position
						returnArr.push(leafs[i]); //put the leaf in our list
					}
				}
			}
			else if (nodes.length > 0) { //otherwise, if this node has childs, check if they got what we are looking for too
				for (i in 0...nodes.length) { //loop every node (we need to check them all in case of overlapping leafs)
					var nodeArr:Array<RTLeaf<T>> = nodes[i].getLeafsFromPosition(topX, topY, overlapX, overlapY); //get the leafs we are interested in
					if ((nodeArr != null) && (nodeArr.length > 0)) returnArr = returnArr.concat(nodeArr); //if we found some, add them to our current list
				}
			}
			if (returnArr.length > 0) return returnArr; //return our results if applicable
		}
		return null; //no results, return null
	}
	
	//returns all leafs containing T in an array which are located within the given range or null when no results were found
	public function getLeafsFromRange(topX:Float, topY:Float, botX:Float, botY:Float, ?overlapX:Float = 0, ?overlapY:Float = 0):Array<RTLeaf<T>>
	{
		//check if our range intersects with this node
		if (topX - overlapX <= botXBoundary && botX >= topXBoundary && topY - overlapY <= botYBoundary && botY >= topYBoundary) {
			//initialize the array we're going to return
			var returnArr:Array<RTLeaf<T>> = new Array<RTLeaf<T>>();
			
			//if this node has leafs, check if they are what we are looking for
			if (leafs.length > 0) {
				for (i in 0...leafs.length) { //loop every leaf
					if ((leafs[i].botX >= topX) && (leafs[i].botY >= topY) && (leafs[i].topX <= botX) && (leafs[i].topY <= botY)) { //check if this object resides within our field
						returnArr.push(leafs[i]); //put the leaf in our list
					}
				}
			}
			else if (nodes.length > 0) { //otherwise, if this node has childs, check if they got what we are looking for too
				for (i in 0...nodes.length) { //loop every node (we need to check them all in case of overlapping leafs)
					var nodeArr:Array<RTLeaf<T>> = nodes[i].getLeafsFromRange(topX, topY, botX, botY, overlapX, overlapY); //get the Ts we are interested in
					if ((nodeArr != null) && (nodeArr.length > 0)) returnArr = returnArr.concat(nodeArr); //if we found some, add them to our current list
				}
			}
			if (returnArr.length > 0) return returnArr; //return our results if applicable
		}
		return null; //no results, return null
	}
	
	//returns the leaf corresponding to the given object
	private function getObjLeaf(obj:T, objTopX:Float, objTopY:Float):RTLeaf<T>
	{
		//get all leafs at this position
		var leafArr:Array<RTLeaf<T>> = mainNode.getLeafsFromPosition(objTopX, objTopY);
		
		//return the matched leaf
		for (i in 0...leafArr.length) {
			if (leafArr[i].getObj() == obj) return leafArr[i];
		}
		return null;
	}
	
	//updates the leaf of the given object
	public function updateObject(obj:T, objTopX:Float, objTopY:Float, ?newTopX:Float, ?newTopY:Float, ?newBotX:Float, ?newBotY:Float)
	{
		var leaf:RTLeaf<T> = getObjLeaf(obj, objTopX, objTopY);
		if (leaf != null) updateLeaf(leaf, newTopX, newTopY, newBotX, newBotY);
	}

	public function deleteObject(obj:T, objTopX:Float, objTopY:Float):Void{
		var leaf:RTLeaf<T> = getObjLeaf(obj, objTopX, objTopY);
		if (leaf != null) deleteLeaf(leaf);
	}

	public function deleteLeaf(leaf:RTLeaf<T>):Void{
		leaf.parentNode.leafs.remove(leaf);
	}
	
	//updates the data of the given leaf
	public function updateLeaf(leaf:RTLeaf<T>, ?topX:Float, ?topY, ?botX, ?botY):Void
	{
		//update new leaf data
		if (topX != null) leaf.topX = topX;
		if (topY != null) leaf.topY = topY;
		if (botX != null) leaf.botX = botX;
		if (botY != null) leaf.botY = botY;
		
		//if leaf is now outide it's parent's proportions
		if ((leaf.topX < leaf.parentNode.topXBoundary) || (leaf.topY < leaf.parentNode.topYBoundary) || (leaf.botX > leaf.parentNode.botXBoundary) || (leaf.botY > leaf.parentNode.botYBoundary)) {
			//save leaf data
			var leafTopX:Float = leaf.topX;
			var leafTopY:Float = leaf.topY;
			var leafBotX:Float = leaf.botX;
			var leafBotY:Float = leaf.botY;
			var leafObj:T = leaf.getObj();
			//remove old leaf
			leaf.parentNode.leafs.remove(leaf);
			//insert new object
			mainNode.insertObj(leafObj, leafTopX, leafTopY, leafBotX, leafBotY);
		}
	}
	
	//creates a custom node, should only be used during initialization when using infinite boundaries for the main node
	public function addCustomNode(topX:Float, topY:Float, botX:Float, botY:Float):Void
	{
		nodes.push(new RTNode(topX, topY, botX, botY, maxChildsPerNode, toleranceEpsilon, mainNode));
	}
}