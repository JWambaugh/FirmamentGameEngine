package firmament.utils.loader.serializer;

import firmament.utils.loader.serializer.FSerializerInterface;
import firmament.utils.loader.serializer.FJsonSerializer;

/**
 * ...
 * @author Jordan Wambaugh
 */

class FSerializerFactory 
{

	static var serializers:Array<FSerializerInterface>;
	public static function getSerializerForFile(fileName:String):FSerializerInterface {
		if (serializers == null) {
			serializers = new Array<FSerializerInterface>();
			//add all supported serializers here
			serializers.push(new FJsonSerializer());
		}
		
		for (s in serializers) {
			if (s.canProccessFileName(fileName)) {
				return s;	
			}
		}
		return null;
	}
	
}