package firmament.core;

import firmament.core.FSortedLinkedListCell;
import firmament.core.FSortedLinkedList;

/**
 * Sorted Double-linked list implementation
 * Sorted by Float.
 * Does NOT support changing of sort value after an item's been added.
 *
 */
class FSortedLinkedListIterator<T>{

    private var _list:FSortedLinkedList<T>;
    private var _next:FSortedLinkedListCell<T>;

    public function new(list:FSortedLinkedList<T>){
       _list = list;
       _next = _list.getLowestCell();
    }


    public function hasNext():Bool{
        return _next != null ;
    }

    public function next():T{
        var n = _next;
        _next = _next.getNext();
        return n.getValue();
       
    }


}