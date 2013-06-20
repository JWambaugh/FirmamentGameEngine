
package firmament.core;

import firmament.core.FAnimation;
import firmament.util.loader.FDataLoader;

class FAnimationManager {

	private static  var _instance:FAnimationManager;

	private var _animationsHash:Map<String,FAnimation>;

	private function new(){
		_animationsHash = new Map<String,FAnimation>();

	}

	public static function getInstance():FAnimationManager{
		if(_instance == null){
			_instance = new FAnimationManager();
		}
		return _instance;
	}


	public function addAnimation(fileName:String,animation:FAnimation){
		_animationsHash.set(fileName,animation);
	}

	/**
	 * Function: getAnimationByFileName
	 * returns an animation defined in the specified file. Will either load from file or internal cache.
	 */
	public function getAnimationByFileName(fileName:String):FAnimation{
		if(_animationsHash.exists(fileName)){
			return _animationsHash.get(fileName);
		}

		var data:Dynamic = FDataLoader.loadData(fileName);
		if(data == null){
			throw "data laoded from "+fileName+' is null';
		}
		var a:FAnimation = new FAnimation();
		a.init(data);
		_animationsHash.set(fileName,a);
		return a;
	}



	

}