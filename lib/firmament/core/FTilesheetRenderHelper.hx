
package firmament.core;

import firmament.core.FTilesheet;
import firmament.core.FCamera;

class FTilesheetRenderHelper {
	private static var _instance;

	var drawList:IntHash<Array<Float>>;
	var initializedCameras:Array<FCamera>;


	private function new(){
		drawList = new IntHash<Array<Float>>();
		initializedCameras = new Array<FCamera>();
	}

	public static function getInstance(){
		if(_instance == null){
			_instance = new FTilesheetRenderHelper();
		}
		return _instance;
	}



	/*
		Function: initCamera
		initializes itself on the specified camera if not already done.
	*/
	public function initCamera(camera:FCamera){
		if(isCameraInitialized(camera)){
			return;
		}

	}


	private function isCameraInitialized(camera:FCamera){
		for(c in initializedCameras){
			if(c == camera) return true;
		}
		return false;
	}

}