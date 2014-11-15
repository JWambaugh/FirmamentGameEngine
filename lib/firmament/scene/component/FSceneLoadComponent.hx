
package firmament.scene.component;

import firmament.core.FConfig;
import firmament.core.FEvent;
import firmament.core.FGame;
import firmament.process.base.FProcessManager;
import firmament.scene.FSceneComponent;

class FSceneLoadComponent extends FSceneComponent {

	private var _processManager:FProcessManager;

	public function new(gameInstance:FGame) 
	{
		super(gameInstance);
	}

	override public function init(config:FConfig):Void {
		var game:FGame = _scene.getGameInstance();
		var events:FConfig = _config.getNotNull("listen");
		for( event in events.fields() ) {
		    events.getNotNull( "sceneFile",String ); // early failure detection
			on(_scene,event,function(e:FEvent){
					game.loadScene( events.getNotNull( "sceneFile",String ) );
				});
		}

	}
}