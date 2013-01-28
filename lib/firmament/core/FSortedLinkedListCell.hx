package firmament.core;

import firmament.core.FSortedLinkedList;

class FSortedLinkedListCell<T>{
	
	var _sortValue:Float;
	var _value:T;
	var _next:FSortedLinkedListCell<T>;
	var _previous:FSortedLinkedListCell<T>;
	var _list:FSortedLinkedList<T>;

	public function new(value:T, sortValue:Float, list:FSortedLinkedList<T>){
		_value = value;
		_sortValue = sortValue;
		_list = list;
		_next = null;
		_previous = null;
	}

	public function getValue(){
		return _value;
	}

	public function getSortValue():Float{
		return _sortValue;
	}


	public function getNext():FSortedLinkedListCell<T>{
		return _next;
	}

	/**
	 * Sets the next cell.
	 * Automatically calls setPrevious() on cell.
	 */
	public function setNext(cell:FSortedLinkedListCell<T>){
		_next = cell;
		if(cell!= null)
			cell.setPrevious(this);
	}

	public function getPrevious(){
		return _previous;
	}

	/**
	 * Sets the previous cell. Usually just called from the setNext() method so you don't have to call this as well
	 */
	public function setPrevious(cell:FSortedLinkedListCell<T>){
		_previous = cell;
	}
}