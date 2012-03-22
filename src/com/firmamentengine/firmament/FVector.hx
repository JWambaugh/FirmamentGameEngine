package com.firmamentengine.firmament;

import box2D.common.math.B2Vec2;
/**
 * ...
 * @author Jordan Wambaugh
 */

class FVector extends B2Vec2
{

	
	public function new(x:Float =0,y:Float =0) 
	{
		super(x, y);
	}
	
	
	public function toString() {
		return this.x + ',' + this.y;
	}
}