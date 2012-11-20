
package firmament.utils.loader;

import firmament.utils.FMisc;
import firmament.utils.loader.serializer.FSerializerFactory;
import nme.Assets;
import nme.events.EventDispatcher;
#if(cpp)
import sys.io.File;
#end

/*
	Class: FDataLoader
*/
class FDataLoader 
{
	static var _cache:Hash<Dynamic> = new Hash();

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
		#if cpp
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
		_cache.set(fileName,FMisc.deepClone(data));
		return data;
	}
	

}
