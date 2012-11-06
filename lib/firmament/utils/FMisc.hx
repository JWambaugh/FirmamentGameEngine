package firmament.utils;

/**
 * Class: FMisc
 * @author Jordan Wambaugh
 */

class FMisc 
{

	/**
	 * Function: cloneInto
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


	/**
	 * Function: mergeInto
	 * merges one object into another. does not remove fields from b that aren't in a.
	 */

	public static function mergeInto(a:Dynamic,b:Dynamic){
		for (f in Reflect.fields(a)) {
			var val = Reflect.field(a, f);
			if (Reflect.isObject(val)) {
				if(!Reflect.isObject(Reflect.field(b,f))){
					Reflect.setField(b,f,{});
				}
				mergeInto(Reflect.field(a,f),Reflect.field(b,f));
			}else {
				Reflect.setField(b, f, val);
			}
		}
	}
	
}