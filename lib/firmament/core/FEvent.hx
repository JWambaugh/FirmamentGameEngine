package firmament.core;

class FEvent{

	public var name(get,set):String;
	public var data(get,set):Dynamic;


    //if true, all objects receiving this single event will trigger listeners.
    //If set to false, bubbling will not happen unless a listener sets handled to false.
    public var bubbles:Bool=true;

    //if bubbles is false, event handlers will have to set this to false to allow other listeners to receive it.
    public var handled:Bool=false;


	private var _name:String;
	private var _data:Dynamic;



	public function new(name:String,data:Dynamic = null){
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