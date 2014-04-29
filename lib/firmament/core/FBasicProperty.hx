package firmament.core;
import firmament.core.FProperty;

class FBasicProperty<T> extends FProperty{
	
	private var _value:T;

	public function new(key:String){
		super(key);
	}

	override public function set(value:Dynamic){
		_value = cast value;
	}

	override public function getFloat():Float{
		return cast _value;
	}

	override public function getInt():Int{
		return cast _value;
		
	}

	override public function getString():String{
		return cast _value;
		
	}

	override public function getBool():Bool{
		return cast _value;
		
	}

	override public function getDynamic():Dynamic{
		return _value;
	}


}