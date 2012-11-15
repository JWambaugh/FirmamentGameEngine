
package firmament.core;

class FPolygonShape extends FShape{
	var _vectors:Array<FVector>;
	
	public function new(v:Array<FVector>){
		super();
		_vectors = v;
	}


	public function getVectors():Array<FVector>{
		return _vectors;
	}

}