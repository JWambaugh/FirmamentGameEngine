
package firmament.scene.component;

import flash.Lib;

import firmament.core.FConfig;
import firmament.core.FVector;
import firmament.scene.FSceneComponent;
import firmament.util.FLog;
import firmament.util.FStatistics;

class FSceneDisplayStatisticsComponent extends FSceneComponent {

	private var _textField:flash.text.TextField;
    private var _textFormat:flash.text.TextFormat;
	private var _statistics:FStatistics;
    private var _screenPosition:FVector;

	public function new(gameInstance:Dynamic) 
	{
		super(gameInstance);
		_statistics = FStatistics.getInstance();
	}


    public function getType(){
        return "displayStats";
    }

	override public function init(config:FConfig):Void {
        if( FLog.is(FLog.DEBUG)  || config.get('force',Bool,false)) {
            useStep(true); // this turns on the module
        }

		var _glowFilter:flash.filters.GlowFilter = new flash.filters.GlowFilter(
            _config.get('outlineColor',Int,0x000000), // color
            1.0,
            2.0,
            2.0,
            10
        );
        _glowFilter.quality=flash.filters.BitmapFilterQuality.MEDIUM;
        
        _textFormat = new flash.text.TextFormat();
        _textFormat.align=_config.get('align',String,"left");
        _textFormat.font=_config.get('font',String,"Arial");
        _textFormat.color=_config.get('color',Int,0xDDDDDD);
        _textFormat.size=_config.get('size',Int,10);
        _textFormat.letterSpacing=3;
        
        // should I create this now??
        _textField = new flash.text.TextField();
        _textField.text = "";
        _textField.width=_config.get('width',Int,1000); // in meters?
        _textField.mouseEnabled=false;
        _textField.multiline=true;
        _textField.defaultTextFormat = _textFormat;
        _textField.filters = [ _glowFilter ];

        var stage = Lib.current.stage;
        stage.addChild(_textField);

        var camera = _gameInstance.getCamera('main');
        _screenPosition = camera.getScreenPosition( 
             _config.get('positionX',Float,0),
             _config.get('positionY',Float,0) );

        _textField.x = _screenPosition.x;
        _textField.y = _screenPosition.y;
	}

	override public function destruct(){
        var stage = Lib.current.stage;
        stage.removeChild(_textField);
        super.destruct();
	}

	override public function step(delta:Float) {
		var camera = _gameInstance.getCamera('main');
        
        var textValue:Dynamic = "";
        var count = 0;
        for( key in _statistics.keys() ) {
            count++;
            var value = _statistics.getProp(key);
            log("Pulling - " + key + ": " + value);
        	textValue += key + ": " + value + "\n";
        }
        
        if( _textField != textValue ) {
            _textField.height=_textFormat.size * count * 2;
            _textField.text=textValue;
        }

        if(Math.random() <= .1) {
            log("Value - " + _textField.text + " Position - " + _screenPosition);
        }
	}
}