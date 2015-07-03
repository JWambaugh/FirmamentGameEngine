package firmament.tilesheet;
import openfl.display.Tilesheet;
import firmament.tilesheet.FTilesheetManager;
import flash.display.BitmapData;
import flash.geom.Rectangle;
import flash.geom.Point;



/**
 * Class: FTilesheet
 * @author jordan
 */
class FTilesheet extends Tilesheet {
	

	private var id:Int;
	private var definitionFileName:String;
	private var imageFileName:String;
	private var _renderPriority:Float;
	private var _labelMap:Map<String,Int>;
	
	private var _rects:Array<Rectangle>;
	public function new (inImage:BitmapData) {
		super(inImage);
		var tm = FTilesheetManager.getInstance();
		this.id = tm.genTilesheetId();
		tm.addTileSheet(this);
		_rects = new Array<Rectangle>();
		_renderPriority = 0;
		_labelMap = new Map();

		var stats = firmament.util.FStatistics.getInstance();
		if( !stats.hasProperty('Tilesheets') ) {
			stats.registerProp('Tilesheets','Int');
			stats.setProp('Tilesheets',0);
		}
		stats.setProp('Tilesheets',stats.getProp('Tilesheets')+1);
	}


	public function getId(){
		return this.id;
	}


	public function getDefinitionFileName():String{
		return this.definitionFileName;
	}

	public function getImageFileName():String{
		return this.imageFileName;
	}

	public function setImageFileName(name:String){
		this.imageFileName = name;
	}

	public function setDefinitionFileName(name:String){
		this.definitionFileName = name;
	}


	/**
	 * Function: addTileRect
	 *
	 * Adds a rectangle definition
	 *
	 * Parameters:
	 *	rectangle - Rectangle definition
	 *	centerPoint - the center point of the image
	 *
	 */
	override public function addTileRect(rectangle:Rectangle, centerPoint:Point = null):Int{
		var ret =super.addTileRect(rectangle,centerPoint);
		_rects.push(rectangle);
		return ret;
	}


	/**
	 * Function: addTileRect
	 *
	 * Adds a rectangle definition
	 *
	 * Parameters:
	 *	rectangle - Rectangle definition
	 *	centerPoint - the center point of the image
	 *
	 */
	public function addTileRectWithLabel(rectangle:Rectangle, centerPoint:Point = null, label:String=null):Int{
		super.addTileRect(rectangle,centerPoint);
		if(label!=null){
			//firmament.util.FLog.debug("LENGTH:"+_rects.length);
			_labelMap.set(label,_rects.length);
		}
		_rects.push(rectangle);
		return _rects.length -1;
	}
	
	public function getRectangle(i:Int){
		return _rects[i];
	}

	public function getRenderPriority(){
		return _renderPriority;
	}
	
	public function setRenderPriority(priority:Float){
		_renderPriority = priority;
	}

	public function getTileNumber(label:String):Int{
		return _labelMap.get(label);
	}

}
