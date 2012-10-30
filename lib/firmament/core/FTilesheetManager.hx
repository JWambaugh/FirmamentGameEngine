package firmament.core;

import firmament.core.FTilesheet;
import firmament.utils.loader.FDataLoader;
import nme.display.BitmapData;
import nme.geom.Rectangle;
import nme.geom.Point;
/**
 * ...
 * @author jordan wambaugh
 */
class FTilesheetManager {
	
	
	static var _instance:FTilesheetManager;
	var idCounter:Int;
	var tilesheets:IntHash<FTilesheet>;

	private function new () {
		idCounter = 0;
		tilesheets = new IntHash<FTilesheet>();
		
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

	public function getTilesheetFromDifinitionFile(fileName:String){
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


	public function createTilesheet(config:Dynamic){
		var image = config.image;
		var bitmap:BitmapData;
		var imageIsFileName = false;
		if (Std.is(image,String) && image != ''){
			bitmap = nme.Assets.getBitmapData(image);
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
		if(Std.is(config.tiles,Array)) {
			for(tile in cast(config.tiles,Array<Dynamic>)){
				if(Reflect.isObject(tile.topLeft) && Reflect.isObject(tile.bottomRight)){
					var center:Dynamic = {};
					if(Reflect.isObject(tile.center)){
						center = tile.center;
					}else{
						center.x = Math.floor((tile.bottomRight.x - tile.topLeft.x)/2);
						center.y = Math.floor((tile.bottomRight.y - tile.topLeft.y)/2);
					}
					t.addTileRect(new Rectangle (tile.topLeft.x, tile.topLeft.y, tile.bottomRight.x, tile.bottomRight.y)
						,new Point(center.x,center.y));
				}else{
					throw "Found a tile that doesn't have a topLeft and/or bottomRight!";
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
