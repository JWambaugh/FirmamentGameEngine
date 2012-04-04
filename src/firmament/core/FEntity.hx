package firmament.core;
import firmament.core.FRenderable;
import nme.display.BitmapData;
/**
 * ...
 * @author Jordan Wambaugh
 */

class FEntity extends FRenderable
{
	var world:FWorld;
	var currentImage:BitmapData;
	
	public function new(world:FWorld,config:Dynamic) 
	{
		super();
		this.world = world;
		world.addEntity(this);
		if (Std.is(config.sprite, BitmapData)) {
			this.currentImage = config.sprite;
			this.renderer = new FSpriteRenderer();
		}else {
			this.renderer = new FWireframeRenderer();
		}
		if (Std.is(config.imageScale, Int)) {
				this.imageScale = config.imageScale;
		}
		else this.renderer = new FWireframeRenderer();
		
		
	}
	
	override public function getCurrentImage():BitmapData {
		return this.currentImage;
	}
	
	
	
}