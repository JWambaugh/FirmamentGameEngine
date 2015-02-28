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
class FPropertyContainer extends FObject implements FPropertyInterface {

	//events
	var _config:Dynamic;
	public var _properties:Map<String,FProperty>;


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
		_properties = new Map<String,FProperty>();
	}
	
	
	public function getConfig():Dynamic {
		return this._config;
	}


	//property functions

	public function registerProperty(property:FProperty){
		if(_properties.exists(property.getKey()))  {
			throw("Property already exists with key "+ property.getKey() );
		}
		_properties.set(property.getKey(),property);
	}

    public function hasProperty(key:String){
        return _properties.exists(key);
    }
	
	public function getProperty(key:String):FProperty{
		var p = _properties.get(key);
		if(p == null) throw("No property with key "+key);
		return p;
	}


	public function getPropertyValue(key:String):Dynamic{
		return getProperty(key).getDynamic();
	}

	public function setPropertyValue(key:String,value:Dynamic){
		getProperty(key).set(value);
	}

	//property helper functions
	/**
	 * Registers a property in the entity. This must be done before the property can be read or written.
	 */
	public function registerProp(key:String, type:Dynamic, getter:Dynamic->Dynamic=null, setter:Dynamic->Void=null){
        var prop;
        if(getter==null&&setter==null)
            prop = FProperty.createBasic(key,type);
        else
            prop = FProperty.createComputed(key,type,getter,setter);
		this.registerProperty(prop);
	}
	
	/**
	 * Returns the value of the given property
	 */
	public function getProp(key:String):Dynamic{
		return getProperty(key).getDynamic();
	}

	/**
	 * sets the value of the property
	 */
	public function setProp(key:String,value:Dynamic){
		getProperty(key).set(value);
	}
	
}