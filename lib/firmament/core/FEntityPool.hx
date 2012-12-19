
package firmament.core;


import firmament.core.FEntity;
import firmament.core.FEntityFactory;


class FEntityPool {

	var _entityConfig:Dynamic;
	var _entities:Array<FEntity>;
	
	public function new(config:Dynamic, ?preAllocate:Int=0){
		_entities = new Array<FEntity>();
		_entityConfig=config;
		
		if(preAllocate!=0){
			this.preAllocate(preAllocate);
		}
	}

	public function getEntityTypeId(){
		return _entityConfig.typeId;
	}

	private function preAllocate(number:Int){
		for(n in 0...number){
			var ent:FEntity = FEntityFactory.createEntity(_entityConfig);
			ent.setPool(this);
			ent.returnToPool();

		}
	}

	public function addEntity(entity:FEntity){
		_entities.push(entity);
	}

	public function getEntity():FEntity{
		//trace(_entityConfig.typeId+"poolSize: "+_entities.length);
		var ent = _entities.pop();

		if(ent!=null) {
			//ent.setActive(true);
			return ent;
		}else {
			ent = FEntityFactory.createEntity(_entityConfig);
			ent.setPool(this);
			return ent;
		}
	}


}