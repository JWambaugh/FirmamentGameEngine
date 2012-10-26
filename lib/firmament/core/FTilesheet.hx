package firmament.core;
import nme.display.Tilesheet;

/**
 * ...
 * @author jordan
 */
class FTilesheet extends Tilesheet {
	
	public function new (inImage:BitmapData) {
		
		super(inImage);
		
	}
	
	override public function addTileRect(rectangle:Rectangle, label="", centerPoint:Point = null){
	
	
		super.addTileRect(rectangle,centerPoint);
	}
	
	
	

}
