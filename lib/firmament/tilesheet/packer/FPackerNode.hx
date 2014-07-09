package firmament.tilesheet.packer;

import firmament.core.FRectangle;
import flash.display.BitmapData;

class FPackerNode {
	var childA:FPackerNode = null;
	var childB:FPackerNode = null;
	public var rect:FRectangle = null;
	public var label:String = null;

	public function new(){

	}

	public function insert(img:BitmapData, padding:Int):FPackerNode{
		if(!isLeaf()){
			//try inserting to A node
			var newNode = childA.insert(img,padding);
			if(newNode != null){
				return newNode;
			}
			//that fails, try b.
			return childB.insert(img,padding);


		}else{
			//if we have an image here, return
			if(label != null) {
				return null;
			}

			//see if image fits in rect
			if(!imageFits(img, padding)){
				return null;
			}

			//if image fits perfectly in this node, return this node
			if(imageExactFit(img, padding)){
				return this;
			}

			//image doesn't fit perfectly, split into children
			childA = new FPackerNode();
			childB = new FPackerNode();

			var dw = rect.width - img.width;
			var dh = rect.height - img.height;


			if(dw>dh){
				childA.rect = new FRectangle(rect.left, rect.top, rect.left + img.width+padding*2 , rect.bottom);
				childB.rect = new FRectangle(rect.left + img.width+padding*2, rect.top, rect.right, rect.bottom);
			}else{
				childA.rect = new FRectangle(rect.left, rect.top, rect.right, rect.top + img.height+padding*2);
				childB.rect = new FRectangle(rect.left, rect.top + img.height+padding*2, rect.right, rect.bottom);
			}
			return childA.insert(img,padding);
		}
	}

	public function isLeaf():Bool{
		if(childA != null) return false;
		if(childB != null) return false;
		return true;
	}

	private function imageFits(img:BitmapData, padding:Int):Bool{
		if(img.width+padding*2 > rect.width  || img.height+padding*2 > rect.height){
			return false;
		}
		return true;
	}

	private function imageExactFit(img:BitmapData, padding:Int):Bool{
		if(img.width+padding*2  == rect.width && img.height+padding*2 == rect.height){
			return true;
		}
		return false;
	}
}
