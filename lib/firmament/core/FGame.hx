package firmament.core;

/**
 * Class: FGame
 * Manages the game, including all worlds, cameras, simulation, rendering, etc.
 */



import nme.events.EventDispatcher;
import nme.events.TimerEvent;
import nme.Lib;
import nme.events.Event;
import nme.display.Bitmap;
import nme.Assets;
import nme.text.TextField;
import nme.utils.Timer;
import haxe.Timer;
import firmament.core.FEntity;
import firmament.core.FWorldFactory;

import firmament.core.FCamera;

/**
 * Main Game class
 */
class FGame extends EventDispatcher
{
	var cameras:Array<FCamera>;
	var worldHash:Hash<FWorld>; 
	var enableSimulation:Bool;
	//Constant: COLLISION_EVENT
	public static inline var COLLISION_EVENT = 'collision';
	
	//CONSTANT: BEFORE_STEP
	public static inline var BEFORE_STEP = 'beforeStep';
	
	//CONSTANT: AFTER_STEP
	public static inline var AFTER_STEP = 'afterStep';
	
	private static var _instance:FGame;

	/**
	 * Constructor: new
	 */
	private function new() 
	{
		super();
		
		this.enableSimulation = true;
		worldHash = new Hash<FWorld>();
		cameras = new Array<FCamera>();
		var stage = Lib.current.stage;
		stage.addEventListener(Event.ENTER_FRAME, this_onEnterFrame);
		
		/*var timer = new Timer(33);
		timer.addEventListener(TimerEvent.TIMER, this_step);
		timer.start();
		*/
		
		
	}

	/*
		Function: instance
		returns the singleton instance of FGame.
	*/
	public static function instance():FGame{
		if(_instance == null){
			_instance = new FGame();
		}
		return _instance;
	}
	
	/**
	 * Function: getWorld
	 *
	 * Returns: an FWorld objecto of the type provided
	 */
	public function getWorld(type:String):FWorld{
		if(worldHash.exists(type)){
			return worldHash.get(type);
		}
		var w = FWorldFactory.createWorld(type);
		worldHash.set(type, w);
		return w;
	}

	/**
	 * Function: addCamera
	 * 
	 * Adds a new <FCamera> object to the game. Cameras must be added to the game in order for them to work.
	 * 
	 * Parameters:
	 *	c - <FCamera> The camera to add
	 */
	public function addCamera(c:FCamera) {
		this.cameras.push(c);
	}
	
	
	
	private function doStep():Void {
		if (!this.enableSimulation) return;
		
		for (world in this.worldHash) {
			world.step();
			
		}
	}
	private function this_onEnterFrame (event:Event):Void {
		//trace('this is called.');
		this.dispatchEvent(new Event(FGame.BEFORE_STEP));
		//var start = haxe.Timer.stamp();
		this.doStep();
		//trace("step time: "+(haxe.Timer.stamp() - start));
		this.dispatchEvent(new Event(FGame.AFTER_STEP));
		//var start = haxe.Timer.stamp();
		for(camera in cameras){
			camera.render(worldHash);
		}
		
	}


}