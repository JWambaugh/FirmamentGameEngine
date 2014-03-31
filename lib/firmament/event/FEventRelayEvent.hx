
package firmament.event;
import firmament.core.FEvent;
import firmament.core.FEntity;
class FEventRelayEvent extends FEvent {

	private var _config:Dynamic;
	private var _entity:FEntity;

	public function new(type:String,originEntity:FEntity,config:Dynamic){
		super(type);
		_entity = originEntity;
		_config = config;
	}


	public function getOriginEntity():FEntity{
		return _entity;
	}

	public function getConfig():Dynamic{
		return _config;
	}
	

}