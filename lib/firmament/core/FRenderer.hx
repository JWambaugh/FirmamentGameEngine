package firmament.core;
import nme.events.EventDispatcher;

/**
 * Class: FRenderer
 */

interface FRenderer 
{

	function render(item:FRenderable,camera:FCamera):Void;
	
	
}