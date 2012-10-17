package firmament.component.render;

import box2D.common.math.B2Vec2;
import nme.display.MovieClip;
import nme.display.Bitmap;
import nme.display.Shape;
import nme.display.Sprite;
import box2D.collision.shapes.B2Shape;
import box2D.collision.shapes.B2PolygonShape;
import box2D.collision.shapes.B2CircleShape;
//import these two classes
import nme.display.BitmapData;
import nme.geom.Rectangle;
import firmament.component.base.FEntityComponent;
import firmament.core.FEntity;
import firmament.core.FCamera;
import firmament.component.physics.FBox2DComponent;

/**
 * ...
 * @author Jordan Wambaugh
 */

class FWireframeRenderComponent extends FEntityComponent, implements FRenderComponentInterface
{

	public function new() 
	{
		super();
		
	}

	override public function init(config:Dynamic){

	}
	
	public function render(camera:FCamera):Void {
		var physicsComponent:FBox2DComponent = cast(this._entity.getComponent("physics"));
		var pos = physicsComponent.getPosition();
		
		camera.graphics.lineStyle(1,0xFF00FF);
		var cameraPos = camera.getTopLeftPosition();
		//trace(cameraPos.y);
		
		//draw entity location
		camera.graphics.drawCircle((pos.x-cameraPos.x)*camera.getZoom(),(pos.y-cameraPos.y)*camera.getZoom(),5);
		if (physicsComponent.hasShapes()) {
			var shapes:Array<B2Shape> = physicsComponent.getShapes();
			//trace(shapes.length);
			for (shape in shapes) {
				//trace(shape.getType());
				if (shape.getType() == B2Shape.e_polygonShape) {
					//trace('poly!');
					var pshape:B2PolygonShape = cast(shape, B2PolygonShape);
					var counter:Int = 0;
					var pvec:B2Vec2;
					for (vec in pshape.m_vertices) {
						//trace(vec.x+'   '+vec.y);
						if (counter++ > 0) {
							camera.graphics.lineTo((pos.x+vec.x-cameraPos.x)*camera.getZoom(), (pos.y+vec.y-cameraPos.y)*camera.getZoom());
						}
						pvec = vec;
						camera.graphics.moveTo((pos.x + pvec.x - cameraPos.x) * camera.getZoom(), (pos.y + pvec.y - cameraPos.y) * camera.getZoom());
						//trace('draw');
					}
					
					if (counter > 0) {
						var vec = pshape.m_vertices[0];
						camera.graphics.lineTo((pos.x+vec.x-cameraPos.x)*camera.getZoom(), (pos.y+vec.y-cameraPos.y)*camera.getZoom());
					}
				}else if (shape.getType() == B2Shape.e_circleShape) {
					var pshape:B2CircleShape = cast(shape, B2CircleShape);
					camera.graphics.drawCircle((pos.x+pshape.getLocalPosition().x-cameraPos.x)*camera.getZoom(),(pos.y+pshape.getLocalPosition().y-cameraPos.y)*camera.getZoom(),pshape.m_radius*camera.getZoom());
			
				}
			}
		}else{
			camera.graphics.drawCircle((pos.x-cameraPos.x)*camera.getZoom(),(pos.y-cameraPos.y)*camera.getZoom(),1*camera.getZoom());
			
		}
		
	}
	
	
	override public function getType():String {
		return "render";
	}
}