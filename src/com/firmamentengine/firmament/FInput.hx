package com.firmamentengine.firmament;



import nme.events.EventDispatcher;
import nme.events.Event;
import nme.events.MouseEvent;




class FInput{
	var observable:EventDispatcher;
	var pressedKeys:Array<Int>;
	var mainButtonPressed:Bool;
	var localX:Float;
	var localY:Float;
	var stageX:Float; 
	var stageY:Float;
	public function new(o:EventDispatcher){
		this.observable = o;
		this.localX = 0;
		this.localY = 0;
		this.stageX = 0;
		this.stageY = 0;

		o.addEventListener(MouseEvent.CLICK, this.mouseEvent);
		o.addEventListener(MouseEvent.MOUSE_MOVE, this.mouseEvent);
	}
	
	public function mouseEvent(e:MouseEvent) {
		this.localX = e.localX;
		this.localY = e.localY;
		this.stageX = e.stageX;
		this.stageY = e.stageY;
	}


	public function keyboardEvent() {
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
	
}



