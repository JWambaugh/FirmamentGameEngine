package firmament.core;
import nme.display.Tilesheet;
import firmament.core.FTilesheetManager;
import nme.display.BitmapData;
import nme.geom.Rectangle;
import nme.geom.Point;



/**
 * Class: FTilesheet
 * @author jordan
 */
class FTilesheet extends Tilesheet {
	

	private var id:Int;
	private var definitionFileName:String;
	private var imageFileName:String;
	private var _renderPriority:Float;
	private var _labelMap:Hash<Int>;
	
	private var _rects:Array<Rectangle>;
	public function new (inImage:BitmapData) {
		super(inImage);
		var tm = FTilesheetManager.getInstance();
		this.id = tm.genTilesheetId();
		tm.addTileSheet(this);
		_rects = new Array<Rectangle>();
		_renderPriority = 0;
		_labelMap = new Hash();
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
	override public function addTileRect(rectangle:Rectangle, centerPoint:Point = null){
		super.addTileRect(rectangle,centerPoint);
		_rects.push(rectangle);
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
	public function addTileRectWithLabel(rectangle:Rectangle, centerPoint:Point = null, label:String=null){
		super.addTileRect(rectangle,centerPoint);
		if(label!=null){
			//trace("LENGTH:"+_rects.length);
			_labelMap.set(label,_rects.length);
		}
		_rects.push(rectangle);
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
