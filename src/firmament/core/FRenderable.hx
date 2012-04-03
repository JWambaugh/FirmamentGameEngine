package firmament.core;
import firmament.core.FRenderer;
import box2D.collision.shapes.B2Shape;
import nme.display.Bitmap;
/**
 * ...
 * @author Jordan Wambaugh
 */

class FRenderable extends FWorldPositional
{
	var renderer:FRenderer;
	var imageScale:Float;
	var zPosition:Float;
	
	
	public function new() 
	{
		super();
		this.imageScale = 100;
		this.zPosition = 0;
	}
	
	
	
	public function getRenderer():FRenderer {
		return this.renderer;
	}
	
	public function setRenderer(r:FRenderer) {
		this.renderer = r;
	}
	
	public function hasShapes():Bool {
		return false;
	}
	
	public function getShapes():Array<B2Shape> {
		return new Array<B2Shape>();
	}
	
	public function getCurrentImage():Bitmap {
			return null;
	}
	public function getImageScale():Float {
		return this.imageScale;
	}
	

	public function setZPosition(pos:Float):Void {

		this.zPosition = pos;
	}
	public function getZPosition():Float {
		return this.zPosition;
	}
	
}