package firmament.core;

import firmament.core.FTilesheet;
import firmament.core.FTilesheetManager;

class FAnimation {

	private var _tilesheet:FTilesheet;
	private var _frames:Array<Int>;
	private var _timeBetweenFrames:Float;

	private var _config:Dynamic;
	
	public function new(){

	}

	public function init(config:Dynamic){
		if(Std.is(config.tilesheetFile,String)){
			_tilesheet = FTilesheetManager.getInstance().getTilesheetFromDifinitionFile(config.tilesheetFile);
		}
		else if(Std.is(config.tilesheet,FTilesheet)){
			_tilesheet = config.tilesheet;
		} else {
			throw "Tilesheet not provided";
		}

		if(Std.is(config.frames,Array)){
			for(el in cast(config.frames,Array<Dynamic>)){
				_frames.push(el);
			}
		}else{
			throw "Frames not provided";
		}

		if(Std.is(config.timeBeweenFrames,Float)){
			_timeBetweenFrames = config.timeBeweenFrames;
		}else {
			_timeBetweenFrames = 0.03;
		}
	}

	public function getTilesheet():FTilesheet{
		return _tilesheet;
	}

	public function setTilesheet(t:FTilesheet){
		_tilesheet = t;
	}

	public function getTimeBetweenFrames(){
		return _timeBetweenFrames;
	}

	/**
	 * Function: getTileIndexForFrame
	 * returns the tilesheet tile index for the specified animation frame
	 */
	public function getTileIndexForFrame(frame:Int):Int{
		if(frame >=_frames.length) throw 'Frame of '+frame+' doesn\'t exist';
		return _frames[frame];
	}

	/**
	 * Function: getNextFrame
	 * Given the provided fram index, it returns the next one in the animation sequence.
	 */
	public function getNextFrame(currentFrame:Int):Int{
		return (currentFrame+1)%_frames.length;
	}


	

}