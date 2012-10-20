package firmament.utils.loader.serializer;
import firmament.utils.loader.serializer.FSerializerInterface;

import hxjson2.JSON;
import tjson.TJSON;
/**
 * ...
 * @author Jordan Wambaugh
 */

class FJsonSerializer implements FSerializerInterface
{
	public function new() {
		
	}
	public function unserialize(data:String):Dynamic {
		
		return TJSON.parse(data);
		
	}
	
	public function serialize( object:Dynamic):String {
		return JSON.encode(object);
	}
	
	public function canProccessFileName(fileName:String):Bool {
		return (fileName.indexOf('.json') >= 0);
	}
	
}
