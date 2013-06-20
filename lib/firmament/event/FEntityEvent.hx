
package firmament.event;

import flash.events.Event;
import firmament.core.FEntity;
class FEntityEvent extends Event {

	var _entity:FEntity;

	public function new(event:String,entity:FEntity){
		super(event);
		_entity = entity;
	}

	public function getEntity():FEntity{
		return _entity;
	}

}