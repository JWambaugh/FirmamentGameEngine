package com.firmamentengine.firmamenteditor.ui;
import firmament.ui.FWindow;
import firmament.ui.layout.FHBox;
import flash.display.Sprite;
import sys.FileSystem;
import firmament.ui.FDialog;
import sys.io.File;
import firmament.util.loader.FDataLoader;
/**
 * ...
 * @author Jordan Wambaugh
 */

class EntitySelector extends FWindow
{

	var ents:Array<Dynamic>;
	var c:Sprite;
	var layout:FHBox;
	public function new(entityDir:String) 
	{
		super(false);
		ents = new Array<Dynamic>();
		c = new Sprite();
		layout = new FHBox();

		this.loadEntities(entityDir);
		
		
		c.addChild(layout);
		
		this.setTitle("Entities");
		//canvas.addChild(new FHBox());
		this.setCanvas(c);
	}
	
	function loadEntities(entityDir:String) {
		var exeDir = Sys.getCwd();
		Sys.setCwd(FirmamentEditor.cwd);
		var files = FileSystem.readDirectory(entityDir);
		for (file in files) {
			if(FileSystem.isDirectory(entityDir + "/" + file)){
				loadEntities(entityDir + "/" + file);
				continue;
			}
			if(file.indexOf(".json")<0)continue;
			try{
				
				var config = FDataLoader.loadData(entityDir + "/" + file);
				ents.push(config);
				layout.addChild(new EntityItem(file,entityDir, config));
			}catch (e:Dynamic) {
				FDialog.alert("Error loading entity file " + entityDir + "/" + file);
				firmament.util.FLog.debug("######### "+e);
			}
			
		}
		Sys.setCwd(exeDir);
	}
	
}
