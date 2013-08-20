package firmament.core;

import firmament.core.FTilesheet;
import firmament.util.loader.FDataLoader;
import flash.display.BitmapData;
import flash.geom.Rectangle;
import flash.geom.Point;
#if(cpp||neko)
import com.firmamentengine.firmamenteditor.ResourceLoader;
#end

/**
 * ...
 * @author jordan wambaugh
 */
class FTilesheetManager {
	
	
	static var _instance:FTilesheetManager;
	var idCounter:Int;
	var tilesheets:Map<Int,FTilesheet>;
	var _orderedTilesheets:Array<FTilesheet>;

	private function new () {
		idCounter = 0;
		tilesheets = new Map<Int,FTilesheet>();
		_orderedTilesheets = new Array<FTilesheet>();
		
	}
	
	public static function getInstance(){
		if (_instance == null) {
				_instance = new FTilesheetManager();
		}
		return _instance;
	}

	public function genTilesheetId(){
		return this.idCounter++;
	}


	public function getTilesheetWithId(id:Int){
		return tilesheets.get(id);
	}

	public function getTilesheetFromDefinitionFile(fileName:String){
		for(tilesheet in this.tilesheets){
			if(tilesheet.getDefinitionFileName() == fileName){
				return tilesheet;
			}
		}
		//didn't find one
		var data = FDataLoader.loadData(fileName);
		var t = createTilesheet(data);
		t.setDefinitionFileName(fileName);
		return t;
	}

	public function addTileSheet(tilesheet:FTilesheet){
		this.tilesheets.set(tilesheet.getId(),tilesheet);
	}

	public function getOrderedTilesheets():Array<FTilesheet>{
		if(idCounter > _orderedTilesheets.length){
			//trace("building ordered tilesheet list");
			_orderedTilesheets = new Array<FTilesheet>();
			for(tilesheet in tilesheets){
				_orderedTilesheets.push(tilesheet);
			}
			this._orderedTilesheets.sort(function(a:FTilesheet,b:FTilesheet):Int{
				var cmp = a.getRenderPriority()- b.getRenderPriority();
				if (cmp==0) {
					return 0;	
				} else if (cmp > 0) return 1;
				return -1;
			});
		}
		return _orderedTilesheets;
	}


	public function createTilesheet(config:Dynamic){
		var image = config.image;
		var bitmap:BitmapData;
		var imageIsFileName = false;
		if (Std.is(image,String) && image != ''){
			
			bitmap = openfl.Assets.getBitmapData(image);
			
			#if(cpp||neko)
			if(bitmap==null){
				bitmap = BitmapData.load(image);
			}
			#end
		}
		else if(Std.is(image,BitmapData)){
			bitmap = cast(image,BitmapData);
		}
		else {
			throw "image property is not a file name";
		}
		if(bitmap == null){
			throw "Error loading bitmap";
		}

		var t = new FTilesheet(bitmap);
		if(imageIsFileName)t.setImageFileName(image);

		if(Std.is(config.renderPriority,Float)){
			t.setRenderPriority(config.renderPriority);
		}
		//trace("Render priority: "+t.getRenderPriority());

		if(Std.is(config.tiles,Array)) {
			for(tile in cast(config.tiles,Array<Dynamic>)){
				if(Reflect.isObject(tile.topLeft) && Std.is(tile.width,Float) && Std.is(tile.height,Float)){
					var center:Dynamic = {};
					if(Reflect.isObject(tile.center)){
						center = tile.center;
					}else{
						center.x = Math.floor(( tile.width)/2);
						center.y = Math.floor((tile.height)/2);
					}
					var label:String = null;
					if(Std.is(tile.label,String))label = tile.label;
					//flash is off by a bit for some reason... hack to make it work.
					#if(flash)
					t.addTileRectWithLabel(new Rectangle (tile.topLeft.x+.2, tile.topLeft.y+.2, tile.width, tile.height)
						,new Point(center.x,center.y),label);
					#else
					t.addTileRectWithLabel(new Rectangle (tile.topLeft.x, tile.topLeft.y, tile.width, tile.height)
						,new Point(center.x,center.y),label);
					#end
				}else{
					throw "Found a tile that doesn't have a topLeft and/or height and width";
				}
			}
		}else {
			//no tile definition! assume whole image is single tile
			trace("No tile definition");
			t.addTileRect(new Rectangle (0, 0, bitmap.width, bitmap.height),new Point(bitmap.width/2,bitmap.height/2));
		}
		return t;

	}
	
	
	
	
	
	

}
