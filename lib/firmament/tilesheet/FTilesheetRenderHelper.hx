
package firmament.tilesheet;

import firmament.tilesheet.FTilesheet;
import firmament.core.FCamera;
import flash.events.Event;
import openfl.display.Tilesheet;


typedef DrawItem={
	var tilesheet:FTilesheet;
	var list:Array<Float>;
	var positionZ:Float;
}

class FTilesheetRenderHelper {
	private static var _instance;

	var drawList:Array<DrawItem>;
	var initializedCameras:Array<FCamera>;
	var drawItemPool:Array<DrawItem>;


	private function new(){
		drawList = new Array();
		drawItemPool = new Array();
		initializedCameras = new Array<FCamera>();
	}

	public static function getInstance(){
		if(_instance == null){
			_instance = new FTilesheetRenderHelper();
		}
		return _instance;
	}


	public function addToDrawList(tilesheet:FTilesheet, list:Array<Float>,positionZ:Float){
		var di:DrawItem=null;
		if(drawItemPool.length>0){ //draw from pool if available
			di = drawItemPool.pop();
			di.tilesheet = tilesheet;
			di.list = list;
			di.positionZ = positionZ;
		}else{
			di = {tilesheet:tilesheet,list:list,positionZ:positionZ};
		}
		drawList.push(di);
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
		//move all draw items back to the pool
		while(drawList.length>0){
			drawItemPool.push(drawList.pop());
		}
	}

	public function postRender(e:Event){
		if(drawList.length < 1) return;
		//sort draw list by z position first, then tilesheet
		drawList.sort(function(a:DrawItem,b:DrawItem){
			if(a.positionZ > b.positionZ) return 1;
			if(a.positionZ < b.positionZ) return -1;
			if(a.tilesheet.getId() > b.tilesheet.getId()) return 1;
			if(a.tilesheet.getId() < b.tilesheet.getId()) return -1;
			else return 0;
		});
		var camera = cast(e.currentTarget,FCamera);
		var currentSheet:FTilesheet = drawList[0].tilesheet;
		var l:Array<Float> = new Array();
		var i:Int=0;
		while(true){
			var di:DrawItem = drawList[i];
			
			if(di.tilesheet == currentSheet){
				l = l.concat(di.list);
			}else{
				currentSheet.drawTiles(camera.graphics, l, true, 
				Tilesheet.TILE_TRANS_2x2 | Tilesheet.TILE_ALPHA |Tilesheet.TILE_RGB);
				l = di.list.copy();

				currentSheet = di.tilesheet;
			}
			
			if(++i==drawList.length){
				currentSheet.drawTiles(camera.graphics, l, true, 
				Tilesheet.TILE_TRANS_2x2 | Tilesheet.TILE_ALPHA |Tilesheet.TILE_RGB);
				break;
			}
		
		}
		
	}


	private function isCameraInitialized(camera:FCamera){
		for(c in initializedCameras){
			if(c == camera) return true;
		}
		return false;
	}

}