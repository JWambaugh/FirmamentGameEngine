
package firmament.core;


import firmament.core.FEntity;



class FEntityPool {

	var _entityConfig:Dynamic;
	var _entities:Array<FEntity>;
	
	public function new(config:Dynamic){
		_entities = new Array<FEntity>();
		_entityConfig=config;
	}

	public function addEntity(entity:FEntity){
		_entities.push(entity);
	}


}