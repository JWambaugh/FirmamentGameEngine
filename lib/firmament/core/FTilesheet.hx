package firmament.core;
import nme.display.Tilesheet;

/**
 * Class: FTilesheet
 * @author jordan
 */
class FTilesheet extends Tilesheet {
	



	public function new (inImage:BitmapData) {
		super(inImage);
		
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
