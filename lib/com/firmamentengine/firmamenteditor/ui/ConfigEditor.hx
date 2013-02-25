package com.firmamentengine.firmamenteditor.ui;
import firmament.ui.FWidget;
import com.firmamentengine.firmamenteditor.ui.ConfigEditorField;
import com.firmamentengine.firmamenteditor.ui.ConfigEditorStringField;
import firmament.util.FMisc;
import nme.events.Event;

class ConfigEditor extends FWidget{
	var _config:Dynamic;
	var _originalConfig:Dynamic;
	var _root:ConfigEditorField;
	var _hasChild:Bool;

	public function new(){
		super();
		_hasChild = false;

	}

	public function setConfig(config:Dynamic){
		_originalConfig = config;
		_config = FMisc.deepClone(config);
		_root =ConfigEditorField.getEditorField(null,_config,this);
		if(_hasChild){
			this.removeChildAt(0);
		}
		this.addChild(_root);
		_hasChild = true;
		this.dispatchEvent(new Event(FWidget.RESIZED));
		trace(this.height);
	}

	public function setValue(path:Array<String>, value:Dynamic){
		var current:ConfigEditorField;
		current = _root;
		for(p in path){
			if(Std.is(current,ConfigEditorStringField)){

			}
		}
	}


}