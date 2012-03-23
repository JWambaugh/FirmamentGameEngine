package firmament.core;
import nme.events.EventDispatcher;

/**
 * ...
 * @author Jordan Wambaugh
 */

interface FRenderer 
{

	function render(item:FRenderable,camera:FCamera):Void;
	
	
}