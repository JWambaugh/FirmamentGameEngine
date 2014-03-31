
package firmament.event;

import firmament.core.FEvent;
import firmament.core.FEntity;
class FEntityEvent extends FEvent {

	var _entity:FEntity;

	public function new(event:String,entity:FEntity){
		super(event);
		_entity = entity;
	}

	public function getEntity():FEntity{
		return _entity;
	}

}