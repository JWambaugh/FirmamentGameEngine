package firmament.util;
import flash.display.BitmapData;
import flash.geom.Rectangle;

import flash.geom.Point;

/**
 * ...
 * @author Jordan Wambaugh
 */

class FAutoCrop 
{
	
	public static function isContent(color:Int):Bool {
		var alphaValue:Int = color >> 24 & 0xFF;
		if (alphaValue != 0) return true;
		return false;
	}
	
	
	public static function crop(bitmap:BitmapData) {
		var top:Int =0;
		var bottom:Int =0;
		var left:Int =0;
		var right:Int =0;
		
		firmament.util.FLog.debug('w: '+bitmap.width+"  h:"+bitmap.height);
		//find left
		for (x in 0 ... bitmap.width) {
			for (y in 0 ... bitmap.height) {
				if (isContent( bitmap.getPixel32(x, y))) {
					left = x;
					
					break;
				}
			}
			if (left != 0) break;
		}
		
		
		//find right
		var x = bitmap.width-1 ;
		
		while (x-- >= 0) {
			
			for (y in 0...bitmap.height) {
				//firmament.util.FLog.debug("x:"+x+"  y:"+y);
				if (isContent( bitmap.getPixel32(x, y))) {
					right = x;
					break;
				}
			}
			if (right != 0) break;
		}
		
		
		//find top
		for (y in 0 ... bitmap.height) {
			for (x in 0 ... bitmap.width) {
				if (isContent( bitmap.getPixel32(x, y))) {
					top = y;
					break;
				}
			}
			if (top != 0) break;
		}
		
		
		var y = bitmap.height-1;
		//find bottom
		while (y-- >= 0) {
			for (x in 0...bitmap.width) {
				if (isContent( bitmap.getPixel32(x, y))) {
					bottom = y;
					break;
				}
			}
			if (bottom != 0) break;
		}
		
		firmament.util.FLog.debug('top:'+top);
		firmament.util.FLog.debug('bottom:'+bottom);
		firmament.util.FLog.debug('left:'+left);
		firmament.util.FLog.debug('right:'+right);
		var width = right - left;
		var height = bottom - top;
		var newBitmap = new BitmapData(width, height, true, 0);
		newBitmap.copyPixels(bitmap, new Rectangle(left, top, width, height), new Point(0, 0),null,null,true);
		return newBitmap;
		
	}
	
}