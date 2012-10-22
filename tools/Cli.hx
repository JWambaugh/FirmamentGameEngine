
import neko.FileSystem;
import neko.io.Path;
import Sys;
import neko.Lib;

import sys.FileSystem;
import sys.io.File;
import StringTools;
using StringTools;
class Cli {
	
	static var firmamentPath:String;
	static var projectHomeDir:String;
	public static function main() {
		var args:Array<String> = Sys.args();
		var last:String = (new neko.io.Path(args.pop())).toString();
		var slash = last.substr( -1);

	
		firmamentPath = Sys.getCwd();
		
		if (slash=="/"|| slash=="\\") 
			last = last.substr(0,last.length-1);
		if (neko.FileSystem.exists(last) && neko.FileSystem.isDirectory(last)) {
			Sys.setCwd(last);
		}
		
		
		if (args.length == 0) {
				Lib.println("possible commands: setup");
				return;
		}
		
		switch(args[0]) {
			case "setup": {
				if (args.length < 2) {
					Lib.println("setup requires project name.");
					return;
				}
				doSetup(args[1]);
			}
		}
		
		
		
		
	}
	
	static function doSetup(projectName:String, ?packageName:String = "com.firmamentengine.example", ?template:String = "SimpleProject") {
		projectName = ucFirst(projectName);
		Lib.println("Creating new project...");
		if (FileSystem.exists(projectName)) {
			Lib.println("Directory '" + projectName + "' already exists.");
			return;
		}
		
		var templatePath = firmamentPath + "/templates/" + template;
		if (!FileSystem.exists(templatePath)) {
			Lib.println("Template '"+template+"' cannot be found.");
			return;
		}
		
		Lib.println("Creating project '"+projectName+"' ...");
		
		var vars = { 
			PROJECT_NAME:projectName
			,PACKAGE_NAME:packageName
		
		};
		
		projectHomeDir = Sys.getCwd()+projectName;

		processTemplateDir(templatePath, projectName,vars,projectName,"__SRC__");
		
		var sourceCodeDir = projectName + "/src/" + packageName.replace(".", "/");
		makeDirRecursive(sourceCodeDir);
		processTemplateDir(templatePath+"/__SRC__", sourceCodeDir,vars,projectName);
			
			
		
		Lib.println("Project '" + projectName + "' Created! Run the following to try it out:");
		Lib.println("cd " + projectName);
		Lib.println("nme test "+projectName+".nmml flash");
	}
	
	static function makeDirRecursive(path:String) {
		var dirs = path.split("/");
		var workingPath = "";
		for (dir in dirs) {
			if (workingPath != '') dir = workingPath + '/' + dir;
			if (!FileSystem.exists(dir)) {
				FileSystem.createDirectory(dir);
			}
			workingPath = dir;
			
		}
	}
	
	static function processTemplateDir(srcDir:String, destDir:String, vars:Dynamic, projectName:String,?skipDir:String='') {
		if (!FileSystem.isDirectory(srcDir)) {
			Lib.println(srcDir + " is not a directory!");
			return;
		}
		if (!FileSystem.exists(destDir)) {
			FileSystem.createDirectory(destDir);
		}
		
		
		
		var entries = FileSystem.readDirectory(srcDir);
		
		for (entry in entries) {
			var sdir = srcDir + "/" + entry;
			if (FileSystem.isDirectory(sdir)) {
				
				//only process if we aren't in our skip directory.
				if (skipDir == '' || sdir.indexOf(skipDir) == -1) {
					processTemplateDir(sdir, destDir+'/'+entry, vars, projectName, skipDir);
				}
			}
			else {
				smartCopy(entry,srcDir, destDir , vars, projectName);
			}
		}
		
		
	}
	
	static function smartCopy(fileName:String,srcDir:String, destDir:String, vars:Dynamic, projectName:String) {
		var data = File.getContent(srcDir+"/"+fileName);
		
		var destFile = fileName.replace("__PROJECT_NAME__", projectName);
		
		//do interpolation if the filename is any of these types
		if (stringContainsAny(fileName, [".hx", ".nmml", ".xml", ".md", ".htm", ".html", ".txt",".fprj",".sublime"])){
			data = interpolateVarsIntoString(data, vars);
		}
		File.saveContent(destDir + "/" + destFile,data);
			
	}
	
	static function interpolateVarsIntoString(str:String, vars:Dynamic):String {
		vars.HAXE_PATH = Sys.getEnv("HAXEPATH");
		vars.FIRMAMENT_PATH = firmamentPath.replace("\\","/");
		vars.PROJECT_HOME_PATH = projectHomeDir.replace("\\","/");
		//no colon varieties
		vars.PROJECT_HOME_PATH_NC = projectHomeDir.replace("\\","/").replace(":","");
		vars.FIRMAMENT_PATH_NC = firmamentPath.replace("\\","/").replace(":","");
		var fields = Reflect.fields(vars);
		for (field in fields) {
			str=str.replace("[*" + field + "*]", Reflect.field(vars, field));
		}
		return str;
	}
	
	static function stringContainsAny(str:String, substrs:Array<String>) {
		for (substr in substrs) {
			if (str.indexOf(substr) != -1) return true;
		}
		return false;
	}
	
	static function ucFirst(str:String) {
		var first = str.charAt(0);
		first = first.toUpperCase();
		return first + str.substr(1);
	}


	
}