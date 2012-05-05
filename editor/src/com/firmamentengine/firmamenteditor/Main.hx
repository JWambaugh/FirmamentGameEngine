package com.firmamentengine.firmamenteditor;

import com.firmamentengine.firmamenteditor.ui.ProjectSettings;
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
	  
	    var project = new Project();
		var projectEditor = new ProjectSettings(project);
		stage.addChild(projectEditor);
		FDialog.alert("Welcome to the Firmament Editor!\nThis is still a work in progress, so please bear with us!","Welcome to Firmament");
		
   }
}