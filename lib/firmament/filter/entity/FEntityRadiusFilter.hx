package firmament.filter.entity;

import firmament.core.FEntity;
import firmament.core.FVector;
import firmament.core.FConfig;

class FEntityRadiusFilter extends FEntityFilter{

	var _type:String;
	public function new(){
		super();
	}

	//returns true if the entity matches the criteria of the filter
	override public function filterEntity(entity:FEntity,?options:Dynamic=null):Bool{
		var oh:FConfig =  options;
		var radius:Float = oh.getNotNull("radius",Float);
		var point:FVector = oh.getVector("point",null);
		var entPoint = entity.getProp('position');
		if(point == null){
			throw "point parameter in options is null but should be a vector.";
		}
		//Pythagorean Theorem
		var distance = Math.pow(point.x - entPoint.x, 2) + Math.pow(point.y - entPoint.y, 2);
		if(distance <= Math.pow(radius,2)) return true;

		return false;
	}




}
