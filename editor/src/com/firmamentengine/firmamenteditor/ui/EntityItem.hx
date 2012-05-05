package com.firmamentengine.firmamenteditor.ui;
import firmament.ui.FTextLabel;
import firmament.ui.layout.FHBox;
import firmament.ui.layout.FVBox;
import nme.display.Loader;
import nme.display.Sprite;
import nme.events.IOErrorEvent;
import nme.net.URLRequest;
import nme.events.Event;
import firmament.ui.FDialog;
import sys.io.File;
import nme.utils.ByteArray;
/**
 * ...
 * @author Jordan Wambaugh
 */

class EntityItem extends Sprite
{

	var n:FTextLabel;
	var layout:FVBox;
	public function new(fileName:String,dir:String,config:Dynamic) 
	{
		super();
		
		var entName = fileName.split(".")[0];
		layout = new FVBox();
		var loader = new Loader();
		
		var data = File.getBytes(config.sprite);
		
		loader.contentLoaderInfo.addEventListener(IOErrorEvent.IO_ERROR, function(e:IOErrorEvent) { 
			FDialog.alert("error"+e.toString());
		});
		loader.contentLoaderInfo.addEventListener(Event.COMPLETE, function(e:Event) { 
			var scaleFactor = 75 / loader.content.height;
			loader.content.scaleX = scaleFactor;
			loader.content.scaleY = scaleFactor;
			
		} );
		
		//copy from haxe bytes to ByteArray. Apparently we cant cast in cpp
		var bytes = new ByteArray();
		for (x in 0... data.length) {
			bytes.writeByte(data.get(x));
		}
		loader.loadBytes(bytes);
		n=new FTextLabel(entName);
		layout.addChild(loader);
		layout.addChild(n);
		this.addChild(layout);
	}
	
}