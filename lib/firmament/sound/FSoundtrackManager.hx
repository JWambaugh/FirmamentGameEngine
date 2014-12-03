package firmament.sound;

import flash.media.Sound;
import flash.media.SoundChannel;
import flash.media.SoundTransform;
import firmament.sound.FSoundManager;

class FSoundtrackManager{

	private static var _soundChannel:SoundChannel;
    private static var _currentSoundName:String;
    private static var _isPlaying:Bool;
	private static var _volume:Float = 1;


	public static function play(name:String, repeat:Bool=true){
        _currentSoundName = name;
		if(_soundChannel != null){
			_soundChannel.stop();
		}
		var currentSound = FSoundManager.getSound(name);
		_soundChannel = currentSound.play();
		_isPlaying = true;
		setVolume(_volume);
        if(repeat){
            _soundChannel.addEventListener('soundComplete',repeatSound);
        }
	}

    private static function repeatSound(e:flash.events.Event){
        play(_currentSoundName,true);
    }

	public static function stop(){
		if(_soundChannel != null){
			_soundChannel.stop();
		}
		_isPlaying = false;
	}

	public static function isPlaying():Bool {
		return _isPlaying;
	}

	/*
		volume is 0-1
	*/
	public static function setVolume(volume:Float){
		_volume = volume;
		if(_soundChannel != null){
			var transform = new SoundTransform(_volume*FSoundManager.getMasterVolume());
			_soundChannel.soundTransform = transform;
		}
	}

	public static function getVolume(){
		return _volume;
	}
}