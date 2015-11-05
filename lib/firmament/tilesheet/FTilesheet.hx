package firmament.tilesheet;
import openfl.display.Tilesheet;
import firmament.tilesheet.FTilesheetManager;
import flash.display.BitmapData;
import flash.geom.Rectangle;
import flash.geom.Point;


import openfl.gl.GL;
import openfl.gl.GLBuffer;
import openfl.gl.GLTexture;

import openfl.utils.Float32Array;
import openfl.utils.UInt8Array;

class FTile {
    public var pixelRect:Rectangle;
    public var normalized:Rectangle;
    public var label:String;
    public var tileId:Int;

    public function new(pixelRect:Rectangle, label:String, imageWidth:Float, imageHeight:Float, tileId:Int){
        this.pixelRect = pixelRect;
        this.label = label;
        normalized = new Rectangle();
        this.tileId = tileId;
        calculateNormalized(imageWidth, imageHeight);
    }

    function calculateNormalized(imageWidth:Float, imageHeight:Float){
        normalized.x = pixelRect.x/imageWidth;
        normalized.y = pixelRect.y/imageHeight;
        normalized.width = pixelRect.width/imageWidth;
        normalized.height = pixelRect.height/imageHeight;
    }
}


/**
 * Class: FTilesheet
 * @author jordan
 */
class FTilesheet  {
	
    private var texture:GLTexture;
    private var vertexAttribute:Int;
    private var vertexBuffer:GLBuffer;
    private var texCoordAttribute:Int;
    private var texCoordBuffer:GLBuffer;
    private var bitmapData:BitmapData;
	private var id:Int;
	private var definitionFileName:String;
	private var imageFileName:String;
	private var _renderPriority:Float;
	private var _labelMap:Map<String,Int>;
	
	private var _tiles:Array<FTile>;


	public function new (inImage:BitmapData) {
		var tm = FTilesheetManager.getInstance();
		this.id = tm.genTilesheetId();
		tm.addTileSheet(this);
		_tiles = new Array<FTile>();
		_renderPriority = 0;
		_labelMap = new Map();
        this.bitmapData = inImage;

		var stats = firmament.util.FStatistics.getInstance();
		if( !stats.hasProperty('Tilesheets') ) {
			stats.registerProp('Tilesheets','Int');
			stats.setProp('Tilesheets',0);
		}
		stats.setProp('Tilesheets',stats.getProp('Tilesheets')+1);
	}

    private function createBuffers ():Void {
        
        var vertices = [
            
            bitmapData.width, bitmapData.height, 0,
            0, bitmapData.height, 0,
            bitmapData.width, 0, 0,
            0, 0, 0
            
        ];
        
        vertexBuffer = GL.createBuffer ();
        GL.bindBuffer (GL.ARRAY_BUFFER, vertexBuffer);
        GL.bufferData (GL.ARRAY_BUFFER, new Float32Array (cast vertices), GL.STATIC_DRAW);
        GL.bindBuffer (GL.ARRAY_BUFFER, null);
        
        var texCoords = [
            
            1, 1, 
            0, 1, 
            1, 0, 
            0, 0, 
            
        ];
        
        texCoordBuffer = GL.createBuffer ();
        GL.bindBuffer (GL.ARRAY_BUFFER, texCoordBuffer);    
        GL.bufferData (GL.ARRAY_BUFFER, new Float32Array (cast texCoords), GL.STATIC_DRAW);
        GL.bindBuffer (GL.ARRAY_BUFFER, null);
        
    }
    
    
    private function createTexture ():Void {
        
        #if html5
        var pixelData = bitmapData.getPixels (bitmapData.rect).byteView;
        #else
        var pixelData = new UInt8Array (bitmapData.getPixels (bitmapData.rect));
        #end
        
        texture = GL.createTexture ();
        GL.bindTexture (GL.TEXTURE_2D, texture);
        GL.texParameteri (GL.TEXTURE_2D, GL.TEXTURE_WRAP_S, GL.CLAMP_TO_EDGE);
        GL.texParameteri (GL.TEXTURE_2D, GL.TEXTURE_WRAP_T, GL.CLAMP_TO_EDGE);
        GL.texImage2D (GL.TEXTURE_2D, 0, GL.RGBA, bitmapData.width, bitmapData.height, 0, GL.RGBA, GL.UNSIGNED_BYTE, pixelData);
        GL.texParameteri (GL.TEXTURE_2D, GL.TEXTURE_MAG_FILTER, GL.LINEAR);
        GL.texParameteri (GL.TEXTURE_2D, GL.TEXTURE_MIN_FILTER, GL.LINEAR);
        GL.bindTexture (GL.TEXTURE_2D, null);
        
    }

	public function getId(){
		return this.id;
	}


	public function getDefinitionFileName():String{
		return this.definitionFileName;
	}

	public function getImageFileName():String{
		return this.imageFileName;
	}

	public function setImageFileName(name:String){
		this.imageFileName = name;
	}

	public function setDefinitionFileName(name:String){
		this.definitionFileName = name;
	}


	/**
	 * Function: addTileRect
	 *
	 * Adds a rectangle definition
	 *
	 * Parameters:
	 *	rectangle - Rectangle definition
	 *	centerPoint - the center point of the image
	 *
	 */
	public function addTileRect(rectangle:Rectangle, centerPoint:Point = null):Int{
		
		_tiles.push(new FTile(rectangle,null,bitmapData.width, bitmapData.height, _tiles.length));
		return _tiles.length-1;
	}


	/**
	 * Function: addTileRect
	 *
	 * Adds a rectangle definition
	 *
	 * Parameters:
	 *	rectangle - Rectangle definition
	 *	centerPoint - the center point of the image
	 *
	 */
	public function addTileRectWithLabel(rectangle:Rectangle, centerPoint:Point = null, label:String=null):Int{
		if(label!=null){
			//firmament.util.FLog.debug("LENGTH:"+_tiles.length);
			_labelMap.set(label,_tiles.length);
		}
        _tiles.push(new FTile(rectangle, label, bitmapData.width, bitmapData.height, _tiles.length));
		return _tiles.length -1;
	}
	
	public function getRectangle(i:Int){
		return _tiles[i].pixelRect;
	}

	public function getRenderPriority(){
		return _renderPriority;
	}
	
	public function setRenderPriority(priority:Float){
		_renderPriority = priority;
	}

	public function getTileNumber(label:String):Int{
		return _labelMap.get(label);
	}

    public function getTileBitmap(tileId:Int){
        var tile = _tiles[tileId];
        if(tile == null) throw "invalid tileId: "+tileId;
        var bmd = new BitmapData(cast tile.pixelRect.width, cast tile.pixelRect.height);
        bmd.copyPixels(bitmapData,tile.pixelRect, new Point(0,0));
        return bmd;
    }

}
