package firmament.scene;
import flash.events.EventDispatcher;
import flash.events.Event;
import firmament.util.FConfigHelper;
import firmament.scene.FScene;

/*
	Class: FEntity Component


	FEntityComponents are the components that make up an entity.
	@author Jordan Wambaugh
 */

class FSceneComponent extends EventDispatcher
{

	private var _config:Dynamic;
	private var _componentKey:String;
	private var _configHelper:FConfigHelper;
	private var _scene:FScene;
	
	public function new() 
	{
		_configHelper = null;
		super();

	}
	
	public function init(config:Dynamic):Void {
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
	public function destruct(){
	}
	

	

	public function setComponentKey(key:String){
		_componentKey = key;
	}

	public function setScene(scene:FScene){
		_scene = scene;
	}



}