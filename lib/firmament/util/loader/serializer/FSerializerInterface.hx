package firmament.util.loader.serializer;

/**
 * ...
 * @author Jordan Wambaugh
 */

interface FSerializerInterface{
	function unserialize(data:String):Dynamic;
	function serialize(object:Dynamic):String;
	function canProccessFileName(fileName:String):Bool;
}