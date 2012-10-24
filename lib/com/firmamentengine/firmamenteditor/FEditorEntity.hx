package com.firmamentengine.firmamenteditor;
import firmament.core.FEntity;
import firmament.utils.FEntityCompat;
import firmament.ui.FDialog;
/**
 * ...
 * @author Jordan Wambaugh
 */
using firmament.utils.FEntityCompat;
class FEditorEntity extends FEntity
{

	var originalSprite:Dynamic;
	var fileName:String;
	public function new(config:Dynamic) 
	{
		//must preserve original config for editor
		this.originalSprite = config.components.render.tileSheetImage;
		this.fileName = config.entityFile;
		//need to use our own image loader here since we don't have compiled assets
		if(Std.is(config.components.render.tileSheetImage,String)){
			config.components.render.tileSheetImage = ResourceLoader.loadImage(config.components.render.tileSheetImage);
		}
		super(config);
		
		
	}
	
	public function setFileName(n:String) {
		this.fileName = n;
	}
	public function getFileName() {
		return this.fileName;
	}
	public function getMapConfig():Dynamic {
		return { 
			entityFile:this.fileName
			,config: {
				components:{
					physics:{
						position: this.getPosition()
						,angle: this.getAngle()
						}
					}
				}
			};
		
	}
	
}