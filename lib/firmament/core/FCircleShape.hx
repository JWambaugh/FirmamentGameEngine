
package firmament.core;
import firmament.core.FVector;
class FCircleShape extends FShape{

	var _radius:Float;
	var _localPosition:FVector;
	
	public function new(r:Float,pos:FVector){
		super();
		setRadius(r);
		_localPosition = pos;
	}

	public function getRadius():Float{
		return _radius;
	}

	public function setRadius(r:Float){
		_radius = r;
	}
	public function getLocalPosition():FVector{
		return _localPosition;
	}
	

}