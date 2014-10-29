package firmament.scene;
import flash.events.Event;
import firmament.core.FObject;
import firmament.core.FEvent;
import firmament.util.FConfigHelper;
import firmament.scene.FSceneComponent;
import firmament.util.loader.FDataLoader;
import firmament.core.FGame;
import flash.Lib;
import firmament.core.FCamera;
import firmament.util.loader.FEntityLoader;
import firmament.sound.FSoundManager;
import firmament.scene.FSceneComponentFactory;

class FScene extends FObject{

	var _components : Array<FSceneComponent>;
	var _gameInstanceName:String;
	var _game:FGame;

	/**
	 * event fired after all scene components are initialized.
	 */
	public static var COMPONENTS_INITIALIZED = "componentsInit"; 
	public function new(){
		super();
		_components = new Array();
	}

	public function init(config:Dynamic, ?gameInstanceName:String='main'){
		_gameInstanceName = gameInstanceName;
		if(Std.is(config,String)){
			config = FDataLoader.loadData(config);
		}

		_game = FGame.getInstance(gameInstanceName);
		var stage = Lib.current.stage;
		var configHelper = new FConfigHelper(config);

		
		//initialize cameras
		if(Std.is(config.cameras,Array)){
			for(cameraDef in cast(config.cameras,Array<Dynamic>)){
				var c = new FConfigHelper(cameraDef);
				var camera = new FCamera(100,100,gameInstanceName);
				
				camera.init(cameraDef);
				
				_game.addCamera(c.getNotNull('name',String),camera);
				stage.addChild(camera);
				stage.addEventListener(Event.RESIZE, function(e:Event) { 
					camera.resizeToStage(); 
				});
			}
		}else{
			var camera = new FCamera(100,100,gameInstanceName);
			camera.init({});
			_game.addCamera(gameInstanceName,camera);
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
				_game.getWorld(worldName).init(worldConfig);
			}
		}

		var loader = FEntityLoader.getInstance();

		//initialize pools
		if(Std.is(config.entityPools,Array)){
			for(poolConfig in cast(config.entityPools,Array<Dynamic>)){
				var pool = new FConfigHelper(poolConfig);
				//load non-map entities we need
				//firmament.util.FLog.debug("entFile: "+pool.getNotNull('entityFile',String));
				loader.loadPool(pool.getNotNull('entityFile',String),pool.get("amount",Int,10));
			}
		}

		//load sounds
		if(Std.is(config.sounds,Array)){
			for(sound in cast(config.sounds,Array<Dynamic>)){
				if(Std.is(sound,String)){
					if(FSoundManager.getSound(sound) == null){
						firmament.util.FLog.debug("config loader warning: Sound not found: "+sound);
					}
				}
				
			}
		}



		//load map
		if(config.map != null){
			
			loader.loadMap(config.map,null,gameInstanceName);
		}

		//load scene components
		if(Std.is(config.components,Array)){
			for(component in cast(config.components,Array<Dynamic>)){
				if(Reflect.isObject(component)){
					var c = new FConfigHelper(component);
					var componentInstance = FSceneComponentFactory.createComponent(c.getNotNull("type"),_game);
					componentInstance.setScene(this);
					componentInstance.init(component);
					_components.push(componentInstance);
				}
			}
		}
		this.trigger(new FEvent(FScene.COMPONENTS_INITIALIZED));

	}

	public function getGame(){
		return _game;
	}

	public function getComponents(){
		return _components;
	}

	override public function destruct(){
		firmament.util.FLog.debug('scene destructed!');
		if(_components != null){
			for(component in _components){
				component.destruct();
			}
			while(_components.length>0){
				_components.pop();
			}
		}
		_components = new Array();
		super.destruct();
	}
}


