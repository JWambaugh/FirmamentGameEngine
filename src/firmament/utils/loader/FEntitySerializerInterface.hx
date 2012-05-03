package firmament.utils.loader;

/**
 * ...
 * @author Jordan Wambaugh
 */

interface FEntitySerializerInterface{
	function unserialize(fileName:String):Dynamic;
	function serialize(fileName:String,config:Dynamic):Void;
	function canProccessFileName(fileName:String):Bool;
}