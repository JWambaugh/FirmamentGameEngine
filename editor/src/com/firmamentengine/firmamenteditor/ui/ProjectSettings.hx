package com.firmamentengine.firmamenteditor.ui;
import com.firmamentengine.firmamenteditor.Project;
import firmament.ui.FButton;
import nme.display.Sprite;
import firmament.ui.FTextLabel;
import firmament.ui.FLineEdit;
import firmament.ui.FWindow;

/**
 * ...
 * @author Jordan Wambaugh
 */

class ProjectSettings extends FWindow
{
	var baseDirTxt:FLineEdit;
	var entityDirTxt:FLineEdit;
	var mapDirTxt:FLineEdit;
	var projectFileTxt:FLineEdit;
	var project:Project;
	public function new(project:Project) 
	{
		super();
		
		var canvas = new Sprite();
		
		this.setTitle("Project Settings");
		this.project = project;
		
		canvas.addChild(new FTextLabel("Project File:"));
		
		projectFileTxt = new FLineEdit("", 75);
		canvas.addChild(projectFileTxt);
		
		canvas.addChild(new FTextLabel("Base Dir:",0,30));
		
		baseDirTxt = new FLineEdit("", 75,30);
		canvas.addChild(baseDirTxt);
		
		canvas.addChild(new FTextLabel("Entity Dir:",0,60));
		entityDirTxt = new FLineEdit("",75,60);
		canvas.addChild(entityDirTxt);
		
		canvas.addChild(new FTextLabel("Map Dir:",0,90));
		mapDirTxt = new FLineEdit("",75,90);
		canvas.addChild(mapDirTxt);
		
		
		var saveButton = new FButton("Load Settings",0,120);
		canvas.addChild(saveButton);
		
		var loadButton = new FButton("Save Settings",100,120);
		canvas.addChild(loadButton);
		
		
		this.setCanvas(canvas);
	}
	
}