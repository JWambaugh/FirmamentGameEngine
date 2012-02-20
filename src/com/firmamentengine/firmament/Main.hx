package com.firmamentengine.firmament;

import box2D.collision.B2WorldManifold;
import nme.display.StageAlign;
import nme.display.StageScaleMode;
import nme.Lib;


import com.firmamentengine.firmament.FRenderable;
import com.firmamentengine.firmament.FPhysicsWorld;
/**
 * ...
 * @author Jordan Wambaugh
 */

class Main 
{
	
	static public function main() 
	{
		var stage = Lib.current.stage;
		stage.scaleMode = StageScaleMode.NO_SCALE;
		stage.align = StageAlign.TOP_LEFT;
		// entry point
		
		var world = new FPhysicsWorld(new FVector(0,.5));
	}
	
}