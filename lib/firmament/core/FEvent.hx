package firmament.core;

class FEvent{

	public var name(get,set):String;
	public var data(get,set):Dynamic;

	private var _name:String;
	private var _data:Dynamic;

	public function new(name:String,?data:Dynamic = null){
		_name = name;
		_data = data;
	}

	public function get_name():String{
		return _name;
	}

	public function set_name(val:String){
		_name = val;
		return _name;
	}

	public function get_data():Dynamic{
		return _data;
	}

	public function set_data(val:Dynamic){
		_data = val;
		return _data;
	}
}