package firmament.core;

import firmament.core.FConfig;
import firmament.core.FObject;
import firmament.tilesheet.FTilesheet;
import firmament.tilesheet.FTilesheetManager;

class FAnimation extends FObject {

	private var _frames:Array<SpriteTilesheet>;
	private var _timeBetweenFrames:Float;

	private var _config:FConfig;
	
	public function new(){
		super();
		_frames = new Array<SpriteTilesheet>();
	}

	public function init(config:FConfig){
        _config = config;
		firmament.util.FLog.debug(Std.string(config));
	    var tm = FTilesheetManager.getInstance();
		if( !config.hasField("frames") ) {
			throw "Frames not provided";
		} else {
		    // Sometimes the images may not be loaded
		    // so queue images that have not been loaded
		    // yet for dynamic creation of a tilesheet
		    var frames:Array<String> = config.getNotNull("frames",Array);
			for(el in frames) {
				if( Std.is(el,String) ) {
				    var tdata = tm.getTilesheetForPath( cast el );
				    if( tdata == null ) {
				    	tm.queueTilesheetForPath(cast el);
				    }
				}
			}
			afterInit();
		}
	}

	/*override*/ public function afterInit(){
		var tm = FTilesheetManager.getInstance();
		// Creates fewer tilesheets
		// Dynamically create tilesheet and get references
		var frames:Array<String> = _config.getNotNull("frames");
		for( el in frames ) {
		    var tdata = tm.getTilesheetForQueuedPath( cast el );
		    if( tdata == null ) {
		    	throw "Error: <" + el + "> could not be found!";
		    }
			_frames.push( tdata );
		}
	}

	public function getTilesheetDataForFrame(index:Int) : SpriteTilesheet {
		return _frames[index];
	}

	public function getTimeBetweenFrames() : Float {
		return _config.get("timeBetweenFrames",Float,0.03);
	}

	/**
	 * Function: getTileIndexForFrame
	 * returns the tilesheet tile index for the specified animation frame
	 */
	public function getTileIndexForFrame(frame:Int) : Int {
		if(frame >=_frames.length) throw 'Frame of '+frame+' doesn\'t exist';
		var tdata = _frames[frame];
		return tdata.tileId;
	}

	/**
	 * Function: getNextFrame
	 * Given the provided frame index, it returns the next one in the animation sequence.
	 */
	public function getNextFrame(currentFrame:Int):Int{
		return (currentFrame+1)%_frames.length;
	}

}