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
	public function new (inImage:BitmapData) {
		super(inImage);
		this.id = FTilesheetManager.getInstance().genTilesheetId();

	}


	public function getId(){
		return this.id;
	}


	public function getFileName():String{
		return this.definitionFileName;
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
	override public function addTileRect(rectangle:Rectangle,centerPoint:Point = null){
		super.addTileRect(rectangle,centerPoint);
	}
	
	
	

}
