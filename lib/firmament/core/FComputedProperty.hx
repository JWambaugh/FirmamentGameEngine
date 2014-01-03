package firmament.core;
import firmament.core.FProperty;

class FComputedProperty<T> extends FProperty{
	
	private var _setter:T->Void;
	private var _getter:Void->T;

	public function new(key:String, setter:T->Void, getter:Void->T){
		super(key);
		_setter = setter;
		_getter = getter;
	}


	override public function set(value:Dynamic){
		_setter(value);
	}

	override public function getFloat():Float{
		return cast _getter();
	}

	override public function getInt():Int{
		return cast _getter();
		
	}

	override public function getString():String{
		return cast _getter();
		
	}

	override public function getBool():Bool{
		return cast _getter();
		
	}

	override public function getDynamic():Dynamic{
		return _getter();
	}


}