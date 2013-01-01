package com.firmamentengine.firmamenteditor.ui;

import firmament.ui.FButton;
import firmament.ui.FWindow;
import firmament.ui.layout.FHBox;
import firmament.ui.layout.FLayout;
import nme.display.Sprite;
import nme.events.MouseEvent;
import sys.FileSystem;
import firmament.util.loader.serializer.FJsonSerializer;
import firmament.ui.FDialog;
import com.firmamentengine.firmamenteditor.FirmamentEditor;
import firmament.util.loader.FEntityLoader;
import com.firmamentengine.firmamenteditor.FEditorEntity;
import sys.io.File;
import firmament.core.FGame;
/**
 * ...
 * @author Jordan Wambaugh
 */
using StringTools;
class ToolBar extends FWindow
{

	var layout:FLayout;
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
			FirmamentEditor.projectEditor.setLastOpenedMap(fileName);
			//get all entities
			var ents = FGame.getInstance().getAllEntities();
			
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
		},"Save Map", FirmamentEditor.projectEditor.getLastOpenedMap());
		
	}
	
	
	private function load(e:MouseEvent) {
		FDialog.prompt("Please enter the name of the map you wish to load.", function(fileName) { 
			this.loadMap(fileName);
		},"Load Map", FirmamentEditor.projectEditor.getLastOpenedMap() );
	}


	public function loadMap(fileName:String){
		FirmamentEditor.projectEditor.setLastOpenedMap(fileName);
		var path = FirmamentEditor.projectEditor.getMapDir() + "/" + fileName;
		//FDialog.alert(path);
		FGame.getInstance().clearWorlds();
		FEntityLoader.getInstance().loadMap(path, "com.firmamentengine.firmamenteditor.FEditorEntity");
	}
	
	
	
	
}