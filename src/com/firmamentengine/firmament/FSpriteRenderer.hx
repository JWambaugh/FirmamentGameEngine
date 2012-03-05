package com.firmamentengine.firmament;
import nme.geom.Matrix;
import nme.display.IBitmapDrawable;
/**
 * ...
 * @author Jordan Wambaugh
 */

class FSpriteRenderer implements FRenderer
{

	public function new() 
	{
		
	}
	
	public function render(item:FRenderable, camera:FCamera):Void {
		
		if (item.getCurrentImage() == null) return;
		var bmData = item.getCurrentImage().bitmapData;
		if (bmData == null) return;
		var pos = item.getPosition();
		
		var cameraPos = camera.getTopLeftPosition();
		var matrix = new Matrix();
		var ratio = camera.getZoom() / item.getImageScale();
		var pos = item.getPosition();
		var nx=(pos.x-cameraPos.x)*camera.getZoom();
		var ny=(pos.y-cameraPos.y)*camera.getZoom();
		
		
		//trace(cameraPos.y);
		matrix.translate(nx, ny);
		matrix.rotate(item.getAngle());
		matrix.scale(ratio,ratio);
		trace(item.getAngle());
		camera.bitmapData.draw(bmData, matrix,null,null,null,true);
		
		
	}
	
}