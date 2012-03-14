package com.firmamentengine.firmament;
import com.firmamentengine.firmament.FRenderable;
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
		if (Std.is(config.sprite, Bitmap)) {
			this.currentImage = config.sprite;
		}
	}
	
	override public function getCurrentImage():Bitmap {
		return this.currentImage;
	}
	
	
	
}