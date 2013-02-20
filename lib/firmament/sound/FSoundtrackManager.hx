package firmament.sound;

import nme.media.Sound;
import nme.media.SoundChannel;
import nme.media.SoundTransform;
import firmament.sound.FSoundManager;
class FSoundtrackManager{

	private static var _soundChannel:SoundChannel;
	private static var _volume:Float = 1;

	public static function play(name:String){
		if(_soundChannel != null){
			_soundChannel.stop();
		}
		var sound = FSoundManager.getSound(name);
		_soundChannel = sound.play();
		setVolume(_volume);
	}

	public function stop(){
		if(_soundChannel != null){
			_soundChannel.stop();
		}
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
}