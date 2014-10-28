package com.firmamentengine.firmamenteditor.ui;
import com.firmamentengine.firmamenteditor.FEditorEntity;
import firmament.core.FVector;
import firmament.ui.FButton;
import firmament.ui.FFloatEntry;
import firmament.ui.FLineEdit;
import firmament.ui.FTextLabel;
import firmament.ui.FWindow;
import firmament.ui.FSmallButton;
import firmament.ui.layout.FHBox;
import firmament.ui.layout.FVBox;
import flash.display.Sprite;
import flash.events.MouseEvent;
import flash.events.Event;
import flash.Lib;
import  com.firmamentengine.firmamenteditor.ui.ConfigEditor;
import  com.firmamentengine.firmamenteditor.ui.ConfigEditorFieldEvent;
import firmament.util.FMisc;
/**
 * ...
 * @author Jordan Wambaugh
 */
using firmament.util.FEntityCompat;
class EntityWindow extends FWindow
{

	var selectedEntity:FEditorEntity;
	var rotationEdit:FFloatEntry;
	var positionXEdit:FFloatEntry;
	var positionYEdit:FFloatEntry;
	var entName:FTextLabel;
	var _configEditor:ConfigEditor;

	public function new() 
	{
		super(false);
		this.setTitle("Entity");
		_configEditor = new ConfigEditor();
		_configEditor.setConfig({
			
		});

		var layout = new FVBox([
			entName = new FTextLabel("(No Entity Selected")
			,new FButton("Delete", 0, 0, deleteEntity)
			,_configEditor
			
		]);
		
		/*
		rotationEdit.addEventListener(FFloatEntry.VALUE_CHANGED, function(e:Event) { 
			if(this.selectedEntity!=null)
				this.selectedEntity.setAngle(rotationEdit.getValue()*0.0174532925);
		} );
		*/
		_configEditor.addEventListener(ConfigEditorFieldEvent.FIELD_CHANGED, function(e:ConfigEditorFieldEvent) { 
			if(this.selectedEntity!=null){
				if(e.getPath() == '/components/physics/position/y'){
					this.selectedEntity.setPosition(new FVector(this.selectedEntity.getPositionY(),e.getValue()));
				}
				else if(e.getPath() == '/components/physics/position/x'){
					this.selectedEntity.setPosition(new FVector( this.selectedEntity.getPositionX(),e.getValue()));
				}else{
					FMisc.setObjectValue(e.getPath(),this.selectedEntity._modifications,e.getValue());
				}
			}
		} );
		
		/*
		positionYEdit.addEventListener(FFloatEntry.VALUE_CHANGED, function(e:Event) { 
			if(this.selectedEntity!=null)
				this.selectedEntity.setPosition(new FVector( this.selectedEntity.getPositionX() , positionYEdit.getValue()));
		} );*/
		
		
		var stage = Lib.current.stage;
		stage.addEventListener("entityMove", function(e:Event) {
			try{
				_configEditor.setValue(['components','physics','position','x'],selectedEntity.getPositionX());
				_configEditor.setValue(['components','physics','position','y'],selectedEntity.getPositionY());
			}catch(error:String){
				trace(error);
			}
		} );
		
		this.setCanvas(layout);
	}
	
	public function setEntity(e:FEditorEntity) {
		this.selectedEntity = e;
		var name = e.getFileName();
		var p = name.split("/");
		name = p[p.length - 1];
		name = name.split(".")[0];
		entName.text = name;
		
		
		_configEditor.setConfig(e.getConfig());
	}
	
	public function deleteEntity(e:MouseEvent) {
		if (this.selectedEntity == null) return;
		this.selectedEntity.delete();
		this.selectedEntity = null;
		
	}


	
	
}