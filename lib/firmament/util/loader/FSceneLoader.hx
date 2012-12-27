
package firmament.util.loader;
import firmament.util.loader.FDataLoader;
import firmament.core.FGame;
import nme.Lib;
import firmament.core.FCamera;
import firmament.util.FConfigHelper;
import firmament.util.loader.FEntityLoader;
import nme.events.Event;

class FSceneLoader {
	public static function loadScene(scene:Dynamic){
		if(Std.is(scene,String)){
			scene = FDataLoader.loadData(scene);
		}

		var game = FGame.getInstance();
		var stage = Lib.current.stage;
		var sceneHelper = new FConfigHelper(scene);
		//clear any previous scene
		game.clearAll();


		//initialize cameras
		if(Std.is(scene.cameras,Array)){
			for(cameraDef in cast(scene.cameras,Array<Dynamic>)){
				var c = new FConfigHelper(cameraDef);
				var camera = new FCamera();
				
				camera.init(cameraDef);
				
				game.addCamera(c.getNotNull('name',String),camera);
				stage.addChild(camera);
			}
		}else{
			var camera = new FCamera();
			camera.init({});
			game.addCamera("main",camera);
			stage.addChild(camera);
			//resize camera when the stage gets resized
			stage.addEventListener(Event.RESIZE, function(e:Event) { 
				camera.resizeToStage(); 
			});
		}

		//initialize specified world types
		if(Reflect.isObject(scene.worlds)){
			for(worldName in Reflect.fields(scene.worlds)){
				var worldConfig = Reflect.field(scene.worlds,worldName);
				game.getWorld(worldName).init(worldConfig);
			}
		}

		var loader = FEntityLoader.getInstance();

		//initialize pools
		if(Std.is(scene.entityPools,Array)){
			for(poolConfig in cast(scene.entityPools,Array<Dynamic>)){
				var pool = new FConfigHelper(poolConfig);
				//load non-map entities we need
				//trace("entFile: "+pool.getNotNull('entityFile',String));
				loader.loadPool(pool.getNotNull('entityFile',String),pool.get("amount",Int,10));
			}
		}

		//load map
		if(Std.is(scene.map,String)){
			
			loader.loadMap(scene.map);
		}


	}


	

}