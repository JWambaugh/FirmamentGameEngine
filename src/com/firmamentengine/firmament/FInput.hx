package com.firmamentengine.firmament;



import nme.events.EventDispatcher;
import nme.events.Event;
import nme.events.MouseEvent;
import nme.events.KeyboardEvent;




class FInput{
	var observable:EventDispatcher;
	var pressedKeys:Array<Int>;
	var mainButtonPressed:Bool;
	var localX:Float;
	var localY:Float;
	var stageX:Float; 
	var stageY:Float;
	var keyStatus:Array<Bool>;

	public function new(o:EventDispatcher){
		this.observable = o;
		this.localX = 0;
		this.localY = 0;
		this.stageX = 0;
		this.stageY = 0;
		this.keyStatus = new Array<Bool>();

		//initialize our array. there must be a better way to do this.
		for(i in 0...255){
			keyStatus.push(false);
		}

		o.addEventListener(MouseEvent.CLICK, this.mouseEvent);
		o.addEventListener(MouseEvent.MOUSE_MOVE, this.mouseEvent);
		o.addEventListener(KeyboardEvent.KEY_DOWN,this.keyboardEventDown);
		o.addEventListener(KeyboardEvent.KEY_UP,this.keyboardEventUp);
		
	}
	
	public function mouseEvent(e:MouseEvent) {
		this.localX = e.localX;
		this.localY = e.localY;
		this.stageX = e.stageX;
		this.stageY = e.stageY;
	}


	public function keyboardEventDown(e:KeyboardEvent) {
		this.keyStatus[e.keyCode] = true;
		//trace(e.keyCode);
	}
	public function keyboardEventUp(e:KeyboardEvent) {
		this.keyStatus[e.keyCode]=false;
	}

	
	public function getLocalX() {
		return localX;
	}
	
	public function getLocalY() {
		return localY;
	}
	
	public function getStageX() {
		return stageX;
	}
	
	public function getStageY() {
		return stageY;
	}


	public function isKeyPressed(keyCode:Int):Bool{
		if(keyCode<=255 && keyCode >=0)
			return this.keyStatus[keyCode];
		throw "Invalid keycode";
	}
	
}



