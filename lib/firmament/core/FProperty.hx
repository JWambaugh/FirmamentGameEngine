package firmament.core;

import firmament.core.FBasicProperty;
import firmament.core.FVector;

class FProperty{
	private var _key:String;

	public static function createBasic(key:String, type:Dynamic):FProperty{
		if(type == Int) {
			var p = new FBasicProperty<Int>(key);
			return p;
		}
		if(type == Float) {
			var p = new FBasicProperty<Float>(key);
			return p;
		}
		if(type == Bool) {
			var p = new FBasicProperty<Bool>(key);
			return p;
		}
        if(type == FVector){
            var p = new FBasicProperty<FVector>(key);
            return p;
        }
		var p = new FBasicProperty<Dynamic>(key);
		return p;
	}

    public static function createComputed(key:String, type:Dynamic, getter:Void->Dynamic, setter:Dynamic->Void):FProperty{
        if(type == Int) {
            var p = new FComputedProperty<Int>(key,getter,setter);
            return p;
        }
        if(type == Float) {
            var p = new FComputedProperty<Float>(key,getter,setter);
            return p;
        }
        if(type == Bool) {
            var p = new FComputedProperty<Bool>(key,getter,setter);
            return p;
        }
        if(type == FVector){
            var p = new FComputedProperty<FVector>(key,getter,setter);
            return p;
        }
        var p = new FComputedProperty<Dynamic>(key,getter,setter);
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