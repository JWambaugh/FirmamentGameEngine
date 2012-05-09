
package firmament.ui;

/**
 * use as a mixin for extra tools with config values
 */
class FStyleHelper {
	public static function get(o:Dynamic, key:String, ?def:Dynamic=null){
		var val = Reflect.field(o,key);
		if(Std.is(val,null)) val = def;
		return val;
	}

}
