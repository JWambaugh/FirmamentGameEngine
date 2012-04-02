package firmament.core;
import firmament.core.FRenderable;
import nme.display.Bitmap;
/**
 * ...
 * @author Jordan Wambaugh
 */

class FEntity extends FRenderable
{
	var world:FWorld;
	var currentImage:Bitmap;
	
	public function new(world:FWorld,config:Dynamic) 
	{
		super();
		this.world = world;
		world.addEntity(this);
		if (Std.is(config.sprite, Bitmap)) {
			this.currentImage = config.sprite;
			this.renderer = new FSpriteRenderer();
		}
		if (Std.is(config.imageScale, Int) {
				this.imageScale = config.imageScale;
		}
		else this.renderer = new FWireframeRenderer();
	}
	
	override public function getCurrentImage():Bitmap {
		return this.currentImage;
	}
	
	
	
}