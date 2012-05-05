package com.firmamentengine.firmamenteditor.ui;
import firmament.ui.FTextLabel;
import firmament.ui.layout.FHBox;
import firmament.ui.layout.FVBox;
import firmament.core.FCamera;
import firmament.core.FPhysicsEntity;
import nme.display.Bitmap;
import nme.display.BitmapData;
import nme.display.Loader;
import nme.display.Sprite;
import nme.events.IOErrorEvent;
import nme.geom.Point;
import nme.net.URLRequest;
import nme.events.Event;
import firmament.ui.FDialog;
import sys.io.File;
import nme.utils.ByteArray;
import nme.events.MouseEvent;
import com.firmamentengine.firmamenteditor.Main;
import nme.Lib;
/**
 * ...
 * @author Jordan Wambaugh
 */

class EntityItem extends Sprite
{

	var n:FTextLabel;
	var layout:FVBox;
	var startX:Float;
	var startY:Float;
	var config:Dynamic;
	var sprite:BitmapData;
	public function new(fileName:String,dir:String,config:Dynamic) 
	{
		super();
		this.config = config;
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
			this.sprite = cast(loader.content,Bitmap).bitmapData;
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
		
		
		this.addEventListener(MouseEvent.MOUSE_DOWN, function(e:MouseEvent) { 
				this.startDrag();
				this.startX = this.x;
				this.startY = this.y;
		} );
		
		this.addEventListener(MouseEvent.MOUSE_UP, function(e:MouseEvent) { 
			var stage = Lib.current.stage;
			this.stopDrag();
			this.x = this.startX;
			this.y = this.startY;
			var obs = stage.getObjectsUnderPoint(new Point(e.stageX, e.stageY));
			var ob = obs[0];
			if (Std.is(ob, FCamera)&& obs.length==1) {
				var world = Main.world;
				var config = Reflect.copy(this.config);
				config.sprite = this.sprite;
				config.position = Main.camera.getWorldPosition(e.stageX,e.stageY);
				var ent = new FPhysicsEntity(world, config);
			}
			
		} );
		
	}
	
}