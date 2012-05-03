package firmament.utils.loader.serializer;
import firmament.utils.loader.FEntitySerializerInterface;

import hxjson2.JSON;
/**
 * ...
 * @author Jordan Wambaugh
 */

class FJsonSerializer implements FEntitySerializerInterface
{
	public function new() {
		
	}
	public function unserialize(data:String):Dynamic {
		
		return JSON.decode(data);
		
	}
	
	public function serialize( object:Dynamic):String {
		return JSON.encode(object);
	}
	
	public function canProccessFileName(fileName:String):Bool {
		return (fileName.indexOf('.json') >= 0);
	}
	
}