package firmament.core;

import firmament.core.FSortedLinkedListCell;
import firmament.core.FSortedLinkedListIterator;

/**
 * Sorted Double-linked list implementation
 * Sorted by Float.
 * Does NOT support changing of sort value after an item's been added.
 *
 */
class FSortedLinkedList<T>{

	var _first:FSortedLinkedListCell<T>;
	var _cellCount:Int;
	var _last:FSortedLinkedListCell<T>;

	public function new(){
		_first = null;
		_cellCount = 0;
	}

	/**
	 * Adds an item to the list based on sort order
	 *
	 */
	public function add(item:T, sortValue:Float){
		var cell = new FSortedLinkedListCell<T>(item,sortValue,this);
		if(_first == null){
			_first = cell;
			_last = cell;
		}else{
			var iCell = _first; //iterator cell
			var pCell = null;	//previous cell
			while(iCell != null){
				if(sortValue <= iCell.getSortValue()){ //cell should go before this cell
					if(pCell == null){
						_first = cell;
						_first.setPrevious(null);
					}else{
						pCell.setNext(cell); //setNext also sets previous automatically on that cell
					}
					cell.setNext(iCell);
					break;
				}
				pCell = iCell;
				iCell = iCell.getNext();
				if(iCell == null){
					pCell.setNext(cell); // add to end if it's greater than all previous cells
					_last = cell;
				}
			}
		}
		_cellCount++;
		return cell;
	}

	/**
	 * Gets the cell with the lowest value in the list
	 * Does not remove the item from the list.
	 * Be extremely careful modifying the cell. 
	 * This should only be used for iterating over the contents of the list with getNext().
	 */
	public function getLowestCell(){
		return _first;
	}

	/**
	 * Gets the lowest value in the list
	 * Does not remove the item from the list.
	 */
	public function getLowestValue(){
		return _first.getValue();
	}

	/**
	 * removes the lowest value from the list and returns it
	 *
	 */
	public function getRemoveLowestCell(){
		var cell = _first;
		_first = cell.getNext();
		if(_first!=null)
			cell.getNext().setPrevious(null);
		_cellCount--;
		return cell;
	}

	/**
	 * removes the lowest Cell from the list and returns it
	 *
	 */
	public function getRemoveLowestValue(){
		return getRemoveLowestCell().getValue();
	}



	/**
	 * Gets the cell with the highest value in the list
	 * Does not remove the item from the list.
	 * Be extremely careful modifying the cell. 
	 * This should only be used for iterating over the contents of the list with getPrevious().
	 */
	public function getHighestCell(){
		return _last;
	}


	/**
	 * Gets the highest value in the list
	 * Does not remove the item from the list.
	 */
	public function getHighestValue(){
		return _last.getValue();
	}

	/**
	 * removes the highest cell from the list and returns it
	 *
	 */
	public function getRemoveHighestCell(){
		var cell = _last;
		_last= cell.getPrevious();
		cell.getPrevious().setNext(null);
		_cellCount--;
		return cell;
	}


	/**
	 * removes the highest cell from the list and returns it
	 *
	 */
	public function getRemoveHighestValue(){
		return getRemoveHighestCell().getValue();
	}


	/**
	 * Returns the number of entries in the list
	 */
	public function getCellCount(){
		return _cellCount;
	}

	public function removeCell(cell:FSortedLinkedListCell<T>){
		var next = cell.getNext();
		var previous = cell.getPrevious();
		if(previous!=null){
			previous.setNext(next);
		}else{
			_first = next;
		}
		if(next != null){
			next.setPrevious(previous);
		}else{
			_last = previous;
		}
	}

    public function iterator():Iterator<T>{
        return new FSortedLinkedListIterator(this);
    }


}