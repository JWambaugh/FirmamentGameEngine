
package firmament.process.engine;
import firmament.process.base.FProcess;
import firmament.world.FWorld;
import firmament.core.FGame;
class FWorldStepProcess extends FProcess {

	private var world:FWorld;
	private var game:FGame;
	public function new(world:FWorld,game:FGame){
		this.world = world;
		this.game = game;
		super();
	}

	override public function step(delta:Float){
		if(game._enableSimulation){
			this.world.step();
		}
	}
	

}