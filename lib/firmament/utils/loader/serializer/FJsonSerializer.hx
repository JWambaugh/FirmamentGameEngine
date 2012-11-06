package firmament.utils.loader.serializer;
import firmament.utils.loader.serializer.FSerializerInterface;

import nice_json.Render;
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
		return Render.as_json(object);
	}
	
	public function canProccessFileName(fileName:String):Bool {
		return (fileName.indexOf('.json') >= 0);
	}
	
}
