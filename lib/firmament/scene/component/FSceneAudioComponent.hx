
package firmament.scene.component;

import firmament.core.FConfig;
import firmament.core.FEvent;
import firmament.core.FGame;
import firmament.scene.FSceneComponent;
import firmament.sound.FSoundtrackManager;
import firmament.core.FPropertyInterface;
import firmament.core.FPropertyDefinition;

// import firmament.util.loader.FDataLoader;

class FSceneAudioComponent extends FSceneComponent {

	private var _events:FConfig;
	private var _repeat:Bool;
	private var _paused:Bool;
	private var _triggers:FConfig;
	private var _soundTrackName:String;

	public function new(gameInstance:FGame)
	{
		super(gameInstance);
	}

	override public function init(config:FConfig):Void {
		_soundTrackName = config.get('fileName',String,null);					//supports 'fileName' or 'tag'
		_soundTrackName = config.getNotNull('tag',String,_soundTrackName);
//trace(_soundTrackName );
		_repeat = config.get('repeat',Bool,true);
//trace(_repeat );
		_paused = config.get('paused',Bool,false);
//trace(_paused );

		FSoundtrackManager.setVolume( config.get('volume',Float,1.0) );
//trace( FSoundtrackManager.getVolume() );

		var listeners:FConfig = config.get('listeners');
// trace( listeners );
		for( event in listeners.fields() ) {
// trace( event );
			switch( event ){
				case "play":
					on(_scene,listeners.get(event,String),onPlay);
				case "stop":
					on(_scene,listeners.get(event,String),onStop);
			}
		}

		_triggers = config.get('triggers',Dynamic,{});
		
		if( _paused == false ) {
			on(_scene,FScene.COMPONENTS_INITIALIZED,onPlay);
		}
	}

	public function getType() {
		return "soundTrack";
	}

	override public function getProperties():Array<FPropertyDefinition>{
        var props:Array<FPropertyDefinition> = [
        	{
                key:'soundTrack'
                ,type:String
                ,getter:getSoundTrack
                ,setter:setSoundTrack
                ,sortOrder:1
            },
            {
                key:'volume'
                ,type:Float
                ,getter:getVolume
                ,setter:setVolume
                ,sortOrder:1
            }
        ];
        return props;
    }

    public function getSoundTrack(p:String=''):String {
    	return _soundTrackName;
    }

    public function setSoundTrack(track:String):Void {
    	if(	_soundTrackName != track ) {
    		_soundTrackName = track;
    		if( _paused == false ) {
    			play();
    		} else {
    			stop();
    		}
    	}
    }

    public function getVolume(v:Float=0):Float {
    	return FSoundtrackManager.getVolume();
    }

    public function setVolume(v:Float):Void {
    	return FSoundtrackManager.setVolume(v);

    }

	public function play() {
//trace( "Starting audio!" );
		FSoundtrackManager.play(_soundTrackName,_repeat);
	}

	public function stop() {
//trace( "Stopping audio!" );
		FSoundtrackManager.stop();
	}

	public function onPlay(e:FEvent) {
		play();
		if( _triggers.hasField('play') ) {
trace( "Trigger play!" );
			_scene.trigger( new FEvent( _triggers.get('play') ) );
		}
	}

	public function onStop(e:FEvent) {
trace( "Trigger stop!" );
		stop();
		if( _triggers.hasField('stop') ) {
trace( "Trigger stop!" );
			_scene.trigger( new FEvent( _triggers.get('stop') ) );
		}
	}
}