package firmament.core;

import firmament.core.FBasicProperty;

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
		var p = new FBasicProperty<Dynamic>(key);
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