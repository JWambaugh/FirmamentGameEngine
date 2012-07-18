
package firmament.ui;

/**
 * use as a mixin for extra tools with config values
 */
class FStyleHelper {
	public static function get(o:Dynamic, key:String, ?def:Dynamic=null):Dynamic{
		if(Reflect.hasField(o,key))	
			return Reflect.field(o,key);
		
		return def;
		
	}

}
