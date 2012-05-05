package com.firmamentengine.firmamenteditor.ui;
import com.firmamentengine.firmamenteditor.Project;
import firmament.ui.FButton;
import firmament.ui.layout.FHBox;
import firmament.ui.layout.FVBox;
import nme.display.Sprite;
import firmament.ui.FTextLabel;
import firmament.ui.FLineEdit;
import firmament.ui.FWindow;
import nme.events.MouseEvent;

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
		

		canvas.addChild(new FVBox([
			new FHBox([new FTextLabel("Project File:"), projectFileTxt = new FLineEdit()])
			,new FHBox([new FTextLabel("Base Dir:",0,30), baseDirTxt = new FLineEdit("", 75,30)])
			,new FHBox([new FTextLabel("Entity Dir:",0,60), entityDirTxt = new FLineEdit("",75,60)])
			,new FHBox([new FTextLabel("Map Dir:",0,90), mapDirTxt = new FLineEdit("",75,90)])
			,new FHBox([new FButton("Load Settings",0,120,save),new FButton("Save Settings",100,120,load)])
	]));
		
		
		this.setCanvas(canvas);
	}
	
	function load(e:MouseEvent) {
	}
	
	function save(e:MouseEvent) {
	}
	
	
}