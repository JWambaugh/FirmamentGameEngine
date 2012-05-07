package firmament.utils;

/**
 * Class: FMisc
 * @author Jordan Wambaugh
 */

class FMisc 
{

	/**
	 * Function: copyInto
	 * clones the properties of a into b
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
	
}