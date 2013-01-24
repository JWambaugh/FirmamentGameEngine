package com.firmamentengine.firmamenteditor.ui;
import firmament.ui.FWindow;
import firmament.ui.layout.FHBox;
import nme.display.Sprite;
import sys.FileSystem;
import firmament.util.loader.serializer.FJsonSerializer;
import firmament.ui.FDialog;
import sys.io.File;

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
		var serializer = new FJsonSerializer();
		for (file in files) {
			if(file.indexOf(".json")<0)continue;
			try{
				var str = File.getContent(entityDir + "/" + file);
				var config = serializer.unserialize(str);
				ents.push(config);
				layout.addChild(new EntityItem(file,entityDir, config));
			}catch (e:Dynamic) {
				FDialog.alert("Error loading entity file " + entityDir + "/" + file);
				trace("######### "+e);
			}
			
		}
		Sys.setCwd(exeDir);
	}
	
}
