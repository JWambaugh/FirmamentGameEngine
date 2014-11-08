package firmament.component.base;
import firmament.core.FEntity;
import flash.events.EventDispatcher;
import firmament.core.FEvent;
import firmament.util.FConfigHelper;
import firmament.core.FProperty;
import firmament.core.FObject;
import firmament.core.FConfig;


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
	private var _configHelper:FConfigHelper;
	private var _usesStep:Bool;

	public function new() 
	{
		_configHelper = null;
		super();
		_usesStep = false;

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
		throw "This needs to be overwritten in a subclass.";
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

	/**
	 * Returns a config helper object for the component's config
	 */
	public function getConfigHelper():FConfigHelper{
		if(_configHelper == null){
			_configHelper = new FConfigHelper(_config);
		}
		return _configHelper;
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



}