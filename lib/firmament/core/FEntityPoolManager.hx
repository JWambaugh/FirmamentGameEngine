
package firmament.core;

import firmament.core.FEntityPool;


class FEntityPoolManager {

	var pools:Hash<FEntityPool>;


	public function new(){
		pools = new Hash<FEntityPool>();
	}

	public function getPool(entityTypeId:String){
		return pools.get(entityTypeId);
	}

	public function addPool(pool:FEntityPool){
		pools.set(pool.getEntityTypeId(),pool);
	}
}