package firmament.util;


class FGuidManager{

	private static var _guidSeed:Int = 0;



	public static function getGuid(){
		var guid = haxe.crypto.Sha1.encode(_guidSeed+"_"+Math.random());
		_guidSeed++;
		return guid;
	}

}