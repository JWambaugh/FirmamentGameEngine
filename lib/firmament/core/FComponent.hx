package firmament.core;

import firmament.core.FPropertyContainer;
class FComponent extends FObject{
    
    var _parent:FPropertyContainer;
    private var _config:Dynamic;

    var _gameInstance:FGame;

    public function new(gameInstance:FGame) {
        super();
        _gameInstance = gameInstance;
    }


    public function init(config:FConfig):Void {
        throw "This needs to be overwritten in a subclass.";
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

    /**
     * Should be overridden to implement a destructor
     */
    override public function destruct(){
        super.destruct();
    }
}