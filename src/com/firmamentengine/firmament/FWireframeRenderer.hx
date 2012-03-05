package com.firmamentengine.firmament;

import nme.display.MovieClip;
import nme.display.Bitmap;
import nme.display.Sprite;


//import these two classes
import nme.display.BitmapData;
import nme.geom.Rectangle;
/**
 * ...
 * @author Jordan Wambaugh
 */

class FWireframeRenderer implements FRenderer
{

	public function new() 
	{
		
	}
	
	public function render(item:FRenderable, camera:FCamera):Void {
		//camera.graphics.lineStyle(1, 0);
		var pos = item.getPosition();
		var sprite = new Sprite();
		
		var cameraPos = camera.getTopLeftPosition();
		//trace(cameraPos.y);
		sprite.graphics.drawCircle((pos.x-cameraPos.x)*camera.getZoom(),(pos.y-cameraPos.y)*camera.getZoom(),1*camera.getZoom());
		camera.bitmapData.draw(sprite);
	}
	
	
	
}