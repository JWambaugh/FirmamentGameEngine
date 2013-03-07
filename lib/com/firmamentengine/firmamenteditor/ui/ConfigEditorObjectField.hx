package com.firmamentengine.firmamenteditor.ui;

import com.firmamentengine.firmamenteditor.ui.ConfigEditorField;
import firmament.ui.layout.FHBox;
import firmament.ui.layout.FVBox;
import firmament.ui.FTextLabel;

class ConfigEditorObjectField extends ConfigEditorField{


	
	var _children:Array<ConfigEditorField>;
	public function new(){
		super();
		_children = new Array();

	}

	override public function draw(){
		var vbox = new FVBox();
		
		for(field in Reflect.fields(_value)){
			var hbox = new FHBox();
			var label = new FTextLabel(field+':');
			hbox.addChild(label);
			var value = ConfigEditorField.getEditorField(field,Reflect.field(_value,field),_editor,this);
			_children.push(value);
			if(Std.is(value,ConfigEditorObjectField)){
				vbox.addChild(hbox);
				var ihb = new FHBox();
				ihb.addChildren([
					new FTextLabel("  ")
					,value
				]); 
				vbox.addChild(ihb);
			}else{
				hbox.addChild(value);
				vbox.addChild(hbox);
			}
			
		}
		this.addChild(vbox);
	}

	override public function getValue(){
		var ob:Dynamic = {};
		for(child in _children){
			Reflect.setField(ob,child.getKey(),child.getValue());
		}
		return ob;
	}

	public function getChildren(){
		return _children;
	}




}





