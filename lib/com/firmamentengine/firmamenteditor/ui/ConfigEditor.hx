package com.firmamentengine.firmamenteditor.ui;
import firmament.ui.FWidget;
import com.firmamentengine.firmamenteditor.ui.ConfigEditorField;
import com.firmamentengine.firmamenteditor.ui.ConfigEditorStringField;
import firmament.util.FMisc;
import flash.events.Event;

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
		//trace(this.height);
	}

	public function setValue(path:Array<String>, value:Dynamic){
		var current:ConfigEditorField;
		var pathString = '/'+path.join('/');
		current = _root;
		var found:Bool=false;
		for(p in path){
			found=false;			
			if(Std.is(current,ConfigEditorObjectField)){
				
				for(o in cast(current,ConfigEditorObjectField).getChildren()){
					if(o.getKey() == p){
						current = o;
						found = true;
						break;
					} 
				}
			}
			if(!found)throw "Invalid path? "+ pathString;
		}
		if(current.getPath() == pathString){
			current.updateValue(value);			
		}else{
			if(!found)throw "Invalid path? "+ pathString;
		}
	}


}