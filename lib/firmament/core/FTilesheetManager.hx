package firmament.core;

import firmament.core.FTilesheet;
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


	public function getTilesheetFromDifinitionFile(fileName:String){
		for(tilesheet in this.tilesheets){
			if(tilesheet.getFileName() == fileName){
				return tilesheet;
			}
		}
		//didn't find one

	}


	public function createTilesheet(config:Dynamic){
		var image = config.image;
		var bitmap:BitmapData;
		if (Std.is(image,String) && image != ''){
			bitmap = nme.Assets.getBitmapData(image);
		}
		else if(Std.is(image,bitmapData)){
			bitmap = image;
		}
		else {
			throw "image property is not a file name";
		}
		if(bitmap == null){
			throw "Error loading bitmap";
		}

		var t = new FTilesheet(bitmap);

		if(Std.is(config.tiles,Array<Dynamic>)){
			for(tile in config.tiles){
				if(Reflect.isObject(tile.topLeft) && Reflect.isObject(tile.bottomRight)){
					var center={};
					if(Reflect.isObject(tile.center)){
						center = tile.center;
					}else{
						center.x = Math.floor((tile.bottomRight.x - tile.topLeft.x)/2);
						center.y = Math.floor(tile.bottomRight.y - tile.topLeft.y)/2);
					}
					t.addTileRect(new Rectangle (tile.topLeft.x, tile.topLeft.y, tile.bottomRight.x, tile.bottomRight.y)
						,new Point(center.x,center.y));
				}else{
					throw "Found a tile that doesn't have a topLeft and/or bottomRight!";
				}
			}
		}else {
			//no tile definition! assume whole image is single tile
			t.addTileRect(new Rectangle (0, 0, bd.width, bd.height),new Point(bd.width/2,bd.height/2));
		}

	}
	
	
	
	
	
	

}
