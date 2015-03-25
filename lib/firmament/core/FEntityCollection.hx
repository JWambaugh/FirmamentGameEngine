package firmament.core;



import firmament.core.FMutex;
import firmament.core.FEntity;
import firmament.util.FMisc;
import haxe.ds.ArraySort;

class FEntityCollection implements ArrayAccess<FEntity>{
	var _entities:Array<FEntity>;
	var _this:FEntity;
    var _mutex:FMutex;

	public var length(get_length,never):Int;

	public function new (?a:Array<FEntity>=null, ?thisEntity:FEntity=null){
		if(a == null) {
			a = new Array<FEntity>();
		}
		_entities = a;
		_this = thisEntity;

        _mutex = new FMutex();

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




	public function filter(val:Dynamic){

		if(val == "" || val == null) return this;
		if(Std.is(val, String)){
			val = FMisc.smartSplitWhiteSpace(val);
		}
		if(!Std.is(val, Array)){
			throw "Value must be string or array";
		}
		firmament.util.FLog.debug(Std.string(val));
    _mutex.acquire();
		doFilter(val);
    _mutex.release();
		return this;
	}



	private function doFilter(val:Array<Dynamic>){
		var subject:Dynamic = val.shift();
		var comparator = findComparator(cast val.shift());
		var newArray = new Array<FEntity>();

		for(entity in _entities){
			if(entity.isActive() && comparator(subject,val,entity)){
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
				//firmament.util.FLog.debug(ent.getPropertyValue(propertyKey));
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
			case "notEqual","!=": this.lessThan;
			default: throw "Unrecognized comparator: "+comparatorStr;
		};
	}

	private function equals(a:Dynamic,b:Array<Dynamic>, ent:FEntity):Bool{
		return evalValue(a,ent) == evalValue(b[0],ent);
	}

	private function lessThan(a:Dynamic,b:Array<Dynamic>, ent:FEntity):Bool{
		return evalValue(a,ent) < evalValue(b[0],ent);
	}

	private function greaterThan(a:Dynamic,b:Array<Dynamic>, ent:FEntity):Bool{
		return evalValue(a,ent) > evalValue(b[0],ent);
	}

    private function notEqual(a:Dynamic,b:Array<Dynamic>, ent:FEntity):Bool{
        return evalValue(a,ent) != evalValue(b[0],ent);
    }

	public function iterator(){
		return _entities.iterator();
	}

	public function remove(e:FEntity){
        _mutex.acquire();
		var rval = _entities.remove(e);
        _mutex.release();
        return rval;
	}

	public function get_length(){
		return _entities.length;
	}


	//array access
	public function __get(x:Int){
        _mutex.acquire();
        var rval = _entities[x];
        _mutex.release();
		return rval;
	}

	public function __set(x:Int,v:FEntity){
        _mutex.acquire();
        var rval = _entities[x] = v;
        _mutex.release();
        return rval;

	}

	public function sort(f:FEntity ->FEntity ->Int):Void{
        _mutex.acquire();
        ArraySort.sort(_entities, f);
        _mutex.release();
	}

    public function sortByPropertyAsc(property:String){
        sort(function(x,y){
            var xz=x.getProp(property);
            var yz=y.getProp(property);
            if(xz<yz)return 1;
            if(xz>yz)return -1;
            return 0;
        });
    }

    public function sortByPropertyDesc(property:String){
        sort(function(x,y){
            var xz=x.getProp(property);
            var yz=y.getProp(property);
            if(xz>yz)return 1;
            if(xz<yz)return -1;
            return 0;
        });
    }

	public function first():FEntity{
        _mutex.acquire();
        var rval = _entities[0];
        _mutex.release();
        return rval;
	}

    public function concat(c:FEntityCollection){
        _mutex.acquire();
        var rval = _entities.concat(c.get());
        _mutex.release();
        return rval;
    }
}
