package firmament.core;
import firmament.component.physics.FPhysicsComponentInterface;
import firmament.component.render.FRenderComponentInterface;
import flash.display.Sprite;
import firmament.core.FEntity;
import firmament.world.FWorld;
import flash.display.BitmapData;
import flash.geom.Rectangle;
import flash.Lib;
import flash.display.Stage;
import flash.events.Event;
import flash.events.MouseEvent;
import firmament.component.render.FWireframeRenderComponent;
import firmament.util.FConfigHelper;
import firmament.core.FGame;
/**
 * Class: FCamera
 * 
 * Extends: Sprite
 * 
 * Implements: <FWorldPositionalInterface>
 * 
 * @author Jordan Wambaugh
 */

class FCamera extends Sprite implements FWorldPositionalInterface 
{
	public inline static var BEFORE_RENDER_EVENT = "beforeRenderEvent";
	public inline static var AFTER_RENDER_EVENT = "afterRenderEvent";

	var _position:FVector;
	var _topLeftPosition:FVector;
	var _positionBase:String;
	var _angle:Float;
	var _zoom:Float;
	var _displayWidth:Int;
	var _displayHeight:Int;
	var _debugRender:Bool;
	var _debugRenderer:FWireframeRenderComponent;
	var _calculatedTopLeft:Bool;
	var _game:FGame;
	var _mouseOverEnts:Array<FEntity>;

	/**
	 * Constructor: new
	 * 
	 * Parameters:
		 * width - Int The width of the camera
		 * height - Int The height of the camera
	 */
	public function new(?width:Int=100,?height:Int=100,?gameInstanceName='main') 
	{
		super();
		this._zoom = 100;
		this._position = new FVector(0, 0);
		this._calculatedTopLeft = false;
		this._topLeftPosition = new FVector(0, 0);
		this._displayHeight = height;
		this._displayWidth = width;
		_debugRender = false;
		_debugRenderer = new FWireframeRenderComponent();
		_game = FGame.getInstance(gameInstanceName);
		_mouseOverEnts = new Array();
	}


	public function init(config:Dynamic){
		var c= new FConfigHelper(config);
		var pos = c.getVector('_position',{x:0,y:0});
		this.x = pos.x;
		this.y = pos.y;

		var stage = Lib.current.stage;
		this._displayWidth = c.getNotNull("width",Float,stage.stageWidth);
		this._displayHeight = c.getNotNull("height",Float,stage.stageHeight);
		this.calculateTopLeftPosition(1);

	}
	
	public function render(worlds:Map<String,FWorld>) {
		this.dispatchEvent(new Event(FCamera.BEFORE_RENDER_EVENT));
		
		this.graphics.clear();
		
		this.graphics.beginFill(0);
		this.graphics.drawRect(0, 0, this._displayWidth, this._displayHeight);
		this.graphics.endFill();
		
		//this.graphics.drawRect(0,0, this._displayWidth, this._displayHeight);
		var entityList:Array<FEntity> = new Array<FEntity>();
		var displayPadding = 4; //number of meters to pad in query for entities. Increase this if you have entities popping out at the edges
		for (world in worlds) {
			var entities = world.getEntitiesInBox(Math.floor(this._position.x - (this._displayWidth / 2 / this._zoom+displayPadding))
				,Math.floor(this._position.y - (this._displayHeight / 2 / this._zoom+displayPadding))
				,Math.floor(this._position.x + this._displayWidth / 2 / this._zoom+displayPadding)
				,Math.floor(this._position.y + this._displayHeight / 2 / this._zoom+displayPadding));
			
			//add entites marked for always rendering
			entities=entities.concat(world.getAlwaysRenderEntities());

			//Firmament.log(entities);
			if(entities!=null)
				entityList=entityList.concat(entities);
		}
		entityList.sort(function(a:FEntity,b:FEntity):Int{
			var cmp = a.getPhysicsComponent().getZPosition() -b.getPhysicsComponent().getZPosition();
			if (cmp==0) {
				return 0;	
			} else if (cmp > 0) return 1;
			return -1;
		});
		for (ent in entityList) {
			var components = ent.getComponent("render");
			if(components!=null)
			for (component in components){
				cast(component,FRenderComponentInterface).render(this);
			}
		}
		this.dispatchEvent(new Event(FCamera.AFTER_RENDER_EVENT));
		if(_debugRender){
			for (ent in entityList) {
				_debugRenderer.setEntity(ent);
				_debugRenderer.render(this);
			}
		}

	}

