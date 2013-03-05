package firmament.core;
import firmament.component.base.FEntityComponent;
import firmament.component.physics.FPhysicsComponentInterface;
import firmament.component.render.FRenderComponentInterface;
import firmament.component.render.FTilesheetRenderComponent;
import firmament.world.FWorld;
import firmament.core.FEntityPool;
import nme.display.BitmapData;
import nme.display.Tilesheet;
import nme.events.Event;
import nme.geom.Point;
import nme.geom.Rectangle;
import firmament.util.FMisc;
import nme.Assets;
 
 /**
  * Core entity class for all entities/actors in the game.
  * entities now follow a component archetecture. Modify their behavior with coponents.
  * 
  * 
  */
class FEntity extends nme.events.EventDispatcher
{

	//events
	public static inline var COMPONENTS_INITIALIZED = 'componentsInited';
	public static inline var ACTIVE_STATE_CHANGE = "activeChange";

	var _config:Dynamic;
	var _componentsHash:Hash<Array<FEntityComponent>>;
	var _components:Array<FEntityComponent>;
	var _pool:FEntityPool;
	var _active:Bool;
	var _typeId:String;
	var _listeners : Hash<Dynamic>; 
	var _tags:Array<String>;


	/**
	 * 
	 * Config Paramers:
	 * 	imageScale - [Float] The initial scale value for the sprite.
	 * 	sprite  - [BitmapData] The image to use as a sprite for this entity
	 */
	public function new(config:Dynamic) 
	{
		super();
		if(config == null) config ={};
		this._config = config;
		this._componentsHash = new Hash<Array<FEntityComponent>>();
		_components = new Array<FEntityComponent>();
		_active = true;
		if(!Std.is(config.typeId,String)){
			config.typeId = "Entity_"+Math.floor(Math.random()*10000000);
			
		}
		_typeId = config.typeId;
		_listeners = new Hash();

		if(Std.is(config.tags,Array)){
			_tags = config.tags;
		}else{
			_tags = new Array<String>();
		}

	}


	public function getTypeId():String{
		return _typeId;
	}
	
	
	/**
	 * Returns an array of components with the specified type.
	 * 
	 * @return  The components with matching type
	 */
	public function getComponent(type:String):Array<FEntityComponent> {
		return this._componentsHash.get(type);
	}

	public function getAllComponents():Array<FEntityComponent>{
		return _components;
	}


	/**
	 *	returns a physics component if there is one. null otherwise
	 * 
	 *
	 * @return PysicsComponentInterface
	 */
	public function getPhysicsComponent():FPhysicsComponentInterface {
		var ca = this.getComponent('physics');
		if(ca!=null){
			return cast(ca[0]);
		}
		return null;
	}

	/**
	 *	returns a render component, if there is one. null otherwise
	 * 
	 *
	 * @return PysicsComponentInterface
	 */
	public function getRenderComponent():FRenderComponentInterface {
		var ca = this.getComponent('render');
		if(ca!=null){
			return cast(ca[0]);
		}
		return null;
	}
	
	/**
	 * Adds a component to the entity
	 */
	public function setComponent(component:FEntityComponent) {
		var array:Array<FEntityComponent>;
		array = _componentsHash.get(component.getType());
		if(array == null){
			array = new Array();
			_componentsHash.set(component.getType(),array);
		}
		array.push(component);
		_components.push(component);
		component.setEntity(this);
	}
	
	
	public function getConfig():Dynamic {
		return this._config;
	}

	/**
	 * Deletes the entity
	**/
	public function delete():Void{
		this.dispatchEvent(new Event(FGame.DELETE_ENTITY));
		if(_components!=null){
			for(c in _components){
				c.destruct();
			}
			this._components = null;
			this._config = null;
		}	
		//this.removeListeners();
	}

	public function setActive(active:Bool){
		if(active!=_active){
			_active = active;
			this.dispatchEvent(new Event(ACTIVE_STATE_CHANGE));
		}
	}

	public function isActive():Bool{
		return _active;
	}

	public function setPool(pool:FEntityPool){
		_pool = pool;
	}
	public function getPool(){
		return _pool;
	}
	
	public function returnToPool(){
		
		this.setActive(false);
		
		if(_pool == null){
			throw "Can't return to pool. Pool is null";
		}else{
			_pool.addEntity(this);
		}
		
	}

	public function getTags():Array<String>{
		return _tags;
	}

	public function addTag(tag:String){
		_tags.push(tag);
	}

	public function removeTag(tag:String){
		_tags.remove(tag);
	}

	public function hasTag(tag:String):Bool{
		for(t in _tags){
			if(t == tag) return true;
		}
		return false;
	}
	
}