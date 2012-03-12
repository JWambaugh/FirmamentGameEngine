package com.firmamentengine.games;

import nme.display.StageAlign;
import nme.display.StageScaleMode;
import nme.events.TimerEvent;
import nme.Lib;
import nme.events.Event;
import nme.display.Bitmap;
import nme.Assets;
import nme.text.TextField;
import nme.utils.Timer;

import com.firmamentengine.firmament.FPhysicsEntity;
import com.firmamentengine.firmament.FPhysicsWorld;
import com.firmamentengine.firmament.FCamera;
import com.firmamentengine.firmament.FGame;
import com.firmamentengine.firmament.FVector;
/**
 * ...
 * @author Jordan Wambaugh
 */

class Test 
{
	
	static public function main() 
	{
		#if (flash9 || flash10)
		haxe.Log.trace = function(v,?pos) { untyped __global__["trace"](pos.className+"#"+pos.methodName+"("+pos.lineNumber+"):",v); }
		#elseif flash
		haxe.Log.trace = function(v,?pos) { flash.Lib.trace(pos.className+"#"+pos.methodName+"("+pos.lineNumber+"): "+v); }
		#end
		var stage = Lib.current.stage;
		stage.align = StageAlign.TOP_LEFT;
		stage.scaleMode = StageScaleMode.NO_SCALE;
		
		// entry point
		var logo = new Bitmap (Assets.getBitmapData ("assets/sample.png"));
		var world = new FPhysicsWorld(new FVector(0, 10));
		for(x in 1...10){
		world.createEntity( {
			test:'blah'
			,position:new FVector(Math.random()*2-1, 0)
			,type:'dynamic'
			,sprite:logo
			,angle:Math.random()
			,shapes:[
				{
					type:'box'
					,width:1
					,height:1
					,restitution:1
					,density:.5
					,friction:.5
				}
				
			]
		});
		}
		world.createEntity( {
			test:'blah'
			,position:new FVector(.5, 2)
			,type:'static'
			,shapes:[
				{
					type:'box'
					,width:10
					,height:.2
				}
				
			]
		});
		
		var camera = new FCamera(500, 500);
		camera.setZoom(90);
		var map = new FCamera(200, 200);
		map.x = 500;
		map.setZoom(20);
		stage.addChild(camera);
		stage.addChild(map);
		var game = new FGame();
		game.addWorld(world);
		game.addCamera(camera);
		game.addCamera(map);
		var field = new TextField();
		field.text = 'This is working!?';
		stage.addChild(field);
		
		
	}
	
	
}