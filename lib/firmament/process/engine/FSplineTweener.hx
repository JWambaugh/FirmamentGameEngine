
package firmament.process.engine;

import firmament.core.FGame;
import firmament.core.FCamera;
import firmament.process.base.FProcess;
import firmament.process.engine.FLinearTweener;
import firmament.process.engine.CatmullRom;

import nme.geom.Point;
import nme.display.Graphics;

class FSplineTweener extends FProcess {

    private var spline:CatmullRom;
    private var q:Point;
    private var graphics:Graphics;

	public function new(parameters:Dynamic) {
		super();		
		FGame.getInstance().addProcess("splineTweener",this);
		spline = new CatmullRom();
		/*if(parameters.time != null) {
			_duration = parameters.time+0.0;
		}*/
		if( parameters.graphicsObject != null ) {
			graphics = parameters.graphicsObject;
		}
	}

	/*override*/ public function pause() { 
	}

	/*override*/ public function resume() { 
	}

	/*override*/ public function stop() { 
	}

	/*override*/ public function reset() { 
	}

	override public function step() {
		// Ti = 0.5 * ( Pi+1 - Pi-1 ) // Catmull-Rom splines

		var delta = this._manager.getFrameDelta();
		trace("Delta: " + delta);
		q=spline.loop(delta);

		/*var ts:Float = t / steps;
        
        var pt:B2Vec2 = 0.5 * ( 
        				(2*p1) +  ts * ( 
        					(-p0+p2) + ts * (
        						  (2*p0 -5*p1 +4*p2 -p3) + ts * (-p0.x +3*p1.x -3*p2.x +p3.x)
        						)
        					)
        				)
        */

		/*
		var s:Float = t / steps
		var s3:Float = s*s*s;
		var s2:Float = s*s;
		var h1:Float =  2*s3 - 3*s2 + 1;
		var h2:Float = -2*s3 + 3*s2;
		var h3:Float =    s3 - 2*s2 + s;
		var h4:Float =    s3 -   s2;*/

		// Ti = 0.5 * ( Pi-1 - Pi+1 )
		// B2Vec2 p = h1*P1 + h2*P2 + h3*T1 + h4*T2;
		// set object position to p
	}

	public function renderPoint() {		
        // graphics.drawCircle((q.x-cameraPos.x)*camera.getZoom(),(q.y-cameraPos.y)*camera.getZoom(),100);
        
        var points:Array<Dynamic> = spline.getPoints();

        graphics.lineStyle(2,0xcccc0);
        graphics.beginFill(0xcc0000);

        for( point in points ) {
        	graphics.drawCircle(point.x+300,point.y+400,5);
        }

		graphics.lineStyle(1,0xFFFF00);
        graphics.beginFill(0xFF0000);
        graphics.drawCircle(q.x+300,q.y+400,2);
	}
}
