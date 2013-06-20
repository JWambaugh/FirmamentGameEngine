package firmament.util.loader.serializer;
import firmament.util.loader.serializer.FSerializerInterface;


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
		return TJSON.encode(object,'fancy');
	}
	
	public function canProccessFileName(fileName:String):Bool {
		return (fileName.indexOf('.json') >= 0);
	}
	
}
