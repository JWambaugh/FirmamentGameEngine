package firmament.sound;

import flash.media.Sound;
import openfl.Assets;
/**
 * Firmament Sound Repository. Also manages volumes.
 *
 *
 */
class FSoundManager{
	private static var _soundHash:Map<String,Sound>;

	private static var _masterVolume:Float=.7;
	private static var _soundVolume:Float=1;


	private static function init(){
		if(_soundHash == null){
			_soundHash = new Map();
		}
	}
	/**
	 * returns the specified sound object from the repository
	 * @param name The file name of the sound asset
	 *
	 */
	public static function getSound(name:String):Sound{
		init();
		var s = _soundHash.get(name);
		if(s==null){
			s = Assets.getSound(name);
			_soundHash.set(name,s);
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


	
	public static function setMasterVolume(volume:Float) {
		_masterVolume = volume;
	}

	
	public static function setSoundVolume(volume:Float) {
		_soundVolume = volume;
	}

	public static function getMasterVolume() {
		return _masterVolume;
	}


	public static function getSoundVolume() {
		return _soundVolume;
	}

	/**
	 * Returns the effective sound volume, after master volume is applied.
	 *
	 */
	public static function getEffectiveSoundVolume() {
		return _soundVolume*_masterVolume;
	}

	
}
