package firmament.component.render;

import firmament.core.FCamera;
import flash.display.BitmapData;
/**
 * Class: FRenderer
 */

interface FRenderComponentInterface
{

	function render(camera:FCamera):Void;
	
	function getBitmapData():BitmapData;

	function getParallaxMultiplier():Float;
	
}