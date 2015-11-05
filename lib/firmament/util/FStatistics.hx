package firmament.util;

import firmament.core.FPropertyContainer;
import firmament.core.FProperty;
import firmament.util.FRepository;

class FStatistics extends FPropertyContainer {
	
	static private var __stats:FStatistics;
	
	private function new() {
		super(null);
	}

	static public function getInstance() {
		if( __stats == null ) {
			__stats =  new FStatistics();
		}
		return __stats;
	}

	public function iterator():Iterator<FProperty>
    {
        return _properties.iterator();
    }

    public function keys():Iterator<String>
    {
        return _properties.keys();
    }

	override public function registerProperty(property:FProperty){
		super.registerProperty(property);
	}

    override public function hasProperty(key:String){
		return super.hasProperty(key);
    }

	override public function getProperty(key:String):FProperty{
		return super.getProperty(key);
	}


	override public function getPropertyValue(key:String):Dynamic{
		return getProp(key);
	}

	override public function setPropertyValue(key:String,value:Dynamic){
		setProp(key,value);
	}

	//property helper functions
	/**
	 * Registers a property in the entity. This must be done before the property can be read or written.
	 */
	override public function registerProp(key:String, type:Dynamic, getter:Dynamic->Dynamic=null, setter:Dynamic->Void=null){
        super.registerProp(key,type,getter,setter);
	}

	/**
	 * Returns the value of the given property
	 */
	override public function getProp(key:String):Dynamic{
		return super.getProp(key);
	}

	/**
	 * sets the value of the property
	 */
	override public function setProp(key:String,value:Dynamic){
		super.setProp(key,value);
	}
}