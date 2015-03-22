
package firmament.component.entity;

import flash.Lib;

import firmament.util.FLog;
import firmament.component.base.FEntityComponent;
import firmament.core.FConfig;
import firmament.core.FEntity;
import firmament.core.FEvent;
import firmament.process.timer.FTimer;
import firmament.core.FVector;

/*
    Class: FEventMapperComponent
    maps events on the entity of a type to another event of a different type.
*/
class FTextComponent extends FEntityComponent{
    
    var _textField:flash.text.TextField;
    var _textFormat:flash.text.TextFormat;
    var _glowFilter:flash.filters.GlowFilter;

    public function new(gameInstance:firmament.core.FGame){
        super(gameInstance);
    }

    public function initialize(config:FConfig){

    }

    override public function onActivate(){
        // 0, 0 is top left
        // need to get the camera position and turn it into 
        // scene
        _textField.x = 500; // _entity.getProp("postitionX");
        // _textField.y = _entity.getProp("postitionY");

        log("Position ({_textField.x},{_textField.y})");
    }

    override public function init(config:FConfig){
        useStep(true);
        log("Getting value ");

        _glowFilter = new flash.filters.GlowFilter(
            0x000000, // color
            1.0,
            2.0,
            2.0,
            10
        );
        _glowFilter.quality=flash.filters.BitmapFilterQuality.MEDIUM;

        _textFormat = new flash.text.TextFormat();
        _textFormat.align=_config.get('align',String,"left");
        _textFormat.font=_config.get('font',String,"Arial");
        _textFormat.color=_config.get('color',Int,0xDD1111);
        _textFormat.size=_config.get('size',Int,30);
        _textFormat.letterSpacing=3;
        
        // should I create this now??
        _textField = new flash.text.TextField();
        _textField.text = "";
        _textField.mouseEnabled=false;
        _textField.defaultTextFormat = _textFormat;
        _textField.filters = [ _glowFilter ];

        _config.get('value'); // checking for existance early on

        initialize(config);

        onActivate();

        var stage = Lib.current.stage;
        stage.addChild(_textField);
    }

    override public function getType(){
        return "textBox";
    }

    override public function step(delta:Float){
        var camera = _gameInstance.getCamera('main');
        var pos:FVector = _entity.getProp('position');
        var screenPosition:FVector = camera.getScreenPosition( 
             pos.x + _config.get('offsetX',Float,0),
             pos.y + _config.get('offsetY',Float,0) );

        _textField.x = screenPosition.x;
        _textField.y = screenPosition.y;

        _textField.text=_config.getNotNull('value');

        if(Math.random() <= .1) {
            log("Value - " + _textField.text + " Position - " + screenPosition);
        }
    }

    override public function destruct(){
        var stage = Lib.current.stage;
        stage.removeChild(_textField);
        super.destruct();
    }
}