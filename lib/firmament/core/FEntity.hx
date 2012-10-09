package firmament.core;
import firmament.core.component.physics.FPhysicsComponentInterface;
import nme.display.BitmapData;
import nme.display.Tilesheet;
import nme.geom.Rectangle;
import firmament.core.component.render.FTilesheetRenderComponent;
import nme.geom.Point;
import firmament.core.component.FEntityComponent;

import nme.Assets;
 
 /**
  * Class: FEntity 
  * Base class for all entities in Firmament
  * 
  * 
  */
class FEntity extends flash.events.EventDispatcher
{
	var config:Dynamic;
	var components:Hash<FEntityComponent>;
	/**
	 * Constructor: new
	 * 
	 * Config Paramers:
		 * imageScale - [Float] The initial scale value for the sprite.
		 * sprite  - [BitmapData] The image to use as a sprite for this entity
	 */
	public function new(config:Dynamic) 
	{
		super();
		this.config = config;
		
		
	}
	
	
	/**
	 * Function: getComponent
	 * @return
	 */
	public function getComponent(type:String):FEntityComponent {
		return this.components.get(type);
	}
	
	public function getPhysicsComponent():FPhysicsComponentInterface {
		return cast(this.getComponent('physics'), FPhysicsComponentInterface);
	}
	
	public function setComponent(component:FEntityComponent) {
		
	}
	
	
	public function getConfig():Dynamic {
		return this.config;
	}

	/**
	 * Function: delete
	 * Will handle deletion of itself
	**/
	public function delete():Void{

	}
	
	
	
}