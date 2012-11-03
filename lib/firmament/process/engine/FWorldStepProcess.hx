
package firmament.process.engine;
import firmament.process.base.FProcess;
import firmament.core.FWorld;
import firmament.core.FGame;
class FWorldStepProcess extends FProcess {

	private var world:FWorld;
	public function new(world:FWorld){
		this.world = world;
		super();
	}

	override public function step(){
		if(FGame.getInstance().enableSimulation){
			this.world.step();
		}
	}
	

}