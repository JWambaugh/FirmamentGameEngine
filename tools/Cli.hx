
import neko.FileSystem;
import neko.io.Path;
import sys.FileSystem;
import sys.io.File;

class Cli {
	public static function main() {
		var args:Array<String> = Sys.args();
		var last:String = (new neko.io.Path(args.pop())).toString();
		var slash = last.substr(-1);
		if (slash=="/"|| slash=="\\") 
			last = last.substr(0,last.length-1);
		if (neko.FileSystem.exists(last) && neko.FileSystem.isDirectory(last)) {
			neko.Sys.setCwd(last);
		}
		
		
		if (args.length == 0) {
				trace("possible commands: setup");
				return;
		}
		
		switch(args[0]) {
			case "setup": {
				if (args.length < 2) {
					trace("setup requires project name.");
					return;
				}
				doSetup(args[1]);
			}
		}
		
		
		
		
	}
	
	static function doSetup(projectName:String) {
		trace("Creating new project...");
		if (FileSystem.exists(projectName)) {
			trace("Directory '" + projectName + "' already exists.");
			return;
		}
		FileSystem.createDirectory(projectName);
		neko.Sys.setCwd(projectName);
		FileSystem.createDirectory("assets");
		FileSystem.createDirectory("src");
		FileSystem.createDirectory("assets/images");
		FileSystem.createDirectory("assets/entities");
		FileSystem.createDirectory("assets/maps");
		File.saveContent(projectName + ".fprj", "{\"baseDir\":\".\",\"entityDir\":\"assets\\/entities\",\"mapDir\":\"assets\\/maps\" } ");
		
		var nmml="<?xml version=\"1.0\" encoding=\"utf-8\"?>\n"+
			"<project>\n"+
			"<!-- metadata, make sure 'package' is at least 2 segments (ie. com.myproject) -->\n"+
			"<app file=\""+projectName+"\" title=\""+projectName+"\" main=\"com.firmamentengine.example.Main\" package=\"com.firmamentengine.example\" \n"+
			"	version=\"1.0.0\" company=\"\" />\n"+
			"<!-- output -->"+
			"<window width=\"800\" height=\"480\" fps=\"30\" background=\"0xFFFFFF\" orientation=\"landscape\" resizable=\"true\" />\n"+
			"<set name=\"BUILD_DIR\" value=\"bin\" />\n"+
			"\n"+
			"<!-- classpath, haxe libs -->\n"+
			"<classpath name=\"src\" />\n"+
			"\n"+
			"<haxelib name=\"nme\" /><haxelib name=\"hxJson2\" />\n" +
			"<haxelib name=\"Firmament.hx\" />\n"+	
			"\n"+
			"<!-- assets -->\n"+
			"<assets path=\"assets\" include=\"*\"  />\n"+
			"\n"+
			"<!-- DLLs -->\n"+
			"<ndll name=\"std\" />\n"+
			"<ndll name=\"regexp\" />\n"+
			"<ndll name=\"zlib\" />\n"+
			"<ndll name=\"nme\" haxelib=\"nme\" />\n"+
			"\n"+
			"</project>\n";
			File.saveContent(projectName + ".nmml", nmml);
			
			
			
			
			
			
			neko.Sys.setCwd("..");
	}
	
	
}