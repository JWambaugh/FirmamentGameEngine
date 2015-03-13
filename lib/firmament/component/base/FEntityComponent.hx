
package firmament.component.base;

import firmament.core.FConfig;
import firmament.core.FEntity;
import firmament.core.FEvent;
import firmament.core.FObject;
import firmament.core.FProperty;
import firmament.core.FPropertyInterface;
import firmament.util.FLog;
import flash.events.EventDispatcher;



/*
	Class: FEntity Component


	FEntityComponents are the components that make up an entity.
	@author Jordan Wambaugh
 */

class FEntityComponent extends firmament.core.FComponent 
{

	private var _entity:FEntity;

	public function new(gameInstance:firmament.core.FGame) 
	{
		super(gameInstance);
		
		_enableDebug = false;
	}
	
	public function getType():String {
		throw "this needs to be overwritten in a subclass.";
		return "";
	}
	
	public function setEntity(entity:FEntity){
		this._entity = entity;
	}

	public function getEntity():FEntity{
		return this._entity;
	}

	override public function _init(config:FConfig) {
		// loop through FConfig looking for properties, convert to property objects!
        for( key in config.fields() ) {
        	var entry;
        	try {
	            entry = Reflect.field(config,key); // should I use reflect here?
	        } catch(e:Dynamic) { 
            	/* ignore any special types */
            	continue;
            }
            if( Reflect.isObject(entry) && Reflect.hasField(entry,'*property*') ) {
                var prop = Reflect.field(entry,'*property*');
                var property:firmament.core.FProperty = _entity.getProperty( prop );
                Reflect.setField(config, key, property ); 
            }
        }
        super._init(config);
	}
	

	override public function destruct(){
		_entity.getGameInstance().removeEventListener(this);
		_entity.removeEventListener(this);
		if(_usesStep)_entity.getGameInstance().removeStepSubscriber(this);
        //_entity = null;
		super.destruct();
	}
	

	public function removeEventListenerFromEntity(event:String){
		_entity.removeEventListener(event,this);
	}

	public function removeAllEventListenersFromEntity(){
		_entity.removeEventListener(this);
	}
	

    /**
     * Called when the entity is activated (like from a pool)
     */
    public function onActivate(){

    }

    /**
     * Called when the entity is deactivated (like when repooled)
     */
    public function onDeactivate(){

    }

    /**
     * Called after all entities are initialized
     */
    public function afterInit(){

    }


    //called by FGame instance
    override public function _doStep(delta:Float){
        if(_entity.isActive() && _usesStep){
            step(delta);
        }
    }

}