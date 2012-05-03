package firmament.utils.loader.serializer;
import firmament.utils.loader.FEntitySerializerInterface;

/**
 * ...
 * @author Jordan Wambaugh
 */

class FJsonSerializer implements FEntitySerializerInterface
{
	public function new() {
		
	}
	public function unserialize(fileName:String):Dynamic {
	}
	public function serialize(fileName:String, config:Dynamic):Void {
		
	}
	public function canProccessFileName(fileName:String):Bool {
		return (fileName.indexOf('.json') >= 0);
	}
	
}