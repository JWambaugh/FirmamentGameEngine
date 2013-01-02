package com.firmamentengine.firmamenteditor.ui;
import firmament.ui.FButton;
import firmament.ui.FScroller;
import firmament.ui.layout.FHBox;
import firmament.ui.layout.FVBox;
import nme.display.Sprite;
import firmament.ui.FTextLabel;
import firmament.ui.FLineEdit;
import firmament.ui.FWindow;
import nme.events.MouseEvent;

import firmament.ui.FDialog;
import sys.io.File;
import sys.FileSystem;
import firmament.util.loader.serializer.FJsonSerializer;
import nme.events.Event;

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
	var lastOpenedMap:String;
	
	
	public static inline var PROJECT_READY = "projectReady";
	public function new() 
	{
		//no close button
		super(false);
		
		
		
		
		var canvas = new Sprite();
		
		this.setTitle("Project Settings");

		

		canvas.addChild(new FVBox([
			new FHBox([new FTextLabel("Project File:"), projectFileTxt = new FLineEdit()])
			,new FHBox([new FTextLabel("Base Dir:",0,30), baseDirTxt = new FLineEdit("", 75,30)])
			,new FHBox([new FTextLabel("Entity Dir:",0,60), entityDirTxt = new FLineEdit("",75,60)])
			,new FHBox([new FTextLabel("Map Dir:",0,90), mapDirTxt = new FLineEdit("",75,90)])
			,new FHBox([new FButton("Load Settings",0,120,load),new FButton("Save Settings",100,120,save)])
		]));
		
		
		
		this.setCanvas(canvas);
		
		
	}
	public function autoLoad() {
		//autoload file if we are passed a project file
		var args = Sys.args();
		if (args[0] != null && args[0] != "") {
			this.projectFileTxt.text = args[0];
			this.load();
		}else{
			//if no project file specified, look for on in the current directory
			var files = FileSystem.readDirectory(FirmamentEditor.cwd);
			for (file in files) {
				if(file.indexOf(".fprj")>0){
					this.projectFileTxt.text = file;
					this.load();
					return;
				}

			}
		}
	}

	function load(?e:MouseEvent=null) {
		if (projectFileTxt.text == "") {
			FDialog.alert("Project file is blank!");
			return;
		}
		var data;

		try{
			var exeDir = Sys.getCwd();
			Sys.setCwd(FirmamentEditor.cwd);
			if(!FileSystem.exists(projectFileTxt.text)){
				throw "File doesn't exist";
			}

			data = File.getContent(projectFileTxt.text);
			Sys.setCwd(exeDir);
			var serializer = new FJsonSerializer();
			var settings = serializer.unserialize(data);
			this.entityDirTxt.text = settings.entityDir;
			this.mapDirTxt.text = settings.mapDir;
			this.baseDirTxt.text = settings.baseDir;
			this.lastOpenedMap = settings.lastOpenedMap;
		}catch(e:Dynamic){
			FDialog.alert("Error loading file " + projectFileTxt.text);
			trace(e);
			return;
		}
		
		this.dispatchEvent(new Event(PROJECT_READY));
		
	}
	
	function save(e:MouseEvent) {
		if (projectFileTxt.text == "") {
			FDialog.alert("Project file is blank!");
			return;
		}
		var serializer = new FJsonSerializer();
		
		var data:Dynamic={};
		
		data.entityDir = this.entityDirTxt.text;
		data.mapDir = this.mapDirTxt.text;
		data.baseDir = this.baseDirTxt.text;
		data.lastOpenedMap = this.lastOpenedMap;
		var str = serializer.serialize(data);
		trace(str);
		
		try{
			File.saveContent(projectFileTxt.text, str);
			
		}catch (e:Dynamic) {
			trace(e);
			FDialog.alert("Error saving file " + projectFileTxt.text);
			return;
		}
		this.dispatchEvent(new Event(PROJECT_READY));
	}
	
	public function getEntityDir() {
		return this.entityDirTxt.text;
	}
	
	public function getMapDir() {
		return this.mapDirTxt.text;
	}
	
	public function setLastOpenedMap(map:String){
		this.lastOpenedMap = map;
	}

	public function getLastOpenedMap():String{
		return this.lastOpenedMap;
	}
}