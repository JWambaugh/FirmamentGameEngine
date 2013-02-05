package firmament.util.loader.serializer;
import firmament.util.loader.serializer.FSerializerInterface;

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
	public function unserialize(data:String,?fileName:String=''):Dynamic {
		
		return TJSON.parse(data,fileName);
		
	}
	
	public function serialize( object:Dynamic):String {
		return Render.as_json(object);
	}
	
	public function canProccessFileName(fileName:String):Bool {
		return (fileName.indexOf('.json') >= 0);
	}
	
}
