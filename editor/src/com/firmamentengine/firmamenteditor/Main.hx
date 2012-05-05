package com.firmamentengine.firmamenteditor;

import com.firmamentengine.firmamenteditor.ui.EntitySelector;
import com.firmamentengine.firmamenteditor.ui.ProjectSettings;
import firmament.core.FCamera;
import firmament.core.FEntity;
import firmament.core.FGame;
import firmament.core.FPhysicsWorld;
import firmament.core.FVector;
import nme.display.StageAlign;
import nme.display.StageScaleMode;
import nme.Lib;

import nme.events.Event;
import nme.events.MouseEvent;
import firmament.ui.FDialog;

/**
 * ...
 * @author Jordan Wambaugh
 */

class Main 
{
	
	public static var world;
	public static var camera;
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
		var game  = new FGame();
		world = new FPhysicsWorld(new FVector(0,0));
		game.addWorld(world);
		game.addCamera(camera);
		stage.addChild(camera);
		
	  
	    var project = new Project();
		var projectEditor = new ProjectSettings(project);
		stage.addChild(projectEditor);
		FDialog.alert("Welcome to the Firmament Editor!\nThis is still a work in progress, so please bear with us!","Welcome to Firmament");
		
		projectEditor.addEventListener(ProjectSettings.PROJECT_READY, function(e:Event) {
			var entitySelector = new EntitySelector(projectEditor.getEntityDir());
			stage.addChild(entitySelector);
		});
		projectEditor.autoLoad();
		
		//enable auto resize
		stage.addEventListener(Event.RESIZE, function(e:Event) { camera.resizeToStage(); } );
		trace(stage.stageWidth);
		
   }
}