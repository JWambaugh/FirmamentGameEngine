package firmament.core;

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
/**
 * ...
 * @author Jordan Wambaugh
 */

class FWireframeRenderer implements FRenderer
{

	public function new() 
	{
		
	}
	
	public function render(item:FRenderable, camera:FCamera):Void {
		//camera.graphics.lineStyle(1, 0);
		var pos = item.getPosition();
		var sprite = new Shape();
		sprite.graphics.lineStyle(1,0xFF00FF);
		var cameraPos = camera.getTopLeftPosition();
		//trace(cameraPos.y);
		if (item.hasShapes()) {
			var shapes:Array<B2Shape> = item.getShapes();
			//trace(shapes.length);
			for (shape in shapes) {
				//trace(shape.getType());
				if (shape.getType() == B2Shape.e_polygonShape) {
					//trace('poly!');
					var pshape:B2PolygonShape = cast(shape, B2PolygonShape);
					var counter:Int = 0;
					var pvec:B2Vec2;
					for (vec in pshape.m_vertices) {
						if (counter++ > 0) {
							sprite.graphics.lineTo((pos.x+vec.x-cameraPos.x)*camera.getZoom(), (pos.y+vec.y-cameraPos.y)*camera.getZoom());
						}
						pvec = vec;
						sprite.graphics.moveTo((pos.x + pvec.x - cameraPos.x) * camera.getZoom(), (pos.y + pvec.y - cameraPos.y) * camera.getZoom());
						//trace('draw');
					}
				}else if (shape.getType() == B2Shape.e_circleShape) {
					var pshape:B2CircleShape = cast(shape, B2CircleShape);
					sprite.graphics.drawCircle((pos.x+pshape.getLocalPosition().x-cameraPos.x)*camera.getZoom(),(pos.y+pshape.getLocalPosition().y-cameraPos.y)*camera.getZoom(),pshape.m_radius*camera.getZoom());
			
				}
			}
		}else{
			sprite.graphics.drawCircle((pos.x-cameraPos.x)*camera.getZoom(),(pos.y-cameraPos.y)*camera.getZoom(),1*camera.getZoom());
			
		}
		camera.bitmapData.draw(sprite);
	}
	
	
	
}