
package firmament.tilesheet;

import firmament.tilesheet.FTilesheet;
import firmament.core.FCamera;
import flash.events.Event;
import openfl.display.Tilesheet;

import openfl.gl.GL;
import openfl.gl.GLBuffer;
import openfl.gl.GLTexture;
import openfl.gl.GLProgram;
import openfl.gl.GLUniformLocation;


typedef DrawItem={
	var tilesheet:FTilesheet;
	var list:Array<Float>;
	var positionZ:Float;
}

class FTilesheetRenderHelper {
	private static var _instance;

	var drawList:Array<DrawItem>;
	var initializedCameras:Array<FCamera>;
	var drawItemPool:Array<DrawItem>;

       private var shaderProgram:GLProgram;
    private var vertexAttribute:Int;
    private var modelViewMatrixUniform:GLUniformLocation;
    private var projectionMatrixUniform:GLUniformLocation;
    private var texCoordAttribute:Int;
    private var imageUniform:GLUniformLocation;


	private function new(){
		drawList = new Array();
		drawItemPool = new Array();
		initializedCameras = new Array<FCamera>();
        initializeShaders();
	}




    private function initializeShaders ():Void {
        
        var vertexShaderSource = 
            
            "attribute vec3 aVertexPosition;
            attribute vec2 aTexCoord;
            varying vec2 vTexCoord;
            
            uniform mat4 uModelViewMatrix;
            uniform mat4 uProjectionMatrix;
            
            void main(void) {
                vTexCoord = aTexCoord;
                gl_Position = uProjectionMatrix * uModelViewMatrix * vec4 (aVertexPosition, 1.0);
            }";
        
        var vertexShader = GL.createShader (GL.VERTEX_SHADER);
        GL.shaderSource (vertexShader, vertexShaderSource);
        GL.compileShader (vertexShader);
        
        if (GL.getShaderParameter (vertexShader, GL.COMPILE_STATUS) == 0) {
            
            throw "Error compiling vertex shader";
            
        }
        
        /*var fragmentShaderSource = 
            
            #if !desktop
            "precision mediump float;" +
            #end
            "varying vec2 vTexCoord;
            uniform sampler2D uImage0;
            
            void main(void)
            {"
            #if html5
                + "gl_FragColor = texture2D (uImage0, vTexCoord);" + 
            #else
                + "gl_FragColor = texture2D (uImage0, vTexCoord).gbar;" + 
            #end
            "}";*/


        var fragmentShaderSource = "
            varying vec2 vTexCoord;
            uniform sampler2D uImage0;
            uniform float u_time;
             
            // 1
            const float speed = 2.0;
            const float bendFactor = 0.2;
            void main()
            {
              // 2
              float height = 1.0 - vTexCoord.y;
              // 3
              float offset = pow(height, 2.5);
             
              // 4 multiply by sin since it gives us nice bending
              offset *= (sin(u_time * speed) * bendFactor);
             
              // 5
              gl_FragColor = texture2D(uImage0, vec2(vTexCoord.x + offset, vTexCoord.y)).gbar;
              //gl_FragColor = vec4(normalColor, 1);
            }";
        
        var fragmentShader = GL.createShader (GL.FRAGMENT_SHADER);
        GL.shaderSource (fragmentShader, fragmentShaderSource);
        GL.compileShader (fragmentShader);
        
        if (GL.getShaderParameter (fragmentShader, GL.COMPILE_STATUS) == 0) {
            
            throw "Error compiling fragment shader";
            
        }
        
        shaderProgram = GL.createProgram ();
        GL.attachShader (shaderProgram, vertexShader);
        GL.attachShader (shaderProgram, fragmentShader);
        GL.linkProgram (shaderProgram);
        
        if (GL.getProgramParameter (shaderProgram, GL.LINK_STATUS) == 0) {
            
            throw "Unable to initialize the shader program.";
            
        }
        
        vertexAttribute = GL.getAttribLocation (shaderProgram, "aVertexPosition");
        texCoordAttribute = GL.getAttribLocation (shaderProgram, "aTexCoord");
        projectionMatrixUniform = GL.getUniformLocation (shaderProgram, "uProjectionMatrix");
        modelViewMatrixUniform = GL.getUniformLocation (shaderProgram, "uModelViewMatrix");
        imageUniform = GL.getUniformLocation (shaderProgram, "uImage0");
        
    }


	public static function getInstance(){
		if(_instance == null){
			_instance = new FTilesheetRenderHelper();
		}
		return _instance;
	}


