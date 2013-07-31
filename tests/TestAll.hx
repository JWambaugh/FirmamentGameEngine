
package ;
import TestSortedLInkedList;
import TestGridWorld;
class TestAll {
    function new(){

    }
    static function main(){
        var r = new haxe.unit.TestRunner();
        r.add(new TestSortedLinkedList());
        r.add(new TestGridWorld());
        // your can add others TestCase here

        // finally, run the tests
        r.run();
    }
}