	private function calculateTopLeftPosition(?parallax:Float=1) {
		//trace(this.width);
		this._topLeftPosition.x=this._position.x-(this._displayWidth/this._zoom/parallax)/2;
		this._topLeftPosition.y = this._position.y - (this._displayHeight / this._zoom/parallax) / 2;
		this._calculatedTopLeft = true;
	}
	
	public function getTopLeftPosition(?parallax:Float=1) {
		
		this.calculateTopLeftPosition(parallax);
		
		return this._topLeftPosition;
	}
	
	public function getBottomRightPosition(?parallax:Float=1){
		return new FVector(
			this._position.x + (this._displayWidth/this._zoom/parallax)/2
			,this._position.y + (this._displayHeight / this._zoom/parallax) / 2);

	}


	/**
	 * Function: setPosition
	 * 
	 * Parameters:
		 * pos - <FVector>
	 */
	public function setPosition(pos:FVector) {
		this._position = pos;
	}
	
	/**
	 * Function: getPosition
	 * 
	 * Returns:
		 * <FVector>
	 */
	public function getPosition():FVector {
		return this._position;
	}
	
	/**
	 * Function: getPositionX
	 * 
	 * Returns:
		 * Float
	 */
	public function getPositionX():Float {
		return this._position.x;
	}
	
		/**
	 * Function: getPositionY
	 * 
	 * Returns:
		 * Float
	 */
	public function getPositionY():Float {
		return this._position.y;
	}
	
	/**
	 * Function: getZoom
	 * 
	 * The _zoom is 'pixels per meter'. By default, this value is set to 100, meaning we show 100 pixels for each meter in world space.
	 * 
	 * Returns: 
		 * Float - the camera's current _zoom value.
	 * 
	 * 
	 * See Also: 
		 * <setZoom>
	 */
	public function getZoom():Float {
		return this._zoom;
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
			this._zoom = z;
	}
	
	public function resizeToStage() {
		var stage = Lib.current.stage;
		this._displayWidth = stage.stageWidth;
		this._displayHeight = stage.stageHeight;
		//this.width = this._displayWidth;
		//this.height = this._displayHeight;
		this.calculateTopLeftPosition(1);
	}
	
	public function getWorldPosition(x:Float,y:Float) {
		return new FVector(
		(x / this.getZoom()) + (this.getPositionX() - (this._displayWidth / this.getZoom() / 2))
		,(y / this.getZoom()) + (this.getPositionY() - (this._displayHeight / this.getZoom() / 2)));

	}


	public function setDebugMode(debug:Bool){
		_debugRender = debug;
	}

	public function getAngle():Float{
		return 0;
	}
	public function setAngle(a:Float){
		//noop
	}

	/**
	 * Enables click events on this camera. Any entities under the point clicked on will receive a click event.
	 *
	 */
	public function enableClickEvents(){
		this.addEventListener(flash.events.MouseEvent.CLICK,onClick);
	}

	/**
	 * Enables click events on this camera. Any entities under the point clicked on will receive a click event.
	 *
	 */
	public function enableOverEvents(){
		this.addEventListener(flash.events.MouseEvent.MOUSE_MOVE,function(e:MouseEvent){
			var ents = _game.getEntitiesAtPoint(getWorldPosition(e.localX,e.localY));
			for(ent in ents){
				var alreadyOver = _mouseOverEnts.remove(ent);
				if(ent.isActive() && !alreadyOver){
					ent.dispatchEvent(new Event(MouseEvent.MOUSE_OVER));
				}
			}
			//any ents left in _mouseOverEnts is now mouse_out
			for(ent in _mouseOverEnts){
				if(ent.isActive()){
					ent.dispatchEvent(new Event(MouseEvent.MOUSE_OUT));
				}
			}
			_mouseOverEnts = ents;
		});
	}

	private function onClick(e:MouseEvent){
		var ents = _game.getEntitiesAtPoint(getWorldPosition(e.localX,e.localY));
		for(ent in ents){
			if(ent.isActive()){
				ent.dispatchEvent(new Event(MouseEvent.CLICK));
			}
		}
	}
	
}