	public function addToDrawList(tilesheet:FTilesheet, list:Array<Float>,positionZ:Float){
		var di:DrawItem=null;
		if(drawItemPool.length>0){ //draw from pool if available
			di = drawItemPool.pop();
			di.tilesheet = tilesheet;
			di.list = list;
			di.positionZ = positionZ;
		}else{
			di = {tilesheet:tilesheet,list:list,positionZ:positionZ};
		}
		drawList.push(di);
	}

	

	public function preRender(){
		//move all draw items back to the pool
		while(drawList.length>0){
			drawItemPool.push(drawList.pop());
		}
	}

	public function postRender(camera:FCamera){
        renderView(camera);
		/*if(drawList.length < 1) return;
		//sort draw list by z position first, then tilesheet
		drawList.sort(function(a:DrawItem,b:DrawItem){
			if(a.positionZ > b.positionZ) return 1;
			if(a.positionZ < b.positionZ) return -1;
			if(a.tilesheet.getId() > b.tilesheet.getId()) return 1;
			if(a.tilesheet.getId() < b.tilesheet.getId()) return -1;
			else return 0;
		});
		var currentSheet:FTilesheet = drawList[0].tilesheet;
		var l:Array<Float> = new Array();
		var i:Int=0;
		while(true){
			var di:DrawItem = drawList[i];
			
			if(di.tilesheet == currentSheet){
				l = l.concat(di.list);
			}else{
				currentSheet.drawTiles(camera.graphics, l, true, 
				Tilesheet.TILE_TRANS_2x2 | Tilesheet.TILE_ALPHA |Tilesheet.TILE_RGB);
				l = di.list.copy();

				currentSheet = di.tilesheet;
			}
			
			if(++i==drawList.length){
				currentSheet.drawTiles(camera.graphics, l, true, 
				Tilesheet.TILE_TRANS_2x2 | Tilesheet.TILE_ALPHA |Tilesheet.TILE_RGB);
				break;
			}
		
		}*/
		
	}

    private function renderView (camera:FCamera):Void {
        var w = camera.getDisplayWidth;
        var h = camera.getDisplayHeight;
        GL.viewport (Std.int (camera.x - w/2), Std.int (camera.y-h/2), Std.int (w), Std.int (h));
        
        GL.clearColor (1.0, 1.0, 1.0, 1.0);
        GL.clear (GL.COLOR_BUFFER_BIT);
        
        var positionX = (stage.stageWidth - bitmapData.width) / 2;
        var positionY = (stage.stageHeight - bitmapData.height) / 2;
        
        var projectionMatrix = Matrix3D.createOrtho (0, rect.width, rect.height, 0, 1000, -1000);
        var modelViewMatrix = Matrix3D.create2D (positionX, positionY, 1, 0);
        
        GL.useProgram (shaderProgram);
        GL.uniform1f(timeUniform,time);
        GL.enableVertexAttribArray (vertexAttribute);
        GL.enableVertexAttribArray (texCoordAttribute);
        
        GL.activeTexture (GL.TEXTURE0);
        GL.bindTexture (GL.TEXTURE_2D, texture);
        
        #if desktop
        GL.enable (GL.TEXTURE_2D);
        #end
        
        GL.bindBuffer (GL.ARRAY_BUFFER, vertexBuffer);
        GL.vertexAttribPointer (vertexAttribute, 3, GL.FLOAT, false, 0, 0);
        GL.bindBuffer (GL.ARRAY_BUFFER, texCoordBuffer);
        GL.vertexAttribPointer (texCoordAttribute, 2, GL.FLOAT, false, 0, 0);
        
        GL.uniformMatrix3D (projectionMatrixUniform, false, projectionMatrix);
        GL.uniformMatrix3D (modelViewMatrixUniform, false, modelViewMatrix);
        GL.uniform1i (imageUniform, 0);
        
        GL.drawArrays (GL.TRIANGLE_STRIP, 0, 4);
        
        GL.bindBuffer (GL.ARRAY_BUFFER, null);
        GL.bindTexture (GL.TEXTURE_2D, null);
        
        #if desktop
        GL.disable (GL.TEXTURE_2D);
        #end
        
        GL.disableVertexAttribArray (vertexAttribute);
        GL.disableVertexAttribArray (texCoordAttribute);
        GL.useProgram (null);
        time+=.1;
    }


	private function isCameraInitialized(camera:FCamera){
		for(c in initializedCameras){
			if(c == camera) return true;
		}
		return false;
	}

}