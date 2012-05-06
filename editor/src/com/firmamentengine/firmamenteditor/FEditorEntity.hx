package com.firmamentengine.firmamenteditor;
import firmament.core.FPhysicsEntity;
import firmament.core.FSpriteRenderer;
import firmament.core.FPhysicsWorld;
import firmament.ui.FDialog;
/**
 * ...
 * @author Jordan Wambaugh
 */

class FEditorEntity extends FPhysicsEntity
{

	var originalSprite:Dynamic;
	var fileName:String;
	public function new(world:FPhysicsWorld,config:Dynamic) 
	{
		//must preserve original config for editor
		this.originalSprite = config.sprite;
		this.fileName = config.entityFile;
		//need to use our own image loader here since we don't have compiled assets
		if(Std.is(config.sprite,String)){
			config.sprite = ResourceLoader.loadImage(config.sprite);
		}
		super(world, config);
		
		this.config.sprite = originalSprite;
	}
	
	public function setFileName(n:String) {
		this.fileName = n;
	}
	
	public function getMapConfig():Dynamic {
		return { 
			entityFile:this.fileName
			,config: {
				position: this.getPosition()
				,angle: this.getAngle()
				}
			};
		
	}
	
}