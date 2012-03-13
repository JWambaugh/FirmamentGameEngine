package com.firmamentengine.firmament;



import nme.events.EventDispatcher;
import nme.events.Event;
import nme.events.MouseEvent;




class FInput{
	var observable:EventDispatcher;
	public function new(o:EventDispatcher){
		this.observable = o;

		o.addEventListener(MouseEvent.CLICK,this.mouseEvent);
	}
	
	public function mouseEvent(e:MouseEvent){
		trace('mouse event');
	}


}



