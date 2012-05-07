package com.firmamentengine.firmamenteditor;
import nme.display.Loader;
import nme.display.Sprite;
import nme.events.IOErrorEvent;
import nme.geom.Point;

import nme.events.Event;
import firmament.ui.FDialog;
import sys.io.File;
import nme.utils.ByteArray;
import nme.display.BitmapData;
import nme.display.Bitmap;
/**
 * ...
 * @author Jordan Wambaugh
 */

class ResourceLoader 
{
	static var bitmapCache:Hash<BitmapData>;
	public function new() 
	{
		
	}
	
	private static function init() {
		if (bitmapCache == null) {
			bitmapCache = new Hash<BitmapData>();
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