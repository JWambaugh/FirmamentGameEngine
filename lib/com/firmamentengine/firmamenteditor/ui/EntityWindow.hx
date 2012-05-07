package com.firmamentengine.firmamenteditor.ui;
import com.firmamentengine.firmamenteditor.FEditorEntity;
import firmament.ui.FButton;
import firmament.ui.FFloatEntry;
import firmament.ui.FLineEdit;
import firmament.ui.FTextLabel;
import firmament.ui.FWindow;
import firmament.ui.FSmallButton;
import firmament.ui.layout.FHBox;
import firmament.ui.layout.FVBox;
import nme.display.Sprite;
import nme.events.MouseEvent;
import nme.events.Event;

/**
 * ...
 * @author Jordan Wambaugh
 */

class EntityWindow extends FWindow
{

	var selectedEntity:FEditorEntity;
	var rotationEdit:FFloatEntry;
	var entName:FTextLabel;
	public function new() 
	{
		super(false);
		this.setTitle("Entity");
		var layout = new FVBox([
			entName = new FTextLabel("(No Entity Selected")
			,new FHBox([
				new FTextLabel("Rotation:")
				,rotationEdit = new FFloatEntry(0.0,0.1)
			])
		
		]);
		
		rotationEdit.addEventListener(FFloatEntry.VALUE_CHANGED, function(e:Event) { 
			this.selectedEntity.setAngle(rotationEdit.getValue());
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
		
		rotationEdit.setValue(e.getAngle());
	}
	
	
}