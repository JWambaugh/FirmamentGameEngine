package firmament.core;

/**
 * Class: FGame
 * Manages the game, including all worlds, cameras, simulation, rendering, etc.
 */





import firmament.component.base.FEntityComponent;
import firmament.core.FCamera;
import firmament.core.FConfig;
import firmament.core.FEntity;
import firmament.core.FEntityCollection;
import firmament.core.FEntityPoolManager;
import firmament.core.FEvent;
import firmament.core.FInput;
import firmament.core.FThreadPool;
import firmament.core.FObject;
import firmament.filter.entity.FEntityFilter;
import firmament.filter.entity.FEntityFilterFactory;
import firmament.process.base.FProcess;
import firmament.process.base.FProcessManager;
import firmament.process.engine.FCameraRenderProcess;
import firmament.process.engine.FWorldStepProcess;
import firmament.process.timer.FTimerManager;
import firmament.scene.FScene;
import firmament.util.FLog;
import firmament.util.FRepository;
import firmament.util.loader.FDataLoader;
import firmament.util.loader.FSceneLoader;
import firmament.util.loader.serializer.FSerializerFactory;
import firmament.world.FWorld;
import firmament.world.FWorldFactory;
import flash.display.Bitmap;
import flash.display.Sprite;
import flash.events.Event;
import flash.events.EventDispatcher;
import flash.events.TimerEvent;
import flash.Lib;
import flash.text.TextField;
import flash.utils.Timer;
import haxe.Timer;
import hscript.Interp;
import openfl.Assets;

using StringTools;
/**
 * Class: FGame
 */
class FGame extends FObject
{
	public var _enableSimulation:Bool;

	var _cameras:Map<String,FCamera>;
	var _worldHash:Map<String,FWorld>;


	var _gameProcessManager:FProcessManager;
	var _renderProcessManager:FProcessManager;

	var _mainInput:FInput;

	var _poolManager:FEntityPoolManager;

	var _gameTimerManager:FTimerManager;

	var _currentScene:FScene;

	var _name:String;

	var _interpreter:Interp;

	var _stepSubscribers:List<FStepSubscriber>;

	//Constant: COLLISION_PRE_SOLVE_EVENT
	public static inline var COLLISION_PRE_SOLVE_EVENT = 'preSolveCollision';

	//Constant: COLLISION_POST_SOLVE_EVENT
	public static inline var COLLISION_POST_SOLVE_EVENT = 'postSolveCollision';

	//Constant: COLLISION_BEGIN_CONTACT_EVENT
	public static inline var COLLISION_BEGIN_CONTACT_EVENT = 'beginContactCollision';

	//Constant: COLLISION_END_CONTACT_EVENT
	public static inline var COLLISION_END_CONTACT_EVENT = 'endContactCollision';




	//CONSTANT: BEFORE_STEP
	public static inline var BEFORE_STEP = 'beforeStep';

	//CONSTANT: AFTER_STEP
	public static inline var AFTER_STEP = 'afterStep';

	//CONSTANT: BEFORE_RENDER
	public static inline var BEFORE_RENDER = 'beforeRender';

	//CONSTANT: AFTER_RENDER
	public static inline var AFTER_RENDER = 'afterRender';

	//CONSTANT: DELETE_ENTITY
	public static inline var DELETE_ENTITY = 'deleteEntity';


	private static var _instances:Map<String,FGame>;


	private var _inStep:Bool;

	private var _deferredFunctionsArray:List< List<Void->Void> >;

	/**
	 * Constructor: new
	 */
	private function new()
	{
		super();

		this._enableSimulation = true;
		_inStep = false;
		_deferredFunctionsArray = new List();
		{
			_deferredFunctionsArray.add( new List() );
			_deferredFunctionsArray.add( new List() );
		}
		_worldHash = new Map<String,FWorld>();
		_cameras = new Map<String,FCamera>();
		_stepSubscribers = new List();
		var stage = Lib.current.stage;
		this._gameProcessManager = new FProcessManager();
		_renderProcessManager = new FProcessManager();
		stage.addEventListener(Event.ENTER_FRAME, this_onEnterFrame);
		initializeInterpreter();
		_mainInput = new FInput(stage);
		_poolManager = new FEntityPoolManager();
		_gameTimerManager = new FTimerManager();
		this._gameProcessManager.addProcess(_gameTimerManager);
	}

