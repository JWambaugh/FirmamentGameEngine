package com.firmamentengine.firmamenteditor.ui;
import firmament.ui.FWidget;
import com.firmamentengine.firmamenteditor.ui.ConfigEditorField;
import firmament.util.FMisc;


class ConfigEditor extends FWidget{
	var _config:Dynamic;
	var _originalConfig:Dynamic;
	var _root:ConfigEditorField;
	public function new(){
		super();

	}

	public function setConfig(config:Dynamic){
		_originalConfig = config;
		_config = FMisc.deepClone(config);
		_root =ConfigEditorField.getEditorField(null,_config,this);
		this.addChild(_root);
	}


}