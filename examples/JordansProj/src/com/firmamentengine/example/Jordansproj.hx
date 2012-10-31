//feel free to change this package name, but be sure to update your .nmml file when you do!
package com.firmamentengine.example; 

import firmament.core.FCamera;
import firmament.core.FGame;
import firmament.core.FBox2DWorld;
import firmament.core.FVector;

import nme.display.StageAlign;
import nme.display.StageScaleMode;
import nme.Lib;
import nme.utils.WeakRef;

import nme.display.Sprite;
import nme.display.Bitmap;
import nme.text.TextField;
import nme.events.MouseEvent;
import nme.Assets;
import nme.events.Event;
import firmament.utils.FAutoCrop;
import firmament.utils.loader.FEntityLoader;
import firmament.core.FEntityFactory;

import firmament.process.helper.FCallbackProcess;

//all entities must be imported somewhere to be compiled


class Jordansproj
{
	
	static public function main() 
	{
		
			#if (flash9 || flash10)
		haxe.Log.trace = function(v,?pos) { untyped __global__["trace"](pos.className+"#"+pos.methodName+"("+pos.lineNumber+"):",v); }
		#elseif flash
		haxe.Log.trace = function(v,?pos) { flash.Lib.trace(pos.className+"#"+pos.methodName+"("+pos.lineNumber+"): "+v); }
		#end
		
		trace("blah");
		
		var stage = Lib.current.stage;
		stage.scaleMode = StageScaleMode.NO_SCALE;
		stage.align = StageAlign.TOP_LEFT;
		
		
		// create our camera
		var camera = new FCamera(stage.stageWidth, stage.stageHeight);
		
		//resize camera when the stage gets resized
		stage.addEventListener(Event.RESIZE, function(e:Event) { camera.resizeToStage(); } );
		
		//add camera to the stage so it's visible
		stage.addChild(camera);
		
		//set up our game object
		var game = FGame.instance();
		game.addCamera("main",camera);
		
		//set zoom to 100 (default) play with this!
		camera.setZoom(100);
		
		//load our map!
		var loader:FEntityLoader = FEntityLoader.getInstance();
		
		loader.loadMap("config/maps/exampleMap.json");

	
	}
	
}