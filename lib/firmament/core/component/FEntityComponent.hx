package firmament.core;

import nme.events.EventDispatcher;
/**
 * FEntityComponents are the components that make up an entity.
 * @author Jordan Wambaugh
 */

class FEntityComponent extends EventDispatcher
{

	private var _config:Dynamic;
	private var _entity:FEntity;
	
	public function new() 
	{
		super();
	}
	
	public function init(config:Dynamic) {
		throw "This needs to be overridden in a subclass.";
	}
	
	
	public function getType():String {
		throw "this needs to be overridden in a subclass.";
		return "";
	}
	
}