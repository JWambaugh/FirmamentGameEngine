package firmament.component.base;
import firmament.core.FEntity;
import nme.events.EventDispatcher;
import nme.events.Event;
import firmament.util.FConfigHelper;
/*
	Class: FEntity Component


	FEntityComponents are the components that make up an entity.
	@author Jordan Wambaugh
 */

class FEntityComponent extends EventDispatcher
{

	private var _config:Dynamic;
	private var _entity:FEntity;
	private var _listeners:Hash<Dynamic->Void>;
	private var _componentKey:String;
	private var _configHelper:FConfigHelper;

	public function new() 
	{
		_configHelper = null;
		super();
		_listeners = new Hash();

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

	
	public function destruct(){
		removeAllEventListenersFromEntity();
	}
	

	public function addEventListenerToEntity(event:String,listener:Dynamic->Void):Void{
		//is it safe to assume a single component won't have multiple listeners for the same event on an entity?
		//I can't think of a reason why you'd ever want to do that.
		_listeners.set(event,listener);
		_entity.addEventListener(event,listener);
	}

	public function removeEventListenerFromEntity(event:String){
		_entity.removeEventListener(event,_listeners.get(event));
		_listeners.remove(event);
	}

	public function removeAllEventListenersFromEntity(){
		for(event in _listeners.keys()){
			removeEventListenerFromEntity(event);
		}
	}

	public function setComponentKey(key:String){
		_componentKey = key;
	}



}