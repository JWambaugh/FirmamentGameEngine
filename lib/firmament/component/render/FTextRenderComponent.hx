package firmament.component.render;



import firmament.component.base.FEntityComponent;
import firmament.component.physics.FPhysicsComponentInterface;
import firmament.component.render.FRenderComponentInterface;
import firmament.core.FCamera;
import firmament.core.FGame;
import firmament.core.FTilesheet;
import firmament.core.FTilesheetManager;
import firmament.core.FTilesheetRenderHelper;
import firmament.component.animation.FAnimationComponent;
import firmament.core.FComputedProperty;
import firmament.core.FVector;
import openfl.Assets;
import flash.display.BitmapData;
import flash.display.IBitmapDrawable;
import flash.display.Sprite;
import openfl.display.Tilesheet;
import firmament.core.FEvent;
import flash.geom.Point;
import flash.geom.Rectangle;


typedef LetterPositionData={
	tile:Int
	,xOffset:Float
	,yOffset:Float
};
typedef PositionData={
	width:Float
	,height:Float
	,letters:Array<LetterPositionData>

};


/**
 * ...
 * @author jordan
 */
class FTextRenderComponent extends FEntityComponent  implements FRenderComponentInterface 
{
	
	var _tilesheet:FTilesheet;
	var imageScale:Float;
	var _parallax:Float;
	var _flipX:Bool;
	var _flipY:Bool;
	
	var _positionOffset:FVector;
	var _angleOffset:Float;

	var _r:Float=1;
	var _g:Float=1;
	var _b:Float=1;
	var _alpha:Float=1;

	var _text:String;
	var _tilePrefix:String;
	var _positionData:PositionData;

	var _textAlign:String;


	public function new() {
		imageScale=100;
		super();
		
		_parallax = 1;
		_flipX = false;
		_flipY = false;
		_positionOffset = new FVector(0,0);
		_angleOffset = 0;
	}

	override public function init(config:Dynamic){
		//trace(Std.string(config));
		this._config = config;
		var ch = getConfigHelper();
		initTilesheet();

		if(_tilesheet == null){
			throw 'tilesheet is still null after init';
		}
		
        if(Std.is(config.imageScale,Float)) {
			imageScale = config.imageScale;
		}

		if(Std.is(config.parallax,Float)){
			_parallax = config.parallax;
		}

		if(Std.is(config.flipX,Bool)){
			_flipX = config.flipX;
		}
		if(Std.is(config.flipY,Bool)){
			_flipY = config.flipY;
		}

		_r=ch.get('red',Float,1.);
		_g=ch.get('green',Float,1.);
		_b=ch.get('blue',Float,1.);
		_alpha=ch.get('alpha',Float,1.);
		_text = ch.get('text',String,"");
		_tilePrefix = ch.get("tilePrefix",String,"");
		_textAlign = ch.get("textAlign",String,"center");
		_entity.registerProperty(new FComputedProperty<String>("text",setText,getText));
		calculatePositions();
	}
	

	public function initTilesheet(){
		
		var imageIsFileName = false;
		
		var ch = getConfigHelper();
		var tilesheetConfig = _config['tilesheet'];
		var fontKey:String = ch.getNotNull('fontKey',String);
		if(Reflect.isObject(tilesheetConfig)){
			_tilesheet = FTilesheetManager.getInstance().findTilesheetWithKey( fontKey );
			if(_tilesheet == null){
				_tilesheet = FTilesheetManager.getInstance().createTilesheet(tilesheetConfig);
				if(_tilesheet == null){
					throw('Tilesheet is null after creation');
				}
				_tilesheet.setDefinitionFileName(fontKey);
				FTilesheetManager.getInstance().addTileSheet(_tilesheet);
			}

		}
		else throw("tilesheet not found in config");
	}

	public function render(camera:FCamera):Void {
		
		//make sure we are currently active 
		if(!_entity.isActive())return;

		FTilesheetRenderHelper.getInstance().initCamera(camera);
		if (_tilesheet == null) {
			throw ('tilesheet is null');
			return;
		}

		_entity.trigger(new FEvent(FGame.BEFORE_RENDER));
		
		var physicsComponent:FPhysicsComponentInterface = this._entity.getPhysicsComponent();
		if(physicsComponent == null) return;
		var cameraPos = camera.getTopLeftPosition(this._parallax);
		var ratio = camera.getZoom() / imageScale;
		var pos = physicsComponent.getPosition();

		var drawList:Array<Float> = new Array();
		var count:Int = 0;
		for(letter in _positionData.letters){
			
			var nx = (((pos.x+_positionOffset.x + letter.xOffset) - cameraPos.x) *_parallax * camera.getZoom());
			var ny = (((pos.y+_positionOffset.y + letter.yOffset) - cameraPos.y) *_parallax * camera.getZoom());
			var a:Float, b:Float,c:Float,d:Float;
			var angle =physicsComponent.getAngle()+_angleOffset;
			//perform rotation and scale
			a = Math.cos(angle)*ratio;
			b = Math.sin(angle)*ratio; 
			c = -Math.sin(angle)*ratio; 
			d = Math.cos(angle)*ratio;
			if(_flipX)a =- a;
			if(_flipY)d =- d;
			drawList[count++] = nx;
			drawList[count++] = ny;
			drawList[count++] = letter.tile; // sprite index
			drawList[count++] = a;
			drawList[count++] = b;
			drawList[count++] = c;
			drawList[count++] = d;

			drawList[count++] = _r;
			drawList[count++] = _g;
			drawList[count++] = _b;
			//drawList[count++] = ratio;
			//drawList[count++] = physicsComponent.getAngle();
			drawList[count++] = _alpha;
			
			FTilesheetRenderHelper.getInstance().addToDrawList(_tilesheet, drawList, _entity.getProp('positionZ'));
		}
		FTilesheetRenderHelper.getInstance().addToDrawList(_tilesheet, drawList, _entity.getProp('positionZ'));
	}

	

	


