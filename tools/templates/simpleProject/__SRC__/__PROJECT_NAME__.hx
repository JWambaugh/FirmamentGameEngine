//feel free to change this package name, but be sure to update your .nmml file when you do!
package [*PACKAGE_NAME*]; 



import firmament.util.loader.FSceneLoader;
import nme.display.StageAlign;
import nme.display.StageScaleMode;

import nme.Lib;



class [*PROJECT_NAME*]
{
	

	public function new(){
		
	}
	
	static public function main() 
	{
		//make traces go to flash log
		#if (flash9 || flash10)
		haxe.Log.trace = function(v,?pos) { untyped __global__["trace"](pos.className+"#"+pos.methodName+"("+pos.lineNumber+"):",v); }
		#elseif flash
		haxe.Log.trace = function(v,?pos) { flash.Lib.trace(pos.className+"#"+pos.methodName+"("+pos.lineNumber+"): "+v); }
		#end
		
		
		var stage = Lib.current.stage;
		stage.scaleMode = StageScaleMode.NO_SCALE;
		stage.align = StageAlign.TOP_LEFT;

		
		FSceneLoader.loadScene("config/scenes/exampleScene.json");
		
	}

}