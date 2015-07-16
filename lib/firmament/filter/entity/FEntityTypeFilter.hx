package firmament.filter.entity;

import firmament.core.FEntity;

class FEntityTypeFilter extends FEntityFilter{

	var _type:String;
	public function new(?scope:FEntity=null){
		super(scope);
	}

	//returns true if the entity matches the criteria of the filter
	override public function filterEntity(entity:FEntity,?options:Dynamic=null):Bool{
		if(Std.is(options.typeId,String)){
			if(entity.getTypeId()==options.typeId)return true;
		}else if(Std.is(options.typeIds,Array)){
			var arr:Array<String> = options.typeIds;
			for (typeId in arr){
				if(entity.getTypeId()==typeId) return true;
			}
		}
		return false;
	}

	


}