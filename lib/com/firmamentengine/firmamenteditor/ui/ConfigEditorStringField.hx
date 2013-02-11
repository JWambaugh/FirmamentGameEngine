package com.firmamentengine.firmamenteditor.ui;

import com.firmamentengine.firmamenteditor.ui.ConfigEditorField;
import firmament.ui.FTextField;

class ConfigEditorStringField extends ConfigEditorField{


	
	var _field:FTextField;
	public function new(){
		super();
		trace('INITED');

	}

	override public function draw(){
		_field = new FTextField(_value);
		this.addChild(_field);
	}

}