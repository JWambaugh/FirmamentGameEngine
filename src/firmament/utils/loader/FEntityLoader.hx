package firmament.utils.loader;
import firmament.core.FEntity;
import firmament.utils.loader.FEntitySerializerInterface;
import firmament.core.FWorld;
import firmament.utils.loader.serializer.FJsonSerializer;
import firmament.utils.FMisc;

/**
 * ...
 * @author Jordan Wambaugh
 */

 
 /**
  * Class: FEntityLoader
  */
class FEntityLoader 
{

	static var serializers:Array<FEntitySerializerInterface>;
	
	
	static function getSerializerForFile(fileName:String):FEntitySerializerInterface {
		if (serializers == null) {
			serializers = new Array<FEntitySerializerInterface>();
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
	
	
	
	/**
	 * Function: loadEntity
	 */
	public static function loadEntity(fileName:String, world:FWorld, config:Dynamic) {
		var serializer = getSerializerForFile(fileName);
		if (serializer == null) {
			throw ("Appropriate serializer for fileName "+fileName+" could not befound.");
		}
		var data = serializer.unserialize(fileName);
		if (data == null) {
			throw("entity data could not be unserialized for "+fileName);
		}
		FMisc.cloneInto(config,data);
		var ent:FEntity;
		if (Std.is(data.className, String)) {
			ent = Type.createInstance(Type.resolveClass(data.className), [world,data]);
		}else {
			ent = new FEntity(world, data);
		}
		
	}
	
	
	
}