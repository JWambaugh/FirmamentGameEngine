
package firmament.process.engine;

import firmament.core.FGame;
import firmament.core.FCamera;
import firmament.process.base.FProcess;
import firmament.process.engine.FLinearTweener;
import firmament.process.engine.CatmullRom;
import firmament.core.FVector;
import firmament.core.FEntity;

import flash.geom.Point;
import flash.display.Graphics;
import firmament.core.FConfig;

class FSplineTweener extends FProcess {

    private var spline:CatmullRom;
    private var q:FVector;
    private var t:FVector;
    private var pts:Array<FVector>;
    private var _graphics:Graphics;
    private var _entity:FEntity;
    private var _startPos:FVector;
    private var _draw:Bool;
    private var _changeAngle:Bool;

	public function new(parameters:FConfig, ?entity:FEntity=null,?graphics:Graphics=null) {
		super();

		var points:Array<FVector> = [];
		var totalTime:Float = parameters.get('totalTime',Float,1.0);
		var offset = parameters.get('offset',FVector,new FVector(0,0));
		_changeAngle = parameters.get("changeAngle",Bool,true);
		var args:Array<Dynamic> = parameters.get('points',Array,[]);
		for ( pt in args ) {
		    //firmament.util.FLog.debug(pt[0],",",pt[1]);
		    points.push( new FVector(pt[0],pt[1]) );
		}
		spline = new CatmullRom(points, totalTime);

		//apply random start position if desired
		if(parameters.get('randomStart',Bool,false)){
			var startSeed = Math.random()*totalTime;
			spline.update(startSeed);
		}

		_entity = entity;
		if(_entity != null) {
			_startPos = _entity.getProp('position');
		}
		_graphics = graphics;

		//build spline path
		// this will build a static array which will be incorrect
		// when dynamically updating array position/shape
		_draw = parameters.get('draw',Bool,false);
		if(_draw) {
			pts = [];
			var delta:Float = 0.01;
			spline.setActive(true);
			var rate:Float = spline.setRate( Math.max( 10, spline.getPoints().length) );
			while( spline.isActive() ) {
				spline.update(delta);
				pts.push(spline.getPosition());
				delta = 1.0/15;
			}
			spline.reset();
			spline.setRate(rate);
		}

		spline.setActive(true);

		FGame.getInstance().addProcess(this);
	}

	public function setEntity(entity:FEntity): FEntity {
		var oldEntity:FEntity = _entity;
		_entity = entity;
		return oldEntity;
	}

	public function setGraphics(g:Graphics) {
		_graphics = g;
	}

	override public function step(delta:Float) {
		spline.update(delta);

		q=spline.getPosition();
		t=spline.getTangent();
		if(_entity != null) {
		    var qa = q.copy();
		    qa.add(_startPos);
			_entity.setProp('position', qa );
			if(_changeAngle){
				_entity.setProp('angle',Math.atan2(t.y,t.x));
			}
		}

		if(spline.isActive() == false ) {
			spline.reset();
			spline.setActive(true);
		}
	}

	public function render() {
		if(_draw == false) { return; }
		//firmament.util.FLog.debug( Type.getClassName(Type.getClass(this)));

        var points:Array<FVector> = spline.getPoints();

        _graphics.lineStyle(2,0xcccc0);

        if( pts.length > 0) {
			_graphics.moveTo(pts[0].x+_startPos.x,pts[0].y+_startPos.y);
	        for ( index in 1...(pts.length-1) ) {
	        	var point:FVector = pts[index];
	        	_graphics.lineStyle(2,0xcccc0);
	        	_graphics.lineTo(point.x+300,point.y+400);
	        }
    	}

        _graphics.beginFill(0xcc0000);
        for( point in points ) {
        	_graphics.drawCircle(point.x+_startPos.x,point.y+_startPos.y,5);
        }

		_graphics.lineStyle(1,0xFFFF00);
        _graphics.beginFill(0xFF0000);
        _graphics.drawCircle(q.x+_startPos.x,q.y+_startPos.y,2);
        _graphics.moveTo(q.x+_startPos.x,q.y+_startPos.x);
        _graphics.lineTo((q.x+t.x*25)+_startPos.x,(q.y+t.y*25)+_startPos.y);
        _graphics.lineStyle(0,0,0);
        _graphics.endFill();
	}
}
