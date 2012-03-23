package com.firmamentengine.games;

import firmament.core.FInput;
import nice_json.Render;
import nme.display.Stage;
import nme.display.StageAlign;
import nme.display.StageScaleMode;
import nme.events.TimerEvent;
import nme.Lib;
import nme.events.Event;
import nme.events.MouseEvent;

import nme.display.Bitmap;
import nme.Assets;
import nme.text.TextField;
import nme.utils.Timer;

import firmament.core.FPhysicsEntity;
import firmament.core.FPhysicsWorld;
import firmament.core.FCamera;
import firmament.core.FGame;
import firmament.core.FVector;
import firmament.core.FInput;
import firmament.core.FTriangulator;

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
		var world = new FPhysicsWorld(new FVector(0, 5));
		for (x in 1...50) {
			for(y in 1...30){
				world.createEntity( {
					test:'blah'
					,position:new FVector(x-25, y)
					,type:'static'
					,sprite:logo
					,angle:0
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
		}
		var player = world.createEntity( {
			test:'blah'
			,position:new FVector(2, -2)
			,type:'dynamic'
			,sprite:logo
			,shapes:[
				{
					type:'circle'
					,radius:.5
					,restitution:1
				}
				
			]
		});
		
		var camera = new FCamera(stage.stageWidth,stage.stageHeight);
		
		var input = new FInput(stage);
		camera.setZoom(90);
		
		stage.addChild(camera);
		
		var game = new FGame();
		game.addWorld(world);
		game.addCamera(camera);
		
		var field = new TextField();
		field.text = 'This is working!?';
		stage.addChild(field);
		var input = new FInput(stage);
		game.addEventListener(FGame.BEFORE_STEP, function(e:Event) {
		//	trace(input.getStageX());
			if (input.isKeyPressed(38)) {
				player.setLinearVelocity(new FVector(player.getLinearVelocity().x,player.getLinearVelocity().y-.5));
			}
			if (input.isKeyPressed(40)) {
				player.setLinearVelocity(new FVector(player.getLinearVelocity().x,player.getLinearVelocity().y+.5));
			}
			if (input.isKeyPressed(37)) {
				player.setLinearVelocity(new FVector(player.getLinearVelocity().x-.5,player.getLinearVelocity().y));
			}
			if (input.isKeyPressed(39)) {
				player.setLinearVelocity(new FVector(player.getLinearVelocity().x+.5,player.getLinearVelocity().y));
			}
			if (input.isKeyPressed(65)) {
				camera.setZoom(camera.getZoom() * 1.02);
			}
			if (input.isKeyPressed(90)) {
				camera.setZoom(camera.getZoom() * .98);
			}
			camera.setPosition(player.getPosition());
		} );
		stage.addEventListener(Event.RESIZE, function(e:Event) { camera.resizeToStage(); } );
		
		var poly:Array<FVector> = [new FVector(0,0),new FVector(1,0),new FVector(1,1),new FVector(0,1)];
		trace(Render.as_json(poly));
		
		trace(Render.as_json(FTriangulator.getTriangles(poly)));
		
	}
	
	
}
