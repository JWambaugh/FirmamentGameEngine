package firmament.scene;

import firmament.core.FConfig;
import firmament.core.FGame;
import firmament.core.FObject;
import firmament.scene.FScene;



/*
	Class: FScene Component


	FSceneComponents are the components that make up an scene.
	@author Jordan Wambaugh
 */

class FSceneComponent extends FObject
{

	private var _config:Dynamic;
	private var _componentKey:String;
	private var _scene:FScene;
	private var _gameInstance:FGame;
	
	public function new(gameInstance:FGame) 
	{
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