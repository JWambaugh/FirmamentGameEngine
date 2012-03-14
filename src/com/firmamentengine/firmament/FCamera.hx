package com.firmamentengine.firmament;

import nme.display.Bitmap;
import com.firmamentengine.firmament.FEntity;
import com.firmamentengine.firmament.FWorld;
import nme.display.BitmapData;
import nme.geom.Rectangle;
import nme.Lib;
import nme.display.Stage;
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
		this.zoom = 100;
		this.bitmapData = new BitmapData(width, height);
		this.position = new FVector(0, 0);
		this.calculatedTopLeft = false;
		this.topLeftPosition = new FVector(0, 0);
		this.displayHeight = height;
		this.displayWidth = width;
		this.width = width;
		this.height = height;
	}
	
	public function render(worlds:Array<FWorld>) {
		
		this.bitmapData.fillRect(new Rectangle(0, 0, this.displayWidth, this.displayHeight),0xFFFFFF);
		
		//this.graphics.drawRect(0,0, this.displayWidth, this.displayHeight);
		var entityList:Array<FEntity> = new Array<FEntity>();
		var displayPadding = 4; //number of meters to pad in query for entities. Incres this if you have entities popping out at the edges
		for (world in worlds) {
			var entities = world.getEntitiesInBox(Math.floor(this.position.x - (this.displayWidth / 2 / this.zoom+displayPadding))
				,Math.floor(this.position.y - (this.displayHeight / 2 / this.zoom+displayPadding))
				,Math.floor(this.position.x + this.displayWidth / 2 / this.zoom+displayPadding)
				,Math.floor(this.position.y + this.displayHeight / 2 / this.zoom+displayPadding));
			
			//Firmament.log(entities);
			entityList=entityList.concat(entities);
			
			
		}
		entityList.sort(function(a:FEntity,b:FEntity):Int{
			var cmp = a.getZPosition() - b.getZPosition();
			if (cmp==0) {
				return 0;	
			} else if (cmp > 0) return 1;
			return -1;
		});
		for (ent in entityList) {
				ent.getRenderer().render(ent, this);
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
	
	public function setZoom(z:Float) {
			this.zoom = z;
	}
	
	public function resizeToStage() {
		var stage = Lib.current.stage;
		this.displayWidth = stage.stageWidth;
		this.displayHeight = stage.stageHeight;
		this.width = this.displayWidth;
		this.height = this.displayHeight;
		this.calculateTopLeftPosition();
	}
	
}
