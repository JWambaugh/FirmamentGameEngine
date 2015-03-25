package firmament.util;

import firmament.core.FGame;
import firmament.process.base.FProcessManager;
import firmament.process.helper.FCallbackProcess;
/**
 * Class: FMisc
 * @author Jordan Wambaugh
 */

class FMisc
{

	/**
	 * Function: cloneInto
	 * clones the properties of a into b. Does a shallow clone.
	 */
	public static function cloneInto(a:Dynamic,b:Dynamic) {
		for (f in Reflect.fields(a)) {
			var val = Reflect.field(a, f);
			if (Reflect.isObject(val)) {
				Reflect.setField(b, f, Reflect.copy(val));
			}else {
				Reflect.setField(b, f, val);
			}
		}
	}


	/**
	 * Function: mergeInto
	 * merges one object (a) into another (b). does not remove fields from b that aren't in a.
	 * does a deep merge. When comes accross 2 arrays, it does a shallow concat.
	 */

	public static function mergeInto(a:{},b:{}){
		for (f in Reflect.fields(a)) {
			var val:Dynamic = Reflect.field(a, f);
			if(Std.is(val,Array)){
				if(Std.is( Reflect.field(b, f), Array )){
					Reflect.setField(b,f,cast(Reflect.field(b, f), Array<Dynamic>).concat(val));
				} else {
					Reflect.setField(b, f, val);
				}
			}
			else if (Reflect.isObject(val) && !Std.is(val,String)) {
				if(!Reflect.isObject(Reflect.field(b,f))){
					Reflect.setField(b,f,{});
				}
				mergeInto(val,Reflect.field(b,f));
			}else {
				Reflect.setField(b, f, val);
			}
		}
	}

	/*public static function deepClone(o:Dynamic){
		firmament.util.FLog.debug("INPUT "+Std.string(o));
		var a:Dynamic={};
		mergeInto(o,a);
		firmament.util.FLog.debug("OUTPUT "+Std.string(a));

		return a;
	}*/
	/**
		*deep copy of anything
	 **/
	public static function deepClone<T>( v:T ) : T
	{
		if (!Reflect.isObject(v) || Std.is(v,String)) // simple type
		{
			return v;
		}
		else if( Std.is( v, Array ) ) // array
		{
			var r = Type.createInstance(Type.getClass(v), []);
			untyped
			{
			for( ii in 0...v.length )
				r.push(deepClone(v[ii]));
			}
			return r;
		}
		else if( Type.getClass(v) == null ) // anonymous object
		{
			var obj : Dynamic = {};
			for( ff in Reflect.fields(v) )
				Reflect.setField(obj, ff, deepClone(Reflect.field(v, ff)));
			return obj;
		}
		else // class
		{
			var obj = Type.createEmptyInstance(Type.getClass(v));
			for( ff in Reflect.fields(v) )
				Reflect.setField(obj, ff, deepClone(Reflect.field(v, ff)));
			return obj;
		}
		return null;
	}

	public static function doLater(cb:Void->Void){
		FGame.getInstance().getProcessManager().addProcess(new FCallbackProcess({step:function(){
			cb();
			return false;
		}}));
	}

	/**
	 *	sets the value at the specified path to the specified value
	 */
	public static function setObjectValue(path:String,obj:Dynamic,value:Dynamic){
		var steps:Array<String> = path.split('/');
		var currentPos = obj;
		var x=0;

		for(step in steps){
			if(x++ == steps.length -1){
				Reflect.setField(currentPos,step,value);
				break;
			}
			if(step=='')continue;

			var n:Dynamic  = Reflect.field(currentPos,step);
			if(n!=null){
				currentPos = n;
				continue;
			}else{
				Reflect.setField(currentPos,step,{});
				currentPos = Reflect.field(currentPos,step);
			}
		}
	}

	public static function smartSplitWhiteSpace(str:String):Array<Dynamic>{
		var arr:Array<Dynamic> = new Array();
		var buffer:StringBuf = new StringBuf();
		var c:String;
		var f:Float;
		var i=0;
		do{
			c = str.charAt(i);
			if(c == ' ' || c == "\t" || c == ""){
				if(buffer.length > 0){
					f = Std.parseFloat(buffer.toString());
					if(Math.isNaN(f)){
						arr.push(buffer.toString());
					}else{
						arr.push(f);
					}
					buffer = new StringBuf();
				}
			} else {
				buffer.add(c);
			}
			i++;
		} while(c != "");
		return arr;
	}


}
