
package firmament.util.loader;

import firmament.util.FMisc;
import firmament.util.loader.serializer.FSerializerFactory;
import nme.Assets;
import nme.events.EventDispatcher;
#if (cpp || neko)
import sys.io.File;
#end

/*
	Class: FDataLoader
*/
class FDataLoader 
{
	static var _cache:Hash<Dynamic> = new Hash();
	static var _recursionCount:Int;
	public static function loadData(fileName:String, ?allowEmpty:Bool=false):Dynamic{

		trace("Processing: " + fileName);
		if(_cache.exists(fileName)){
			return FMisc.deepClone(_cache.get(fileName));
		}
		var serializer = FSerializerFactory.getSerializerForFile(fileName);
		if (serializer == null) {
			throw ("Appropriate serializer for fileName "+fileName+" could not be found.");
		}
		var string = Assets.getText(fileName);
		
		#if (cpp || neko)
			//trace('attempting load with file.getContents');
			if (string == null || string == '') {
				string = File.getContent(fileName);
			}
		#end

		if(string==null || (!allowEmpty && string == '')){
			throw("Error reading data from "+fileName);
		}
		var data = serializer.unserialize(string);
		if (data == null) {
			throw("Data could not be unserialized for "+fileName);
		}
		data.entityFile = fileName;

		if(Std.is(data._extends,String)){
			_recursionCount++;
			if(_recursionCount > 100 )throw "recursive _extends detected in "+fileName;
			var parent = loadData(data._extends);
			_recursionCount--;
			FMisc.mergeInto(data,parent);
			data = parent;
			trace(Std.string(data));
		}
		_cache.set(fileName,FMisc.deepClone(data));
		return data;
	}
	

}
