package firmament.filter.entity;


import firmament.filter.entity.FEntityFilterInterface;
import firmament.core.FEntity;

class FEntityFilter implements FEntityFilterInterface{

	public function new(){
		
	}

	//returns true if the entity matches the criteria of the filter
	public function filterEntity(entity:FEntity,?options:Dynamic=null):Bool{
		throw "needs to be overridden by subclass";
		return false;
	}

	//returns a new array with only entities that pass the filter.
	//this shouldn't have to be implemented in sublcasses
	public function filterEntityArray(arr:Array<FEntity>,?options:Dynamic=null):Array<FEntity>{
		var ret = new Array<FEntity>();
		for(ent in arr){
			if(filterEntity(ent,options)){
				ret.push(ent);
			}
		}
		return ret;
	}


}