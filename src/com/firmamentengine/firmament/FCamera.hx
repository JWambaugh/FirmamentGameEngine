package com.firmamentengine.firmament;

import nme.display.Sprite;
import com.firmamentengine.firmament.FEntity;
import com.firmamentengine.firmament.FWorld;
import nme.events.Event;
/**
 * ...
 * @author Jordan Wambaugh
 */

class FCamera extends Sprite ,implements FWorldPositionalInterface 
{
	var position:FVector;
	var topLeftPosition:FVector;
	var positionBase:String;
	var angle:Float;
	var zoom:Float;
	var displayWidth:Int;
	var displayHeight:Int;

	var calculatedTopLeft:Bool;
	public function new(height:Int,width:Int) 
	{
		super();
		this.zoom = 100;
		
		this.position = new FVector(0, 0);
		this.calculatedTopLeft = false;
		this.topLeftPosition = new FVector(0, 0);
		this.displayHeight = height;
		this.displayWidth = width;
	}
	
	public function render(worlds:Array<FWorld>) {
		this.graphics.clear();
		this.graphics.lineStyle(1, 0);
		this.graphics.drawRect(0,0, this.displayWidth, this.displayHeight);
		for (world in worlds) {
			var entities:Array<FEntity> = world.getAllEntities();
			for (ent in entities) {
				ent.getRenderer().render(ent, this);
			}
		}
	}
	private function calculateTopLeftPosition() {
		
		this.topLeftPosition.x=this.position.x-(this.displayWidth/this.zoom)/2;
		this.topLeftPosition.y = this.position.y - (this.displayHeight / this.zoom) / 2;
		this.calculatedTopLeft = true;
	}
	
	public function getTopLeftPosition() {
		
			this.calculateTopLeftPosition();
		
		return this.topLeftPosition;
	}
	
	public function setPosition(pos:FVector):Void {
		this.position = pos;
		this.calculateTopLeftPosition();
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
	
	public function getZoom():Float {
		return this.zoom;
	}
	
	
}