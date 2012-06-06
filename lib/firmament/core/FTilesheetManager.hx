package firmament.core;

/**
 * ...
 * @author jordan wambaugh
 */
class FTilesheetManager {
	
	
	static var _instance:FTilesheetManager;
	private function new () {
		
		
		
	}
	
	public function getInstance(){
		if (_instance == null) {
				_instance = new FTilesheetManager();
		}
		return _instance;
	}
	
	
	
	
	
	

}
