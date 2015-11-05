package firmament.core;

// import firmament.core.FBasicProperty;
import firmament.core.FPropertyInterface;
import firmament.core.FVector;

class FProperty{
	private var _key:String;
    public var type:Dynamic;

	public static function createBasic(key:String, type:Dynamic):FProperty{
		if(type == Int) {
			var p = new FBasicProperty<Int>(key);
            p.type = type;
			return p;
		}
		if(type == Float) {
			var p = new FBasicProperty<Float>(key);
            p.type = type;
			return p;
		}
		if(type == Bool) {
			var p = new FBasicProperty<Bool>(key);
            p.type = type;
			return p;
		}
        if(type == String) {
            var p = new FBasicProperty<String>(key);
            p.type = type;
            return p;
        }
        if(type == FVector){
            var p = new FBasicProperty<FVector>(key);
            p.type = type;
            return p;
        }
		var p = new FBasicProperty<Dynamic>(key);
        p.type = type;
		return p;
	}

    public static function createComputed(key:String, type:Dynamic, getter:Dynamic->Dynamic, setter:Dynamic->Void):FProperty{
        if(type == Bool) {
            var p = new FComputedProperty<Bool>(key,getter,setter);
            p.type = type;
            return p;
        }
        if(type == Int) {
            var p = new FComputedProperty<Int>(key,getter,setter);
            p.type = type;
            return p;
        }
        if(type == Float) {
            var p = new FComputedProperty<Float>(key,getter,setter);
            p.type = type;
            return p;
        }
        if(type == FVector){
            var p = new FComputedProperty<FVector>(key,getter,setter);
            p.type = type;
            return p;
        }
        if(type == String){
            // Added for completeness
            var p = new FComputedProperty<String>(key,getter,setter);
            p.type = type;
            return p;
        }
        var p = new FComputedProperty<Dynamic>(key,getter,setter);
            p.type = type;
        return p;
    }

	public function getKey():String{
		return _key;
	}

	public function set(value:Dynamic){

	}

	private function new(key:String){
		_key = key;
	}

	public function getFloat():Float{
		return 0.0;
	}

	public function getInt():Int{
		return 0;
	}

	public function getString():String{
		return null;
	}

	public function getBool():Bool{
		return false;
	}

	public function getDynamic():Dynamic{
		return null;
	}

}