
package firmament.process.engine;

import firmament.core.FGame;
import firmament.core.FCamera;
import firmament.process.base.FProcess;
import firmament.process.engine.FLinearTweener;
import firmament.process.engine.CatmullRom;
import firmament.core.FVector;

import nme.geom.Point;
import nme.display.Graphics;

class FSplineTweener extends FProcess {

    private var spline:CatmullRom;
    private var q:FVector;
    private var t:FVector;
    private var pts:Array<FVector>;
    private var graphics:Graphics;

	public function new(?name:String="splineTweener",parameters:Dynamic) {
		super();
		FGame.getInstance().addProcess(name,this);
		spline = new CatmullRom(null,Math.NaN);
		if( parameters.graphicsObject != null ) {
			graphics = parameters.graphicsObject;
		}

		//build spline path
		// this will build a static array which will be incorrect
		// when dynamically updating array position/shape
		pts = [];
		var delta:Float = 0.01;
		// var progress:Float = spline.progress();
		spline.setActive(true);
		var rate:Float = spline.setRate( Math.max( 10, spline.getPoints().length) );
		while( spline.isActive() ) {
			spline.update(delta);
			pts.push(spline.getPosition());
			delta = 1.0/15;
		}
		spline.reset();
		spline.setRate(rate);
		spline.setActive(true);
	}

	override public function step() {
		// Ti = 0.5 * ( Pi+1 - Pi-1 ) // Catmull-Rom splines

		var delta = this._manager.getFrameDelta();
		// trace("Delta: " + delta);
		spline.update(delta);
		q=spline.getPosition();
		t=spline.getTangent();

		if(spline.isActive() == false ) {
			spline.reset();
			spline.setActive(true);
		}

		// update the entities position


		// update the entities heading

	}

	public function render() {
        var points:Array<FVector> = spline.getPoints();

        graphics.lineStyle(2,0xcccc0);

        if( pts.length > 0) {
			graphics.moveTo(pts[0].x+300,pts[0].y+400);
	        for ( index in 1...(pts.length-1) ) {
	        	var point:FVector = pts[index];
	        	graphics.lineStyle(2,0xcccc0);
	        	graphics.lineTo(point.x+300,point.y+400);
	        }
    	}

        graphics.beginFill(0xcc0000);
        for( point in points ) {
        	graphics.drawCircle(point.x+300,point.y+400,5);
        }

		graphics.lineStyle(1,0xFFFF00);
        graphics.beginFill(0xFF0000);
        graphics.drawCircle(q.x+300,q.y+400,2);
        graphics.moveTo(q.x+300,q.y+400);
        graphics.lineTo((q.x+t.x*25)+300,(q.y+t.y*25)+400);
        graphics.lineStyle(0,0,0);
        graphics.endFill();
	}
}
