package firmament.sound;

import firmament.util.FRepository;
import flash.media.Sound;
import openfl.Assets;
import firmament.core.FConfig;
import firmament.util.loader.FDataLoader;

using StringTools;
/**
 * Firmament Sound Repository. Also manages volumes.
 *
 *
 */
class FSoundManager{
	private static var _soundHash:Map<String,Sound>;
	private static var _repository:FRepository = null;
	private static var _config:FConfig = null;

	private static var _masterVolume:Float=.7;
	private static var _soundVolume:Float=1;
	private static var _extensionReg:EReg;

	private static function init(){
		if(_extensionReg == null) _extensionReg = ~/\.(wav|mp3|ogg)$/;
		if(_soundHash == null){
			_soundHash = new Map();
		}
		if(_repository == null){
			_repository = FRepository.getInstance();
		}
		if(_config == null) {
			// this totally isn't the way I want to do this in the end but for 
			// now is ok.
			//uncaught exception if the file doesn't exist.
			try{
			_config = FDataLoader.loadData("config/audio/sounds.json");
			}catch(e:Dynamic){
				firmament.util.FLog.warning("could not find hardcoded sound config file config/audio/sounds.json");

			}
		}
	}
	/**
	 * returns the specified sound object from the repository
	 * @param name The file name of the sound asset
	 *
	 */
	public static function getSound(name:String):Sound{
		init();
		// name needs to be converted to a file name
		var s = _soundHash.get(name);
		if(s != null) return s;

		//first attempt using standards to get sound
		var newName:String;
		//Check if it has right extension
		if(name.indexOf("."+getPlatformFormat())!=-1){
			newName = name;
		}else{
			//if it has an extension, replace the extension with this one
			if(_extensionReg.match(name))
				newName = _extensionReg.replace(name, getPlatformFormat());
			else //otherwise just add the extension to the name
				newName = name+getPlatformFormat();
		}
		if(newName == null){
			firmament.util.FLog.warning("Could not find audio file that matches "+name+" for this platform! (needs "+getPlatformFormat()+"+");
		}
		if(Assets.exists(newName,SOUND)){
			s = Assets.getSound(newName);
			_soundHash.set(name,s); //record the given name in the hash as a shortcut
			_soundHash.set(newName,s);
			return s;
		}

		//if here, couldn't automatically find the sound. use config.
		name = convertNameToPath(name);
		s = _soundHash.get(name);
		if(s==null){
			s = Assets.getSound(name);
			_soundHash.set(name,s);
		}
		return s;
	}


	public static function convertNameToPath(name:String):String {
		// I need to know the avail formats (as a list)
		// the first one I find is the one I'll use
        firmament.util.FLog.debug("Parsing "+ _config);
		var supportedFormats:Array<String> = _repository.get('soundFormats'); // prolly only need to do this once
        firmament.util.FLog.debug("Supported formats "+ supportedFormats);
		var asset:Dynamic = null;
		var sounds:Array<Dynamic> = _config["sounds"];
        firmament.util.FLog.debug("Sound configurations "+ sounds);
		var sound:FConfig = null, format:String = null;
		for( raw in sounds ) {
			sound = raw;
			var sname:String = sound["name"];
			if( sname != name ) {continue;}
			var formats:Array<String> = sound["formats"];
			for( supportformats in supportedFormats ) { // this should be in hash?
				for( raw2 in formats ) {
					format = raw2;
					if( supportformats == format ) {
						asset = sound;
						break;
					}
				}
				if (asset != null ) {break;}
			}
			if (asset != null ) {break; }
		}
		if( asset == null ) { 
			firmament.util.FLog.msg( name +" did not match any tags" );
			return ""; 
		}

		var assetPath:String = new String(sound["format"]);
        firmament.util.FLog.debug("Format "+ assetPath);
		// build the correct path
		assetPath = StringTools.replace( assetPath, "{basedir}", sound["basedir"]);
		assetPath = StringTools.replace( assetPath, "{name}", sound["name"]);
		assetPath = StringTools.replace( assetPath, "{format}", format);
        firmament.util.FLog.debug("Format "+ assetPath);

		// find the asset with the correct name
		return assetPath;
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

	public static function getPlatformFormat():String{
		#if(flash)
		return "mp3";
		#else
		return "ogg";
		#end
	}

	/**
	 * Returns the effective sound volume, after master volume is applied.
	 *
	 */
	public static function getEffectiveSoundVolume() {
		return _soundVolume*_masterVolume;
	}

	
}
