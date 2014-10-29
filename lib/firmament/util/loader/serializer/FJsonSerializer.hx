package firmament.util.loader.serializer;
import firmament.util.loader.serializer.FSerializerInterface;
import openfl.Assets;

#if (cpp || neko)
import sys.io.File;
#end


import tjson.TJSON;

/**
 * ...
 * @author Jordan Wambaugh
 */

class FJsonSerializer implements FSerializerInterface
{
	var _scripts:Array<hscript.Expr>;
	public function new() {
		
	}
	public function unserialize(data:String,?fileName:String=''):Dynamic {
		_scripts = new Array();
		var d = TJSON.parse(data,fileName /*,processStringVal*/);
		d._scripts = _scripts;
		return d;
		
	}
	
	public function serialize( object:Dynamic):String {
		return TJSON.encode(object,new FancyStyle());
	}
	
	public function canProccessFileName(fileName:String):Bool {
		return (fileName.indexOf('.json') >= 0);
	}
/* //This isn't completely done yet, so commenting out. not sure which direction i want to go with this.
	private function processStringVal(val:String):Dynamic{
		if(val.indexOf("@source:") ==0){
			var path = val.substr(8);
			var parser = new hscript.Parser();
			var code = Assets.getText(path);
		
			#if (cpp || neko)
				//firmament.util.FLog.debug('attempting load with file.getContents');
				if (code == null || code == '') {
					code = File.getContent(path);
				}
			#end
			if(code == null) throw "Error loading script from "+path;
			var expr = parser.parseString(code);
			_scripts.push({});
		}

		if(val.indexOf("@script:") ==0){
			var code = val.substr(8);
			var parser = new hscript.Parser();
			var expr = parser.parseString(code);
			_scripts.push(expr);
		}
		return val;
	}*/
	
}
