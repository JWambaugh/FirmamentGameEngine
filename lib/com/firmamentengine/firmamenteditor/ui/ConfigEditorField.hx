package com.firmamentengine.firmamenteditor.ui;



import firmament.ui.FWidget;

import com.firmamentengine.firmamenteditor.ui.ConfigEditorObjectField;
import com.firmamentengine.firmamenteditor.ui.ConfigEditorStringField;



class ConfigEditorField extends FWidget{
	var _value:Dynamic;
	var _key:String;
	var _parent:ConfigEditorField;
	var _type:String;


	public static function getEditorField(key:String,value:Dynamic,?parent:ConfigEditorField=null){
		
		var field:ConfigEditorField = switch(getType(value)){
			case "string":
				new ConfigEditorStringField();
			case "object":
				new ConfigEditorObjectField();

		}
		field.setValue(key,value,parent);
		return field;
	}

	public function new(){
		super();

	}

	public function setValue(key:String,value:Dynamic,?parent:ConfigEditorField=null){
		_value = value;
		_key = key;
		_parent = parent;
		if(_type == null) getType(value);
		draw();
	}

	private static function getType(value:Dynamic){
		var type:String=null;
		if(Std.is(value,String))type = 'string';
		else if(Std.is(value,Array))type = 'array';

		return type;
	}

	public function draw(){}
	public function getKey(){
		return _key;
	}

	public function getValue(){
		return _value;
	}


}