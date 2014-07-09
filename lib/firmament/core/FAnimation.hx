package firmament.core;

import firmament.tilesheet.FTilesheet;
import firmament.tilesheet.FTilesheetManager;

class FAnimation {

	private var _tilesheet:FTilesheet;
	private var _frames:Array<Int>;
	private var _timeBetweenFrames:Float;

	private var _config:Dynamic;
	
	public function new(){
		_frames = new Array<Int>();
	}

	public function init(config:Dynamic){
		if(Std.is(config.tilesheetFile,String)){
			_tilesheet = FTilesheetManager.getInstance().getTilesheetFromDefinitionFile(config.tilesheetFile);
		}
		else if(Std.is(config.tilesheet,FTilesheet)){
			_tilesheet = config.tilesheet;
		} else {
			throw "Tilesheet not provided";
		}

		if(Std.is(config.frames,Array)){
			for(el in cast(config.frames,Array<Dynamic>)){
				if(Std.is(el,String)){
					el = _tilesheet.getTileNumber(el);
				}
				_frames.push(el);
			}
		}else{
			throw "Frames not provided";
		}

		if(Std.is(config.timeBetweenFrames,Float)){
			_timeBetweenFrames = config.timeBetweenFrames;
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
	 * Given the provided frame index, it returns the next one in the animation sequence.
	 */
	public function getNextFrame(currentFrame:Int):Int{
		return (currentFrame+1)%_frames.length;
	}


	

}