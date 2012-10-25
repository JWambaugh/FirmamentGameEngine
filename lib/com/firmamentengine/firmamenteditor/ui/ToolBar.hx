package com.firmamentengine.firmamenteditor.ui;

import firmament.ui.FButton;
import firmament.ui.FWindow;
import firmament.ui.layout.FHBox;
import firmament.ui.layout.FLayout;
import nme.display.Sprite;
import nme.events.MouseEvent;
import sys.FileSystem;
import firmament.utils.loader.serializer.FJsonSerializer;
import firmament.ui.FDialog;
import com.firmamentengine.firmamenteditor.FirmamentEditor;
import firmament.utils.loader.FEntityLoader;
import com.firmamentengine.firmamenteditor.FEditorEntity;
import sys.io.File;
/**
 * ...
 * @author Jordan Wambaugh
 */
using StringTools;
class ToolBar extends FWindow
{

	var layout:FLayout;
	var lastFileName:String;
	public function new() 
	{
		super(false);
		this.setTitle('map');
		this.layout = new FHBox([
			new FButton("Save", 0, 0, save)
			,new FButton("Load",0,0,load)
		]);
		this.setCanvas(layout);
	}
	
	private function save(e:MouseEvent) {
		FDialog.prompt("Please enter the name of the map you wish to save.", function(fileName) { 
			lastFileName = fileName;
			//get all entities
			var ents = FirmamentEditor.world.getAllEntities();
			
			var entC = [];
			for (ent in ents) {
				entC.push(cast(ent, FEditorEntity).getMapConfig());
			}
			var c = {
				entities:entC
				};
			trace(c);
			var serializer = new FJsonSerializer();
			var data:String = serializer.serialize(c).replace("\\/","/");
			trace(data);
			File.saveContent(FirmamentEditor.projectEditor.getMapDir() + "/" +fileName, data);
		},"Save Map", lastFileName);
		
	}
	
	
	private function load(e:MouseEvent) {
		FDialog.prompt("Please enter the name of the map you wish to load.", function(fileName) { 
			lastFileName = fileName;
			var path = FirmamentEditor.projectEditor.getMapDir() + "/" + fileName;
			//FDialog.alert(path);
			
			FEntityLoader.getInstance().loadMap(path, "com.firmamentengine.firmamenteditor.FEditorEntity");
		},"Load Map",lastFileName );
	}
	
	
	
	
}