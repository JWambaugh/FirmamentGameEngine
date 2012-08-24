package firmament.core;
import firmament.core.FRendererComponentInterface;
import box2D.collision.shapes.B2Shape;
import nme.display.BitmapData;
import nme.display.Tilesheet;
/**
 * ...
 * @author Jordan Wambaugh
 */

 /**
  * Class: FRenderable
  * 
  * Extends: 
	  * 
	  * <FWorldPositional>
  */
class FRenderable extends FWorldPositional
{
	var renderer:FRendererComponentInterface;
	var imageScale:Float;
	var zPosition:Float;
	
	/**
	 * Constructor: new
	 */
	public function new() 
	{
		super();
		this.imageScale = 100;
		this.zPosition = 0;
	}
	
	
	/**
	 * Function: getRenderer
	 * 
	 * Returns: 
	 * 
	 * 		<FRenderer> the object's current renderer 
	 */
	public function getRenderer():FRendererComponentInterface {
		return this.renderer;
	}
	
	public function setRenderer(r:FRendererComponentInterface) {
		this.renderer = r;
	}
	
	public function hasShapes():Bool {
		return false;
	}
	
	public function getShapes():Array<B2Shape> {
		return new Array<B2Shape>();
	} 
	
	public function getCurrentImage():BitmapData {
			return null;
	}
	public function getImageScale():Float {
		return this.imageScale;
	}
	
	/**
	 * Function: setZPosition
	 * 
	 * sets the objet's position on the z axis. This controls which objects display in front or behind. Lesser values are behind Larger values.
	 * 
	 */
	public function setZPosition(pos:Float):Void {

		this.zPosition = pos;
	}
	
	/**
	 * Function: getZPosition 
     * 
	 * Returns:
		 * Float the object's current position on the z axis.
	 * 
	 */
	public function getZPosition():Float {
		return this.zPosition;
	}
	
	/**
	 * Function: getTilesheet
	 * Returns:
		 * 
		 * Tilesheet the current tilesheet
	 */
	public function getTilesheet():Tilesheet{
		return null;
	}
	
}