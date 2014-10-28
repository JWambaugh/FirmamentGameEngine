package firmament.util;
import flash.display.Loader;
import flash.display.Sprite;
import flash.events.IOErrorEvent;
import flash.geom.Point;

import flash.events.Event;
import firmament.ui.FDialog;
import sys.io.File;
import flash.utils.ByteArray;
import flash.display.BitmapData;
import flash.display.Bitmap;
/**
 * ...
 * @author Jordan Wambaugh
 * This is deprecated. Use BitmapData.load() instead.
 */

class ResourceLoader 
{
	static var bitmapCache:Map<String,BitmapData>;
	public function new() 
	{
		
	}
	
	private static function init() {
		if (bitmapCache == null) {
			bitmapCache = new Map<String,BitmapData>();
		}
	}
	
	public static function loadImage(fileName:String):BitmapData {
		init();
		var bitmap:BitmapData;
		if ((bitmap = bitmapCache.get(fileName))!=null) {
			return bitmap;
		}
		var loader = new Loader();
		
		var data = File.getBytes(fileName);
		
		loader.contentLoaderInfo.addEventListener(IOErrorEvent.IO_ERROR, function(e:IOErrorEvent) { 
			FDialog.alert("error"+e.toString());
		});
		loader.contentLoaderInfo.addEventListener(Event.COMPLETE, function(e:Event) { 
			bitmap = cast(loader.content, Bitmap).bitmapData;
			bitmapCache.set(fileName , bitmap);
		} );
		
		//copy from haxe bytes to ByteArray. Apparently we cant cast in cpp
		var bytes = new ByteArray();
		for (x in 0... data.length) {
			bytes.writeByte(data.get(x));
		}
		loader.loadBytes(bytes);
		return bitmap;
	}
	
}