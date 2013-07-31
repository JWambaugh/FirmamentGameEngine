package firmament.world.grid;

import firmament.core.FEntity;

class FGridCell{
	var _entities:Array<FEntity> = null;
	public function new(){
		_entities = new Array<FEntity>();
	}

	public function getEntities(){
		
		return _entities;
	}

	public function addEntity(ent:FEntity){
		_entities.push(ent);
	}
	public function removeEntity(ent:FEntity){
		_entities.remove(ent);
	}
}