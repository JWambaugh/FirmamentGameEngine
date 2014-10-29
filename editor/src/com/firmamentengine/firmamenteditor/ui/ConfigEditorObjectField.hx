package com.firmamentengine.firmamenteditor.ui;

import com.firmamentengine.firmamenteditor.ui.ConfigEditorField;
import firmament.ui.layout.FHBox;
import firmament.ui.layout.FVBox;
import firmament.ui.FTextLabel;
import firmament.ui.FSmallButton;
import flash.events.MouseEvent;

class ConfigEditorObjectField extends ConfigEditorField{


	
	var _children:Array<ConfigEditorField>;
	var _maximized:Bool;
	var _vbox:FVBox;

	

	public function new(){
		super();
		_children = new Array();
		_maximized = true;

	}

	override public function draw(){
		_vbox = new FVBox();
	
		
		for(field in Reflect.fields(_value)){
			var hbox = new FHBox();
			var label = new FTextLabel(field+':');
			
			hbox.addChild(label);
			var value = ConfigEditorField.getEditorField(field,Reflect.field(_value,field),_editor,this);
			_children.push(value);
			if(Std.is(value,ConfigEditorObjectField)){
				var minimizeButton:FSmallButton;
				var ihb = new FHBox();

				var minimizeButton:FSmallButton = new FSmallButton("-",0,0);
				minimizeButton.addEventListener(MouseEvent.CLICK, function(e:MouseEvent){
					firmament.util.FLog.debug(ihb);
					
					if(minimizeButton.getText() == '-'){
						ihb.removeChild(value);
						minimizeButton.setText('+');
					}else{
						minimizeButton.setText('-');
						ihb.addChild(value);
					}
				});
				hbox.addChild(minimizeButton);
				_vbox.addChild(hbox);
				
				ihb.addChildren([
					new FTextLabel("  ")
					,value
				]); 
				_vbox.addChild(ihb);
			}else{
				hbox.addChild(value);
				_vbox.addChild(hbox);
			}
			
		}
		
		this.addChild(_vbox);
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

	/*public function minimize(e:Event){
		if(_maximized){
			this.removeChild(_vbox);
			_minimizeButton.setText('+');
			_maximized = false;
		}else{
			_minimizeButton.setText('-');
			_this.addChild(_vbox);
			_maximized = true;
		}
	}*/




}





