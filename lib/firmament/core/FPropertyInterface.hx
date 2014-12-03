package firmament.core;

typedef PropertyDefinition={
    key:String,
    type:Dynamic,
    setter:Dynamic->Void,
    getter:Void->Dynamic
};

interface FPropertyInterface{
    public function hasProperty(key:String):Bool;
    
    public function getProperty(key:String):FProperty;

    public function getPropertyValue(key:String):Dynamic;

    public function setPropertyValue(key:String,value:Dynamic):Void;
}