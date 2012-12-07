
package firmament.util;

class FRepository {

	static var _instance:FRepository;

	var _hash:Hash<Dynamic>;

	private function new(){
		_hash = new Hash<Dynamic>();
	}


	public static function getInstance():FRepository{
		if(_instance == null){
			_instance = new FRepository();
		}
		return _instance;
	}


	public function set(key:String,val:Dynamic){
		_hash.set(key,val);

	}


	public function get(key:String):Dynamic{
		return _hash.get(key);
	}
}