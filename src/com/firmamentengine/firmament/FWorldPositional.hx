package com.firmamentengine.firmament;
import com.firmamentengine.firmament.FVector;
import nme.events.EventDispatcher;


/**
 * ...
 * @author Jordan Wambaugh
 */

class FWorldPositional extends EventDispatcher
{

	var position:FVector;
	var positionBase:String;
	var angle:Float;
	public function new() {
		super();
		this.position = new FVector(0, 0);
	}
	
	public function setPosition(pos:FVector) {
		this.position = pos;
	}
	
	public function getPosition():FVector {
		return this.position;
	}
	
	public function getPositionX():Float {
		return this.position.x;
	}
	
	public function getPositionY():Float {
		return this.position.y;
	}
}