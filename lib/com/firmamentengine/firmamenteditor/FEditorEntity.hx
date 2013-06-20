package com.firmamentengine.firmamenteditor;
import firmament.core.FEntity;
import firmament.util.FEntityCompat;
import firmament.component.base.FEntityComponentFactory;
import firmament.ui.FDialog;
import openfl.Assets;
import firmament.component.render.FTilesheetRenderComponent;
import firmament.util.FMisc;
import firmament.core.FGame;
/**
 * ...
 * @author Jordan Wambaugh
 */
using firmament.util.FEntityCompat;
class FEditorEntity extends FEntity
{

	var originalSprite:Dynamic;
	var fileName:String;
	public var _modifications:Dynamic;
	public function new(config:Dynamic,?gameInstanceName:String="main") 
	{
		_modifications = {};
		//filter out any custom components
		for(key in Reflect.fields(config.components)){
			if(key!='animation' && key!='render' && key!='physics'){
				Reflect.deleteField(config.components,key);
			}
		}
		
		this.fileName = config.entityFile;

		if(config.components.physics.componentName == 'noPhysics'){
			if(config.components.physics.width <.20)config.components.physics.width =.20;
			if(config.components.physics.height <.20)config.components.physics.height =.20;
		}

		//must preserve original config for editor
		if(config.components.render!=null){
			this.originalSprite = config.components.render.image;
			//need to use our own image loader here since we don't have compiled assets
			if(Std.is(config.components.render.image,String)){
				config.components.render.image = ResourceLoader.loadImage(config.components.render.image);
			}
		}
		if(config._defaultImage == true || config.components.render==null){
			
			config.components.render={
				componentName:'tilesheet'
				,image: Assets.getBitmapData("assets/images/default-icon.png")
			};
			if(config.components.physics.componentName == 'noPhysics'){
				config.components.render.imageScale= 256/config.components.physics.width;
			}else if(config.components.physics.componentName == 'box2d'){
				config.components.render.imageScale= 256/config.components.physics.shapes[0].width;
			}
		}


		super(config,gameInstanceName);
		
		
	}
	
	public function setFileName(n:String) {
		this.fileName = n;
	}

	public function getFileName() {
		return this.fileName;
	}

	public function getMapConfig():Dynamic {
		var p = this.getPhysicsComponent();

		var base = { 
			entityFile:this.fileName
			,config: {
				components:{
					physics:{
						position: {x:p.getPositionX(),y:getPositionY()}
						,angle: p.getAngle()
						}
					}
				}
			};
		FMisc.mergeInto(_modifications,base.config);
		base.config.components.physics.position={x:p.getPositionX(),y:getPositionY()};
		return base;
		
	}
	
}