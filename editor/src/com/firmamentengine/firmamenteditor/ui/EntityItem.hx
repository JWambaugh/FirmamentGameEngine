package com.firmamentengine.firmamenteditor.ui;
import com.firmamentengine.firmamenteditor.FEditorEntity;
import com.firmamentengine.firmamenteditor.FirmamentEditor;
import com.firmamentengine.firmamenteditor.ResourceLoader;
import firmament.component.base.FEntityComponentFactory;
import firmament.component.render.FRenderComponentInterface;
import firmament.core.FCamera;
import firmament.core.FEntity;
import firmament.core.FEntityFactory;
import firmament.core.FVector;
import firmament.ui.FDialog;
import firmament.ui.FTextLabel;
import firmament.ui.layout.FHBox;
import firmament.ui.layout.FVBox;
import openfl.Assets;
import flash.display.Bitmap;
import flash.display.BitmapData;
import flash.display.Loader;
import flash.display.Sprite;
import flash.events.Event;
import flash.events.IOErrorEvent;
import flash.events.MouseEvent;
import flash.geom.Point;
import flash.Lib;
import flash.net.URLRequest;
import flash.utils.ByteArray;
import sys.FileSystem;
import sys.io.File;
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
	var dragging:Bool;
	public function new(fileName:String,dir:String,config:Dynamic) 
	{
		//trace("intityItem constructor");
		//trace("processing entity "+fileName);
		super();
		this.filePath = dir+"/"+fileName;
		this.config = config;
		var entName = fileName.split(".")[0];
		layout = new FVBox();
		this.dragging = false;
		var tempEntity:FEntity = new FEntity(config);
		if(config == null || config.components == null){
			throw "invalid entity config";
		}
		

		if(config.components.render == null){
			
			config.components.render={
				componentName:'tilesheet'
				,image:Assets.getBitmapData("assets/images/default-icon.png")

			};
			config._defaultImage = true;
		}


		var component = FEntityComponentFactory.createComponent(config.components.render.componentName);
		if(component == null)throw "error getting render component!";
		var renderComponent = cast(component,FRenderComponentInterface);
		component.setEntity(tempEntity);
		

		if(Reflect.isObject(config.components.animation)){
			var animationComponent = FEntityComponentFactory.createComponent(config.components.animation.componentName);
			animationComponent.setEntity(tempEntity);
			animationComponent.init(config.components.animation);
		}

		//init render component
		component.init(config.components.render);



		var bitmapData = renderComponent.getBitmapData();
		if(bitmapData == null)throw("bitmapData null");
		var bitmap = new Bitmap(bitmapData);
		
		image = new Sprite();
		var scaleFactor = 75 / bitmap.height;
		//if(bitmap.width > 75 && bitmap.width > bitmap.height)scaleFactor = 75/bitmap.width;
		
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
				this.dragging = true;
		} );
		
		this.addEventListener(MouseEvent.MOUSE_UP, function(e:MouseEvent) { 
			var stage = Lib.current.stage;
			this.image.stopDrag();
			this.image.x = this.startX;
			this.image.y = this.startY;
		} );
		
		this.addEventListener(MouseEvent.MOUSE_MOVE, function(e:MouseEvent) { 
			if (!dragging) return;
			var stage = Lib.current.stage;
			
			var obs = stage.getObjectsUnderPoint(new Point(e.stageX, e.stageY));
			var ob = obs[0];
			var overSelector:Bool = false;
			for (object in obs) {
				if (Std.is(object, EntitySelector)) overSelector = true;
			}
			if (Std.is(ob, FCamera)&& overSelector==false) {
				this.dragging = false;
				this.image.stopDrag();
				this.image.x = this.startX;
				this.image.y = this.startY;
				var config = Reflect.copy(this.config);
				config.components.render.tileSheetImage = this.sprite;
				config.components.physics.position = FirmamentEditor.camera.getWorldPosition(e.stageX,e.stageY);

				

				var ent = new FEditorEntity(config);
				FEntityFactory.applyComponents(ent,config);
				FEntityFactory.initComponents(ent,config);
				ent.setFileName(this.filePath);
				FirmamentEditor.entityWindow.setEntity(ent);
				FirmamentEditor.dragEnt = ent;
				FirmamentEditor.dragOffset = new FVector(0, 0);
			}
			
		} );
	}
	
}