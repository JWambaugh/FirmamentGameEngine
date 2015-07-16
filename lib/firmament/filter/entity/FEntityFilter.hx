package firmament.filter.entity;


import firmament.filter.entity.FEntityFilterInterface;
import firmament.core.FEntity;

class FEntityFilter implements FEntityFilterInterface{

	private var _scope:FEntity;
	public function new(?scope:FEntity=null){
		_scope = scope;
	}

	private function evalOption(?value:Dynamic=null):Dynamic {
		if( Std.is(value,String) ) {
			if( value.indexOf("@")==0 && _scope != null ) {
				var propertyKey:String = value.substr(1);
				if(_scope.hasProperty(propertyKey)) {
					return _scope.getProp(propertyKey);
				} else {
					trace( 'Invalid property key -' + value);
				}
				
			}
		}
		return value;
	}

	private function patchOptions(?options:Dynamic=null):Dynamic {
		if( options != null ) {
			var fields = Reflect.fields(options);
			for( field in fields ) {
				var data = Reflect.field(options,field);
				var value = evalOption(data);
				Reflect.setField( options, field, value );
			}
		}
		return options;
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
		options = patchOptions(options);
		for(ent in arr){
			if(filterEntity(ent,options)){
				ret.push(ent);
			}
		}
		return ret;
	}


}