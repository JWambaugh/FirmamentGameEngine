package com.firmamentengine.firmament;

import nme.display.Bitmap;
import com.firmamentengine.firmament.FEntity;
import com.firmamentengine.firmament.FWorld;
import nme.display.BitmapData;
import nme.geom.Rectangle;

import nme.events.Event;
/**
 * ...
 * @author Jordan Wambaugh
 */

class FCamera extends Bitmap ,implements FWorldPositionalInterface 
{
	var position:FVector;
	var topLeftPosition:FVector;
	var positionBase:String;
	var angle:Float;
	var zoom:Float;
	var displayWidth:Int;
	var displayHeight:Int;

	var calculatedTopLeft:Bool;
	public function new(width:Int,height:Int) 
	{
		super();
		this.zoom = 80;
		this.bitmapData = new BitmapData(width, height);
		this.position = new FVector(0, 0);
		this.calculatedTopLeft = false;
		this.topLeftPosition = new FVector(0, 0);
		this.displayHeight = height;
		this.displayWidth = width;
	}
	
	public function render(worlds:Array<FWorld>) {
		
		this.bitmapData.fillRect(new Rectangle(0, 0, this.width, this.height),0xFFFFFF);
		
		//this.graphics.drawRect(0,0, this.displayWidth, this.displayHeight);
		for (world in worlds) {
			var entities:Array<FEntity> = world.getAllEntities();
			for (ent in entities) {
				ent.getRenderer().render(ent, this);
			}
		}
	}
	private function calculateTopLeftPosition() {
		//trace(this.width);
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