
package firmament.util;
import firmament.core.FVector;

class FConfigHelper {

	private var _config:Dynamic;
	public function new(config:Dynamic){
		_config = config;
		if(!Reflect.isObject(config))throw "Config is not an object!";
	}

	public function get(field:String,?type:Dynamic=null,?def:Dynamic=null):Dynamic{
		var entry:Dynamic = Reflect.field(_config,field);
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
		var v = vectorFromDynamic(Reflect.field(_config,field));
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