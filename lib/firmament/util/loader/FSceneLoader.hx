
package firmament.util.loader;
import firmament.core.FCamera;
import firmament.core.FGame;
import firmament.sound.FSoundManager;
import firmament.util.loader.FDataLoader;
import firmament.util.loader.FEntityLoader;
import flash.events.Event;
import flash.Lib;

class FSceneLoader {
	
	/**
	 * Deprecated. Use FGame.loadScene instead.
	 *
	 */
	public static function loadScene(scene:Dynamic,?gameInstanceName:String='main'){
		return FGame.getInstance(gameInstanceName).loadScene(scene);
	}


	

}