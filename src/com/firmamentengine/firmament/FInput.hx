package com.firmamentengine.firmament;



import nme.events.EventDispatcher;
import nme.events.Event;
import nme.events.MouseEvent;




class FInput{
	var observable:EventDispatcher;
	var pressedKeys:Array<Int>;
	var mainButtonPressed:Bool;
	var lastMouseEvent:MouseEvent;
	public function new(o:EventDispatcher){
		this.observable = o;

		o.addEventListener(MouseEvent.CLICK,this.mouseEvent);
	}
	
	public function mouseEvent(e:MouseEvent) {
		this.lastMouseEvent = e;
	}


	public function keyboardEvent() {
	}
	
	public function getLocalX() {
		return lastMouseEvent.localX;
	}
	
	public function getLocalY() {
		return lastMouseEvent.localY;
	}
	
}



