package firmament.core;

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
import firmament.core.FGame;
import firmament.core.FConfig;
import firmament.event.FMouseEvent;
import firmament.tilesheet.FTilesheetRenderHelper;
import firmament.util.FLog;
import openfl.system.System;

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
	var _mouseOverEnts:firmament.core.FEntityCollection;
	var _autoZoomToFit:Bool;
	var _fillColor:Int;
	var _fillAlpha:Float;
	var _clickEventsEnabled:Bool = false;
	var _seconds:Int;

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
		this._seconds = flash.Lib.getTimer();
		this._zoom = 100;
		this._position = new FVector(0, 0);
		this._calculatedTopLeft = false;
		this._topLeftPosition = new FVector(0, 0);
		this._displayHeight = height;
		this._displayWidth = width;
		_debugRender = false;
        _game = FGame.getInstance(gameInstanceName);
		_debugRenderer = new FWireframeRenderComponent(_game);
		_mouseOverEnts = new FEntityCollection();
		_autoZoomToFit = false;
		enableClickEvents();
	}


	public function init(config:FConfig){

		var pos = config.getVector('screenPosition',{x:0,y:0});
		this.x = pos.x;
		this.y = pos.y;
		_zoom = config.get('zoom',Float,100);

		var stage = Lib.current.stage;
		this._displayWidth = config.getNotNull("width",Float,stage.stageWidth);
		this._displayHeight = config.getNotNull("height",Float,stage.stageHeight);
		this.calculateTopLeftPosition(1);
		this._fillAlpha=config.get("fillAlpha",Float,1);
		this._fillColor=config.get("fillColor",Int,0);

		var properties:FConfig = config.get('properties',Dynamic);
		for( key in properties.fields() ) {
			/*
			// arrg!!  This isn't a property :(
			var prop:FProperty = this.getProperty( key );
			var value = properties.getNotNull( key, prop.type );
			prop.set(value);
			*/
			switch(key) {
				case 'position':{
					var value:FVector = properties.getNotNull(key,FVector);
					setPosition(value);
				}
				case 'positionX':{
					var value:Float = properties.getNotNull(key,Float);
					setPositionX(value);
				}
				case 'positionY': {
					var value:Float = properties.getNotNull(key,Float);
					setPositionY(value);
				}
				case 'zoom': {
					var value:Float = properties.getNotNull(key,Float);
					setZoom(value);
				}
			}
		}

		this._debugRender=config.get("debug",Bool,false);

	}

	public function render(worlds:Map<String,FWorld>) {
		this.dispatchEvent(new Event(FCamera.BEFORE_RENDER_EVENT));
		var rh = FTilesheetRenderHelper.getInstance();
		rh.preRender();
		this.graphics.clear();
		if(0 != _fillAlpha){
			this.graphics.beginFill(_fillColor,_fillAlpha);
			this.graphics.drawRect(0, 0, this._displayWidth, this._displayHeight);
			this.graphics.endFill();
		}

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

		for (ent in entityList) {
			var components = ent.getComponent("render");
			if(components!=null)
			for (component in components){
				cast(component,FRenderComponentInterface).render(this);
			}
		}
		this.dispatchEvent(new Event(FCamera.AFTER_RENDER_EVENT));
		rh.postRender(this);
		if(_debugRender){
			for (ent in entityList) {
				_debugRenderer.setEntity(ent);
				_debugRenderer.render(this);
			}
		}

		var stats = firmament.util.FStatistics.getInstance();
		recordFramesPerSecond(stats);
		recordMemoryUsage(stats);

	}

	static var _aveFPS = 0;
	static var _count = 0;
	private function recordFramesPerSecond(stats:firmament.util.FStatistics) {
		var ctime = flash.Lib.getTimer();
		if( !stats.hasProperty('FPS') ) {
			stats.registerProp('FPS',Float);
		}
		_aveFPS += ctime - _seconds;
		if( _count == 0 ) {
			stats.setProp('FPS', _aveFPS / 10.0);
			_aveFPS = 0;
		}
		_count = (++_count % 10);
		_seconds = ctime;
	}

	private function recordMemoryUsage(stats:firmament.util.FStatistics) {

		var mem:Float = Math.round(System.totalMemory / 1024 / 1024 * 100) / 100;
		
		if( !stats.hasProperty('MemPeak') ) {
			stats.registerProp('MemPeak',Int);
		}
		if( !stats.hasProperty('MemCurrent') ) {
			stats.registerProp('MemCurrent',Int);
		}
		stats.setProp('MemCurrent', mem );
		
		if( stats.getProp('MemCurrent') <= mem ) {
			stats.setProp('MemPeak', mem );
		}		
	}

	private function calculateTopLeftPosition(?parallax:Float=1) {
		//firmament.util.FLog.debug(this.width);
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

	public function setPositionX(v:Float) {
		this._position.x = v;
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

	public function setPositionY(v:Float) {
		this._position.y = v;
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

		var newZoom:Float = stage.stageWidth/this._displayWidth * this.getZoom();
		this.setZoom(newZoom);
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

	public function getScreenPosition(xc:Float,yc:Float):FVector {
		var btmRight:FVector = getBottomRightPosition();

		// translate object/coords so that the left most is 0,0 like camera
		// then stage * obj/cam
		var xs:Float = _displayWidth * (xc + btmRight.x) / (btmRight.x + btmRight.x);
		var ys:Float = _displayHeight * (yc + btmRight.y) / (btmRight.y + btmRight.y);

		return new FVector( xs, ys );
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

	public function setFillColor(color:Int){
		this._fillColor=color;
	}

    public function getFillColor(color:Int){
        return this._fillColor;
    }

	public function setFillAlpha(alpha:Float){
		this._fillAlpha=alpha;
	}

    public function getFillAlpha(color:Float){
        return this._fillAlpha;
    }

	/**
	 * Enables click events on this camera. Any entities under the point clicked on will receive a click event.
	 *
	 */
	public function enableClickEvents(){
		if(_clickEventsEnabled)return;
		_clickEventsEnabled = true;
		this.doubleClickEnabled=true; // turn on dblclicks
		var mouseEvents = [ // this could be a static
			flash.events.MouseEvent.CLICK,
			flash.events.MouseEvent.DOUBLE_CLICK,
			flash.events.MouseEvent.MIDDLE_CLICK,
			flash.events.MouseEvent.MIDDLE_MOUSE_DOWN,
			flash.events.MouseEvent.MIDDLE_MOUSE_UP,
			flash.events.MouseEvent.MOUSE_DOWN,
			flash.events.MouseEvent.MOUSE_UP,
			flash.events.MouseEvent.RIGHT_MOUSE_DOWN,
			flash.events.MouseEvent.RIGHT_MOUSE_UP,
			flash.events.MouseEvent.RIGHT_CLICK
		];
		for( event in mouseEvents ) {
			FLog.debug("Adding event - " + event);
			this.addEventListener(event,onMouseButton);	
		}
	}

	/**
	 * Enables mousemove events on this camera. Any entities under the point clicked on will receive a click event.
	 *
	 */
	public function enableOverEvents(){
		trace("Adding event - " + MouseEvent.MOUSE_OVER);
		trace("Adding event - " + MouseEvent.MOUSE_OUT);
		this.addEventListener(flash.events.MouseEvent.MOUSE_MOVE,function(e:MouseEvent){
			var ents = _game.getEntitiesAtPoint(getWorldPosition(e.localX,e.localY));
			for(ent in ents){
				var alreadyOver = _mouseOverEnts.remove(ent);
				if(ent.isActive() && !alreadyOver){
					ent.trigger(new FEvent(MouseEvent.MOUSE_OVER));
				}
			}
			//any ents left in _mouseOverEnts is now mouse_out
			for(ent in _mouseOverEnts){
				if(ent.isActive()){
					ent.trigger(new FEvent(MouseEvent.MOUSE_OUT));
				}
			}
			_mouseOverEnts = ents;
		});
	}

	private function onMouseButton(e:MouseEvent){
		var ents = _game.getEntitiesAtPoint(getWorldPosition(e.localX,e.localY));
		var mousePos:firmament.core.FVector = new firmament.core.FVector(e.localX, e.localY);
        ents.sortByPropertyAsc("positionZ");
        var event = new FMouseEvent(e.type, this, mousePos);
        event.bubbles = false;
		for(ent in ents){
			if(ent.isActive()){
				ent.trigger(event);
			}
		}

        //send event to scene components
        var event = new FMouseEvent(e.type, this, mousePos);
        _game.getCurrentScene().trigger(event);

	}

	public function destruct(){
		parent.removeChild(this);
	}

}
