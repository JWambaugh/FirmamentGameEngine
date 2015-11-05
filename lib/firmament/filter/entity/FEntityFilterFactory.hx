package firmament.filter.entity;

import firmament.filter.entity.FEntityTypeFilter;
import firmament.filter.entity.FEntityRadiusFilter;
import firmament.filter.entity.FEntityTagFilter;
import firmament.filter.entity.FEntityFilterInterface;

class FEntityFilterFactory{
	public static function createfilter(type:String,?scope:Dynamic=null):FEntityFilter {
		var className = getClassFromType(type);
		var c =Type.resolveClass(className);
		if(c==null){
			throw "class "+className+" could not be found.";
		}
		var filter:FEntityFilter = Type.createInstance(c,[scope]);
		if(filter == null){
			throw "filter of type "+type+" with class "+className+" could not be instantiated!";
		}
		return filter;
	}

	public static function getClassFromType(type:String){
		var map = {
			"type":"firmament.filter.entity.FEntityTypeFilter"
			,"radius":"firmament.filter.entity.FEntityRadiusFilter"
			,"tag":"firmament.filter.entity.FEntityTagFilter"
		};

		var cls = Reflect.field(map,type);
		if(cls == null) return type;
		return cls;
	}
}