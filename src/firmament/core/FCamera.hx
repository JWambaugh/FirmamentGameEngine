package firmament.core;

import nme.display.Sprite;
import firmament.core.FEntity;
import firmament.core.FWorld;
import nme.display.BitmapData;
import nme.geom.Rectangle;
import nme.Lib;
import nme.display.Stage;
import nme.events.Event;
/**
 * Class: FCamera
 * 
 * Extends: Sprite
 * 
 * Implements: <FWorldPositionalInterface>
 * 
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
	
	/**
	 * Constructor: new
	 * 
	 * Parameters:
		 * width - Int The width of the camera
		 * height - Int The height of the camera
	 */
	public function new(width:Int,height:Int) 
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
		trace('render');
		this.graphics.clear();
		this.graphics.beginFill(0);
		this.graphics.drawRect(0, 0, this.displayWidth, this.displayHeight);
		this.graphics.endFill();
		var wireframe = new FWireframeRenderer();
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
				//wireframe.render(ent,this);
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
	
	/**
	 * Function: setPosition
	 * 
	 * Parameters:
		 * pos - <FVector>
	 */
	public function setPosition(pos:FVector) {
		this.position = pos;
	}
	
	/**
	 * Function: getPosition
	 * 
	 * Returns:
		 * <FVector>
	 */
	public function getPosition():FVector {
		return this.position;
	}
	
	/**
	 * Function: getPositionX
	 * 
	 * Returns:
		 * Float
	 */
	public function getPositionX():Float {
		return this.position.x;
	}
	
		/**
	 * Function: getPositionY
	 * 
	 * Returns:
		 * Float
	 */
	public function getPositionY():Float {
		return this.position.y;
	}
	
	/**
	 * Function: getZoom
	 * 
	 * The zoom is 'pixels per meter'. By default, this value is set to 100, meaning we show 100 pixels for each meter in world space.
	 * 
	 * Returns: 
		 * Float - the camera's current zoom value.
	 * 
	 * 
	 * See Also: 
		 * <setZoom>
	 */
	public function getZoom():Float {
		return this.zoom;
	}
	
	/**
	 * Function: setZoom
	 * 
	 * The zoom is 'pixels per meter'. By default, this value is set to 100, meaning we show 100 pixels for each meter in world space.
	 * 
	 * Parameters:
		 * z - Float
	 * 
	 * See Also: 
		 * <getZoom>
	 */
	public function setZoom(z:Float) {
			this.zoom = z;
	}
	
	public function resizeToStage() {
		var stage = Lib.current.stage;
		this.displayWidth = stage.stageWidth;
		this.displayHeight = stage.stageHeight;
		//this.width = this.displayWidth;
		//this.height = this.displayHeight;
		this.calculateTopLeftPosition();
	}
	
	public function getWorldPosition(x:Float,y:Float) {
		return new FVector(
		(x / this.getZoom()) + (this.getPositionX() - (this.displayWidth / this.getZoom() / 2))
		,(y / this.getZoom()) + (this.getPositionY() - (this.displayHeight / this.getZoom() / 2)));

	}
	
}