	public function isInStep():Bool {
		return _inStep == true;
	}

	public function addStepSubscriber(c:FStepSubscriber){
		_stepSubscribers.push(c);
	}

	public function removeStepSubscriber(c:FStepSubscriber){
		_stepSubscribers.remove(c);
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
		returns an instance of FGame.
		As of 2.1, has optional parameter 'key'
		@param String - The name of the instance to get. Default name is 'main'
		@param Bool - Set instance to active (use as default when calling this function)
	*/
	public static function getInstance(?name:String=null):FGame{
		if(_instances == null){
			_instances = new Map();
		}
		if( name == null || name == "" ) { // use name if avail
			name = "main";
		}
		var instance = _instances.get(name);
		if(instance == null){
			instance = new FGame();
			instance._name = name;
			_instances.set(name,instance);
		}
		return instance;
	}

	/**
	 * Function: getWorld
	 *
	 * Returns: an FWorld object of the type provided
	 */
	public function getWorld(type:String):FWorld{
		if(_worldHash.exists(type)){
			return _worldHash.get(type);
		}
		var w = FWorldFactory.createWorld(type);
		_worldHash.set(type, w);

		//set up process for it
		var p = new FWorldStepProcess(w,this);
		this._gameProcessManager.addProcess(p);

		return w;
	}

	public function getWorlds():Map<String,FWorld>{
		return this._worldHash;
	}

	public function getAllEntities():FEntityCollection{
		var a = new Array<FEntity>();
		for(world in getWorlds()){
			a=a.concat(world.getAllEntities());
		}
		return new FEntityCollection(a);
	}

	public function getEntitiesAtPoint(p:FVector):FEntityCollection{
		var a = new Array<FEntity>();
		for(world in _worldHash){
			a=a.concat(world.getEntitiesAtPoint(p));
		}
		return new FEntityCollection(a);
	}

	public function getEntitiesInBox(topLeftX:Float,topLeftY:Float,bottomRightX:Float,bottomRightY:Float):FEntityCollection {
		var a = new Array<FEntity>();
		for(world in _worldHash){
			a=a.concat(world.getEntitiesInBox(topLeftX,topLeftY,bottomRightX,bottomRightY));
		}
		return new FEntityCollection(a);
	}


	/*
		Function: queryEntities

		Returns: Array<FEntity> objects

		Example query:
			{
				selector: 'box'
				,topLeft: {x:-1,-1}
				,bottomRight:{1,1}
				,filters:{
					type:{
						typeId: "enemy"
					}
				}

			}

	*/
	public function queryEntities(query:Dynamic, scope:FEntity=null):FEntityCollection{
		if(Std.is(query, String)){
			return this.select(query);
		}
		var entities:Array<FEntity>;
		var config:FConfig = query;
		var selector:String = config.get("selector",String,"Default");
		if (selector == "box"){
			var topLeft = config.getVector("topLeft",null);
			var bottomRight = config.getVector("bottomRight",null);
			if(topLeft == null || bottomRight ==null){
				throw "parameters topLeft or bottomRight are null.";
			}
			entities = getEntitiesInBox(topLeft.x,topLeft.y,bottomRight.x,bottomRight.y).get();
		}else if(selector =="point"){
			var point = config.getVector("point",null);
			if(point == null){throw "parameter 'point' is missing or null";}
			entities = getEntitiesAtPoint(point).get();
		}else{
			//default to select all
			entities = getAllEntities().get();
		}

		//run filters
		if(Reflect.isObject(query.filters)){
			for(filterName in Reflect.fields(query.filters)){
				var filter:FEntityFilter = FEntityFilterFactory.createfilter(filterName);
				entities = filter.filterEntityArray(entities,Reflect.field(query.filters,filterName));
			}
		}
		return new FEntityCollection(entities);
	}


	public function select(query:String, scope:FEntity=null):FEntityCollection{
		var collection:FEntityCollection = null;
		query=query.ltrim();

		//determine main selecor
		if(query.charAt(0)=='#'){

			if(query.startsWith("#game")){
				collection = getAllEntities();
				query = query.substr(5);
			}

			else if(query.startsWith("#world:")){	//#world:box2d
				query = query.substr(7);
				var spacePos = query.indexOf(' ');
				var worldName = query.substr(0,spacePos);
				if(worldName==null || worldName ==''){
					FLog.error('World is required when using the world: selector');
					return new FEntityCollection();
				}

				var world = getWorld(worldName);
				if(world == null){
					FLog.error('World of type '+worldName+' does not exist');
					return new FEntityCollection();
				}
				collection = new FEntityCollection(world.getAllEntities());
				query = query.substr(spacePos);
			}


		}else{
			collection = getAllEntities();
		}
		collection.thisIs(scope);
		return collection.filter(query);
	}

	/**
	 * Function: getProcessManager
	 */
	public function getProcessManager():FProcessManager {
		return this._gameProcessManager;
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
	public function addProcess(?type:String=null,p:FProcess):Void {
		this._gameProcessManager.addProcess(p);
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
		this._cameras.set(name,c);
		this._renderProcessManager.addProcess(new FCameraRenderProcess(c,this));
	}


	/**
	 *	Parameters:
	 *		name - String the name of the camera to retrieve
	 *	Returns: <FCamera>
	*/
	public function getCamera(name:String="main"):FCamera{
		return this._cameras.get(name);
	}

	/**
	 * Returns all the cameras attached to this
	 */
	public function getCameras(){
		return _cameras;
	}

	/*
		Function: getMainInput
		returns the main <FInput> object connected to the stage.

	*/
	public function getMainInput(){
		return _mainInput;
	}


	private function doStep():Void {
		_inStep = true;
		var delta = _gameProcessManager.getFrameDelta();
		if(!_gameProcessManager.isPaused()){ // pause can
			this.trigger(new FEvent(FGame.BEFORE_STEP));
		}

		for(c in _stepSubscribers){
			if(!_gameProcessManager.isPaused()){ // pause can
				c._doStep(delta);
			}
		}

		if(!_gameProcessManager.isPaused()){ //don't fire step events if we are paused.
			this._gameProcessManager.step();
		}
		if(!_gameProcessManager.isPaused()){ //don't fire step events if we are paused.
			this.trigger(new FEvent(FGame.AFTER_STEP));
		}
		if(!this._renderProcessManager.isPaused()) {
			this._renderProcessManager.step();
		}
		_inStep = false;

		// safer way to handle deferred functions, multi-threaded safe as well
		var deferredFunctions:List<Void->Void> = _deferredFunctionsArray.pop();
		_deferredFunctionsArray.add(deferredFunctions);
		for(func in deferredFunctions){
			func();
		}
		deferredFunctions.clear();

		//firmament.util.FLog.debug('Simulation: '+_gameProcessManager.getLastStepTime()+ ' Render: '+_renderProcessManager.getLastStepTime());
	}



	private function this_onEnterFrame (event:Event):Void {
		//firmament.util.FLog.debug('this is called.');
		//var start = haxe.Timer.stamp();
		this.doStep();
		//firmament.util.FLog.debug("step time: "+(haxe.Timer.stamp() - start));

	}

	public function getPoolManager(){
		return _poolManager;
	}

	/*
		Function: clearWorlds
		Destroys all worlds and entities

	*/
	public function clearWorlds(){
		for (world in _worldHash){
			world.destruct();
		}

		_worldHash = new Map();
	}

	public function clearCameras(){
		if(_cameras != null)
		for(camera in _cameras){
			camera.destruct();
		}
	}

	/*
		destroys or clears references to all entities, worlds, cameras, and processes.
	*/
	public function clearAll(){

		// --------------------------------------------
		// Deallocation and clean-up here
		Lib.current.stage.removeEventListener(Event.ENTER_FRAME, this_onEnterFrame);
		_gameProcessManager.pause();
		_renderProcessManager.pause();
		while(_stepSubscribers.length>0){
			_stepSubscribers.pop();
		}

		// _poolManager.destruct needs to happen before clear worlds
		// clear worlds deletes the world object, which is 
		// used by entities that are registered in pools
		_poolManager.destruct();
		clearWorlds();

		// This needs to be last as some components may be 
		// cleaned up in clearWorlds, if those use the scene
		// object then they would crash
		if(_currentScene!=null)_currentScene.destruct();
		_currentScene=null;

		// --------------------------------------------
		// New Object creation below here
		_stepSubscribers = new List();
		_gameProcessManager = new FProcessManager();
		_renderProcessManager = new FProcessManager();
		_cameras = new Map();
		_gameTimerManager = new FTimerManager();
		this._gameProcessManager.addProcess(_gameTimerManager);
		_poolManager = new FEntityPoolManager();
		//this.removeAllListeners();
		clearCameras();
		Lib.current.stage.addEventListener(Event.ENTER_FRAME, this_onEnterFrame);
		//firmament.util.FLog.debug("FGAME CLEARED-----------------------------------");
	}

	/**
	 * Returns the FTimerManager object for game timers
	 *
	 */
	public function getGameTimerManager(){
		return _gameTimerManager;
	}

	/**
	 * Adds a game timer.
	 * @param seconds - number of seconds until timer times out
	 *
	 */
	public function addGameTimer(seconds:Float, cb:Void->Void, ?scope:Dynamic=null){
		return _gameTimerManager.addTimer(seconds, cb, scope);
	}

	public function getInstanceName():String{
		return _name;
	}

	/**
	 * Loads a scene.
	 */
	public function loadScene(scene:FConfig){

		if(_inStep){
			var deferredFunctions:List<Void->Void> 
				= _deferredFunctionsArray.first();
			deferredFunctions.push(function(){
					loadScene(scene);
				}
			);
			return;
		}
		var instanceName = getInstanceName();
		clearAll();

		//firmament.util.FLog.debug("loadScene: Creating new scene");
		_currentScene = new FScene();
		//firmament.util.FLog.debug("loadScene: Loading instance data");
		_currentScene.init(scene,instanceName);
		return;
	}

	/**
	 * Switches to a preloaded a scene.
	*/
	public function switchScene(?name:String='main',?camName:String='main') {
		// Noop'd
		return null;
	}

	public function getCurrentScene(){
		return _currentScene;
	}

	/**
	 * Initializes the interpreter instance.
	 *
	 */
	public function initializeInterpreter(){
		_interpreter = new Interp();
		_interpreter.variables.set("Math",Math);
		_interpreter.variables.set("FGame",FGame);
		_interpreter.variables.set("FSoundtrackManager",firmament.sound.FSoundtrackManager);
		_interpreter.variables.set("FCamera",FCamera);
        _interpreter.variables.set("FRepository",FRepository);
        _interpreter.variables.set("FConfig",FConfig);
        _interpreter.variables.set("FDataLoader",FDataLoader);
        _interpreter.variables.set("FLog",FLog);
        _interpreter.variables.set("FEntityFactory",firmament.core.FEntityFactory);
        _interpreter.variables.set("Std",Std);
	}
	/**
	 * returns the interpreter for this fgame instance.
	 *
	 */
	public function getInterpreter(){
		return _interpreter;
	}

    public function execProgram(program:hscript.Expr, scope:Dynamic=null){
        _interpreter.variables.set('this',scope);
        return _interpreter.execute(program);
    }

	public function eval(script:String, scope:Dynamic=null){
		var parser = new hscript.Parser();
		var program = parser.parseString(script);
		return execProgram(program, scope);
	}

	public function executeFile(fileName:String, scope:Dynamic=null){
		return eval(FDataLoader.loadFile(fileName), scope);
	}

	/**
	 * Schedule a function to execute after a step is complete.
	 */
	public function doAfterStep(func:Void->Void){
		// if we are already running the deferred loop, then
		// we need to execute this immediately, otherwise defer
		// by adding onto the function array
		var deferredFunctions:List<Void->Void> 
				= _deferredFunctionsArray.first();
		deferredFunctions.push(func);
	}

	override public function destruct(){
		Lib.current.stage.removeEventListener(Event.ENTER_FRAME, this_onEnterFrame);
		_gameProcessManager.pause();
		_renderProcessManager.pause();
		if(_currentScene!=null)_currentScene.destruct();
		_currentScene=null;

		while(_stepSubscribers.length>0){
			_stepSubscribers.pop();
		}
		_stepSubscribers = null;

		clearWorlds();
		_gameProcessManager = null;
		_renderProcessManager = null;
		_cameras = null;
		_gameTimerManager = null;

		_poolManager.destruct();
		_poolManager = null;
		//this.removeAllListeners();
		clearCameras();
		FGame._instances.remove(_name);
		_cameras = null;
		//firmament.util.FLog.debug("FGAME DESTRUCTED-----------------------------------");
		super.destruct();
	}




}
