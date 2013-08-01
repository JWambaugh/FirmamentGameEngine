
package firmament.util.loader;
import firmament.util.loader.FDataLoader;
import firmament.core.FGame;
import flash.Lib;
import firmament.core.FCamera;
import firmament.util.FConfigHelper;
import firmament.util.loader.FEntityLoader;
import flash.events.Event;
import firmament.sound.FSoundManager;

class FSceneLoader {
	
	/**
	 * Deprecated. Use FGame.loadScene instead.
	 *
	 */
	public static function loadScene(scene:Dynamic,?gameInstanceName:String='main'){
		return FGame.getInstance(gameInstanceName).loadScene(scene);
	}


	

}