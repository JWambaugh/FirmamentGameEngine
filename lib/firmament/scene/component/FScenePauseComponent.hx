
package firmament.scene.component;

import firmament.core.FConfig;
import firmament.core.FEvent;
import firmament.core.FGame;
import firmament.process.base.FProcessManager;
import firmament.scene.FSceneComponent;
import firmament.util.FLog;

class FScenePauseComponent extends FSceneComponent {

	private var _processManager:FProcessManager;

	public function new(gameInstance:FGame) 
	{
		super(gameInstance);
	}

	override public function init(config:FConfig):Void {
		var game:FGame = _scene.getGameInstance();
		_processManager = game.getProcessManager();

		var listeners:FConfig = config.getNotNull("listen");
		for( event in listeners.fields() ) {
			var value = listeners.getNotNull( event, String );
			switch( event ) {
				case "pause": on( _scene, value, this.onPause );
				case "unpause": on( _scene, value, this.onUnPause );
				case "toggle": on( _scene, value, this.onToggle );
				default: 
					FLog.error( "<" +event+ "> is not one of pause, unpause, or toggle" );
					throw "Error: <" +event+ "> is not one of pause, unpause, or toggle";
			}
		}
	}

	public function onPause(e:FEvent){
		_processManager.pause();
	}

	public function onUnPause(e:FEvent){
		_processManager.unPause();
	}

	public function onToggle(e:FEvent){
		if( _processManager.isPaused() ) {
			_processManager.unPause();
		} else {
			_processManager.pause();
		}
	}

	public function getType() {
		return "pause";
	}
}