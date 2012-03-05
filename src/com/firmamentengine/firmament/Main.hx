package com.firmamentengine.firmament;

import com.firmamentengine.firmament.FGame;
/**
 * ...
 * @author Jordan Wambaugh
 */

class Main 
{
	
	static public function main() 
	{
		#if (flash9 || flash10)
		haxe.Log.trace = function(v,?pos) { untyped __global__["trace"](pos.className+"#"+pos.methodName+"("+pos.lineNumber+"):",v); }
		#elseif flash
		haxe.Log.trace = function(v,?pos) { flash.Lib.trace(pos.className+"#"+pos.methodName+"("+pos.lineNumber+"): "+v); }
		#end
		var game = new FGame();
		
		
	}
	
	
}