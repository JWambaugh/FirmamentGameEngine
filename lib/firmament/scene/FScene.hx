package firmament.scene;
import flash.events.EventDispatcher;
import flash.events.Event;
import firmament.util.FConfigHelper;
import firmament.scene.FSceneComponent;
import firmament.util.loader.FDataLoader;
import firmament.core.FGame;
import flash.Lib;
import firmament.core.FCamera;
import firmament.util.loader.FEntityLoader;
import firmament.sound.FSoundManager;


class FScene extends EventDispatcher{

	var _components : Array<FSceneComponent>;
	var _gameInstanceName:String;
	public function new(){
		super();
		var _components = new Array();
	}

	public function init(config:Dynamic, ?gameInstanceName:String='main'){
		_gameInstanceName = gameInstanceName;
		if(Std.is(config,String)){
			config = FDataLoader.loadData(config);
		}

		var game = FGame.getInstance(gameInstanceName);
		var stage = Lib.current.stage;
		var configHelper = new FConfigHelper(config);
		//clear any previous config
		game.clearAll();


		//initialize cameras
		if(Std.is(config.cameras,Array)){
			for(cameraDef in cast(config.cameras,Array<Dynamic>)){
				var c = new FConfigHelper(cameraDef);
				var camera = new FCamera();
				
				camera.init(cameraDef);
				
				game.addCamera(c.getNotNull('name',String),camera);
				stage.addChild(camera);
			}
		}else{
			var camera = new FCamera(100,100,gameInstanceName);
			camera.init({});
			game.addCamera("main",camera);
			stage.addChild(camera);
			//resize camera when the stage gets resized
			stage.addEventListener(Event.RESIZE, function(e:Event) { 
				camera.resizeToStage(); 
			});
		}

		//initialize specified world types
		if(Reflect.isObject(config.worlds)){
			for(worldName in Reflect.fields(config.worlds)){
				var worldConfig = Reflect.field(config.worlds,worldName);
				game.getWorld(worldName).init(worldConfig);
			}
		}

		var loader = FEntityLoader.getInstance();

		//initialize pools
		if(Std.is(config.entityPools,Array)){
			for(poolConfig in cast(config.entityPools,Array<Dynamic>)){
				var pool = new FConfigHelper(poolConfig);
				//load non-map entities we need
				//trace("entFile: "+pool.getNotNull('entityFile',String));
				loader.loadPool(pool.getNotNull('entityFile',String),pool.get("amount",Int,10));
			}
		}

		//load sounds
		if(Std.is(config.sounds,Array)){
			for(sound in cast(config.sounds,Array<Dynamic>)){
				if(Std.is(sound,String)){
					if(FSoundManager.getSound(sound) == null){
						trace("config loader warning: Sound not found: "+sound);
					}
				}
				
			}
		}

		//load map
		if(Std.is(config.map,String)){
			
			loader.loadMap(config.map,null,gameInstanceName);
		}
	}
}