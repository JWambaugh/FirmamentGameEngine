
package firmament.core;

import firmament.core.FTilesheet;
import firmament.core.FCamera;
import flash.events.Event;
import openfl.display.Tilesheet;

class FTilesheetRenderHelper {
	private static var _instance;

	var drawList:Map<Int,Array<Float>>;
	var initializedCameras:Array<FCamera>;


	private function new(){
		drawList = new Map<Int,Array<Float>>();
		initializedCameras = new Array<FCamera>();
	}

	public static function getInstance(){
		if(_instance == null){
			_instance = new FTilesheetRenderHelper();
		}
		return _instance;
	}


	public function addToDrawList(tilesheet:FTilesheet, list:Array<Float>){
		var id = tilesheet.getId();
		if(!drawList.exists(id)){
			drawList.set(id,new Array<Float>());
		}
		drawList.set(id,drawList.get(id).concat(list));
	}

	/*
		Function: initCamera
		initializes itself on the specified camera if not already done.
	*/
	public function initCamera(camera:FCamera){
		if(isCameraInitialized(camera)){
			return;
		}
		this.initializedCameras.push(camera);
		camera.addEventListener(FCamera.BEFORE_RENDER_EVENT,this.preRender);
		camera.addEventListener(FCamera.AFTER_RENDER_EVENT,this.postRender);
	}

	public function preRender(e:Event){
		this.drawList = new Map<Int,Array<Float>>();
	}

	public function postRender(e:Event){

		for(tilesheet in FTilesheetManager.getInstance().getOrderedTilesheets()){
			if(tilesheet == null)continue;
			var list = this.drawList.get(tilesheet.getId());
			if(list ==null){
				continue;
			}
			var camera = cast(e.currentTarget,FCamera);
			tilesheet.drawTiles(camera.graphics, list, true, 
			Tilesheet.TILE_TRANS_2x2 | Tilesheet.TILE_ALPHA |Tilesheet.TILE_RGB);
		}
		
	}


	private function isCameraInitialized(camera:FCamera){
		for(c in initializedCameras){
			if(c == camera) return true;
		}
		return false;
	}

}