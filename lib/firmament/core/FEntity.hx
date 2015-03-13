package firmament.core;

import firmament.component.base.FEntityComponent;
import firmament.component.physics.FPhysicsComponentInterface;
import firmament.component.render.FRenderComponentInterface;
import firmament.component.render.FTilesheetRenderComponent;
import firmament.core.FEntityPool;
import firmament.core.FEvent;
import firmament.core.FGame;
import firmament.core.FGameChildInterface;
import firmament.core.FObject;
import firmament.core.FProperty;
import firmament.core.FPropertyInterface;
import firmament.util.FGuidManager;
import firmament.util.FLog;
import firmament.util.FMisc;
import firmament.world.FWorld;
import flash.display.BitmapData;
import flash.events.Event;
import flash.geom.Point;
import flash.geom.Rectangle;
import openfl.Assets;
import openfl.display.Tilesheet;
 /**
  * Core entity class for all entities/actors in the game.
  * entities now follow a component archetecture. Modify their behavior with coponents.
  * 
  * 
  */
class FEntity extends FPropertyContainer implements FGameChildInterface{

	//events
	public static inline var COMPONENTS_INITIALIZED = 'componentsInited';
	public static inline var ACTIVE_STATE_CHANGE = "activeChange";

	var _componentsHash:Map<String,Array<FEntityComponent>>;
	var _components:Array<FEntityComponent>;
	var _pool:FEntityPool;
	var _active:Bool;
	var _typeId:String;
	var _tags:Array<String>;
	var _gameInstance:FGame;
	var _instanceId:String = null;
	var _debug:Bool = false;



	/**
	 * 
	 * Config Paramers:
	 * 	imageScale - [Float] The initial scale value for the sprite.
	 * 	sprite  - [BitmapData] The image to use as a sprite for this entity
	 */
	public function new(config:Dynamic,?gameInstanceName='main') 
	{
		super(config);

		this._componentsHash = new Map<String,Array<FEntityComponent>>();
		_components = new Array<FEntityComponent>();
		_active = true;
		if(!Std.is(config.typeId,String)){
			config.typeId = "Entity_"+Math.floor(Math.random()*10000000);
			
		}
		_typeId = config.typeId;
		_instanceId = config.instanceId;
		
		if(Std.is(config.tags,Array)){
			_tags = config.tags;
		}else{
			_tags = new Array<String>();
		}
		_gameInstance = FGame.getInstance(gameInstanceName);
		registerProperty(new FComputedProperty<String>("typeId",getTypeId,setTypeId));
        registerProperty(new FComputedProperty<String>("instanceId",getInstanceId,setInstanceId));
		registerProperty(new FComputedProperty<Bool>("debug",getDebug,setDebug));
	}


	public function getTypeId(t:String=""):String{
		return _typeId;
	}

	public function setTypeId(typeId:String){
		_typeId = typeId;
	}

	public function getDebug(d:Bool=false):Bool{
		return _debug;
	}

	public function setDebug(value:Bool){
		_debug = value;
	}

	/**
	 * Returns the instanceId of this entity. If an instanceId is not set by the 'instanceId' config proprty,
	 * a guid will be assigned (lazily)
	 *
	 */
	public function getInstanceId(i:String=''):String{
		if(_instanceId == null){
			_instanceId = FGuidManager.getGuid();
		}

		return _instanceId;
	}

	/**
	 * Sets the instanceId of this entity. If an instanceId is already set, throws an error.
	 *
	 */
	public function setInstanceId(id:String){
		if(_instanceId != null) throw dbgMsg()+"instanceId already set";
		_instanceId = id;
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
	

	/**
	 * Deletes the entity
	**/
	public function delete():Void{
		this.trigger(new FEvent(FGame.DELETE_ENTITY));
		if(_components!=null){
			for(c in _components){
				c.destruct();
			}
			this._components = null;
			this._config = null;
		}
		this._active=false;
	}

	override public function destruct(){
		delete();
		super.destruct();
	}

	public function setActive(active:Bool){
		if(active!=_active){
			_active = active;
			this.trigger(new FEvent(ACTIVE_STATE_CHANGE));
            for (c in _components){
                if(active)c.onActivate();
                else c.onDeactivate();
            }
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
			throw dbgMsg()+"Can't return to pool. Pool is null";
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

	public function getGameInstance():FGame{
		return _gameInstance;
	}

	//property functions

	override public function getProperty(key:String):FProperty{
		try {
			return super.getProperty(key);
		} catch (e:String) {
			throw dbgMsg() + e;
		}
	}

	override public function registerProperty(property:FProperty){
		try {
			super.registerProperty(property);
		} catch (e:String) {
			throw dbgMsg() + e;
		}
	}
	
    public function registerComponentProperties(){
        for(c in _components){
            var props = c.getProperties();
            for (p in props){
                if(!hasProperty(p.key)){
                    registerProp(p.key,p.type,p.getter,p.setter);
                }else{
                    var property = getProperty(p.key);
                    if(Std.is(property,firmament.core.FComputedProperty)){
                        cast(property, firmament.core.FComputedProperty<Dynamic>).add(p.getter,p.setter,p.sortOrder);
                    }else{
                        //do nothing for non-computed properties
                    }
                }
            }
        }
    }

    private function dbgMsg(){
        return "Entity '"+_typeId+"':'"+_instanceId+"': "; 
    }

    public function log(message:Dynamic,force:Bool = false){
		var msg:String = dbgMsg() + Std.string(message);
		if( _debug == true || force == true ) {
			FLog.msg(msg);
		} else {
			FLog.debug(msg);
		}
	}
	
}