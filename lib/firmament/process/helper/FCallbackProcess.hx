package firmament.process.helper;

import firmament.process.base.FProcess;
import firmament.process.base.FProcessManager;
class FCallbackProcess extends FProcess{

	private var config:Dynamic;


	/*
		Constructor: new

		expects a config object with the following optional properties:
			beforeStart(processManager:FProcessManager) - Function that is called when process is added to the queue.function
			step():bool - Function executed each iteration of the process loop. Returns true if more processing required, false if done.
			afterFinish() - Function executed after processing is complete.
	*/
	public function new(config:Dynamic){
		super();
		this.config=config;
	}

	override public function beforeStart(pm:FProcessManager){
		if(Reflect.isFunction(this.config.beforeStart)){
			this.config.beforeStart(pm);
		}
	}

	override public function step(){
		if(Reflect.isFunction(this.config.step)){
			var res=this.config.step();
			if(res == false){
				this._isComplete=true ;
			}
		}
	}

	override public function afterFinish(){
		if(Reflect.isFunction(this.config.afterStart)){
			this.config.afterStart();
		}
	}

}