package firmament.core;
import firmament.core.FProperty;
import firmament.core.FSortedLinkedList;

class FComputedProperty<T> extends FProperty{
	
	private var _setters:Array<T->Void>;
	private var _getters:FSortedLinkedList<T->T>;

    //sort value gets processed lower -> highest
	public function new(key:String, getter:T->T, setter:T->Void, sortValue=1.0){
		super(key);
        _setters = new Array();
		_getters = new FSortedLinkedList();

        _setters.push(setter);
		_getters.add(getter,sortValue);
	}

    public function add(getter:T->T, setter:T->Void, sortValue=1.0){
        _setters.push(setter);
        _getters.add(getter,sortValue);
    }


	override public function set(value:Dynamic){
		for(setter in _setters){
            setter(value);
        }
	}

	override public function getFloat():Float{
		var v:T = null;
        for(getter in _getters){
            v=getter(v);
        }
        return cast v;
	}

	override public function getInt():Int{
		var v:T = null;
        for(getter in _getters){
            v=getter(v);
        }
        return cast v;
	}

	override public function getString():String{
		var v:T = null;
        for(getter in _getters){
            v=getter(v);
        }
        return cast v;
	}

	override public function getBool():Bool{
		var v:T = null;
        for(getter in _getters){
            v=getter(v);
        }
        return cast v;
	}

	override public function getDynamic():Dynamic{
		var v:T = null;
        for(getter in _getters){
            v=getter(v);
        }
        return v;
	}


}