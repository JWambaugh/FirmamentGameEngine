package firmament.core;

/**
 * Class: FGame
 * Manages the game, including all worlds, cameras, simulation, rendering, etc.
 */


import firmament.core.FCamera;
import firmament.core.FEntity;
import firmament.core.FEntityPoolManager;
import firmament.core.FInput;
import firmament.core.FWorldFactory;
import firmament.process.base.FProcess;
import firmament.process.base.FProcessManager;
import firmament.process.engine.FCameraRenderProcess;
import firmament.process.engine.FWorldStepProcess;
import firmament.utils.loader.serializer.FSerializerFactory;
import firmament.utils.loader.FSceneLoader;
import haxe.Timer;
import nme.Assets;
import nme.display.Bitmap;
import nme.display.Sprite;
import nme.events.Event;
import nme.events.EventDispatcher;
import nme.events.TimerEvent;
import nme.Lib;
import nme.text.TextField;
import nme.utils.Timer;

/**
 * Class: FGame
 */
class FGame extends EventDispatcher
{
	var cameras:Hash<FCamera>;
	var worldHash:Hash<FWorld>; 
	public var enableSimulation:Bool;
	var processManager:FProcessManager;
	var _renderProcessManager:FProcessManager;

	var _mainInput:FInput;

	var _poolManager:FEntityPoolManager;

	//Constant: COLLISION_EVENT
	public static inline var COLLISION_EVENT = 'collision';
	
	//CONSTANT: BEFORE_STEP
	public static inline var BEFORE_STEP = 'beforeStep';
	
	//CONSTANT: AFTER_STEP
	public static inline var AFTER_STEP = 'afterStep';

	//CONSTANT: BEFORE_RENDER
	public static inline var BEFORE_RENDER = 'beforeRender';
	
	//CONSTANT: AFTER_RENDER
	public static inline var AFTER_RENDER = 'afterRender';

	//CONCSTANT: DELETE_ENTITY
	public static inline var DELETE_ENTITY = 'deleteEntity';

	private static var _instance:FGame;

	/**
	 * Constructor: new
	 */
	private function new() 
	{
		super();
		
		this.enableSimulation = true;
		worldHash = new Hash<FWorld>();
		cameras = new Hash<FCamera>();
		var stage = Lib.current.stage;
		this.processManager = new FProcessManager();
		_renderProcessManager = new FProcessManager();
		stage.addEventListener(Event.ENTER_FRAME, this_onEnterFrame);
		
		_mainInput = new FInput(stage);
		_poolManager = new FEntityPoolManager();
		/*var timer = new Timer(33);
		timer.addEventListener(TimerEvent.TIMER, this_step);
		timer.start();
		*/
	}



	public function loadGameConfig(fileName:String){
		var serializer = FSerializerFactory.getSerializerForFile(fileName);
		if (serializer == null) {
			throw ("Appropriate serializer for fileName "+fileName+" could not befound.");
		}
		var string = Assets.getText(fileName);
		var config = serializer.unserialize(string);
	}



	/*
		Function: getInstance
		returns the singleton instance of FGame.
	*/
	// TODO: Refactor to getInstance
	public static function getInstance():FGame{
		if(_instance == null){
			_instance = new FGame();
		}
		return _instance;
	}
	
	/**
	 * Function: getWorld
	 *
	 * Returns: an FWorld object of the type provided
	 */
	public function getWorld(type:String):FWorld{
		if(worldHash.exists(type)){
			return worldHash.get(type);
		}
		var w = FWorldFactory.createWorld(type);
		worldHash.set(type, w);

		//set up process for it
		var p = new FWorldStepProcess(w);
		this.processManager.addProcess(p);

		return w;
	}

	public function getWorlds():Hash<FWorld>{
		return this.worldHash;
	}

	public function getAllEntities():Array<FEntity>{
		var a = new Array<FEntity>();
		for(world in getWorlds()){
			a=a.concat(world.getAllEntities());
		}
		return a;
	}

	public function getEntitiesAtPoint(p:FVector):Array<FEntity>{
		var a = new Array<FEntity>();
		for(world in worldHash){
			a=a.concat(world.getEntitiesAtPoint(p));
		}
		return a;
	}

	/**
	 * Function: getProcessManager
	 */
	public function getProcessManager():FProcessManager {
		return this.processManager;
	}

	/**
	 * Function: getRenderProcessManager
	 */
	public function getRenderProcessManager():FProcessManager {
		return this._renderProcessManager;
	}


	/**
	 * Function: addProcess
	 *
	 * Parameters: 
	 *  name - String identifier for object, for retrieval
	 *  p - Process object
	 */
	public function addProcess(?type:String,p:FProcess):Void {
		this.processManager.addProcess(p);
	}

	/**
	 * Function: addCamera
	 * 
	 * Adds a new <FCamera> object to the game. Cameras must be added to the game in order for them to work.
	 * 
	 * Parameters:
	 *	name - String the name to call the camera. Used for getting the right camera.
	 *	c - <FCamera> The camera to add
	 */
	public function addCamera(name:String,c:FCamera):Void {
		this.cameras.set(name,c);
		this._renderProcessManager.addProcess(new FCameraRenderProcess(c));
	}


	/**
	 *	Function: getCamera
	 *	Parameters:
	 *		name - String the name of the camera to retrieve
	 *	Returns: <FCamera>
	*/
	public function getCamera(name:String):FCamera{
		return this.cameras.get(name);
	}
	

	/*
		Function: getMainInput
		returns the main <FInput> object connected to the stage.

	*/
	public function getMainInput(){
		return _mainInput;
	}
	
	
	private function doStep():Void {
		this.dispatchEvent(new Event(FGame.BEFORE_STEP));
		this.processManager.step();
		this.dispatchEvent(new Event(FGame.AFTER_STEP));
		this._renderProcessManager.step();
	}



	private function this_onEnterFrame (event:Event):Void {
		//trace('this is called.');
		
		//var start = haxe.Timer.stamp();
		this.doStep();
		//trace("step time: "+(haxe.Timer.stamp() - start));
		
	} 

	public function getPoolManager(){
		return _poolManager;
	}

	/*
		Function: clearWorlds
		Destroys all worlds and entities

	*/
	public function clearWorlds(){
		for (world in worldHash){
			world.destruct();
		}
		worldHash = new Hash();
	}

	/*
		Function: clearAll
		destroys or clears references to all entities, worlds, cameras, and processes.
	*/
	public function clearAll(){
		clearWorlds();
		processManager = new FProcessManager();
		_renderProcessManager = new FProcessManager();
		cameras = new Hash();
	}


}
