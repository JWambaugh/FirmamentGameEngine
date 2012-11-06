package firmament.core;
import firmament.component.physics.FPhysicsComponentInterface;
import nme.display.BitmapData;
import nme.display.Tilesheet;
import nme.geom.Rectangle;
import firmament.component.render.FTilesheetRenderComponent;
import nme.geom.Point;
import firmament.component.base.FEntityComponent;
import firmament.component.render.FRenderComponentInterface;

import nme.Assets;
 
 /**
  * Class: FEntity 
  * Base class for all entities in Firmament
  * 
  * 
  */
class FEntity extends nme.events.EventDispatcher
{
	var config:Dynamic;
	var components:Hash<FEntityComponent>;
	/**
	 * Constructor: new
	 * 
	 * Config Paramers:
	 * 	imageScale - [Float] The initial scale value for the sprite.
	 * 	sprite  - [BitmapData] The image to use as a sprite for this entity
	 */
	public function new(config:Dynamic) 
	{
		super();
		this.config = config;
		this.components = new Hash<FEntityComponent>();
		
	}
	
	
	/**
	 * Function: getComponent
	 * 
	 * Returns:
	 * 	<FentityComponent>
	 */
	public function getComponent(type:String):FEntityComponent {
		return this.components.get(type);
	}



	/**
	 * Function: getPhysicsComponent()
	 *	returns a physics component
	 * 
	 * Parameters: 
	 *	none
	 *
	 * Returns:
	 *	<FPysicsComponentInterface>
	 */
	public function getPhysicsComponent():FPhysicsComponentInterface {
		return cast(this.getComponent('physics'), FPhysicsComponentInterface);
	}

	public function getRenderComponent():FRenderComponentInterface {
		return cast(this.getComponent('render'), FRenderComponentInterface);
	}
	
	
	public function setComponent(component:FEntityComponent) {
		this.components.set(component.getType(),component);
		component.setEntity(this);
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