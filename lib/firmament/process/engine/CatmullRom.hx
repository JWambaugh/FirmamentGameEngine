
package firmament.process.engine;

import flash.geom.Point;
import firmament.core.FVector;

class SplinePoints {
    public var _p0:FVector;
    public var _p1:FVector;
    public var _p2:FVector;
    public var _p3:FVector;

    public function new() {}

    public function setPoints(p0:FVector,p1:FVector,p2:FVector,p3:FVector):Void {
        _p0 = p0; _p1 = p1; _p2 = p2; _p3 = p3;
    }
}

class CatmullRom
{
    private var updateStep:Float->Bool;
    private var _ps:Array<FVector>; // spline points
    private var _index:Int; // active index
    private var _step:Float; 
    private var _rate:Float; // how many seconds it takes to traverse the curve
    private var _active:Bool; // if object updates or not
    private var _calcTangent:Bool = true;
    private var _ptcache:SplinePoints;
    
    private var _q:FVector; // current position along spline
    private var _t:FVector; // tangent as unit vector, needs to be moved to _step

    /*CatmullRom*/
    public function new (points:Array<FVector>,totalTime:Float)
    {
        _ptcache = new SplinePoints();
    	_ps = [];

        _index = -1;
        _step = 1;
        _active = true;
        updateStep = updateStepForwards;

        /*var N:Int = Std.int(3 + 10 * Math.random ());
        for ( i in 0 ... N ) {
            _ps.push (new FVector (200-400 * Math.random (), 200-400 * Math.random ()));
        }*/
        /*_ps.push (new FVector (-200, -200));
        _ps.push (new FVector (0,0));
        _ps.push (new FVector (200, 200));*/

        if(Std.is(points,Array)) {
            _ps = [];
            for(point in points) {
                _ps.push(point);
            }
        }

        if( _ps.length < 3 ) {
            throw "CatmullRom - Spline must have a minimum of 3 control points";
        }

        if(Math.isNaN(totalTime) == false) {
            _rate = _ps.length / totalTime;
        } else {
            _rate = _ps.length / 5.0; // default is 5 seconds, shorter makes it quite difficult to see the progression of the entity
        }

    }

    public function setRate(totalTime:Float):Float {
        var currentRate:Float = _ps.length / _rate;
        _rate = _ps.length / totalTime;
        return currentRate;
    }

    public function getPosition():FVector {
        return _q;
    }

    public function getTangent():FVector {
        return _t;
    }

    public function getPoints():Array<FVector> {
        return _ps;
    }

    public function setActive(active:Bool) {
        _active = active;
    }

    public function isActive() {
        return (_active == true);
    }

    public function reset() {
        _index = -1;
        _step = 1;
    }

    public function update (delta:Float):Void 
    {
        if(_active) {
            if(updateStep(delta)) {
                setPositionCache(_index,_ptcache);
            }

            _q = spline (_ptcache._p0, _ptcache._p1, _ptcache._p2, _ptcache._p3, _step);

            if( _calcTangent ) {
                var t1:FVector = spline (_ptcache._p0, _ptcache._p1, _ptcache._p2, _ptcache._p3, _step-.0000000001);
                var t2:FVector = spline (_ptcache._p0, _ptcache._p1, _ptcache._p2, _ptcache._p3, _step+.0000000001);
                t2.subtract(t1);
                _t = t2.makeUnit();
            } else { 
                _t = null; 
            }
        }
    }

    private function updateStepForwards(delta:Float):Bool {
        var updated:Bool = false;
        var lenMinusOne:Int = _ps.length -1;
        _step=_step+(delta*_rate);
        while(_step > 1) {
            updated=true;
            _step -= 1;
            _index += 1;
            if( _index >= lenMinusOne ) {
                _index = lenMinusOne-1;
                _step = .99999;
                _active = false;
                break;
            }
        }
        return updated;
    }

    private function setPositionCache(index:Int,ptcache:SplinePoints) {
        var s0 = (index>0)?index-1:0; 
        var s1 = (index>0)?index:0;
        var s2=((index+1)<_ps.length)?index+1:index; 
        var s3=((index+2)<_ps.length)?index+2:index;
        ptcache.setPoints(_ps[s0],_ps[s1],_ps[s2],_ps[s3]);
    }

    /* 
    * Calculates 2D cubic Catmull-Rom spline.
    * @see http://www.mv_ps.org/directx/articles/catmull/
    */ 
    public function spline (p0:FVector, p1:FVector, p2:FVector, p3:FVector, t:Float):FVector 
    {
        return new FVector (
            0.5 * ((          2*p1.x) +
                t * (( -p0.x           +p2.x) +
                t * ((2*p0.x -5*p1.x +4*p2.x -p3.x) +
                t * (  -p0.x +3*p1.x -3*p2.x +p3.x)))),
            0.5 * ((          2*p1.y) +
                t * (( -p0.y           +p2.y) +
                t * ((2*p0.y -5*p1.y +4*p2.y -p3.y) +
                t * (  -p0.y +3*p1.y -3*p2.y +p3.y))))
        );
    }
}