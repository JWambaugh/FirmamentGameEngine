//feel free to change this package name, but be sure to update your .nmml file when you do!
package [*PACKAGE_NAME*]; 



import firmament.util.loader.FSceneLoader;
import flash.display.StageAlign;
import flash.display.StageScaleMode;

import flash.Lib;



class [*PROJECT_NAME*]
{
	

	public function new(){
		
	}
	
	static public function main() 
	{
		
		
		
		var stage = Lib.current.stage;
		stage.scaleMode = StageScaleMode.NO_SCALE;
		stage.align = StageAlign.TOP_LEFT;

		
		FSceneLoader.loadScene("config/scenes/exampleScene.json");
		
	}

}