package firmament.filter.entity;

import firmament.core.FEntity;
import firmament.core.FVector;
import firmament.util.FConfigHelper;

class FEntityRadiusFilter extends FEntityFilter{

	var _type:String;
	public function new(){
		super();
	}

	//returns true if the entity matches the criteria of the filter
	override public function filterEntity(entity:FEntity,?options:Dynamic=null):Bool{
		var oh = new FConfigHelper(options);
		var radius:Float = oh.getNotNull("radius",Float);
		var point:FVector = oh.getVector("point",null);
		var entPoint = entity.getPhysicsComponent().getPosition();
		if(point == null){
			throw "point parameter in options is null but should be a vector.";
		}
		//Pythagorean Theorem
		var distance = Math.abs(Math.sqrt(Math.pow(point.x - entPoint.x, 2) + Math.pow(point.y - entPoint.y, 2)));
		if(distance <= radius) return true;

		return false;
	}

	


}