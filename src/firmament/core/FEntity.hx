package firmament.core;
import firmament.core.FRenderable;
import nme.display.BitmapData;
import nme.display.Tilesheet;
import nme.geom.Rectangle;
import firmament.core.FTilesheetRenderer;
import nme.geom.Point;
/**
 * ...
 * @author Jordan Wambaugh
 */

class FEntity extends FRenderable
{
	var world:FWorld;
	var currentImage:BitmapData;
	var tilesheet:Tilesheet;
	public function new(world:FWorld,config:Dynamic) 
	{
		super();
		this.world = world;
		world.addEntity(this);
		if (Std.is(config.sprite, BitmapData)) {
			this.setCurrentImage(config.sprite);
			this.renderer = new FTilesheetRenderer();
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
	
	public function setCurrentImage(i:BitmapData){
			this.currentImage=i;
			tilesheet = new Tilesheet(i);
			tilesheet.addTileRect(
			new Rectangle (0, 0, i.width, i.height),new Point(i.width/2,i.height/2));
	}
	
	override public function getTilesheet():Tilesheet{
		return this.tilesheet;
	}
	
	
	
}