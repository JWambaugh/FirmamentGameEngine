package com.firmamentengine.firmamenteditor;

import com.firmamentengine.firmamenteditor.ui.EntitySelector;
import com.firmamentengine.firmamenteditor.ui.EntityWindow;
import com.firmamentengine.firmamenteditor.ui.ToolBar;
import com.firmamentengine.firmamenteditor.ui.ProjectSettings;
import firmament.core.FCamera;
import firmament.core.FEntity;
import firmament.core.FGame;
import firmament.core.FEntity;
import firmament.core.FVector;
import nme.display.StageAlign;
import nme.display.StageScaleMode;
import nme.Lib;
import nme.Assets;
import firmament.component.physics.FPhysicsComponentInterface;

import nme.events.Event;
import nme.events.MouseEvent;
import firmament.ui.FDialog;
import firmament.ui.FStyle;
import nme.display.StageQuality;
import firmament.core.FInput;
import firmament.core.FBox2DWorld;

/**
 * ...
 * @author Jordan Wambaugh
 */
using StringTools;
using firmament.utils.FEntityCompat;
class FirmamentEditor
{
	
	public static var camera:FCamera;
	public static var projectEditor:ProjectSettings;
	public static var game:FGame;
	public static var entitySelector:EntitySelector;
	public static var toolBar:ToolBar;
	public static var entityWindow:EntityWindow;

	public static var dragEnt:FEntity;
	public static var cwd:String;
	public static var dragOffset:FVector;
    public static function main()
    {
	    #if (flash9 || flash10)
		haxe.Log.trace = function(v,?pos) { untyped __global__["trace"](pos.className+"#"+pos.methodName+"("+pos.lineNumber+"):",v); }
		#elseif flash
		haxe.Log.trace = function(v,?pos) { flash.Lib.trace(pos.className+"#"+pos.methodName+"("+pos.lineNumber+"): "+v); }
		#end

		var executableDir:String = Sys.executablePath();
		trace(executableDir);
		executableDir=executableDir.replace("\\","/");
		var arr:Array<String>=executableDir.split('/');
		arr.pop();
		executableDir = arr.join("/");
		//Sys.setCwd(executableDir);
		//set styles

		cwd = Sys.getCwd();
		//temporarily changeworking directory while we load our font
		Sys.setCwd(executableDir);
	
		var font = Assets.getFont ("assets/fonts/Ubuntu-R.ttf");
		FStyle.setStyleObj("",{
			fontName:font.fontName
			,fontHeightMultiplier:1
			,fontHeightAdd:5
					
		});
	   	
		var stage = Lib.current.stage;
		stage.align = StageAlign.TOP_LEFT;
		stage.scaleMode = StageScaleMode.NO_SCALE;
		stage.quality = StageQuality.BEST;
		camera = new FCamera(stage.stageWidth,stage.stageHeight);
		camera.setDebugMode(true);
		game  = FGame.getInstance();
		
		game.enableSimulation = false;
		game.addCamera("main",camera);
		stage.addChild(camera);
		
		toolBar = new ToolBar();
		stage.addChild(toolBar);
	  
	    
		projectEditor = new ProjectSettings();
		projectEditor.y = 60;
		stage.addChild(projectEditor);
		FDialog.alert("Welcome to the Firmament Editor!\nThis is still a work in progress, so please bear with us!","Welcome to Firmament");
		
		
		entityWindow = new EntityWindow();
		entityWindow.x = 650;
		stage.addChild(entityWindow);
		
		projectEditor.addEventListener(ProjectSettings.PROJECT_READY, function(e:Event) {
			if(entitySelector == null){
				entitySelector = new EntitySelector(projectEditor.getEntityDir());
				entitySelector.y = 350;
				stage.addChild(entitySelector);
			}
		});
		projectEditor.autoLoad();
		
		//enable auto resize
		stage.addEventListener(Event.RESIZE, function(e:Event) { camera.resizeToStage(); } );
		trace(stage.stageWidth);
		
		camera.addEventListener(MouseEvent.MOUSE_DOWN, function(e:MouseEvent) { 
			var point:FVector = camera.getWorldPosition(e.localX, e.localY);
			var ents = FGame.getInstance().getEntitiesAtPoint(point);
			if (ents.length > 0) {
				ents.sort(function(a:FEntity,b:FEntity):Int{
					var cmp = cast(b.getComponent("physics"),FPhysicsComponentInterface).getZPosition() - cast(a.getComponent("physics"),FPhysicsComponentInterface).getZPosition();
					if (cmp==0) {
						return 0;	
					} else if (cmp > 0) return 1;
					return -1;
				});
				dragEnt = cast(ents[0], FEntity);
				entityWindow.setEntity(cast(ents[0]));
				point.subtract(dragEnt.getPosition());
				dragOffset = point;
			}
		} );
		
		camera.addEventListener(MouseEvent.MOUSE_MOVE, function(e:MouseEvent) { 
			if (dragEnt == null) return;
			var point = camera.getWorldPosition(e.localX, e.localY);
			point.subtract(dragOffset);
			dragEnt.setPosition(point);
			stage.dispatchEvent(new Event('entityMove'));
		});
		camera.addEventListener(MouseEvent.MOUSE_UP, function(e:MouseEvent) { 
			dragEnt = null;
		});
		
		
		var input = new FInput(stage);
		
		game.addEventListener(FGame.BEFORE_STEP, function(e:Event) {
			
			//trace(input.getStageX());
			
			if (input.isKeyPressed(38)) {
				camera.setPosition(new FVector(camera.getPositionX(),camera.getPositionY()-.2));
			}
			if (input.isKeyPressed(40)) {
				camera.setPosition(new FVector(camera.getPositionX(),camera.getPositionY()+.2));
			}
			if (input.isKeyPressed(37)) {
				camera.setPosition(new FVector(camera.getPositionX()-.2,camera.getPositionY()));
			}
			if (input.isKeyPressed(39)) {
				camera.setPosition(new FVector(camera.getPositionX()+.2,camera.getPositionY()));
			}
			if (input.isKeyPressed(270)) {
				camera.setZoom(camera.getZoom() * 1.02);
			}
			if (input.isKeyPressed(269)) {
				camera.setZoom(camera.getZoom() * .98);
			}
			
		} );
		
		Sys.setCwd(cwd);
		//FDialog.prompt("Howdy! please put somthing in here.", function(s) { } ,"Please enter your name","jordan");
    }
}
