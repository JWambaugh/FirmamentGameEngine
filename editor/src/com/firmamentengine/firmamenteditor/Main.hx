package com.firmamentengine.firmamenteditor;

import com.firmamentengine.firmamenteditor.ui.ProjectSettings;
import nme.display.StageAlign;
import nme.display.StageScaleMode;
import nme.Lib;

import nme.events.Event;
import nme.events.MouseEvent;

/**
 * ...
 * @author Jordan Wambaugh
 */

class Main 
{
	


   public static function main()
   {
		var stage = Lib.current.stage;
		stage.align = StageAlign.TOP_LEFT;
		stage.scaleMode = StageScaleMode.NO_SCALE;
	  
	    var project = new Project();
		var projectEditor = new ProjectSettings(project);
		stage.addChild(projectEditor);
   }
}