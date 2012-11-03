package firmament.process.engine;
import firmament.process.base.FProcess;
import firmament.core.FCamera;
import firmament.core.FGame;

class FCameraRenderProcess extends FProcess {
	private var camera:FCamera;

	public function new(camera:FCamera){
		this.camera = camera;
		super();
	}

	override public function step(){
		this.camera.render(FGame.getInstance().getWorlds());
	}
	

}