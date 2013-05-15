package firmament.process.engine;
import firmament.process.base.FProcess;
import firmament.core.FCamera;
import firmament.core.FGame;

class FCameraRenderProcess extends FProcess {
	private var camera:FCamera;
	private var game:FGame;

	public function new(camera:FCamera,game:FGame){
		this.camera = camera;
		this.game = game;
		super();
	}

	override public function step(){
		this.camera.render(game.getWorlds());
	}
	

}