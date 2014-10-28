package com.firmamentengine.firmamenteditor.ui;



import flash.events.Event;


class ConfigEditorFieldEvent extends Event{

	var _value:Dynamic;
	var _path:String;
	public static inline var FIELD_CHANGED = 'fieldChanged';
	public function new(path:String,value:Dynamic){
		_value = value;
		_path = path;

		super(FIELD_CHANGED);
	}

	public function getValue(){
		return _value;
	}

	public function getPath(){
		return _path;
	}


}


