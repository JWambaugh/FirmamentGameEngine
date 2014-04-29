package firmament.scene;

import flash.events.EventDispatcher;
import flash.events.Event;
import firmament.util.FConfigHelper;
import firmament.scene.FScene;
import firmament.core.FGame;
import firmament.core.FObject;
import firmament.core.FConfig;

/*
	Class: FScene Component


	FSceneComponents are the components that make up an scene.
	@author Jordan Wambaugh
 */

class FSceneComponent extends FObject
{

	private var _config:Dynamic;
	private var _componentKey:String;
	private var _configHelper:FConfigHelper;
	private var _scene:FScene;
	private var _gameInstance:FGame;
	
	public function new(gameInstance:FGame) 
	{
		_configHelper = null;
		super();
		_gameInstance = gameInstance;


	}
	
	public function init(config:FConfig):Void {
		throw "This needs to be overwritten in a subclass.";
	}
	

	public function setConfig(c:Dynamic){
		_config = c;
	}

	public function getConfig(){
		return _config;
	}

	/**
	 * Returns a config helper object for the component's config
	 */
	public function getConfigHelper():FConfigHelper{
		if(_configHelper == null){
			_configHelper = new FConfigHelper(_config);
		}
		return _configHelper;
	}

	/**
	 * Should be overridden to implement a destructor
	 */
	override public function destruct(){
		super.destruct();
	}

	public function setComponentKey(key:String){
		_componentKey = key;
	}

	public function setScene(scene:FScene){
		_scene = scene;
	}



}