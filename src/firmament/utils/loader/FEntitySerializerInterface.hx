package firmament.utils.loader;

/**
 * ...
 * @author Jordan Wambaugh
 */

interface FEntitySerializerInterface{
	function unserialize(identifier:String):Dynamic;
	function serialize(identifier:String,config:Dynamic):Void;
	
}