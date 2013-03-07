package com.firmamentengine.firmamenteditor.ui;
import com.firmamentengine.firmamenteditor.ui.ConfigEditor;



import firmament.ui.FWidget;

import com.firmamentengine.firmamenteditor.ui.ConfigEditorObjectField;
import com.firmamentengine.firmamenteditor.ui.ConfigEditorStringField;
import com.firmamentengine.firmamenteditor.ui.ConfigEditorArrayField;



class ConfigEditorField extends FWidget{
	var _value:Dynamic;
	var _key:String;
	var _parent:ConfigEditorField;
	var _type:String;
	var _editor:ConfigEditor;


	public static function getEditorField(key:String,value:Dynamic,editor:ConfigEditor,?parent:ConfigEditorField=null){
		
		var field:ConfigEditorField = switch(getType(value)){
			case "string":
				new ConfigEditorStringField();
			case "int":
				new ConfigEditorStringField();
			case "float":
				new ConfigEditorStringField();
			case "object":
				new ConfigEditorObjectField();
			case "array":
				new ConfigEditorArrayField();
			default:
				throw "Invalid type:"+getType(value);

		}
		
		field.setValue(key,value,editor,parent);
		
		return field;
	}

	public function new(){
		super();

	}

	public function setValue(key:String,value:Dynamic,editor:ConfigEditor,?parent:ConfigEditorField=null){
		_value = value;
		_key = key;
		_parent = parent;
		_editor = editor;
		if(_type == null) getType(value);
		draw();
	}

	public function updateValue(value:Dynamic){
		_value = value;
		draw();
	}

	private static function getType(value:Dynamic){
		var type:String=null;
		if(Std.is(value,String))type = 'string';
		else if(Std.is(value,Array))type = 'array';
		else if(Reflect.isObject(value)) type ='object';
		else if(Std.is(value,Int)) type = 'int';
		else if(Std.is(value,Float)) type = 'float';
		else type = 'string';
		return type;
	}

	public function draw(){}

	public function getPath(){
		var path:String = null;
		if(_parent!=null)
			path = _parent.getPath();
		if(path == null)path ='';
		if(_key!=null)
			return path+'/'+_key;
		else return "";
	}
	public function getKey(){
		return _key;
	}

	public function getValue(){
		return _value;
	}


}