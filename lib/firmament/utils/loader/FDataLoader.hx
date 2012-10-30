
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

	public static function loadData(fileName:String, ?allowEmpty:Bool=false):Dynamic{
		var serializer = FSerializerFactory.getSerializerForFile(fileName);
		if (serializer == null) {
			throw ("Appropriate serializer for fileName "+fileName+" could not befound.");
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
		return data;
	}
	

}
