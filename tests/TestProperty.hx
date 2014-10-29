package ;
import firmament.core.FProperty;
import firmament.core.FComputedProperty;
class TestProperty extends haxe.unit.TestCase {
	var value:Int;
	override public function setup() {
       value = 1;
	}

	private function getVal():Int{
		return value;
	}
/*
    public function testPerformance(){
 		var t = Sys.cpuTime();
 		for(x in 0...10000000){
 			var x = getVal();
 		}
 		firmament.util.FLog.debug(Sys.cpuTime() - t);

 		var property = FProperty.createBasic("test",Int);
 		property.set(1);
 		var t = Sys.cpuTime();
		for(x in 0...10000000){
 			var x=property.getInt();
 		}
 		firmament.util.FLog.debug(Sys.cpuTime() - t);

 		var t = Sys.cpuTime();
		for(x in 0...10000000){
 			var x=property.getDynamic();
 		}
 		firmament.util.FLog.debug(Sys.cpuTime() - t);


 		property.set(1);
 		var t = Sys.cpuTime();
		for(x in 0...10000000){
 			var x=property.getString();
 		}
 		firmament.util.FLog.debug(Sys.cpuTime() - t);

 		assertEquals(1,1);
    }*/


    public function testBasicProperty(){
    	var p = FProperty.createBasic("test",Int);
    	p.set(1);
    	assertEquals(1,p.getDynamic());
    	assertEquals(1,p.getInt());

    	p.set(123);
    	assertEquals(123,p.getDynamic());
    	assertEquals(123,p.getInt());


    	p.set(123.0);
    	assertEquals(123,p.getDynamic());
    	assertEquals(123,p.getInt());


    	var p = FProperty.createBasic("test",Float);
		p.set(123.0);
    	assertEquals(123.0,p.getDynamic());
    	assertEquals(123.0,p.getFloat());

    }

    private function setter(v:Int){
    	value = v;
    }
    private function getter():Int{
    	return value;
    }

    public function testComputedProperty(){
    	var p:FProperty = new FComputedProperty<Int>("test",setter,getter);
    	p.set(22);
    	assertEquals(22,p.getInt());
    }

}