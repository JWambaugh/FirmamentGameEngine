package firmament.util;



class FLog {
    
    public static inline var ERROR:Int = 1;
    public static inline var WARNING:Int = 2;
    public static inline var DEBUG:Int = 4;

    public static var logLevel:Int = 3;

    public static var loggers:Array<FLogger> = [/*new FTraceLogger(),*/ new FStdoutLogger() ];

    public static function is(level:Int) {
        return ( level&logLevel != 0 );
    }

    public static function error(message:Dynamic,?pos : haxe.PosInfos):Void{
        if(logLevel&ERROR > 0){
            msg("ERROR: "+Std.string(message) + "\n  " 
                + haxe.CallStack.toString(haxe.CallStack.exceptionStack())
                ,pos);
        }
    }

    public static function warning(message:Dynamic,?pos : haxe.PosInfos):Void{
        if(logLevel&WARNING > 0){
            msg("Warning: "+Std.string(message),pos);
        }
    }

    public static function debug(message:Dynamic,?pos : haxe.PosInfos):Void{
        if(logLevel&DEBUG > 0){
            msg("debug: "+Std.string(message),pos);
        }
    }


    public static function msg(message:String="", ?pos : haxe.PosInfos):Void{
        for (logger in loggers){
            if(pos!=null)
                logger.log(pos.className+"#"+pos.methodName+"("+pos.lineNumber+"):"+message);
            else{
                logger.log(message);
            }
        }
    }


    
}

interface FLogger{
    public function log(message:String):Void;
}

class FStdoutLogger implements FLogger{
    public function new(){

    }

    public function log(message:String){
        #if (flash9 || flash10)
        untyped __global__["trace"](message);
        #elseif flash
        flash.Lib.trace(message); 
        #elseif neko
        neko.Lib.println(message);
        #elseif cpp
        cpp.Lib.println(message);
        #end
    }

}

class FTraceLogger implements FLogger{
    public function new(){

    }

    public function log(message:String){
        trace(message);
    }

}
