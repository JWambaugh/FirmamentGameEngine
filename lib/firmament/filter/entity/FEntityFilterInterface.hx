package firmament.filter.entity;

import firmament.core.FEntity;

interface FEntityFilterInterface{

	//returns true if the entity matches the criteria of the filter
	public function filterEntity(entity:FEntity,?options:Dynamic=null):Bool;

	//returns a new array with only entities that pass the filter.
	public function filterEntityArray(arr:Array<FEntity>,?options:Dynamic=null):Array<FEntity>;
	
}