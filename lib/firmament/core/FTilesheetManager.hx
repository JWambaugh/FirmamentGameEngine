package firmament.core;

/**
 * ...
 * @author jordan wambaugh
 */
class FTilesheetManager {
	
	
	static var _instance:FTilesheetManager;
	var idCounter:Int;
	private function new () {
		idCounter = 0;
		
		
	}
	
	public static function getInstance(){
		if (_instance == null) {
				_instance = new FTilesheetManager();
		}
		return _instance;
	}

	public function genTilesheetId(){
		return this.idCounter++;
	}
	
	
	
	
	
	

}
