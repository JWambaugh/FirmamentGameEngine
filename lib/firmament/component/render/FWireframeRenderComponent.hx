package firmament.component.render;


import flash.display.MovieClip;
import flash.display.Bitmap;
import flash.display.Shape;
import flash.display.Sprite;
import firmament.core.FShape;
import firmament.core.FPolygonShape;
import firmament.core.FCircleShape;
import firmament.core.FVector;
//import these two classes
import flash.display.BitmapData;
import flash.geom.Rectangle;
import firmament.component.base.FEntityComponent;
import firmament.core.FEntity;
import firmament.core.FCamera;
import firmament.component.physics.FPhysicsComponentInterface;
import flash.geom.Matrix;
import flash.geom.Point;

/**
 * ...
 * @author Jordan Wambaugh
 */

class FWireframeRenderComponent extends FEntityComponent implements FRenderComponentInterface
{

	public function new() 
	{
		super();
		
	}

	override public function init(config:Dynamic){

	}
	
	public function render(camera:FCamera):Void {
		var physicsComponent:FPhysicsComponentInterface= _entity.getPhysicsComponent();
		if(physicsComponent==null)return;
		var pos = physicsComponent.getPosition();
		
		camera.graphics.lineStyle(1,0xFF00FF);
		var cameraPos = camera.getTopLeftPosition();
		
		//firmament.util.FLog.debug(cameraPos.y);
		
		//draw entity location
		camera.graphics.drawCircle((pos.x-cameraPos.x)*camera.getZoom(),(pos.y-cameraPos.y)*camera.getZoom(),5);
		
		var shapes:Array<FShape> = physicsComponent.getShapes();
		//firmament.util.FLog.debug(shapes.length);
		for (shape in shapes) {
			//firmament.util.FLog.debug(shape.getType());
			if (Std.is(shape,FPolygonShape)) {
				//firmament.util.FLog.debug('poly!');
				var pshape:FPolygonShape = cast(shape);
				var counter:Int = 0;
				var pvec:FVector;
				var matrix:flash.geom.Matrix = new Matrix();
				matrix.rotate(physicsComponent.getAngle());

				for (vec in pshape.getVectors()) {
					vec = vec.copy(); //don't want to modify original

					var p:Point = new Point(vec.x,vec.y);
					p=matrix.transformPoint(p);
					vec.x=p.x;
					vec.y=p.y;
					if (counter++ > 0) {
						camera.graphics.lineTo((pos.x+vec.x-cameraPos.x)*camera.getZoom(), (pos.y+vec.y-cameraPos.y)*camera.getZoom());
					}
					pvec = vec;
					camera.graphics.moveTo(( pos.x+pvec.x - cameraPos.x)*camera.getZoom(), (pos.y+pvec.y - cameraPos.y)*camera.getZoom());

				}
				
				if (counter > 0) {
					var vec = pshape.getVectors()[0].copy();
					var p:Point = new Point(vec.x,vec.y);
					p=matrix.transformPoint(p);
					vec.x=p.x;
					vec.y=p.y;
					camera.graphics.lineTo((pos.x+vec.x-cameraPos.x)*camera.getZoom(), (pos.y+vec.y-cameraPos.y)*camera.getZoom());
				}
			}else if (Std.is(shape,FCircleShape)) {
				var pshape:FCircleShape = cast(shape);
				camera.graphics.drawCircle((pos.x+pshape.getLocalPosition().x-cameraPos.x)*camera.getZoom(),(pos.y+pshape.getLocalPosition().y-cameraPos.y)*camera.getZoom(),pshape.getRadius()*camera.getZoom());
		
			}
		}
		camera.graphics.lineStyle(0,0,0);
		
	}
	public function getBitmapData():BitmapData{
		return new BitmapData(0,0);
	}
	
	override public function getType():String {
		return "render";
	}
	public function getParallaxMultiplier():Float{
		return 1;
	}
}