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

class FSceneComponent extends firmament.core.FComponent{

	private var _componentKey:String;
	private var _scene:FScene;
	
	public function new(gameInstance:FGame) 
	{
		super(gameInstance);
		_gameInstance = gameInstance;
	}
	
	


	/**
	 * Should be overridden to implement a destructor
	 */
	override public function destruct(){
		super.destruct();
	}

	public function setScene(scene:FScene){
		_scene = scene;
	}



}