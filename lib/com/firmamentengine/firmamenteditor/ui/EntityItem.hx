package com.firmamentengine.firmamenteditor.ui;
import com.firmamentengine.firmamenteditor.FEditorEntity;
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
import com.firmamentengine.firmamenteditor.FirmamentEditor;
import nme.Lib;
import com.firmamentengine.firmamenteditor.ResourceLoader;
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
	var image:Sprite;
	var filePath:String;
	public function new(fileName:String,dir:String,config:Dynamic) 
	{
		super();
		this.filePath = dir+"/"+fileName;
		this.config = config;
		var entName = fileName.split(".")[0];
		layout = new FVBox();
		
		var bitmap = new Bitmap(ResourceLoader.loadImage(config.sprite));
		
		image = new Sprite();
		var scaleFactor = 75 / bitmap.height;
		bitmap.scaleX = scaleFactor;
		bitmap.scaleY = scaleFactor;
		this.sprite = bitmap.bitmapData;
		image.addChild(bitmap);
		n=new FTextLabel(entName);
		layout.addChild(image);
		layout.addChild(n);
		this.addChild(layout);
		
		
		this.addEventListener(MouseEvent.MOUSE_DOWN, function(e:MouseEvent) { 
				this.image.startDrag();
				this.startX = this.image.x;
				this.startY = this.image.y;
		} );
		
		this.addEventListener(MouseEvent.MOUSE_UP, function(e:MouseEvent) { 
			var stage = Lib.current.stage;
			this.image.stopDrag();
			this.image.x = this.startX;
			this.image.y = this.startY;
			var obs = stage.getObjectsUnderPoint(new Point(e.stageX, e.stageY));
			var ob = obs[0];
			if (Std.is(ob, FCamera)&& obs.length==1) {
				var world = FirmamentEditor.world;
				var config = Reflect.copy(this.config);
				config.sprite = this.sprite;
				config.position = FirmamentEditor.camera.getWorldPosition(e.stageX,e.stageY);
				var ent = new FEditorEntity(world, config);
				ent.setFileName(this.filePath);
			}
			
		} );
		
	}
	
}