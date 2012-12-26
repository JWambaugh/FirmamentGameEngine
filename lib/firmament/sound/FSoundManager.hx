package firmament.sound;

import nme.media.Sound;
import nme.Assets;

class FSoundManager{
	private static var soundHash:Hash<Sound>;

	private static function init(){
		if(soundHash == null){
			soundHash = new Hash();
		}
	}

	public static function getSound(name:String){
		init();
		var s = soundHash.get(name);
		if(s==null){
			s = Assets.getSound(name);
			soundHash.set(name,s);
		}
		return s;
	}

	/**
	* Pre-loads the list of sound files.
	*/
	public static function loadSounds(soundNames:Array<String>){
		for(name in soundNames){
			getSound(name);
		}
	}


}