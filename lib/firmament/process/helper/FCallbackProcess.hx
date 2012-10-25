package firmament.process.helper;

import firmament.process.base.FProcess.hx;

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
		if(Std.is(this.config.beforeStart,FProcessManager->Void)){
			this.config.beforeStart(pm);
		}
	}

	override public function step(){
		if(Std.is(this.config.step,Void->Bool)){
			var res=this.config.step();
			if(res == false){
				this._isComplete=true ;
			}
		}
	}

	override public function afterFinish(){
		
	}

}