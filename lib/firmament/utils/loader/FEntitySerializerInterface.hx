package firmament.utils.loader;

/**
 * ...
 * @author Jordan Wambaugh
 */

interface FEntitySerializerInterface{
	function unserialize(data:String):Dynamic;
	function serialize(object:Dynamic):String;
	function canProccessFileName(fileName:String):Bool;
}