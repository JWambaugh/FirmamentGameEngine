package firmament.tilesheet.packer;

import flash.display.BitmapData;
import firmament.tilesheet.packer.FPackerNode;
import firmament.core.FRectangle;
import firmament.tilesheet.FTilesheet;
import flash.geom.Rectangle;

typedef TilesheetEntry={
	var rect:Rectangle;
	var label:String;
};

class FTilesheetPacker{

	private var _root:FPackerNode;
	private var _bitmap:BitmapData;
	private var _padding:Int;
	private var _entries:Array<TilesheetEntry>;

	public function new(width:Int, height:Int, padding:Int = 1){
		_bitmap = new BitmapData(width, height, true, 0x00FFFFFF);
		_root = new FPackerNode();
		_root.rect = new FRectangle(0.0, 0.0, width, height);
		_padding = padding;
		_entries = new Array();
	}

	
	public function addBitmapData(img:BitmapData, label:String):Rectangle{
		var node = _root.insert(img,_padding);
		if(node == null){
			throw "Error adding image '"+label+"' to tilesheet. Out of room?";
		}
		_bitmap.copyPixels(img, img.rect.clone(),new flash.geom.Point(node.rect.left+_padding,node.rect.top+_padding),null,null,true);
		node.label = label;
		var entry:TilesheetEntry = {
			rect: new Rectangle(node.rect.left+_padding,node.rect.top+_padding,img.width,img.height)
			,label:label
		}
		_entries.push(entry);
		return entry.rect;
	}

	public function getBitmapData():BitmapData{
		return _bitmap;
	}

	public function getTilesheet():FTilesheet{
		var t = new FTilesheet(_bitmap);
		for(entry in _entries){
			t.addTileRectWithLabel(entry.rect, new flash.geom.Point(entry.rect.width/2, entry.rect.height/2), entry.label);
		}
		return t;
	}
}