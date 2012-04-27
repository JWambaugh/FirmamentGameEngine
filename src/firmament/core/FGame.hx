package firmament.core;

/**
 * Class: FGame
 * Manages the game, including all worlds, cameras, simulation, rendering, etc.
 */


import nme.display.StageAlign;
import nme.display.StageScaleMode;
import nme.events.EventDispatcher;
import nme.events.TimerEvent;
import nme.Lib;
import nme.events.Event;
import nme.display.Bitmap;
import nme.Assets;
import nme.text.TextField;
import nme.utils.Timer;
import haxe.Timer;
import firmament.core.FPhysicsEntity;
import firmament.core.FPhysicsWorld;
import firmament.core.FCamera;

/**
 * Main Game class
 */
class FGame extends EventDispatcher
{
	var cameras:Array<FCamera>;
	var world:FPhysicsWorld;
	var worldArray:Array<FWorld>;
	
	//Constant: COLLISION_EVENT
	public static inline var COLLISION_EVENT = 'collision';
	
	//CONSTANT: BEFORE_STEP
	public static inline var BEFORE_STEP = 'beforeStep';
	
	//CONSTANT: AFTER_STEP
	public static inline var AFTER_STEP = 'afterStep';
	
	/**
	 * Constructor: new
	 */
	public function new() 
	{
		super();
		
		
		worldArray = new Array<FWorld>();
		cameras = new Array<FCamera>();
		var stage = Lib.current.stage;
		stage.addEventListener(Event.ENTER_FRAME, this_onEnterFrame);
		
		/*var timer = new Timer(33);
		timer.addEventListener(TimerEvent.TIMER, this_step);
		timer.start();
		*/
		
		
	}
	/**
	 * Function: addWorld
	 * 
	 * Adds a new <FWorld> object to the game.
	 * 
	 * Parameters:
		 * w - <FWorld> The world to add
	 */
	public function addWorld(w:FWorld) {
		this.worldArray.push(w);
	}
	
	/**
	 * Function: addCamera
	 * 
	 * Adds a new <FCamera> object to the game. Cameras must be added to the game in order for them to work.
	 * 
	 * Parameters:
		 * c - <FCamera> The camera to add
	 */
	public function addCamera(c:FCamera) {
		this.cameras.push(c);
	}
	
	
	
	private function doStep():Void {
		//trace('step');
		
		for (world in this.worldArray) {
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
			camera.render(worldArray);
		}
		//trace("render time: "+(haxe.Timer.stamp() - start));
		
	}
}