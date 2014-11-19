package firmament.scene;

import firmament.core.FCamera;
import firmament.core.FConfig;
import firmament.core.FEvent;
import firmament.core.FGame;
import firmament.core.FGameChildInterface;
import firmament.core.FObject;
import firmament.core.FVector;
import firmament.scene.FSceneComponent;
import firmament.scene.FSceneComponentFactory;
import firmament.sound.FSoundManager;
import firmament.util.FLog;
import firmament.util.FRepository;
import firmament.util.loader.FDataLoader;
import firmament.util.loader.FEntityLoader;
import flash.events.Event;
import flash.Lib;

class FScene extends FObject implements FGameChildInterface{

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
		//initialize repository
		FLog.debug( "Processing " + config.repository );
		if(Std.is(config.repository,Dynamic)){
			var repoInstance = FRepository.getInstance();
			var repository:FConfig = config.repository;
			for( item in repository.fields() ) {
				var value:Dynamic = repository[item];
				FLog.debug("key: "+item+", value: " + value);
				var val:Dynamic;
				try {
					val = repository.get(item,Float,null);
					if( Std.string(val) == value ) {
						FLog.debug("Setting "+val+" as number to repository");
						repoInstance.set(item,cast(val,Float));
					} else {
						throw item + " did not parse to a float";
					}
				} catch (e:String) { // not a Float
					val = repository.get(item,FVector,null);
					if( val != null ) {
						FLog.debug("Setting "+val+" as FVector to repository");
						repoInstance.set(item,cast(val,FVector));
					} else {
						val = repository.get(item,String,null);
						if( val != null && Std.string(val) == value ) {
							FLog.debug("Setting "+val+" as string to repository");
							repoInstance.set(item,cast(val,String));
						} else {
							FLog.debug("Setting "+value+" as object to repository");
							repoInstance.set(item,value);
						}
					}
				}
			}
		}
		//initialize cameras
		if(Std.is(config.cameras,Array)){
			for(cameraDef in cast(config.cameras,Array<Dynamic>)){
				var c:FConfig = (cameraDef);
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
				var pool:FConfig = (poolConfig);
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
		if(Std.is(config.components,Array) ){
			for(component in cast(config.components,Array<Dynamic>)){
				if(Reflect.isObject(component)){
					var c:FConfig = component;
					var componentInstance = FSceneComponentFactory.createComponent(c.getNotNull("type"),_game);
					componentInstance.setConfig(c);
					componentInstance.setScene(this);
					componentInstance.init(c);
					_components.push(componentInstance);
				}
			}
		}
		this.trigger(new FEvent(FScene.COMPONENTS_INITIALIZED));
	}

	public function getGameInstance(){
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


