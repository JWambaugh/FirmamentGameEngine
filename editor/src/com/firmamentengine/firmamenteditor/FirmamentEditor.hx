package com.firmamentengine.firmamenteditor;

import com.firmamentengine.firmamenteditor.ui.EntitySelector;
import com.firmamentengine.firmamenteditor.ui.ToolBar;
import com.firmamentengine.firmamenteditor.ui.ProjectSettings;
import firmament.core.FCamera;
import firmament.core.FEntity;
import firmament.core.FGame;
import firmament.core.FPhysicsWorld;
import firmament.core.FPhysicsEntity;
import firmament.core.FVector;
import nme.display.StageAlign;
import nme.display.StageScaleMode;
import nme.Lib;

import nme.events.Event;
import nme.events.MouseEvent;
import firmament.ui.FDialog;
import firmament.core.FInput;

/**
 * ...
 * @author Jordan Wambaugh
 */

class FirmamentEditor
{
	
	public static var world:FPhysicsWorld;
	public static var camera:FCamera;
	public static var projectEditor:ProjectSettings;
	public static var game:FGame;
	public static var entitySelector:EntitySelector;
	public static var toolBar:ToolBar;
	private static var dragEnt:FEntity;
	
    public static function main()
    {
	    #if (flash9 || flash10)
		haxe.Log.trace = function(v,?pos) { untyped __global__["trace"](pos.className+"#"+pos.methodName+"("+pos.lineNumber+"):",v); }
		#elseif flash
		haxe.Log.trace = function(v,?pos) { flash.Lib.trace(pos.className+"#"+pos.methodName+"("+pos.lineNumber+"): "+v); }
		#end
	   
		var stage = Lib.current.stage;
		stage.align = StageAlign.TOP_LEFT;
		stage.scaleMode = StageScaleMode.NO_SCALE;
		
		camera = new FCamera(stage.stageWidth,stage.stageHeight);
		game  = new FGame();
		game.enableSimulation = false;
		world = new FPhysicsWorld(new FVector(0,0));
		game.addWorld(world);
		game.addCamera(camera);
		stage.addChild(camera);
		
		toolBar = new ToolBar();
		stage.addChild(toolBar);
	  
	    
		projectEditor = new ProjectSettings();
		projectEditor.y = 60;
		stage.addChild(projectEditor);
		FDialog.alert("Welcome to the Firmament Editor!\nThis is still a work in progress, so please bear with us!","Welcome to Firmament");
		
		projectEditor.addEventListener(ProjectSettings.PROJECT_READY, function(e:Event) {
			if(entitySelector == null){
				entitySelector = new EntitySelector(projectEditor.getEntityDir());
				entitySelector.y = 400;
				stage.addChild(entitySelector);
			}
		});
		projectEditor.autoLoad();
		
		//enable auto resize
		stage.addEventListener(Event.RESIZE, function(e:Event) { camera.resizeToStage(); } );
		trace(stage.stageWidth);
		
		camera.addEventListener(MouseEvent.MOUSE_DOWN, function(e:MouseEvent) { 
			var ents = world.getEntitiesAtPoint(camera.getWorldPosition(e.localX, e.localY));
			if (ents.length > 0) {
				dragEnt = cast(ents[0], FPhysicsEntity);
			}
		} );
		
		camera.addEventListener(MouseEvent.MOUSE_MOVE, function(e:MouseEvent) { 
			if (dragEnt == null) return;
			dragEnt.setPosition(camera.getWorldPosition(e.localX, e.localY));
		});
		camera.addEventListener(MouseEvent.MOUSE_UP, function(e:MouseEvent) { 
			dragEnt = null;
		});
		
		
		var input = new FInput(stage);
		
		game.addEventListener(FGame.BEFORE_STEP, function(e:Event) {
			
			//trace(input.getStageX());
			
			if (input.isKeyPressed(38)) {
				camera.setPosition(new FVector(camera.getPositionX(),camera.getPositionY()-.5));
			}
			if (input.isKeyPressed(40)) {
				camera.setPosition(new FVector(camera.getPositionX(),camera.getPositionY()+.5));
			}
			if (input.isKeyPressed(37)) {
				camera.setPosition(new FVector(camera.getPositionX()-.5,camera.getPositionY()));
			}
			if (input.isKeyPressed(39)) {
				camera.setPosition(new FVector(camera.getPositionX()+.5,camera.getPositionY()));
			}
			if (input.isKeyPressed(65)) {
				camera.setZoom(camera.getZoom() * 1.02);
			}
			if (input.isKeyPressed(90)) {
				camera.setZoom(camera.getZoom() * .98);
			}
			
		} );
		
		//FDialog.prompt("Howdy! please put somthing in here.", function(s) { } ,"Please enter your name","jordan");
    }
}