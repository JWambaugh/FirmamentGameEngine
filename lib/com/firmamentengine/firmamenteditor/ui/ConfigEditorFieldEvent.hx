package com.firmamentengine.firmamenteditor.ui;



import nme.events.Event;


class ConfigEditorFieldEvent extends Event{

	var _value:Dynamic;
	var _path:String;
	public static inline var FIELD_CHANGED_PREFIX = 'fieldChanged_';
	public function new(path:String,value:Dynamic){
		_value = value;
		_path = path;

		super(FIELD_CHANGED_PREFIX+path);
	}

	public function getValue(){
		return _value;
	}

	public function getPath(){
		return _path;
	}


}


