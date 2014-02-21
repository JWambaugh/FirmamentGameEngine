package firmament.core;
import firmament.core.FVector;

abstract FConfig({}) from {} to {} {
	public function new(o:Dynamic){
		this = o;
	}
	
    @:arrayAccess public inline function arrayAccess(key:String):Dynamic {
        return Reflect.field(this, key);
    }
    
    @:arrayAccess public inline function arrayWrite<T>(key:String, value:T):T {
        Reflect.setField(this, key, value);
        return value;
    }

    public function get(field:String,?type:Dynamic=null,?def:Dynamic=null):Dynamic{
		var entry:Dynamic = Reflect.field(this,field);
		if(entry == null)return def;

		if(type==null){
			if(entry == null){
				return def;
			}else{
				return entry;
			}
		}else{
			if(Std.is(type,Array)){
				for(t in cast(type,Array<Dynamic>)){
					if(Std.is(entry,t)){
						return entry;
					}
				}
				return def;
			}else{
				if(Std.is(entry,type)){
						return entry;
				}else{
					return def;
				}
			}
		}
	}

	public function getVector(field:String,?def:Dynamic=null){
		if(def == null)def={x:0,y:0};
		var v = vectorFromDynamic(Reflect.field(this,field));
		if(v == null) return vectorFromDynamic(def);
		return v;
	}

	private function vectorFromDynamic(d:Dynamic):FVector{
		if(Std.is(d,FVector)) return d;
		if(Reflect.isObject(d)){
			if(Std.is(d.x,Float) && Std.is(d.y,Float)){
				return new FVector(d.x,d.y);
			}
		}
		return null;
	}

	public function getNotNull(field:String,?type:Dynamic=null,?def:Dynamic=null):Dynamic{
		var ret = get(field,type,def);
		if(ret == null){
			throw "Field "+field+" does not exist or is not a valid type";
		}
		return ret;
	}
}