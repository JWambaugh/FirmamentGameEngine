package firmament.core;
import firmament.component.base.FEntityComponent;
import firmament.component.physics.FPhysicsComponentInterface;
import firmament.component.render.FRenderComponentInterface;
import firmament.component.render.FTilesheetRenderComponent;
import firmament.core.FWorld;
import firmament.core.FEntityPool;
import nme.display.BitmapData;
import nme.display.Tilesheet;
import nme.events.Event;
import nme.geom.Point;
import nme.geom.Rectangle;

import nme.Assets;
 
 /**
  * Class: FEntity 
  * Base class for all entities in Firmament
  * 
  * 
  */
class FEntity extends nme.events.EventDispatcher
{
	var _config:Dynamic;
	var _components:Hash<FEntityComponent>;
	var _pool:FEntityPool;
	var _active:Bool;
	var _typeId:String;

	public static inline var ACTIVE_STATE_CHANGE = "activeChange";

	/**
	 * Constructor: new
	 * 
	 * Config Paramers:
	 * 	imageScale - [Float] The initial scale value for the sprite.
	 * 	sprite  - [BitmapData] The image to use as a sprite for this entity
	 */
	public function new(config:Dynamic) 
	{
		super();
		this._config = config;
		this._components = new Hash<FEntityComponent>();
		_active = true;
		if(!Std.is(config.typeId,String)){
			config.typeId = "Entity_"+Math.floor(Math.random()*10000000);
			
		}
		_typeId = config.typeId;

	}


	public function getTypeId():String{
		return _typeId;
	}
	
	
	/**
	 * Function: getComponent
	 * 
	 * Returns:
	 * 	<FentityComponent>
	 */
	public function getComponent(type:String):FEntityComponent {
		return this._components.get(type);
	}

	public function getAllComponents():Hash<FEntityComponent>{
		return _components;
	}


	/**
	 * Function: getPhysicsComponent()
	 *	returns a physics component
	 * 
	 * Parameters: 
	 *	none
	 *
	 * Returns:
	 *	<FPysicsComponentInterface>
	 */
	public function getPhysicsComponent():FPhysicsComponentInterface {
		return cast(this.getComponent('physics'), FPhysicsComponentInterface);
	}

	public function getRenderComponent():FRenderComponentInterface {
		return cast(this.getComponent('render'), FRenderComponentInterface);
	}
	
	
	public function setComponent(component:FEntityComponent) {
		this._components.set(component.getType(),component);
		component.setEntity(this);
	}
	
	
	public function getConfig():Dynamic {
		return this._config;
	}

	/**
	 * Function: delete
	 * Will handle deletion of itself
	**/
	public function delete():Void{
		var p = this.getPhysicsComponent();
		if(p!=null){
			p.getWorld().deleteEntity(this);
		}
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


	
	
}