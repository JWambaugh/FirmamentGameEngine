package com.firmamentengine.firmament;
import com.firmamentengine.firmament.FRenderer;
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
	
}