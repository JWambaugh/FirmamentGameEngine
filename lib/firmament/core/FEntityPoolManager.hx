
package firmament.core;

import firmament.core.FEntityPool;


class FEntityPoolManager {

	var pools:Map<String,FEntityPool>;


	public function new(){
		pools = new Map<String,FEntityPool>();
	}

	public function getPool(entityTypeId:String){
		return pools.get(entityTypeId);
	}

	public function addPool(pool:FEntityPool){
		pools.set(pool.getEntityTypeId(),pool);
	}

	public function destruct(){
		for(pool in pools){
			pool.destruct();
		}
		pools = null;

	}
}