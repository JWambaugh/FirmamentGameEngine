package com.firmamentengine.firmamenteditor.ui;

import com.firmamentengine.firmamenteditor.ui.ConfigEditorField;
import firmament.ui.FLineEdit;
import com.firmamentengine.firmamenteditor.ui.ConfigEditorFieldEvent;
import nme.events.Event;
class ConfigEditorStringField extends ConfigEditorField{


	
	var _field:FLineEdit;
	public function new(){
		super();

	}

	override public function draw(){
		if(_field != null){
			_field.text = _value;
		}else{
			_field = new FLineEdit(_value);
			_field.addEventListener(Event.CHANGE, function(e:Event) {
				trace(this.getPath());
				_editor.dispatchEvent(new ConfigEditorFieldEvent(this.getPath(),_field.text)); } );
			this.addChild(_field);
		}
	}


}