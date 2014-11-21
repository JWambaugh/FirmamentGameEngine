package firmament.component.base;
import firmament.core.FEntity;
import flash.events.EventDispatcher;
import firmament.core.FEvent;
import firmament.core.FProperty;
import firmament.core.FObject;
import firmament.core.FConfig;
import firmament.util.FLog;


typedef PropertyDefinition={
    key:String,
    type:Dynamic,
    setter:Dynamic->Void,
    getter:Void->Dynamic
};

/*
	Class: FEntity Component


	FEntityComponents are the components that make up an entity.
	@author Jordan Wambaugh
 */

class FEntityComponent extends FObject implements firmament.core.FStepSubscriber
{

	private var _config:FConfig;
	private var _entity:FEntity;
	private var _componentKey:String;
	private var _usesStep:Bool;
	private var _enableDebug:Bool;

	public function new() 
	{
		super();
		_usesStep = false;
		_enableDebug = false;
	}

	public function log(message:Dynamic,force:Bool = false){
		var msg:String = Std.string(message);
		if( _enableDebug == true || force == true ) {
			FLog.msg(msg);
		} else {
			FLog.debug(msg);
		}
	}

	public function useStep(u:Bool = true){
		if(_usesStep && !u){
			_entity.getGameInstance().removeStepSubscriber(this);
		}else{
			_entity.getGameInstance().addStepSubscriber(this);
		}
		_usesStep = u;
	}

	//called by FGame instance
	public function _doStep(delta:Float){
		if(_entity.isActive() && _usesStep){
			step(delta);
		}
	}

	public function step(delta:Float){

	}
	
	public function init(config:Dynamic):Void {
		if( config != null ) {
			throw "This needs to be overwritten in a subclass.";
		}
		_enableDebug = _config.get( 'debug', Bool, false );
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

	public function setConfig(c:Dynamic){
		_config = c;
	}

	public function getConfig(){
		return _config;
	}

    public function getProperties():Array<PropertyDefinition>{
        return [];
    }

	

	
	override public function destruct(){
		_entity.getGameInstance().removeEventListener(this);
		_entity.removeEventListener(this);
		if(_usesStep)_entity.getGameInstance().removeStepSubscriber(this);
		super.destruct();
	}
	

	public function removeEventListenerFromEntity(event:String){
		_entity.removeEventListener(event,this);
	}

	public function removeAllEventListenersFromEntity(){
		_entity.removeEventListener(this);
	}

	public function setComponentKey(key:String){
		_componentKey = key;
	}

	//entity property helpers
	public function registerProp(key:String, type:Dynamic, getter:Void->Dynamic=null, setter:Dynamic->Void=null){
		
		_entity.registerProp(key,type,getter,setter);
	}

	public function getProp(key:String){
		return _entity.getProperty(key).getDynamic();
	}

	public function setProp(key:String,value:Dynamic){
		_entity.getProperty(key).set(value);
	}

    public function getGameInstance():firmament.core.FGame{
        return _entity.getGameInstance();
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



}