package com.firmamentengine.firmament;

import box2D.collision.B2WorldManifold;
import nme.display.StageAlign;
import nme.display.StageScaleMode;
import nme.Lib;
import box2D.dynamics.B2World;
import box2D.common.math.B2Vec2;

import com.firmamentengine.firmament.FRenderable;
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
		
		var world = new B2World(new B2Vec2(0,.5) ,true);
	}
	
}