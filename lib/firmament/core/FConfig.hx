package firmament.core;
import firmament.core.FVector;
import firmament.util.FLog;

abstract FConfig({}) from {} to {} {
	public function new(o:Dynamic){
		this = o;
	}
	
    @:arrayAccess public inline function arrayAccess(key:String):Dynamic {
        return get(key);
    }
    
    @:arrayAccess public inline function arrayWrite<T>(key:String, value:T):T {
        Reflect.setField(this, key, value);
        return value;
    }

    public function hasField(field:String, type:Dynamic = null){
        if(! Reflect.hasField(this,field)) return false;
        if(type != null){
            return Std.is(Reflect.field(this,field),type);
        } 
        return true;
    }

    public function fields(){
        return Reflect.fields(this);
    }

    public function get(field:String,?type:Dynamic=null,?def:Dynamic=null):Dynamic{
		var entry:Dynamic =  Reflect.field(this,field);
       /*  // Allows arrays so keys are not necessary
            //  ie. components wouldn't need names anymore
            if( Std.is(this,Array) ) {
                var asArray:Array<Dynamic> = cast( this, Array<Dynamic> );
                entry = asArray[ Std.parseInt(field) ];
            }*/
        
        
        // if I'm an array this doesn't seem to work.
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
					if(type==Int && Reflect.isObject(entry)){
                        return parseIntObject(entry,def);
                    }
                    else if(type==Float && Reflect.isObject(entry)){
                        return parseFloatObject(entry,def);
                    } 
                    else if(type==String && Reflect.isObject(entry)){
                        return parseStringObject(entry,def);
                    }
                    else if(type==FVector && Reflect.isObject(entry)){
                        return parseVectorObject(entry,def);
                    } 
                    else{
                        FLog.warning("field "+field+" is not type expected! Returning default.");
                        return def;
                    }
                   
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
        return parseVectorObject(d);
    }

    private function parseVectorObject(v:Dynamic,d:FVector=null):FVector {
        // vector is { x: Float, y: Float }
        //           [ Float, Float ], 
        //           [ Float ]
        //           []
        var error:Bool = false;
        var a:Array<Float> = [0.0,0.0];

        if( Std.is(v,FVector) ){return v;}

        if(Reflect.isObject(v)){
            if(Std.is(v,Array)) {
                var length = v.length;
                if(length>=1) {
                    a[0] = parseFloat(v[0]);
                }
                if(length>=2) {
                    a[1] = parseFloat(v[1]);
                }
            } else if( Std.is(v,Dynamic) ){
                if(Reflect.hasField(v,'x') && Reflect.hasField(v,'y') ) {
                    a[0] = parseFloat(v.x);
                    a[1] = parseFloat(v.y);
                } else {
                    error = true;
                }
            } else {
                error = true;
            }
        } else {
            error = true;
        }

        if( error ) {
            return d;
        }

        return new FVector(a[0], a[1]);
    }

    private function parseFloat(v:Dynamic):Float {
        if(Std.is(v,Float) || Std.is(v,Int)) {
            return v + 0.0;
        }
        if(Std.is(v,String) ) {
            return Std.parseFloat(v);
        } 
        else if(Reflect.isObject(v)) {
            return parseFloatObject(v);
        }
        throw "Unexpected value passed as float <"+v+">";
    }


    private function parseFloatObject(v:Dynamic,d:Float=0.0):Float{
        if(Reflect.hasField(v,"*min*") && Reflect.hasField(v,"*max*")){
            var min:Float = Reflect.field(v,"*min*");
            var max:Float = Reflect.field(v,"*max*");
            return min+Math.random()*(max-min);
        }
        if(Reflect.hasField(v,"*random*")){
            var a:Array<Float> = cast Reflect.field(v,"*random*");
            return a[Math.floor(Math.random()*a.length)];
        }
        if(Reflect.hasField(v,"*weighted*")){
            var a:Array<Dynamic> = cast Reflect.field(v,"*weighted*");
            var k:Array<String> = new Array();
            var sum:Float=0;
            for( o in a ) {
                var f:String = Reflect.fields(o)[0];
                k.push(f);
                sum += Std.parseFloat(f);
            }
            var rand:Float = Math.random() * sum;
            var target:Float = rand;
            for( i in 0...a.length) {
                var o = a[i];
                var w = k[i];
                target -= Std.parseFloat(w);
                if( target <= 0 ) {
                    var value:Float = Std.parseFloat(Reflect.field(o,w));
                    FLog.debug("Weighted Value " + value + "("+ w +")");
                    return value;
                }
            }
        }
        return d; // I didn't know what you were
    }

    private function parseIntObject(v:Dynamic,d:Int=0):Int{
       if(Reflect.hasField(v,"*min*") && Reflect.hasField(v,"*max*")){
            var min:Int = Reflect.field(v,"*min*");
            var max:Int = Reflect.field(v,"*max*");
            return min+Math.floor(Math.random()*(max-min));
        }
        if(Reflect.hasField(v,"*random*")){
            var a:Array<Int> = cast Reflect.field(v,"*random*");
            var key = Math.floor(Math.random()* a.length);
            FLog.debug('using key '+key);
            return a[key];
        }
        if(Reflect.hasField(v,"weighted")){
            var a:Array<Dynamic> = cast Reflect.field(v,"weighted");
            var k:Array<String> = new Array();
            var sum:Int=0;
            for( o in a ) {
                var f:String = Reflect.fields(o)[0];
                k.push(f);
                sum += Std.parseInt(f);
            }
            var rand:Int = Std.random(sum);
            var target:Int = rand;
            for( i in 0...a.length) {
                var o = a[i];
                var w = k[i];
                target -= Std.parseInt(w);
                if( target <= 0 ) {
                    var value:Int = Std.parseInt(Reflect.field(o,w));
                    FLog.debug("Weighted Value " + value + "("+ w +")");
                    return value;
                }
            }
        }
        return d; // I didn't know what you were
        
    }

    private function parseStringObject(v:Dynamic,d:String):String{
       
        if(Reflect.hasField(v,"*random*")){
            var a:Array<String> = cast Reflect.field(v,"*random*");
            return a[Math.floor(Math.random()*a.length)];
        }
        if(Std.is(v,String)) {
            return v;
        }
        return d;
    }

	public function getNotNull(field:String,?type:Dynamic=null,?def:Dynamic=null):Dynamic{
		var ret = get(field,type,def);
		if(ret == null){
			throw "Field "+field+" does not exist or is not a valid type";
		}
		return ret;
	}
}