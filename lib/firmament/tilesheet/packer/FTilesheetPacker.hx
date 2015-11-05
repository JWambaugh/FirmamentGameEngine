package firmament.tilesheet.packer;

import flash.display.BitmapData;
import firmament.tilesheet.packer.FPackerNode;
import firmament.core.FRectangle;
import firmament.tilesheet.FTilesheet;
import firmament.tilesheet.FTilesheetManager;
import flash.geom.Rectangle;

typedef TilesheetEntry={
	var rect:Rectangle;
	var label:String;
	var path:String;
};

class FTilesheetPacker{

	private var _root:FPackerNode;
	private var _bitmap:BitmapData;
	private var _padding:Int;
	private var _entries:Array<TilesheetEntry>;
	private var _tilesheet:FTilesheet = null;
	private var _stats:firmament.util.FStatistics;

	public function new(width:Int, height:Int, padding:Int = 1){
		_bitmap = new BitmapData(width, height, true, 0x00FFFFFF);
		_root = new FPackerNode();
		_root.rect = new FRectangle(0.0, 0.0, width, height);
		_padding = padding;
		_entries = new Array();

		_stats = firmament.util.FStatistics.getInstance();
		if( !_stats.hasProperty('BitmapData') ) {
			_stats.registerProp('BitmapData','Int');
			_stats.setProp('BitmapData',0);
		}
	}

	
	public function addBitmapData(img:BitmapData, label:String, path:String = null):Rectangle{
		_stats.setProp('BitmapData',_stats.getProp('BitmapData')+1);
		var node = _root.insert(img,_padding);
		if(node == null){
			throw "Error adding image '"+label+"' to tilesheet. Out of room?";
		}
		_bitmap.copyPixels(img, img.rect.clone(),new flash.geom.Point(node.rect.left+_padding,node.rect.top+_padding),null,null,true);
		node.label = label;
		var entry:TilesheetEntry = {
			rect: new Rectangle(node.rect.left+_padding,node.rect.top+_padding,img.width,img.height)
			,label:label
			,path:path
		}
		_entries.push(entry);
		return entry.rect;
	}

	public function getBitmapData():BitmapData{
		return _bitmap;
	}

	public function getTilesheet():FTilesheet{
		if(_tilesheet != null) return _tilesheet;
		var tm = FTilesheetManager.getInstance();
		var t = new FTilesheet(_bitmap);
		for(entry in _entries){
			var tileId = t.addTileRectWithLabel(entry.rect, new flash.geom.Point(entry.rect.width/2, entry.rect.height/2), entry.label);
			//if we have a path add it to our map of paths to tilesheets
			if(entry.path != null){
				tm.addToTilesheetMap(entry.path, t.getId(), tileId);
			}
		}
		_tilesheet = t;
		return t;
	}
}