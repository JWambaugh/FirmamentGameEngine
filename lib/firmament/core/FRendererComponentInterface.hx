package firmament.core;
import nme.events.EventDispatcher;

/**
 * Class: FRenderer
 */

interface FRendererComponentInterface
{

	function render(item:FRenderable,camera:FCamera):Void;
	
	
	
}