	public function getTilesheet():FTilesheet{
		return _tilesheet;
	}


	public function setTilesheet(t:FTilesheet){
		_tilesheet = t;
	}


	public function setImageScale(scale:Float){
		imageScale = scale;
	}

	public function getImageScale(){
		return imageScale;
	}
	
	public function getBitmapData():BitmapData{
		var sprite:Sprite = new Sprite();
		var tempAlignment = _textAlign;

		_textAlign='left';
		calculatePositions();
		var drawList:Array<Float> = new Array();
		for(letter in _positionData.letters){
			drawList[0] = letter.xOffset*100;
			drawList[1] = (letter.yOffset+_positionData.height)*100;
			drawList[2] = letter.tile; // sprite index
			drawList[3] = 1;
			_tilesheet.drawTiles(sprite.graphics, drawList, true, Tilesheet.TILE_ALPHA);
		}
		var bd:BitmapData = new BitmapData(Std.int(sprite.width),Std.int(sprite.height));
		bd.draw(sprite);
		_textAlign = tempAlignment;
		calculatePositions();
		return bd;
	}
	
	override public function getType():String {
		return "render";
	}

	public function getParallaxMultiplier():Float{
		return _parallax;
	}

	public function setRGB(r:Float,g:Float,b:Float){
		_r=r;
		_g=g;
		_b=b;
	}

	public function getRGB(){
		return {
			r:_r
			,g:_g
			,b:_b
		}
	}

	public function setAlpha(a:Float){
		_alpha = a;
	}

	public function getAlpha(){
		return _alpha;
	}

	public function getText(){
		return _text;
	}

	public function setText(t:String){
		_text = t;
		calculatePositions();
	}


	/**
	 * precalculates data for rendering of text. 
	 * we do it once when the text is set instead of at render time.
	 */
	private function calculatePositions(){
		_positionData = {
			width:0.0
			,height:0.0
			,letters:[]
		};
		var lineHeight:Float = cast(_config['lineHeight'],Float)/this.imageScale;
		_positionData.height = lineHeight;
		//trace("preparting for text: "+_text);
		for(index in 0..._text.length){

			var letter = _text.charAt(index);
			var letterConfig = Reflect.field(_config['glyphs'],letter);
			var advance:Int = letterConfig.advance;
			if(letter == ' ')trace('got a space');
			if(letterConfig == null) throw("No glyph config found for "+letter);
			var nextLetter = _text.charAt(index+1);
			var tile = _tilePrefix + letter;
			var code = letter.charCodeAt(0);
			
			var tileId = _tilesheet.getTileNumber(tile);
			var tileWidth = _tilesheet.getRectangle(tileId).width/this.imageScale;
			var tileHeight = _tilesheet.getRectangle(tileId).height/this.imageScale;

			var letterData:LetterPositionData = {
				tile:tileId
				,xOffset:_positionData.width+(cast(letterConfig.offset.x,Float)/this.imageScale)
				,yOffset: lineHeight/2 - (cast(letterConfig.offset.y,Float)/this.imageScale)/2
			};
			//trace("yOffset = "+letterData.yOffset);
			if(nextLetter != null){
				var kerning = Reflect.field(letterConfig.kerning,nextLetter);
				if(Std.is(kerning,Int)){
					_positionData.width+=cast(kerning,Float)/this.imageScale;
				}
			}
			if(letter == ' ')trace("xAdvance: "+cast(letterConfig.xAdvance,Float)/this.imageScale);
			_positionData.letters.push(letterData);
			_positionData.width+=(cast(letterConfig.xAdvance,Float)/this.imageScale);
		}

		//adjust text positions for center or right alignment
		if(_textAlign!='left'){
			var diff:Float;
			if(_textAlign =='center'){
				diff = _positionData.width/2;
			}else if(_textAlign == 'right'){
				diff = _positionData.width;
			}else{
				throw "unsupported text align: "+_textAlign;
			}

			for(letter in _positionData.letters){
					letter.xOffset-=diff;
			}
		}

		
	}
	
	
}