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
import firmament.core.FVector;
import openfl.Assets;
import flash.display.BitmapData;
import flash.display.IBitmapDrawable;
import flash.display.Sprite;
import openfl.display.Tilesheet;
import flash.events.Event;
import flash.events.EventDispatcher;
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
	var drawList:Array<Float>;
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
	var _kerning:Float;
	var _positionData:PositionData;

	var _textAlign:String;


	public function new() {
		imageScale=100;
		super();
		drawList = new Array<Float>();
		_parallax = 1;
		_flipX = false;
		_flipY = false;
		_positionOffset = new FVector(0,0);
		_angleOffset = 0;
	}

	override public function init(config:Dynamic){
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
		_kerning = ch.get("kerning",Float,0);
		_textAlign = ch.get("textAlign",String,"center");

		calculatePositions();
	}
	

	public function initTilesheet(){
		var image = _config.image;
		var imageIsFileName = false;
		if(Std.is(_config.tilesheetFile,String)){
			_tilesheet = FTilesheetManager.getInstance().getTilesheetFromDefinitionFile(_config.tilesheetFile);
			if(_tilesheet == null){
				throw('tilesheet file "'+_config.tilesheetFile+'" could not be loaded');
			}
		}
		else if(image !=null){
			if(Std.is(image,FTilesheet)){
				_tilesheet = cast(image);
			}else{
				var bd:BitmapData;
				if(Std.is(image,String)){
					//trace("image: " + Std.string(image));
					bd = Assets.getBitmapData(cast(image,String));
					
				}
				else if(Std.is(image,BitmapData)){
					bd = cast(image,BitmapData);
				}
				else{
					throw("invalid tileSheetImage");
				}
				_tilesheet = new FTilesheet(bd);
				if(imageIsFileName){
					_tilesheet.setImageFileName(cast(image,String));
				}
				_tilesheet.addTileRect(new Rectangle (0, 0, bd.width, bd.height),new Point(bd.width/2,bd.height/2));
			}
		}else{
			//try to get a tilesheet from the animation
			var animationC = _entity.getComponent("animation");
			if(animationC!=null){
				var c = cast(animationC,FAnimationComponent);
				c.jumpToFrame(0);
			}
		}
	}

	public function render(camera:FCamera):Void {
		
		//make sure we are currently active 
		if(!_entity.isActive())return;

		FTilesheetRenderHelper.getInstance().initCamera(camera);
		if (_tilesheet == null) {
			trace('tilesheet is null');
			return;
		}

		this._entity.dispatchEvent(new Event(FGame.BEFORE_RENDER));
		
		var physicsComponent:FPhysicsComponentInterface = this._entity.getPhysicsComponent();
		if(physicsComponent == null) return;
		var cameraPos = camera.getTopLeftPosition(this._parallax);
		var ratio = camera.getZoom() / imageScale;
		var pos = physicsComponent.getPosition();



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
			drawList[0] = nx;
			drawList[1] = ny;
			drawList[2] = letter.tile; // sprite index
			drawList[3] = a;
			drawList[4] = b;
			drawList[5] = c;
			drawList[6] = d;

			drawList[7] = _r;
			drawList[8] = _g;
			drawList[9] = _b;
			//drawList[3] = ratio;
			//drawList[4] = physicsComponent.getAngle();
			drawList[10] = _alpha;
			
			FTilesheetRenderHelper.getInstance().addToDrawList(_tilesheet, drawList);
		}
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
		for(index in 0..._text.length){

			var letter = _text.charAt(index);
			var tile = _tilePrefix + letter;
			var code = letter.charCodeAt(0);
			if(code >= 97 && code <= 122){ //add 'l' for lowercase chars
				tile+='l';
			}
			var tileId = _tilesheet.getTileNumber(tile);
			var tileWidth = _tilesheet.getRectangle(tileId).width/this.imageScale;
			var tileHeight = _tilesheet.getRectangle(tileId).height/this.imageScale;
			var letterData:LetterPositionData = {
				tile:tileId
				,xOffset:_positionData.width+tileWidth/2
				,yOffset:0
			};
			_positionData.letters.push(letterData);
			_positionData.width+=((tileWidth )+_kerning);
			if(tileHeight > _positionData.height)_positionData.height = tileHeight;
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