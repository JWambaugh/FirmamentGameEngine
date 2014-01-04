package firmament.core;


import firmament.core.FEntity;

class FEntityCollection{
	var _entities:Array<FEntity>;
	var _this:FEntity;

	public function new (a:Array<FEntity>, ?thisEntity:FEntity=null){
		_entities = a;
		_this = thisEntity;
	}


	public function get():Array<FEntity>{
		return _entities;
	}

	/** 
	 * Sets the scope of 'this' to the specified entity.
	 *
	 */
	public function thisIs(entity:FEntity):FEntityCollection{
		_this = entity;
		return this;
	}


	public function filter(val:Array<Dynamic>){
		return this;
	}


	private function doFilter(val:Array<Dynamic>){
		var subject:Dynamic = val.shift();
		var comparator = findComparator(cast val.shift());
		var newArray = new Array<FEntity>();

		for(entity in _entities){
			if(comparator(subject,val,entity)){
				newArray.push(entity);
			}
		}
		_entities = newArray;

	}

	private function evalValue(value:Dynamic,ent:FEntity):Dynamic{
		if(Std.is(value,String)){
			var strVal:String = cast value;
			if(strVal.indexOf("@this.")==0){
				var propertyKey = strVal.substr(6);
				if(_this == null) throw("entity to use as 'this' has not been set, but used in query as value: "+value);
				return _this.getPropertyValue(propertyKey);
			}
			else if(strVal.indexOf("@")==0){
				var propertyKey = strVal.substr(1);
				return ent.getPropertyValue(propertyKey);
			}
			else{
				return value;
			}
		}else{
			return value;
		}
	}

	public function findComparator(comparatorStr:String):Dynamic -> Array<Dynamic> ->FEntity -> Bool{
		return switch(comparatorStr){
			case "equals","equal","=","==": this.equals;
			case "lessThan","<": this.lessThan;
			case "greaterThan",">": this.lessThan;
			default: throw "Unrecognized comparator: "+comparatorStr;
		};
	}

	private function equals(a:Dynamic,b:Array<Dynamic>, ent:FEntity):Bool{
		return evalValue(a,ent)==evalValue(b[0],ent);
	}

	private function lessThan(a:Dynamic,b:Array<Dynamic>, ent:FEntity):Bool{
		return evalValue(a,ent)<evalValue(b[0],ent);
	}

	private function greaterThan(a:Dynamic,b:Array<Dynamic>, ent:FEntity):Bool{
		return evalValue(a,ent)>evalValue(b[0],ent);
	}



}