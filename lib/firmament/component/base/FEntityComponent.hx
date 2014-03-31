package firmament.component.base;
import firmament.core.FEntity;
import flash.events.EventDispatcher;
import firmament.core.FEvent;
import firmament.util.FConfigHelper;
import firmament.core.FProperty;
import firmament.core.FObject;

/*
	Class: FEntity Component


	FEntityComponents are the components that make up an entity.
	@author Jordan Wambaugh
 */

class FEntityComponent extends FObject
{

	private var _config:Dynamic;
	private var _entity:FEntity;
	private var _componentKey:String;
	private var _configHelper:FConfigHelper;

	public function new() 
	{
		_configHelper = null;
		super();
		

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
	public function registerProp(key:String, type:Dynamic){
		var prop = FProperty.createBasic(key,type);
		_entity.registerProperty(prop);
	}

	public function getProp(key:String){
		return _entity.getProperty(key).getDynamic();
	}

	public function setProp(key:String,value:Dynamic){
		_entity.getProperty(key).set(value);
	}



}