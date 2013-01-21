package firmament.core;


class FSortedLinkedListCell<T>{
	
	var _sortValue:Float;
	var _value:T;
	var _next:FSortedLickedListCell<T>;

	public function new(next:T){
		_next = next;
	}

	public function getSortValue():Float{
		return _sortValue;
	}

	public function setSortValue(val:Float){
		_sortValue = val;
	}

	public function next():FSortedLinkedListCell{
		return _next;
	}
}