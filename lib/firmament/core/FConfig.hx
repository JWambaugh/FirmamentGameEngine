package firmament.core;

import firmament.core.FVector;
import firmament.core.FGame;
import firmament.scene.FScene;
import firmament.util.FRepository;
import firmament.util.FLog;
import firmament.core.FEntity;
import firmament.component.base.FEntityComponent;
import firmament.core.FEntityCollection;


@:forward
abstract FConfig({}) from {} to {} {


    public function new(o:Dynamic/*,?pos:PosInfos*/){
        if(Std.is(o, String)){
            throw "Cannot convert string to FConfig!";
        }
        /*trace('Called from ${pos.className}');
        trace('Called from ${pos.methodName}');
        trace('Called from ${pos.fileName}');
        trace('Called from ${pos.lineNumber}');*/
        this = o;
    }

    @:arrayAccess public inline function arrayAccess(key:String):Dynamic {
        return get(key);
    }

    @:arrayAccess public inline function arrayWrite<T>(key:String, value:T):T {
        Reflect.setField(this, key, value);
        return value;
    }

    public function hasField(field:String, type:Dynamic = null){
        if(! Reflect.hasField(this,field)) return false;
        if(type != null){
            return Std.is(Reflect.field(this,field),type);
        }
        return true;
    }

    public function setScope(s:FGameChildInterface):Void{
        Reflect.setField(this, '__SCOPE__', s); //doesn't work
    }

    public function getScope():FGameChildInterface{
        return Reflect.field(this, '__SCOPE__');//doesnt work
        
    }

    public static function filterFields(object):Array<Dynamic> {
        // So the __SCOPE__/__PROGRAM__ field appeared in the field listing
        // which was breaking some of the looping routines, which
        // would then act on the __SCOPE__/__PROGRAM__ property ...
        return Lambda.array(
                    Lambda.filter(
                        object, 
                        function(v) {return StringTools.startsWith(v,"__") == false; } 
                    )
                );
    }

    public function fields(?field:Dynamic=null):Array<Dynamic> {
        var tmp:Array<Dynamic>;
        var mythis = this;
        // if fields is !null attempt to look it up and then 
        // return the fields for the subobject
        if( field != null ) {
            mythis = get(field,Dynamic);
        }

        if( Std.is(this,Array) ) {
            tmp = cast mythis;
        } else {
            tmp = Reflect.fields(mythis);
        }
        return FConfig.filterFields(tmp);
    }

    public function get(field:Dynamic,?type:Dynamic=null,?def:Dynamic=null):Dynamic{
        var entry:Dynamic;

        //allow for chaining an array of subconfig objects
        // example: 
        // {
        //     "parent":{
        //         "child":{
        //             "myKey":"My value"
        //         }
        //     }
        // }
        // config.get(['parent','child','myKey'])
        if(Std.is(field, Array)){
            var fieldArray:Array<String> = cast field;
            if(fieldArray.length < 1) throw "Can't use empty array as field in FConfig.get()!";
            var key:String = fieldArray.shift();
            if(fieldArray.length<1){
                return get(key,type,def);
            }else{
                //just try to set its scope, ignore failure
                var newConfig:FConfig = null;
                
                // returning a new config??
                try { newConfig.setScope( getScope() ); } catch(e:Dynamic) {}
                return newConfig.get(fieldArray,type,def);
            }
        }

        // Allows arrays so keys are not necessary
        //  ie. components wouldn't need names anymore
        if( Std.is(this,Array) ) {
            var asArray:Array<Dynamic> = cast( this, Array<Dynamic> );
            entry = asArray[ Std.parseInt(field) ];
        } else {
            entry =  Reflect.field(this,field);
        }

        if(Reflect.isObject(entry)) {
            // Property Conversions
            if(Std.is(entry,firmament.core.FProperty)) {
                var property:firmament.core.FProperty = cast(entry,firmament.core.FProperty);
                entry = property.getDynamic();
            } else {
                // Scripting check
                var scriptObj= Reflect.field(entry,'*script*');
                if(Std.is(scriptObj,String)) {
                    entry = runScript(entry);
                } else {
                    // Repository check
                    var repoObj = Reflect.field(entry,'*repository*');
                    if(Std.is(repoObj,String)){
                        entry = FRepository.getInstance().get(repoObj);
                    }
                }
            }
        }

        // if I'm an array this doesn't seem to work.
        if(entry == null)return def;
        if(type==null){
            if(entry == null){
                return def;
            }else{
                return entry;
            }
        }else{
            if(Std.is(type,Array)){
                for(t in cast(type,Array<Dynamic>)){
                    if(Std.is(entry,t)){
                        return entry;
                    }
                }
                return def;
            }else{
                if(Std.is(entry,type)){
                    return entry;
                }else{
                    if(type==Int && Reflect.isObject(entry)){
                        return parseIntObject(entry,def);
                    }
                    else if(type==Float && Reflect.isObject(entry)){
                        return parseFloatObject(entry,def);
                    }
                    else if(type==String && (Std.is(entry,Float) || Reflect.isObject(entry)) ){
                        return parseStringObject(entry,def);
                    }
                    else if(type==FVector && Reflect.isObject(entry)){
                        return parseVectorObject(entry,def);
                    }
                    else if(type==Bool && Reflect.isObject(entry)){
                        return parseBoolObject(entry,def);
                    }
                    else if(type == FEntity && entry != null){
                        return getEntities(entry).first();
                    }
                    else if(type == FEntityCollection && entry != null){
                        return getEntities(entry);
                    }
                    else {
                        FLog.warning("field "+field+" is not type expected! Returning default.");
                        return def;
                    }

                }
            }
        }
    }

    public function getVector(field:String,?def:Dynamic=null){
        if(def == null)def={x:0,y:0};
        var v = vectorFromDynamic(Reflect.field(this,field));
        if(v == null) return vectorFromDynamic(def);
        return v;
    }

    public function destruct(){
        //clear reference to parent
        Reflect.setField(this, '__SCOPE__', null);
    }

    private function vectorFromDynamic(d:Dynamic):FVector{
        return parseVectorObject(d);
    }

    private function getEntities(d:Dynamic){
        var scope = getScope();
        var e:FEntity=null;
        try{ //ignore errors here
            e = cast (scope, FEntityComponent).getEntity();
        }catch(ex:Dynamic){}
        if(scope == null) throw "Scope required for querying entities!" + Std.string(this);
        return scope.getGameInstance().queryEntities(d, e);
    }

    private function parseVectorObject(v:Dynamic,d:FVector=null):FVector {
        // vector is { x: Float, y: Float }
        //           [ Float, Float ],
        //           [ Float ]
        //           []
        var error:Bool = false;
        var a:Array<Float> = [0.0,0.0];

        if( Std.is(v,FVector) ){return v;}

        if(Reflect.isObject(v)){
            // it might be special
            if( ! Reflect.hasField(v,'x') || ! Reflect.hasField(v,'y') ) {
                var o:Dynamic<FVector> = {};
                if(convertMinMax(v,o) == true ){

                    return new FVector(
                        o.min.x+Math.random()*(o.max.x-o.min.x),
                        o.min.y+Math.random()*(o.max.y-o.min.y)
                    );
                }
                if(convertRandom(v,o) == true ){
                    return o.value;
                }
                if(convertKeyValue(v,o,FVector) == true ){
                    return o.value;
                }
                if(convertSceneProperty(v,o) ==true ) {
                    if( Std.is(o.value,Float ) ) {
                        return o.value;
                    }
                    return parseVectorObject( o.value, d );
                }
                if(Reflect.hasField(v,"*weighted*")){
                    var a:Array<Dynamic> = cast Reflect.field(v,"*weighted*");
                    var k:Array<String> = new Array();
                    var sum:Int=0;
                    for( o in a ) {
                        var f:String = Reflect.fields(o)[0];
                        k.push(f);
                        sum += Std.parseInt(f);
                    }
                    var rand:Int = Std.random(sum);
                    var target:Int = rand;
                    for( i in 0...a.length) {
                        var o = a[i];
                        var w = k[i];
                        target -= Std.parseInt(w);
                        if( target <= 0 ) {
                            var value:FVector = parseVectorObject(Reflect.field(o,w));
                            return value;
                        }
                    }
                }
                error = true;
            } else {
                a[0] = parseFloat(v.x);
                a[1] = parseFloat(v.y);
            }
        } else {
            error = true;
        }

        if( error ) {
            return d;
        }

        return new FVector(a[0], a[1]);
    }

    private function parseFloat(v:Dynamic):Float {
        if(Std.is(v,Float) || Std.is(v,Int)) {
            return v + 0.0;
        }
        if(Std.is(v,String) ) {
            return Std.parseFloat(v);
        }
        else if(Reflect.isObject(v)) {
            return parseFloatObject(v);
        }
        throw "Unexpected value passed as float <"+v+">";
    }

    private function parseFloatObject(v:Dynamic,d:Float=0.0):Float{
        if( Std.is(v,String) ) {
            // try to parse
            var value:Float = Std.parseFloat(v);
            if(!Math.isNaN( value ) ) {
                return value + 0.0;
            }
            throw "Failed to parse Float from string : " + v;
        }
        var o:Dynamic<Float> = {};
        if(convertMinMax(v,o) == true ){
            return o.min+Math.random()*(o.max-o.min);
        }
        if(convertRandom(v,o) == true ){
            return o.value;
        }
        if(convertKeyValue(v,o,Float) == true ){
            return o.value;
        }
        if(convertSceneProperty(v,o) ==true ) {
            if( Std.is(o.value,Float ) ) {
                return o.value;
            }
            return parseFloatObject( o.value, d );
        }
        if(Reflect.hasField(v,"*weighted*")){
            var a:Array<Dynamic> = cast Reflect.field(v,"*weighted*");
            var k:Array<String> = new Array();
            var sum:Float=0;
            for( o in a ) {
                var f:String = Reflect.fields(o)[0];
                k.push(f);
                sum += Std.parseFloat(f);
            }
            var rand:Float = Math.random() * sum;
            var target:Float = rand;
            for( i in 0...a.length) {
                var o = a[i];
                var w = k[i];
                target -= Std.parseFloat(w);
                if( target <= 0 ) {
                    var value:Float = Std.parseFloat(Reflect.field(o,w));
                    return value;
                }
            }
        }
        return d; // I didn't know what you were
    }

    private function parseBoolObject(v:Dynamic,d:Bool=false):Bool {
        if( Std.is(v,String) ) {
            throw "Failed to parse Bool from string : " + v;
        }
        var o:Dynamic<Bool> = {};
        if(convertRandom(v,o) == true ){
            return o.value;
        }
        if(convertKeyValue(v,o,Bool) == true ){
            return o.value;
        }
        if(convertSceneProperty(v,o) ==true ) {
            if( Std.is(o.value,Bool ) ) {
                return o.value;
            }
            return parseBoolObject( o.value, d );
        }
        if(Reflect.hasField(v,"*weighted*")){
            var a:Array<Dynamic> = cast Reflect.field(v,"*weighted*");
            var k:Array<String> = new Array();
            var sum:Int=0;
            for( o in a ) {
                var f:String = Reflect.fields(o)[0];
                k.push(f);
                sum += Std.parseInt(f);
            }
            var rand:Int = Std.random(sum);
            var target:Int = rand;
            for( i in 0...a.length) {
                var o = a[i];
                var w = k[i];
                target -= Std.parseInt(w);
                if( target <= 0 ) {
                    var value:Bool = Reflect.field(o,w);
                    return value;
                }
            }
        }
        return d; // I didn't know what you were
    }

    private function parseIntObject(v:Dynamic,d:Int=0):Int{
        if( Std.is(v,String) ) {
            // try to parse
            var value:Null<Int> =  Std.parseInt(v);
            if( value != null ) {
                return value;
            }
            throw "Failed to parse Int from string : " + v;
        }
        var o:Dynamic<Int> = {};
        if(convertMinMax(v,o) == true ){
            return o.min+Math.floor(Math.random()*(o.max-o.min));
        }
        if(convertRandom(v,o) == true ){
            return o.value;
        }
        if(convertKeyValue(v,o,Int) == true ){
            return o.value;
        }
        if(convertSceneProperty(v,o) ==true ) {
            if( Std.is(o.value,Int ) ) {
                return o.value;
            }
            return parseIntObject( o.value, d );
        }
        if(Reflect.hasField(v,"*weighted*")){
            var a:Array<Dynamic> = cast Reflect.field(v,"*weighted*");
            var k:Array<String> = new Array();
            var sum:Int=0;
            for( o in a ) {
                var f:String = Reflect.fields(o)[0];
                k.push(f);
                sum += Std.parseInt(f);
            }
            var rand:Int = Std.random(sum);
            var target:Int = rand;
            for( i in 0...a.length) {
                var o = a[i];
                var w = k[i];
                target -= Std.parseInt(w);
                if( target <= 0 ) {
                    var value:Int = Std.parseInt(Reflect.field(o,w));
                    return value;
                }
            }
        }
        return d; // I didn't know what you were
    }

    private function parseStringObject(v:Dynamic,d:String):String{
        if(Std.is(v,Float)){
            return Std.string(v);
        }
        var o:Dynamic<String> = {};
        if(convertRandom(v,o) == true ){
            return o.value;
        }
        if(convertKeyValue(v,o,String) == true ){
            return o.value;
        }
        if(convertSceneProperty(v,o) ==true ) {
            if( Std.is(o.value,String ) ) {
                return o.value;
            }
            return parseStringObject( o.value, d );
        }
        if(Std.is(v,String)) {
            return v;
        }
        return d;
    }

    private function runScript(v:Dynamic):Dynamic{
        var program:hscript.Expr = null;
        var script = Reflect.field(v,'*script*');
        if(Reflect.isObject(v) ){
            //if we have a compiled program already, use it
            program = Reflect.field(v,'__PROGRAM__');
            if(program == null && Std.is(script, String)){
                var parser = new hscript.Parser();
                program = parser.parseString(script);
                Reflect.setField(this,'__PROGRAM__',program);
            }else{
                FLog.error('program is null and script is not string');
            }
            if(program != null){
                var game:FGame;
                var programScope = Reflect.field(this,'__SCOPE__');
                if(programScope == null)  {
                    game = FGame.getInstance();
                }
                else {
                    game = programScope.getGameInstance();
                }
                return game.execProgram(program, programScope);
            }else{
                FLog.warning("Program failed to parse.");
                return null;
            }
        }
        return null;
    }

    public function getNotNull(field:Dynamic,?type:Dynamic=null,?def:Dynamic=null):Dynamic{
        var ret = get(field,type,def);
        if(ret == null){
            throw "Field "+field+" does not exist or is not a valid type";
        }
        return ret;
    }

    // Helper functions
    private function convertMinMax<T>( v:Dynamic, o:Dynamic<T> ):Bool {
        if(Reflect.hasField(v,"*min*") && Reflect.hasField(v,"*max*") ) {
            o.min = Reflect.field(v,"*min*");
            o.max = Reflect.field(v,"*max*");
            return true;
        }
        return false;
    }

    private function convertSceneProperty<T>( v:Dynamic, o:Dynamic<T> ):Bool {
        if(Reflect.hasField(v,"*sceneProperty*") ) {
            var scene:FScene = FGame.getInstance().getCurrentScene();
            // do I need to match types here?
            o.value = scene.getPropertyValue( Reflect.field( v, "*sceneProperty*" ) );
            return true;
        }
        return false;
    }

    private function convertKeyValue<T>( v:Dynamic, o:Dynamic<T>, type:Dynamic ):Bool {
        if(Reflect.hasField(v,"*key*") && Reflect.hasField(v,"*values*")){
            var c:FConfig = v;
            var key:String = c.get("*key*",String);
            var values:FConfig = c.get("*values*");
            // FLog.debug("Result - " + values.get( key ));
            o.value = values.get( key, type );
            return true;
        }
        return false;
    }

    private function convertRandom<T>( v:Dynamic, o:Dynamic<T> ):Bool {
        if(Reflect.hasField(v,"*random*")){
            var a:Array<T> = cast Reflect.field(v,"*random*");
            var key = Math.floor(Math.random()* a.length);
            o.value = a[key];
            return true;
        }
        return false;
    }

}
