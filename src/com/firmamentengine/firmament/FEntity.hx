package com.firmamentengine.firmament;
import com.firmamentengine.firmament.FRenderable;
/**
 * ...
 * @author Jordan Wambaugh
 */

class FEntity extends FRenderable
{
	var world:FWorld;
	public function new(world:FWorld,config:Dynamic) 
	{
		super();
		this.world = world;
	}
	
}