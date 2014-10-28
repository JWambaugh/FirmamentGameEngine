package firmament.tilesheet;

import firmament.tilesheet.FTilesheet;
import firmament.util.loader.FDataLoader;
import flash.display.BitmapData;
import flash.geom.Rectangle;
import flash.geom.Point;
import firmament.tilesheet.packer.FTilesheetPacker;
import firmament.core.FConfig;
#if(cpp||neko)
import firmament.util.ResourceLoader;
#end

typedef SpriteTilesheet = {
	var tilesheetId:Int;
	var tileId:Int;
};

/**
 * ...
 * @author jordan wambaugh
 */
class FTilesheetManager {
	
	
	static var _instance:FTilesheetManager;
	var idCounter:Int;
	var tilesheets:Map<Int,FTilesheet>;
	var _orderedTilesheets:Array<FTilesheet>;

	//tracks which tilesheet an asset is in
	var tilesheetMap:Map<String,SpriteTilesheet>;

	var tilesheetAutoQueue:Array<String>;

	private function new () {
		idCounter = 0;
		tilesheets = new Map<Int,FTilesheet>();
		_orderedTilesheets = new Array<FTilesheet>();
		tilesheetMap = new Map();
		tilesheetAutoQueue = new Array();
		
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

	public function findTilesheetWithKey(fileName:String){
		for(tilesheet in this.tilesheets){
			if(tilesheet.getDefinitionFileName() == fileName){
				return tilesheet;
			}
		}
		return null;
	}

	public function getTilesheetFromDefinitionFile(fileName:String){
		var t = findTilesheetWithKey(fileName);
		if(t!=null) return t;

		//didn't find one
		var data = FDataLoader.loadData(fileName);
		t = createTilesheet(data);
		t.setDefinitionFileName(fileName);
		return t;
	}

	public function addTileSheet(tilesheet:FTilesheet){
		this.tilesheets.set(tilesheet.getId(),tilesheet);
	}

	

	public function createTilesheet(config:Dynamic){
		var image = config.image;
		var bitmap:BitmapData = null;
		var imageIsFileName = false;
		var t:FTilesheet = null;                                  
		var packer:FTilesheetPacker = null;
		var c:FConfig = config;
		if (Std.is(image,String) && image != ''){
			bitmap = loadImage(image);
		}
		else if(Std.is(image,BitmapData)){
			bitmap = cast(image,BitmapData);
		}
		
		
		if(bitmap != null){
			t = new FTilesheet(bitmap);
			if(imageIsFileName)t.setImageFileName(image);
		}else{
			//if bitmap is null, assume we are building our tilesheet
			packer = new FTilesheetPacker( c.get("width",Int,1024) , c.get("height",Int,1024) , c.get("padding",Int,1));
		}
		

		var entries:Array<Dynamic> = new Array();

		if(Std.is(config.tiles,Array)) {
			for(tile in cast(config.tiles,Array<Dynamic>)){
				var rect:Rectangle = null;
				var center:Dynamic = null;
				var path:String = null;
				if(Reflect.isObject(tile.center)){
					center = tile.center;
				}
				var label:String = null;
				if(Std.is(tile.label,String))label = tile.label;

				if(Reflect.isObject(tile.topLeft) && Std.is(tile.width,Float) && Std.is(tile.height,Float)){
					//tile definition defines place in tilesheet image
					rect = new Rectangle (tile.topLeft.x, tile.topLeft.y, tile.width, tile.height);
					if(center == null){
						center = {};
						center.x = Math.floor(( tile.width)/2);
						center.y = Math.floor((tile.height)/2);
					}
					
				
				
				}else if(Std.is(tile.fileName,String) && packer != null){
					//tile definition defines filename, build tilesheet dynamically
					var img = loadImage(tile.fileName);
					path = tile.fileName;
			
					rect = packer.addBitmapData(img,label);
					if(label == null)label = tile.fileName;
					if(center == null){
						center = {};
						center.x = Math.floor(( img.width)/2);
						center.y = Math.floor((img.height)/2);
					}
				}
				entries.push({
					rect: rect
					,center: new Point(center.x,center.y)
					,label: label
					,path: path
				});
			}
		}

		//support an 'includeAll option that includes all images in a asset folder'
		var search = c.get("includeAll",String,null);
		if( search  != null){
			//trace('includAll found!');
			var mainList:Array<String> = openfl.Assets.list(IMAGE);
			var matchList:Array<String> = new Array<String>();
			for(fileName in mainList){
				if(fileName.indexOf(search) != -1){
					//trace("adding "+fileName);
					var p = new haxe.io.Path(fileName);
					var img:BitmapData = loadImage(fileName);
					entries.push({
						rect: packer.addBitmapData(img,p.file)
						,center: new Point(Math.floor((img.width)/2),Math.floor((img.height)/2))
						,label: p.file
						,path: fileName
					});
				}
			}
		}

		if(packer != null){
			bitmap = packer.getBitmapData();
			t = new FTilesheet(bitmap);
		}

		for(entry in entries){
				var tileId = t.addTileRectWithLabel(entry.rect,entry.center,entry.label);
				if(entry.path != null){
					tilesheetMap.set(entry.path,{
						tilesheetId: t.getId()
						,tileId: tileId
					});
				}
			}
		return t;

	}
	
	
	public function addToTilesheetMap(path, tilesheetId, tileId){
		tilesheetMap.set(path,{
			tilesheetId: tilesheetId
			,tileId: tileId
		});
	}
	
	
	private function loadImage(fileName:String){
		var img:BitmapData = openfl.Assets.getBitmapData(fileName);

		#if(cpp||neko)
		if(img==null){
			img = BitmapData.load(fileName);
		}
		#end
		return img;
	}


	//////////automatic tilesheet system

	public function getTilesheetForPath(path:String){
		return tilesheetMap.get(path);
	}

	public function queueTilesheetForPath(path:String){
		tilesheetAutoQueue.push(path);
	}

	public function getTilesheetForQueuedPath(path:String){
		//check to see if it's already been generated
		var data = getTilesheetForPath(path);
		if(data!=null) return data;
		var maxTilesheetNum = 10;
		while(tilesheetAutoQueue.length>0 && maxTilesheetNum-- > 0){
			//not already generated, so process queue into tilesheets
			trace("Creating a new tilesheet!");
			var packer = new FTilesheetPacker(2048,2048);
			while(tilesheetAutoQueue.length > 0){
				var fileName = tilesheetAutoQueue[0];
				try{
					var p = new haxe.io.Path(fileName);
					packer.addBitmapData(loadImage(fileName), p.file, fileName);
					tilesheetAutoQueue.shift();
				}catch(e:Dynamic){
					trace("Error auto generating tilesheet for "+ fileName+" Perhaps current tilesheet is full? Will try another");
					break;
				}
			}
			var tilesheet = packer.getTilesheet();
		}
		return getTilesheetForPath(path);
	}
	

}
