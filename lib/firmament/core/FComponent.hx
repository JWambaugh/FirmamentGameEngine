package firmament.core;

import firmament.core.FConfig;
import firmament.core.FGameChildInterface;
import firmament.core.FPropertyContainer;
import firmament.core.FPropertyDefinition;
import firmament.util.FLog;



class FComponent extends FObject implements firmament.core.FStepSubscriber implements FGameChildInterface{
    
    var _parent:FPropertyContainer;
    private var _usesStep:Bool;

    private var _config:FConfig;
    private var _enableDebug:Bool;

    var _gameInstance:FGame;

    public function new(gameInstance:FGame) {
        super();
        _usesStep = false;
        _gameInstance = gameInstance;
    }

    //called by factory
    public function _init(config:FConfig){
        _enableDebug = _config.get( 'debug', Bool, false );
        _config.setScope(this);
        this.init(config);
    }

    public function init(config:FConfig):Void {
        throw "This needs to be overwritten in a subclass.";
    }

    public function log(message:Dynamic,force:Bool = false){
        var msg:String = Std.string(message);
        if( _enableDebug == true || force == true ) {
            FLog.msg(msg);
        } else {
            FLog.debug(msg);
        }
    }


    public function useStep(u:Bool = true){
        if(_usesStep && !u){
            _gameInstance.removeStepSubscriber(this);
        }else{
            _gameInstance.addStepSubscriber(this);
        }
        _usesStep = u;
    }

    //called by FGame instance
    public function _doStep(delta:Float){
        if(_usesStep)
            step(delta);
    }

    public function step(delta:Float){

    }

    public function setConfig(c:Dynamic){
        _config = c;
    }

    public function getConfig(){
        return _config;
    }

    public function setParent(parent:FPropertyContainer){
        _parent = parent;
    }

    public function getProperties():Array<FPropertyDefinition>{
        return [];
    }

    //entity property helpers
    public function registerProp(key:String, type:Dynamic, getter:Dynamic->Dynamic=null, setter:Dynamic->Void=null){
        
        _parent.registerProp(key,type,getter,setter);
    }

    public function getProp(key:String){
        return _parent.getProperty(key).getDynamic();
    }

    public function setProp(key:String,value:Dynamic){
        _parent.getProperty(key).set(value);
    }

    public function getGameInstance():firmament.core.FGame{
        return _gameInstance;
    }

    /**
     * Should be overridden to implement a destructor
     */
    override public function destruct(){
        //FLog.warning('destructor called');
        _config.destruct();
        _config = null;
        _parent = null;
        _gameInstance = null;
        super.destruct();
    }
}