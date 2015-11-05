package firmament.scene;

import flash.events.Event;
import flash.Lib;

import firmament.core.FCamera;
import firmament.core.FConfig;
import firmament.core.FEvent;
import firmament.core.FGame;
import firmament.core.FGameChildInterface;
import firmament.core.FObject;
import firmament.core.FProperty;
import firmament.core.FPropertyContainer;
import firmament.core.FVector;
import firmament.scene.FSceneComponent;
import firmament.scene.FSceneComponentFactory;
import firmament.sound.FSoundManager;
import firmament.util.FLog;
import firmament.util.FRepository;
import firmament.util.FStatistics;
import firmament.util.loader.FDataLoader;
import firmament.util.loader.FEntityLoader;

class FScene extends FPropertyContainer implements FGameChildInterface{

	var _components : Array<FSceneComponent>;
	var _gameInstanceName:String;
	var _game:FGame;

	/**
	 * event fired after all scene components are initialized.
	 */
	public static var COMPONENTS_INITIALIZED = "componentsInit"; 
	public function new(){
		super( {} );
		_components = new Array();
	}

	public function init(config:Dynamic, ?gameInstanceName:String='main'){
		_gameInstanceName = gameInstanceName;
		if(Std.is(config,String)){
			config = FDataLoader.loadData(config);
		}
		_game = FGame.getInstance(gameInstanceName);
		var stage = Lib.current.stage;

		if(Std.is(config.properties,Dynamic)) {
			// keeps the function clean by calling a method
			createProperties(config.properties);
		}
		if(Std.is(config.statistics,Dynamic)) {
			// keeps the function clean by calling a method
			createProperties(config.statistics,FStatistics.getInstance() );
		}
		//initialize repository
		FLog.debug( "Processing " + config.repository );

		if(Std.is(config.repository,Dynamic) && config.repository!=null){
			createRepositoryEntries(config.repository);
		}
		//initialize cameras

		if(!Std.is(config.cameras,Array) ||  ( Std.is(config.cameras,Array) && cast(config.cameras,Array<Dynamic>).length <= 0 ) ) {
			config.cameras = [{}];
		}
		// Allows code reuse
		for(cameraDef in cast(config.cameras,Array<Dynamic>)){
			var c:FConfig = cameraDef;
			var camName:String = c.get('name',String,gameInstanceName);
			var camera = new FCamera(100,100,camName);
			camera.init(cameraDef);

			_game.addCamera(camName,camera);
			stage.addChild(camera);
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
					var componentInstance = FSceneComponentFactory.createComponent(
						c.get("componentName",Dynamic,c.getNotNull("type") )
						,_game);
					componentInstance.setConfig(c);
					componentInstance.setScene(this);
                    componentInstance.setParent(this);
					componentInstance._init(c);
					_components.push(componentInstance);
				}
			}
		}
		this.trigger(new FEvent(FScene.COMPONENTS_INITIALIZED));
	}

	private function createRepositoryEntries(repository:FConfig) {
		var repoInstance = FRepository.getInstance();
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

	private function createProperties(propertyDefinitions:FConfig,?propertyStore:FPropertyContainer=null) {
		if( propertyStore == null ) {
			propertyStore = this;
		}
		for( key in propertyDefinitions.fields() ) {
			try {
				var propDef:FConfig = propertyDefinitions.getNotNull(key);
				var type:Dynamic = Type.resolveClass( propDef.get("type",String,"Float") );
				var value:Dynamic = propDef.getNotNull("value", type );
				var prop:FProperty = FProperty.createBasic(key,type);
				prop.set( value );
				propertyStore.registerProperty(prop);
			} catch (e:Dynamic) {
				FLog.error( e );
			}
		}
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


