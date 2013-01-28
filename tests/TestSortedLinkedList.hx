
package ;

import firmament.core.FSortedLinkedList;
class TestSortedLinkedList extends haxe.unit.TestCase {
    
    var ll:FSortedLinkedList<Int>;
	override public function setup() {
        ll = new FSortedLinkedList();

        ll.add(24,24);
        ll.add(2,2);
        ll.add(100,100);
        ll.add(55,55);
        ll.add(78,78);
        ll.add(5,5);
	}

    public function testBasicGetValue(){
    	assertEquals(6,ll.getCellCount());
        assertEquals(2,ll.getLowestValue());
        assertEquals(100,ll.getHighestValue());
    	assertEquals(6,ll.getCellCount());

    }

    public function testGetRemoveLowest(){
    	assertEquals(6,ll.getCellCount());
    	assertEquals(2,ll.getRemoveLowestValue());
    	assertEquals(5,ll.getRemoveLowestValue());
    	assertEquals(24,ll.getRemoveLowestValue());
    	assertEquals(55,ll.getLowestValue());
    	assertEquals(3,ll.getCellCount());

    }

    public function testGetRemoveHighest(){
    	assertEquals(6,ll.getCellCount());
    	assertEquals(100,ll.getRemoveHighestValue());
    	assertEquals(78,ll.getRemoveHighestValue());
    	assertEquals(55,ll.getRemoveHighestValue());
    	assertEquals(3,ll.getCellCount());

    }
    
}